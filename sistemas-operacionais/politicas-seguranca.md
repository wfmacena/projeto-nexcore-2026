# Políticas de Segurança, Operação e Backup

## NexCore Tecnologia

---

## 1. Políticas de Segurança

### 1.1 Autenticação e Senhas

| Item | Política |
|------|----------|
| Tamanho mínimo de senha | 12 caracteres |
| Complexidade | Letras maiúsculas, minúsculas, números, símbolos |
| Histórico | Não permitir últimas 10 senhas |
| Expiração | 90 dias (exceto contas de serviço — senha 32+ caracs, nunca expira) |
| Bloqueio de conta | 5 tentativas erradas → 15 minutos bloqueado |
| MFA | Obrigatória para **todos** os usuários via Microsoft Authenticator (M365 BP/E3) |
| Acesso RDP aos servidores | Permitido **somente** IPs da rede TI (10.10.5.0/24) + MFA |
| LAPS | Senha local de admin gerenciada por AD LAPS — acessível somente ao grupo G_TI |

---

### 1.2 Criptografia e Proteção de Dados

| Camada | Tecnologia | Escopo |
|--------|------------|--------|
| Discos estações | **BitLocker** (TPM + senha de recuperação no AD) | 100% das estações |
| Discos servidores | **BitLocker** nos volumes de sistema, Storage Spaces encriptado nos clusters HV | Todos os servidores físicos |
| Arquivos confidenciais (financeiro/RH) | **Azure Information Protection** + classificação AIP | Grupo G_Diretoria + G_RH + G_Financeiro |
| E-mails confidenciais | **EOP (Exchange Online Protection)** + DLP | Global |
| Trânsito rede interna | HTTPS (TLS 1.3), LDAPS (AD), SMB3 encriptado | Padrão |

---

### 1.3 Software Permitido / Bloqueado

| Tipo | Regra |
|------|-------|
| Instalação de software | Bloqueado para usuários comuns (AppLocker / WDAC via GPO) — somente TI pode instalar |
| Aplicativos permitidos | Lista de permissão WDAC: Microsoft 365, AutoCAD, Packet Tracer, navegadores, Zabbix, Jira, etc. |
| Scripts PowerShell | Modo **Constrained Language** exceto TI (GPO) |
| Armazenamento USB | Bloqueado (GPO) exceto grupo G_TI (criptografado BitLocker To Go obrigatório) |
| Torrent / P2P | Bloqueado por firewall Next-Gen + DNS (OpenDNS / Quad9 com filtro) |
| Redes sociais | Bloqueado em horário comercial para perfis operacionais, liberado para Marketing |

---

## 2. Procedimentos Operacionais (SOPs principais)

| SOP | Descrição | Janela |
|-----|-----------|--------|
| **SOP 01 - Backup Diário** | Execução dos jobs Veeam (Full semanal, Incremental diário às 22:00) + checagem por NOC | 22:00 a 05:00 |
| **SOP 02 - Atualizações SO** | Patch Tuesday (2ª terça) — WSUS libera atualizações na **terça às 20:00**, reboot automático às 22:00. Servidores: última semana do mês, janelas escalonadas. | Terças 20:00~22:00 |
| **SOP 03 - Troca de senhas privilegiadas** | Rotação das contas de serviço e admin local via LAPS + CyberArk (credencial manager) | A cada 60 dias |
| **SOP 04 - Restore Drill (DR Campinas)** | Teste de failover de pelo menos 2 VMs críticas (ERP e Monitoramento) para o nó DR de Campinas | A cada trimestre (último sábado do mês) |
| **SOP 05 - Auditoria de acessos** | Revisão de membros dos grupos (G_TI, G_Diretoria, G_Financeiro) e logs RDP/AD | Mensal |
| **SOP 06 - Onboarding / Offboarding** | Criação/desativação de conta AD + M365 + acesso VPN + permissões pastas | Responsável RH → via service desk |

---

## 3. Estratégia de Backup e Recuperação

### 3.1 Solução

- **Software:** Veeam Backup & Replication v12
- **Servidor:** NEX-BKP01 (Ubuntu 24.04 + 140 TB RAID6 + LTO-9 Tape Library)
- **3-2-1 Rule:**
  - **3 cópias:** Produção (HV01/HV02 cluster) + Backup disco (BKP01) + Fita LTO-9
  - **2 tipos de mídia:** HD Enterprise + Fita magnética LTO-9
  - **1 cópia Offsite:** fitas LTO-9 trocadas semanalmente → levadas para a filial de Campinas (DR)
  - **(+ 1 cópia imutável):** 20 TB HD WORM (Write Once Read Many) para backups contra ransomware

### 3.2 Jobs e Horários

| Job | Tipo | Horário | RPO | RTO Alvo |
|-----|------|---------|-----|----------|
| VMs CRÍTICAS (SQL, ERP, CRM, WEB, MON) | Incremental (Reversed) | A cada 1 hora (24x7) | 1 hora | 1 hora (restore imediato via Veeam Instant Recovery) |
| VMs Não Críticas (arquivos, print, WSUS) | Incremental | Diário 22:00 | 24 horas | 4 horas |
| File Server FILE01 (compartilhamentos) | Backup a nível de arquivo (Veeam Agent) | Diário 22:30 | 24 horas | 2 horas |
| Todos os jobs semanal | FULL Synthetic | Domingo 04:00 | - | - |
| Cópia para Fita LTO-9 | Backup to Tape | Sexta 23:00 | 1 semana | 4 horas (troca de fita e restore) |

### 3.3 Retenção

| Tipo | Período |
|------|---------|
| Pontos de recuperação em disco | 14 dias (incrementais) + 4 semanas (sintéticos) |
| Pontos em fita LTO-9 | 12 fitas → rotação GFS semanal (52 semanas / 1 ano) |
| Imutáveis (anti-ransomware) | 12 últimos backups full |

---

## 4. Desastre (DRP)

- **Cenário de desastre da Matriz SP (incêndio, queda predial):**
  - Failover do cluster Hyper-V para as réplicas na Filial Campinas (RPO ~5 min, RTO ~30 min)
  - RODC de Campinas assume autenticação da região sudeste
  - VPN temporária 4G + Starlink ativa em 2 horas para colaboradores remotos
- **Responsáveis:** Diretor de Infraestrutura + Líder de NOC
- **Plano de teste:** Último sábado de cada trimestre (SOP 04 - Restore Drill)

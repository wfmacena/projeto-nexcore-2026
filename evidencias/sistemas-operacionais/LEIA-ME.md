# Evidências - Sistemas Operacionais

## 📁 O que deve estar nesta pasta

Esta pasta contém as **evidências visuais e documentais** da disciplina de Sistemas Operacionais (D2).

---

## 📸 Prints e Evidências Sugeridas

### 1. Escolha dos Sistemas Operacionais
**Nome do arquivo:** `01-sistemas-operacionais-escolhidos.png`

**O que incluir:**
- Tabela mostrando:
  - **Servidores:** Windows Server 2022 (Datacenter/Standard) + Ubuntu Server 24.04 LTS
  - **Estações Admin:** Windows 11 Pro + M365 Business Premium
  - **Estações Operacionais:** Windows 11 Enterprise LTSC 2024
  - **Estações Especializadas:** Windows 11 Enterprise + M365 E3
- Quantidade de licenças por tipo
- Justificativas resumidas

---

### 2. Serviços Configurados
**Nome do arquivo:** `02-servicos-servidores.png`

**O que incluir:**
- Lista de serviços por servidor:
  - **DC01:** Active Directory, DNS, DHCP, GPO, WSUS
  - **FILE01:** File Server, Print Server, Quotas
  - **SQL01:** SQL Server 2022 (WMS, TMS, ERP)
  - **HV01/HV02:** Hyper-V Cluster (VMs de aplicações)
  - **BACKUP01:** Veeam Backup & Replication, LTO-9
- IPs e portas utilizadas

---

### 3. Estrutura do Active Directory
**Nome do arquivo:** `03-estrutura-ad-ous-grupos.png`

**O que incluir:**
- Diagrama da estrutura AD:
  - Domínio: `nexcore.local`
  - OUs por local (SP, Campinas, Ribeirão Preto)
  - OUs por departamento (RH, Financeiro, TI, Comercial, etc.)
- Grupos de segurança
- Políticas de GPO aplicadas

---

### 4. Políticas de Segurança
**Nome do arquivo:** `04-politicas-senhas-seguranca.png`

**O que incluir:**
- Política de senhas:
  - Complexidade: 12+ caracteres, maiúsculas, minúsculas, números, símbolos
  - Expiração: 90 dias
  - Histórico: últimas 5 senhas
- Criptografia:
  - BitLocker nos desktops/notebooks
  - TLS 1.3 para comunicações
- MFA habilitado (Microsoft Authenticator)

---

### 5. Estratégia de Backup
**Nome do arquivo:** `05-backup-rpo-rto.png`

**O que incluir:**
- Software: Veeam Backup & Replication v12
- Frequência:
  - Servidores críticos: Backup incremental a cada 4h
  - Arquivos: Backup diário (23h)
  - Fitas LTO-9 offsite semanais
- RPO (Recovery Point Objective): 4 horas
- RTO (Recovery Time Objective): 2 horas
- Retenção: 30 dias disco + 1 ano fitas

---

### 6. Licenciamento e Custos
**Nome do arquivo:** `06-licencas-custos-3anos.png`

**O que incluir:**
- Tabela com licenças:
  - Windows Server 2022: Datacenter (2x) + Standard (6x)
  - Windows 11: Pro (108x) + Enterprise (192x)
  - Microsoft 365: Business Premium (143x) + E3 (30x)
  - SQL Server 2022: Enterprise (1x)
  - CALs: User CALs (300x)
  - Outros: AutoCAD, Adobe Creative Cloud
- **Custo total 3 anos: R$ 6.676.800**

---

## 📊 Documentação Adicional (Opcional)

### GPOs Configuradas
**Nome:** `gpos-configuradas.png`

Lista de Group Policy Objects:
- Política de senhas
- Bloqueio de USB em estações críticas
- Configuração de proxy/firewall
- Instalação automática de atualizações
- Restrições de software

---

### Plano de Disaster Recovery (DRP)
**Nome:** `plano-disaster-recovery.png`

Procedimentos documentados:
- Ordem de restauração de servidores
- Contatos de emergência
- Failover para filiais (servidores DR)
- Testes trimestrais de restauração

---

## 📋 Checklist de Verificação

Antes de considerar a disciplina completa, verifique:

- [ ] Arquivos MD da disciplina existem em `sistemas-operacionais/`
  - [ ] `servidores.md`
  - [ ] `estacoes.md`
  - [ ] `politicas-seguranca.md`
  - [ ] `licenciamento.md`
- [ ] Pelo menos 3 prints/evidências visuais salvos nesta pasta
- [ ] SOs escolhidos para servidores e estações estão claros
- [ ] Serviços (AD, DNS, DHCP, etc.) estão listados
- [ ] Políticas de segurança estão documentadas
- [ ] Estratégia de backup está definida (RPO/RTO)
- [ ] Licenças estão dimensionadas e custadas
- [ ] Total de licenciamento está correto

---

## 🎯 Para o Professor

Estas evidências provam que:
1. ✅ Sistemas operacionais foram escolhidos adequadamente
2. ✅ Serviços estão especificados por servidor
3. ✅ Active Directory e GPOs foram planejados
4. ✅ Políticas de segurança estão definidas
5. ✅ Estratégia de backup está clara (RPO/RTO)
6. ✅ Licenciamento foi dimensionado e custado
7. ✅ Projeto atende aos requisitos da disciplina de SO

---

## 📂 Estrutura Final Esperada

```
evidencias/sistemas-operacionais/
├── LEIA-ME.md                              ← Este arquivo
├── 01-sistemas-operacionais-escolhidos.png ← Recomendado
├── 02-servicos-servidores.png              ← Recomendado
├── 03-estrutura-ad-ous-grupos.png          ← Recomendado
├── 04-politicas-senhas-seguranca.png       ← Recomendado
├── 05-backup-rpo-rto.png                   ← Recomendado
├── 06-licencas-custos-3anos.png            ← Recomendado
├── gpos-configuradas.png                   ← Opcional
└── plano-disaster-recovery.png             ← Opcional
```

---

## 💡 Dicas

- **Diagramas de AD:** Use Draw.io ou PowerPoint para visualizar OUs
- **Tabelas de licenças:** Excel/LibreOffice com colunas: Produto, Qtd, Valor Unit, Subtotal
- **Políticas:** Pode ser screenshot do próprio documento MD renderizado
- **Backup:** Diagrama mostrando fluxo: Servidor → Veeam → Disco → Fita → Offsite

---

## ⚠️ Importante

- **NÃO incluir** senhas reais ou credenciais nos prints
- **NÃO incluir** dados pessoais (nomes, RAs)
- Focar em **configurações técnicas e custos**
- Manter **clareza e organização** visual

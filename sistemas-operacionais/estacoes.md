# Estações de Trabalho - SO e Licenças

## NexCore Tecnologia

---

## 1. Sistema Operacional por Perfil

### 1.1 Perfil Administrativo (108 máquinas)

- **SO:** Windows 11 Pro 24H2
- **Licença:** Microsoft 365 Business Premium (por usuário)
- **Atualizações:** Windows Update for Business (WaaS) via WSUS no DC01
- **Ingresso em domínio:** Sim (NEXCORE.local)
- **Aplicativos padrão:**
  - Microsoft 365 Apps (Word, Excel, PowerPoint, Outlook, Teams)
  - Navegador Edge (padrão) + Chrome
  - Adobe Reader
  - Antivírus: Microsoft Defender for Business (incluído no M365 BP)
  - Agente Zabbix (monitoramento)
  - Cliente VPN (Always On VPN)

---

### 1.2 Perfil Operacional Engenharia / NOC (162 máquinas)

- **SO:** Windows 11 Enterprise LTSC 2024 (24H2 LTSC)
- **Licença:** Volume License (CSP) — 162 licenças device
- **Justificativa LTSC:** Sem atualizações de feature por 10 anos. Sem bloatware (Copilot, Loja, Teams, etc.), ideal para estações 24x7 do NOC e engenharia que rodam Zabbix, Packet Tracer, GNS3, AutoCAD etc. sem surpresas.
- **Aplicativos adicionais vs Admin:**
  - AutoCAD 2024 / SketchUp Pro
  - Cisco Packet Tracer + GNS3
  - PuTTY, WinSCP, VNC Viewer, Wireshark
  - Tinkercad / Arduino IDE (laboratório IoT)
  - Microsoft Visio (diagramas de rede)
  - Jira Desktop / ServiceDesk

---

### 1.3 Perfil Especializado (30 máquinas — Data Center, BI, Engenharia Sênior)

- **SO:** Windows 11 Enterprise 24H2
- **Licença:** Microsoft 365 E3 + Windows 11 Enterprise VL (30)
- **Aplicativos adicionais:**
  - Hyper-V / VMware Workstation (virtualização local)
  - Power BI Desktop + Tableau
  - SQL Server Management Studio (SSMS) + Azure Data Studio
  - Visual Studio 2022 Enterprise
  - Adobe Creative Cloud (Photoshop, Illustrator, Premiere)
  - Microsoft Project (gestão de projetos)

---

### 1.4 Estações Vídeo-Wall NOC (12 unidades — Matriz SP)

- **SO:** Windows 11 IoT Enterprise LTSC 24H2
- **Licença:** 12 licenças Device (IoT)
- **Modo:** Kiosk multi-app (somente dashboards: Zabbix, Grafana, Power BI em tela cheia)
- **Login:** Conta de serviço sem privilégios locais
- **Atualizações:** 1 vez por mês, janela de manutenção domingo 04:00

---

## 2. Políticas Principais (GPO)

| Nome GPO | Aplicada a | O que faz |
|----------|------------|-----------|
| **GPO-Seguranca-Base** | Todos os usuários e computadores | Bloqueia USB exceto TI, força senha 12+ caracs, bloqueia PowerShell local sem moderação, ativa BitLocker em todas as estações |
| **GPO-Admin** | Grupo G_Administrativos | Mapeia unidade R: (Rede: FILE01\Public) e P: (Pessoal), libera impressoras do andar |
| **GPO-Engenharia** | Grupo G_Engenharia | Libera acesso administrativo local (via LAPS), mapeia unidades de engenharia, libera Wireshark/Packet Tracer |
| **GPO-NOC** | Grupo G_NOC | Modo Quiosque em 12 estações video-wall, acesso RDP permitido para operadores |
| **GPO-WSUS-Updates** | Todos os computadores | Define WSUS=NEX-DC01, atualizações terça 20:00, força reboot após 1h |
| **GPO-LAPS** | Todos os computadores | Gerencia senhas locais de admin via AD LAPS (acesso TI somente) |

---

## 3. Nome de domínio e estrutura

- **Domínio AD:** `NEXCORE.local` (floresta nível 2016, domínio nível 2016)
- **Domain Controllers:**
  - NEX-DC01 (Matriz SP) — PDC Emulator + 5 FSMO roles
  - NEX-DR-CAMP01 (Filial Campinas) — RODC (Read Only DC)
  - NEX-DR-RIBE01 (Filial Ribeirão) — RODC (Read Only DC)
- **OU (Organizational Units):**
  ```
  NEXCORE.local
  ├─ USUARIOS/
  │  ├─ ADMINISTRATIVO/
  │  ├─ ENGENHARIA/
  │  ├─ NOC_SUPORTE/
  │  └─ DIRETORIA/
  ├─ COMPUTADORES/
  │  ├─ ESTACOES_ADM/
  │  ├─ ESTACOES_ENG/
  │  ├─ ESTACOES_NOC/
  │  └─ SERVIDORES/
  └─ GRUPOS/
     ├─ G_Administrativos
     ├─ G_Engenharia
     ├─ G_NOC
     ├─ G_TI (LocalAdmin)
     └─ G_Diretoria
  ```

# Servidores - Sistemas Operacionais e Serviços

## NexCore Tecnologia

---

## 1. Resumo por Servidor

| Servidor | SO | Hostname | IP Principal | Serviços Principais | Local |
|----------|----|----------|--------------|---------------------|-------|
| DC01 (AD/DNS/DHCP) | **Windows Server 2022 Datacenter** | NEX-DC01 | 10.10.0.10 | Active Directory (DC), DNS, DHCP, GPO, WSUS, NTP | Matriz SP |
| FILE01 | Windows Server 2022 Standard | NEX-FILE01 | 10.10.0.11 | File Server, Print Server, Quotas, FSRM | Matriz SP |
| SQL01 | **Windows Server 2022 Standard** + **SQL Server 2022 Enterprise** | NEX-SQL01 | 10.10.0.12 | SQL Server 2022 (bancos ERP, CRM, Helpdesk) | Matriz SP |
| HV01 (Hyper-V) | Windows Server 2022 Datacenter (Hyper-V) | NEX-HV01 | 10.10.0.20 | Cluster Hyper-V NO 1 - VMs ERP, CRM, Monitoramento | Matriz SP |
| HV02 (Hyper-V) | Windows Server 2022 Datacenter (Hyper-V) | NEX-HV02 | 10.10.0.21 | Cluster Hyper-V NO 2 - Failover do HV01 | Matriz SP |
| BKP01 | **Ubuntu Server 24.04 LTS** | NEX-BKP01 | 10.10.0.30 | Veeam Backup & Replication v12 + Tape LTO-9 | Matriz SP |
| MON01 (VM) | **Ubuntu Server 24.04 LTS** | NEX-MON01 | 10.10.0.31 | Zabbix, Grafana, Prometheus, NOC Dashboards | VM no Cluster HV |
| WEB01 (VM) | Windows Server 2022 Standard + IIS | NEX-WEB01 | 10.10.0.32 | IIS, ASP.NET Core (Intranet, Portal do Cliente) | VM no Cluster HV |
| ERP01 (VM) | Windows Server 2022 Standard | NEX-ERP01 | 10.10.0.33 | Aplicativo ERP (backend) | VM no Cluster HV |
| CRM01 (VM) | Windows Server 2022 Standard | NEX-CRM01 | 10.10.0.34 | Dynamics 365 / CRM interno | VM no Cluster HV |
| DR-CAMP01 | Windows Server 2022 Standard (Hyper-V) | NEX-DR-CAMP01 | 10.20.0.10 | Replicação Hyper-V, RODC, Arquivos local | Filial Campinas |
| DR-RIBE01 | Windows Server 2022 Standard (Hyper-V) | NEX-DR-RIBE01 | 10.30.0.10 | Replicação Hyper-V, RODC, Arquivos local | Filial Ribeirão Preto |

---

## 2. Escolhas e Justificativas

### Por que Windows Server na maioria?
- **Active Directory (AD):** Gestão centralizada de 300 usuários, GPOs (políticas de segurança), DNS e DHCP integrados
- **SQL Server + ERP/CRM:** Plataforma corporativa padrão e com suporte
- **Hyper-V:** Cluster de 2 nós (HV01 + HV02) com **Failover Clustering** e Live Migration para alta disponibilidade
- **Licenciamento Datacenter:** Permite VMs ilimitadas nos hosts HV01/HV02, melhor custo-benefício

### Por que Linux em 2 servidores?
- **Backup (Ubuntu + Veeam):** Menor custo de licença, melhor desempenho para armazenamento de backup
- **Monitoramento (Ubuntu + Zabbix/Grafana):** Stack livre e amplamente utilizado para NOCs, sem custo de licença

---

## 3. Estações de Trabalho - SO por Perfil

| Perfil | SO | Versão | Licenciamento | Qtd |
|--------|----|--------|---------------|-----|
| Administrativo | **Windows 11 Pro** | 24H2 (Latest) | Microsoft 365 Business Premium (per user) | 108 |
| Operacional (Engenharia/NOC) | **Windows 11 Enterprise LTSC** | 24H2 LTSC | Volume License (CSP) | 162 |
| Especializado (Data Center / Eng) | **Windows 11 Enterprise** | 24H2 | Microsoft 365 E3 + W11 Enterprise VL | 30 |
| NOC 24x7 Kiosk | **Windows 11 IoT Enterprise LTSC** | 24H2 LTSC | Licenças Device | 12 estações video-wall |

### Justificativa LTSC para operações:
- Sem atualizações de feature por 10 anos → máquinas de NOC e engenharia não pegam updates que quebram ferramentas
- Sem bloatware (sem Copilot, sem Teams pré-instalado, sem loja) → mais leve e estável para operação 24x7

---

## 4. Virtualização (Hipervisores)

| Camada | Tecnologia | Nós | Objetivo |
|--------|------------|-----|----------|
| Hypervisor Hosts | **Microsoft Hyper-V 2022** em Failover Cluster | 2 nós (HV01 + HV02) | VMs de produção (ERP, CRM, WEB, MON) |
| Replicação DR | Replicação Hyper-V (Replica Broker) | 2 DR nodes (Campinas + Ribeirão) | Replicação assíncrona a 5 min das VMs críticas |
| Virtualização de desktop | VDI opcional futuro | - | A considerar para 2027 |
| Backup de VMs | Veeam B&R v12 | 1 servidor + 1 tape | Imagens nível VM, RTO 1h, RPO 1h |

## 5. Serviços Principais e Portas

| Serviço | Porta TCP/UDP | Origem | Destino |
|---------|--------------|--------|---------|
| AD LDAP | 389 / 636 (LDAPS) | Todos | DC01, DRs |
| DNS | 53 UDP/TCP | Todos | DC01 |
| DHCP | 67/68 UDP | Todos | DC01 |
| SMB Arquivos | 445 TCP | Interno | FILE01 |
| SQL TDS | 1433 TCP | Aplicativos | SQL01 |
| RDP Admin | 3389 TCP | IPs de TI | Todos os servidores |
| HTTPS Intranet | 443 TCP | Interno | WEB01 |
| Zabbix Agent | 10050 TCP | Todos | MON01 |
| Veeam | 2500-3300 TCP | Hosts HV | BKP01 |

# Endereçamento IP e VLANs

## NexCore Tecnologia

---

## 1. Faixas IP Privadas

| Local | Bloco CIDR | Faixa de IP | Descrição |
|-------|------------|-------------|-----------|
| **Matriz SP** | `10.10.0.0/16` | 10.10.0.1 - 10.10.255.254 | Sede Itaim Bibi / SP |
| **Filial Campinas** | `10.20.0.0/16` | 10.20.0.1 - 10.20.255.254 | Filial Campinas / SP |
| **Filial Ribeirão Preto** | `10.30.0.0/16` | 10.30.0.1 - 10.30.255.254 | Filial Ribeirão Preto / SP |
| **VPN Usuários (Always-On)** | `10.200.0.0/24` | 10.200.0.1 - 10.200.0.254 | Pool de endereços VPN |
| **Rede de Gerenciamento** | `10.250.0.0/24` | 10.250.0.1 - 10.250.0.254 | Out-of-band (iDRAC, ILO, switches) |

---

## 2. VLANs - Matriz SP (10.10.x.x /16) — Sub-redes /24 por VLAN

| VLAN ID | Nome da VLAN | Sub-rede CIDR | Gateway | Qtd. IPs úteis | Finalidade |
|---------|-------------|---------------|---------|---------------|------------|
| 1 | Nativa / Default | - | - | - | Desativada (segurança) |
| **10** | **MGMT - Gerência** | `10.10.0.0/24` | 10.10.0.1 | 254 | Switches, Roteadores, Firewall, iDRAC servidores |
| **20** | **Servidores** | `10.10.10.0/24` | 10.10.10.1 | 254 | DC01, FILE01, SQL01, HV01, HV02, BKP01, VMs (ERP, CRM, WEB, MON) |
| **30** | **Estações Administrativo** | `10.10.20.0/23` | 10.10.20.1 | 510 | RH, Financeiro, Diretoria, Marketing, Comercial (5 andares) |
| **40** | **Engenharia / Projetos** | `10.10.30.0/24` | 10.10.30.1 | 254 | Engenharia, Implementação, Laboratório IoT (3º andar) |
| **50** | **NOC / Helpdesk** | `10.10.40.0/24` | 10.10.40.1 | 254 | Operadores 24x7, Vídeowalls, Helpdesk (2º andar) |
| **60** | **VoIP** | `10.10.50.0/24` | 10.10.50.1 | 254 | Telefonia IP, Headsets, PABX IP |
| **70** | **WiFi Corporativo** | `10.10.60.0/22` | 10.10.60.1 | 1022 | Wi-Fi autenticado via 802.1x (RADIUS - AD CS) |
| **80** | **Impressoras** | `10.10.80.0/24` | 10.10.80.1 | 254 | Multifuncionais, Etiquetadoras Zebra |
| **90** | **IoT / Laboratório** | `10.10.90.0/24` | 10.10.90.1 | 254 | Sensores DHT22 dos racks, Arduino, automação do DC |
| **100** | **Convidados (DMZ-WiFi)** | `10.10.100.0/24` | 10.10.100.1 | 254 | Wi-Fi visitantes (captive portal, sem acesso rede interna) |
| **101** | **VPN Site-to-Site (Tunnel)** | `10.255.0.0/30` | - | 2 | IPSEC MPLS entre Matriz ↔ Campinas ↔ Ribeirão |

---

## 3. VLANs - Filial Campinas (10.20.x.x /16) — /24 por VLAN

| VLAN ID | Nome | Sub-rede | Gateway | Finalidade |
|---------|------|----------|---------|------------|
| 10 | MGMT | 10.20.0.0/24 | 10.20.0.1 | Gerência dos equipamentos |
| 20 | Servidores DR | 10.20.10.0/24 | 10.20.10.1 | DR-CAMP01, File Server local |
| 30 | Estações Admin | 10.20.20.0/23 | 10.20.20.1 | Administrativo / Comercial Regional |
| 40 | Engenharia Regional | 10.20.30.0/24 | 10.20.30.1 | Implementação, Projetos, Engenharia |
| 60 | VoIP | 10.20.50.0/24 | 10.20.50.1 | Telefonia |
| 70 | WiFi Corp | 10.20.60.0/23 | 10.20.60.1 | Wireless corporativo |
| 100 | WiFi Visitantes | 10.20.100.0/24 | 10.20.100.1 | Visitantes |

---

## 4. VLANs - Filial Ribeirão Preto (10.30.x.x /16) — /24 por VLAN

| VLAN ID | Nome | Sub-rede | Gateway | Finalidade |
|---------|------|----------|---------|------------|
| 10 | MGMT | 10.30.0.0/24 | 10.30.0.1 | Gerência |
| 20 | Servidores DR | 10.30.10.0/24 | 10.30.10.1 | DR-RIBE01 |
| 30 | Estações Admin | 10.30.20.0/23 | 10.30.20.1 | Admin / Comercial Agronegócio |
| 40 | Engenharia Regional | 10.30.30.0/24 | 10.30.30.1 | Equipes de projeto |
| 60 | VoIP | 10.30.50.0/24 | 10.30.50.1 | Telefonia |
| 70 | WiFi Corp | 10.30.60.0/23 | 10.30.60.1 | Wireless corporativo |
| 100 | WiFi Visitantes | 10.30.100.0/24 | 10.30.100.1 | Visitantes |

---

## 5. IPs Fixos (Reservados)

### Matriz SP - Servidores Principais
| IP Fixo | Equipamento | VLAN |
|---------|-------------|------|
| 10.10.0.1 | Gateway Layer 3 Core Switch (VLAN 10) | 10 |
| 10.10.0.10 | NEX-DC01 (AD/DNS/DHCP) | 10 |
| 10.10.0.11 | NEX-FILE01 | 20 |
| 10.10.0.12 | NEX-SQL01 | 20 |
| 10.10.0.20 | NEX-HV01 (host Hyper-V) | 20 |
| 10.10.0.21 | NEX-HV02 (host Hyper-V) | 20 |
| 10.10.0.30 | NEX-BKP01 (Veeam) | 20 |
| 10.10.0.31 | NEX-MON01 (Zabbix/Grafana) | 20 |
| 10.10.0.32 | NEX-WEB01 (IIS) | 20 |
| 10.10.0.33 | NEX-ERP01 | 20 |
| 10.10.0.34 | NEX-CRM01 | 20 |
| 10.10.0.254 | Next-Gen Firewall Palo Alto (interface LAN) | - |

### DHCP Scope (Estações dinâmicas)
| VLAN | Escopo DHCP | Lease | Exclusões (10 primeiros IPs fixos para impressoras/APs) |
|------|-------------|-------|-------|
| Admin (30) | 10.10.20.10 - 10.10.21.240 | 7 dias | 20.1 a 20.10 |
| Engenharia (40) | 10.10.30.20 - 10.10.30.240 | 7 dias | 30.1 a 30.20 |
| NOC (50) | 10.10.40.10 - 10.10.40.240 | 1 dia | 40.1 a 40.10 |
| WiFi (70) | 10.10.60.10 - 10.10.63.250 | 8 horas | 60.1 a 60.10 |
| IoT (90) | 10.10.90.100 - 10.10.90.200 | Infinito (reservas MAC) | 90.1 a 90.99 (sensores) |

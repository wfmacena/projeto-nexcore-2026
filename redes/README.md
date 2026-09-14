# Redes de Computadores - NexCore Tecnologia

## Objetivo
Projetar a conexão da matriz e das filiais de forma legível e dimensionada.

## Entregaveis:
- [x] Topologia da Matriz (Sao Paulo) + Diagrama texto ASCII - [conexao-matriz-filiais.md](conexao-matriz-filiais.md)
- [x] Topologia da Filial 1 (Campinas) - [conexao-matriz-filiais.md](conexao-matriz-filiais.md)
- [x] Topologia da Filial 2 (Ribeirao Preto) - [conexao-matriz-filiais.md](conexao-matriz-filiais.md)
- [x] Diagrama de conexao entre unidades (MPLS + IPSEC VPN backup) - [conexao-matriz-filiais.md](conexao-matriz-filiais.md)
- [x] Enderecamento IP (sub-redes, VLANs, IPs fixos, DHCP) - [enderecamento-ip.md](enderecamento-ip.md)
- [x] Lista de equipamentos de rede (switches, routers, firewalls, APs) - [equipamentos-rede.csv](equipamentos-rede.csv)
- [x] Planilha de orcamento de rede (CAPEX + OPEX 3 anos) - [equipamentos-rede.csv](equipamentos-rede.csv)
- [x] Protocolos, seguranca e QoS - [conexao-matriz-filiais.md](conexao-matriz-filiais.md)
- [ ] **Arquivo .pkt do Cisco Packet Tracer (Matriz SP)** - **OBRIGATORIO conforme professor: simulacao com 2+ VLANs, Switch L3, PCs, Servidor, ping inter-VLAN funcionando**

## Estrutura de arquivos:
```
redes/
├── README.md                 ← Este arquivo (resumo)
├── enderecamento-ip.md       ← VLANs, sub-redes /16 por local, IPs fixos, DHCP scopes
├── equipamentos-rede.csv     ← Planilha orçamento: switches, firewalls, APs, links, cabeamento
├── conexao-matriz-filiais.md ← Topologia geral ASCII, conexão MPLS, protocolos, segurança, QoS
├── topologia-matriz.png            ← (a ser adicionado: diagrama Visio/Draw.io)
├── topologia-filial-campinas.png   ← (a ser adicionado)
└── topologia-filial-ribeirao.png   ← (a ser adicionado)
```

---

## Resumo Executivo - D3

### Conexões Principais:
| Link | Tipo | Largura de Banda | Failover |
|------|------|-----------------|----------|
| Internet Matriz SP | Fibra GIGA x2 (Vivo + Claro) | 1 Gbps cada | 4G/5G 300 Mbps |
| Internet Filiais | Fibra GIGA cada | 1 Gbps | 4G/5G 200 Mbps |
| Matriz ↔ Campinas | MPLS L3VPN dedicado | 500 Mbps | IPSEC sobre internet |
| Matriz ↔ Ribeirão Preto | MPLS L3VPN dedicado | 300 Mbps | IPSEC sobre internet |
| VPN Usuários Remotos | Always-On VPN (IKEv2) no Palo Alto | 500 usuários concorrentes | - |

### Segmentação VLANs (Matriz SP):
| VLAN | Nome | Sub-rede | Finalidade |
|------|------|----------|------------|
| 10 | MGMT | 10.10.0.0/24 | Switches, iDRAC, firewall |
| 20 | Servidores | 10.10.10.0/24 | DC01, SQL, HV cluster, VMs |
| 30 | Estações Admin | 10.10.20.0/23 | RH, Financeiro, Diretoria |
| 40 | Engenharia | 10.10.30.0/24 | Projetos, Implementação, IoT Lab |
| 50 | NOC | 10.10.40.0/24 | Operadores 24x7, Videowalls |
| 70 | WiFi Corp | 10.10.60.0/22 | 802.1x EAP-TLS (RADIUS ClearPass) |
| 90 | IoT / Sensores DC | 10.10.90.0/24 | DHT22, Arduino, automação racks |
| 100 | Convidados | 10.10.100.0/24 | Captive portal, sem acesso interno |

### Custos (3 anos):
| Item | Valor (BRL) |
|------|-------------|
| Equipamentos de Rede (CAPEX) | R$ 1.520.500 |
| Links e Internet (OPEX 3 anos) | R$ 1.929.600 |
| **TOTAL D3 (3 anos)** | **R$ 3.450.100** |

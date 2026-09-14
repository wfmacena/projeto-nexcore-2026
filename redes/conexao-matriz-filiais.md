# Conexão Matriz ↔ Filiais (Topologia Interligação)

## NexCore Tecnologia

---

## 1. Diagrama de Alto Nível (Topologia Geral)

```
                 ┌─────────────────────────────────────┐
                 │       INTERNET / ISPs DIVERSOS       │
                 │     (Vivo GIGA + Claro GIGA x2)      │
                 └───────┬──────────────────┬───────────┘
                         │ 1G Fibra         │
                         ▼                  ▼
              ┌──────────────────┐  ┌──────────────────┐
              │  Juniper MX204   │  │  Juniper MX204   │  ← Matriz: 2 roteadores WAN (BGP)
              └───────┬──────────┘  └───────┬──────────┘
                      │                     │
                      └─────────┬───────────┘
                                ▼
              ┌─────────────────────────────────────┐
              │     FIREWALL PALO ALTO PA-460        │
              │    (NGFW, VPN Site-to-Site IPSEC,    │
              │     Always-On VPN, NAT, IPS)         │
              └───────────────┬─────────────────────┘
                              │ Tronco 802.1Q VLANs
                              ▼
              ┌─────────────────────────────────────┐
              │   CORE SWITCH ARUBA 8360 (L3)       │
              ├─────── VLAN TRUNK 10/20/30/... ─────┤
              └──┬──────────┬──────────┬──────────┬──┘
                 │          │          │          │
           ┌─────▼──┐ ┌────▼────┐ ┌──▼──────┐ ┌─▼──────┐
           | ACCESS | | SERVIDORES  | |  NOC   | |  WiFi  |
           | SW 6200| | DC01,HV01.. | |  24x7  | |  AP-615|
           └─────────┴──────────────┴─────────┴─────────┘
                 │
                 │ MPLS + IPSEC TUNNEL (Backup pela internet)
                 │
   ┌─────────────┴──────────────────────────────────┐
   │                                                 │
   ▼ MPLS 500 Mbps                                   ▼ MPLS 300 Mbps
┌─────────────────────────┐               ┌──────────────────────────┐
│  FILIAL CAMPINAS        │               │  FILIAL RIBEIRÃO PRETO   │
│  Roteador: NFX250 SDWAN │               │  Roteador: NFX250 SDWAN  │
│  Firewall: PA-220R      │               │  Firewall: PA-220R       │
│  Core: 6300M 48G        │               │  Core: 6300M 24G         │
│  APs WiFi 6: 15         │               │  APs WiFi 6: 10          │
│  DR-CAMP01 (Hyper-V)    │               │  DR-RIBE01 (Hyper-V)     │
│  87 funcionários        │               │  63 funcionários         │
└─────────────────────────┘               └──────────────────────────┘
```

---

## 2. Detalhe da Topologia Física - Matriz SP (Andares)

```
        DATACENTER (Subsolo)
     ┌─────────────────────────────┐
     │ Rack 42U x3                 │
     │ - Core SW (Aruba 8360)      │
     │ - HV01, HV02, SQL01, FILE01 │
     │ - DC01, BKP01               │
     │ - Patch panels / cabos      │
     └────────────┬────────────────┘
                  │ Fibra OM4 10G
                  │
   ┌──────────────┴───────────────┐
   │  TELECOM ROOM - CADA ANDAR   │
   │  6 andares x 1 Sala Telecom  │
   │  - Access Switch 6200F PoE+  │
   │  - Patch Panel 48p CAT6A     │
   │  - 2x APs Wi-Fi 6 por andar  │
   └──────────────────────────────┘
```

---

## 3. Protocolos Utilizados

| Camada | Protocolo / Tecnologia | Finalidade |
|--------|-------------------------|------------|
| Física | CAT6A (cobre), OM4 (fibra multimodo) | 10 Gbps cabeamento horizontal |
| Link | 802.1Q VLAN tagging, LACP (Agregação de Links 20G entre Core e Access) | Redundância e separação de tráfego |
| Rede | IPv4, OSPF (roteamento interno) | Rotear entre VLANs e filiais |
| WAN | BGP (ISP duplo), MPLS L3VPN (operadora) | Conexão de longa distância |
| VPN | IKEv2/IPSEC (Always-On usuários), IPSEC (túneis site-to-site) | Acesso seguro e DR fallback |
| Autenticação | 802.1x EAP-TLS (RADIUS - ClearPass integrado com AD) | WiFi e porta switch corporativo |
| QoS | DSCP marking (EF para VoIP, AF41 para ERP, BE para convidados) + LLDP-MED | Prioridade para voz e aplicações críticas |
| Monitoramento | SNMP v3, Syslog, NetStream/sFlow, Zabbix + Grafana | NOC 24x7 |
| Segurança | ACLs por VLAN no Core, Palo Alto NGFW (IPS/AV/URL-Filtering) | Micro-segmentação e ameaças |

---

## 4. Segurança da Rede

| Pilar | Implementação |
|-------|---------------|
| **Segmentação** | VLANs separadas + ACLs no Core L3 impedem tráfego direto, ex: IoT/VLAN 90 não pode acessar AD/VLAN 20 |
| **Zero Trust** | Nenhuma VLAN confia em outra; autenticação sempre via 802.1x ou firewall |
| **Proteção perimetral** | NGFW Palo Alto com IPS, anti-malware, sandbox e filtro de URL |
| **Bloqueio ARP / DHCP Snooping** | Habilitado em todos os switches access (evita ARP spoofing e rogue DHCP) |
| **AAA / Contas admin** | Tacacs+ (Aruba ClearPass) para logar em switches/roteadores (auditoria) |
| **Criptografia trânsito** | IPSEC nos túneis inter-filiais; sempre HTTPS, LDAPS, DNS sobre HTTPS |
| **Rede convidados** | VLAN 100 → captive portal → sai DIRETO para internet (não tem rota para VLANs internas) |

---

## 5. Ferramentas para o Projeto (Entregáveis D3)

| Item | Ferramenta | Link |
|------|-----------|------|
| Topologia lógica / física | Draw.io (diagrams.net) + Visio Pro | (serão incluídas imagens aqui) |
| Simulação | Cisco Packet Tracer (arquivo .pkt) | (será incluído) |
| Planta baixa / cabeamento | LibreCAD / AutoCAD | (PDF na pasta evidencias/) |
| Planilha orçamento | CSV nesta pasta | [equipamentos-rede.csv](equipamentos-rede.csv) |

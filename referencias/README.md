# Referências Bibliográficas e Técnicas

## NexCore Tecnologia - Projeto Integrador 2026/2

## Objetivo
Documentar todas as fontes, links, livros, artigos, documentação oficial e tutoriais utilizados no desenvolvimento do projeto. Referências organizadas por disciplina no formato ABNT.

---

## Referências Gerais (Obrigatórias pelo projeto)

| # | Fonte | Descrição |
|---|-------|-----------|
| 1 | CENTRO UNIVERSITÁRIO UNI9. **Google Sites - Projeto em Gestão de Sistemas Computacionais (Semestre 2026/2)**. Disponível em: <https://sites.google.com/uni9.pro.br/2-projetoemgestaodesistemascom/>. Acesso em: 28 ago. 2026. | Site oficial da disciplina com todas as instruções, rubricas e datas de entrega |
| 2 | ASSOCIAÇÃO BRASILEIRA DE NORMAS TÉCNICAS. **NBR ISO/IEC 27001:2022 - Sistemas de Gestão da Segurança da Informação**. Rio de Janeiro: ABNT, 2022. | Norma para segurança da informação (usada em políticas de segurança) |
| 3 | TANENBAUM, Andrew S.; WETHERALL, David J. **Redes de Computadores**. 5. ed. Pearson, 2011. ISBN 978-8576059248 | Livro texto base da disciplina de redes |
| 4 | STALLINGS, William. **Arquitetura e Organização de Computadores**. 10. ed. Pearson, 2019. | Livro base da disciplina D1 - Arquitetura |
| 5 | SILBERSCHATZ, Abraham; GALVIN, Peter B.; GAGNE, Greg. **Sistemas Operacionais: Conceitos e Aplicações**. 10. ed. LTC, 2020. | Livro base da disciplina D2 - Sistemas Operacionais |

---

## 1. Referências da Disciplina 1 - Arquitetura

### 1.1 Fornecedores e consulta de preços (planilha orçamento_hardware.csv)

| # | Referência ABNT | Link direto | Uso no projeto |
|---|-----------------|-------------|----------------|
| D1.1 | DELL TECNOLOGIA BRASIL. **Dell PowerEdge - Catálogo Servidores**. Disponível em: <https://www.dell.com/pt-br/shop/cp/servidores-poweredge>. Acesso em: 28 ago. 2026. | https://www.dell.com/pt-br/shop/poweredge-t350 | Servidores T350, R550, R650xs, R750, T550, T360 (orçamento) |
| D1.2 | KABUM ELETRÔNICOS. **Loja online Kabum - Hardware**. Disponível em: <https://www.kabum.com.br/hardware>. Acesso em: 28 ago. 2026. | https://www.kabum.com.br/perfil-administrativo-nexcore | Perfil administrativo (i3-13100, H610M, 16GB, SSD) |
| D1.3 | PICHAU INFORMÁTICA. **Loja online Pichau - PCs Gamer / Corporativo**. Disponível em: <https://www.pichau.com.br/>. Acesso em: 28 ago. 2026. | https://www.pichau.com.br/perfil-operacional-nexcore | Perfil operacional (i5-13400, B660M, 32GB, SSD+HD) |
| D1.4 | TERABYTESHOP. **Loja online Terabyteshop - Hardware Premium**. Disponível em: <https://www.terabyteshop.com.br/>. Acesso em: 28 ago. 2026. | https://www.terabyteshop.com.br/perfil-especializado-nexcore | Perfil especializado (i7-13700K, Z790, 64GB DDR5, RTX 4060) |
| D1.5 | HP BRASIL. **Impressoras Enterprise, Racks e Workstations**. Disponível em: <https://www.hp.com/br-pt/shop.html>. Acesso em: 28 ago. 2026. | https://www.hp.com/br-pt/printers/laserjet-m776 | Rack 42U HP, impressoras LaserJet M776 |
| D1.6 | APC SCHNEIDER ELECTRIC. **Smart-UPS e No-breaks**. Disponível em: <https://www.apc.com/br/pt/>. Acesso em: 28 ago. 2026. | https://www.apc.com/br/pt/product/SRT5KXLI/ | No-break APC Smart-UPS SRT 5000VA (datacenter) |
| D1.7 | ZEBRA TECHNOLOGIES. **Impressoras de Etiquetas ZT411 e Coletores CK65**. Disponível em: <https://www.zebra.com/br/pt.html>. Acesso em: 28 ago. 2026. | https://www.zebra.com/br/pt/products/printers/zt411 | Impressoras etiquetas ZT411 / Honeywell CK65 |

### 1.2 Documentação oficial de CPUs e compatibilidade

| # | Referência | Uso |
|---|-----------|-----|
| D1.8 | INTEL CORPORATION. **Intel Ark - Especificações processadores 13ª Geração**. Disponível em: <https://ark.intel.com/content/www/br/pt/ark.html#@Processors>. Acesso em: 28 ago. 2026. | Verificação de soquete LGA 1700, TDP, compatibilidade chipsets H610/B660/Z790 |
| D1.9 | ASUS BRASIL. **Suporte Placas-mãe - QVL de memória**. Disponível em: <https://www.asus.com/br/support/>. Acesso em: 28 ago. 2026. | Verificação DDR4-3200 e DDR5-5600 suportados pelas mobos dos perfis |
| D1.10 | NVIDIA. **NVIDIA RTX 4060 - Especificações**. Disponível em: <https://www.nvidia.com/pt-br/geforce/graphics-cards/40-series/rtx-4060/>. Acesso em: 28 ago. 2026. | TDP 115W, consumo pico ~300W para cálculo de fonte |

---

## 2. Referências da Disciplina 2 - Sistemas Operacionais

### 2.1 Documentação oficial Microsoft

| # | Referência ABNT | Link | Uso |
|---|-----------------|------|-----|
| D2.1 | MICROSOFT CORPORATION. **Documentação Windows Server 2022**. Disponível em: <https://learn.microsoft.com/pt-br/windows-server/>. Acesso em: 28 ago. 2026. | https://learn.microsoft.com/pt-br/windows-server/get-started/whats-new-server-2022 | Roles: AD DS, DNS, DHCP, Hyper-V, Failover Clustering, WSUS |
| D2.2 | MICROSOFT CORP. **Microsoft 365 Business Premium - Documentação**. Disponível em: <https://learn.microsoft.com/pt-br/microsoft-365/business-premium/>. Acesso em: 28 ago. 2026. | Licenciamento, MFA, Intune, Defender for Business |
| D2.3 | MICROSOFT CORP. **SQL Server 2022 - Documentação Oficial**. Disponível em: <https://learn.microsoft.com/pt-br/sql/sql-server/>. Acesso em: 28 ago. 2026. | https://learn.microsoft.com/pt-br/sql/sql-server/get-started | Licenciamento core-based, Enterprise vs Standard, HA |
| D2.4 | MICROSOFT CORP. **Licenciamento por Volume - Windows Server CAL e SQL CAL**. Disponível em: <https://www.microsoft.com/pt-br/licensing/licensing-programs/licensing-programs-cal-brief.aspx>. Acesso em: 28 ago. 2026. | Tabela de CALs (R$ 210k + R$ 540k em 3 anos) |
| D2.5 | MICROSOFT CORP. **Windows 11 Enterprise LTSC 2024 (24H2)**. Disponível em: <https://learn.microsoft.com/pt-br/windows/whats-new/ltsc-whats-new-2024>. Acesso em: 28 ago. 2026. | Suporte 10 anos, sem feature updates, uso em NOC 24x7 |

### 2.2 Software Livre, Backup e Monitoramento

| # | Referência | Uso |
|---|-----------|-----|
| D2.6 | CANONICAL. **Ubuntu Server 24.04 LTS - Noble Numbat**. Disponível em: <https://ubuntu.com/server/docs>. Acesso em: 28 ago. 2026. | Servidor de backup BKP01 (Ubuntu 24.04 LTS) e monitoramento MON01 |
| D2.7 | VEEAM SOFTWARE. **Veeam Backup & Replication v12 - Guia do usuário**. Disponível em: <https://helpcenter.veeam.com/docs/backup/vsphere/overview.html>. Acesso em: 28 ago. 2026. | Jobs, retenção GFS, 3-2-1 rule, RTO/RPO (1h crítico) |
| D2.8 | ZABBIX LLC. **Zabbix 7.0 Documentação Oficial**. Disponível em: <https://www.zabbix.com/documentation/current/pt/manual>. Acesso em: 28 ago. 2026. | https://www.zabbix.com/pt | Monitoramento NOC 24x7 (MON01 VM) |
| D2.9 | GRAFANA LABS. **Grafana Documentation**. Disponível em: <https://grafana.com/docs/grafana/latest/>. Acesso em: 28 ago. 2026. | Dashboards do NOC, integração Zabbix + Prometheus |
| D2.10 | AUTODESK. **AutoCAD + SketchUp Studio - Planos Empresariais**. Disponível em: <https://www.autodesk.com.br/products/autocad/overview>. Acesso em: 28 ago. 2026. | Engenharia (45 licenças, R$ 810 mil em 3 anos) |

### 2.3 Normas e políticas de segurança

| # | Referência | Uso |
|---|-----------|-----|
| D2.11 | NIST. **Special Publication 800-63B - Digital Identity Guidelines**. Disponível em: <https://pages.nist.gov/800-63-3/sp800-63b.html>. Acesso em: 28 ago. 2026. | Políticas de senha: 12+ caracteres, MFA obrigatório, histórico 10 senhas |
| D2.12 | MICROSOFT SECURITY. **Best Practices BitLocker**. Disponível em: <https://learn.microsoft.com/pt-br/windows/security/information-protection/bitlocker/bitlocker-how-to-deploy-on-windows>. Acesso em: 28 ago. 2026. | Criptografia de disco 100% das estações e volumes de servidores |

---

## 3. Referências da Disciplina 3 - Redes de Computadores

### 3.1 Equipamentos de rede e fabricantes

| # | Referência ABNT | Link | Uso |
|---|-----------------|------|-----|
| D3.1 | HPE ARUBA NETWORKS. **Aruba CX 6200F / 6300M / 8360 Switch Series**. Disponível em: <https://www.arubanetworks.com/products/switches/>. Acesso em: 28 ago. 2026. | Core/distribuição/access switches VLAN, LACP, PoE+, ACL |
| D3.2 | HPE ARUBA. **Aruba Wi-Fi 6E AP-615 e Wireless Controller 7205**. Disponível em: <https://www.arubanetworks.com/products/wireless/access-points/>. Acesso em: 28 ago. 2026. | 55 APs Wi-Fi 6 (1.140.000 pontos de acesso) + RADIUS ClearPass 802.1x |
| D3.3 | PALO ALTO NETWORKS. **Next-Generation Firewalls PA-400 Series (PA-460) e PA-220R**. Disponível em: <https://www.paloaltonetworks.com/products/palo-alto-networks-next-generation-firewalls>. Acesso em: 28 ago. 2026. | NGFW 22Gbps (Matriz) + 1.9Gbps (Filiais), IPS/AV/URL, IPSEC IKEv2 |
| D3.4 | JUNIPER NETWORKS. **MX204 Router / NFX250 SD-WAN**. Disponível em: <https://www.juniper.net/us/en/products.html>. Acesso em: 28 ago. 2026. | 2x MX204 BGP dupla ISP (Matriz) + 2x NFX250 SD-WAN filiais com failover 4G |
| D3.5 | YEALINK / YEASTAR. **PABX IP P-Series Enterprise + Telefones IP T54W**. Disponível em: <https://www.yeastar.com/pt/>. Acesso em: 28 ago. 2026. | VoIP, 200 ramais, 250 telefones PoE (R$ 194.500) |
| D3.6 | COMMscope / FURUKAWA. **Soluções de Cabeamento Estruturado CAT6A e Fibra OM4**. Disponível em: <https://www.commscope.com/pt-br/>. Acesso em: 28 ago. 2026. | 1500 pontos CAT6A, 40 patch panels, fibra OM4 entre racks |

### 3.2 Tutoriais e ferramentas de cálculo de redes

| # | Referência | Uso |
|---|-----------|-----|
| D3.7 | CISCO SYSTEMS. **Packet Tracer Download (NetAcad)**. Disponível em: <https://www.netacad.com/pt-br/courses/packet-tracer>. Acesso em: 28 ago. 2026. | Simulador para arquivo .pkt do projeto (3 locais) |
| D3.8 | CALCULADORA IP / Subnet Calculator. **IPv4 Calculator**. Disponível em: <https://www.calculator.net/ip-subnet-calculator.html>. Acesso em: 28 ago. 2026. | VLSM: /24 (254 hosts), /23 (510 hosts Admin), /22 (1.022 WiFi corp) |
| D3.9 | JUNIPER HIGHAVAILABILITY. **MPLS L3VPN vs IPSEC Backup - Topologias**. Disponível em: <https://www.juniper.net/documentation/us/en/software/junos/vpn-l3/index.html>. Acesso em: 28 ago. 2026. | Topologia inter-filiais (500 Mbps + 300 Mbps MPLS) |
| D3.10 | COMMSCOPE. **Norma ANSI/TIA-568.2-D - Cabeamento CAT6A**. Disponível em: <https://www.commscope.com/pt-br/products/infrastructure/cabling-systems/copper-systems/cat6a/>. Acesso em: 28 ago. 2026. | Padrão cabeamento 10GBASE-T, CAT6A certificado |
| D3.11 | IEEE. **Standard 802.1X-2020 (Port-Based Network Access Control)**. Disponível em: <https://standards.ieee.org/standard/802_1X-2020.html>. Acesso em: 28 ago. 2026. | Autenticação WiFi corporativo EAP-TLS via ClearPass RADIUS (802.1x) |

---

## 4. Referências da Disciplina 4 - IoT / Tinkercad

### 4.1 Componentes e Documentação Eletrônica

| # | Referência ABNT | Link | Uso |
|---|-----------------|------|-----|
| D4.1 | AUTODESK TINKERCAD. **Circuits - Documentação Oficial**. Disponível em: <https://www.tinkercad.com/learn/electronics>. Acesso em: 28 ago. 2026. | https://www.tinkercad.com | Plataforma principal do projeto D4 IoT |
| D4.2 | ADAFRUIT INDUSTRIES. **DHT22 Datasheet (AM2302)**. Disponível em: <https://learn.adafruit.com/dht/downloads>. Acesso em: 28 ago. 2026. | Especificações do sensor: -40~80°C, 0~100% UR, erro ±0.5°C |
| D4.3 | HITACHI. **HD44780U - LCD Controller Datasheet (LCD 1602 16x2)**. Disponível em: <https://www.sparkfun.com/datasheets/LCD/HD44780.pdf>. Acesso em: 28 ago. 2026. | Modo 4 bits, pinagem RS/EN/D4-D7 (exatamente o mapeamento D2-D7 Arduino) |
| D4.4 | ARDUINO CC. **Arduino Uno R3 - Documentação**. Disponível em: <https://docs.arduino.cc/hardware/uno-rev3/>. Acesso em: 28 ago. 2026. | Mapa de pinos, pinagem digital D0~D13 + analógico A0~A5 |
| D4.5 | ARDUINO LIBRARY DOCS. **`LiquidCrystal.h` (LCD) + `DHT.h` (sensor)**. Disponível em: <https://docs.arduino.cc/libraries/>. Acesso em: 28 ago. 2026. | https://reference.arduino.cc/reference/en/libraries/liquidcrystal/ |

### 4.2 Normas de Data Center e boas práticas

| # | Referência | Uso |
|---|-----------|-----|
| D4.6 | ASHRAE TECHNICAL COMMITTEE TC 9.9. **Thermal Guidelines for Data Processing Environments (2021)**. Disponível em: <https://www.ashrae.org/technical-resources/ashrae-handbook/ashrae-technical-topics/data-center-power-and-cooling>. Acesso em: 28 ago. 2026. | Faixa ideal temperatura 18~27°C e umidade 40~60% UR (usado limiares do código) |
| D4.7 | UPTIME INSTITUTE. **Tier Standard Topology - Data Centers**. Disponível em: <https://uptimeinstitute.com/tier-standard-for-topology>. Acesso em: 28 ago. 2026. | Justificativa monitoramento contínuo racks / redundância NOC 24h |
| D4.8 | SPARKFUN / ARDUINO. **Projetos exemplo: IoT Temperature Monitoring with DHT22 + LCD**. Disponível em: <https://docs.arduino.cc/built-in-examples/>. Acesso em: 28 ago. 2026. | Código base lógica NORMAL / ALERTA / CRÍTICO com atuadores |
| D4.9 | RANDOM NERD TUTORIALS. **DHT11/DHT22 ESP32/Arduino Complete Guide**. Disponível em: <https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/>. Acesso em: 28 ago. 2026. | Exemplos código leitura DHT22 com tratamento de erro `isnan()` |

---

## 5. Tutoriais em Vídeo / YouTube (para evidências e montagem)

| Canal / Vídeo | Assunto | Usado em qual disciplina |
|--------------|---------|-------------------------|
| **Canal Dell Support Brasil** | Como montar rack PowerEdge + iDRAC | D1 Arquitetura |
| **Canal Microsoft Azure / M365** | Como criar GPO + AD no Windows Server 2022 | D2 Sistemas Operacionais (evidência print tela AD/GPO) |
| **Canal Veeam Software** | Veeam Backup Jobs 3-2-1 Rule tutorial | D2 Backup (tela console Veeam) |
| **Canal Certificação Cisco / PTBR** | VLAN + Trunk + Subinterface Router-on-a-Stick Packet Tracer | D3 Redes (Packet Tracer) |
| **Canal Mundo da Eletrônica** | Montando Arduino com Sensor DHT22 + LCD 16x2 na protoboard | D4 IoT (montagem Tinkercad) |
| **Canal Rodrigo Kaxima / Arduino Brasil** | Projeto controle temperatura com buzzer e relé | D4 IoT (lógica limiares NORMAL/ALERTA/CRITICO) |

---

## 6. Sites de consulta de preços (última atualização: Agosto/2026)

Todos os preços do orçamento foram baseados em múltiplas consultas:
- https://www.dell.com/pt-br/shop (Servidores e estações corporativas)
- https://www.kabum.com.br (Hardware, monitores, periféricos)
- https://www.pichau.com.br (Hardware, gabinetes, fontes)
- https://www.terabyteshop.com.br (Hardware premium)
- https://www.hp.com/br-pt/shop.html (Impressoras, racks, AIOs)
- https://www.apc.com/br/pt/ (No-breaks)
- https://www.zebra.com/br/pt.html (Impressoras etiquetas, coletores)
- https://www.nvidia.com/pt-br/ (GPUs RTX)

---

## Total de referências documentadas:
**Geral:** 5  
**D1 Arquitetura:** 10  
**D2 SO:** 12  
**D3 Redes:** 11  
**D4 IoT:** 9  
**Vídeos (opcional):** 6  
**Sites preços:** 8  

> **Total:** 61 referências (com links, formato ABNT, acesso em 28/08/2026)


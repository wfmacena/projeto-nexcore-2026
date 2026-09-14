# Disciplina 1 - Arquitetura e Organização de Computadores

---

## 1. Visão Geral

Definição de todos os equipamentos de hardware da NexCore Tecnologia:
- **Perfis de computadores** (administrativo, operacional, especializado)
- **Configuracao detalhada** (CPU, placa-mae, RAM, armazenamento, etc.)
- **Compatibilidade** entre componentes
- **Servidores** e infraestrutura de datacenter
- **Orcamento detalhado** com valores, fornecedores e justificativa

---

## 2. Perfis de Computadores

### 2.1 Perfil ADMINISTRATIVO (Escritório)

**Setores de uso:** Diretoria, RH, Financeiro, Contábil, Comercial, Qualidade, Suprimentos, Marketing

**Aplicações:** Microsoft Office (Word/Excel/PowerPoint/Outlook), navegador web, sistema ERP corporativo, CRM, videoconferência (Teams/Zoom), acesso a arquivos em rede.

**Quantidade total:** 108 unidades
| Local | Quantidade |
|-------|-----------|
| Matriz SP | 55 |
| Filial Campinas | 31 |
| Filial Ribeirão Preto | 22 |

---

### 2.2 Perfil OPERACIONAL (Engenharia, Projetos, NOC e Helpdesk)

**Setores de uso:** Engenharia de Projetos, Implementação, NOC 24x7, Helpdesk/Suporte, Qualidade, Almoxarifado Técnico

**Aplicações:** Sistemas de monitoramento (Zabbix/Grafana), AutoCAD, Ferramentas de simulação, Software de gestão de projetos (Jira), ERP, CRM, Acesso remoto a servidores.

**Quantidade total:** 162 unidades
| Local | Quantidade |
|-------|-----------|
| Matriz SP | 83 |
| Filial Campinas | 46 |
| Filial Ribeirão Preto | 33 |

---

### 2.3 Perfil ESPECIALIZADO (TI / Data Center / BI / Engenharia)

**Setores de uso:** Administração de Data Center, Engenharia de Redes, BI / Análise de Dados, Desenvolvimento, Segurança da Informação, Laboratório de IoT.

**Aplicações:** Virtualização (VMware/Hyper-V), Monitoramento (Zabbix), AD/GPO/WSUS, BI (Power BI), Banco de Dados, Simuladores de rede (Packet Tracer, GNS3), AutoCAD/Revit, Compilação de código, Tinkercad.

**Quantidade total:** 30 unidades
| Local | Quantidade |
|-------|-----------|
| Matriz SP | 18 |
| Filial Campinas | 8 |
| Filial Ribeirão Preto | 4 |

---

## 3. Configuracao Detalhada por Perfil

### 3.1 Computador Administrativo

| Componente | Modelo Especifico | Quantidade | Justificativa |
|-----------|------------------|-----------|---------------|
| **CPU** | Intel Core i3-13100 (4 nucleos, 3.4GHz) | 1 | Baixo consumo, suficiente para Office, navegador e ERP |
| **Placa-mae** | ASUS PRIME H610M-E (LGA 1700, chipset H610) | 1 | Soquete compativel com i3-13100, 2 slots DDR4, USB 3.2 |
| **RAM** | 16GB DDR4-3200 (2x8GB) Kingston Fury Beast | 2 | Dual-channel para multitarefa (planilhas + Teams + navegador) |
| **Armazenamento SSD** | SSD NVMe 512GB Kingston NV2 | 1 | Velocidade para boot rapido e carregamento de aplicativos |
| **GPU** | Grafico integrado Intel UHD 730 | 0 | Nao ha necessidade de GPU dedicada para este perfil |
| **Rede** | Placa de rede Gigabit integrada + Wi-Fi 6 AX201 | 1 | Conexao cabeada (prioritaria) e Wi-Fi para contingencia |
| **Monitor** | Monitor LED 21.5" Dell P2222H (Full HD, IPS, DP+HDMI) | 1 | Tamanho adequado para escritorio, qualidade IPS |
| **Perifericos** | Teclado + Mouse Dell KM5221W, Webcam Logitech C270, Headset Microsoft Modern | 1 kit | Produtividade + videoconferencia |
| **Fonte** | Fonte 400W 80 Plus Bronze Corsair CV450 | 1 | Estabilidade e eficiencia energetica |
| **Gabinete** | Gabinete Mid Tower Thermaltake Versa H18 | 1 | Compacto, boa ventilacao, compatibilidade ATX/mATX |

**Compatibilidade verificada:**
- Soquete LGA 1700: Compativel (i3-13100 + H610)
- Chipset H610 suporta DDR4-3200: Sim
- Fonte 400W: Suficiente para o consumo total do sistema (~150W pico)
- Dimensoes: Cabem no gabinete Versa H18 sem conflitos
- Expansao: Possui 1 slot M.2 (usado), 2 slots DDR4 (usados), 4 ports SATA (livres)

---

### 3.2 Computador Operacional

| Componente | Modelo Especifico | Quantidade | Justificativa |
|-----------|------------------|-----------|---------------|
| **CPU** | Intel Core i5-13400 (10 nucleos, 2.5GHz) | 1 | Mais performance para WMS/TMS e multitasking em ambiente 24h |
| **Placa-mae** | ASUS PRIME B660M-A (LGA 1700, chipset B660) | 1 | 4 slots RAM, mais ports USB, melhor resfriamento para uso continuo |
| **RAM** | 32GB DDR4-3200 (2x16GB) Corsair Vengeance | 2 | Maior memoria para sistemas WMS pesados e varias abas abertas |
| **Armazenamento SSD** | SSD NVMe 1TB WD Blue SN580 | 1 | Mais espaco para logs do sistema e cache WMS |
| **Armazenamento HD** | HD 2TB Toshiba MG08ACA (Enterprise) | 1 | Persistencia de dados locais, resistente para uso 24h |
| **GPU** | Grafico integrado Intel UHD 730 | 0 | Nao necessario |
| **Rede** | Placa de rede Gigabit Dual Intel I226-V (cabeada) | 1 | Duas portas para redundancia/rede separada WMS x corporativa |
| **Monitor** | Monitor Touch 24" HP ProOne 440 G9 (Full HD, AIO touch) | 1 | Touch screen para operacao rapida nas docas sem mouse |
| **Perifericos** | Teclado + Mouse ABNT2 resistentes (HP K1500), Leitor codigo barras USB Honeywell | 1 kit | Durabilidade para uso em areas de armazem |
| **Fonte** | Fonte 500W 80 Plus Bronze Seasonic S12III | 1 | Maior estabilidade para funcionamento 24h por dia |
| **Gabinete** | Gabinete Industrial Mid Tower Cooler Master N400 | 1 | Mais robusto, melhor ventilacao, com filtros de poeira |

**Compatibilidade verificada:**
- Soquete LGA 1700: Compativel (i5-13400 + B660)
- 4 slots DDR4: 2 usados (32GB), 2 livres para upgrade futuro
- Fonte 500W: Suficiente (~200W pico)
- Filtros de poeira do gabinete: Essencial para areas de CD (poupas de algodao, papel)

---

### 3.3 Computador Especializado (TI / BI / Design)

| Componente | Modelo Especifico | Quantidade | Justificativa |
|-----------|------------------|-----------|---------------|
| **CPU** | Intel Core i7-13700K (16 nucleos, 3.4GHz) | 1 | Alto desempenho para compilacao, BI, virtualizacao |
| **Placa-mae** | ASUS TUF GAMING Z790-PLUS (LGA 1700, Z790) | 1 | Suporta overclock, 4 slots DDR5, 3 slots M.2 NVMe |
| **RAM** | 64GB DDR5-5600 (2x32GB) Kingston Fury Beast | 2 | Memoria alta para maquinas virtuais e Power BI |
| **Armazenamento SSD 1** | SSD NVMe 2TB Samsung 990 PRO (Sistema) | 1 | Velocidade maxima para sistema e arquivos de projeto |
| **Armazenamento SSD 2** | SSD NVMe 1TB Kingston NV2 (Dados / VM) | 1 | Disco dedicado para VMs e banco de dados local |
| **GPU** | NVIDIA RTX 4060 8GB Gigabyte OC | 1 | Aceleracao GPU para BI, Design e renderizacao |
| **Rede** | Placa de rede Gigabit Intel I226-V + Wi-Fi 6E Intel AX211 | 1 | Conectividade completa, cabo + Wi-Fi 6E |
| **Monitor** | Monitor 27" QHD Dell S2722QC (2560x1440, IPS) | 2 | Dois monitores 2K para multitasking, qualidade de imagem |
| **Perifericos** | Teclado Mecanico Logitech MX, Mouse MX Master 3, Fone Sony WH-1000XM5 | 1 kit | Produtividade para longas horas de trabalho |
| **Fonte** | Fonte 750W 80 Plus Gold Corsair RM750x | 1 | Potencia para CPU + GPU, certificacao Gold |
| **Gabinete** | Gabinete Full Tower NZXT H7 Flow RGB | 1 | Espaco para 3 M.2, 6 HDs, excelente ventilacao |

**Compatibilidade verificada:**
- Soquete LGA 1700: i7-13700K + Z790 (perfeito)
- DDR5-5600 suportado pelo Z790: Sim
- Fonte 750W: RTX 4060 (~300W pico) + i7 (~250W) -> Seguro
- 3 slots M.2 na placa-mae: 2 usados, 1 livre
- Expansao: Possibilidade de ate 64GB->128GB no futuro

---

## 4. Servidores (Datacenter Matriz SP)

Localizado no **Subsolo da Matriz SP** - Sala de Datacenter (~60 m², ar-condicionado de precisão dedicado, no-break de alta capacidade + gerador a diesel).
Além da matriz, cada filial possui um mini-datacenter próprio com servidores locais.

---

### 4.1 Servidor 01 - Controlador de Dominio / AD / DNS

| Item | Especificacao |
|------|--------------|
| **Chassis** | Dell PowerEdge T350 (Tower) |
| **CPU** | Intel Xeon E-2388G (8 nucleos, 3.2GHz) |
| **RAM** | 32GB DDR4-3200 ECC (2x16GB) |
| **Discos** | 2 x SSD 960GB Intel S4520 (RAID 1 - espelho) |
| **RAID** | Controladora PERC H355 |
| **Rede** | 4 x Gigabit Ethernet |
| **Fonte** | Fonte redundante 2x 495W 80 Plus Gold |
| **No-break** | APC Smart-UPS SRT 5000VA (compartilhado entre todos) |
| **Qtd** | 1 unidade |

**Servicos:** Active Directory (AD DS), DNS, DHCP, GPO, WSUS

---

### 4.2 Servidor 02 - Arquivos e Impressao (File Server)

| Item | Especificacao |
|------|--------------|
| **Chassis** | Dell PowerEdge R550 (Rack 2U) |
| **CPU** | Intel Xeon Silver 4310 (12 nucleos, 2.1GHz) |
| **RAM** | 64GB DDR4-2933 ECC (4x16GB) |
| **Discos** | 4 x HD 8TB WD Gold (RAID 5) - ~21TB uteis |
| **RAID** | Controladora PERC H755 NVRAM |
| **Rede** | 4 x Gigabit Ethernet (LACP - agregacao) |
| **Fonte** | Fonte redundante 2x 800W 80 Plus Titanium |
| **Qtd** | 1 unidade |

**Servicos:** File Server (compartilhamentos), Print Server, Quotas de disco

---

### 4.3 Servidor 03 - Banco de Dados (SQL Server)

| Item | Especificacao |
|------|--------------|
| **Chassis** | Dell PowerEdge R650xs (Rack 1U) |
| **CPU** | 2 x Intel Xeon Gold 5318Y (2x24 nucleos total) |
| **RAM** | 256GB DDR4-2933 ECC (8x32GB) |
| **Discos** | 2 x SSD 1.92TB (RAID 1 - Logs) + 6 x SSD 3.84TB (RAID 5 - Dados) |
| **RAID** | Controladora PERC H755 NVRAM |
| **Rede** | 2 x 10GbE SFP+ + 2 x Gigabit |
| **Fonte** | Fonte redundante 2x 1100W Titanium |
| **Qtd** | 1 unidade |

**Servicos:** SQL Server 2022 - bancos WMS, TMS e ERP

---

### 4.4 Servidor 04 - Virtualizacao / Aplicativos (Hyper-V)

| Item | Especificacao |
|------|--------------|
| **Chassis** | Dell PowerEdge R750 (Rack 2U) |
| **CPU** | 2 x Intel Xeon Gold 6338 (2x32 nucleos total) |
| **RAM** | 512GB DDR4-2933 ECC (16x32GB) |
| **Discos** | 8 x SSD 1.92TB (RAID 6 - ~11TB uteis para VMs) |
| **RAID** | Controladora PERC H755 NVRAM |
| **Rede** | 4 x 10GbE SFP+ |
| **Fonte** | Fonte redundante 2x 1400W Titanium |
| **Qtd** | 2 unidades (cluster) |

**VMs:** WMS Server, TMS Server, ERP Web Frontend, IIS Web Server, Monitoramento Zabbix, BI Gateway

---

### 4.5 Servidor 05 - Backup

| Item | Especificacao |
|------|--------------|
| **Chassis** | Dell PowerEdge T550 (Tower) |
| **CPU** | Intel Xeon Silver 4314 (16 nucleos) |
| **RAM** | 32GB DDR4 ECC |
| **Discos** | 12 x HD 16TB WD Ultrastar (RAID 6 - ~140TB uteis) |
| **Rede** | 2 x 10GbE SFP+ |
| **Fonte** | 2x 750W redundantes |
| **Qtd** | 1 unidade |
| **Midia adicional** | Tape Library LTO-9 (fitas offsite semanais) |

**Software:** Veeam Backup & Replication v12

---

## 5. Orçamento Total - Hardware

Planilha detalhada em: [orcamento_hardware.csv](orcamento_hardware.csv)

**Resumo do orçamento:**
| Categoria | Qtd Equipamentos | Subtotal BRL |
|----------|-----------------|-------------|
| Computadores Administrativos | 108 | R$ 432.000,00 |
| Computadores Operacionais (Engenharia/NOC) | 162 | R$ 1.134.000,00 |
| Computadores Especializados (Data Center/BI) | 30 | R$ 540.000,00 |
| Servidores (06 unidades + racks + nobreak) | 8 | R$ 1.620.000,00 |
| Impressoras / Etiquetadoras / Coletores | 45 | R$ 350.000,00 |
| **TOTAL GERAL** | **353** | **R$ 4.076.000,00** |

**Data da consulta:** Agosto/2026  
**Fornecedores consultados:** Dell Oficial, Lenovo Brasil, Pichau, Terabyteshop, Kabum, APC

---

## 6. Justificativa das Escolhas

### Equilíbrio custo x benefício:
- **Administrativo:** i3 + 16GB + SSD NVMe = máquina barata, performática e com upgrade fácil para toda a equipe de escritório (RH, Financeiro, Comercial, Marketing).
- **Operacional (Engenharia / NOC):** i5 + 32GB + SSD+HD = robusto, preparado para funcionamento 24h no NOC e engenharia, com redundância de disco local.
- **Especializado (Data Center / BI / Engenharia):** i7 + 64GB DDR5 + RTX 4060 = capacidade para rodar VMs, simuladores de rede (Packet Tracer/GNS3), Power BI pesado, AutoCAD e laboratório de IoT.

### Servidores:
- **Cluster de virtualização (R750 x2):** Alta disponibilidade para ERP, CRM, serviços de nuvem privada e ambientes de homologação da NexCore (não pode parar).
- **SQL Server dedicado (R650xs):** Performance do banco de dados = performance do negócio (ERP, CRM, projetos e atendimento).
- **RAID 1 para SO/Logs, RAID 5 para dados:** Equilíbrio entre performance e confiabilidade.
- **Fontes redundantes em TODOS os servidores:** Nenhum servidor fica indisponível por falha de fonte.
- **No-break + Gerador em todos os locais:** Autonomia para desligamento seguro e continuidade de operação (NOC 24x7).

### Sem excesso nem falta:
Nenhuma máquina tem componentes "overkill" desnecessários, e todas estão dimensionadas para pelo menos 5 anos de vida útil. Todos os componentes são compatíveis entre si, e a fonte de cada máquina tem pelo menos 30% de margem de segurança sobre o consumo de pico.

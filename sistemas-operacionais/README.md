# Sistemas Operacionais - NexCore Tecnologia

## Objetivo
Definir os sistemas operacionais, serviços e políticas compatíveis com o hardware escolhido na disciplina de Arquitetura.

## Entregáveis:
- [x] Escolha do SO para servidores (Windows Server / Linux) — [servidores.md](servidores.md)
- [x] Escolha do SO para estações de trabalho — [estacoes.md](estacoes.md)
- [x] Políticas de segurança, usuários, backup e DRP — [politicas-seguranca.md](politicas-seguranca.md)
- [x] Serviços configurados (AD, DNS, DHCP, Arquivos, Web, Banco, Hyper-V) — [servidores.md](servidores.md)
- [x] Licenciamento e custos de software (3 anos) — [licenciamento.md](licenciamento.md)
- [x] Estrutura de domínio AD, GPOs e grupos — [estacoes.md](estacoes.md)

## Estrutura de arquivos:
```
sistemas-operacionais/
├── README.md              ← Este arquivo (resumo)
├── servidores.md          ← SO, hostnames, IPs, serviços e portas por servidor
├── estacoes.md            ← SO por perfil, GPOs, estrutura AD (OU e grupos)
├── politicas-seguranca.md ← Senhas, criptografia, SOPs, backup (Veeam), DRP
└── licenciamento.md       ← Custos M365, CALs, Windows Server, SQL, AutoCAD (3 anos)
```

---

## Resumo Executivo - D2

### Sistemas Operacionais Principais:
| Camada | SO Principal | Justificativa |
|--------|-------------|---------------|
| Servidores (maioria) | **Windows Server 2022** (Datacenter nos HVs, Standard nos demais) | AD, GPO, Hyper-V Cluster, SQL Server, ERP/CRM |
| Backup + Monitoramento | **Ubuntu Server 24.04 LTS** | Menor custo, melhor desempenho, software livre (Zabbix, Grafana, Veeam repo) |
| Estações Admin | **Windows 11 Pro + M365 Business Premium** | Gestão completa, MFA, Intune, Defender for Business |
| Estações Operacionais (NOC/Eng) | **Windows 11 Enterprise LTSC 2024** | Sem feature updates por 10 anos, sem bloatware, estável 24x7 |
| Estações Especializadas | **Windows 11 Enterprise + M365 E3** | Power BI Pro, AIP P2, Identity Protection |

### Custos (3 anos):
- Software e licenças: **R$ 6.676.800** (inclui CALs)
- Hardware já orçado em D1: **R$ 4.076.000**
- Implementação + manutenção 3 anos: **R$ 1.834.200**
- **TOTAL GERAL 3 anos (CAPEX + OPEX): R$ 12.587.000**

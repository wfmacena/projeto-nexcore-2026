# Evidências - Arquitetura e Organização de Computadores

## 📁 O que deve estar nesta pasta

Esta pasta contém as **evidências visuais e documentais** da disciplina de Arquitetura e Organização de Computadores (D1).

---

## 📸 Prints e Evidências Sugeridas

### 1. Tabelas de Configuração
**Nome do arquivo:** `01-perfis-computadores-configuracao.png`

**O que incluir:**
- Tabela com os 3 perfis (Administrativo, Operacional, Especializado)
- Configuração detalhada de cada componente:
  - CPU, Placa-mãe, RAM, Armazenamento, GPU, Fonte, Gabinete
  - Quantidade e valores
- Print pode ser do próprio README.md ou de planilha Excel/LibreOffice

---

### 2. Planilha de Orçamento
**Nome do arquivo:** `02-orcamento-hardware-completo.png` ou `.pdf`

**O que incluir:**
- Print ou exportação do arquivo `orcamento_hardware.csv`
- Visão completa mostrando:
  - Todos os equipamentos (desktops, servidores, impressoras)
  - Quantidades por local
  - Valores unitários e subtotais
  - Fornecedores
  - **Total geral: R$ 4.076.000**

---

### 3. Servidores Dimensionados
**Nome do arquivo:** `03-servidores-datacenter.png`

**O que incluir:**
- Lista dos 8 servidores:
  1. Servidor AD/DNS (Dell PowerEdge T350)
  2. Servidor Arquivos (Dell PowerEdge R550)
  3. Servidor SQL (Dell PowerEdge R650xs)
  4. Servidores Hyper-V cluster (2x Dell PowerEdge R750)
  5. Servidor Backup (Dell PowerEdge T550)
  6. Servidores DR Filiais (2x Dell PowerEdge T360)
- Especificações: CPU, RAM, Discos, RAID

---

### 4. Compatibilidade Verificada
**Nome do arquivo:** `04-compatibilidade-perfil-administrativo.png`

**Exemplo para Perfil Administrativo:**
- Soquete: LGA 1700 (i3-13100 compatível com H610)
- RAM: DDR4-3200 suportado pelo chipset H610
- Fonte: 400W suficiente para consumo ~150W
- Tudo cabe no gabinete Mid Tower

*Pode criar um print similar para cada perfil*

---

### 5. Fontes Consultadas
**Nome do arquivo:** `05-fontes-precos-fornecedores.png`

**O que incluir:**
- Screenshots de sites consultados:
  - Dell.com.br (servidores)
  - Kabum.com.br (desktops)
  - Pichau.com.br (componentes)
  - Terabyteshop.com.br (workstations)
- Datas de consulta (Agosto/2026)
- Preços praticados

---

## 📊 Documentação Adicional (Opcional)

### Comparação Técnica
**Nome:** `comparacao-cpus.png` ou `comparacao-servidores.png`

Tabela comparativa mostrando:
- Opção A vs Opção B
- Desempenho, consumo, garantia, custo
- Justificativa da escolha final

---

### Dimensionamento de RAID
**Nome:** `dimensionamento-raid-servidores.png`

Cálculos mostrando:
- RAID 1: 2 discos → 50% capacidade útil
- RAID 5: 4 discos → 75% capacidade útil
- RAID 6: 8 discos → ~75% capacidade útil
- Exemplos aplicados aos servidores do projeto

---

## 📋 Checklist de Verificação

Antes de considerar a disciplina completa, verifique:

- [ ] Arquivo `orcamento_hardware.csv` existe em `arquitetura/`
- [ ] README.md da arquitetura está completo
- [ ] Pelo menos 3 prints/evidências visuais salvos nesta pasta
- [ ] Todos os 3 perfis estão documentados
- [ ] Todos os servidores estão especificados
- [ ] Orçamento totaliza R$ 4.076.000
- [ ] Compatibilidade está verificada e documentada
- [ ] Justificativas técnicas estão claras

---

## 🎯 Para o Professor

Estas evidências provam que:
1. ✅ Os perfis de computadores foram criados (3 tipos)
2. ✅ Configurações estão detalhadas e compatíveis
3. ✅ Servidores foram dimensionados adequadamente
4. ✅ Orçamento foi pesquisado e documentado
5. ✅ Escolhas técnicas foram justificadas
6. ✅ Projeto atende aos requisitos da disciplina de Arquitetura

---

## 📂 Estrutura Final Esperada

```
evidencias/arquitetura/
├── LEIA-ME.md                                    ← Este arquivo
├── 01-perfis-computadores-configuracao.png       ← Recomendado
├── 02-orcamento-hardware-completo.png            ← Recomendado
├── 03-servidores-datacenter.png                  ← Recomendado
├── 04-compatibilidade-perfil-administrativo.png  ← Opcional
├── 05-fontes-precos-fornecedores.png             ← Opcional
└── comparacao-tecnica.png                        ← Opcional
```

---

## 💡 Dicas

- **Screenshots de Excel/LibreOffice:** Certifique-se que as colunas estão legíveis
- **Documentos longos:** Pode dividir em múltiplas páginas (parte 1, parte 2, etc.)
- **Formato:** PNG ou JPG preferencial, PDF aceito para documentos multi-página
- **Legibilidade:** Zoom adequado para leitura de números e especificações

---

## ⚠️ Importante

- **NÃO incluir dados pessoais** (nomes completos, RAs, CPFs) nas evidências
- Focar em **especificações técnicas e valores**
- Manter **organização e clareza** visual

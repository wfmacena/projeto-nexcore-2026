# Evidências - Redes de Computadores

## 📁 O que deve estar nesta pasta

Esta pasta contém as **evidências visuais** da disciplina de Redes de Computadores (D3).

---

## 📸 Prints Obrigatórios do Cisco Packet Tracer

### Print 07: Topologia Completa
**Nome do arquivo:** `07-packet-tracer-topologia-matriz-sp.png`

**O que deve aparecer:**
- ✅ Topologia completa da Matriz SP na área de trabalho
- ✅ Dispositivos visíveis:
  - Router 1941 (R-MATRIZ-SP)
  - Switch 2960-24TT (SW-MATRIZ-SP)
  - 2 PCs (PC-ADM01, PC-ADM02) na VLAN 30
  - 2-3 Servidores (SRV-FILE, SRV-WEB) na VLAN 20
- ✅ Todos os cabos com pontas **VERDES** (conexão ativa)
- ✅ Nomes dos dispositivos visíveis abaixo de cada ícone
- ✅ Layout organizado e legível

**Como tirar:**
1. Abrir arquivo `.pkt` no Packet Tracer
2. Visualizar aba **"Logical"** (topologia lógica)
3. Dar zoom para ver todos os dispositivos
4. Capturar tela: **Windows + Shift + S**

---

### Print 08: Ping Inter-VLAN Funcionando
**Nome do arquivo:** `08-packet-tracer-ping-inter-vlan.png`

**O que deve aparecer:**
- ✅ Janela do **Command Prompt** do PC-ADM01 aberta
- ✅ Comando executado: `ping 10.10.10.10` (SRV-FILE na VLAN 20)
- ✅ Resultado: **4/4 pacotes recebidos** (100% sucesso)
- ✅ Mensagens "Reply from 10.10.10.10: bytes=32 time<1ms TTL=127"
- ✅ Topologia visível ao fundo (para contexto)

**Como tirar:**
1. Abrir Packet Tracer com projeto carregado
2. Clicar em **PC-ADM01** → aba **Desktop** → **Command Prompt**
3. Digitar: `ping 10.10.10.10`
4. Aguardar resultado (4 replies)
5. Capturar tela com Command Prompt em primeiro plano

**Por que este print é crítico:**
- Prova que o **roteamento inter-VLAN está funcionando**
- Dispositivos de VLANs diferentes (30 e 20) conseguem se comunicar
- Router está fazendo o roteamento corretamente
- Atende requisito **OBRIGATÓRIO** do professor

---

## 📊 Prints Opcionais (Recomendados)

### Diagramas de Topologia Visual
**Nomes sugeridos:**
- `topologia-matriz-sp-visual.png` - Diagrama Draw.io/Visio da Matriz SP
- `topologia-filial-campinas-visual.png` - Diagrama da Filial Campinas
- `topologia-filial-ribeirao-visual.png` - Diagrama da Filial Ribeirão

**O que incluir:**
- Switches por andar
- Conexões de rede
- VLANs identificadas
- Equipamentos (PCs, servidores, APs)
- IPs dos principais dispositivos

---

### Configurações do Switch
**Nome do arquivo:** `config-switch-vlan-show.png`

**Como obter:**
1. No Packet Tracer, clicar no Switch → aba **CLI**
2. Executar comandos:
   ```
   enable
   show vlan brief
   show interfaces trunk
   ```
3. Capturar output mostrando:
   - VLANs 20 e 30 criadas
   - Portas Fa0/2-3 na VLAN 30
   - Portas Fa0/4-5 na VLAN 20
   - Porta Fa0/1 como TRUNK

---

### Configurações do Router
**Nome do arquivo:** `config-router-subinterfaces.png`

**Como obter:**
1. No Packet Tracer, clicar no Router → aba **CLI**
2. Executar comandos:
   ```
   enable
   show ip interface brief
   show ip route
   ```
3. Capturar output mostrando:
   - Interface Gi0/0 up/up
   - Subinterfaces Gi0/0.20 (10.10.10.1) e Gi0/0.30 (10.10.20.1)
   - Rotas Connected (C) para as duas sub-redes

---

## 📋 Checklist de Verificação

Antes de considerar a disciplina completa, verifique:

- [ ] Arquivo `nexcore-matriz-sp-packet-tracer.pkt` existe em `redes/`
- [ ] Print 07 (topologia completa) salvo nesta pasta
- [ ] Print 08 (ping inter-VLAN) salvo nesta pasta
- [ ] Ping mostra 100% de sucesso (4/4 pacotes)
- [ ] Nomes dos dispositivos estão corretos (R-MATRIZ-SP, SW-MATRIZ-SP, etc.)
- [ ] VLANs 20 e 30 estão funcionais
- [ ] Todos os prints estão em formato PNG ou JPG
- [ ] Prints são legíveis (texto e números visíveis)

---

## 🎯 Para o Professor

Estes prints provam que:
1. ✅ A topologia foi implementada no Cisco Packet Tracer
2. ✅ VLANs foram configuradas corretamente
3. ✅ Roteamento inter-VLAN está funcional
4. ✅ Comunicação entre redes diferentes (VLAN 30 ↔ VLAN 20) funciona
5. ✅ Projeto atende aos requisitos da disciplina de Redes

---

## 📂 Estrutura Final Esperada

```
evidencias/redes/
├── LEIA-ME.md                                      ← Este arquivo
├── 07-packet-tracer-topologia-matriz-sp.png        ← OBRIGATÓRIO
├── 08-packet-tracer-ping-inter-vlan.png            ← OBRIGATÓRIO
├── config-switch-vlan-show.png                     ← Opcional
├── config-router-subinterfaces.png                 ← Opcional
├── topologia-matriz-sp-visual.png                  ← Opcional
├── topologia-filial-campinas-visual.png            ← Opcional
└── topologia-filial-ribeirao-visual.png            ← Opcional
```

---

## ⚠️ Importante

- **NÃO incluir dados pessoais** (nomes, RAs, e-mails) nos prints
- **Formato:** PNG ou JPG (máx 5MB por imagem)
- **Resolução:** Mínimo 1280x720 (HD) para legibilidade
- **Nomes dos arquivos:** Seguir padrão indicado acima

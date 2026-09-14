# Evidencias - D4 IoT (Tinkercad)

> Aviso: Os prints desta pasta sao as evidencias do Tinkercad (simulacao). Para duplicatas organizadas, os mesmos arquivos tambem podem ser salvos em `iot/prints-simulacao/`.

---

## Atividade (especificada pelo professor):
> *"uma unica atividade no Tinkercad: um monitor de temperatura para a sala de servidores com Arduino, protoboard, TMP36, LEDs e resistores. O codigo devera ser desenvolvido pela propria equipe."*

---

## Lista de prints obrigatorios (4 arquivos):

| Nome do arquivo | O que mostrar no print | Como reproduzir no Tinkercad | Status |
|-----------------|----------------------|------------------------------|--------|
| `01-montagem-completa.png` | **Todo o circuito montado** (Arduino Uno + Protoboard + TMP36 + 3 LEDs + 3 resistores 220R), componentes organizados e fios arrumados, **SEM iniciar a simulacao** | Apenas montar tudo, antes de clicar em Start Simulation | ⬜ Pendente |
| `02-teste-normal-led-verde.png` | Circuito LIGADO com LED **VERDE aceso**, temperatura no TMP36 < 28C (ex: 24C). Tudo visivel na tela. | Clicar no TMP36 → arrastar slider para 24 C → Start | ⬜ Pendente |
| `03-teste-alerta-led-amarelo.png` | Circuito LIGADO com LED **AMARELO aceso**, temperatura no TMP36 entre 28C e 35C (ex: 30C). | Slider TMP36 → 30 C | ⬜ Pendente |
| `04-teste-critico-led-vermelho.png` | Circuito LIGADO com LED **VERMELHO** (pode aparecer ligado ou no meio da piscada, print em qualquer instante), temperatura >= 35 C (ex: 37 C). | Slider TMP36 → 37 C | ⬜ Pendente |
| `05-serial-monitor-log.png` | Janela do **Serial Monitor** (icone de lupa na barra inferior do Tinkercad) aberta durante a simulacao, mostrando linhas do tipo: `[NexCore] Temp = 24.0 C  |  Status: NORMAL (LED VERDE)` | Start Simulation → clicar em "Serial Monitor" (lupa) → aguardar aparecerem 2 ou 3 linhas | ⬜ Pendente |

---

### Opcionais (pontos extras):
| Nome | Descricao |
|------|-----------|
| `06-link-projeto-publico.png` | Print da tela do Tinkercad mostrando que o projeto foi compartilhado como "Publico" (botao Share → Change → Public) |
| `07-codigo-no-tinkercad.png` | Print da aba "Code" do Tinkercad mostrando o codigo .ino colado la |

---

### O que deve aparecer em TODOS os prints:
- O nome do projeto no topo do Tinkercad: **"NexCore - Monitor Temperatura Sala Servidores"**
- Os fios coloridos e organizados (evitar "fio de espaguete" emaranhado)
- Componentes claramente visiveis (TMP36 com os 3 pinos conectados, LEDs com resistores em serie)
- Resolucao minima: 1280x720 (melhor 1920x1080)

---

### Dica de montagem no Tinkercad:
1. Arduino Uno R3 no centro superior
2. Protoboard 830 pontos abaixo do Arduino
3. TMP36 na parte ESQUERDA da protoboard (3 pinos: VCC / OUT / GND)
4. LEDs na parte DIREITA da protoboard, enfileirados: Verde / Amarelo / Vermelho
5. Cada LED tem um resistor 220R no catodo (-) indo para GND
6. Jumpers coloridos:
   - Vermelho: 5V → TMP36 pino 1
   - Preto: GND → TMP36 pino 3
   - Amarelo: A0 → TMP36 pino 2 (OUT)
   - Verde: D8 → Anodo LED Verde
   - Amarelo: D9 → Anodo LED Amarelo
   - Vermelho: D10 → Anodo LED Vermelho

# Prints de Simulacao - Tinkercad (D4 IoT)

## NexCore Tecnologia - Monitor de Temperatura Sala de Servidores

Esta pasta deve conter **screenshots** da simulacao executada no Tinkercad para comprovar o funcionamento do circuito com TMP36.

---

## Instrucoes para gerar os prints:

1. Acesse o [Tinkercad](https://www.tinkercad.com) e crie o circuito conforme o README da pasta `iot/`
2. Cole o codigo-fonte do arquivo `codigo-automacao.ino`
3. Clique em **Start Simulation**
4. Clique no componente **TMP36** e use o controle deslizante para ajustar a temperatura conforme cada cenario abaixo
5. Tire print da tela inteira (circuito + LEDs acesos) para cada caso

---

## Lista de prints obrigatorios (5 arquivos):

| Nome do arquivo | Como reproduzir | O que deve aparecer na imagem |
|-----------------|-----------------|-------------------------------|
| `01-montagem-completa.png` | Antes de clicar em Start, mostre toda a montagem | Visao geral do circuito completo no Tinkercad: Arduino + Protoboard + TMP36 + 3 LEDs + 3 resistores 220R, todos os componentes e ligacoes visiveis |
| `02-teste-normal.png` | Slider do TMP36 em **24 C** (abaixo de 28 C) | LED **VERDE** LIGADO (fixo). LEDs amarelo e vermelho APAGADOS |
| `03-teste-alerta.png` | Slider do TMP36 em **30 C** (entre 28 e 35 C) | LED **AMARELO** LIGADO. Verde e vermelho APAGADOS |
| `04-teste-critico.png` | Slider do TMP36 em **37 C** (acima de 35 C) | LED **VERMELHO** (pode aparecer aceso ou no meio da piscada) |
| `05-serial-monitor.png` | Abra o **Serial Monitor** (icone da lupa) durante a simulacao | Log mostrando as leituras de temperatura e status: `[NexCore] Temp = XX.X C  |  Status: NORMAL/ALERTA/CRITICA` |

---

## Dicas:

- No Tinkercad, o TMP36 tem **1 slider interativo apenas para TEMPERATURA** (nao tem umidade, pois TMP36 mede so temperatura)
- Use a tecla **Win + Shift + S** no Windows para capturar a tela
- Ou use a ferramenta **Screenshot** do proprio Tinkercad quando disponivel
- Salve cada imagem com o nome exato da tabela acima (facilita correcao pelo professor)

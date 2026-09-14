# Internet das Coisas (IoT) - NexCore Tecnologia

## Objetivo
Implementar uma automacao funcional no Tinkercad relacionada ao negocio da NexCore: **monitor de temperatura para a sala de servidores (CPD/Datacenter)**, conforme especificado pelo professor.

**Componentes obrigatorios (professor):** Arduino, protoboard, TMP36, LEDs e resistores.

---

## 1. Problema a Resolver

A **Sala de Servidores (CPD)** da Matriz SP (e tambem das filiais) precisa de monitoramento 24h de **temperatura**. O superaquecimento e uma das principais causas de falha em servidores e reducao de vida util de hardware. A faixa ideal para datacenters (conforme norma ASHRAE TC 9.9) fica entre **18C e 27C**.

---

## 2. Solucao Proposta

Sistema embarcado com **Arduino Uno R3** + **Sensor Analogico TMP36** que mede temperatura a cada 2 segundos e aciona **LEDs de status** conforme limiares pre-definidos:

| Situacao | Faixa Temperatura | LED que acende |
|----------|-------------------|----------------|
| **NORMAL** | < 28 C | Verde (ligado fixo) |
| **ALERTA** | >= 28 C e < 35 C | Amarelo (ligado fixo) |
| **CRITICA** | >= 35 C | Vermelho (piscando) |

---

## 3. Entregaveis:
- [x] Codigo-fonte .ino (C++ para Arduino) - [codigo-automacao.ino](codigo-automacao.ino)
- [x] Lista de componentes e diagrama de conexao (abaixo)
- [x] Explicacao detalhada do funcionamento e limiares
- [x] **Link do projeto publico no Tinkercad com sharecode** - [Glorious Luulia](https://www.tinkercad.com/things/3D7w2tFX9Pa-glorious-luulia/editel?sharecode=RLALSzS840Xe5kYSXabKECpm6mc8rV9YudF2UlgOunk)
- [x] Diagrama de montagem (screenshot Tinkercad) - `montagem-tinkercad.png`
- [x] Prints de simulacao (5 screenshots) - Pasta [prints-simulacao/](prints-simulacao/)

## Estrutura de arquivos:
```
iot/
├── README.md                   ← Este arquivo
├── codigo-automacao.ino        ← Codigo-fonte Arduino (TMP36 + LEDs)
├── montagem-tinkercad.png      ← (a ser adicionado) screenshot da montagem
└── prints-simulacao/
    ├── teste1-normal.png       ← Temperatura normal (LED verde)
    ├── teste2-alerta.png       ← Alerta (LED amarelo)
    └── teste3-critico.png      ← Critico (LED vermelho piscando)
```

---

## 4. Lista de Componentes (Bill of Materials - BOM)

Conforme especificado pelo professor: **Arduino, protoboard, TMP36, LEDs e resistores**.

| Item | Componente | Quantidade | Valor estimado (BRL) | Funcao no Projeto |
|------|-----------|------------|----------------------|-------------------|
| 1 | Arduino Uno R3 (compativel) | 1 | R$ 45,00 | Microcontrolador principal |
| 2 | Sensor TMP36 (Temperatura analogica) | 1 | R$ 8,00 | Medir temperatura em graus Celsius |
| 3 | LED Verde 5mm | 1 | R$ 0,50 | Indicador NORMAL (< 28C) |
| 4 | LED Amarelo 5mm | 1 | R$ 0,50 | Indicador ALERTA (28C ~ 35C) |
| 5 | LED Vermelho 5mm | 1 | R$ 0,50 | Indicador CRITICO (>= 35C) |
| 6 | Resistor 220 Ohms | 3 | R$ 0,30 cada | Limitador de corrente para CADA LED (3 unidades) |
| 7 | Protoboard 830 pontos | 1 | R$ 12,00 | Montagem do circuito |
| 8 | Jumpers macho-macho | 1 kit | R$ 5,00 | Conexoes do circuito |
| | **TOTAL GERAL** | | **~R$ 72,40** | Por unidade de monitoramento |

> **Observacao:** Diferente do sensor DHT22 (digital, mede temp + umidade), o **TMP36** e analogico e mede **apenas temperatura**. O professor especificou TMP36 explicitamente.

---

## 5. Diagrama de Montagem (Tinkercad)

```
                          ARDUINO UNO R3
                       ┌─────────────────────┐
                       │                     │
   TMP36 (3 pinos)     │                     │
      ┌──────┐         │                     │
  VCC─┤1  VCC├─────────┤ 5V                  │
  OUT─┤2 OUT ├─────────┤ A0  (Analogico 0)   │
  GND─┤3 GND ├─────────┤ GND                 │
      └──────┘         │                     │
                       │                     │
   LED VERDE           │                     │
   Anodo (+) ──────────┤ D8  ─► Resistor 220R ─► GND
   Catodo (-) ─────────┤                     │
                       │                     │
   LED AMARELO         │                     │
   Anodo (+) ──────────┤ D9  ─► Resistor 220R ─► GND
   Catodo (-) ─────────┤                     │
                       │                     │
   LED VERMELHO        │                     │
   Anodo (+) ──────────┤ D10 ─► Resistor 220R ─► GND
   Catodo (-) ─────────┤                     │
                       │                     │
                       └─────────────────────┘
```

---

## 6. Mapa de Pinos

| Pino Arduino | Componente | Tipo | Observacao |
|-------------|-----------|------|------------|
| A0 | TMP36 (pino do meio = OUT) | Entrada Analogica | Leitura da tensao 0V~5V |
| 5V | TMP36 VCC (pino 1/esquerdo) | Alimentacao | +5V |
| GND | TMP36 GND (pino 3/direito) | Terra | 0V |
| D8 | LED Verde (Anodo) | Saida Digital | Resistor 220R entre catodo e GND |
| D9 | LED Amarelo (Anodo) | Saida Digital | Resistor 220R entre catodo e GND |
| D10 | LED Vermelho (Anodo) | Saida Digital | Resistor 220R entre catodo e GND |

> **Atencao no TMP36**: A pinagem e (olhando a face plana para voce, pinos para baixo):
> - **Esquerdo:** VCC (3V a 5V)
> - **Meio:** VOUT (saida analogica)
> - **Direito:** GND

---

## 7. Funcionamento - Logica e Limiares

### Formula do TMP36:
O TMP36 gera uma tensao proporcional a temperatura:
- 0.5V = 0C
- Cada 10mV = 1C

```
valorADC = analogRead(A0)         → 0 a 1023
tensao   = valorADC * (5.0 / 1024)
tempC    = (tensao - 0.5) * 100
```

### Limiares:
| Situacao | Faixa Temperatura | LED Verde | LED Amarelo | LED Vermelho |
|----------|-------------------|-----------|--------------|--------------|
| **NORMAL** | < 28 C | ✅ LIGADO | ❌ | ❌ |
| **ALERTA** | >= 28 C E < 35 C | ❌ | ✅ LIGADO | ❌ |
| **CRITICA** | >= 35 C | ❌ | ❌ | ✅ PISCA (500ms ON/OFF) |

### Tempo de leitura:
- Leitura do sensor e atualizacao dos LEDs a cada **2 segundos**

---

## 8. Bibliotecas Utilizadas

| Biblioteca | Uso |
|-----------|-----|
| **Nenhuma externa** | TMP36 e analogico, usa apenas `analogRead()` nativo do Arduino |

---

## 9. Casos de Uso Reais na NexCore

1. **Sala de Servidores Matriz SP (Subsolo):** Instalar 1 sensor TMP36 em cada rack (6 sensores total).
2. **Filiais Campinas e Ribeirao Preto:** 2 a 3 sensores por mini-datacenter.
3. **Integracao com NOC:** Os pinos digitais D8/D9/D10 podem ser lidos por um modulo Ethernet/ESP e enviados via MQTT para o painel Zabbix do NOC.
4. **Economia:** Monitoramento preventivo evita troca prematura de hardware por superaquecimento.

---

## 10. Evidencias de Simulacao (Tinkercad)

> **Instrucoes para o Tinkercad**:
> 1. Abrir [www.tinkercad.com](https://www.tinkercad.com)
> 2. Criar novo circuito → "Circuit Design"
> 3. Arrastar componentes conforme lista BOM acima
> 4. Conectar pinos conforme diagrama
> 5. Copiar codigo de [codigo-automacao.ino](codigo-automacao.ino)
> 6. Clicar em "Start Simulation"
> 7. Clicar no TMP36 e usar o **slider de temperatura** para testar cada caso

### Casos de Teste (para gerar os prints):
| Teste n | Descri | Resultado esperado | Onde salvar |
|---------|--------|-------------------|-------------|
| **Teste 1** | Temp = 24 C (slider do TMP36) | LED **verde** LIGADO | `prints-simulacao/teste1-normal.png` |
| **Teste 2** | Temp = 30 C (slider do TMP36) | LED **amarelo** LIGADO | `prints-simulacao/teste2-alerta.png` |
| **Teste 3** | Temp = 37 C (slider do TMP36) | LED **vermelho** PISCANDO | `prints-simulacao/teste3-critico.png` |
| **Teste 4** | Serial Monitor aberto | Mostra `[NexCore] Temp = XX.X C  |  Status: ...` | `prints-simulacao/teste4-serial.png` |

---

## 11. Link do Projeto Público

✅ **PROJETO TINKERCAD DISPONÍVEL (ACESSO PÚBLICO):**

🔗 **[Glorious Luulia - Monitor de Temperatura NexCore](https://www.tinkercad.com/things/3D7w2tFX9Pa-glorious-luulia/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=RLALSzS840Xe5kYSXabKECpm6mc8rV9YudF2UlgOunk)**

**Link com código de compartilhamento público - qualquer pessoa pode acessar!**

**Acesso direto ao projeto completo com:**
- ✅ Circuito montado (Arduino + TMP36 + 3 LEDs)
- ✅ Código Arduino funcional
- ✅ Simulação interativa (ajuste temperatura do sensor)
- ✅ Demonstração das 3 faixas de temperatura

**Como usar:**
1. Clique no link acima
2. Clique em "Iniciar simulação" ▶️
3. Clique no sensor TMP36 e ajuste a temperatura
4. Observe os LEDs mudarem conforme a faixa de temperatura

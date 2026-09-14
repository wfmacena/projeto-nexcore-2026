/*
 * ============================================================
 *  NexCore Tecnologia - Monitor de Temperatura Sala de Servidores
 *  Disciplina 4: Internet das Coisas (IoT) - Tinkercad
 * ============================================================
 *
 *  PROFESSOR ESPECIFICOU:
 *  Monitor de temperatura para a sala de servidores com
 *  Arduino, protoboard, TMP36, LEDs e resistores.
 *
 *  SOLUCAO:
 *  Arduino Uno com sensor analogico TMP36 mede temperatura (C)
 *  a cada 2 segundos. LEDs indicam o status conforme limiares:
 *
 *    - LED VERDE  : Temperatura NORMAL  (Temp < 28 C)
 *    - LED AMARELO: Temperatura ALERTA  (Temp >= 28 C e < 35 C)
 *    - LED VERMELHO: Temperatura CRITICA (Temp >= 35 C) - pisca
 *
 *  FORMULA DO TMP36:
 *    Vout = (analogRead * 5.0) / 1024.0
 *    Temp C = (Vout - 0.5) * 100
 *
 * ============================================================
 *  HARDWARE (Tinkercad - Arduino Uno R3):
 * ============================================================
 *  PINO  | COMPONENTE           | OBSERVACAO
 *  ------|----------------------|-------------------------------
 *  A0    | TMP36 (VOUT)         | Saida analogica do sensor
 *  5V    | TMP36 (VCC)          | Alimentacao 5V
 *  GND   | TMP36 (GND)          | Terra
 *  D8    | LED VERDE            | Anodo (+) -> Resistor 220R -> GND
 *  D9    | LED AMARELO          | Anodo (+) -> Resistor 220R -> GND
 *  D10   | LED VERMELHO         | Anodo (+) -> Resistor 220R -> GND
 * ============================================================
 */

/* ============= DEFINICOES DE PINOS ============= */

#define TMP36_PIN    A0
#define LED_VERDE    8
#define LED_AMARELO  9
#define LED_VERMELHO 10

/* ============= LIMITES DE OPERACAO ============= */

#define TEMP_NORMAL_MAX  28.0
#define TEMP_CRITICO_MIN 35.0

/* ============= VARIAVEIS GLOBAIS ============= */

float temperatura = 0.0;
bool  vermelhoState = false;
unsigned long lastBlink = 0;

/* ============= SETUP (EXECUTA 1 VEZ) ============= */

void setup() {
  Serial.begin(9600);
  Serial.println(F("[NexCore IoT] Monitor TMP36 inicializando..."));

  pinMode(LED_VERDE,    OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  desligarTodos();
  delay(1000);
  Serial.println(F("[TMP36] Sistema pronto. Iniciando leituras."));
}

/* ============= LOOP PRINCIPAL ============= */

void loop() {
  temperatura = lerTMP36();
  aplicarLogica();
  exibirSerial();
  delay(2000);
}

/* ============= FUNCOES AUXILIARES ============= */

/**
 * Le o sensor TMP36 e retorna a temperatura em Celsius.
 * Formula: Vout = valorADC * (5.0 / 1024.0)
 *          TempC = (Vout - 0.5) * 100.0
 */
float lerTMP36() {
  int valorADC = analogRead(TMP36_PIN);
  float tensao = valorADC * (5.0 / 1024.0);
  float tempC  = (tensao - 0.5) * 100.0;
  return tempC;
}

/**
 * Aciona os LEDs conforme a faixa de temperatura.
 * Normal  (verde)   : < 28 C
 * Alerta  (amarelo) : >= 28 C e < 35 C
 * Critico (vermelho): >= 35 C (pisca)
 */
void aplicarLogica() {
  desligarTodos();

  if (temperatura < TEMP_NORMAL_MAX) {
    digitalWrite(LED_VERDE, HIGH);
  }
  else if (temperatura >= TEMP_CRITICO_MIN) {
    if (millis() - lastBlink > 500) {
      vermelhoState = !vermelhoState;
      lastBlink = millis();
    }
    digitalWrite(LED_VERMELHO, vermelhoState ? HIGH : LOW);
  }
  else {
    digitalWrite(LED_AMARELO, HIGH);
  }
}

/**
 * Desliga todos os LEDs.
 */
void desligarTodos() {
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

/**
 * Envia os valores para o Serial Monitor.
 */
void exibirSerial() {
  Serial.print(F("[NexCore] Temp = "));
  Serial.print(temperatura, 1);
  Serial.print(F(" C  |  Status: "));

  if (temperatura < TEMP_NORMAL_MAX) {
    Serial.println(F("NORMAL (LED VERDE)"));
  }
  else if (temperatura >= TEMP_CRITICO_MIN) {
    Serial.println(F("CRITICA (LED VERMELHO PISCA)"));
  }
  else {
    Serial.println(F("ALERTA (LED AMARELO)"));
  }
}

// Pinos
const int pinSensorTemp = A0;  // Pino para o sensor de temperatura TMP36
const int pinMotor = 9;        // Pino para o motor DC
const int pinLED = 13;         // Pino para o LED vermelho
const int pinBuzzer = 12;      // Pino para a buzina

void setup() {
  // Configuração dos pinos
  pinMode(pinSensorTemp, INPUT);
  pinMode(pinMotor, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  // Inicializa comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Leitura do sensor de temperatura
  int valorSensor = analogRead(pinSensorTemp);
  float temperatura = map(valorSensor,20,358,-40,125);           
  // Exibe a temperatura na Serial
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  
  // Lógica para controle do motor, LED e buzina
  if (temperatura >= 30.0 && temperatura <= 50.0) {
    digitalWrite(pinMotor, HIGH); // Motor ON
    digitalWrite(pinLED, LOW);    // LED OFF
    digitalWrite(pinBuzzer, LOW); // Buzzer OFF
  }
  else if (temperatura > 50.0) {
    digitalWrite(pinMotor, HIGH);  // Motor ON
    digitalWrite(pinLED, HIGH);    // LED ON
    digitalWrite(pinBuzzer, HIGH); // Buzzer ON
  }
  else {
    digitalWrite(pinMotor, LOW);   // Motor OFF
    digitalWrite(pinLED, LOW);     // LED OFF
    digitalWrite(pinBuzzer, LOW);  // Buzzer OFF
  }
  
  delay(1000); // Aguarda 1 segundo antes de fazer a próxima leitura
}

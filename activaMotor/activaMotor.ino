int pinIntLamina = 5;
int pinIN1 = 7;
int pinIN2 = 8;
int pinPWM = 9;
boolean estadoIntLamina;
int valorPWM = 230;
long tiempoActual;
long tiempoActivacion[5];
int toma = 0;

// Función setup
void setup() {
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinIntLamina, INPUT);
  tiempoActivacion[0] = 30000;
  tiempoActivacion[1] = 60000;
  tiempoActivacion[2] = 120000;
  tiempoActivacion[3] = 240000;
  tiempoActivacion[4] = 24 * 60 * 60000;
}

// Función loop
void loop() {
  digitalWrite(pinIN1, 0);
  digitalWrite(pinIN2, 0);
  analogWrite(pinPWM, valorPWM);
  do {
    tiempoActual = millis();
  } while (tiempoActual < tiempoActivacion[toma]);
  activaMotor();
  toma++;
}

void activaMotor() {
  do {
    digitalWrite(pinIN1, 1);
    estadoIntLamina = digitalRead(pinIntLamina);
  } while (estadoIntLamina == HIGH);
  delay(200);
  do {
    digitalWrite(pinIN1, 1);
    estadoIntLamina = digitalRead(pinIntLamina);
  } while (estadoIntLamina == LOW);
  digitalWrite(pinIN1, 0);
}

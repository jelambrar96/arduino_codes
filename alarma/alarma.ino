// Variables Alarma
int pinBuzzer = 15;
int pinLed1 = 16;
int pinLed2 = 17;
int pinBoton = 2;
boolean banderaAlarma = HIGH;
int rep;
int numRep = 10;
int tiempoEnc = 600;
int tiempoApag = 400;
int tiempoEspera = 9900;


void setup(){
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinBoton, INPUT);
  attachInterrupt(0, Interruptor, RISING);
}

void loop()
{
  Serial.println(banderaAlarma);
  do {
    Alarma();
  } while(banderaAlarma == HIGH);
  
}


void Alarma()
{
  for (rep = 0; rep < numRep; rep++)
  {
    digitalWrite(pinBuzzer, LOW);
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    delay(tiempoEnc);
    digitalWrite(pinBuzzer, HIGH);
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    delay(tiempoApag);
  }
  delay(tiempoEspera);
}

void Interruptor()
{
  Serial.println("interrupcion");
  banderaAlarma = LOW;
}

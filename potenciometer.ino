void setup()
{
Serial.begin(9600);
pinMode(A0, INPUT); 
pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
int potencia = analogRead(A0);
Serial.println(potencia);
///potencia = 1023 - potencia;
analogWrite(LED_BUILTIN, potencia);
delay(100);
}

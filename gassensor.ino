const int AOUTpin=0;
const int DOUTpin=8;
const int ledPin=13;
int limit;
int value;
void setup()
{
Serial.begin(115200);
pinMode(DOUTpin, INPUT);
pinMode(ledPin, OUTPUT);
}
void loop()
{
value= analogRead(AOUTpin);
limit= digitalRead(DOUTpin);
Serial.print("CO value: ");
Serial.println(value);
Serial.print("Limit: ");
Serial.print(limit);
delay(100);
if (limit == HIGH){
digitalWrite(ledPin, HIGH);
}
else
{
digitalWrite(ledPin, LOW);
}
}

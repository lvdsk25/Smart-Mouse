
const int trigger1 = 2;
const int echo1 = 3;
const int trigger2 = 5;
const int echo2 = 6;
long time_taken;
int dist;
void setup() {
  Serial.begin(9600);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
}
void calculate_distance(int trigger, int echo)
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  time_taken = pulseIn(echo, HIGH);
  dist = microsecondsToCentimeters(time_taken);
}
void loop()
{
  calculate_distance(trigger1, echo1);
  if (dist > 0 && dist <= 15)
  {
    Serial.println("up");
    delay (500);
  }
  calculate_distance(trigger1, echo1);
  if (dist > 15 && dist <= 30)
  {
    Serial.println("down");
    delay(500);
  }
  calculate_distance(trigger1, echo1);
  if (dist > 30 && dist <= 45)
  {
    Serial.println("next");
    delay(500);
  }
  calculate_distance(trigger1, echo1);
  if (dist > 45)
  {
    Serial.println("nothing");
    delay(500);
  }
  calculate_distance(trigger2, echo2);
  if (dist > 20 && dist <= 40)
  {
    Serial.println("previous");
    delay(500);
  }
  calculate_distance(trigger2, echo2);
  if (dist > 0 && dist <= 20)
  {
    Serial.println("change");
    delay(500);
  }
  calculate_distance(trigger2, echo2);
  if (dist > 40)
  {
    Serial.println("nothing");
    delay(500);
  }
}
long microsecondsToCentimeters(long microseconds)
{ return microseconds / 29 / 2;
}

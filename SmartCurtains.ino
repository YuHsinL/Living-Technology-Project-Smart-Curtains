int LIGHT_SENSOR_PIN = 36;
int B_1A = 25;
int B_2A = 26;
bool curtains_state = false; //true: open; false: closed

void setup() {
  pinMode(B_1A,OUTPUT);
  pinMode(B_2A,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int lum = analogRead(LIGHT_SENSOR_PIN);
  delay(1000);

  Serial.print("Luminance Value = ");
  Serial.println(lum);

  if (lum > 3000 && curtains_state == true) {
    close_curtains();
    curtains_state = false;
  } else if (lum < 3000 && curtains_state == false) {
    open_curtains();
    curtains_state = true;
  }

}

void open_curtains() {
  digitalWrite(B_1A,LOW);
  digitalWrite(B_2A,HIGH);
  delay(900);
  digitalWrite(B_1A,LOW);
  digitalWrite(B_2A,LOW);
}

void close_curtains() {
  digitalWrite(B_1A,HIGH);
  digitalWrite(B_2A,LOW);
  delay(900);
  digitalWrite(B_1A,LOW);
  digitalWrite(B_2A,LOW);
}
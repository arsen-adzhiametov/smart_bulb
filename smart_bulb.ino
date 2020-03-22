
long firstClap = 0;

int turnedOn = false;
int soundval = LOW;
int in_1 = 1;
int soundinputPin = 0;

void setup() {
  Serial.println("in setup!");
  pinMode(in_1, OUTPUT);
  pinMode(soundinputPin, INPUT);
  firstClap = millis();
  Serial.begin(9600);
}

void loop() {
  soundval = digitalRead(soundinputPin);
  if (soundval == HIGH ) {
    Serial.println("Motion detected!");

    long currentTime = millis();
    long diff = currentTime - firstClap;
    Serial.println(diff);
    if ((diff > 150) && (diff < 450)) {
      Serial.print("double clap: ");
      Serial.println(diff);
      if (turnedOn == false) {
        turnedOn = true;
        digitalWrite(in_1, HIGH);
      } 
      else {
        turnedOn = false;
        digitalWrite(in_1, LOW);
      }
    }
    firstClap = millis();
  }
}


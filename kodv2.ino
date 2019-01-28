int pomiar = 0;
int odleglosc = 0;
int oswietlenie = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup(){
	Serial.begin(9600);
    pinMode(9, INPUT);
}

void loop(){
    odleglosc = 0.01723 * readUltrasonicDistance(A0, A0);
    if (odleglosc > 50){
        Serial.println("Leci samolot do buzi!");
    }
    else{
        Serial.println("Om nom nom!");
    }
    delay (500);
  
  	oswietlenie = digitalRead(2);
    if(oswietlenie == 1){
        Serial.println("*otwieranie buzi*");
    }
    else{
        Serial.println("*buzia zamknięta*"); 
    }
    delay(500);  
}
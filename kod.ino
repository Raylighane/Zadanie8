int pomiar = 0;
int odleglosc = 0;
int oswietlenie = 0;

void setup(){
	Serial.begin(9600);
  	pinMode(A0, INPUT);
    pinMode(9, INPUT);
}

void loop(){
    pomiar = analogRead (A0);
    odleglosc = ((67870 / (pomiar - 3)) - 40);
    if (odleglosc > 500){
        Serial.println("Leci samolot do buzi!");  #duża odległość, obiekt wciąż czeka na łyżeczkę
    }
    else{
        Serial.println("Om nom nom!"); #łyżeczka jest blisko, więc czas otworzyć buzię
    }
    delay (500);
  
  	oswietlenie = digitalRead(2);
    if(oswietlenie == 1){
        Serial.println("*otwieranie buzi*"); #jeśli obraz jest ciemny, czujnik widzi łyżeczkę i otwiera buzię
    }
    else{
        Serial.println("*buzia zamknięta*"); #obraz jest jasny, nie ma łyżeczki, buzia pozostaje zamknięta
    }
    delay(500);  
}

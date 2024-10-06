//setarea pinilor
int buttonPin = 3;
int ledPin = 2;
int senzor = A0;
int senzor2 = A1;
//variabilele ajutatoare//
int stare_buton = 0; //variabila care ne ajuta sa citim starea
butonului
int count = 0; //counterul
int n = 0;
void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(buttonPin, INPUT);
	Serial.begin(9600);
}
void loop() {
	// citim starea valorii butonului
	stare_buton = digitalRead(buttonPin);
	// verificam daca butonul este apasat.Daca este , starea butenului e HIGH.
	if (stare_buton == HIGH && n == 0)
	{
		count++; //crestem countul
		if (count % 2 == 0) //if countul nostru este numar par(la a 2-a
			apasare)
			{
				int citeste = analogRead(senzor);
				int citeste2 = analogRead(senzor2);
				float voltaj = citeste * 0.5;
				float voltaj2 = citeste2 * 0.5;
				voltaj /= 1024.0;
				voltaj2 /= 1024.0;
				float temperatura = (voltaj - 0.5) * 100;
				float temperatura2 = (voltaj2 - 0.5) * 100;
				Serial.print(temperatura);
				Serial.println(" grade in senzorul 1");
				Serial.print(temperatura2);
				Serial.println(" grade in senzorul 2");
				delay(1000);
}
		else {
			// aprinde led
			digitalWrite(ledPin, HIGH);
			delay(100);
			// stinge led
			digitalWrite(ledPin, LOW);
		}
		n = 1;
	}
	else if (stare_buton == LOW)
	{
		n = 0;
	}
}
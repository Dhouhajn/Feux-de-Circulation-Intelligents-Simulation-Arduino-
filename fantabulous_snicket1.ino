// Définition des broches pour les LEDs
const int ledVerte = 4;
const int ledOrange = 3;
const int ledRouge = 2;

// Définition des broches pour le capteur à ultrasons
const int trigPin = 7;  // Broche TRIG
const int echoPin = 6;  // Broche ECHO

// Variables pour le capteur
long duration;
int distance;

void setup() {
  // Configuration des broches LEDs
  pinMode(ledVerte, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledRouge, OUTPUT);
  
  // Configuration des broches du capteur
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialisation de la communication série pour débogage
  Serial.begin(9600);
}

void loop() {
  // Mesure de la distance avec le capteur
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Distance en cm
  
  Serial.print("Distance: ");
  Serial.println(distance);

  // Feu vert : prolongé si un véhicule est détecté (< 50 cm)
  digitalWrite(ledVerte, HIGH);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledRouge, LOW);
  
  if (distance < 50) {
    delay(8000); // Prolonge le feu vert si véhicule détecté
  } else {
    delay(5000); // Durée normale
  }

  // Feu orange
  digitalWrite(ledVerte, LOW);
  digitalWrite(ledOrange, HIGH);
  digitalWrite(ledRouge, LOW);
  delay(2000);

  // Feu rouge
  digitalWrite(ledVerte, LOW);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledRouge, HIGH);
  delay(5000);
}
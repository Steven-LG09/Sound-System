#include <Keypad.h>;

char contrasena[] = "A912";
char contrasena1[] = "B926";
char contrasena2[] = "C123";
char contrasena3[] = "ABC3";
char codigo[4];
char codigo1[4];
char codigo2[4];
char codigo3[4];
int cont = 0;
int cont1 = 0;
int cont2 = 0;
int cont3 = 0;

int estado2 = 0;
int estadoanterior2 = 0;
int salida2 = 0;
int estado1 = 0;
int estadoanterior1 = 0;
int salida1 = 0;

const int ledRojo = A1;
const int ledazul = A3;

const int sensor = 11;
int led1 = 9;
int alarma = A2;
int estado;

int sensorPin = 12; // Entrada para nuestro sensor de sonido
int led = 10;       // Pin Rele
int sensorValue = 0;
int estadoanterior3 = 0;
int salida3 = 0; // Variable para almacenar el valor del sensor
int count = 0;

const byte ROWS = 3;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},

};

byte rowPins[ROWS] = {8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int spk = 13;                            // altavoz a GND y pin 13
int c[5] = {131, 262, 523, 1046, 2093};  // frecuencias 4 octavas de Do
int cs[5] = {139, 277, 554, 1108, 2217}; // Do#
int d[5] = {147, 294, 587, 1175, 2349};  // Re
int ds[5] = {156, 311, 622, 1244, 2489}; // Re#
int e[5] = {165, 330, 659, 1319, 2637};  // Mi
int f[5] = {175, 349, 698, 1397, 2794};  // Fa
int fs[5] = {185, 370, 740, 1480, 2960}; // Fa#
int g[5] = {196, 392, 784, 1568, 3136};  // Sol
int gs[5] = {208, 415, 831, 1661, 3322}; // Sol#
int a[5] = {220, 440, 880, 1760, 3520};  // La
int as[5] = {233, 466, 932, 1866, 3729}; // La#
int b[5] = {247, 494, 988, 1976, 3951};  // Si

void nota(int a, int b); // declaración de la función auxiliar. Recibe dos números enteros.

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(alarma, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(led, LOW);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void nota(int frec, int t)
{
  tone(spk, frec); // suena la nota frec recibida
  delay(t);        // para despues de un tiempo t
}

void loop()
{

  estado = digitalRead(sensor);
  estado2 = digitalRead(A0);
  estado1 = digitalRead(A5);
  sensorValue = digitalRead(12);

  if ((estado2 == HIGH) and (estadoanterior2 == LOW))
  {
    salida2 = 1 - salida2;
    delay(20);
  }
  estadoanterior2 = estado2;
  if (salida2 == 1)
  {
    digitalWrite(A1, HIGH);
  }
  else
  {
    digitalWrite(A1, LOW);
  }
  if ((estado1 == HIGH) and (estadoanterior1 == LOW))
  {
    salida1 = 1 - salida1;
    delay(20);
  }
  estadoanterior1 = estado1;
  if (salida1 == 1)
  {
    digitalWrite(A3, HIGH);
  }
  else
  {
    digitalWrite(A3, LOW);
  }
  if (estado == LOW)
  {
    digitalWrite(led1, LOW);
    digitalWrite(alarma, LOW);
  }
  else
  {
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    digitalWrite(alarma, HIGH);
    delay(200);
    digitalWrite(alarma, LOW);
  }
  sensorValue = digitalRead(sensorPin);
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY)
  {
    codigo[cont] = customKey;
    codigo1[cont1] = customKey;
    codigo2[cont2] = customKey;
    codigo3[cont3] = customKey;

    Serial.print(codigo[cont]);
    cont = cont + 1;
    cont1 = cont1 + 1;
    cont2 = cont2 + 1;
    cont3 = cont3 + 1;

    if (cont == 4)
    {

      if (codigo[0] == contrasena[0] && codigo[1] == contrasena[1] && codigo[2] == contrasena[2] && codigo[3] == contrasena[3])
      {

        digitalWrite(13, !digitalRead(13));
        Serial.println("Password correcta");

        noTone(spk);
        delay(1000);
        nota(b[2], 500);
        nota(e[3], 1000);
        nota(g[3], 250);
        nota(fs[3], 250);
        nota(e[3], 1000);
        nota(b[3], 500);
        nota(d[4], 1000);
        nota(cs[4], 500);
        nota(c[4], 1000);
        nota(a[3], 500);
        nota(c[4], 1000);
        nota(b[3], 250);
        nota(as[3], 250);
        nota(b[2], 1000);
        nota(g[3], 500);
        nota(e[3], 1000);
        noTone(spk);
        delay(2000);
      }

      cont = 0;
    }
    if (cont1 == 4)
    {

      if (codigo1[0] == contrasena1[0] && codigo1[1] == contrasena1[1] && codigo1[2] == contrasena1[2] && codigo1[3] == contrasena1[3])
      {

        digitalWrite(13, !digitalRead(13));
        Serial.println("Password correcta");

        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(ds[2], 500);
        noTone(spk);
        delay(1);
        nota(as[2], 125);
        noTone(spk);
        delay(25);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(ds[2], 500);
        noTone(spk);
        delay(1);
        nota(as[2], 125);
        noTone(spk);
        delay(25);
        nota(g[2], 500);
        noTone(spk);
        delay(2000);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(ds[2], 500);
        noTone(spk);
        delay(1);
        nota(as[2], 125);
        noTone(spk);
        delay(25);
        nota(g[2], 500);
        noTone(spk);
        delay(100);
        nota(ds[2], 500);
        noTone(spk);
        delay(1);
        nota(as[2], 125);
        noTone(spk);
        delay(25);
        nota(g[2], 500);
        noTone(spk);
        delay(2000);
      }

      cont1 = 0;
    }
    if (cont2 == 4)
    {

      if (codigo2[0] == contrasena2[0] && codigo2[1] == contrasena2[1] && codigo2[2] == contrasena2[2] && codigo2[3] == contrasena2[3])
      {

        digitalWrite(13, !digitalRead(13));
        Serial.println("Password correcta");

        nota(d[1], 150);
        noTone(spk);
        delay(50);
        nota(d[1], 150);
        noTone(spk);
        delay(50);
        nota(d[1], 150);
        noTone(spk);
        delay(50);
        nota(g[1], 900);
        noTone(spk);
        delay(150);
        nota(d[2], 900);
        noTone(spk);
        delay(50);
        nota(c[2], 150);
        noTone(spk);
        delay(50);
        nota(b[1], 150);
        noTone(spk);
        delay(50);
        nota(a[1], 150);
        noTone(spk);
        delay(50);
        nota(g[2], 900);
        noTone(spk);
        delay(150);
        nota(d[2], 900);
        noTone(spk);
        delay(100);
        nota(c[2], 150);
        noTone(spk);
        delay(50);
        nota(b[1], 150);
        noTone(spk);
        delay(50);
        nota(a[1], 150);
        noTone(spk);
        delay(50);
        nota(g[2], 900);
        noTone(spk);
        delay(150);
        nota(d[2], 900);
        noTone(spk);
        delay(100);
        nota(c[2], 150);
        noTone(spk);
        delay(50);
        nota(b[1], 150);
        noTone(spk);
        delay(50);
        nota(c[2], 150);
        noTone(spk);
        delay(50);
        nota(a[1], 1200);
        noTone(spk);
        delay(2000);
      }
      cont2 = 0;
    }

    if (cont3 == 4)
    {

      if (codigo3[0] == contrasena3[0] && codigo3[1] == contrasena3[1] && codigo3[2] == contrasena3[2] && codigo3[3] == contrasena3[3])
      {

        digitalWrite(13, !digitalRead(13));
        Serial.println("Password correcta");

        nota(a[1], 400);
        noTone(spk);
        delay(400);
        nota(e[1], 400);
        noTone(spk);
        delay(400);
        nota(a[1], 400);
        noTone(spk);
        delay(200);
        nota(e[1], 200);
        noTone(spk);
        delay(200);
        nota(a[1], 200);
        noTone(spk);
        delay(200);
        nota(as[1], 100);
        noTone(spk);
        delay(100);
        nota(b[1], 400);
        noTone(spk);
        delay(400);
        nota(fs[1], 400);
        noTone(spk);
        delay(400);
        nota(b[1], 400);
        noTone(spk);
        delay(200);
        nota(fs[1], 200);
        noTone(spk);
        delay(200);
        nota(b[1], 200);
        noTone(spk);
        delay(200);
        nota(as[1], 100);
        noTone(spk);
        delay(100);
        nota(a[1], 400);
        noTone(spk);
        delay(400);
        nota(e[1], 400);
        noTone(spk);
        delay(400);
        nota(a[1], 400);
        noTone(spk);
        delay(400);
      }
      if (codigo3 != contrasena3)
      {

        Serial.println("Password incorrecta");
      }

      cont3 = 0;
    }
  }
  if ((sensorValue == HIGH) and (estadoanterior3 == LOW))
  {
    salida3 = 1 - salida3;
    delay(20);
  }
  estadoanterior3 = sensorValue;
  if (salida3 == 1)
  {
    digitalWrite(led, HIGH);
  }

  else
  {
    digitalWrite(led, LOW);
  }
}

//Este es el bueno bueno :v/
//Librerias para comunicación con el sensor y la LCD
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// Pin donde está conectado DQ
const byte pinDatosDQ = 12;
//Configuramos pines para transmitir informacion y controlar la LCD
LiquidCrystal lcd(7,6,5,4,3,2);

// Insncia a las clases OneWire y DallasTemperature
OneWire OneWireObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&OneWireObjeto); // & hace que no se pase la posición, sino la posicón de memoria donde está almacenado ese dato

void setup() {
  
  lcd.begin(16, 2);  //Tamaño de la LCD (está en orden (x, y))
  // Iniciamos el bus OneWire
  sensorDS18B20.begin();
  Serial.begin(9600);

}

void loop() {
  // Mandamos comandos para toma de temperatura a los sensores
  sensorDS18B20.requestTemperatures();
  
  //Colocamos el cursor al principio de la pantalla para empezar a escribir
  lcd.setCursor(0,0);
  //Imprimimos en pantalla
  lcd.print("Temperatura");
  //Reposicionamos el cursor
  lcd.setCursor(0,1);  // Coloca el cursor en la línea 0,1
  //Imprimimos la temperatura obtenida del sensor
  lcd.print(sensorDS18B20.getTempCByIndex(0));
  lcd.print(" C");
  //delay(500);
  //lcd.clear();
  Serial.print("Temperatura: \n");
  Serial.print(sensorDS18B20.getTempCByIndex(0));
  Serial.print(" C");
}

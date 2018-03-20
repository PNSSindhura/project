#include <MQ135.h>
#include <DHT.h>
#define DHTPIN 2     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

int chk;
float hum;
float temp;
int sensorValue;
int digitalValue;




void setup()
{
    Serial.begin(9600);
     pinMode( 0, INPUT);
  dht.begin();
    
}
void loop()
{
  MQ135 gasSensor = MQ135(A0);
  float air_quality = gasSensor.getPPM();
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    sensorValue = analogRead(0);       
    digitalValue = digitalRead(0); 
    Serial.println(sensorValue, DEC);
    if (air_quality<=1000)
{
Serial.println("Methane gas released");
//Serial.println (" PPM ");
digitalWrite(8, LOW);
}
else if( air_quality>=1000 && air_quality<=2000 )
{
Serial.println("Few gases released");
//Serial.println (" PPM ");
digitalWrite(8, HIGH );
}
else if (air_quality>=2000 )
{
Serial.println("All gases released");
//Serial.println (" PPM ");
digitalWrite(8, HIGH);   // turn the LED on
}
    delay(2000);                      

}
    


   

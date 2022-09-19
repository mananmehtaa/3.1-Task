/* Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float temperature_sense;
  bool led_state;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include<DHT.h>
#include<DHT_U.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
//float temperature_sense;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1000); 
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  
  //Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop()
{
  ArduinoCloud.update();
  // Your code here 
  temperature_sense = dht.readTemperature();
  
  if( temperature_sense > 29.5)
  {
    led_state = true;
    digitalWrite(LED_BUILTIN, led_state);
  }

  else
  {
    led_state = false;
    digitalWrite(LED_BUILTIN,led_state);
  }
  delay(1000);
}

/*
  Since LedState is READ_WRITE variable, onLedStateChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedStateChange() 
{
  // Add your code here to act upon LedState change
   
   

}

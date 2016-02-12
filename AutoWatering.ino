/*================================
   AUTOMATIC WATERING SYSTEM 
==================================  
 Christophe Cachin - October 2015
---------------------------------- 
   == Description ==
   A sensor check the soil moisture and when it's dry a pump is switched on.
   The pump is switched off when the sensor is wet. 
   To avoid an overfill or sensor error, the time to fill is blocked to 40 seconds.

   == Material ==
   - Arduino Uno
   - Relay 
   - Pump (DC Motor)
   - Hygrometer Sensor
   - Potentiometer
*/

	/*------- PINS & STATES DEFINITION --------*/
	#define SensorPin A0
	#define PotPin A2
	#define Relay 8
	#define Fill digitalWrite(Relay, HIGH); 	//Activate Relay (pump)
	#define FillOff digitalWrite(Relay,LOW);	//Deactivate Relay (pump)

	/*--------- INITIALIZATION ------------------*/
	int SensorValue = 0;
	int map_SensorValue = 0;
	int sensor_val = 0;
	int PotValue = 0;
	int map_PotValue = 0;

	int dry = 0;
	int maxTime = 20000; //  Max time to fill in millisecondes (=>40 sec)
	unsigned long timer = 0;
	int Dtimer = 0; // Delta timer
 
void setup(){ 
  Serial.begin(9600);
  pinMode(Relay,OUTPUT);
  FillOff;
}

/*------------------------ FUNCTIONS -----------------------------*/
int ReadSensorValue(){ 								//Read and map the sensor value
  SensorValue = analogRead(SensorPin); 				// Read the sensor value
  map_SensorValue = map(SensorValue,0,1023,0,100);	// Scale value from 0 to 100
  return map_SensorValue;
 }
 int Potentiometer_value(){ 						//Read and map the potentiometer value
  PotValue = analogRead(PotPin);
  map_PotValue = map(PotValue,0,1023,40,135); 		// Scale value from 40 to 135. Values defined after tests. When it's fry, the sensor value is >90
  return map_PotValue;
 }

/*------------------------ START PROGRAM ---------------------------*/
void loop(){

   sensor_val = ReadSensorValue(); 	//Read the sensor value
   dry = Potentiometer_value(); 	// Set the "dry" value equal to the potentiometer value
   timer=millis(); 					//Set start point in time
    
	/*--- Display variables values in serial monitor ---*/
		Serial.println("===== IDLE MODE =====");
		Serial.print("Sensor value: ");
		Serial.println(sensor_val);
		Serial.print("Potentiometer value: ");
		Serial.println(dry); 
		Serial.print("Timer: ");
		Serial.println(Dtimer);
  
  while((sensor_val >= dry)&&(Dtimer<=40000)){  //temps de remplissage 
      Fill; 									//Watering 
      sensor_val = ReadSensorValue(); 			// Check the sensor value
      Dtimer= millis() - timer; 				// Check delta time 
	  
	  /*--- Display variables values in serial monitor /---*/
		  Serial.println("===== WATERING =====");
		  Serial.print("Sensor value: ");
		  Serial.println(topsensor_val);
		  Serial.print("Potentiometer value: ");
		  Serial.println(dry); 
		  Serial.print("Timer: ");
		  Serial.println(Dtimer); 

      delay(500); 	// Avoid uprocessor overloading
  }
  FillOff; 			// Stop watering
  Dtimer=0; 		// Reset timer value

  Serial.println("===== PAUSE ====="); 	// Indication in serial monitor work is done
  delay(18000000); 						// Pause for 5 hours to save energy.
  
}


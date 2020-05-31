/*Bu kodlar AnalogOutSerial örnek Arduino dosyası baz alınarak hazırlanmıştır*/
/*These codes are based on the AnalogOutSerial sample Arduino file*/
/*Bu Proje Saksılarınızın ve Çiçek topraklarınızın sululuk derecesini ölçer*/
// Author : MUSTAFA ERGÜL 

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(9, OUTPUT);  // Set the pin 9 as an output
  pinMode(8, OUTPUT);  //Set the pin 8 as an output
  pinMode(7, OUTPUT);  //Set the pin 7 as an output
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:

if(sensorValue>0 && sensorValue<200){ //If the water level is low, the commands will work.
  digitalWrite(9,HIGH); 
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  }
 
if(sensorValue>=200 && sensorValue<600){ // If the water level in the middle, the commands will work.
   digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(7,LOW);
}
 if(sensorValue>=600){ //If the water level is normal, the commands will work.
  digitalWrite(7,HIGH );
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
    }

  
    
 
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(1);
}

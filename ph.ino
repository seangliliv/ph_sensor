#include <DHT.h>

int phPin = A1;         // Pin 
  

class Sensor {
private:
  float ph;
   
public:
  // Constructor
  Sensor() {
    // Initialize 
    ph = 0;
     
    
  }

  // Setter methods
  void setPh(float p) {
    ph = p;
  }

 

  // Getter methods
  float getPh() {
    return ph;
  }

  
};


Sensor mySensor;  
 

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // Read 
  int buffer_arr[10];
for (int i = 0; i < 10; i++) {
    buffer_arr[i] = analogRead(phPin);
    delay(30);
  }
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buffer_arr[i] > buffer_arr[j]) {
       int temp = buffer_arr[i];
        buffer_arr[i] = buffer_arr[j];
        buffer_arr[j] = temp;
      }
    }
  }
  unsigned long int avgval = 0;
  for (int i = 2; i < 8; i++)
     avgval += buffer_arr[i];
  float volt = (float)avgval * 5.0 / 1024 / 6;
  float ph= -5.70 * volt + 21.34;

  // Set 
  mySensor.setPh(ph);

  // Get 
  float currentPh = mySensor.getPh();
  
//  Serial.print("Ph: ");
  Serial.println(currentPh);
   

  delay(1000);  
}

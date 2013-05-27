#define LED  13
#define BUTTON 7  
                  
int val = 0;      
                  
int old_val = 0;  
                  
int state = 0;     

const int analogInPin = A0;
const int analogOutPin = 4;
int sensorValue = 0;        
int outputValue = 0;


void setup() { 
  pinMode(LED, OUTPUT);     
  pinMode(BUTTON, INPUT);   
  Serial.begin(9600);
} 
void loop(){ 
  val = digitalRead(BUTTON);  
                             

  // check if there was a transition 
  if ((val == HIGH) && (old_val == LOW)){ 
    state = 1 - state; 
  } 

  old_val = val;   

  if (state == 1) {      
    digitalWrite(LED, HIGH);  
  } else { 
    digitalWrite(LED, LOW); 
  }
 // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 100, 200, 255, 0);  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue); 
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);
  delay(2);
} 


//rocket launcher V1.1
//1 = launch sequence
//2 = test sequence will be where system check
//3 = beep count down
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);//set baud rate
  
  //set variable pins
  int fire = 12;//launch rocket OUTPUT
  int launch_led = 1;//LED for when rocket launches OUTPUT
  int test_gnd = 2;//test to see if ground touches launch pad INPUT
  int test_hot = 3;//test to see if positive touches launch pad INPUT
  int gndError = 4;//ground launch pad error LED OUTPUT
  int hotError = 5;//hot launch pad error LED OUTPUT
  int error_led = 6;//error LED OUTPUT
  int cont_led = 7;//continuity LED OUTPUT
  int test_cont = 8;//read continuity INPUT
  int disarmed_led = 10;//disarmed led
  int fire_power = 11;//dignostic 
  
  //holding variables
  int gnd;
  int hot;
  int cont;
  
  //C# hold variable
  byte code;
  
  //set mode
  
  //output pins
  pinMode(fire, OUTPUT);
  pinMode(launch_led, OUTPUT);
  pinMode(gndError, OUTPUT);
  pinMode(hotError, OUTPUT);
  pinMode(error_led, OUTPUT);
  pinMode(cont_led, OUTPUT);
  pinMode(fire_power, OUTPUT);
  
  //input pins
  pinMode(test_gnd, INPUT);
  pinMode(test_hot, INPUT);
  pinMode(test_cont, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //test connections..............................
  gnd = digitalRead(test_gnd);
  hot = digitalRead(test_hot);
  cont = digitalRead(test_cont);
  //..............................................
  
  //turn off all OUTPUT pins
  digitalWrite(fire, LOW);
  digitalWrite(launch_led, LOW);
  digitalWrite(gndError, LOW);
  digitalWrite(hotError, LOW);
  digitalWrite(error_led, LOW);
  digitalWrite(cont_led, LOW);
  
  //turn on disarmed LED
  digitalWrite(disarmed_led, HIGH);
  
  //launch sequence fire system
  if(Serial.available() > 0)
  {
    code = Serial.read();
    
    if(gnd == LOW && hot == LOW && cont == HIGH)// test that neither connection on the rocket is bad and count is 0
    {  
      
        //turn on cont LED
        digitalWrite(cont_led, HIGH);
        
        //turn off disarmed LED
        digitalWrite(disarmed_led, LOW);
      
        //launch sequence
        if(code == 1)
        {
          //turn on system
          digitalWrite(launch_led, HIGH);//turn on launch LED
          digitalWrite(fire, HIGH);//fire rocket
       
        
          //reset system when ignitor is broken after launch and turn on disarmed LED
          if(cont == LOW)
          {
            //turn off LEDs and fire realy
            digitalWrite(launch_led, LOW);
            digitalWrite(fire, LOW);
            digitalWrite(cont_led, LOW);
            digitalWrite(disarmed_led, HIGH);
            
          }
        }
        
        
      }
      else
      {
        
        // if the gnd or hot test jumper are hot send error or if cont is no good send error
        while(gnd == HIGH || hot == HIGH || cont == LOW)
        {
          
           Serial.write("error");
           
           //turn on error LED
           digitalWrite(error_led, HIGH);
           
           //blink both test LEDs if both are shorted
           while(gnd == HIGH && hot == HIGH)
           {
             
             digitalWrite(gndError, HIGH);
             digitalWrite(hotError, HIGH);
             delay(500);
             digitalWrite(gndError, LOW);
             digitalWrite(hotError, LOW);
             
           }
           
           //blink gnd test probe LED if error
           while(gnd == HIGH)
           {
             
             digitalWrite(gndError, HIGH);
             delay(500);
             digitalWrite(gndError, LOW);
             
           }
           
           //blink hot test Probe LED if error
           while(hot == HIGH)
           {
             
             digitalWrite(hotError, HIGH);
             delay(500);
             digitalWrite(hotError, LOW);
             
           }
           
           //blink cont LED if error
           while(cont == LOW)
           {
             
             digitalWrite(cont_led, HIGH);
             delay(500);
             digitalWrite(cont_led), LOW);
             
           }
           
          
        }
        
        
      }
  }
  

}

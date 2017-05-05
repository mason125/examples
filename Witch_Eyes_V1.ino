//Witch eyes
//8/18/2014
//Mason White
//Version 1

//pins 3,4 and 5 are for the witch eyes
//pin 8 is for the body
//there is no body blinking in this program
int blue = 3;
int red = 4;
int green = 5;
int body = 8;
void setup() {
  // put your setup code here, to run once:

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(body, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //body on only
  digitalWrite(body, HIGH);
  //
  
  //eyes colors
  
  //green
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
  delay(1000);
  
  //red
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  
  //blue
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);
  delay(1000);
  
  //white
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
  delay(1000);
  
  //red and green
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);
  delay(1000);
  
  //red and blue
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(green, LOW);
  delay(1000);
  
  //blue and green
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  delay(1000);
}

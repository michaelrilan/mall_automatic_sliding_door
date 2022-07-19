
#include <LiquidCrystal.h>
#include <Servo.h>


Servo myservo_entrance;
Servo myservo_exit;
int pir_entrance=7;
int pir_entry_counter = 8;
int pir_exit = 13;
int pir_exit_counter = 9;
int maximum_visitors;
int count;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  count = 0; //initialize the count to 0
  maximum_visitors = 10;
  pinMode(pir_entrance,INPUT);
  pinMode(pir_entry_counter,INPUT);
  pinMode(pir_exit,INPUT);
  pinMode(pir_exit_counter,INPUT);
  
  lcd.begin(1, 2);
  lcd.print("Max Visitor:" + String(maximum_visitors));
  lcd.setCursor(0, 2);
  lcd.print("Entries:" + String(count));
  myservo_entrance.attach(6);
  myservo_exit.attach(10);
  Serial.begin(9600);
}

//Entrance Code
void entrance(){
  int state_entrance = digitalRead(pir_entrance);
  if(state_entrance == HIGH && count!=maximum_visitors){
    
    myservo_entrance.write(90);
  }
  else{
    myservo_entrance.write(0);
  }

  
  delay(100);
}

void entry_counter(){
  int state_entry_counter = digitalRead(pir_entry_counter);
  if(state_entry_counter == HIGH){
   count = count+1;
   lcd.setCursor(0, 2);
   lcd.print("Entries:" + String(count));
   
  }

  
  delay(600);

}

//Exit Code
void exit(){
  int state_exit = digitalRead(pir_exit);
  if(state_exit == HIGH){
    
    myservo_exit.write(90);
  }
  else{
    myservo_exit.write(0);
  }
  
  delay(100);
}

void exit_counter(){
  int state_exit_counter = digitalRead(pir_exit_counter);
  if(state_exit_counter == HIGH && count>0){
   count = count-1;
   lcd.setCursor(0, 2);
   lcd.print("Entries:" + String(count));
   
  }

  
  delay(600);

}

void loop() {
  entrance();
  entry_counter();
  exit();
  exit_counter();
  
  
}
 

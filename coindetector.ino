/*
  A SIMPLE PESO COIN DETECTOR AND COUNTER USING BUTTONS
  SIMULATED IN PROTEUS
  MATERIALS USED IN PROTEUS:
  ARDUINO MEGA 2560
  BUTTON
  LM016L

  LIMITED TO 1, 5, 10 PHP COINS ONLY
*/

#include <LiquidCrystal.h>


LiquidCrystal lcd(30, 32, 34, 31, 33, 35, 37);
const byte interruptPin1 = 21;
const byte interruptPin2 = 18;
const byte interruptPin3 = 19;
const byte interruptPin4 = 20;
const byte interruptPin5 = 3;
volatile int value10 = 0;
volatile int value5 = 0;
volatile int value1 = 0;
volatile int valueswitch = 0;
volatile int countOne = 0 ;
volatile int countFive = 0;
volatile int countTen = 0;
volatile
int TOTAL=0;

void setup() {
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);
  pinMode(interruptPin4, INPUT_PULLUP);
  pinMode(interruptPin5, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), coinOne , RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), coinFive , RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), coinTen , RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin4), show_1_5_10, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin5), show_total, RISING);
  lcd.begin(16,2);
  
  lcd.print("COIN DETECTOR &");
  lcd.setCursor(1, 1);
  lcd.print("AMOUNT COUNTER");
  delay(1200);
  delay(1200);
  delay(1200);
  
  lcd.begin(16,2);
  lcd.print("INSERT THE COIN");


  Serial.begin(9600);
  Serial.println("");
  Serial.print("COIN DETECTOR , SORT & AMOUNT COUNTER ");
}

void loop() {
  delay(2000);
  lcd.begin(16, 2);
  lcd.print("INSERT THE COIN");
}

/*

  BUTTONS

*/

// 1st button add 1php coin
void coinOne() {
  countOne++;
  value1 = (countOne);
  Serial.println("\
");
  Serial.println(" 1Php coin = \
 ");
  Serial.print(value1);
  Serial.print("Php");
}

// 2nd button add 5php coin
void coinFive() {
  countFive++;

  value5 = (countFive * 5);
  Serial.println("\
  ");
  Serial.println(" 5Php coin = \
  ");
  Serial.print(value5);
  Serial.print("Php");
}

// 3rd button add 10php coin
void coinTen() {
  countTen++;
  value10 = (countTen * 10);
  Serial.println("\
");

  Serial.println(" 10Php coin = \
 ");
  Serial.print(value10);
  Serial.print("Php");

  Serial.println("\
");
}

// 4th button display number and amount 1 5 10 php coins
void show_1_5_10() {

  // number of 1php coins
  Serial.println("\
");
  Serial.println(" Number of 1Php coins =  \
 ");
  Serial.print(countOne);
  Serial.println("\
");

  // total amount of 1php coins
  Serial.println(" TOTAL 1Php COINS =  \
 ");
  Serial.print(value1);
  Serial.print("Php");
  Serial.println("\
");

 // number of 5php coins
  Serial.println(" Number of 5Php coins =  \
 ");
  Serial.print(countFive);
  Serial.println("\
");

  // total amount of 5php coins
  Serial.println(" TOTAL 5Php COINS =  \
 ");
  Serial.print(value5);
  Serial.print("Php");

 Serial.println("\
");

  // number of 10php coins
  Serial.println(" Number of 10Php coins =  \
 ");
  Serial.print(countTen);
  Serial.println("\
");

  // total amount of 10php coins
  Serial.println(" TOTAL 10Php COINS =  \
 ");
  Serial.print(value10);

  Serial.print("Php");


  // Dislpay 1Php in LCD
  lcd.begin(16, 2);
  lcd.print(" 1Php coin = \
  ");
  lcd.setCursor(11,0);
  lcd.print(value1);


  // Display 5Php in LCD
  lcd.begin(16, 2);
  lcd.print(" 5Php coin = \
  ");
  lcd.setCursor(11, 0);
  lcd.print(value5);

  // display 10Php in LCD
  lcd.begin(16, 2);
  lcd.print(" 10Php coin = \
  ");
  lcd.setCursor(11, 0);
  lcd.print(value10);
}

// 5th button display total amount
void show_total() {
  
  // Display total in LCD
  TOTAL=(value1+value5+value10);
  lcd.setCursor(0, 1);
  lcd.print(" TOTAL = ");
  lcd.setCursor(11, 1);
  lcd.print(TOTAL);
  Serial.println("\
");

  // in virtual terminal
  Serial.println(" TOTAL AMOUNT =  \
 ");
  Serial.print(TOTAL);
  Serial.print("Php");
}

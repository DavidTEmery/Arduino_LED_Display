// DavidE  2/16/15 4-digit 7-segment common-anode LED Display code
// Counting up in minutes and seconds approximately on my Uno clone.
// I find that a strobe of 3500 and a delay of 20 microseconds is very close.

// Special thanks to Rudy Schlaf for the tutorial
// https://www.youtube.com/watch?v=sXJ_ILTs6IE

// Arduino pins 2-5 are the common anodes
const int anode1 = 2;
const int anode2 = 3;
const int anode3 = 4;
const int anode4 = 5;

// Arduino pins 6-12 are the cathodes(-) named after the segments of the display:
const int A = 6;
const int B = 7;
const int C = 8;
const int D = 9;
const int E = 10;
const int F = 11;
const int G = 12;
// Aduino pin 13 will drive the colon:
const int colon = 13;

// array of the cathode pins:
const int segments[7] = { A, B, C, D, E, F, G };

// 10 numerals: 0-9
//  7 segments: A-G
const int numerals[10][7] = { 
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

// determines how many times each digit is strobed
static const int strobe = 3500;

void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  digitalWrite(A, LOW);
  pinMode(B, OUTPUT);
  digitalWrite(B, LOW);
  pinMode(C, OUTPUT);
  digitalWrite(C, LOW);
  pinMode(D, OUTPUT);
  digitalWrite(D, LOW);
  pinMode(E, OUTPUT);
  digitalWrite(E, LOW);
  pinMode(F, OUTPUT);
  digitalWrite(F, LOW);
  pinMode(G, OUTPUT);
  digitalWrite(G, LOW);
  pinMode(colon, OUTPUT);
  digitalWrite(colon, LOW);

  pinMode(anode1, OUTPUT); 
  digitalWrite(anode1, LOW);
  pinMode(anode2, OUTPUT);
  digitalWrite(anode2, LOW);
  pinMode(anode3, OUTPUT);
  digitalWrite(anode3, LOW);
  pinMode(anode4, OUTPUT);
  digitalWrite(anode4, LOW);
}

void loop() {
  for (int num1=0; num1 < 6; num1++) { //minutes
    for (int num2=0; num2 < 10; num2++) {
      for (int num3=0; num3 < 6; num3++){ //seconds
        for (int num4=0; num4 < 10; num4++){
          for(int t=0; t<strobe; t++){
            makeNum(num1,anode1); 
            makeNum(num2,anode2); 
            makeNum(num3,anode3); 
            makeNum(num4,anode4); 
            }
          }
        }
      }
    }
  }

// This function makes the numeral for the digit specified by the anode pin
void makeNum(int numeral, int digit){
  for (int seg = 0; seg < 7; seg++){
    if (numerals[numeral][seg]==1) 
      {digitalWrite(segments[seg], LOW);}     // set cathode of the segment LOW for ON if the numbers array shows a 1
    else {digitalWrite(segments[seg], HIGH);} // set cathode of the segment HIGH for OFF if the numbers array shows a 0
  }
  digitalWrite(digit, HIGH);  // set anode high for on
  delayMicroseconds (20); // How long to leave the digit on
  digitalWrite(digit, LOW);   // set anode low for off
}


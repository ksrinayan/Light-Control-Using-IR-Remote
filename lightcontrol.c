#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 2;

// Define LED pin
#define RED    6
#define GREEN  5
#define WHITE  7


// Define integer to remember toggle state
int redState = 0;
int greenState = 0;
int whiteState = 0;
;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(WHITE, OUTPUT);
  
}


void loop() {
  if (irrecv.decode(&results)) {

    switch (results.value) {

      case 0xE0E020DF:

        if (redState == 0) {
          digitalWrite(RED, HIGH);
          redState = 1;
        }
        else {
          digitalWrite(RED, LOW);
          redState = 0;

        }
        break;

      case 0xE0E0A05F:

        if (greenState == 0) {
          digitalWrite(GREEN, HIGH);
          greenState = 1;
        }
        else {
          digitalWrite(GREEN, LOW);
          greenState = 0;

        }
        break;

      case 0xE0E0609F:

        if (whiteState == 0) {
          digitalWrite(WHITE, HIGH);
          whiteState = 1;
        }
        else {
          digitalWrite(WHITE, LOW);
          whiteState = 0;

        }
        break;
        case 0xE0E010EF:
          if(whiteState==0 || greenState == 0 || redState == 0 ){
            digitalWrite(WHITE,HIGH);
            digitalWrite(RED,HIGH);
            digitalWrite(GREEN,HIGH);
            whiteState = 1;
            greenState = 1;
            redState = 1;
          }
          else {
          digitalWrite(WHITE, LOW);
          digitalWrite(RED,LOW);
          digitalWrite(GREEN,LOW);
          whiteState = 0;
          greenState = 0;
          redState = 0;

        }
        break;

      


    }
    irrecv.resume();
  }

}
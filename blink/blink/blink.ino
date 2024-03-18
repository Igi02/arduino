// Define the LED pin
int dotLength = 1000;

void setup() {
  // Set the LED pin as an output

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Wait for user input from serial monitor
  /*if (Serial.available() > 0) {
    // Read the input message from the serial monitor
    String message = Serial.readStringUntil('\n');
    Serial.println("Sending message: " + message);
    // Translate and blink the message in Morse code
    translateAndBlink(message);
  }*/

  // Input message
  String message = "Hello World!";
  Serial.println("Sending message: " + message);
  // Translate and blink the message in Morse code
  translateAndBlink(message);
}

// Function to translate and blink the message in Morse code
void translateAndBlink(String message) {
  // Iterate through each character in the message
  for (int i = 0; i < message.length(); i++) {
    char character = message.charAt(i);
   
    // Translate the character to Morse code and blink accordingly
    switch(character) {
      case 'A':
      case 'a':
        morseDot();
        morseDash();
        break;
      case 'B':
      case 'b':
        morseDash();
        morseDot();
        morseDot();
        morseDot();
        break;
      case 'C':
      case 'c':
        morseDash();
        morseDot();
        morseDash();
        morseDot();
        break;
      case 'D':
      case 'd':
        morseDash();
        morseDot();
        morseDot();
        break;
      case 'E':
      case 'e':
        morseDot();
        break;
      case 'F':
      case 'f':
        morseDot();
        morseDot();
        morseDash();
        morseDot();
        break;
      case 'G':
      case 'g':
        morseDash();
        morseDash();
        morseDot();
        break;
      case 'H':
      case 'h':
        morseDot();
        morseDot();
        morseDot();
        morseDot();
        break;
      case 'I':
      case 'i':
        morseDot();
        morseDot();
        break;
      case 'J':
      case 'j':
        morseDot();
        morseDash();
        morseDash();
        morseDash();
        break;
      case 'K':
      case 'k':
        morseDash();
        morseDot();
        morseDash();
        break;
      case 'L':
      case 'l':
        morseDot();
        morseDash();
        morseDot();
        morseDot();
        break;
      case 'M':
      case 'm':
        morseDash();
        morseDash();
        break;
      case 'N':
      case 'n':
        morseDash();
        morseDot();
        break;
      case 'O':
      case 'o':
        morseDash();
        morseDash();
        morseDash();
        break;
      case 'P':
      case 'p':
        morseDot();
        morseDash();
        morseDash();
        morseDot();
        break;
      case 'Q':
      case 'q':
        morseDash();
        morseDash();
        morseDot();
        morseDash();
        break;
      case 'R':
      case 'r':
        morseDot();
        morseDash();
        morseDot();
        break;
      case 'S':
      case 's':
        morseDot();
        morseDot();
        morseDot();
        break;
      case 'T':
      case 't':
        morseDash();
        break;
      case 'U':
      case 'u':
        morseDot();
        morseDot();
        morseDash();
        break;
      case 'V':
      case 'v':
        morseDot();
        morseDot();
        morseDot();
        morseDash();
        break;
      case 'W':
      case 'w':
        morseDot();
        morseDash();
        morseDash();
        break;
      case 'X':
      case 'x':
        morseDash();
        morseDot();
        morseDot();
        morseDash();
        break;
      case 'Y':
      case 'y':
        morseDash();
        morseDot();
        morseDash();
        morseDash();
        break;
      case 'Z':
      case 'z':
        morseDash();
        morseDash();
        morseDot();
        morseDot();
        break;
      case ' ':
        // Add a delay for space between words
        delay(dotLength*7);
        break;
      case '.':
        // Morse code for period (.)
        morseDot();
        morseDot();
        morseDot();
        morseDash();
        morseDash();
        morseDash();
        break;
      case ',':
        // Morse code for comma (,)
        morseDash();
        morseDash();
        morseDot();
        morseDot();
        morseDash();
        morseDash();
        break;
      case '!':
        // Morse code for exclamation mark (!)
        morseDash();
        morseDot();
        morseDash();
        morseDot();
        morseDash();
        morseDash();
        break;
      case '?':
        // Morse code for question mark (?)
        morseDot();
        morseDot();
        morseDash();
        morseDash();
        morseDot();
        morseDot();
        break;
      default:
        // Ignore unknown characters
        break;
    }
   
    // Add a delay between characters
    delay(dotLength*3);
  }
}

// Function to represent a dot in Morse code
void morseDot() {
  digitalWrite(ledPin, HIGH);
  delay(dotLength); // Dot duration
  digitalWrite(ledPin, LOW);
  delay(dotLength); // Inter-element gap
}

// Function to represent a dash in Morse code
void morseDash() {
  digitalWrite(ledPin, HIGH);
  delay(dotLength*3); // Dash duration
  digitalWrite(ledPin, LOW);
  delay(dotLength); // Inter-element gap
}
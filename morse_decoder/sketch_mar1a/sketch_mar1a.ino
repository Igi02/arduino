// Define the pin number for the LED
const int ledPin = 11;

// Morse code dictionary
const char* morseCodeLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Example: Encode and then decode the letter "S"
  char letterToEncode = 'S';
  String encoded = encodeMorse(letterToEncode);
  char decoded = decodeMorse(encoded);
  
  // Output the encoded and decoded messages
  Serial.begin(9600);
  Serial.print("Encoded Morse code: ");
  Serial.println(encoded);
  Serial.print("Decoded letter: ");
  Serial.println(decoded);
  
  // Blink the LED according to the encoded Morse code
  sendMorseCode(encoded); 
  // Wait for 3 seconds
  delay(3000);
}

// Function to encode a letter to Morse code
String encodeMorse(char letter) {
  if (letter >= 'A' && letter <= 'Z') {
    // Convert uppercase letter to Morse code
    return String(morseCodeLetters[letter - 'A']);
  } else if (letter >= 'a' && letter <= 'z') {
    // Convert lowercase letter to Morse code
    return String(morseCodeLetters[letter - 'a']);
  } else {
    // If the character is not a letter, return an empty string
    return "";
  }
}

// Function to decode Morse code to a letter
char decodeMorse(String morse) {
  for (int i = 0; i < 26; i++) {
    if (morse == String(morseCodeLetters[i])) {
      // Found the Morse code in the dictionary, return the corresponding letter
      return (char)('A' + i);
    }
  }
  // If Morse code is not found in the dictionary, return a question mark '?'
  return '?';
}

// Function to send Morse code signal for a given string
void sendMorseCode(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    if (morseCode[i] == '.') {
      // Send a dot signal (short blink)
      digitalWrite(ledPin, HIGH);
      delay(250); // Dot duration
      digitalWrite(ledPin, LOW);
      delay(250); // Gap between dots and dashes
    } else if (morseCode[i] == '-') {
      // Send a dash signal (long blink)
      digitalWrite(ledPin, HIGH);
      delay(750); // Dash duration
      digitalWrite(ledPin, LOW);
      delay(250); // Gap between dots and dashes
    } else if (morseCode[i] == ' ') {
      // Gap between letters
      delay(750);
    }
  }
  // Gap between words
  delay(1750);
}

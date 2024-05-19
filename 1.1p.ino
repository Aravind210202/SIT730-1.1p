// Define the pins
const int buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = LED_BUILTIN;      // the pin that the LED is attached to

// Define Morse code for each letter of the name "Aravind"
String morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Define the name
String myName = "Aravind";

void setup() {
  pinMode(ledPin, OUTPUT);     // initialize LED as an output
  pinMode(buttonPin, INPUT);   // initialize pushbutton as an input
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {  // check if the pushbutton is pressed
    blinkNameInMorseCode();  // blink the name in Morse code
    delay(1000); // debouncing delay
  }
}

void blinkNameInMorseCode() {
  for (int i = 0; i < myName.length(); i++) { // loop through each character of the name
    char letter = myName[i];
    int index = letter - 'A'; // convert character to Morse code index (assuming uppercase letters)
    
    if (letter >= 'a' && letter <= 'z') { // check for lowercase letters and convert to uppercase
      index = letter - 'a';
    }
    
    if (letter == ' ') { // if there is a space, wait longer between words
      delay(3000);
    } else {
      String code = morseCode[index]; // get Morse code for the letter
      for (int j = 0; j < code.length(); j++) { // loop through each symbol of the Morse code
        if (code[j] == '.') { // if dot, blink for short duration
          digitalWrite(ledPin, HIGH);
          delay(250); // dot duration
        } else if (code[j] == '-') { // if dash, blink for long duration
          digitalWrite(ledPin, HIGH);
          delay(750); // dash duration
        }
        digitalWrite(ledPin, LOW);
        delay(250); // delay between symbols
      }
      delay(750); // delay between letters
    }
  }
}

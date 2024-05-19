
const int buttonPin = 2;    
const int ledPin = LED_BUILTIN;     


String morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
String myName = "Aravind";

void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(buttonPin, INPUT);   
}

void loop() {
  if (digitalRead(buttonPin) == HIGH)
  {  
    blinkNameInMorseCode();  
    delay(1000); 
  }
}

void blinkNameInMorseCode() {
  for (int i = 0; i < myName.length(); i++) 
  { 
    char letter = myName[i];
    int index = letter - 'A'; 
    
    if (letter >= 'a' && letter <= 'z') 
    { 
      index = letter - 'a';
    }
    
    if (letter == ' ') { 
      delay(3000);
    } else {
      String code = morseCode[index]; 
      for (int j = 0; j < code.length(); j++) 
      { 
        if (code[j] == '.') 
        {
          digitalWrite(ledPin, HIGH);
          delay(250); 
        } else if (code[j] == '-') 
        { 
          digitalWrite(ledPin, HIGH);
          delay(750); 
        }
        digitalWrite(ledPin, LOW);
        delay(250);
      }
      delay(750); 
    }
  }
}

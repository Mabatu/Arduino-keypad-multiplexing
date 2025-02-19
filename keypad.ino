const int col1 = 4;
const int col2 = 5;
const int col3 = 6;
const int col4 = 7;

//shift register pins
const int dataPin = 8;
const int clockPin = 9;
const int latchPin = 10;

int currentButton = 0;
int previousButton = 0;

byte rowSelect[4] = { 0b0111, 0b1011, 0b1101, 0b1110 };

//function to check whick button colum is pressed
int readColumn() {
  for (int i = 7; i > 3; i--) {
    if (digitalRead(i) == LOW) {
      return i;
    }
  }
  return 0;
}

void setup() {
  pinMode(col1, INPUT_PULLUP);
  pinMode(col2, INPUT_PULLUP);
  pinMode(col3, INPUT_PULLUP);
  pinMode(col4, INPUT_PULLUP);

  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //iterate through keypad's rows
  for (int i = 0; i < 4; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rowSelect[i]);
    digitalWrite(latchPin, HIGH);
    int pressed = readColumn();
    currentButton = (pressed != 0) ? i * 4 + pressed - 3 : 0;
    if (currentButton != previousButton && pressed != 0) {
      Serial.print('S');
      Serial.print(i * 4 + pressed - 3);
      Serial.println(" pressed");
      previousButton = currentButton;
    }
  } 
}

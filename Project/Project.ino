//H-brigdes 2 on rc car pins control output to them.
// H1-pins for forward and reverse.
// H2-pins for left and right turning. 
//first pin put into array makes it the forward going pin

int H1Pins[] = {12,13};
int H2Pins[] = {2,3};

//for control of H bridges motor can go forward, reverse
//or coast. I have prototypes for quick refrence.
//basicaly spins motors in opposite directions/ than stops motor is coasting
void forward(int HPins[]);
void reverse(int HPins[]);
void coasting(int HPins[]);


void setup() {
for(int i = 0; i <2; i++){
  pinMode(H1Pins[i], OUTPUT);
  pinMode(H2Pins[i], OUTPUT);
}  

}  

void loop() {
  int delayT = 5000;
  forward(H1Pins);
  forward(H2Pins);
  delay(delayT);
  reverse(H2Pins);
  delay(delayT);
  coasting(H1Pins);
  delay(delayT);


}

void forward(int HPins[]){
  digitalWrite(HPins[0], HIGH);
  digitalWrite(HPins[1], LOW);
}
void reverse(int HPins[]){
  digitalWrite(HPins[0], LOW);
  digitalWrite(HPins[1], HIGH);
}

void coasting(int HPins[]){
  digitalWrite(HPins[0],LOW);
  digitalWrite(HPins[1],LOW);
}


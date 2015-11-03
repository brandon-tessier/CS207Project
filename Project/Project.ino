//H-brigdes 2 on rc car pins control output to them.
// H1-pins for forward and reverse.
// H2-pins for left and right turning. 
//first pin put into array makes it the forward going pin

int H1Pins[] = {12,13};
int H2Pins[] = {2,3};

//for sonic sensor
#define trig 10
#define echo 11

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
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
}  
bool first = true;
void loop() {
if(DistanceToObject(trig,echo) >60)
{
  first = true;
  forward(H1Pins);
}
else
  {
   if(first)
   {
    first = false;
    reverse(H1Pins);
    delay(500); 
   }
  
  coasting(H1Pins);
  }
  delay(200);
  coasting(H1Pins);  
  delay(500);
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

int DistanceToObject(int trigPin, int echoPin){
  long duration;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);
  return (duration / 58.2);
}

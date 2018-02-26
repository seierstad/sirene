#define LYDPINNE 5
#define AVTREKKERPINNE 8
#define LYS 10
#define M0RK 1000
#define KLIKKTID 1

int avtrekkerStatus = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(LYDPINNE, OUTPUT);
  pinMode(AVTREKKERPINNE, INPUT_PULLUP);
  avtrekkerStatus = digitalRead(AVTREKKERPINNE);
  Serial.println(avtrekkerStatus);
}


void ett_klikk(int pinne, int total_tid) {
 
  digitalWrite(pinne, HIGH);
  delayMicroseconds(total_tid);
  digitalWrite(pinne, LOW);
  delayMicroseconds(total_tid);
}

void piooom () {
  for (int madagaskarpingvinene = LYS; madagaskarpingvinene <= M0RK; madagaskarpingvinene += 5) {
    ett_klikk(LYDPINNE, madagaskarpingvinene);
  }
}

int avtrekker = LOW;

void sjekk_avtrekker() {
  int ny_status = digitalRead(AVTREKKERPINNE);
  Serial.println(ny_status);
  
  if(ny_status != avtrekkerStatus) {
    avtrekkerStatus = ny_status;
    
    if (ny_status == LOW) {
      avtrekker = HIGH;
    } else {
      avtrekker = LOW;
    }
  } else {
    avtrekker = LOW;
  }
}

void loop() {
  if (avtrekker == HIGH) {
    piooom();
  }
  sjekk_avtrekker();
}

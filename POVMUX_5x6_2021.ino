#include <TimerOne.h>

const int row[] = {6, 9, 5, 3,2};   //row pins
//const int row[] = {6, 9, 5, 3};   //row pins
const int col[] = {4,7,8,10,11,12};  //column pins
volatile byte c,r;
int del;

#define A {    \ 
  {0,0,1,0,0}, \
  {0,1,0,1,0}, \
  {1,0,0,0,1}, \
  {1,1,1,1,1}, \
  {1,0,0,0,1}  \
}
#define B {    \ 
  {1,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,1,1,1,0}  \
}
#define C {    \ 
  {0,1,1,1,1}, \
  {1,0,0,0,0}, \
  {1,0,0,0,0}, \
  {1,0,0,0,0}, \
  {0,1,1,1,1}  \
}
#define D {    \ 
  {1,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {1,1,1,1,0}  \
}

#define E {    \ 
  {1,1,1,1,1}, \
  {1,0,0,0,0}, \
  {1,1,1,1,1}, \
  {1,0,0,0,0}, \
  {1,1,1,1,1}  \
}
#define F {    \ 
  {1,1,1,1,1}, \
  {1,0,0,0,0}, \
  {1,1,1,1,1}, \
  {1,0,0,0,0}, \
  {1,0,0,0,0}  \
}

#define G {    \ 
  {1,1,1,1,1}, \
  {1,0,0,0,0}, \
  {1,0,1,1,1}, \
  {1,0,0,0,1}, \
  {1,1,1,1,1}  \
}
#define H {    \ 
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {1,1,1,1,1}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}  \
}
#define I {    \ 
  {1,1,1,1,1}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {1,1,1,1,1}  \
}
#define J {    \ 
  {1,1,1,1,1}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {1,1,0,0,0}  \
}
#define K {    \ 
  {1,0,0,1,0}, \
  {1,0,1,0,0}, \
  {1,1,1,0,0}, \
  {1,0,0,1,0}, \
  {1,0,0,0,1}  \
}
#define L {    \ 
  {1,0,0,0,0}, \
  {1,0,0,0,0}, \
  {1,0,0,0,0}, \
  {1,0,0,0,0}, \  
  {1,1,1,1,1}  \
}
#define M {    \ 
  {1,0,0,0,1}, \
  {1,1,0,1,1}, \
  {1,0,1,0,1}, \
  {1,0,0,0,1}, \  
  {1,0,0,0,1}  \
}  
#define N {    \ 
  {1,0,0,0,1}, \
  {1,1,0,0,1}, \
  {1,0,1,0,1}, \
  {1,0,0,1,1}, \
  {1,0,0,0,1}  \
}  
#define O {    \ 
  {0,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {0,1,1,1,0}  \
} 
#define P {    \ 
  {1,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,1,1,1,0}, \
  {1,0,0,0,0}, \
  {1,0,0,0,0}  \
}

#define R {    \ 
  {1,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,1,1,1,0}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}  \
}
#define S {    \ 
  {0,1,1,1,1}, \
  {1,0,0,0,0}, \
  {0,1,1,1,0}, \
  {0,0,0,0,1}, \  
  {1,1,1,1,0}  \
}
#define T {    \ 
  {1,1,1,1,1}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}  \
}
#define U {    \ 
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {0,1,1,1,0}  \
}
#define V {    \ 
  {1,0,0,0,1}, \
  {1,0,0,0,1}, \
  {0,1,0,1,0}, \
  {0,1,0,1,0}, \
  {0,0,1,0,0}  \
}


#define W {    \ 
  {1,0,1,0,1}, \
  {1,0,1,0,1}, \
  {1,0,1,0,1}, \
  {1,0,1,0,1}, \
  {0,1,0,1,0}  \
}
#define Y {    \ 
  {1,0,0,0,1}, \
  {0,1,0,1,0}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}, \
  {0,0,1,0,0}  \  
}
#define h {    \ 
  {0,1,0,1,0}, \
  {1,1,1,1,1}, \
  {1,1,1,1,1}, \
  {0,1,1,1,0}, \
  {0,0,1,0,0}  \
}
#define sp {   \ 
  {0,0,0,0,0}, \
  {0,0,0,0,0}, \
  {0,0,0,0,0}, \
  {0,0,0,0,0}, \
  {0,0,0,0,0}  \
}

byte pat[5][6] ={
  {0,1,1,1,0,1},
  {1,0,1,0,1,1},
  {1,1,0,1,1,0},
  {1,0,1,0,1,1},
  {0,1,1,1,0,1}
};
byte FhNh[4][5][5]={F,h,N,h};   //dims are [no. chars][char height][char width]

byte ARWYN[5][5][5]={A,R,W,Y,N};
byte SMELLS[6][5][5]={S,M,E,L,L,S};
byte JOHN[4][5][5]={J,O,H,N};
byte IS[2][5][5]={I,S};
byte Astr[1][5][5]={A};
byte MY[2][5][5]={M,Y};
byte HELLO[5][5][5]={H,E,L,L,O};
byte ELEPHANTS[9][5][5]={E,L,E,P,H,A,N,T,S};
byte SUPRDORY[8][5][5]={S,U,P,R,D,O,R,Y};
byte ROCKS[5][5][5]={R,O,C,K,S};
byte LOVELY[6][5][5]={L,O,V,E,L,Y};
byte THEBIRDS[8][5][5]={T,H,E,B,I,R,D,S};
byte THEFISH[7][5][5]={T,H,E,F,I,S,H};
byte VS[2][5][5]={V,S};


void setup()  { 
  for (int i=0; i <=4; i++){
  pinMode(row[i], OUTPUT);
  }
  for (int i=0; i <=5; i++){
  pinMode(col[i], OUTPUT);
  }
  del=70;
  Timer1.initialize(50);
  Timer1.attachInterrupt(refreshScreen);
//  Serial.begin(9600);

} 

void loop()  { 
  ripple(5,80);
  BIRDSvsFISH(del);
  wipe(30);
  scrollStrU(HELLO,5,del);
  sine(60,30);
  SuprdoryRocks(del);
  delay(del*2);
  wipe(30);
  sineUp(60,30);
}

void refreshScreen() {
  // turn old pixel off
  digitalWrite(row[r], LOW);
  digitalWrite(col[c], HIGH);
  // get next pixel
  c++;
  if (c>5){
    c=0;
  r++;
  }
  if (r>4){
    r=0;
  }
  // turn pixel on if == 1
  if (pat[r][c]==1)
  {                                 
    digitalWrite(row[r], HIGH);
    digitalWrite(col[c], LOW);
  }
}

void BIRDSvsFISH(int del){
  scrollStr(THEBIRDS,8,del);
  shiftPatLeft(1,del);
  delay(del);
  shiftPatRight(2,del);
  scrollStrR(VS,2,del);
  shiftPatRight(1,del);
  delay(del);
  scrollStr(THEFISH,7,del);
  shiftPatLeft(1,del);
  delay(del); 
}

void ArwynSmells(int del){
  scrollStr(ARWYN,5,del);
  shiftPatLeft(1,del);
  delay(del);
  shiftPatRight(2,del);
  scrollStrR(SMELLS,6,del);
  shiftPatRight(1,del);
  delay(del);
}

void SuprdoryRocks(int del){
  scrollStrU(SUPRDORY,8,del);
  //shiftPatUp(1,del);
  delay(del);
  shiftPatRight(6,del);
  scrollStrD(ROCKS,5,del);
  //shiftPatDown(1,del);
  delay(del);
}


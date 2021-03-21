void wipe(int del){
  for (int y = 0;y<5;y++){
    pat[y][0]=1;
  }
  delay(del);
  for(int x=1;x<6;x++){
    for (int y = 0;y<5;y++){
      pat[y][x]=1;
      pat[y][x-1]=0;
    }
  delay(del);
  }
  for (int y = 0;y<5;y++){
    pat[y][5]=0;
  }
  delay(del); 
  for (int y = 0;y<5;y++){
    pat[y][5]=1;
  }
  delay(del);
  for(int x=4;x>=0;x--){
    for (int y = 0;y<5;y++){
      pat[y][x]=1;
      pat[y][x+1]=0;
    }
    delay(del);
  }
  for (int y = 0;y<5;y++){
    pat[y][0]=0;
  }
  delay(del); 
}

void ripple(int n,int del){
  byte r1[5][6]={
  {0,0,0,0,0,0},
  {0,0,0,0,0,0},
  {0,0,1,1,0,0},
  {0,0,0,0,0,0},
  {0,0,0,0,0,0}
  };
  byte r2[5][6]={
  {0,0,0,0,0,0},
  {0,1,1,1,1,0},
  {0,1,0,0,1,0},
  {0,1,1,1,1,0},
  {0,0,0,0,0,0}
  };
  byte r3[5][6]={
  {1,1,1,1,1,1},
  {1,0,0,0,0,1},
  {1,0,0,0,0,1},
  {1,0,0,0,0,1},
  {1,1,1,1,1,1}
  };
  for (int i=0;i<n;i++){
    printPat(r1,del);
    printPat(r2,del);
    printPat(r3,del);
    clearPat(del);
  }
}


void sine(int ni, int del){
  for (int i=0;i<ni;i++){
    int y=round(mapF(sin(i/1.8),-1,1,0,4));
    shiftPatLeft(1,0);
    pat[y][5]=1;
    delay(del);
  }
}
void sineUp(int ni, int del){
  for (int i=0;i<ni;i++){
    int x=round(mapF(sin(i/1.8),-1,1,0,5));
    shiftPatUp(1,0);
    pat[4][x]=1;
    delay(del);
  }
}


float mapF(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void printChar(byte ch[5][5],int del){
  for (int y=0;y<5;y++){
    for (int x=0;x<5;x++){
      pat[y][x]=ch[y][x];
    }
  }
}
void printPat(byte ch[5][6],int del){
  for (int y=0;y<5;y++){
    for (int x=0;x<6;x++){
      pat[y][x]=ch[y][x];
    }
  }
  delay(del);
} 
void clearPat(int del){
  for (int y=0;y<5;y++){
    for (int x=0;x<6;x++){
      pat[y][x]=0;
    }
  }
  delay(del);
} 


void scrollStr(byte str[][5][5],int nchars,int del){
  byte ch[5][5];
  for (int i=0;i<nchars;i++){
    shiftPatLeft(1,del);
    for (int y=0;y<5;y++){
      for (int x=0;x<5;x++){
        ch[y][x]=str[i][y][x];
      }
    }
    scrollChar(&ch[0][0],5,del);
    delay(del*2);
  }
}

void scrollStrR(byte str[][5][5],int nchars,int del){
  byte ch[5][5];
  for (int i=0;i<nchars;i++){
    shiftPatRight(2,del);
    for (int y=0;y<5;y++){
      for (int x=0;x<5;x++){
        ch[y][x]=str[i][y][x];
      }
    }
    scrollCharR(&ch[0][0],5,del);
    delay(del*2);
  }
}
void scrollStrU(byte str[][5][5],int nchars,int del){
  byte ch[5][5];
  for (int i=0;i<nchars;i++){
    shiftPatUp(2,del);
    for (int y=0;y<5;y++){
      for (int x=0;x<5;x++){
        ch[y][x]=str[i][y][x];
      }
    }
    scrollCharU(&ch[0][0],5,del);
    delay(del*4);
  }
}
void scrollStrD(byte str[][5][5],int nchars,int del){
  byte ch[5][5];
  for (int i=0;i<nchars;i++){
    shiftPatDown(2,del);
    for (int y=0;y<5;y++){
      for (int x=0;x<5;x++){
        ch[y][x]=str[i][y][x];
      }
    }
    scrollCharD(&ch[0][0],5,del);
    delay(del*4);
  }
}

void scrollChar(byte *ch, int wid, int del){
  for(int x = 0;x<wid;x++){
    delay(del);
    shiftPatLeft(1,0);
    for(int y=0;y<5;y++){
      pat[y][5]=ch[y*wid+x];
    }
  }
}
void scrollCharR(byte *ch, int wid, int del){
  for(int x = wid-1;x>=0;x--){
    delay(del);
    shiftPatRight(1,0);
    for(int y=0;y<5;y++){
      pat[y][0]=ch[y*wid+x];
    }
  }
}
void scrollCharU(byte *ch, int wid, int del){
  for(int y = 0;y<5;y++){
    delay(del);
    shiftPatUp(1,0);
    for(int x=0;x<5;x++){
      pat[4][x]=ch[y*wid+x];
    }
  }
}
void scrollCharD(byte *ch, int wid, int del){
  for(int y = 0;y<5;y++){
    delay(del);
    shiftPatDown(1,0);
    for(int x=0;x<5;x++){
      pat[0][x]=ch[(4-y)*wid+x];
    }
  }
}

void shiftPatLeft(int n, int del){ //shift pattern n pix left
  for (int i=0;i<n;i++){
    delay(del);
    for(int x=0; x<5; x++){
      for(int y=0; y<5; y++){
        pat[y][x]=pat[y][x+1];
      }
    }
    for(int y=0; y<5; y++){
      pat[y][5]=0;
    }
  }
}
void shiftPatRight(int n, int del){ //shift pattern n pix right
  for (int i=0;i<n;i++){
    delay(del);
    for(int x=5; x>0; x--){
      for(int y=0; y<5; y++){
        pat[y][x]=pat[y][x-1];
      }
    }
    for(int y=0; y<5; y++){
      pat[y][0]=0;
    }
  }
}
void shiftPatDown(int n, int del){ //shift pattern n pix down
  for (int i=0;i<n;i++){
    delay(del);
    for(int y=4; y>0; y--){
      for(int x=0; x<6; x++){
        pat[y][x]=pat[y-1][x];
      }
    }
    for(int x=0; x<6; x++){
      pat[0][x]=0;
    }
  }
}
void shiftPatUp(int n, int del){ //shift pattern n pix up
  for (int i=0;i<n;i++){
    delay(del);
    for(int y=0; y<5; y++){
      for(int x=0; x<6; x++){
        pat[y][x]=pat[y+1][x];
      }
    }
    for(int x=0; x<6; x++){
      pat[4][x]=0;
    }
  }
}

void SerPrintPat(){  // print current patter to serial
  for(int y=0;y<5;y++){
    for(int x=0;x<5;x++){
      Serial.print(pat[y][x]);
    }
      Serial.println(pat[y][5]);
  }
  Serial.println();
}

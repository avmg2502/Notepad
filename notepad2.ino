#include <Arduboy2.h>
#include <EEPROM.h> 
Arduboy2 arduboy;
char *v=(char*)malloc(175*sizeof(char));
char *strings[]={"a","b","c","d","e","f","g","h","i",
"j","k","l","m","n","o","p","q","r","s","t","u","v","w",
"x","y","z"," ",".",",","?","!","A","B","C","D","E","F","G","H","I","J",
"K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y",
"Z","1","2","3","4","5","6","7","8","9","0","+","=","_","/",
"<",">","@","#","$","%","&","*","(",")","]",
"[","|","-","'","}","{",":",";","\n"}; 
int downbuffer, upbuffer,leftbuffer,rightbuffer,abuffer,bbuffer;
int x=0;
int y=0;
int u=0;
int cont=0;
int linha=1;
int i;
uint8_t value=26;
void setup() {
  arduboy.begin();
  arduboy.clear();
  /*for ( i = 0; i < 175; i++ ){
      v[i]=' ';
      EEPROM.update(i,26);
      if ((i+1)%22==0 and i!=0){
        v[i]='\n';
        EEPROM.update(i,90);
      }
    }*/
    for ( i = 0; i < 175; i++ ){
    value=EEPROM.read(i);
    arduboy.print(*strings[value]);
    }
    i=0;
}

void loop() {
  arduboy.setCursor(x, y);
  if (arduboy.pressed(DOWN_BUTTON)==true and downbuffer==0){
    if(u<=90){
    u+=1;
    cont+=1;
    downbuffer=1;
    arduboy.print(strings[u]);
    }
    if(u==90){
      arduboy.setCursor(x, y);
      u=0;
      downbuffer=1;
      arduboy.print(strings[u]);
      
    }
  }
  if(arduboy.notPressed(DOWN_BUTTON)==true){
    downbuffer=0;
  }
  if (arduboy.pressed(UP_BUTTON)==true and upbuffer==0){
    if (u>=0){
      u-=1;
      upbuffer=1;
      arduboy.print(strings[u]);
  
    }
   if(u==-1){
    arduboy.setCursor(x, y);
    u=89;
    upbuffer=1;
    arduboy.print(strings[u]);
   }
    cont+=1;
    
  }
  if(arduboy.notPressed(UP_BUTTON)==true){
    upbuffer=0;
  }
  if (arduboy.pressed(RIGHT_BUTTON)==true and rightbuffer==0){
    if (cont!=0){
      v[i] = (*strings[u]);
      EEPROM.update(i,u);
      cont=0;
    }
    
    i++;
    rightbuffer=1;
    x+=6;
  
  }
  if(arduboy.notPressed(RIGHT_BUTTON)==true){
    rightbuffer=0;
  }
  if (arduboy.pressed(LEFT_BUTTON)==true and leftbuffer==0){
    if (x==0){
      if (y>0){
        y-=8;
        x=126;
        linha=y/8+1;
        i=linha*22-1;
      }
    }
    x=x-6;
    i--;
    v[i]=' ';
    EEPROM.update(i,90);
    arduboy.setCursor(x, y);
    arduboy.print("  ");
    arduboy.setCursor(x, y);
    leftbuffer=1;
    
  }
  if(arduboy.notPressed(LEFT_BUTTON)==true){
    leftbuffer=0;
  }
  if (arduboy.pressed(A_BUTTON)==true and abuffer==0){
    if (cont!=0){
      v[i] = (*strings[u]);
      EEPROM.update(i,u);
      cont=0;
    }
    i=linha*22;
    abuffer=1;
    linha+=1;
    arduboy.print("\n");
    y=y+8;
    x=0;
  }
  if(arduboy.notPressed(A_BUTTON)==true){
    abuffer=0;
  }
  if (arduboy.pressed(B_BUTTON)==true and bbuffer==0){
    bbuffer=1;
    for ( i = 0; i < 175; i++ ){
      v[i]=' ';
      EEPROM.update(i,26);
      if ((i+1)%22==0 and i!=0){
        v[i]='\n';
        EEPROM.update(i,90);
      }
    }
    i=0;
    arduboy.clear();
    x=0;
    y=0;
    u=0;
    cont=0;
  
  }
  if(arduboy.notPressed(B_BUTTON)==true){
    bbuffer=0;
  }
  arduboy.display();
}

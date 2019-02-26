#include <stdio.h>
#include <string.h>
#include <conio.h>

#define boolean unsigned char
#define true 1
#define false 0

#define Undef "XXXXXXXXXX"
#define kalah2 "X111111111" //1 : player, 2 : CPU
#define menang2 "X222222222"
#define seri2 "X000000000"

typedef char state[11];

boolean menang(char *RState, int *countmenang){
  boolean betul = (((RState[1] == '2') && (RState[2] == '2') && (RState[3] == '2'))
                ||((RState[1] == '2') && (RState[4] == '2') && (RState[7] == '2'))
                ||((RState[1] == '2') && (RState[5] == '2') && (RState[9] == '2'))
                ||((RState[7] == '2') && (RState[8] == '2') && (RState[9] == '2'))
                ||((RState[3] == '2') && (RState[6] == '2') && (RState[9] == '2'))
                ||((RState[3] == '2') && (RState[5] == '2') && (RState[7] == '2'))
                ||((RState[2] == '2') && (RState[5] == '2') && (RState[8] == '2'))
                ||((RState[4] == '2') && (RState[5] == '2') && (RState[6] == '2')));
  if (betul){
  //  printf("%s selesai\n",RState);
    //strcpy(RState,menang2);
    *countmenang += 1;
  }
  return betul;
}

boolean kalah(char *RState, int *countkalah){
  boolean betul = (((RState[1] == '1') && (RState[2] == '1') && (RState[3] == '1'))
                ||((RState[1] == '1') && (RState[4] == '1') && (RState[7] == '1'))
                ||((RState[1] == '1') && (RState[5] == '1') && (RState[9] == '1'))
                ||((RState[7] == '1') && (RState[8] == '1') && (RState[9] == '1'))
                ||((RState[3] == '1') && (RState[6] == '1') && (RState[9] == '1'))
                ||((RState[3] == '1') && (RState[5] == '1') && (RState[7] == '1'))
                ||((RState[2] == '1') && (RState[5] == '1') && (RState[8] == '1'))
                ||((RState[4] == '1') && (RState[5] == '1') && (RState[6] == '1')));
  if (betul){
  //  printf("%s selesai\n",RState);
  //  strcpy(RState,kalah2);
    *countkalah +=1;
    printf("%s--",RState);
  }
  return betul;
}

boolean seri(char *RState,int *countseri){
  boolean betul = ((RState[1] != '0') && (RState[2] != '0') && (RState[3] != '0')
                && (RState[4] != '0') && (RState[5] != '0') && (RState[6] != '0')
                && (RState[7] != '0') && (RState[8] != '0') && (RState[9] != '0'));

  if (betul){
  //  printf("%s selesai\n",RState);
  //  strcpy(RState,seri2);
    *countseri += 1;
  }
  return betul;
}

boolean win(char *RState, char turn){
  boolean betul = false;
  int idx;
  if ((RState[1] == turn) && (RState[2] == turn) && (RState[3] == '0')){
    betul = true;
    idx = 3;
  }
  else if ((RState[1] == turn) && (RState[2] == '0') && (RState[3] == turn)){
    betul = true;
    idx = 2;
  }
  else if ((RState[1] == '0') && (RState[2] == turn) && (RState[3] == turn)){
    betul = true;
    idx = 1;
  }
  else if ((RState[1] == turn) && (RState[4] == turn) && (RState[7] == '0')){
    betul = true;
    idx = 7;
  }
  else if ((RState[1] == turn) && (RState[4] == '0') && (RState[7] == turn)){
    betul = true;
    idx = 4;
  }
  else if ((RState[1] == '0') && (RState[4] == turn) && (RState[7] == turn)){
    betul = true;
    idx = 1;
  }
  else if ((RState[1] == turn) && (RState[5] == turn) && (RState[9] == '0')){
    betul = true;
    idx = 9;
  }
  else if ((RState[1] == turn) && (RState[5] == '0') && (RState[9] == turn)){
    betul = true;
    idx = 5;
  }
  else if ((RState[1] == '0') && (RState[5] == turn) && (RState[9] == turn)){
    betul = true;
    idx = 1;
  }
  else if ((RState[7] == turn) && (RState[8] == turn) && (RState[9] == '0')){
    betul = true;
    idx = 9;
  }
  else if ((RState[7] == turn) && (RState[8] == '0') && (RState[9] == turn)){
    betul = true;
    idx = 8;
  }
  else if ((RState[7] == '0') && (RState[8] == turn) && (RState[9] == turn)){
    betul = true;
    idx = 7;
  }
  else if ((RState[3] == turn) && (RState[6] == turn) && (RState[9] == '0')){
    betul = true;
    idx = 9;
  }
  else if ((RState[3] == turn) && (RState[6] == '0') && (RState[9] == turn)){
    betul = true;
    idx = 6;
  }
  else if ((RState[3] == '0') && (RState[6] == turn) && (RState[9] == turn)){
    betul = true;
    idx = 3;
  }
  else if ((RState[3] == turn) && (RState[5] == turn) && (RState[7] == '0')){
    betul = true;
    idx = 7;
  }
  else if ((RState[3] == turn) && (RState[5] == '0') && (RState[7] == turn)){
    betul = true;
    idx = 5;
  }
  else if ((RState[3] == '0') && (RState[5] == turn) && (RState[7] == turn)){
    betul = true;
    idx = 3;
  }
  else if ((RState[2] == turn) && (RState[5] == turn) && (RState[8] == '0')){
    betul = true;
    idx = 8;
  }
  else if ((RState[2] == turn) && (RState[5] == '0') && (RState[8] == turn)){
    betul = true;
    idx = 5;
  }
  else if ((RState[2] == '0') && (RState[5] == turn) && (RState[8] == turn)){
    betul = true;
    idx = 2;
  }
  else if ((RState[4] == turn) && (RState[5] == turn) && (RState[6] == '0')){
    betul = true;
    idx = 6;
  }
  else if ((RState[4] == turn) && (RState[5] == '0') && (RState[6] == turn)){
    betul = true;
    idx = 5;
  }
  else if ((RState[4] == '0') && (RState[5] == turn) && (RState[6] == turn)){
    betul = true;
    idx = 4;
  }
  if (betul){
    RState[idx] = '2';
  }
  if (betul)
    printf("win");
  return betul;
}

boolean garpu(char *RState, char turn,char oppose){
  boolean betul = false;
  if (RState[5] == turn){
    if (RState[1] == turn){
      if (RState[2] == oppose){
        if (RState[7] == '0'){
          RState[7] = '2';
          betul = true;
        }
      }
      else if (RState[4] == oppose){
        if (RState[3] == '0'){
          RState[3] = '2';
          betul = true;
        }
      }
    }
    else if (RState[3] == turn){
      if (RState[2] == oppose){
        if (RState[9] == '0'){
          RState[9] = '2';
          betul = true;
        }
      }
      else if (RState[6] == oppose){
        if (RState[1] == '0'){
          RState[1] = '2';
          betul = true;
        }
      }
    }
    else if (RState[7] == turn){
      if (RState[4] == oppose){
        if (RState[9] == '0'){
          RState[9] = '2';
          betul = true;
        }
      }
      else if (RState[8] == oppose){
        if (RState[1] == '0'){
          RState[1] = '2';
          betul = true;
        }
      }
    }
    else if (RState[9] == turn){
      if (RState[6] == oppose){
        if (RState[7] == '0'){
          RState[7] = '2';
          betul = true;
        }
      }
      else if (RState[8] == oppose){
        if (RState[3] == '0'){
          RState[3] = '2';
          betul = true;
        }
      }
    }
  }
  if (betul)
    printf("fork");
  return betul;
}

boolean oppositeCorner(char *RState){
  boolean betul = false;
  if ((RState[1] == '1') && (RState[9] == '0')) {
    RState[9] = '2';
    betul = true;
  }
  else if ((RState[1] == '0') && (RState[9] == '1')){
    RState[1] = '2';
    betul = true;
  }
  else if ((RState[3] == '1') && (RState[7] == '0')){
    RState[7] = '2';
    betul = true;
  }
  else if ((RState[3] == '0') && (RState[7] == '1')){
    RState[3] = '2';
    betul = true;
  }
  if (betul)
    printf("oppCorn");
  return betul;
}

boolean emptyCorner(char *RState){
  boolean betul = false;
  if (RState[1] == '0'){
    RState[1] = '2';
    betul = true;
  }
  else if (RState[3] == '0'){
    RState[3] = '2';
    betul = true;
  }
  else if (RState[7] == '0'){
    RState[7] = '2';
    betul = true;
  }
  else if (RState[9] == '0'){
    RState[9] = '2';
    betul = true;
  }
  if (betul)
    printf("%s Corn",RState);
  return betul;
}

boolean emptySide(char *RState){
  boolean betul = false;
  if (RState[2] == '0'){
    RState[2] = '2';
    betul = true;
  }
  else if (RState[6] == '0'){
    RState[6] = '2';
    betul = true;
  }
  else if (RState[4] == '0'){
    RState[4] = '2';
    betul = true;
  }
  else if (RState[8] == '0'){
    RState[8] = '2';
    betul = true;
  }
  if (betul)
    printf("Side");
  return betul;
}


int main(){
  char CState[11] = "X200010000";
  char RState[11]; //Result State
  char LState[10000][11][11]; //List of State beserta hasil fungsi transisi
  int Neff = 1;
  strcpy(LState[Neff][0],CState);
  //printf("%s\n",LState[1][0]);
  int p = 1;
  int countmenang = 0;
  int countkalah = 0;
  int countseri = 0;
  while (p <= Neff){
    for (int i = 1; i <= 9; i++){
      strcpy(RState,LState[p][0]);
      //printf("%s ",RState);
      if (menang(RState, &countmenang)){}
      else if (kalah(RState, &countkalah)){}
      else if (seri(RState, &countseri)){}
      else{
        if (RState[i] == '0'){
          RState[i] = '1';
          if (win(RState,'2')){}
          else if (win(RState,'1')){}
          else if (garpu(RState,'2','1')){}
          else if (garpu(RState,'1','2')){}
          else if (oppositeCorner(RState)){}
          else if (emptyCorner(RState)){}
          else if (emptySide(RState)){}
        }
      }
      strcpy(LState[p][i],RState);
  //    printf("%s\n",LState[p][i]);
      boolean found = (strcmp(RState,LState[1][0]) == 0);
      int k =1;
      while ((!found) && (k < Neff)){
        k++;
        //printf("%s != %s\n",RState,LState[k][0]);
        found = (strcmp(RState,LState[k][0]) == 0);
        //printf("%u abcd\n",found);
      }
      if (!found){
        Neff++;
        strcpy(LState[Neff][0],RState);
      }
  /*    for (int j = 1;j <= Neff; j++){
        printf("%s ",LState[j][0]);
      }
      printf("\n");
      getch();*/
    }
    p++;
  }

//  boolean found = (strcmp(selesai,LState[1][0]) == 0);
  //int k =1;
//  int count =0;
  /*while  (k <= Neff){

    //printf("%s != %s\n",RState,LState[k][0]);
    found = (strcmp(selesai,LState[k][0]) == 0);
    if (found)
      printf("%s\n",LState[k][0]);
    //printf("%u abcd\n",found);
    k++;
  }
  printf("%d\n",count);*/

  for (int i =1; i <= Neff; i++){   //mengeluarkan hasil list
    boolean sama = true;
    for (int j =0; j <= 9; j++){
      if (!(strcmp(LState[i][0],LState [i][j]) == 0)){
        sama = false;
        break;
      }

    }
    if (sama)
      printf("%s ",LState[i][0]);
    //printf("\n");
  }
  printf("%d\n",Neff);
  printf("%d %d %d\n",countmenang, countkalah,countseri);
}

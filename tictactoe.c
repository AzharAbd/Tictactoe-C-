#include <stdio.h>
#include <string.h>

#define boolean unsigned char
#define true 1
#define false 0

#define PlayerAwal "200010000" //state awal jika player jalan duluan
#define CPUAwal "000020000" //state awal jika CPU jalan duluan

void cetakState(char *State)
//I.S State terdefinisi sembarang
//F.S mencetak state ke layar dengan ketentuan 0 = - , 1 = X, 2 = O
{
  for (int i =1; i <= 3; i++){
    for (int j = 3*(i-1) + 1; j <= 3*i; j++){
      if (State[j-1] == '0')
        printf("- ");
      if (State[j-1] == '1')
        printf("X ");
      if (State[j-1] == '2')
        printf("O ");
    }
    printf("\n");
  }
}

boolean win(char *RState)
//Mengembalikkan true jika dianggap menang
//Mengembalikkan false jika dianggap belum menang
//Jika true maka akan mencetak state terakhir
{
  boolean betul = (((RState[0] == '1') && (RState[1] == '1') && (RState[2] == '1'))
                ||((RState[0] == '1') && (RState[3] == '1') && (RState[6] == '1'))
                ||((RState[0] == '1') && (RState[4] == '1') && (RState[8] == '1'))
                ||((RState[6] == '1') && (RState[7] == '1') && (RState[8] == '1'))
                ||((RState[2] == '1') && (RState[5] == '1') && (RState[8] == '1'))
                ||((RState[2] == '1') && (RState[4] == '1') && (RState[6] == '1'))
                ||((RState[1] == '1') && (RState[4] == '1') && (RState[7] == '1'))
                ||((RState[3] == '1') && (RState[4] == '1') && (RState[5] == '1')));
  if (betul){
    cetakState(RState);
    printf("menang\n");
  }
  return betul;
}

boolean lose(char *RState)
//Mengembalikkan true jika dianggap menang
//Mengembalikkan false jika dianggap belum menang
//Jika true maka akan mencetak state terakhir
{
  boolean betul = (((RState[0] == '2') && (RState[1] == '2') && (RState[2] == '2'))
                ||((RState[0] == '2') && (RState[3] == '2') && (RState[6] == '2'))
                ||((RState[0] == '2') && (RState[4] == '2') && (RState[8] == '2'))
                ||((RState[6] == '2') && (RState[7] == '2') && (RState[8] == '2'))
                ||((RState[2] == '2') && (RState[5] == '2') && (RState[8] == '2'))
                ||((RState[2] == '2') && (RState[4] == '2') && (RState[6] == '2'))
                ||((RState[1] == '2') && (RState[4] == '2') && (RState[7] == '2'))
                ||((RState[3] == '2') && (RState[4] == '2') && (RState[5] == '2')));
  if (betul){
    cetakState(RState);
    printf("kalah\n");
  }
  return betul;
}

boolean draw(char *RState)
//Mengembalikkan true jika permainan dianggap seri
//Mengembalikkan false jika permainan tidak seri
//Jika true maka akan mencetak state terakhir
{
  boolean betul = ((RState[0] != '0') && (RState[1] != '0') && (RState[2] != '0')
                && (RState[3] != '0') && (RState[4] != '0') && (RState[5] != '0')
                && (RState[6] != '0') && (RState[7] != '0') && (RState[8] != '0'));
  if (betul){
    cetakState(RState);
    printf("seri\n");
  }
  return betul;
}

void cetakPassedState(char *State,int count)
//I.S State terdefinisi sembarang
//F.S mencetak state ke layar
{
  for (int i = 1; i <= count; i++){
    printf("%s\n",State);
  }
}

int main(){
  char ListOfStateP[65][11][10]; //matriks of char[10] yang berukuran 65x11 untuk menyimpan list state jika player bermain duluan
  char ListOfStateC[128][11][10]; //matriks of char[10] yang berukuran 128x11 untuk menyimpan list state jika CPU bermain duluan
  char CurrentState[10] ="000000000"; //menyimpan state sekarang, 000000000 adalah state awal
  char PassedState [10][10]; //array of char[10] yang berukuran 10 untuk menyimpan state-state yang sudah dilalui
  boolean menang = false; //variabel untuk menentukan jika permainan tictactoe dimenangkan oleh player
  boolean seri = false; //variabel untuk menentukan jika hasil permainan adalah seri
  boolean kalah = false; //variabel untuk menentukan jika permainan tictactoe dimenangkan oleh CPU
  boolean UdahanMain = false; //variabel untuk menentukan apakah user ingin berhenti bermain atau tidak
  int countState = 0; //variabel untuk menghitung banyaknya state yang dilalui
  int step; //variabel untuk menyimpan langkah User
  int pilihan; //variabel untuk menyimpan pilihan CPU/Player duluan yang jalan
  int idx; //variabel untuk menyimpan idx ListOfState mana yang sama dengan CurrentState
  FILE * pita; //variabel untuk menyimpan isi file

  pita = fopen("ListOfStateP.txt","r");     //Mengisi Array ListOfStateP
  for (int i =1; i <= 62; i++ ){            //dengan list state jika player main duluan
    for (int j =0; j <= 9; j++){
      fscanf(pita,"%s",&ListOfStateP[i][j]);
    }
  }
  fclose(pita);

  pita = fopen("ListOfStateC.txt","r");     //Mengisi Array ListOfStateC
  for (int i =1; i <= 126; i++ ){           //dengan list state jika CPU main duluan
    for (int j =0; j <= 9; j++){
      fscanf(pita,"%s",&ListOfStateC[i][j]);
    }
  }
  fclose(pita);

  while (!UdahanMain) {
    printf("1. Player duluan\n"); //Memberikan opsi kepada user
    printf("2. CPU duluan\n");
    printf("3. Selesai\n");
    printf("Masukkan pilihan (1/2/3) : ");
    scanf("%d",&pilihan); //User memasukkan pilihan

    countState = 0; //Menginisiasi jumlah state yang dilalui

    if (pilihan == 3) {
      UdahanMain = true;
    }
    else if (pilihan == 1) {
      strcpy(CurrentState,PlayerAwal); //Mengisi CurrentState dengan state awal jika player duluan
      menang = false;  //Menginisiasi semua kondisi dengan false
      seri = false;
      kalah = false;;
      while ((!menang) && (!seri) && (!kalah)) {
        countState++;                                //Menambah jumlah state yang telah dilalui
        strcpy(PassedState[countState],CurrentState);//Mendaftar state apa saja yang sudah dilalui
        cetakState(CurrentState);
        printf("Masukkan langkah selanjutnya : ");
        scanf("%d",&step); //User memasukkan langkah yang diinginkan
        for (int i =1; i <= 62; i++){
          if (strcmp(CurrentState,ListOfStateP[i][0]) == 0){  //Mencari CurrentState di ListOfState
            idx = i; //idx adalah indeks ditemukannya CurrentState
            break;
          }
        }
        strcpy(CurrentState,ListOfStateP[idx][step]); //Mengupdate CurrentState berdasarkan kepada ListOfState
        menang = win(CurrentState); //Mengecek apakah state tersebut menang
        seri = draw(CurrentState); //Mengecek apakah state tersebut seri
        kalah = lose(CurrentState); //Mengecek apakah state tersebut kalah
      }
      countState++; //Menambah jumlah state yg dilalui (untuk state final)
      strcpy(PassedState[countState],CurrentState); //Mengisi PassedState dengan kondisi final
      for (int i = 1; i <= countState; i++){
        printf("%s\n",PassedState[i]); //Mencetak semua state yang telah dilalui
      }
    }
    else if (pilihan == 2) {
      strcpy(CurrentState,CPUAwal); //Mengisi CurrentState dengan state awal jika player duluan
      menang = false;  //Menginisiasi semua kondisi dengan false
      seri = false;
      kalah = false;;
      while ((!menang) && (!seri) && (!kalah)) {
        countState++;                                //Menambah jumlah state yang telah dilalui
        strcpy(PassedState[countState],CurrentState);//Mendaftar state apa saja yang sudah dilalui
        cetakState(CurrentState);
        printf("Masukkan langkah selanjutnya : ");
        scanf("%d",&step); //User memasukkan langkah yang diinginkan
        for (int i =1; i <= 126; i++){
          if (strcmp(CurrentState,ListOfStateC[i][0]) == 0){  //Mencari CurrentState di ListOfState
            idx = i; //idx adalah indeks ditemukannya CurrentState
            break;
          }
        }
        strcpy(CurrentState,ListOfStateC[idx][step]); //Mengupdate CurrentState berdasarkan kepada ListOfState
        menang = win(CurrentState); //Mengecek apakah state tersebut menang
        seri = draw(CurrentState); //Mengecek apakah state tersebut seri
        kalah = lose(CurrentState); //Mengecek apakah state tersebut kalah
      }
      countState++; //Menambah jumlah state yg dilalui (untuk state final)
      strcpy(PassedState[countState],CurrentState); //Mengisi PassedState dengan kondisi final
      for (int i = 1; i <= countState; i++){
        printf("%s\n",PassedState[i]); //Mencetak semua state yang telah dilalui
      }
    }
  }
}

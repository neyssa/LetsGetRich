#include "boolean.h"
#include <stdio.h>

#define Nil 0

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string.h>

#define MARK '.'

typedef struct {
    char Name[20][10];
    int CountName;
} ListName;
extern char CC[10];
extern boolean EOP;
extern ListName LN;

typedef struct {
    char Name[10][10];
    char Score[10][10];
    int Countname;
} ListScore;

void StartRead(char FileName[30]);
/*I.S. : CC, sebuah Nama dalam file  */
/*F.S. : End of Process = true*/
/*CC adalah Nama pertama di dalam file*/

void StartWrite(char FileName[30]);
/*I.S. : sembarang */
/*F.S. : File eksternal siap untuk ditulis*/

void NextName();
/*I.S. : CC adalah kata yang diakuisisi*/
/*F.S. : CC mungkin mark*/

boolean IsKataSama(char Name1[10], char Name2[10]);
/* Mengembalikan true jika Name1 sama dengan Name2; dua kata dikatakan sama
CountNamenya sama dan huruf yang menyusunnya sama */

void WriteFile(char FileName[30], ListName LN);
/*I.S. : sembarang*/
/*F.S. : Menulis kembali ListName dalam file eksternal */


boolean IsNameValid(char Name[10]);
/*Mengembalikan true jika Panjang Nama >= 3 karakter */

boolean IsFileEmpty(ListName LN);
/*Mengembalikan true jika File Eksternal dengan ListName LN kosong */

boolean IsTerdaftar(char Name[10], ListName LN);
/*Mengembalikan true jika Name ada di ListName, dan false jika tidak*/


void SalinFile(char FileName[30], ListName *LN);
/*I.S. : Sembarang */
/*F.S. : LN merupakan ListName asil copy dari file eksternal */


#endif

typedef struct{
	boolean Iya;
	int count;
} Jail;

typedef struct{
	char Nama[20];
	int Lokasi;
	int pnygedung[21];
	long int JmlAwal;
	long int JmlAset;
	Jail Penjara;
	int cnt;
} Pemain;

typedef struct {
    Pemain T[5];
    int Head;
    int Tail;
    int MaxEl;
} Queue;

typedef struct{
	int U1;
	int U2;
} Rupiah;

typedef struct{
	char ITB[21][20];
	long int Price[21];
	int Kepunyaan[21];
	char Kompleks[21];
} Bangunan;

void Boardpermainan (Queue Q, int l);
int NbElmt(Queue Q);
boolean IsEmpty (Queue Q);
boolean IsFull (Queue Q);
void CreateEmpty (Queue *Q, int Max);
void DeAlokasi (Queue *Q);
void Add (Queue *Q, Pemain X);
void Del (Queue *Q, Pemain *X);
void PengisianBangunan (Bangunan *B);
boolean EndGame(Queue Q, Bangunan B);
void CreateQueuePemain (Queue *Q, int Maks);
void ChangeTurn (Queue *Q);
void CreateKondisiAwal(Queue *Q, char Name[]);
void MajuLangkah(Queue *Q, int N);
Rupiah KonversiUang(Queue Q);
Rupiah KonversiAset(Queue Q);
void PrintJumlahUang(Queue Q);
void PrintBiayaGedung(int i);
void PrintDadu(int *N, boolean *Same);
void PrintKoin(int *N);
boolean LwtStart(Queue Q, int tmp);
boolean IsKesempatan(Queue Q);
boolean IsUndian(Queue Q);
boolean IsPenjara(Queue Q);
boolean IsBusITB(Queue Q);
boolean IsStart(Queue Q);
char *Gedung(Queue Q, Bangunan B);
int KonversiTempat(char tempat[], Bangunan B);
long int Harga(Queue Q, Bangunan B);
long int HargaAset(Queue Q, Bangunan B);
char *Pemilik(Queue Q, Bangunan B, char tempat[], int l);
boolean LetakTidakSama(Queue Q, Bangunan B, int l);
void AddPemilik(Queue *Q, Bangunan *B, int l);
void DelPemilik(Queue *Q, Bangunan *B,char tempat[]);
void TambahUang(Queue *Q, long int X);
void KurangUang(Queue *Q, long int X);
void TambahAset(Queue *Q, long int X);
void KurangAset(Queue *Q, long int X);
void TambahUangLwn(Queue *Q, long int X, Bangunan B, int l);
void TambahAsetLwn(Queue *Q, int i, long int X);
void KurangAsetLwn(Queue *Q, int i, long int X);
void PrintKoin(int *K);
void SwapTempat(Queue *Q, Bangunan *B, char j[], char k[], int l);
void LewatStart(Queue *Q);
void Start(Queue Q);
boolean CekGedung(char tempat[]);
void Undian(Queue *Q);
void Penjara(Queue *Q, int *j, boolean *Same);
void Umum (Queue *Q, Bangunan *B, int l);
void BusITB(Queue *Q, Bangunan *B, int *j,int l);
void Kesempatan (Queue *Q, Bangunan *B, int *j, int l, boolean *Same);

#include "GGR.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

char jwbn[6];
char T1[21];
char T2[21];
char T3[21];
char T4[21];
int posisi1, posisi2, posisi3, posisi4;

char CC[10];
boolean EOP;
ListName LN;
static FILE *fp;

void StartRead(char FileName[30]){
    fp=fopen(FileName, "r");
    NextName();
}
void StartWrite(char FileName[30]){
    fp=fopen(FileName, "w");
}
void NextName(){
    int i = fgets(CC,10,fp);
    EOP=(i==NULL);
    if (EOP) {
        fclose(fp);
    }
}
boolean IsNameValid(char Name[10]){
    return(strlen(Name)>=3);
}
void SalinFile(char FileName[30], ListName *LN){
    /*Kamus Lokal*/
    int i, j;
    /*Algoritma*/
    StartRead(FileName);
    i=0;
    while (!EOP) {
        i++;
        for (j=0; j<strlen(CC); j++){
            (*LN).Name[i][j] = CC[j];
        };
        (*LN).CountName=i;
        strtok((*LN).Name[i], "\n");
        NextName();
    }
}
boolean IsFileEmpty(ListName LN){
    return(LN.CountName==0);
}
void WriteFile(char FileName[30], ListName LN){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    StartWrite(FileName);
    for (i=1; i<=LN.CountName; i++){
        strcat(LN.Name[i], "\n");
        fprintf(fp, LN.Name[i]);
    };
    fclose(fp);
}
boolean IsKataSama(char Name1[10], char Name2[10])
{
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    if (strlen(Name1)==strlen(Name2)) {
        i=0;
        while ((i<strlen(Name1)) && (Name1[i]==Name2[i])) {
            i++;
        }
        return(Name1[i]==Name2[i]);
    } else {
        return(False);
    }
}
boolean IsTerdaftar(char Name[10], ListName LN)
/*Mengembalikan true jika Nama ada di ListName, dan false jika tidak*/
{
    /*Kamus lokal*/
    boolean found;
    int i;
    /*Algoritma*/
    found = False;
    i=1;
    while ((i<=LN.CountName) && (!found)) {
        if (IsKataSama(Name, LN.Name[i])) {
            found=True;
        } else {
            i++;
        }
    }
    return(found);
}	
void DaftarPemain(char Name[10], ListName LN)
/*I.S. : Nama terdefinisi*/
/*F.S. : Menampilkan semua nama dalam LN yang bukan Nama*/
{
    /*Kamus lokal*/
    int i;
    /*Algoritma*/
    for (i=1; i<=LN.CountName; i++){
        if (strcmp(LN.Name[i], Name)) {
            printf("%s\n", LN.Name[i]);
        }
    }
}
void Boardpermainan (Queue Q, int l){
	 int jml;
	 int m;
	 m=l;
	 jml=Q.Tail;
    int i, x;              
        for (x=1;x<21;x++){
            T1[x] = ' '; T2[x] = ' '; T3[x] = ' '; T4[x] = ' ';
        }
		if (l==1){
			posisi1=Q.T[Q.Head].Lokasi;
		}
		if (l==2){
			posisi2=Q.T[Q.Head].Lokasi;
		}
		if (l==3){
			posisi3=Q.T[Q.Head].Lokasi;
		}
		if (l==4){
			posisi4=Q.T[Q.Head].Lokasi;
		}
        if (jml == 1){
            T1[posisi1] = '1'; //posisi ganti dengan posisi pemain di queue
        } 
		else if (jml == 2){
            T1[posisi1] = '1';
            T2[posisi2] = '2';                 
        } 
		else if (jml == 3){
			T1[posisi1] = '1';
			T2[posisi2] = '2'; 
			T3[posisi3] = '3';             
		} 
		else{
			T1[posisi1] = '1';
			T2[posisi2] = '2';			
			T3[posisi3] = '3';
			T4[posisi4] = '4';                 
		}
        i=1;
         for (i=1; i<=15; i++)
         {
			 system("cls");
          printf("*******************************************************************************\n" );
          printf("*   UNDIAN   * AULA_BARAT * AULA_TIMUR * KESEMPATAN *  K_BARRACK *   BUS_ITB  *\n" );
          printf("*            *            *            *            *            *            *\n" );
          printf("*    %c%c%c%c    *    %c%c%c%c    *    %c%c%c%c    *    %c%c%c%c    *    %c%c%c%c    *     %c%c%c%c   *\n", T1[11], T2[11],T3[11],T4[11], T1[12],T2[12],T3[12],T4[12], T1[13],T2[13],T3[13],T4[13], T1[14],T2[14],T3[14],T4[14], T1[15],T2[15],T3[15],T4[15], T1[16],T2[16],T3[16],T4[16]);
          printf("*            *            *            *            *            *            *\n" );
          printf("*******************************************************************************\n" );
          printf("* GKU_TIMUR  *                                                   * KESEMPATAN *\n" );
          printf("*            *                                                   *            *\n" );
          printf("*    %c%c%c%c    *                                                   *     %c%c%c%c   *\n", T1[10],T2[10],T3[10],T4[10], T1[17],T2[17],T3[17],T4[17] );
          printf("*            *                                                   *            *\n" );
          printf("**************                                                   **************\n" );
          printf("* GKU_BARAT  *                                                   *   K_BORJU  *\n" );
          printf("*            *                                                   *            *\n" );
          printf("*    %c%c%c%c    *                                                   *     %c%c%c%c   *\n", T1[9],T2[9],T3[9],T4[9], T1[18], T2[18], T3[18], T4[18]);
          printf("*            *                                                   *            *\n" );
          printf("**************                                                   **************\n" );
          printf("* KESEMPATAN *                                                   * LABTEK_VIII*\n" );
          printf("*    %c%c%c%c    *                                                   *     %c%c%c%c   *\n", T1[8],T2[8],T3[8],T4[8], T1[19], T2[19], T3[19], T4[19] );
          printf("*            *                                                   *            *\n" );
          printf("*            *                                                   *            *\n" );
          printf("**************                                                   **************\n" );
          printf("* K_BENGKOK  *                                                   *  LABTEK_V  *\n" );
          printf("*            *                                                   *            *\n" );
          printf("*    %c%c%c%c    *                                                   *     %c%c%c%c   *\n", T1[7],T2[7],T3[7],T4[7], T1[20], T2[20], T3[20], T4[20] );
          printf("*            *                                                   *            *\n" );
          printf("*******************************************************************************\n" );
          printf("*  PENJARA   *   TELKOM   *    TVST    *  COMLABS   *  OKTAGON   *   START    *\n" );
          printf("*            *            *            *            *            *            *\n" );
          printf("*    %c%c%c%c    *     %c%c%c%c   *     %c%c%c%c   *    %c%c%c%c    *     %c%c%c%c   *     %c%c%c%c   *\n", T1[6],T2[6],T3[6],T4[6], T1[5],T2[5],T3[5],T4[5], T1[4],T2[4],T3[4],T4[4], T1[3],T2[3],T3[3],T4[3], T1[2],T2[2],T3[2],T4[2], T1[1], T2[1], T3[1], T4[1]);
          printf("*            *            *            *            *            *            *\n" );
          printf("*******************************************************************************\n" );
          }
		  printf("%d %d %d %d\n", posisi1, posisi2, posisi3, posisi4);
}

int NbElmt(Queue Q){
	return (Q.Tail-Q.Head+1);
}
boolean IsEmpty (Queue Q){
    return((Q.Head==Nil) && (Q.Tail==Nil));
}
boolean IsFull (Queue Q){
    return(Q.Tail==Q.MaxEl);
}
void CreateEmpty (Queue *Q, int Max){
    (*Q).Head=Nil;
    (*Q).Tail=Nil;
    (*Q).MaxEl=Max;
}
void Add (Queue *Q, Pemain X){
	int i;
    if (IsEmpty(*Q)){
        (*Q).Head=1;
        (*Q).Tail=1;
    }
    strcpy((*Q).T[(*Q).Tail].Nama,X.Nama);
	(*Q).T[(*Q).Tail].Lokasi=X.Lokasi;
	for (i=1;i<=X.cnt;i++){
		(*Q).T[(*Q).Tail].pnygedung[i]=X.pnygedung[i];
	}
    (*Q).T[(*Q).Tail].JmlAwal=X.JmlAwal;
	(*Q).T[(*Q).Tail].JmlAset=X.JmlAset;
	(*Q).T[(*Q).Tail].cnt=X.cnt;
	(*Q).T[(*Q).Tail].Penjara.Iya=X.Penjara.Iya;
	(*Q).T[(*Q).Tail].Penjara.count=X.Penjara.count;
}
void Del (Queue *Q, Pemain *X){
    int i,j;
    if (!IsEmpty(*Q)){
		strcpy((*X).Nama,(*Q).T[(*Q).Head].Nama);
        (*X).Lokasi=(*Q).T[(*Q).Head].Lokasi;
		(*X).JmlAwal=(*Q).T[(*Q).Head].JmlAwal;
		(*X).JmlAset=(*Q).T[(*Q).Head].JmlAset;
		(*X).cnt=(*Q).T[(*Q).Head].cnt;
		(*X).Penjara.Iya=(*Q).T[(*Q).Head].Penjara.Iya;
		(*X).Penjara.count=(*Q).T[(*Q).Head].Penjara.count;
		for (i=(*Q).Head;i<=(*Q).T[(*Q).Head].cnt;i++){
			(*X).pnygedung[i]=(*Q).T[(*Q).Head].pnygedung[i];
		}
        for (i=(*Q).Head;i<=(*Q).Tail-1;i++){
            strcpy((*Q).T[i].Nama,(*Q).T[i+1].Nama);
			(*Q).T[i].Lokasi=(*Q).T[i+1].Lokasi;
			(*Q).T[i].JmlAwal=(*Q).T[i+1].JmlAwal;
			(*Q).T[i].JmlAset=(*Q).T[i+1].JmlAset;
			(*Q).T[i].cnt=(*Q).T[i+1].cnt;
			(*Q).T[i].Penjara.Iya=(*Q).T[i+1].Penjara.Iya;
			(*Q).T[i].Penjara.count=(*Q).T[i+1].Penjara.count;
			if ((*Q).T[i+1].cnt==0){
                (*Q).T[i].pnygedung[1]=0;
			}
			else{
                for (j=1;j<=(*Q).T[i+1].cnt;j++){
                    (*Q).T[i].pnygedung[j]=(*Q).T[i+1].pnygedung[j];
                }
			}
        }
    }
	else{
        (*Q).Head=Nil;
        (*Q).Tail=Nil;
    }
}
void PengisianBangunan (Bangunan *B){
		strcpy((*B).ITB[1],"START");
		(*B).Price[1]=0;
		(*B).Kepunyaan[1]=0;
		(*B).Kompleks[1]='0';
		strcpy((*B).ITB[2],"OKTAGON");
		(*B).Price[2]=500000;
		(*B).Kepunyaan[2]=0;
		(*B).Kompleks[2]='1';
		strcpy((*B).ITB[3],"COMLABS");
		(*B).Price[3]=750000;
		(*B).Kepunyaan[3]=0;
		(*B).Kompleks[3]='1';
		strcpy((*B).ITB[4],"TVST");
		(*B).Price[4]=1200000;
		(*B).Kepunyaan[4]=0;
		(*B).Kompleks[4]='2';
		strcpy((*B).ITB[5],"TELKOM");
		(*B).Price[5]=1500000;
		(*B).Kepunyaan[5]=0;
		(*B).Kompleks[5]='2';
		strcpy((*B).ITB[6],"PENJARA");
		(*B).Price[6]=0;
		(*B).Kepunyaan[6]=0;
		(*B).Kompleks[6]='0';
		strcpy((*B).ITB[7],"K_BENGKOK");
		(*B).Price[7]=3500000;
		(*B).Kepunyaan[7]=0;
		(*B).Kompleks[7]='K';
		strcpy((*B).ITB[8],"KESEMPATAN");
		(*B).Price[8]=0;
		(*B).Kepunyaan[8]=0;
		(*B).Kompleks[8]='0';
		strcpy((*B).ITB[9],"GKU_BARAT");
		(*B).Price[9]=1900000;
		(*B).Kepunyaan[9]=0;
		(*B).Kompleks[9]='3';
		strcpy((*B).ITB[10],"GKU_TIMUR");
		(*B).Price[10]=2300000;
		(*B).Kepunyaan[10]=0;
		(*B).Kompleks[10]='3';
		strcpy((*B).ITB[11],"UNDIAN");
		(*B).Price[11]=0;
		(*B).Kepunyaan[11]=0;
		(*B).Kompleks[11]='0';
		strcpy((*B).ITB[12],"AULA_BARAT");
		(*B).Price[12]=2700000;
		(*B).Kepunyaan[12]=0;
		(*B).Kompleks[12]='4';
		strcpy((*B).ITB[13],"AULA_TIMUR");
		(*B).Price[13]=3100000;
		(*B).Kepunyaan[13]=0;
		(*B).Kompleks[13]='4';
		strcpy((*B).ITB[14],"KESEMPATAN");
		(*B).Price[14]=0;
		(*B).Kepunyaan[14]=0;
		(*B).Kompleks[14]='0';
		strcpy((*B).ITB[15],"K_BARRACK");
		(*B).Price[15]=3500000;
		(*B).Kepunyaan[15]=0;
		(*B).Kompleks[15]='K';
		strcpy((*B).ITB[16],"BUS_ITB");
		(*B).Price[16]=0;
		(*B).Kepunyaan[16]=0;
		(*B).Kompleks[16]='0';
		strcpy((*B).ITB[17],"KESEMPATAN");
		(*B).Price[17]=0;
		(*B).Kepunyaan[17]=0;
		(*B).Kompleks[17]='0';
		strcpy((*B).ITB[18],"K_BORJU");
		(*B).Price[18]=3500000;
		(*B).Kepunyaan[18]=0;
		(*B).Kompleks[18]='K';
		strcpy((*B).ITB[19],"LABTEK_VIII");
		(*B).Price[19]=3500000;
		(*B).Kepunyaan[19]=0;
		(*B).Kompleks[19]='5';
		strcpy((*B).ITB[20],"LABTEK_V");
		(*B).Price[20]=4000000;
		(*B).Kepunyaan[20]=0;
		(*B).Kompleks[20]='5';
}
boolean EndGame(Queue Q, Bangunan B){
	if (((B.Kepunyaan[7]==B.Kepunyaan[15])&&(B.Kepunyaan[15]==B.Kepunyaan[18])) && B.Kepunyaan[7]!=0)/*Kompleks Kantin*/{
		return True;
	}
	else if ((B.Kepunyaan[2]==(B.Kepunyaan[3])) && B.Kepunyaan[2]!=0)/*Kompleks 1*/{
		if ((B.Kepunyaan[2]==B.Kepunyaan[4]&&(B.Kepunyaan[4]==(B.Kepunyaan[5]))) && B.Kepunyaan[4]!=0)/*Kompleks 2*/{
			return True;
		}
		else if ((B.Kepunyaan[2]==B.Kepunyaan[9]&&(B.Kepunyaan[9]==B.Kepunyaan[10])) && B.Kepunyaan[9]!=0)/*Kompleks 3*/{
			return True;
		}
		else if ((B.Kepunyaan[2]==B.Kepunyaan[12]&&(B.Kepunyaan[12]==B.Kepunyaan[13])) && B.Kepunyaan[12]!=0)/*Kompleks 4*/{
			return True;
		}
		else if ((B.Kepunyaan[2]==B.Kepunyaan[19]&&(B.Kepunyaan[19]==B.Kepunyaan[20])) && B.Kepunyaan[19]!=0)/*Kompleks 5*/{
			return True;
		}
		else
            return False;
	}
	else if ((B.Kepunyaan[4]==(B.Kepunyaan[5])) && B.Kepunyaan[4]!=0)/*Kompleks 2*/{
		if ((B.Kepunyaan[4]==B.Kepunyaan[9]&&(B.Kepunyaan[9]==B.Kepunyaan[10])) && B.Kepunyaan[9]!=0)/*Kompleks 3*/{
			return True;
		}
		else if ((B.Kepunyaan[4]==B.Kepunyaan[12]&&(B.Kepunyaan[12]==B.Kepunyaan[13])) && B.Kepunyaan[12]!=0)/*Kompleks 4*/{
			return True;
		}
		else if ((B.Kepunyaan[4]==B.Kepunyaan[19]&&(B.Kepunyaan[19]==B.Kepunyaan[20])) && B.Kepunyaan[19]!=0)/*Kompleks 5*/{
			return True;
		}
		else
            return False;
	}
	else if ((B.Kepunyaan[9]==(B.Kepunyaan[10])) && B.Kepunyaan[9]!=0)/*Kompleks 3*/{
		if ((B.Kepunyaan[9]==B.Kepunyaan[12]&&(B.Kepunyaan[12]==B.Kepunyaan[13])) && B.Kepunyaan[12]!=0)/*Kompleks 4*/{
			return True;
		}
		else if ((B.Kepunyaan[9]==B.Kepunyaan[19]&&(B.Kepunyaan[19]==B.Kepunyaan[20])) && B.Kepunyaan[19]!=0)/*Kompleks 5*/{
			return True;
		}
		else
            return False;
	}
	else if ((B.Kepunyaan[12]==(B.Kepunyaan[13])) && B.Kepunyaan[4]!=0)/*Kompleks 4*/{
		if ((B.Kepunyaan[12]==B.Kepunyaan[19]&&(B.Kepunyaan[19]==B.Kepunyaan[20])) && B.Kepunyaan[19]!=0)/*Kompleks 5*/{
			return True;
		}
		else
            return False;
	}
	else if (Q.Tail==1){
		return True;
	}
	else
		return False;
}
void CreateQueuePemain (Queue *Q, int Maks){
    CreateEmpty(Q,Maks);
}
void ChangeTurn (Queue *Q){
    Pemain X;
    Del(Q,&X);
    Add(Q,X);
}
void CreateKondisiAwal(Queue *Q, char Name[10]){
	int i;
	char NamaPmn[10];
	strcpy((*Q).T[1].Nama,Name);
	for (i=2;i<=NbElmt(*Q);i++){
		printf("Nama Player %d : ", i);
		scanf("%s", NamaPmn);
		while (!IsTerdaftar(NamaPmn, LN)){
			printf("Nama Player tidak terdaftar\n");
			printf("Nama Player %d : ", i);
			scanf("%s", NamaPmn);
		}
		strcpy((*Q).T[i].Nama,NamaPmn);
	}
	for (i=1;i<=(*Q).Tail;i++){
		(*Q).T[i].JmlAwal=10000000;
		(*Q).T[i].JmlAset=10000000;
		(*Q).T[i].Lokasi=1;
		(*Q).T[i].pnygedung[0]=0;
		(*Q).T[i].Penjara.Iya=False;
		(*Q).T[i].Penjara.count=4;
		(*Q).T[i].cnt=0;
	}
}
void MajuLangkah(Queue *Q, int N){
	(*Q).T[(*Q).Head].Lokasi=(*Q).T[(*Q).Head].Lokasi+N;
	if ((*Q).T[(*Q).Head].Lokasi>20){
		(*Q).T[(*Q).Head].Lokasi=(*Q).T[(*Q).Head].Lokasi-20;
	}
}
Rupiah KonversiUang(Queue Q){
	Rupiah U;
	U.U1=(Q.T[Q.Head].JmlAwal/1000000);
	U.U2=(Q.T[Q.Head].JmlAwal%1000000)/1000;
	return(U);
}
Rupiah KonversiAset(Queue Q){
	Rupiah U;
	U.U1=(Q.T[Q.Head].JmlAset/1000000);
	U.U2=(Q.T[Q.Head].JmlAset%1000000)/1000;
	return(U);
}
void PrintJumlahUang(Queue Q){
    if (KonversiUang(Q).U1==0){
        printf("Jumlah Uang : Rp %d,000\n", KonversiUang(Q).U2);
    }
    else{
        if (KonversiUang(Q).U2!=0 && (KonversiUang(Q).U2%100!=0 && KonversiUang(Q).U2>99))
            printf("Jumlah Uang : Rp %d,%d,000\n", KonversiUang(Q).U1, KonversiUang(Q).U2);
        else if (KonversiUang(Q).U2/100<10 && (KonversiUang(Q).U2!=0 && KonversiUang(Q).U2<100))
            printf("Jumlah Uang : Rp %d,0%d,000\n", KonversiUang(Q).U1, KonversiUang(Q).U2);
        else if (KonversiUang(Q).U2/100<10 && KonversiUang(Q).U2!=0)
            printf("Jumlah Uang : Rp %d,%d,000\n", KonversiUang(Q).U1, KonversiUang(Q).U2);
        else
            printf("Jumlah Uang : Rp %d,000,000\n", KonversiUang(Q).U1);
    }
    if (KonversiAset(Q).U1==0){
        printf("Jumlah Aset : Rp %d,000\n", KonversiAset(Q).U2);
    }
    else{
        if (KonversiAset(Q).U2!=0 && (KonversiAset(Q).U2%100!=0 && KonversiAset(Q).U2>99))
            printf("Jumlah Aset : Rp %d,%d,000\n", KonversiAset(Q).U1, KonversiAset(Q).U2);
        else if (KonversiAset(Q).U2/100<10 && (KonversiAset(Q).U2!=0 && KonversiAset(Q).U2<100))
            printf("Jumlah Aset : Rp %d,0%d,000\n", KonversiAset(Q).U1, KonversiAset(Q).U2);
        else if (KonversiAset(Q).U2/100<10 && KonversiAset(Q).U2!=0)
            printf("Jumlah Aset : Rp %d,%d,000\n", KonversiAset(Q).U1, KonversiAset(Q).U2);
        else
            printf("Jumlah Aset : Rp %d,000,000\n", KonversiAset(Q).U1);
    }
}
void PrintBiayaGedung(int i){
    Rupiah U;
    U.U1=(i/1000000);
	U.U2=(i%1000000)/1000;
	if (U.U1==0){
        printf("Rp %d,000\n", U.U2);
	}
	else{
        if (U.U2!=0 && (U.U2%100!=0 && U.U2>100))
            printf("Rp %d,%d,000\n", U.U1, U.U2);
        else if (U.U2/100<10 && (U.U2!=0 && U.U2<100))
            printf("Rp %d,0%d,000\n", U.U1, U.U2);
        else if (U.U2/100<10 && U.U2!=0)
            printf("Rp %d,%d,000\n", U.U1, U.U2);
        else
            printf("Rp %d,000,000\n", U.U1);
    }
}
void PrintDadu(int *N, boolean *Same){
	int n1, n2;
	srand(time(NULL));
	printf("Dadu 1 : ");
	n1=rand() % 6 + 1;
	printf("%d\n",n1);
	printf("Dadu 2 : ");
	n2=rand() % 6 + 1;
	printf("%d\n",n2);
	(*N)=n1+n2;
	if (n1==n2){
		(*Same)=True;
	}
	else{
		(*Same)=False;
	}
}
void PrintKoin(int *N){
	srand(time(NULL));
	(*N)=rand() % 2 + 1;
}
boolean LwtStart(Queue Q, int tmp){
	return(Q.T[Q.Head].Lokasi>1 && tmp>20);
}
boolean IsKesempatan(Queue Q){
	return((Q.T[Q.Head].Lokasi==8 || (Q.T[Q.Head].Lokasi==14 || Q.T[Q.Head].Lokasi==17)));
}
boolean IsUndian(Queue Q){
	return(Q.T[Q.Head].Lokasi==11);
}
boolean IsPenjara(Queue Q){
	return(Q.T[Q.Head].Lokasi==6);
}
boolean IsBusITB(Queue Q){
	return(Q.T[Q.Head].Lokasi==16);
}
boolean IsStart(Queue Q){
	return(Q.T[Q.Head].Lokasi==1);
}
char *Gedung(Queue Q, Bangunan B){
	char *type=malloc(20);
	strcpy(type,B.ITB[Q.T[Q.Head].Lokasi]);
	return(type);
	//return(B.ITB[Q.T[Q.Head].Lokasi]);
}
int KonversiTempat(char tempat[20], Bangunan B){
	int i;
	for (i=1;i<=20;i++){
		if (strcmp(tempat,B.ITB[i])==0){
			return(i);
		}
	}
}
long int Harga(Queue Q, Bangunan B){
	return(B.Price[Q.T[Q.Head].Lokasi]);
}
long int HargaAset(Queue Q, Bangunan B){
	return(30*B.Price[Q.T[Q.Head].Lokasi]/100);
}
char *Pemilik(Queue Q, Bangunan B, char tempat[20], int l){
	int i;
	char *type=malloc(20);
	i=1;
	while (l!=B.Kepunyaan[KonversiTempat(tempat,B)]){
		i++;
		if (l<Q.Tail){
			l++;
		}
		else
			l=1;
	}
	strcpy(type,Q.T[i].Nama);
	return(type);
}
boolean LetakTidakSama(Queue Q, Bangunan B, int l){
	return(B.Kepunyaan[Q.T[Q.Head].Lokasi]==0 || (Q.T[Q.Head].Nama==Pemilik(Q,B,Gedung(Q,B),l)));
}
void AddPemilik(Queue *Q, Bangunan *B, int l){
	int i;
	(*Q).T[(*Q).Head].cnt++;
	(*Q).T[(*Q).Head].pnygedung[(*Q).T[(*Q).Head].cnt]=(*Q).T[(*Q).Head].Lokasi;
	(*B).Kepunyaan[(*Q).T[(*Q).Head].Lokasi]=l;
}
void DelPemilik(Queue *Q, Bangunan *B, char tempat[20]){
	int i, j;
	i=1;
	while ((*Q).T[(*Q).Head].pnygedung[i]!=KonversiTempat(tempat,*B))
		i++;
	(*B).Kepunyaan[KonversiTempat(tempat,*B)]=0;
	for (j=i;j<=(*Q).T[(*Q).Head].cnt-1;j++){
        (*Q).T[(*Q).Head].pnygedung[j]=(*Q).T[(*Q).Head].pnygedung[j+1];
	}
	(*Q).T[(*Q).Head].cnt--;
}
void TambahUang(Queue *Q, long int X){
	(*Q).T[(*Q).Head].JmlAwal=(*Q).T[(*Q).Head].JmlAwal+X;
}
void KurangUang(Queue *Q, long int X){
	(*Q).T[(*Q).Head].JmlAwal=(*Q).T[(*Q).Head].JmlAwal-X;
}
void TambahAset(Queue *Q, long int X){
	(*Q).T[(*Q).Head].JmlAset=(*Q).T[(*Q).Head].JmlAset+X;
}
void KurangAset(Queue *Q, long int X){
	(*Q).T[(*Q).Head].JmlAset=(*Q).T[(*Q).Head].JmlAset-X;
}
void TambahUangLwn(Queue *Q, long int X, Bangunan B, int l){
	int i;
	i=1;
	while (l!=B.Kepunyaan[(*Q).T[(*Q).Head].Lokasi]){
		i++;
		if (l<(*Q).Tail){
			l++;
		}
		else
			l=1;
	}
	(*Q).T[i].JmlAwal=(*Q).T[i].JmlAwal+X;
}
void TambahAsetLwn(Queue *Q, int i, long int X){
	(*Q).T[i].JmlAset=(*Q).T[i].JmlAset+X;
}
void KurangAsetLwn(Queue *Q, int i, long int X){
	(*Q).T[i].JmlAset=(*Q).T[i].JmlAset-X;
}
void SwapTempat(Queue *Q, Bangunan *B, char j[20], char k[20], int l){
	int p, q, o, m;
	p=1;
	q=1;
	o=1;
	m=l;
	while ((*Q).T[(*Q).Head].pnygedung[p]!=KonversiTempat(j,*B))
		p++;
    while (strcmp(Pemilik(*Q,*B,k,l),(*Q).T[o].Nama)!=0){
        o++;
        if (m<(*Q).Tail)
            m++;
        else
            m=1;
    }
	while ((*Q).T[o].pnygedung[q]!=KonversiTempat(k,*B))
		q++;
	(*Q).T[(*Q).Head].pnygedung[p]=KonversiTempat(k,*B);
	(*Q).T[o].pnygedung[q]=KonversiTempat(j,*B);
	TambahAset(Q,(*B).Price[KonversiTempat(k,*B)]);
	KurangAset(Q,(*B).Price[KonversiTempat(j,*B)]);
	TambahAsetLwn(Q,o,(*B).Price[KonversiTempat(j,*B)]);
	KurangAsetLwn(Q,o,(*B).Price[KonversiTempat(k,*B)]);
	(*B).Kepunyaan[KonversiTempat(j,*B)]=m;
	(*B).Kepunyaan[KonversiTempat(k,*B)]=l;
}
void LewatStart(Queue *Q){
	printf("%s mendapatkan uang gaji sebesar Rp 1,500,000.\n", (*Q).T[(*Q).Head].Nama);
	TambahUang(Q,1500000);
}
void Start(Queue Q){
	printf("%s menempati posisi START\n", Q.T[Q.Head].Nama);
	printf("%s tidak mendapat gaji apapun\n", Q.T[Q.Head].Nama);
}
boolean CekGedung(char tempat[20]){
    return (strcmp(tempat,"START")!=0 && (strcmp(tempat,"OKTAGON")!=0 && (strcmp(tempat,"COMLABS")!=0 && (strcmp(tempat,"TVST")!=0 &&
         (strcmp(tempat,"TELKOM")!=0 && (strcmp(tempat,"PENJARA")!=0 && (strcmp(tempat,"K_BENGKOK")!=0 && (strcmp(tempat,"KESEMPATAN")!=0 &&
         (strcmp(tempat,"GKU_BARAT")!=0 && (strcmp(tempat,"GKU_TIMUR")!=0 && (strcmp(tempat,"UNDIAN")!=0 && (strcmp(tempat,"AULA_BARAT")!=0 &&
         (strcmp(tempat,"AULA_TIMUR")!=0 && (strcmp(tempat,"K_BARRACK")!=0 && (strcmp(tempat,"BUS_ITB")!=0 && (strcmp(tempat,"K_BORJU")!=0 &&
         (strcmp(tempat,"LABTEK_VIII")!=0 && (strcmp(tempat,"LABTEK_V")!=0))))))))))))))))));
}
void Undian(Queue *Q){
	char taruhan[5], undian[5];
	int menang, K;
	printf("%s mendapatkan kesempatan Undian.\n", (*Q).T[(*Q).Head].Nama);
	if ((*Q).T[(*Q).Head].JmlAwal>1490000){
        printf("Apakah Anda ingin bermain? (Ya/Tidak) ");
        scanf("%s", jwbn);
        while (strcmp(jwbn,"Tidak")!=0 && strcmp(jwbn,"Ya")!=0){
            printf("Input anda salah, Ya/Tidak\n");
            printf("Apakah Anda ingin bermain? (Ya/Tidak) ");
            scanf("%s", jwbn);
        }
        if (strcmp(jwbn,"Ya")==0){
            printf("%s membayar 1,5 juta untuk melakukan taruhan.\n", (*Q).T[(*Q).Head].Nama);
            KurangUang(Q,1500000);
            menang=0;
            while ((strcmp(jwbn,"Ya")==0) && (menang<=3)){
                printf("Taruhan Anda (Head/Tail) ");
                scanf("%s", taruhan);
                while (strcmp(jwbn,"Tidak")!=0 && strcmp(jwbn,"Ya")!=0){
                    printf("Input anda salah, Head/Tail\n");
                    printf("Taruhan Anda (Head/Tail) ");
                    scanf("%s", taruhan);
                }
                PrintKoin(&K);
                switch (K){
                    case 1 :printf("Hasil Undian : Head\n");
                            strcpy(undian,"Head");
                            break;
                    case 2 :printf("Hasil Undian : Tail\n");
                            strcpy(undian,"Tail");
                            break;
                    default:break;
                }
                if (strcmp(taruhan,undian)==0){
                    menang++;
                    if (menang<3){
                        printf("Anda Menang! Apakah Anda ingin bermain? (Ya/Tidak)\n");
                        scanf("%s", jwbn);
                        while (strcmp(jwbn,"Tidak")!=0 && strcmp(jwbn,"Ya")!=0){
                            printf("Input anda salah, Ya/Tidak\n");
                            printf("Apakah Anda ingin bermain? (Ya/Tidak) ");
                            scanf("%s", jwbn);
                        }
                    }
                    if ((strcmp(jwbn,"Tidak")==0) || menang==3){
                        printf("Anda berhasil mendapatkan %dx dari uang taruhan = %d\n", menang+1, ((menang+1)*1500000));
                        TambahUang(Q,(menang+1)*1500000);
                    }
                }
                else{
                    printf("Anda Kalah! Anda tidak mendapatkan apapun\n");
                    strcpy(jwbn,"Tidak");
                }
            }
        }
	}else
        printf("Uang Anda tidak cukup untuk melakukan undian.\n");
}
void Penjara(Queue *Q, int *j, boolean *Same){
	printf("%s masuk penjara\n", (*Q).T[(*Q).Head].Nama);
	(*Q).T[(*Q).Head].Lokasi=6;
	(*j)=6;
	printf("%s tidak dapat bermain selama 2 putaran kecuali mendapat angka yang sama\n", (*Q).T[(*Q).Head].Nama);
	(*Q).T[(*Q).Head].Penjara.Iya=True;
	(*Q).T[(*Q).Head].Penjara.count=1;
	(*Same)=False;
}
void Umum (Queue *Q, Bangunan *B, int l){
	Pemain X;
	char c;
	char tempat[21];
	printf("%s berada pada %s.\n", (*Q).T[(*Q).Head].Nama, Gedung(*Q,*B));
	if (LetakTidakSama(*Q,*B,l)&&(*B).Kepunyaan[(*Q).T[(*Q).Head].Lokasi]==0){
        if ((*Q).T[(*Q).Head].JmlAwal>=(*B).Price[(*Q).T[(*Q).Head].Lokasi]){
            printf("Beli Gedung? (Ya/Tidak) ");

            scanf("%s", jwbn);
            while (strcmp(jwbn,"Tidak")!=0 && strcmp(jwbn,"Ya")!=0){
                printf("Input anda salah, Ya/Tidak\n");
                printf("Beli Gedung? (Ya/Tidak) ");
                scanf("%s", jwbn);
            }
            if (strcmp(jwbn,"Ya")==0){
                printf("%s membeli %s seharga ", (*Q).T[(*Q).Head].Nama, Gedung(*Q,*B));
				PrintBiayaGedung(Harga(*Q,*B));
                KurangUang(Q,Harga(*Q,*B));
                AddPemilik(Q,B,l);
                TambahAset(Q,Harga(*Q,*B));
            }
        }
        else{
            printf("Uang Anda tidak cukup untuk membeli gedung.\n");
        }
	}
	else if ((HargaAset(*Q,*B))<(*Q).T[(*Q).Head].JmlAwal&&((*B).Kepunyaan[(*Q).T[(*Q).Head].Lokasi]!=l)){
		printf("%s membayar uang sewa ke %s sebesar ", (*Q).T[(*Q).Head].Nama, Pemilik(*Q,*B,Gedung(*Q,*B),l));
		PrintBiayaGedung(HargaAset(*Q,*B));
		KurangUang(Q,HargaAset(*Q,*B));
		TambahUangLwn(Q,HargaAset(*Q,*B),*B,l);
	}
	else if ((*Q).T[(*Q).Head].pnygedung[1]>1&&((*B).Kepunyaan[(*Q).T[(*Q).Head].Lokasi]!=l)){
        while ((HargaAset(*Q,*B))>(*Q).T[(*Q).Head].JmlAwal && (*Q).T[(*Q).Head].pnygedung[1]>1){
            printf("%s tidak memiliki uang yang cukup untuk membayar uang sewa.\n", (*Q).T[(*Q).Head].Nama);
            printf("Sebutkan gedung yang ingin dijual! ");
            scanf("%s", tempat);
            while (CekGedung(tempat)){
                printf("Input Anda salah, Nama Gedung\n");
                printf("Sebutkan gedung yang ingin dijual! ");
                scanf("%s", tempat);
            }
            while (strcmp(Pemilik(*Q,*B,tempat,l),(*Q).T[(*Q).Head].Nama)!=0){
                printf("Anda tidak memiliki gedung %s. Sebutkan gedung yang Anda miliki!\n", tempat);
                scanf("%s", tempat);
                while (CekGedung(tempat)){
                    printf("Input Anda salah, Nama Gedung\n");
                    printf("Sebutkan gedung yang ingin dijual! ");
                    scanf("%s", tempat);
                }
            }
            DelPemilik(Q,B,tempat);
            TambahUang(Q,(*B).Price[KonversiTempat(tempat,*B)]/2);
            KurangAset(Q,(*B).Price[KonversiTempat(tempat,*B)]);
        }
		if (HargaAset(*Q,*B)<=(*Q).T[(*Q).Head].JmlAwal+((*B).Price[KonversiTempat(tempat,*B)]/2)){
			printf("%s membayar uang sewa ke %s sebesar ", (*Q).T[(*Q).Head].Nama, Pemilik(*Q,*B,Gedung(*Q,*B),l));
            PrintBiayaGedung(HargaAset(*Q,*B));
			KurangUang(Q,HargaAset(*Q,*B));
			TambahUangLwn(Q,HargaAset(*Q,*B),*B,l);
		}
		else{
			printf("%s bangkrut\n", (*Q).T[(*Q).Head].Nama);
			Del(Q,&X);
			(*Q).Tail--;
		}
	}
	else if ((*B).Kepunyaan[(*Q).T[(*Q).Head].Lokasi]!=l){
		printf("%s bangkrut\n", (*Q).T[(*Q).Head].Nama);
		Del(Q,&X);
		(*Q).Tail--;
	}
}
void BusITB(Queue *Q, Bangunan *B, int *j, int l){
	char tempat[20];
	printf("%s mendapatkan Tiket Bus ITB\n", (*Q).T[(*Q).Head].Nama);
	printf("Apakah Anda ingin menggunakan Tiket Bus ITB? (Ya/Tidak)");
	scanf("%s", jwbn);
	while (strcmp(jwbn,"Tidak")!=0 && strcmp(jwbn,"Ya")!=0){
        printf("Input anda salah, Ya/Tidak\n");
        printf("Apakah Anda ingin menggunakan Tiket Bus ITB? (Ya/Tidak) ");
        scanf("%s", jwbn);
    }
	if (strcmp(jwbn,"Ya")==0){
		printf("Sebutkan lokasi yang ingin Anda tuju : ");
		scanf("%s", tempat);
		while (CekGedung(tempat)){
            printf("Input Gedung Anda salah, Nama Gedung\n");
            printf("Sebutkan lokasi yang ingin Anda tuju : ");
            scanf("%s", tempat);
        }
		printf("%s maju ke %s\n", (*Q).T[(*Q).Head].Nama, tempat);
		if ((*Q).T[(*Q).Head].Lokasi>KonversiTempat(tempat,*B))
            LewatStart(Q);
		(*j)=(*Q).T[(*Q).Head].Lokasi;
		(*Q).T[(*Q).Head].Lokasi=KonversiTempat(tempat,*B);
		if (IsStart(*Q)){
			Start(*Q);
		}
		else if (IsUndian(*Q)){
			Undian(Q);
		}
		else{
			Umum(Q,B,l);
		}
	}
}
void Kesempatan(Queue *Q, Bangunan *B, int *j, int l, boolean *Same){
	int hasil;
	char tempat[20], tempatlawan[20];
	srand(time(NULL));
	hasil=rand() % 3 + 1;
	switch (hasil){
		case 1 :printf("%s mendapatkan kartu kesempatan : Masuk Penjara\n", (*Q).T[(*Q).Head].Nama);
				Penjara(Q,j,Same);
				break;
		case 2 :printf("%s mendapatkan kartu kesempatan : Tiket Bus ITB\n", (*Q).T[(*Q).Head].Nama);
				if (LwtStart(*Q,*j)){
					LewatStart(Q);
				}
				BusITB(Q,B,j,l);
				break;
		case 3 :printf("%s mendapatkan kartu kesempatan : Tukar Gedung\n", (*Q).T[(*Q).Head].Nama);
				if ((*Q).T[(*Q).Head].cnt!=0){
					printf("Apakah Anda ingin menukar gedung? (Ya/Tidak)");
					scanf("%s", jwbn);
					while (strcmp(jwbn,"Tidak")!=0 && strcmp(jwbn,"Ya")!=0){
                        printf("Input anda salah, Ya/Tidak\n");
                        printf("Apakah Anda ingin menukar gedung? (Ya/Tidak) ");
                        scanf("%s", jwbn);
                    }
					if (strcmp(jwbn,"Ya")==0){
						printf("Sebutkan gedung yang ingin ditukar : ");
						scanf("%s", tempat);
						while ((*B).Kepunyaan[KonversiTempat(tempat,*B)]!=l || CekGedung(tempat)){
							printf("Anda tidak memiliki gedung %s atau Input gedung Anda salah\n", tempat);
							printf("Sebutkan gedung yang ingin ditukar : ");
							scanf("%s", tempat);
						}
						printf("Sebutkan gedung pemain lawan yang ingin ditukar : ");
						scanf("%s", tempatlawan);
						while ((*B).Kepunyaan[KonversiTempat(tempatlawan,*B)]==0 || (CekGedung(tempatlawan) || (*B).Kepunyaan[KonversiTempat(tempatlawan,*B)]==l)){
							printf("Tidak ada yang memiliki gedung %s atau Input gedung Anda salah atau Ini adalah gedung Anda\n", tempatlawan);
							printf("Sebutkan gedung pemain lawan yang ingin ditukar : ");
							scanf("%s", tempatlawan);
						}
                        printf("%s menukar gedung %s dengan gedung %s milik %s\n", (*Q).T[(*Q).Head].Nama, tempat, tempatlawan, Pemilik(*Q,*B,tempatlawan,l));
						SwapTempat(Q,B,tempat,tempatlawan,l);
					}
				}
				else
					printf("%s belum memiliki gedung apapun\n", (*Q).T[(*Q).Head].Nama);
				break;
		default:break;
	}
}

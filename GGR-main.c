#include "GGR.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    /*KAMUS*/
    char FileName[30];
    char Name[10];
    char ulang;
    int pil1, pil2, CountName, q;
	char c, NamaPmn[20];
	boolean Same;
	Bangunan B;
	int i, j, N, k, l, n, m, tempLetak[10];
	int jmlpmn;
	Queue Q;
	
    /*ALGORITMA*/
    printf("\n");
    printf("     ______     ______   __    __  ________   ______    ______     \n");
    printf("    /      /   /        |     |   |          /         /          \n");
    printf("   |  $$$$$$   $$$$$$   | $$  | $$| $$$$$$$$|  $$$$$$ |  $$$$$$   \n");
    printf("   | $$ __ $$| $$__| $$ | $$$ | $$| $$__    | $$    $$| $$__| $$  \n");
    printf("   | $$|     | $$    $$ | $$$$  $$| $$      | $$      | $$    $$  \n");
    printf("   | $$  $$$$| $$$$$$$$ | $$ $$ $$| $$$$$   | $$   __ | $$$$$$$$  \n");
    printf("   | $$__| $$| $$  | $$ | $$  $$$$| $$_____ | $$__/   | $$  | $$  \n");
    printf("     $$    $$| $$  | $$ | $$   $$$| $$        $$    $$| $$  | $$  \n");
    printf("      $$$$$$   $$    $$   $$    $$  $$$$$$$$   $$$$$$   $$    $$  \n");
    printf("         _      _   _                 _          _      _      \n");
    printf("        | | ___| |_( )__    __ _  ___| |_   _ __(_) ___| |__   \n");
    printf("        | |/ _   __|/ __|  / _` |/ _   __| | '__| |/ __| '_    \n");
    printf("        | |  __/ |_  __  || (_| |  __/ |_  | |  | | (__| | | | \n");
    printf("        |_| ___| __||___/   __, | ___| __| |_|  |_| ___|_| |_| \n");
    printf("                           |___/                               \n");
    printf("\n");    
    printf("\n");
    printf("--File Eksternal--\n");
    printf("Masukkan nama file : "); 
	scanf("%s", &FileName);
    SalinFile(FileName, &LN);
    do {
        printf("\nMAIN MENU\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. About\n");
        printf("4. Quit\n");
        printf("Pilihan anda = "); 
		scanf("%d", &pil1);
        switch (pil1) {
            case 1: printf("--Register--\n");
                    ulang='Y';
                    do {
                        if (ulang=='Y') {
                            printf("Nama : "); 
							scanf("%s", &Name);
                            if (!IsTerdaftar(Name, LN)) {
                                if (IsNameValid(Name)){
                                    LN.CountName++;
                                    strcpy(LN.Name[LN.CountName], Name);
                                    printf("Pendaftaran Berhasil. %s terdaftar.\n", Name);
                                } else {
                                    printf("Pendaftaran gagal. Nama pemain harus >= 3 karakter\n");
                                }
                            } else {
                                printf("Pendaftaran gagal. %s telah terdaftar.\n", Name);
                            }
                        }else {
                            printf("Input salah, ulangi lagi!\n");
                        };
                        printf("Mendaftar lagi? (Y/T) : ");
                        scanf(" %c", &ulang);
                    } while(ulang!='T');
                    break;
            case 2: if (IsFileEmpty(LN)){
                        printf("File kosong! Register terlebih dahulu!\n");
                    } else {
                        printf("==Login==\n");
                        printf("Nama : "); scanf("%s", &Name);
                        if (IsTerdaftar(Name, LN)) {
                            printf("Login berhasil. \nSelamat datang %s \n", Name);
							printf("\nTeman bermain anda : \n");
                            DaftarPemain(Name, LN);
                            do {
                                printf("\nPREPARATION MENU\n");
                                printf("1. New Game\n");
                                printf("2. High Score Board\n");
                                printf("3. Logout\n");
                                printf("Pilihan anda = "); 
								scanf("%d", &pil2);
                                switch (pil2) {
                                    case 1: 
											PengisianBangunan(&B);
											printf("Masukkan jumlah pemain 2/3/4 : ");
											scanf("%d", &jmlpmn);
											while (jmlpmn>4 || jmlpmn<2){
												printf("Jumlah pemain salah, minimal 2 dan maksimal 4\n");
												printf("Masukkan jumlah pemain 2/3/4 : ");
												scanf("%d", &jmlpmn);
											}				
											CreateQueuePemain(&Q,jmlpmn);
											Q.Head=1;
											Q.Tail=jmlpmn;
											CreateKondisiAwal(&Q,Name);
											for (i=Q.Head;i<=NbElmt(Q);i++){
												printf("-----%s-----\n", Q.T[i].Nama);
												printf("Jumlah Uang : Rp 10,000,000\n");
												printf("Jumlah Aset : Rp 10,000,000\n");
											}
											for (i=Q.Head;i<=Q.Tail;i++){
												tempLetak[i]=1;
											}
											j=0;
											l=1;
											i=Q.Tail;
											n=1;
											while (!EndGame(Q,B)){
												j++;
												Same=False;
												printf("-----Turn %d-----\n", j);
												printf("Giliran : %s\n", Q.T[Q.Head].Nama);
												do{
													PrintJumlahUang(Q);
													printf("Tekan Enter untuk mengocok dadu!\n");
													while (getch()!=13){
													}
													PrintDadu(&N,&Same);
													MajuLangkah(&Q,N);
													Boardpermainan(Q,l);
													if ((Q.T[Q.Head].Penjara.count<3) && (!Same)){
														printf("%s belum bisa keluar dari penjara, tinggal %d putaran lagi\n", Q.T[Q.Head].Nama, 2-Q.T[Q.Head].Penjara.count);
														Q.T[Q.Head].Penjara.count++;
														Same=False;
														Q.T[Q.Head].Lokasi=6;
														Boardpermainan(Q,l);
													}
													else if (Q.T[Q.Head].Penjara.count<3 && (Same && Q.T[Q.Head].Penjara.count>0)){
														printf("%s keluar dari penjara\n", Q.T[Q.Head].Nama);
														Same=True;
														Q.T[Q.Head].Penjara.count=4;
														Q.T[Q.Head].Penjara.Iya=False;
													}
													if (Q.T[Q.Head].Penjara.Iya==False){
														printf("%s maju sebanyak %d langkah!\n", Q.T[Q.Head].Nama, N);
														if (Same){
															printf("%s mendapat dadu yang sama\n", Q.T[Q.Head].Nama);
														}
														tempLetak[l]=tempLetak[l]+N;
														if (IsStart(Q)){
															Start(Q);
														}
														else if (LwtStart(Q,tempLetak[l])){
															LewatStart(&Q);
														}
														if (tempLetak[l]>20){
															tempLetak[l]=tempLetak[l]-20;
														}
														if (IsUndian(Q)){
															Undian(&Q);
														}
														else if (IsKesempatan(Q)){
															Kesempatan(&Q,&B,&tempLetak[l],l,&Same);
														}
														else if (IsBusITB(Q)){
															BusITB(&Q,&B,&tempLetak[l],l);
														}
														else if (IsPenjara(Q)){
															Penjara(&Q,&tempLetak[l],&Same);
														}
														else if (Q.T[Q.Head].Lokasi!=1){
															Umum(&Q,&B,l);
														}
													}
													if (Q.T[Q.Head].Penjara.count==3){
														Q.T[Q.Head].Penjara.count=4;
														Q.T[Q.Head].Penjara.Iya=False;
													}
													PrintJumlahUang(Q);
													if (Q.T[Q.Head].cnt>0 && Q.Tail==i){
														for (m=1;m<=Q.T[Q.Head].cnt;m++){
															printf("%d. %c %s\n", m, B.Kompleks[Q.T[Q.Head].pnygedung[m]], B.ITB[Q.T[Q.Head].pnygedung[m]]);
														}
													}
													printf("\n");
													if (EndGame(Q,B))
														Same=False;
												}
												while (Same);
												if (i<=Q.Tail){
													if (l<Q.Tail){
														l++;
													}
													else
														l=n;
													ChangeTurn(&Q);
												}
												else{
													i--;
													n++;
													if (l<Q.Tail){
														l++;
													}
													else
														l=n;
												}
											}
											//tulis untuk print ke txt
											
                                        break;
                                    case 2:
                                            break;   
                                    case 3: printf("Selamat Tinggal!\n");
                                            break;
                                    default: printf("Masukan salah, ulangi lagi!\n");
                                        }
                                    }while (pil2 != 3);
                        }
                            else {
                            printf("Login Gagal. Nama tidak terdaftar. Silahkan daftarkan terlebih dahulu\n");
                        }
                    }
                    break;
            case 3: printf(" ABOUT \n");
                printf(" ADINDA JUWITA NINGTYAS || 18213026 \n");
                printf(" Gadis berusia 19 tahun ini memiliki hobi nonton film dan anime. \n");
                printf(" Pesan: Semoga tugas ini bermanfaat \n");
                printf("\n");
                printf(" VICTORIO KHOMAS || 18213045 \n");
                printf(" Laki-laki berusia 19 tahun ini memiliki hobi ngoding dan bisnis \n");
                printf(" Pesan: Tubes ini membuat saya semakin mencintai ngoding \n");
                printf("\n");
                printf(" NEYSSA NATHANIA || 18213033 \n");
                printf(" Gadis berusia 19 tahun ini memiliki hobi bermain musik \n");
                printf(" Pesan: Semoga nilai tubes kami bagus! \n");	
                printf("\n");
                break;
            case 4: printf("Selamat Tinggal!\n");
                    break;
            default: printf("Masukan salah, ulangi lagi!\n");
        }
    } while (pil1 != 4);
    WriteFile(FileName, LN);	
	return 0;
}

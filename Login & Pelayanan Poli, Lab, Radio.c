#include <stdio.h> //digunakan untuk standar input dan output
#include <stdlib.h>
#include <conio.h> //digunakan untuk fungsi delay(),getch(),gotoxy(),dll.
#include <string.h> //digunakan untuk fungsi strcmp(),strcpy(),strlen(),dll.
#include <windows.h>
#define MAX 100

typedef struct{
    int data[100];
    char data1[100][20];
    char data3[100][15];
    int front, rear;
}queue;
queue antrian;
queue no;
queue nama;

int choice, data, i, j;
char data1[20], data3[15];

int isEmpty()
{
    if (antrian.rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (antrian.rear==100)
        return 1;
    else
        return 0;
}
void Enqueue (int data, char data1[20], char data3[15])
{
    if (isEmpty()==1)
    {
        antrian.front = antrian.rear = 0;
            nama.front = nama.rear = 0;
            no.front = no.rear;
        antrian.data[antrian.rear] = data;
            for (i=0; i<20; i++){
                nama.data1[nama.rear][i] = data1[i];
            }
            for (i=0; i<15; i++){
                no.data3[no.rear][i] = data3[i];
            }
            printf ("\nData Anda telah masuk. Silakan menunggu untuk dipanggil!\n");
    }else if (isFull()==0)
    {
        antrian.rear++; nama.rear++; no.rear++;
        antrian.data[antrian.rear] = data;
            for (i=0; i<20; i++){
                nama.data1[nama.rear][i] = data1[i];
            }
            for (i=0; i<15; i++){
                no.data3[no.rear][i] = data3[i];
            }
            printf ("Data Anda telah masuk. Silakan menunggu untuk dipanggil!\n");
    }
}
int Dequeue()
{
    if (isEmpty() == 0)
    {
        int i, e;
        char a[20];
        e = antrian.data[antrian.front];
            for (i=0; i<20; i++)
            {
                a[i] = nama.data1[nama.front][i];
            }
            for (i=antrian.front; i<antrian.rear; i++)
            {
                antrian.data[i] = antrian.data[i+1];
                for (j=0; j<20; j++)
                {
                    nama.data1[i][j] = nama.data1[i+1][j];
                }
                for (j=0; j<15; j++)
                {
                    no.data3[i][j] = no.data3[i+1][j];
                }
            }
                antrian.rear--; nama.rear--; no.rear--;
                printf ("Antrean nomor %i atas nama %s", e, a);
            return e, a[20];
            }else{
                printf ("Antrean kosong");
            }
}
void buat()
{
    antrian.front = antrian.rear = -1;
    nama.front = nama.rear = -1;
    no.front = no.rear = -1;
}
void insert(int);
void delete();
void create();
void check(int);
void display();
int queueArray[MAX];
int front= -1, rear= -1;

/* Fungsi untuk membuat antrean kosong */
void create()
{
    front = rear = -1;
}

/* Fungsi untuk menambahkan nomor antrean */
void insert(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nAntrian penuh!");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        queueArray[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

/* Fungsi untuk mengecek nomor dan letaknya pada antrean */
void check(int data)
{
    int i,j;

    for (i = 0; i <= rear; i++)
    {
        if (data >= queueArray[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                queueArray[j] = queueArray[j - 1];
            }
            queueArray[i] = data;
            return;
        }
    }
    queueArray[i] = data;
}

/* Fungsi untuk menghapus nomor antrean */
void delete(int data)
{
    int i;

    if ((front==-1) && (rear==-1))
    {
        printf("\nAntrean kosong!");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == queueArray[i])
        {
            for (; i < rear; i++)
            {
                queueArray[i] = queueArray[i + 1];
            }

        queueArray[i] = -99;
        rear--;

        if (rear == -1)
            front = -1;
        return;
        }
    }
    printf("\n%d tidak ditemukan di dalam antrean.\n", data);
}

/* Fungsi untuk menampilkan nomor antrean */
void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nAntrean kosong!");
        return;
    }

    for (; front <= rear; front++)
    {
        printf("%d ", queueArray[front]);
    }

    front = 0;
}

void menuLogin(){
system ("color 0b");
        char username[6] = "RSUAW", password [10] = "202834";
        char user[6], pass[10];
        char uname[12] = "pasienRSUAW", passw[5] = "1234";
        char u[12], p[5];
        int masuk, ulang, n, pilihan, adm;
        int pil, pil1, poli, umum, bpjs, a;
        n = 1;
menuValidasi :
            printf ("\nMasuk sebagai?\n");
            printf ("1. Pasien\n");
            printf ("2. Admin\n");
            printf ("Pilihan Anda : ");
            scanf ("%d", &masuk);
            switch (masuk){
    case 1:

        printf ("\nSILAKAN LOGIN DENGAN MENGGUNAKAN USERNAME DAN PASSWORD YANG SESUAI\n\n");
        while (ulang<3){
        printf ("username : "); scanf ("%s", &u);
        printf ("password : "); scanf ("%s", &p);
        if (strcmp (uname, u) == 0 && strcmp (passw, p) == 0){
    break;
    }else{
        printf ("Username/Password Anda salah!\n\n");
        ulang++;
    }
}system("cls");
if (ulang<3){
    printf("\t\t\tSELAMAT DATANG DI SISTEM INFORMASI\n");
    printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\tJL.PEGANGSAAN BARAT NO.5 KOTA MALANG\n");
    printf("\t\t\t   NOMOR TELEPON :0361 2457 8897\n");
    printf("\t\tSENYUM ANDA HARAPAN KAMI,KESEMBUHAN ANDA TUJUAN KAMI\n");
    printf("\t\t========================================================\n\n");
        menuPelayanan:
            printf("Silakan pilih jenis pelayanan yang Anda butuhkan!\n");
            printf("1.RAWAT INAP\n");
            printf("2.RAWAT JALAN\n");
            printf("3.IGD\n");
            printf("4.FARMASI\n");
            printf("5.LABORATORIUM\n");
            printf("6.RADIOLOGI\n");
            printf("7.KELUAR\n");
            printf("Masukkan Pilihan Anda : ");
            scanf("%d", &pil);
        if (pil == 1 || 2 || 3 || 4 || 5 || 6){
            system ("cls");
            menuJaminan:
                printf("\nSilakan pilih jaminan kesehatan yang Anda gunakan.\nApabila Anda tidak menggunakan jaminan kesehatan apapun, tekan 1.\n");
                printf("1. Umum\n");
                printf("2. BPJS\n");
                printf("3. Batal Memilih\n");
                printf("Masukkan Pilihan Anda : ");
                scanf("%d", &pil1);
                system ("cls");
                    if(pil1 == 1 || 2){
                            printf("\nSilakan pilih pelayanan Poliklinik yang Anda Butuhkan\n");
                            printf("1. POLIKLINIK UMUM                          8. POLIKLINIK PSIKIATRI\n");
                            printf("2. POLIKLINIK ANAK                          9. POLIKLINIK KANDUNGAN DAN KEBIDANAN (obgyn)\n");
                            printf("3. POLIKLINIIK BEDAH                        10.POLIKLINIK PENYAKIT KULIT DAN KELAMIN\n");
                            printf("4. POLIKLINIK GIGI                          11.POLIKLINIK PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru)\n");
                            printf("5. POLIKLINIK THT                           12.POLIKLINIK JANTUNG\n");
                            printf("6. POLIKLINIK MATA                          13.POLIKLINIK SARAF\n");
                            printf("7. POIKLINIK PENYAKIT DALAM                 0. KEMBALI\n");
                            printf("Masukkan Pilihan Anda:");
                            scanf("%d", &poli);
                            system ("cls");
                                    if (poli == 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10 || 11 || 12 || 13){
                                        printf("Anda memilih poliklinik %d\n", poli);
                                        printf("1. Tambah nomor antrean\n");
                                        printf("2. Tampilkan nomor antrean\n");
                                        printf("3. Lihat nama dan jadwal dokter yang bertugas\n");
                                        printf("4. Batalkan\n");
                                        printf("Masukkan pilihan Anda : ");
                                        scanf("%d", &a);
                                                switch (a){
                                                    case 1:
                                                        printf("\nNomor antrean Anda adalah %i\n", n);
                                                        data = n;
                                                        printf("Masukkan no. rekam medis Anda : "); scanf ("%s", &data3);
                                                        printf("Masukkan nama Anda : "); scanf ("%s", &data1);
                                                        Enqueue(data, data1, data3);
                                                        n++;
                                                    break;
                                                    case 2:
                                                        if (isEmpty() == 1)
                                                        {
                                                            printf ("Antrean kosong\n");
                                                            break;
                                                        }puts ("Nomor antrean           No. Rekam Medis         Nama");
                                                            for (i=antrian.front; i<antrian.rear; i++)
                                                            {
                                                                printf("%i                  %s                  %s\n", antrian.data[i], no.data3[i], nama.data1[i]);
                                                            }
                                                    break;
                                                    case 3:
                                                        printf ("ISIIN NAMA DOKTER DAN JADWAL PRAKTEK");
                                                    break;
                                                    case 4:
                                                        printf ("Terima kasih sudah menggunakan layanan kami!");
                                                    break;
                                                    default:
                                                        printf("\nPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
                                                    }
                                                }else if (poli == 0){
                                                        exit(1);
                                                }else{
                                                    printf("\nPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
                                                }
                    }else if(pil1 == 3){
                            exit(1);
                    }else{
                            printf("Harap pilih sesuai pilihan yang tersedia!");
                            goto menuJaminan;
                    }
        }else if (pil == 7){
            exit (1);
        }else{
            printf("Harap pilih sesuai pilihan yang tersedia!");
            goto menuPelayanan;
        }
    }else{
        printf ("Akses ditolak! Anda sudah melebihi batasan dalam validasi pengguna.\n");
        exit (1);
    }break;
case 2:

       printf ("\nSILAKAN LOGIN DENGAN MENGGUNAKAN USERNAME DAN PASSWORD YANG SESUAI\n\n");
         while (ulang<3){
            printf ("username : "); scanf ("%s", &user);
            printf ("password : "); scanf ("%s", &pass);
            if (strcmp (username, user) == 0 && strcmp (password, pass) == 0){
 break;
        }else{
            printf ("Username/Password Anda salah!\n\n");
            ulang++;
        }
}system("cls");
if (ulang<3){
    printf("\t\t\tSELAMAT DATANG DI SISTEM INFORMASI\n");
    printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\tJL.PEGANGSAAN BARAT NO.5 KOTA MALANG\n");
    printf("\t\t\t   NOMOR TELEPON :0361 2457 8897\n");
    printf("\t\tSENYUM ANDA HARAPAN KAMI,KESEMBUHAN ANDA TUJUAN KAMI\n");
    printf("\t\t========================================================\n\n");
    }else{
        printf ("Akses ditolak! Anda sudah melebihi batasan dalam validasi pengguna.\n");
        exit (1);
    }break;
default:
    printf ("Maaf, pilihan tersebut tidak tersedia.\n\n");
    goto menuValidasi;
    }
}
//PILIHAN LAYANAN RS
int pilihanPelayanan()
{
    int pil;
    printf("\n\n");
    printf("PILIH PELAYANAN RUMAH SAKIT YANG TERSEDIA\n");
    printf("1.RAWAT INAP\n");
    printf("2.RAWAT JALAN\n");
    printf("3.IGD\n");
    printf("4.FARMASI\n");
    printf("5.LABORATORIUM\n");
    printf("6.RADIOLOGI\n");
    printf("7.KELUAR\n");
    printf("MASUKAN PILIHAN ANDA :");
    scanf("%d", &pil);
    return pil;
}

//JALUR YANG AKAN DIGUNAKAN PASIEN
int pilihanJalurLayanan()
{
    system("cls");
    int jalur;
    printf("\t\t\t***00o SELAMAT DATANG DI PROGRAM RAWAT JALAN o00*\n");
    printf("\t\t\t**00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n");
    printf("\t\t\t================================================================\n\n");
    printf("PILIH JALUR PELAYANAN YANG ANDA GUNAKAN\n");
    printf("1.UMUM\n");
    printf("2.BPJS\n");
    printf("3.KEMBALI\n");
    printf("MASUKKAN PILIHAN ANDA :");
    scanf("%d", &jalur);
    return(jalur);
}
//PILIHAN POLIKLINIK
int pilihanPoliklinik()
{
    system("cls");
    printf("\t\t\t***00o SELAMAT DATANG DI PROGRAM RAWAT JALAN o00*\n");
    printf("\t\t\t**00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n");
    printf("\t\t\t===============================================================\n\n");
    int poli;
    printf("SILAHKAN PILIH POLIKLINIK YANG ANDA INGINKAN\n\n");
    printf("1. POLIKLINIK UMUM                          8. POLIKLINIK PSIKIATRI\n");
    printf("2. POLIKLINIK ANAK                          9. POLIKLINIK KANDUNGAN DAN KEBIDANAN (obgyn)\n");
    printf("3. POLIKLINIIK BEDAH                        10.POLIKLINIK PENYAKIT KULIT DAN KELAMIN\n");
    printf("4. POLIKLINIK GIGI                          11.POLIKLINIK PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru)\n");
    printf("5. POLIKLINIK THT                           12.POLIKLINIK JANTUNG\n");
    printf("6. POLIKLINIK MATA                          13.POLIKLINIK SARAF\n");
    printf("7. POIKLINIK PENYAKIT DALAM                 0. KEMBALI\n");
    printf("SILAHKAN MASUKKAN PILIHAN ANDA :");
    scanf("%d", &poli);
    return(poli);
}

int poliklinik(int poli, int n, int choice)
{
        int dataPasienPoli( char* nama, char* dokter, int n, int choice);
        char* nama;
        char* dokter;
        if(poli == 1){
            nama = "POLIKLINIK UMUM";
            dokter = "dr.Amelia Venusia";
        }
        else if (poli == 2){
            nama = "POLIKLINIK ANAK";
            dokter = "dr.Jerry Putra, Sp.A";
        }
        else if (poli == 3){
            nama = "POLIKLINIK BEDAH";
            dokter = "dr.Ferdinan Geneva, Sp.B";
        }
        else if (poli == 4){
            nama = "POLIKLINIK GIGI";
            dokter = "drg.Anisa Rahmantari";
        }
        else if (poli == 5){
            nama = "POLIKLINIK THT";
            dokter = "dr.Reyhan Fernandus, Sp.THT";
        }
        else if (poli == 6){
            nama = "POLIKLINIK MATA";
            dokter = "dr.Anggi Maharani, Sp.M";
        }
        else if (poli == 7){
            nama = "POLIKLINIK PENYAKIT DALAM";
            dokter = "dr.Jhonny Robert, Sp.PD";
        }
        else if (poli == 8){
            nama = "POLIKLINIK PSIKIATRI";
            dokter = "dr.Wahyu Saputra, Sp.KJ";
        }
        else if (poli == 9){
            nama = "POLIKLINIK KANDUNGAN DAN KEBIDANAN (obgyn)";
            dokter = "dr.Andrea Putra, Sp.OG";
        }
        else if (poli == 10){
            nama = "POLIKLINIK PENYAKIT KULIT DAN KELAMIN";
            dokter = "dr.Dita Cahya, Sp.KK";
        }
        else if (poli == 11){
            nama = "POLIKLINIK PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru";
            dokter = "dr.Vina Devianti, Sp.P";
        }
        else if (poli == 12){
            nama = "POLIKLINIK JANTUNG";
            dokter = "dr.Gita Prananda, Sp.JP";
        }
        else if (poli == 13){
            nama = "POLIKLINIK SARAF";
            dokter = "dr.Hendry Wijaya, Sp.S";
        }
        else
        {
            printf("\t\tMenu Tidak Tersedia!\n");
        }
    dataPasienPoli(nama, dokter, n, choice);
}

//FUNGSI INPUT DATA PASIEN POLI DAN ANTREAN
int dataPasienPoli(char* nama, char* dokter, int n, int choice)
{
    char alamat[50], tgl[50], name[35],jk[30],kl[50],umur[10],no[15], bpjs[20];
    printf("\n\t\t\t\t*** %s **\n", nama);
    printf("NAMA DOKTER : %s\n", dokter);
    getchar();
    printf("TANGGAL BEROBAT : ");fgets(tgl, sizeof(tgl), stdin);
    printf("NAMA PASIEN : ");fgets(name, sizeof(name), stdin);
    printf("NO BPJS : ");fgets(bpjs, sizeof(bpjs), stdin);
    printf("UMUR : ");fgets(umur, sizeof(umur), stdin);
    printf("JENIS KELAMIN : ");fgets(jk, sizeof(jk), stdin);;
    printf("ALAMAT : ");fgets(alamat, sizeof(alamat), stdin);
    printf("NO HP : ");fgets(no, sizeof(no), stdin);
    printf("KELUHAN : ");fgets(kl, sizeof(kl), stdin);
    getch();
    getchar();
}

//LAYANAN LABORATORIUM
int pilihanLaboratorium()
{
    system("cls");
    printf("\t\t\t***00o SELAMAT DATANG DI PROGRAM LABORATORIUM o00*\n");
    printf("\t\t\t**00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n");
    printf("\t\t\t===============================================================\n\n");
    int lab;
    printf("JENIS PEMERIKSAAN LABORATORIUM RSU ARDI WIRAMA\n\n");
    printf("1. PEMERIKSAAN DARAH\n");
    printf("2. PEMERIKSAAN URINE LENGKAP (RUTIN+SEDIMEN\n");
    printf("3. ELEKTROKARDIOGRAM (EKG)\n");
    printf("4. PEMERIKSAAN NARKOBA\n");
    printf("5. PEMERIKSAAN HIV\n");
    printf("6. PEMERIKSAAN KIMIA\n");
    printf("7. TEST GLUKOSA RAPID\n");
    printf("8. PEMERIKSAAN FESES LENGKAP (RUTIN+pH+REDUKSI)\n");
    printf("9. PEMERIKSAAN HEMATOLOGI\n");
    printf("10.PEMERIKSAAN KEHAMILAN\n");
    printf("0. KEMBALI\n");
    printf("SILAHKAN MASUKKAN PILIHAN ANDA :");
    scanf("%d", &lab);
    return(lab);
}
//LAYANAN RADIOLOGI
int pilihanRadiologi()
{
    system("cls");
    printf("\t\t\t***00o SELAMAT DATANG DI PROGRAM RADIOLOGI o00*\n");
    printf("\t\t\t**00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n");
    printf("\t\t\t===============================================================\n\n");
    int rad;
    printf("JENIS PEMERIKSAAN RADIOLOGI RSU ARDI WIRAMA\n\n");
    printf("1. RADIOGRAFI ATAU RONTGEN\n");
    printf("2. ULTRASONOGRAFI\n");
    printf("3. FLUOROSKOPI\n");
    printf("4. MRI (Magnetic Resonance Imaging)\n");
    printf("5. MAMMOGRAM\n");
    printf("6. PENCITRAAN NUKLIR\n");
    printf("7. CT (Computed Tomography)\n");
    printf("0. KEMBALI\n");
    printf("SILAHKAN MASUKKAN PILIHAN ANDA :");
    scanf("%d", &rad);
    return(rad);
}

int main(){
    menuLogin();
    while(1){
        int pil, jalur, poli, n, choice, lab, rad;
        pil = pilihanPelayanan();
        if (pil == 1)
        {//layanan rawat inap
             jalur = pilihanJalurLayanan();
            if (jalur == 3)
            {
                continue;
            }
        }
        else if(pil == 2){
            //layanan rawat jalan
                poli = pilihanPoliklinik();
                if (poli == 0)
            {
                continue;
            }
                poli = pilihanPoliklinik();
                if(poli != 0){
                    poliklinik(poli,n,choice);
                }else
                {
                    break;
                }
        }
        else if(pil == 3)
        { //layanan IGD
           printf("Menu Belum Tersedia");
        }
       else if(pil == 4)
        { //LAYANAN FARMASI
            jalur = pilihanJalurLayanan();
            if (jalur == 3)
            {
                continue;
            }
        }
        else if(pil == 5)
        { //LAYANAN LABORATORIUM
            jalur = pilihanJalurLayanan();
            if (jalur == 3)
            {
                continue;
            }
            lab = pilihanLaboratorium();
            if (lab == 0){
                continue;
            }
        }
        else if(pil == 6)
        { //LAYANAN RADIOLOGI
            jalur = pilihanJalurLayanan();
            if (jalur == 3)
            {
                continue;
            }
           rad = pilihanRadiologi();
                if (rad == 0)
            {
                continue;
            }
        }
        else if(pil == 7)
        { //KELUAR
            exit(0);
        }
        else
        {
            printf("Menu Salah");
        }
    }
    return(0);
}

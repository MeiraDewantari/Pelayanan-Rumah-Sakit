#include <stdio.h> //digunakan untuk standar input dan output
#include <stdlib.h>
#include <conio.h> //digunakan untuk fungsi delay(),getch(),gotoxy(),dll.
#include <string.h> //digunakan untuk fungsi strcmp(),strcpy(),strlen(),dll.
#include <ctype.h>//digunakan untuk toupper(), tolower(),etc
#include <windows.h>
#define MAX 100

//deklarasi fungsi
void welcome(void); //dibuat oleh Meira +Widi
void title(void);   //dibuat oleh Meira
void mainMenu(void);//Meira, Widi, Rasky
void pasienn(void);//dibuat oleh Meira
void admin(void);//dibuat oleh Meira
void antrean(void);//dibuat oleh Meira
void keluar(void);//dibuat oleh Meira
void IGD(void);//dibuat oleh Meira
void insert(int);//dibuat oleh Meira
void eliminate();//dibuat oleh Meira
void create();//dibuat oleh Meira
void check(int);//dibuat oleh Meira
void add();//dibuat oleh Meira
void view();//dibuat oleh Meira
void del();//dibuat oleh Meira
void rawatInap(void);//dibuat oleh Rasky
int queueArray[MAX];
int front= -1, rear= -1;
int n,i,j=0,a=0,sum=0,g,flag,num;
int pilihanPelayanan(void);//dibuat oleh Widi
int pilihanJalurLayanan();//dibuat oleh Widi
int pilihanPoliklinik();//dibuat oleh Widi
int poliklinik(int poli);//dibuat oleh Widi
int dataPasienPoli(char* nama, char* dokter);//dibuat oleh Widi
int piihanMenuFarmasi();//dibuat oleh Widi
int farmasi(int m, int jalur);//dibuat oleh Widi
int dataFarmasi(char* dokter, int jasa, int jalur);//dibuat oleh Widi
int pilihanLaboratorium();//dibuat oleh Widi
int laboratorium(int lab, int jalur);//dibuat oleh Widi
int dataPasienLab(char* nama, int harga, int jalur);//dibuat oleh Widi
int pilihanRadiologi();//dibuat oleh Widi
int radiologi(int rad, int jalur);//dibuat oleh Widi
int dataPasienRad(char* nama, int harga, int jalur);//dibuat oleh Widi

int total;
int vvip=3, vip=2, gen=1;
int hari;
char setuju;
char sip = 0;
int PL;
int i, status=0;
struct pasien
{
    char nama[30];
    char sakit[30];
    char jk;
    char alm[50];
    char dokter[50];
    char telp[15];
    int umur;
};
struct pasien  pasien,temp_c;
struct Rumah_sakit
{
    char nama[50];
    char alamat[100];
    int tggi[5], brt[5];
    char golda[3];
    char ayah[50];
    char ibu[50];
};
void gotoxy(short x, short y) {
COORD pos = {x, y};//sets co-ordinates in (x,y).
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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
        printf("\n\n\n\t\t\t\tAntrian penuh!");
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
void eliminate(int data)
{
    int i;

    if ((front==-1) && (rear==-1))
    {
        printf("\n\n\n\t\t\t\tAntrean kosong!");
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
    printf("\n\n\n\t\t\t\t%d tidak ditemukan di dalam antrean.", data);
}

/* Funngsi untuk menampilkan nomor antrean */
void display() //oleh Meira
{
    if ((front == -1) && (rear == -1))
    {
        printf("\n\n\n\t\t\t\tAntrean kosong!");
        return;
    }

    for (; front <= rear; front++)
    {
        printf("\n\t\t\t\t%d ", queueArray[front]);
    }

    front = 0;
}
/* ************************************************* Menu Kop ********************************************* */
void title(void)
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t       RSU ARDI WIRAMA         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ************************************************* Menu Keluar ********************************************* */
void keluar(void)
{
	system("cls");
	printf("\n\n\n\n\n\t\t\t\tTerima Kasih Atas Kepercayaan Anda Terhadap Layanan Kami :)");
	getch();
    exit(1);
}
/* ************************************** Login Pasien *******************************************/
void pasienn(void)
{
    system("cls");
    int ulang;
    char uname[12] = "pasienRSUAW", passw[5] = "1234";
    char u[12], p[5];

    printf ("\n\n\t\t----------------------------------------------------------------------------------");
    printf ("\n\n\n\t\t\tSILAKAN LOGIN DENGAN MENGGUNAKAN USERNAME DAN PASSWORD YANG SESUAI\n");
    printf ("\n\n\t\t----------------------------------------------------------------------------------");
    while (ulang<3){
    printf ("\n\n\t\t\t\t\t  username : "); scanf ("%s", &u);
    printf ("\n\t\t\t\t\t  password : "); scanf ("%s", &p);
        if (strcmp (uname, u) == 0 && strcmp (passw, p) == 0){
            break;
        }else{
            printf ("\n\n\t\t\t\t\tUsername/Password Anda salah!\n\n");
            ulang++;
            }
        }
        if (ulang<3){
            printf("\n\n\t\t\t\t\t\tAkses diterima!");
            printf("\n\n\t\t\t\t\t");
            system("pause");
        }else{
            printf ("\n\t\t\tAkses ditolak! Anda sudah melebihi batasan dalam validasi pengguna.\n");
            exit (1);
        }
}
/* ************************************** Login Admin *******************************************/
void admin(void)
{
    system("cls");
    int ulang;
    char username[6] = "RSUAW", password [10] = "202834";
    char user[6], pass[10];

    printf ("\n\n\t\t----------------------------------------------------------------------------------");
    printf ("\n\n\n\t\t\tSILAKAN LOGIN DENGAN MENGGUNAKAN USERNAME DAN PASSWORD YANG SESUAI\n");
    printf ("\n\n\t\t----------------------------------------------------------------------------------");
    while (ulang<3){
    printf ("\n\n\t\t\t\t\t  username : "); scanf ("%s", &user);
    printf ("\n\t\t\t\t\t  password : "); scanf ("%s", &pass);
        if (strcmp (username, user) == 0 && strcmp (password, pass) == 0){
            break;
        }else{
            printf ("\n\n\t\t\t\t\tUsername/Password Anda salah!\n\n");
            ulang++;
            }
        }
        if (ulang<3){
            printf("\n\n\t\t\t\t\t\tAkses diterima!");
            printf("\n\n\t\t\t\t\t");
            system("pause");
        }else{
            printf ("\n\t\t\tAkses ditolak! Anda sudah melebihi batasan dalam validasi pengguna.\n");
            exit (1);
        }
}
/* ************************************************* Menu Selamat Datang ********************************************* */
void welcome(void)
{
	printf("\n\n\n\n\n\t\t###########################################################\n");
    printf("\t\t  ========================================================\n\n");
    printf("\t\t\t    SELAMAT DATANG DI SISTEM INFORMASI\n");
    printf("\t\t\t       RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\t   JL.PEGANGSAAN BARAT NO.5 KOTA MALANG\n");
    printf("\t\t\t      NOMOR TELEPON: 0361 2457 8897\n");
    printf("\t\t    SENYUM ANDA HARAPAN KAMI,KESEMBUHAN ANDA TUJUAN KAMI\n\n");
    printf("\t\t  ========================================================");
	printf("\n\t\t############################################################");
	printf("\n\n\n\n\n Tekan sembarang untuk melanjutkan......");
	getch();
	system("cls");

}


/* ************************************** Layanan RSUAW *******************************************/
int pilihanPelayanan(void)
{
    system ("cls");
    int pil;
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM PILIHAN PELAYANAN o00***\n\n");
    printf("\t\t\t              ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
        printf("\n\t\t\t\tPILIH PELAYANAN RUMAH SAKIT YANG TERSEDIA\n\n");
        printf("\n\t\t\t\t1. RAWAT INAP      5. LABORATORIUM\n");
        printf("\n\t\t\t\t2. RAWAT JALAN     6. RADIOLOGI\n");
        printf("\n\t\t\t\t3. IGD             7. KELUAR\n");
        printf("\n\t\t\t\t4. FARMASI\n");
        printf("\n\t\t\t\tMASUKAN PILIHAN ANDA : ");
        scanf("%d", &pil);
        return(pil);
}
/* ************************************** Jalur Pelayanan *******************************************/
int pilihanJalurLayanan(void)
{
    system("cls");
    int jalur;
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM JALUR PELAYANAN o00***\n\n");
    printf("\t\t\t              ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
    printf("\n\t\t\t\tPILIH JALUR PELAYANAN YANG ANDA GUNAKAN\n");
    printf("\n\t\t\t\t1. UMUM\n");
    printf("\n\t\t\t\t2. BPJS\n");
    printf("\n\t\t\t\t3. KEMBALI\n");
    printf("\n\t\t\t\tMASUKKAN PILIHAN ANDA : ");
    scanf("%d", &jalur);
    return(jalur);
}
/* ************************************** Rawat Inap *******************************************/
void rawatInap(void)
{
    system("cls");
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM RAWAT INAP o00***\n\n");
    printf("\t\t\t          ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
        struct Rumah_sakit pasien;
        {
            printf("\t\t\t\tMasukkan Identitas Pasien di bawah ini : \n");
            printf("\n\t\t\t\tNama : ");
            scanf("%s",pasien.nama);
            printf("\n\t\t\t\tAlamat : ");
            scanf("%s",pasien.alamat);
            printf("\n\t\t\t\tGolongan darah : ");
            scanf("%s",pasien.golda);
            printf("\n\t\t\t\tTinggi Badan : ");
            scanf("%d",pasien.tggi);
            printf("\n\t\t\t\tBerat badan : ");
            scanf("%d",pasien.brt);
            system("cls");
            printf("\n\t\t\t\t========================================\n");
            printf("\t\t\t\tMasukkan Nama Orang tua Pasien...\n");
            printf("\n\t\t\t\tAyah : ");
            scanf("%s",pasien.ayah);
            printf("\n\t\t\t\tIbu : ");
            scanf("%s",pasien.ibu);
            getch();
        };
    //Pada tahap ini untuk Pemesanan Kamar say..
        system("cls");
        int kamar;
            FILE *frs;
            printf("\n\t\t\t\t========================================\n");
            printf("\n\t\t\t\tSekarang Anda Memasuki tahap selanjutnya..\n");
            printf("\n\t\t\t\t>>PEMESANAN KAMAR<<\n");
            printf("\n\t\t\t\tPilihlah Kelas Pemesanan kamar : \n");
            printf("\n\t\t\t\t1. Kamar VVIP\n\n\t\t\t\t2. Kamar VIP\n\n\t\t\t\t3. General");
            printf("\n\n\t\t\t\tMasukkan pilihan Anda : ");
            kamar = getch();

        switch (kamar)
        {
        case '1':
            printf("\n\t\t\t\tAnda telah memilih kamar VVIP\n");
            printf("\n\t\t\t\tHarga sewa kamar Rp 3.000.000,00 @hari\n");
            printf("\n\t\t\t\tApakah Anda setuju? (Y/N)\n");
            setuju = getch();
        switch (setuju)
        {
        case 'Y':
        frs = fopen("data.txt","a+");
            printf("\n\t\t\t\tBerapa hari hari Pasien dirawat : ");
            scanf("%d",&hari);
            total=hari*vvip;
            printf("\n\t\t\t\tTotal Biaya Yang Pasien Bayar : %d juta",total);
            fprintf(frs,"\n\t\t\t\tAnda telah memilih kamar VIP\n\t\t\t\tHarga sewa kamar Rp 3.000.000,00 @hari\n\t\t\t\tselama %d hari\n\t\t\t\tdengan biaya %d juta rupiah\n\t\t\t\t",hari,total);
        fclose (frs);
        getch();
        break;

        case 'N':
            printf("\n\t\t\t\t========================================\n");
            printf("\n\t\t\t\tAnda Membatalkan Pesanan Kamar VVIP..");
            printf("\n\t\t\t\t========================================\n");
        break;
        };
        break;

        case '2':
            printf("\n\t\t\t\tAnda telah memilih kamar VIP\n");
            printf("\n\t\t\t\tHarga sewa kamar Rp 2.000.000,00 @hari\n");
            printf("\n\t\t\t\tApakah Anda setuju? (Y/N)\n");
            setuju = getch();
        switch (setuju)
        {
        case 'Y':
        frs = fopen("data.txt","a+");
            printf("\n\t\t\t\tBerapa hari hari Pasien dirawat : ");
            scanf("%d",&hari);
            total=hari*vip;
            printf("\n\t\t\t\tTotal Biaya Yang Pasien Bayar : %d juta",total);
            fprintf(frs,"\n\t\t\t\tAnda telah memilih kamar VIP\n\t\t\t\tHarga sewa kamar Rp 2.000.000,00 @hari\n\t\t\t\tselama %d hari\n\t\t\t\tdengan biaya %d juta rupiah\n\t\t\t\t",hari,total);
        fclose (frs);
        getch();
        break;

        case 'N':
            printf("\n\n\t\t\t\t========================================\n");
            printf("\n\t\t\t\tAnda Membatalkan Pesanan Kamar VIP..");
            printf("\n\t\t\t\t========================================\n");
        break;
        };
        break;

        case '3':
            printf("\n\n\t\t\t\tAnda telah memilih kamar General\n");
            printf("\n\t\t\t\tHarga sewa kamar Rp 1.000.000,00 @hari\n");
            printf("\n\t\t\t\tApakah Anda setuju? (Y/N)\n");
            setuju = getch();
        switch (setuju)
        {
        case 'Y':
        frs = fopen("data.txt","a+");
            printf("\n\t\t\t\tBerapa hari Pasien dirawat : ");
            scanf("%d",&hari);
            total =hari*gen;
            printf("\n\t\t\t\tTotal Biaya Yang Pasien Bayar : %d juta",total);
        fprintf(frs,"\n\n\t\t\t\tAnda telah memilih kamar VIP\n\t\t\t\tHarga sewa kamar Rp 1.000.000,00 @hari\n\t\t\t\tselama %d hari\n\t\t\t\tdengan biaya %d juta rupiah\n\t\t\t\t",hari,total);
        getch();
        fclose (frs);
        break;

        case 'N':
            printf("\n\n\t\t\t\t========================================\n");
            printf("\n\t\t\t\tAnda Membatalkan Pesanan Kamar General..");
            printf("\n\n\t\t\t\t========================================\n");
        break;
        };
        break;
        }getch();
}
/* ************************************** Rawat Jalan *******************************************/
int pilihanPoliklinik(void)
{
    system("cls");
    int poli;
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM RAWAT JALAN o00***\n\n");
    printf("\t\t\t          ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
    printf("\n\n\t\t\t\tSILAKAN PILIH POLIKLINIK YANG ANDA INGINKAN\n\n");
    printf("\n\t\t\t1. POLIKLINIK UMUM            8. POLIKLINIK PSIKIATRI\n");
    printf("\n\t\t\t2. POLIKLINIK ANAK            9. POLIKLINIK KANDUNGAN DAN KEBIDANAN (obgyn)\n");
    printf("\n\t\t\t3. POLIKLINIIK BEDAH          10. POLIKLINIK PENYAKIT KULIT DAN KELAMIN\n");
    printf("\n\t\t\t4. POLIKLINIK GIGI            11. POLIKLINIK PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru)\n");
    printf("\n\t\t\t5. POLIKLINIK THT             12. POLIKLINIK JANTUNG\n");
    printf("\n\t\t\t6. POLIKLINIK MATA            13. POLIKLINIK SARAF\n");
    printf("\n\t\t\t7. POIKLINIK PENYAKIT DALAM   0. KEMBALI\n");
    printf("\n\n\t\t\tSILAHKAN MASUKKAN PILIHAN ANDA : ");
    scanf("%d", &poli);
    return(poli);
}
/* ************************************** Menu Antrean Admin *******************************************/
void antrean()
{
    system ("cls");
    int choice;
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o MENU ANTREAN RUMAH SAKIT UMUM ARDI WIRAMAo00***\n");
    printf("\t\t\t===============================================================\n\n");
    printf("\n\n\n\t\t\t\tKelola Nomor Antrean\n");
    printf("\n\t\t\t\t1. Tambah nomor antrean\n");
    printf("\n\t\t\t\t2. Hapus nomor antrean\n");
    printf("\n\t\t\t\t3. Tampilkan nomor antrean\n");
    printf("\n\t\t\t\t4. Tambah data pasien\n");
}

typedef struct{
    int data[100];
    char data1[100][20];
    char data2[100][30];
    char data3[100][15];
    int depan, belakang;
}Queue;
Queue antrian;
Queue no;
Queue nama;
Queue poli;

int pilihan, data, i, j;
char data1[20], data2[30], data3[15];

int isEmpty() //dibuat oleh Meira
{
            if (antrian.belakang==-1)
                        return 1;
            else
                        return 0;
}

int isFull() //dibuat oleh Meira
{
            if(antrian.belakang==100)
                        return 1;
            else
                        return 0;
}

void Enqueue(int data, char data1[20], char data2[30], char data3[15]) //dibuat oleh Meira
{
            if(isEmpty()==1)
            {
                        antrian.depan=antrian.belakang=0;
                        nama.depan=nama.belakang=0;
                        poli.depan=poli.belakang=0;
                        no.depan=no.belakang=0;
                        antrian.data[antrian.belakang]=data;
                        for(i=0;i<20;i++)
                        {nama.data1[nama.belakang][i]=data1[i];}
                        for(i=0;i<30;i++)
                        {poli.data2[poli.belakang][i]=data2[i];}
                        for(i=0;i<15;i++)
                        {no.data3[no.belakang][i]=data3[i];}
                        printf("\n\n\t\t\t\tData Anda Telah Masuk. Silakan Menunggu Dipanggil!");
            }
            else if(isFull()==0)
            {
                        antrian.belakang++;
                        nama.belakang++;
                        poli.belakang++;
                        no.belakang++;
                        antrian.data[antrian.belakang]=data;
                        for(i=0;i<20;i++)
                        {nama.data1[nama.belakang][i]=data1[i];}
                        for(i=0;i<30;i++)
                        {poli.data2[poli.belakang][i]=data2[i];}
                        for(i=0;i<15;i++)
                        {no.data3[no.belakang][i]=data3[i];}
                        printf("\n\n\t\t\t\tData Anda Telah Masuk. Silakan Menunggu Dipanggil!");
            }
}
void buat()
{
            antrian.depan=antrian.belakang=-1;
            nama.depan=nama.belakang=-1;
            poli.depan=poli.belakang=-1;
            no.depan=no.belakang=-1;
}
/* ************************************** Menu Antrean Pasien *******************************************/
void pilihanPasien() //dibuat oleh Meira
{
    system("cls");
    int n;
    buat();
    n=1;
    do{system("cls");
        puts("\n\n\t\t\t\tMENU ANTREAN PASIEN");
        puts("\n\t\t\t\t1. Daftar Antrean");
        puts("\n\t\t\t\t2. Lihat Antrean");
        puts("\n\t\t\t\t3. Batalkan");
        printf("\n\t\t\t\tMasukkan Pilihan Anda : "); scanf("%i", &pilihan);
        switch(pilihan){
            case 1:
                printf("\n\n\t\t\t\tNomor Antrean Anda Adalah %i\n", n);
                data=n;
                printf("\n\t\t\t\tNomor Rekam Medis(apabila memiliki) :"); scanf("%s",&data3);
                printf("\n\t\t\t\tNama Lengkap(gunakan tanda (_) untuk spasi) :"); scanf("%s",&data1);
                printf("\n\t\t\t\tKonfirmasi Jenis Pelayanan(gunakan tanda (_) untuk spasi) :"); scanf("%s",&data2);
                Enqueue(data, data1, data2, data3);
                n++;
            break;
            case 2:
                if(isEmpty()==1){
                        printf("\n\n\t\t\t\tAntrean kosong!");
                break;
                }
                 puts("\n\n\t\t\t\tANTREAN           NO REKAM MEDIS             NAMA             PELAYANAN");
                 for(i=antrian.depan;i<=antrian.belakang;i++)
                    {
                        printf("\n\n\t\t\t\t%i                    %s                       %s                 %s\n", antrian.data[i], no.data3[i], nama.data1[i], poli.data2[i]);
                    }
                break;
            case 3:
                keluar();
            break;
            default:
                puts("\n\n\t\t\t\tHarap pilih sesuai dengan pilihan yang tersedia!\n");
            break;
        }getch();
    }while(pilihan!=4);
}
/* ************************************** Menu di dalam Rawat Jalan *******************************************/
int poliklinik(int poli)
{
        system("cls");
        int dataPasienPoli( char* nama, char* dokter);
        char* nama;
        char* dokter;
        if(poli == 1){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK UMUM";
            dokter = "dr.Amelia Venusia";
        }
        else if (poli == 2){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK ANAK";
            dokter = "dr.Jerry Putra, Sp.A";
        }
        else if (poli == 3){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK BEDAH";
            dokter = "dr.Ferdinan Geneva, Sp.B";
        }
        else if (poli == 4){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK GIGI";
            dokter = "drg.Anisa Rahmantari";
        }
        else if (poli == 5){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK THT";
            dokter = "dr.Reyhan Fernandus, Sp.THT";
        }
        else if (poli == 6){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK MATA";
            dokter = "dr.Anggi Maharani, Sp.M";
        }
        else if (poli == 7){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PENYAKIT DALAM";
            dokter = "dr.Jhonny Robert, Sp.PD";
        }
        else if (poli == 8){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PSIKIATRI";
            dokter = "dr.Wahyu Saputra, Sp.KJ";
        }
        else if (poli == 9){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK KANDUNGAN DAN KEBIDANAN (obgyn)";
            dokter = "dr.Andrea Putra, Sp.OG";
        }
        else if (poli == 10){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PENYAKIT KULIT DAN KELAMIN";
            dokter = "dr.Dita Cahya, Sp.KK";
        }
        else if (poli == 11){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru)";
            dokter = "dr.Vina Devianti, Sp.P";
        }
        else if (poli == 12){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK JANTUNG";
            dokter = "dr.Gita Prananda, Sp.JP";
        }
        else if (poli == 13){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK SARAF";
            dokter = "dr.Hendry Wijaya, Sp.S";
        }
        else if (poli == 0){
            pilihanPelayanan();
        }
        else
        {
            printf("\n\n\t\t\t\tMenu Tidak Tersedia!\n");
        }
    dataPasienPoli(nama, dokter);
    int n, choice;
        create();
                while (1) //PEMANGGILAN FUNGSI
                {
                    antrean();
                    printf("\n\t\t\t\tMasukkan pilihan Anda : ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\n\t\t\t\tMasukkan nomor antrean baru: ");
                        scanf("%d",&n);
                        insert(n);
                        break;
                    case 2:
                        printf("\n\t\t\t\tMasukkan nomor antrean lama: ");
                        scanf("%d",&n);
                        eliminate(n);
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        dataPasienPoli(nama, dokter);
                        break;
                    default:
                        printf("\n\n\t\t\t\tPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
                    }
lainnya:
  printf("\n\n\t\t\t\tPress any key to continue...");
  getch();
  printf("\n\n\t\t\t\tKelola lagi menu ini[Y/N]?? ");
  scanf(" %c",&sip);
  printf("\n\n\t\t\t\t");
    if (toupper(sip)=='Y')
    {
        antrean();
    }else if(toupper(sip)=='N')
    {
        keluar();
    }else
    {
        printf("\n\n\t\t\t\tPilihan tidak tersedia.\n");
        goto lainnya;
    }

    }
        return(poli);
}

/* ************************************** Data Pasien Poli *******************************************/
int dataPasienPoli(char* nama, char* dokter)
{
    char alamat[50], tgl[50], name[35],jk[30],kl[50],umur[10],no[15], bpjs[20];
    printf("\n\t\t\t\t*** %s **", nama);
    printf("\n\n\n\t\t\t\tNAMA DOKTER     : %s\n", dokter);
    getchar();
    printf("\n\t\t\t\tTANGGAL BEROBAT : ");fgets(tgl, sizeof(tgl), stdin);
    printf("\n\t\t\t\tNAMA PASIEN     : ");fgets(name, sizeof(name), stdin);
    printf("\n\t\t\t\tNO BPJS         : ");fgets(bpjs, sizeof(bpjs), stdin);
    printf("\n\t\t\t\tUMUR            : ");fgets(umur, sizeof(umur), stdin);
    printf("\n\t\t\t\tJENIS KELAMIN   : ");fgets(jk, sizeof(jk), stdin);;
    printf("\n\t\t\t\tALAMAT          : ");fgets(alamat, sizeof(alamat), stdin);
    printf("\n\t\t\t\tNO HP           : ");fgets(no, sizeof(no), stdin);
    printf("\n\t\t\t\tKELUHAN         : ");fgets(kl, sizeof(kl), stdin);
}
/* ************************************** Menu di dalam Rawat Jalan II *******************************************/
int poliklinik1(int poli)
{
        system("cls");
        int dataPasienPoli( char* nama, char* dokter);
        char* nama;
        char* dokter;
        if(poli == 1){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK UMUM";
            dokter = "dr.Amelia Venusia";
        }
        else if (poli == 2){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK ANAK";
            dokter = "dr.Jerry Putra, Sp.A";
        }
        else if (poli == 3){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK BEDAH";
            dokter = "dr.Ferdinan Geneva, Sp.B";
        }
        else if (poli == 4){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK GIGI";
            dokter = "drg.Anisa Rahmantari";
        }
        else if (poli == 5){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK THT";
            dokter = "dr.Reyhan Fernandus, Sp.THT";
        }
        else if (poli == 6){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK MATA";
            dokter = "dr.Anggi Maharani, Sp.M";
        }
        else if (poli == 7){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PENYAKIT DALAM";
            dokter = "dr.Jhonny Robert, Sp.PD";
        }
        else if (poli == 8){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PSIKIATRI";
            dokter = "dr.Wahyu Saputra, Sp.KJ";
        }
        else if (poli == 9){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK KANDUNGAN DAN KEBIDANAN (obgyn)";
            dokter = "dr.Andrea Putra, Sp.OG";
        }
        else if (poli == 10){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PENYAKIT KULIT DAN KELAMIN";
            dokter = "dr.Dita Cahya, Sp.KK";
        }
        else if (poli == 11){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru)";
            dokter = "dr.Vina Devianti, Sp.P";
        }
        else if (poli == 12){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK JANTUNG";
            dokter = "dr.Gita Prananda, Sp.JP";
        }
        else if (poli == 13){
            printf("\n\n\t\t\t\t");
            nama = "POLIKLINIK SARAF";
            dokter = "dr.Hendry Wijaya, Sp.S";
        }
        else if (poli == 0){
            pilihanPelayanan();
        }
        else
        {
            printf("\n\n\t\t\t\tMenu Tidak Tersedia!\n");
        }
    dataPasienPoli(nama, dokter);
    pilihanPasien();
}
/* ************************************** Menambahkan Data Pasien IGD *******************************************/
void add()
{
	system("cls");
	title();
	FILE*pointer;//file pointer
	pointer = fopen("DataIGD", "a");//buka file dalam mode menulis
	printf("\n\n\t\t\t\tMASUKKAN IDENTITAS PASIEN DENGAN BENAR!!!\n");
	printf("\n\t\t\t\tcatatan: untuk nama yang lebih dari satu kata, tuliskan dengan format seperti: FarrelBima!");

	/* ************************** Nama Pasien *********************************** */
	nama:
	printf("\n\t\t\tNama : ");
	scanf("%s",pasien.nama);
	pasien.nama[0] = toupper(pasien.nama[0]);
	if(strlen(pasien.nama) > 30 || strlen(pasien.nama) < 2)
	{
		printf("\n\t\t\tBatas jumlah karakter untuk nama pasien adalah >2 dan <30");
		goto nama;
	}
	else
	{
		for (i = 0; i < strlen(pasien.nama); i++)
		{
			if (isalpha(pasien.nama[i]))
			{
				status = 1;
			}
			else
			{
				status = 0;
				break;
			}
		}
		if(!status)
		{
			printf("\n\t\t\tTerdapat karakter yang salah pada data nama pasien. Harap cek kembali!\n");
			goto nama;
		}
	}
/* ******************************************* Jenis Kelamin ************************************************************** */
	do
	{
	    printf("\n\t\t\tJenis Kelamin [P/L]: ");
		scanf(" %c",&pasien.jk);
		if(toupper(pasien.jk) == 'P'|| toupper(pasien.jk) == 'L')
		{
            PL = 1;
		}
		else
		{
		PL =0;
		}
        if(!PL)
	    {
	    	printf("\n\t\t\tHarap input hanya karakter P atau L!");
    	}
	 }	while(!PL);
/* ***************************************** Umur Pasien ********************************************************************** */
    printf("\n\t\t\tUmur :");
    scanf(" %i",&pasien.umur);
/* **************************************** Alamat Pasien ******************************************************************* */
    do
    {
    alamat:
    printf("\n\t\t\tAlamat : ");
    scanf("%s",pasien.alm);
    pasien.alm[0] = toupper(pasien.alm[0]);
    if(strlen(pasien.alm) > 50 || strlen(pasien.alm) < 5)
	{
		printf("\n\t\t\tBatas jumlah karakter untuk alamat pasien adalah >5 dan <50");
		goto alamat;
	}

}while(!status);
/* ******************************************* Telepon Pasien ***************************************** */
do
{
	telepon:
    printf("\n\t\t\tTelepon : ");
    scanf("%s",pasien.telp);

		for (i = 0; i < strlen(pasien.telp); i++)
		{
			if (!isalpha(pasien.telp[i]))
			{
				status = 1;
			}
			else
			{
				status = 0;
				break;
			}
		}
		if(!status)
		{
			printf("\n\t\t\tTerdapat karakter yang salah pada data telepon pasien. Harap cek kembali!\n");
			goto telepon;
		}
	} while(!status);
/* ********************************************************* Penyakit Pasien *********************************************** */
    sakit:
    printf("\n\t\t\tPenyakit : ");
    scanf("%s",pasien.sakit);
/* ********************************************** Dokter yang Menangani **************************************** */
	dokter:
    printf("\n\t\t\tDokter :");
    scanf("%s",pasien.dokter);
    pasien.dokter[0] = toupper(pasien.dokter[0]);
    if(strlen(pasien.dokter) > 50 || strlen(pasien.dokter) < 3)
	{
		printf("\n\t\t\tBatas jumlah karakter untuk alamat pasien adalah >3 dan <50");
		goto dokter;
	}

    fprintf(pointer," %s %c %i %s %s %s %s \n", pasien.nama, pasien.jk, pasien.umur, pasien.alm, pasien.telp, pasien.sakit, pasien.dokter);
    printf("\n\n\t\t\t.... DATA BERHASIL MASUK KE SISTEM ...");
    fclose(pointer);//menutup file pointer
lainnya:
  printf("\n\n\t\t\t\tPress any key to continue...");
  getch();
  printf("\n\n\t\t\t\tTambah data pasien lainnya [Y/N]?? ");
  scanf(" %c",&sip);
    if (toupper(sip)=='Y')
    {
        add();
    }else if(toupper(sip)=='N')
    {
        IGD();
    }else
    {
        printf("\n\n\t\t\t\tPilihan tidak tersedia.\n");
        goto lainnya;
    }
}
/* ************************************** Menampilkan Data Pasien IGD *******************************************/
void view()
{
 	int kolom;
	system("cls");
	title();
	FILE *pointer;
	pointer = fopen("DataIGD", "r");
	printf("\n\t\t\t----- TAMPILAN IDENTITAS PASIEN IGD RSU ARDI WIRAMA -----\n");
	gotoxy(1,15);
		printf("Nama");
		gotoxy(20,15);
		printf("Jenis Kelamin");
		gotoxy(32,15);
		printf("Umur ");
		gotoxy(37,15);
		printf("Alamat");
		gotoxy(49,15);
		printf("Telepon");
		gotoxy(64,15);
		printf("Penyakit");
		gotoxy(88,15);
		printf("Dokter\n");
		printf("=================================================================================================================");
		kolom = 17;
		while(fscanf(pointer," %s %c %i %s %s %s %s \n", pasien.nama, &pasien.jk, &pasien.umur,
               pasien.alm, pasien.telp, pasien.sakit, pasien.dokter)!=EOF)
		{
			gotoxy(1,kolom);
			printf("%s",pasien.nama);
			gotoxy(20,kolom);
			printf("%c",pasien.jk);
			gotoxy(32,kolom);
			printf("%i",pasien.umur);
			gotoxy(37,kolom);
			printf("%s",pasien.alm);
			gotoxy(49,kolom);
			printf("%s",pasien.telp);
			gotoxy(64,kolom);
			printf("%s",pasien.sakit);
			gotoxy(88,kolom);
			printf("%s",pasien.dokter);
			kolom++;
		}
		fclose(pointer);
		getch();
		IGD();
}
/* ************************************** Menghapus Data Pasien IGD *******************************************/
void del(void)
{
    char nama[30];
	int data = 0;
	system("cls");
	title();// call Title function
	FILE *pointer, *pointer1;
	pointer1 = fopen("simpanDataIGD","w+");
	pointer = fopen("DataIGD","r");
	printf("\n\n\t\t\t----- HAPUS DATA PASIEN IGD RSU ARDI WIRAMA -----\n");
	gotoxy(12,8);
	printf("\nHapus berdasarkan nama pasien (masukkan nama pasien) : ");
	fflush(stdin);
	gets(nama);
	nama[0]=toupper(nama[0]);

	while (fscanf(pointer,"%s %c %i %s %s %s %s \n", pasien.nama, &pasien.jk, &pasien.umur,
               pasien.alm, pasien.telp, pasien.sakit, pasien.dokter)!=EOF)
	{
		if (strcmp(pasien.nama,nama)!=0)
		fprintf(pointer1,"%s %c %i %s %s %s %s \n", pasien.nama, &pasien.jk, &pasien.umur,
               pasien.alm, pasien.telp, pasien.sakit, pasien.dokter);
		else
		{
			printf("%s %c %i %s %s %s %s \n", pasien.nama, &pasien.jk, &pasien.umur,
               pasien.alm, pasien.telp, pasien.sakit, pasien.dokter);
			data = 1;
		}
	}//akhir perulangan while
	if(data == 0)
	{
		printf("\n\n\t\t\tData tidak ditemukan!");
		getch();
		IGD();
	}
	else
	{
		fclose(pointer);
		fclose(pointer);
		remove("DataIGD");
		rename("simpanDataIGD","DataIGD");
		printf("\n\n\t\t\t\tDATA BERHASIL DIHAPUS");
		getch();
		IGD();
	}
}
/* ************************************** Layanan IGD *******************************************/
void IGD(void)
{
    system ("cls");
    int choose;
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t         ***00o SELAMAT DATANG DI PROGRAM IGD o00*\n\n");
    printf("\t\t\t          **00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
    menuIGD:
    printf("\n\n\t\t\t\t\t1. Tambah data pasien IGD\n");
	printf("\n\t\t\t\t\t2. Tampilkan data pasien IGD\n");
	printf("\n\t\t\t\t\t3. Hapus data pasien IGD\n");
	printf("\n\t\t\t\t\t4. Keluar\n");
	printf("\n\t\t\t\t\tMasukkan Pilihan Anda : ");
	scanf("%i", &choose);

    switch(choose){
        case 1:
            add();
            break;
        case 2:
            view();
            break;
        case 3:
            del();
            break;
        case 4:
            keluar();
            break;
        default:
            printf("\n\n\t\t\t\tPilihan tidak tersedia. Silakan pilih ulang!");
            goto menuIGD;
    }
}
/* *************************************** Layanan Farmasi *******************************************/
int pilihanMenuFarmasi()
{
    system("cls");
    int m;
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM FARMASI o00***\n");
    printf("\t\t\t         ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
    printf("\n\n\n\t\t\t\tSILAKAN PILIH POLIKLINIK YANG ANDA GUNAKAN SEBELUMNYA\n\n");
    printf("\n\t\t1. UMUM                          8. PSIKIATRI\n");
    printf("\n\t\t2. ANAK                          9. KANDUNGAN DAN KEBIDANAN (obgyn)\n");
    printf("\n\t\t3. BEDAH                         10.PENYAKIT KULIT DAN KELAMIN\n");
    printf("\n\t\t4. GIGI                          11.PULMONOLOGI DAN KEDOKTERAN RESPIRASI (paru)\n");
    printf("\n\t\t5. THT                           12.JANTUNG\n");
    printf("\n\t\t6. MATA                          13.SARAF\n");
    printf("\n\t\t7. DALAM                         0. KEMBALI\n");
    printf("\n\n\t\tSILAHKAN MASUKKAN PILIHAN ANDA : ");
    scanf("%d", &m);
    return(m);
}

int farmasi(int m, int jalur)
{
        system("cls");
        char* dokter;
        int jasa;
            if(m == 1){
                dokter = "dr.Amelia Venusia";
                jasa = 150000;
            }else if (m == 2){
                dokter = "dr.Jerry Putra, SP.A";
                jasa = 160000;
            }else if (m == 3){
                dokter = "dr.Ferdinan Geneva, Sp.B";
                jasa = 200000;
            }else if (m == 4){
                dokter = "drg.Anisa Rahmantari";
                jasa = 170000;
            }else if (m == 5){
                dokter = "dr.Reyhan Fernandus, Sp.THT";
                jasa = 155000;
            }else if (m == 6){
                dokter = "dr.Anggi Maharani, Sp.M";
                jasa = 160000;
            }else if (m == 7){
                dokter = "dr.Jhonny Robert, Sp.PD";
                jasa = 175000;
            }else if (m == 8){
                dokter = "dr.Wahyu Saputra, Sp.KJ";
                jasa = 165000;
            }else if (m == 9){
                dokter = "dr.Andrea Putra, Sp.OG";
                jasa = 170000;
            }else if (m == 10){
                dokter = "dr.Dita Cahya, Sp.KK";
                jasa = 160000;
            }else if (m == 11){
                dokter = "dr.Vina Devianti, Sp.P";
                jasa = 160000;
            }else if(m == 12){
                dokter = "dr.Gita Prananda, Sp.JP";
                jasa = 175000;
            }else if (m == 13){
                dokter = "dr.Hendry Wijaya, Sp.S";
                jasa = 175000;
            }else if (m == 0){
                pilihanJalurLayanan();
            }else{
                printf("\t\tMenu Tidak Tersedia!\n");
                exit(2);}
            if (jalur==2) {
                jasa = 0.0;
            }
            int n, choice;
            create();
            while (2) //PEMANGGILAN FUNGSI
            {
                antrean();
                printf("\n\t\t\t\tMasukkan pilihan Anda : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("\t\t\t\tMasukkan nomor antrean baru: ");
                    scanf("%d",&n);
                    insert(n);
                    break;
                case 2:
                    printf("\n\t\t\t\tMasukkan nomor antrean lama: ");
                    scanf("%d",&n);
                    eliminate(n);
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    dataFarmasi(dokter, jasa, jalur);
                    break;
                default:
                    printf("\nPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
                }
lainnya:
  printf("\n\n\t\t\t\tPress any key to continue...");
  getch();
  printf("\n\n\t\t\tKelola lagi menu ini[Y/N]?? ");
  scanf(" %c",&sip);
    if (toupper(sip)=='Y')
    {
        antrean();
    }else if(toupper(sip)=='N')
    {
        keluar();
    }else
    {
        printf("\n\t\tPilihan tidak tersedia.\n");
        goto lainnya;
    }
    }
    return(m);
}
/* ************************************** Data Pasien Farmasi*******************************************/
int dataFarmasi(char* dokter, int jasa, int jalur)
{
    system("cls");
    printf("\t\t\t****00o SELAMAT DATANG DI PROGRAM FARMASI o00****\n");
    printf("\t\t\t  ****00o RUMAH SAKIT UMUM ARDI WIRAMA o00****\n");
    printf("\t\t\t========================================================\n\n");
    char alamat[50], tgl[50], name[35],jk[30],kl[50],umur[10],no[15], obat[20];
    float ho, total;
    printf("\n\t\t\tNAMA DOKTER : %s\n", dokter);
    getchar();
    printf("\n\t\t\tTANGGAL BEROBAT : ");fgets(tgl, sizeof(tgl), stdin);
    printf("\n\t\t\tNAMA PASIEN : ");fgets(name, sizeof(name), stdin);
    printf("\n\t\t\tUMUR : ");fgets(umur, sizeof(umur), stdin);
    printf("\n\t\t\tJENIS KELAMIN : ");fgets(jk, sizeof(jk), stdin);;
    printf("\n\t\t\tALAMAT : ");fgets(alamat, sizeof(alamat), stdin);
    printf("\n\t\t\tNO HP : ");fgets(no, sizeof(no), stdin);
    printf("\n\t\t\tKELUHAN : ");fgets(kl, sizeof(kl), stdin);
    printf("\n\t\t\tNAMA OBAT : ");fgets(obat, sizeof(obat), stdin);
    printf("\n\t\t\tHARGA OBAT :");scanf("%f", &ho);
    printf("\n\t\t\tJASA DOKTER : %d\n", jasa);
    if (jalur == 2){
        jasa = 0.0;
    }
    total=jasa+ho;
    printf("\n\t\t\tTOTAL BIAYA : %.2f\n", total);
    printf("\t\t\t========================TERIMA KASIH===========================\n");
    printf("\t\t\t======================SEMOGA LEKAS SEMBUH=============================\n\n");
    getch();
    getchar();
}
/* ************************************** Layanan Laboratorium *******************************************/
int pilihanLaboratorium()
{
    system("cls");
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM LABORATORIUM o00***\n\n");
    printf("\t\t\t          ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
    int lab;
    printf("\n\n\n\t\t\tJENIS PEMERIKSAAN LABORATORIUM RSU ARDI WIRAMA\n\n");
    printf("\n\t\t\t1. PEMERIKSAAN DARAH                            7. TEST GLUKOSA RAPID\n");
    printf("\n\t\t\t2. PEMERIKSAAN URINE LENGKAP (RUTIN+SEDIMEN)    8. PEMERIKSAAN FESES LENGKAP (RUTIN+pH+REDUKSI)\n");
    printf("\n\t\t\t3. ELEKTROKARDIOGRAM (EKG)                      9. PEMERIKSAAN HEMATOLOGI\n");
    printf("\n\t\t\t4. PEMERIKSAAN NARKOBA                          10. PEMERIKSAAN KEHAMILAN\n");
    printf("\n\t\t\t5. PEMERIKSAAN HIV                              0. KEMBALI\n");
    printf("\n\t\t\t6. PEMERIKSAAN KIMIA\n");
    printf("\n\n\t\t\tSILAHKAN MASUKKAN PILIHAN ANDA :");
    scanf("%d", &lab);
    return(lab);
}
/* ************************************** Menu di dalam Laboratorium *******************************************/
int laboratorium(int lab, int jalur)
{
        system("cls");
        int harga;
        char* nama;
        if(lab == 1){
            nama = "PEMERIKSAAN DARAH";
            harga = 50000;
        }
        else if (lab == 2){
            nama = "PEMERIKSAAN URINE";
            harga = 55000;
        }
        else if (lab == 3){
            nama = "ELEKTROKARDIOGRAM (EKG)";
            harga = 150000;
        }
        else if (lab == 4){
            nama = "PEMERIKSAAN NARKOBA";
            harga = 150000;
        }
        else if (lab == 5){
            nama = "PEMERIKSAAN HIV";
            harga = 150000;
        }
        else if (lab == 6){
            nama = "PEMERIKSAAN KIMIA";
            harga = 65000;
        }
        else if (lab == 7){
            nama = "TEST GULA RAPID";
            harga = 55000;
        }
        else if (lab == 8){
            nama = "PEMERIKSAAN FESES";
            harga = 60000;
        }
        else if (lab == 9){
            nama = "PEMERIKSAAN HEMATOLOGI";
           harga = 65000;
        }
        else if (lab == 10){
            nama = "PEMERIKSAAN KEHAMILAN";
            harga = 85000;
        }
       else if (lab == 0){
            pilihanPelayanan();
        }
        else
        {
           printf("Menu Tidak Tersedia!");
           exit(1);
        }
         if (jalur==2) {
            harga = 0.0;
        }
        int n, choice;
        create();
                while (1) //PEMANGGILAN FUNGSI
                {
                    antrean();
                    printf("\n\t\t\t\tMasukkan pilihan Anda : ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\n\t\t\t\tMasukkan nomor antrean baru: ");
                        scanf("%d",&n);
                        insert(n);
                        break;
                    case 2:
                        printf("\n\t\t\t\tMasukkan nomor antrean lama: ");
                        scanf("%d",&n);
                        eliminate(n);
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        dataPasienLab(nama, harga, jalur);
                        break;
                    default:
                        printf("\n\n\t\t\t\tPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
                    }
lainnya:
  printf("\n\n\t\t\t\tPress any key to continue...");
  getch();
  printf("\n\n\t\t\tKelola lagi menu ini[Y/N]?? ");
  scanf(" %c",&sip);
    if (toupper(sip)=='Y')
    {
        antrean();
    }else if(toupper(sip)=='N')
    {
        keluar();
    }else
    {
        printf("\n\t\tPilihan tidak tersedia.\n");
        goto lainnya;
    }

    }
        return(lab);
}

/* ************************************** Data Pasien Lab*******************************************/
int dataPasienLab(char* nama, int harga, int jalur)
{
    char alamat[50], tgl[50], name[35],jk[30],umur[10],no[15];
    float total;
    int bpjs;
    printf("\n\t\t\t\t*** %s **\n", nama);
    getchar();
    printf("\n\t\t\t\tTANGGAL BEROBAT : ");fgets(tgl, sizeof(tgl), stdin);
    printf("\n\t\t\t\tNAMA PASIEN     : ");fgets(name, sizeof(name), stdin);
    printf("\n\t\t\t\tUMUR            : ");fgets(umur, sizeof(umur), stdin);
    printf("\n\t\t\t\tJENIS KELAMIN   : ");fgets(jk, sizeof(jk), stdin);;
    printf("\n\t\t\t\tALAMAT          : ");fgets(alamat, sizeof(alamat), stdin);
    printf("\n\t\t\t\tNO HP           : ");fgets(no, sizeof(no), stdin);
    if (jalur == 2){
        harga = 0.0;
        printf("\n\t\t\t\tNo BPJS          :");
        scanf("%d", &bpjs);
    }
    printf("\n\t\t\t\tHARGA            :%d\n", harga);
    total= harga;
    printf("\n\t\t\t\tTOTAL BIAYA     : %.2f\n\n", total);
    printf("\t\t\t========================TERIMA KASIH===========================\n");
    getch();
    getchar();
}
/* ************************************** Layanan Radiologi *******************************************/
int pilihanRadiologi()
{
    system("cls");
    printf("\t\t\t===============================================================\n\n");
    printf("\t\t\t      ***00o SELAMAT DATANG DI PROGRAM RADIOLOGI o00***\n\n");
    printf("\t\t\t          ***00o RUMAH SAKIT UMUM ARDI WIRAMA o00***\n\n");
    printf("\t\t\t===============================================================\n\n");
    int rad;
    printf("\n\n\n\t\t\t\tJENIS PEMERIKSAAN RADIOLOGI RSU ARDI WIRAMA\n\n");
    printf("\n\t\t\t\t1. RADIOGRAFI ATAU RONTGEN            5. MAMMOGRAM\n");
    printf("\n\t\t\t\t2. ULTRASONOGRAFI                     6. PENCITRAAN NUKLIR\n");
    printf("\n\t\t\t\t3. FLUOROSKOPI                        7. CT (Computed Tomography)\n");
    printf("\n\t\t\t\t4. MRI (Magnetic Resonance Imaging)   0. KEMBALI\n");
    printf("\n\n\t\t\t\tSILAHKAN MASUKKAN PILIHAN ANDA :");
    scanf("%d", &rad);
    return(rad);
}
/* ************************************** Menu di dalam Radiologi *******************************************/
int radiologi(int rad, int jalur)
{
        system("cls");
        int harga;
        char* nama;
        if(rad == 1){
            nama = "RADIOGRAFI ATAU RONTGEN";
            harga = 150000;
        }
        else if (rad == 2){
            nama = "ULTRASONOGRAFI";
            harga = 100000;
        }
        else if (rad == 3){
            nama = "FLUOROSKOPI";
            harga = 60000;
        }
        else if (rad == 4){
            nama = "MRI (Magnetic Resonance Imaging)";
            harga = 75000;
        }
        else if (rad == 5){
            nama = "MAMMOGRAM";
            harga = 70000;
        }
        else if (rad == 6){
            nama = "PENCITRAAN NUKLIR";
            harga = 65000;
        }
        else if (rad == 7){
            nama = "CT (Computed Tomography";
            harga = 55000;
        }
        else if (rad == 0){
            pilihanPelayanan();
        }
        else
        {
           printf("Menu Tidak Tersedia!");
           exit(1);
        }
        if (jalur==2) {
            harga= 0.0;
        }
        int n, choice;
        create();
                while (1) //PEMANGGILAN FUNGSI
                {
                    antrean();
                    printf("\n\t\t\t\tMasukkan pilihan Anda : ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        printf("\n\t\t\t\tMasukkan nomor antrean baru: ");
                        scanf("%d",&n);
                        insert(n);
                        break;
                    case 2:
                        printf("\n\t\t\t\tMasukkan nomor antrean lama: ");
                        scanf("%d",&n);
                        eliminate(n);
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        dataPasienRad(nama, harga, jalur);
                        break;
                    default:
                        printf("\n\n\t\t\t\tPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
                    }
lainnya:
  printf("\n\n\t\t\t\tPress any key to continue...");
  getch();
  printf("\n\n\t\t\tKelola lagi menu ini[Y/N]?? ");
  scanf(" %c",&sip);
    if (toupper(sip)=='Y')
    {
        antrean();
    }else if(toupper(sip)=='N')
    {
        keluar();
    }else
    {
        printf("\n\t\tPilihan tidak tersedia.\n");
        goto lainnya;
    }

    }
        return(rad);
}
/* ************************************** Data Pasien Radiologi*******************************************/
int dataPasienRad(char* nama, int harga, int jalur)
{
    char alamat[50], tgl[50], name[35],jk[30],umur[10],no[15];
    float total;
    int bpjs;
    printf("\n\t\t\t\t*** %s **\n", nama);
    getchar();
    printf("\n\t\t\t\tTANGGAL BEROBAT : ");fgets(tgl, sizeof(tgl), stdin);
    printf("\n\t\t\t\tNAMA PASIEN     : ");fgets(name, sizeof(name), stdin);
    printf("\n\t\t\t\tUMUR            : ");fgets(umur, sizeof(umur), stdin);
    printf("\n\t\t\t\tJENIS KELAMIN   : ");fgets(jk, sizeof(jk), stdin);;
    printf("\n\t\t\t\tALAMAT          : ");fgets(alamat, sizeof(alamat), stdin);
    printf("\n\t\t\t\tNO HP           : ");fgets(no, sizeof(no), stdin);
    if (jalur == 2){
        harga = 0.0;
        printf("\n\t\t\t\tNo BPJS     :");
        scanf("%d", &bpjs);
    }
    printf("\n\t\t\t\tHARGA            :%d\n", harga);
    total= harga;
    printf("\n\t\t\t\tTOTAL BIAYA     : %.2f\n\n", total);
    printf("\t\t\t========================TERIMA KASIH===========================\n");
    getch();
    getchar();
}
int main(void)
{
    int masuk;
    system ("color fd");
    welcome();
	system("cls");
	title();
        menuValidasi :
        printf ("\n\n\n\t\t\t\tMasuk sebagai?\n");
        printf ("\n\t\t\t\t1. Pasien\n");
        printf ("\n\t\t\t\t2. Admin\n");
        printf ("\n\n\t\t\t\tPilihan Anda : ");
        scanf ("%d", &masuk);

            switch(masuk)
            {
               case 1:
                pasienn();
                    while(1){
                        int pil, jalur, poli, n, choice, m, lab, rad, choose;
                        pil = pilihanPelayanan();
                        if (pil == 1)
                        {//layanan rawat inap
                             jalur = pilihanJalurLayanan();
                             rawatInap();
                            if (jalur == 3)
                            {
                                continue;
                            }
                        }
                        else if(pil == 2){
                            //layanan rawat jalan
                                poli = pilihanPoliklinik();
                                poliklinik1(poli);
                                if (poli == 0)
                            {
                                continue;
                            }
                                poli = pilihanPoliklinik();
                                pilihanPasien();
                                if(poli != 0){
                                    poliklinik(poli);
                                }else
                                {
                                    break;
                                }
                        }
                        else if(pil == 3)
                        { //layanan IGD
                           printf("\n\n\t\t\t\tMaaf! Anda tidak memiliki akses terhadap bagian ini.\n");
                           printf("\n\n\t\t\t\t");
                           system("pause");
                           pilihanPelayanan();
                        }
                       else if(pil == 4)
                        { //layanan farmasi
                            jalur = pilihanJalurLayanan();
                            pilihanPasien();
                            if (jalur == 3)
                            {
                                continue;
                            }while(2){
                            m = pilihanMenuFarmasi();
                                if (m != 0)
                            {
                                farmasi(m, jalur);
                                }else if (m == 0){
                                    pilihanJalurLayanan();
                                }else if (m != 1||2||3||4||5||6||7||0)
                                {
                                    printf("Menu Tidak Tersedia!");
                                    exit(1);
                                }
                            }
                        }
                        else if(pil == 5)
                        { //layanan laboratorium
                            jalur = pilihanJalurLayanan();
                            if (jalur == 3)
                            {
                                continue;
                            }
                            while(1)
                            {
                                lab = pilihanLaboratorium();
                                pilihanPasien();
                                    if (lab != 0){
                                        laboratorium(lab, jalur);
                                    }else if (lab == 0){
                                        pilihanJalurLayanan();
                                    }else if (lab != 1||2||3||4||5||6||7||0)
                                    {
                                    printf("Menu Tidak Tersedia!");
                                    exit(1);
                                    }
                            }
                        }
                        else if(pil == 6)
                        { //layanan radiologi
                            jalur = pilihanJalurLayanan();
                            if (jalur == 3)
                            {
                                continue;
                            }
                            while(2){
                           rad = pilihanRadiologi();
                           pilihanPasien();
                                if (rad != 0)
                            {
                                radiologi(rad, jalur);
                                }else if (rad == 0){
                                    pilihanJalurLayanan();
                                }else if (rad != 1||2||3||4||5||6||7||0)
                                {
                                    printf("Menu Tidak Tersedia!");
                                    exit(1);
                                }
                            }
                        }
                        else if(pil == 7)
                        { //keluar
                            keluar();
                        }
                        else
                        {
                            printf("Menu Tidak Tersedia.");
                        }
                    }
                break;
            case 2:
                admin();
                    while(1){
                        int pil, jalur, poli, n, choice, m, lab, rad, choose;
                        pil = pilihanPelayanan();
                        if (pil == 1)
                        {//layanan rawat inap
                             jalur = pilihanJalurLayanan();
                             rawatInap();
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
                                    poliklinik(poli);
                                }else
                                {
                                    break;
                                }
                        }
                        else if(pil == 3)
                        { //layanan IGD
                           IGD();
                        }
                       else if(pil == 4)
                        { //layanan farmasi
                            jalur = pilihanJalurLayanan();
                            if (jalur == 3)
                            {
                                continue;
                            }while(2){
                            m = pilihanMenuFarmasi();
                                if (m != 0)
                            {
                                farmasi(m, jalur);
                                }else if (m == 0){
                                    pilihanJalurLayanan();
                                }else if (m != 1||2||3||4||5||6||7||0)
                                {
                                    printf("Menu Tidak Tersedia!");
                                    exit(1);
                                }
                            }
                        }
                        else if(pil == 5)
                        { //layanan laboratorium
                            jalur = pilihanJalurLayanan();
                            if (jalur == 3)
                            {
                                continue;
                            }
                           while(1)
                            {
                                lab = pilihanLaboratorium();
                                    if (lab != 0){
                                        laboratorium(lab, jalur);
                                    }else if (lab == 0){
                                        pilihanJalurLayanan();
                                    }else if (lab != 1||2||3||4||5||6||7||0)
                                    {
                                    printf("Menu Tidak Tersedia!");
                                    exit(1);
                                    }
                            }
                        }
                        else if(pil == 6)
                        { //layanan radiologi
                            jalur = pilihanJalurLayanan();
                            if (jalur == 3)
                            {
                                continue;
                            }
                            while(2){
                           rad = pilihanRadiologi();
                                if (rad != 0)
                            {
                                radiologi(rad, jalur);
                                }else if (rad == 0){
                                    pilihanJalurLayanan();
                                }else if (rad != 1||2||3||4||5||6||7||0)
                                {
                                    printf("Menu Tidak Tersedia!");
                                    exit(1);
                                }
                            }
                        }
                        else if(pil == 7)
                        { //keluar
                            keluar();
                        }
                        else
                        {
                            printf("Menu Tidak Tersedia.");
                        }
                break;
            default:
                printf("\n\n\t\t\t\tHarap masukkan pilihan dengan benar!");
                goto menuValidasi;
                getch();
                    }
            }
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menuLogin()
{
    char username[14]= "ardi_wirama", pass[5]= "1234";
    char usr[14], pas[5];
    int coba = 0, salah = 0;
    printf("\t\t\tSELAMAT DATANG DI SISTEM INFORMASI\n");
    printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\tJL.PEGANGSAAN BARAT NO.5 KOTA MALANG\n");
    printf("\t\t\t   NOMOR TELEPON :0361 2457 8897\n");
    printf("\t\tSENYUM ANDA HARAPAN KAMI,KESEMBUHAN ANDA TUJUAN KAMI\n");
    printf("\t\t========================================================\n\n");
    while(1){
        printf("USERNAME : ");
        scanf("%s", username);
        printf("PASSWORD : ");
        scanf("%s", pass);
        if(strcmp(pass, "1234")==0 && strcmp (username, "ardi_wirama")==0){
            printf("Akses Diterima\n");
            break;
        }else
        {
            printf("Username dan Password salah\n");
            coba++;
            if (coba == 3)
            {
                printf("akses ditolak\n");
                exit(0);
            }
        }
    }
}

int pilihanUtama()
{
    system("cls");
    int pil;
    printf("\t\t\tSELAMAT DATANG DI PROGRAM PELAYANAN\n");
    printf("\t\t\t  RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\t========================================\n\n");
    printf("PILIH JALUR PELAYANAN YANG ANDA GUNAKAN\n");
    printf("1.RAWAT INAP\n");
    printf("2.RAWAT JALAN\n");
    printf("3.IGD\n");
    printf("4.KELUAR\n");
    printf("MASUKAN PILIHAN ANDA :");
    scanf("%d", &pil);
    return pil;
}

int pilihanLayanan()
{
    system("cls");
    int x;
    printf("\t\t\tSELAMAT DATANG DI PROGRAM RAWAT JALAN\n");
    printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\t========================================\n\n");
    printf("PILIH JALUR PELAYANAN YANG ANDA GUNAKAN\n");
    printf("1.UMUM\n");
    printf("2.BPJS\n");
    printf("3.KEMBALI\n");
    printf("MASUKKAN PILIHAN ANDA :");
    scanf("%d", &x);
    return(x);
}

int pelayanan()
{
    system("cls");
    printf("\t\t\tSELAMAT DATANG DI PROGRAM RAWAT JALAN\n");
    printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
    printf("\t\t\t========================================\n\n");
    printf("PILIH JALUR PELAYANAN YANG ANDA GUNAKAN\n");
    int y;
    printf("1. ANTRIAN\n");
    printf("2. POLIKLINIK UMUM\n");
    printf("3. POLIKLINIK ANAK\n");
    printf("4. POLIKLINIIK BEDAH\n");
    printf("5. POLIKLINIK GIGI\n");
    printf("6. POLIKLINIK THT\n");
    printf("7. POLIKLINIK MATA\n");
    printf("8. POIKLINIK PENYAKIT DALAM\n");
    printf("9. POLIKLINIK REKAM MEDIS\n");
    printf("0. KEMBALI\n");
    printf("MASUKKAN PILIHAN ANDA :");
    scanf("%d", &y);
    return(y);
}

int aksiPelayanan(int y, int x)
{
    if(y == 1)
    {
        //panggil program antrian
    }
    else
    {
        char* poli;
        char* dokter;
        int harga;
        if(y == 2){
            poli = "POLIKLINIK UMUM";
            dokter = "dr.Amelia Venusia";
            harga = 150000;
        }
        if (y == 3){
            poli = "POLIKLINIK ANAK";
            dokter = "dr.Jerry Putra";
            harga = 160000;
        }
        if (y == 4){
            poli = "POLIKLINIK BEDAH";
            dokter = "dr.Ferdinan Geneva";
            harga = 200000;
        }
        if (y == 5){
            poli = "POLIKLINIK GIGI";
            dokter = "dr.Anisa Rahmantari";
            harga = 170000;
        }
        if (y == 6){
            poli = "POLIKLINIK THT";
            dokter = "dr.Reyhan Fernandus ";
            harga = 155000;
        }
        if (y == 7){
            poli = "POLIKLINIK MATA";
            dokter = "dr.Anggi Maharani";
            harga = 160000;
        }
        if (y == 8){
            poli = "POLIKLINIK PENYAKIT DALAM";
            dokter = "dr.Jhonny Robert";
            harga = 175000;
        }
        if (y == 9){
            poli = "POLIKLINIK REKAM MEDIS";
            dokter = "dr.Wahyu Saputra";
            harga = 165000;
        }
        else
        {
            printf("\t\tMenu Tidak Tersedia!\n");
        }
        if (x==2) {
            harga= 0;
        }
        fungsiUtama(poli, dokter, harga,x);
        return(y);
    }
}

void fungsiUtama(char* poli, char* dokter, int h, int x)
{
    char alamat[50], tgl[50], nama[35],jk[30],kl[50],umur[10];
    float ho,total;

    printf("\t\t %s\n", poli);
    printf("NAMA DOKTER : %s\n", dokter);
    getchar();
    printf("TANGGAL BEROBAT : ");fgets(tgl, sizeof(tgl), stdin);
    printf("NAMA PASIEN : ");fgets(nama, sizeof(nama), stdin);
    printf("UMUR : ");fgets(umur, sizeof(umur), stdin);
    printf("JENIS KELAMIN : ");fgets(jk, sizeof(jk), stdin);;
    printf("ALAMAT : ");fgets(alamat, sizeof(alamat), stdin);
    printf("KELUHAN : ");fgets(kl, sizeof(kl), stdin);
    printf("JASA DOKTER :%d \n", h);
    if (x == 2){
        printf("HARGA OBAT : 0.0\n");
        ho = 0.0;
    }else
    {
        printf("HARGA OBAT : ");scanf("%f", &ho);
    }
    total=h+ho;
    printf("TOTAL BIAYA : %.2f\n", total);
    printf("============TERIMA KASIH==========\n");
    printf("==========SEMOGA LEKAS SEMBUH======\n");
    printf("Tekan Sembarang Untuk Melanjutkan");getch();
    getchar();
}

int main(){
    menuLogin();
    while(1){
        int pil, x, y;
        pil = pilihanUtama();

        //pilih menu utama
        if (pil == 1)
        {
            //layanan rawat inap
            printf("\nMenu Belum Tersedia\n");
        }
        else if(pil == 2){
            //layanan rawat jalan
            x = pilihanLayanan();
            if (x == 3)
            {
                continue;
            }

            while(1)
            {
                y = pelayanan();
                if(y != 0){
                    aksiPelayanan(y,x);
                }else
                {
                    break;
                }
            }
        }
        else if(pil == 3)
        {
            printf("\nMenu Belum Tersedia\n");
        }
        else if(pil == 4)
        {
            exit(0);
        }
        else
        {
            printf("\nMenu Salah\n");
        }
    }
    return(0);
}


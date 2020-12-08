#include <stdio.h>
#include <string.h>

int main(void)
{   int pil;
    char alamat[50],tgl[25],nama[35],jk[30],kl[50],umur[10];
    float hb,total,jd=150000;

    printf("\t\tPOLIKLINIK UMUM\n");
    printf("NAMA DOKTER :dr. Amelia Venusia\n");
    printf("TANGGAL BEROBAT :");fgets(tgl,sizeof(tgl), stdin);
    printf("NAMA PASIEN :");fgets(nama,sizeof(nama), stdin);
    printf("UMUR :");fgets(umur,sizeof(umur), stdin);
    printf("JENIS KELAMIN :");fgets(jk,sizeof(jk), stdin);
    printf("ALAMAT :");fgets(alamat,sizeof(alamat), stdin);
    printf("KELUHAN :");fgets(kl,sizeof(kl), stdin);
    printf("JASA DOKTER :%.2f\n", jd);
    printf("HARGA OBAT :");scanf(" %f", &hb);
    total=jd+hb;
    printf("TOTAL BIAYA :%.2f\n", total);
 return(0);
}

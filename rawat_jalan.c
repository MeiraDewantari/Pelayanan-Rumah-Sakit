#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   char username[14]= "ardi_wirama", pass[5]= "1234";
   char usr[14], pas[5];
   int status = 0, salah = 0;
printf("\t\t\tSELAMAT DATANG DI SISTEM INFORMASI\n");
printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
printf("\t\t\tJL.PEGANGSAAN BARAT NO.5 KOTA MALANG\n");
printf("\t\t\t   NOMOR TELEPON :0361 2457 8897\n");
printf("\t\tSENYUM ANDA HARAPAN KAMI,KESEMBUHAN ANDA TUJUAN KAMI\n");
printf("\t\t========================================================\n\n");

  while(status < 3){
      printf("USERNAME : ");
      scanf("%s", username);
      printf("PASSWORD : ");
      scanf("%s", pass);
      if(strcmp(pass, "1234")==0 && strcmp (username, "ardi_wirama")==0){
        printf("Akses Diterima\n");
        break;
      }else{
      printf("Username dan Password salah\n");
      salah++;
      if(salah==3){
        printf("Akses Ditolak\n");
      }
      }
      status++;
   }
system("pause");
int pil,umum,bpjs,a;

printf("1.RAWAT INAP\n");
printf("2.RAWAT JALAN\n");
printf("3.IGD\n");
printf("MASUKAN PILIHAN ANDA :");
scanf("%d", &pil);

printf("\t\t\tSELAMAT DATANG DI PROGRAM RAWAT JALAN\n");
printf("\t\t\t   RUMAH SAKIT UMUM ARDI WIRAMA\n");
printf("\t\t\t========================================\n\n");
{
printf("PILIH JALUR PELAYANAN YANG ANDA GUNAKAN\n");
printf("1.UMUM\n");
printf("2.BPJS\n");
printf("3.KELUAR\n");
printf("MASUKKAN PILIHAN ANDA :");
scanf("%d", &pil);

 switch (pil)
 {
 case 1:
    printf("1. ANTRIAN\n");
    printf("2. POLIKLINIK UMUM\n");
    printf("3. POLIKLINIK ANAK\n");
    printf("4. POLIKLINIIK BEDAH\n");
    printf("5. POLIKLINIK GIGI\n");
    printf("6. POLIKLINIK THT\n");
    printf("7. POLIKLINIK MATA\n");
    printf("8. POIKLINIK DALAM\n");
    printf("9. POLIKLINIK REKAM MEDIS\n");
    printf("MASUKKAN PILIHAN ANDA :");
    scanf("%d", &a);
    break;

 case 2:
    printf("1. ANTRIAN\n");
    printf("2. POLIKLINIK UMUM\n");
    printf("3. POLIKLINIK ANAK\n");
    printf("4. POLIKLINIIK BEDAH\n");
    printf("5. POLIKLINIK GIGI\n");
    printf("6. POLIKLINIK THT\n");
    printf("7. POLIKLINIK MATA\n");
    printf("8. POIKLINIK DALAM\n");
    printf("9. POLIKLINIK REKAM MEDIS\n");
    printf("MASUKKAN PILIHAN ANDA :");
    scanf("%d", &a);
 case 3:
    exit(1);
 default:
    printf("\nPIIHAN YANG ANDA MASUKKAN SALAH\n");
 }
}

return (0);
}

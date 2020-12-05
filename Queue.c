/*
 * Program c implementasi dari queue untuk menambahkan dan menghapus elemen pada antrean
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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
    printf("\n%d tidak ditemukan di dalam antrean.", data);
}

/* Funngsi untuk menampilkan nomor antrean */
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

int main(void)
{
    int n, choice;

    printf("1. Tambah nomor antrean\n");
    printf("2. Hapus nomor antrean\n");
    printf("3. Tampilkan nomor antrean\n");
    printf("4. Keluar");

    create();

    while (1)
    {
        printf("\nMasukkan pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan nomor antrean baru: ");
            scanf("%d",&n);
            insert(n);
            break;
        case 2:
            printf("Masukkan nomor antrean lama: ");
            scanf("%d",&n);
            delete(n);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nPilihan Anda tidak sesuai. Harap masukkan pilihan sesuai dengan yang tersedia!\n");
        }
    }
  return (0);
}

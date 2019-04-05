#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int point = 1000;
int h

void* optionstok(void *arg){

	int pilihan=(int)arg;
	key_t pointer = point;
	int *stok;
	int shmid = shmget(pointer, 6*sizeof(int), IPC_CREAT | 0911);
	stok = shmat(shmid, NULL, 0);
	for(int i=0;i<6;i++) {
	printf("Jumlah stok senjata = %d barang\n", *(stok+i));
	}
	getchar();
	}

void optionbeli(void *arg){

	key_t pointer = point;
	int *stok, i=0;
	int shmid = shmget(pointer, 6*sizeof(int), IPC_CREAT | 0911);
        stok = shmat(shmid, NULL, 0);
	char *inputstok = (char*)arg;
        for(int i=0;i<6;i++) {
	if(strcamp(inputstok ,s[i])==0 && *(stok +i)>=h) {
	*(stok+i)-=h; }
	else if (strcmp(inputstok, s[i])==0) {
	printf("stok tidak cukup\n"); }
	}
}

int main() {

	pthread_t tid;
	while(1) {

	printf("Stok Senjata\n");
	printf("Beli Senjata\n");
	printf("Pilihan : ");
	int pilihan;
	scanf("%d", &pilihan);
	if(pilihan==1) pthread_create(&(tid), NULL, &optionstok, (void*)pilihan);
	else if (pilihan==2) {
	char inputbeli[10]
	scanf("%d", inputbeli, &h);
	pthread_create(&(tid), NULL, &optionbeli, (void*)inputbeli);
	}
	pthread_join(tid, NULL);
	getchar();
	}
}

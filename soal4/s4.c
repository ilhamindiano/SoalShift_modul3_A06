#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1, tid2, tid3, tid4;

char command[100];
char command2[100];
int statusps;
int statuszip;
int status;

void* ps(){

	status = 0;

	strcpy(command, "ps aux >> /home/z/Documents/FolderProses1/SimpanProses1.txt");
        system(command);

	strcpy(command2, "ps aux >> /home/z/Documents/FolderProses2/SimpanProses2.txt");
        system(command2);

	statusps = 1;
	return NULL;

}

void* zip()
{

	while(statusps != 1) { }

	system("zip -j /home/z/Documents/FolderProses1/KompresProses1.zip /home/z/Documents/FolderProses1/SimpanProses1.txt");

	system("zip -j /home/z/Documents/FolderProses2/KompresProses2.zip /home/z/Documents/FolderProses2/SimpanProses2.txt");

	statuszip = 1;
	return NULL;

}

void* unzip()
{

	while(statuszip != 1) { }

	system("unzip /home/z/Documents/FolderProses1/KompresProses1.zip");

	system("unzip /home/z/Documents/FolderProses2/KompresProses2.zip");
}

void* rem()
{
	system("rm /home/z/Documents/FolderProses1/SimpanProses1.txt");
	system("rm /home/z/Documents/FolderProses2/SimpanProses2.txt");

}


int main(void)
{
	int t1,t2,t3,t4;  
	t1 = pthread_create(&(tid1), NULL, ps, NULL);
	pthread_join(tid1,NULL);    	

	t2 = pthread_create(&(tid2), NULL, zip, NULL);
	pthread_join(tid2,NULL);	
	
	t3 = pthread_create(&(tid3), NULL, rem, NULL);
        pthread_join(tid3,NULL); 
	
	printf("Menunggu 15 detik untuk mengekstrak kembali\n");

	sleep(5);

	t4 = pthread_create(&(tid4), NULL, unzip, NULL);
	pthread_join(tid4,NULL);
	return 0;
}



#include <stdio.h>
#include <stdlib.h>
//Queue(kuyruk) veri yap�s�nda First in First out (FIFO) mant��� vard�r yani ilk giren veri ilk ��kan veri olmal�d�r.

typedef struct Node Node;
struct Node{
	int data;
	Node *next;
};

Node *head = NULL;	//s�ran�n ba��n� i�aret eden i�aret�i
Node *tail = NULL;  //s�ran�n sonunu i�aret eden i�aret�i

void enQueue(int data);
void deQueue();
int isEmpty();
int queueLen();
void printQueue();
void menu();

int main(){
	
	menu();
	
//	enQueue(100);
//	enQueue(200);
//	enQueue(300);
//	enQueue(400);
//	enQueue(500);
//	enQueue(600);
//	printf("Sira uzunlugu: %d\n", queueLen());
//	printQueue();
//	deQueue();
//	deQueue();
//	deQueue();
//	deQueue();
//	deQueue();
//	deQueue();
//	printQueue();

}

int isEmpty(){
	if(head == NULL)
		return 1;
	else
		return 0;
}
int queueLen(){
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		int counter = 0;
		
		Node *tempHead = head;
		
		
		while(tempHead != NULL)
		{
			tempHead = tempHead -> next;
			counter++;
		}
		return counter;
	}
}

void enQueue(int data){
	Node *newNode = malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> next = NULL;
	if(isEmpty())
	{
		head = tail = newNode;
	}	
	else
	{
		//tail daima Queue'nin sonundaki eleman� g�sterdi�i i�in �teleme de�i�keni kullanmadan listenin sonuna ekleme yapabiliriz.
		tail -> next = newNode;
		//Ekleme i�leminden sonra tail pointer'�m�z�n tuttu�u adresi de�i�tiriyoruz
		tail = newNode;	
	}
	printf("%d Kuyruga basariyla eklendi.\n", data);
}
void deQueue(){
	//Queue FIFO mant��� ile �al��t��� i�in burada listemizdeki ilk eleman� silece�iz ve bellekte kaplad��� adresi serbest b�rakaca��z
	if(isEmpty())
	{
		printf("Kuyruk bos.\n");
	}
	else
	{
		//tempHead'i head de�i�keninin bellekte �u an g�sterdi�i adrese e�itliyoruz
		Node *tempHead = head;
		//printf ciktisindan da g�r�lecegi �zere ikisi de ayn� adresi g�steriyor
		//printf("Adres deneme (tempHead: %p, head: %p)\n", tempHead, head);
		
		//Listemizin ilk eleman�na kullan�c� eri�imini kesiyoruz
		//Bu i�lem sonrasu art�k listemizin ilk eleman� listemizin 2. eleman�na e�it oluyor;
		head = head -> next;
		
		//Kullan�c�ya hangi eleman� sildi�imiz bilgisini vermek i�in silinecek olan eleman�n verisini tutuyoruz.
		int tempData= tempHead -> data;
		//Ard�ndan listemizin eski ilk eleman�n�n bellekte kaplad��� yeri serbest b�rak�yoruz
		free(tempHead);
		tempHead = NULL;
		
		//E�er sildi�imiz eleman listenin tek eleman�ysa tail de�i�kenini de NULL'a e�itlememiz laz�m
		//Aksi takdirde memory leak ya�an�r
		if(head == NULL)
		{
			tail = NULL;
		}
		printf("%d siradan cikarildi\n", tempData);
	}
}
void printQueue(){
	if(isEmpty())
	{
		printf("Kuyruk bos.\n");
	}
	else
	{
		int counter = 1;
		Node *tempHead = head;
		
		while(tempHead != NULL)
		{
			printf("Siranin %d. elemani : %d\n", counter++, tempHead -> data);
			tempHead = tempHead -> next;
		}
	}
}
void menu(){
	int loop = 1;
	int islem = 0;
	do
	{
		
		system("CLS");
		printf("1 -> Ekle: \n");
		printf("2 -> Cikar: \n");
		printf("3 -> Kuyruk uzunlugu: \n");
		printf("4 -> Kuruk basi: \n");
		printf("5 -> Kuyruk sonu: \n");
		printf("6 -> Kuyruk yazdir: \n");
		printf("9 -> Cikis: \n");
		printf("Bir islem seciniz: ");
		scanf("%d", &islem);
		
		
		switch(islem)
		{
			case 1:
				printf("Kuyruga eklemek istediginiz veriyi(int) giriniz: ");
				int data;
				scanf("%d", &data);
				enQueue(data);
				break;
			case 2:
				deQueue();
				break;
			case 3:
				printf("Kuyruk uzunlugu: %d\n", queueLen());
				break;
			case 4:
				printf("Kuyrugun ilk elemani: %d \n", head -> data);
				break;
			case 5:
				printf("Kuyrugun son elemani: %d \n", tail -> data);
				break;
			case 6:
				printQueue();
				break;
			case 9:
				printf("Basariyla cikis yapilmistir.");
				return;
				
			default:
				printf("Hatali tuslama tekrar deneyiniz. \n");
		}
		printf("Devam etmek icin bir tusa basiniz: ");
		getch();
	}while(loop);
		
}



#include <stdio.h>
#include <stdlib.h>
//Queue(kuyruk) veri yapýsýnda First in First out (FIFO) mantýðý vardýr yani ilk giren veri ilk çýkan veri olmalýdýr.

typedef struct Node Node;
struct Node{
	int data;
	Node *next;
};

Node *head = NULL;	//sýranýn baþýný iþaret eden iþaretçi
Node *tail = NULL;  //sýranýn sonunu iþaret eden iþaretçi

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
		//tail daima Queue'nin sonundaki elemaný gösterdiði için öteleme deðiþkeni kullanmadan listenin sonuna ekleme yapabiliriz.
		tail -> next = newNode;
		//Ekleme iþleminden sonra tail pointer'ýmýzýn tuttuðu adresi deðiþtiriyoruz
		tail = newNode;	
	}
	printf("%d Kuyruga basariyla eklendi.\n", data);
}
void deQueue(){
	//Queue FIFO mantýðý ile çalýþtýðý için burada listemizdeki ilk elemaný sileceðiz ve bellekte kapladýðý adresi serbest býrakacaðýz
	if(isEmpty())
	{
		printf("Kuyruk bos.\n");
	}
	else
	{
		//tempHead'i head deðiþkeninin bellekte þu an gösterdiði adrese eþitliyoruz
		Node *tempHead = head;
		//printf ciktisindan da görülecegi üzere ikisi de ayný adresi gösteriyor
		//printf("Adres deneme (tempHead: %p, head: %p)\n", tempHead, head);
		
		//Listemizin ilk elemanýna kullanýcý eriþimini kesiyoruz
		//Bu iþlem sonrasu artýk listemizin ilk elemaný listemizin 2. elemanýna eþit oluyor;
		head = head -> next;
		
		//Kullanýcýya hangi elemaný sildiðimiz bilgisini vermek için silinecek olan elemanýn verisini tutuyoruz.
		int tempData= tempHead -> data;
		//Ardýndan listemizin eski ilk elemanýnýn bellekte kapladýðý yeri serbest býrakýyoruz
		free(tempHead);
		tempHead = NULL;
		
		//Eðer sildiðimiz eleman listenin tek elemanýysa tail deðiþkenini de NULL'a eþitlememiz lazým
		//Aksi takdirde memory leak yaþanýr
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



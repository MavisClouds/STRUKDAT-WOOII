#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

	struct node
	{
		int nopesan=0,jumlah[10],nomeja=0;
		char pesanan[4][50];
  	  struct node *next,*next1,*prev1;
	};

	typedef struct node node;

	struct queue
	{

   	 	int count=0;
    	node *top;
	};

	typedef struct queue queue;

	struct queue1
	{

   	 	int count=0;
    	node *top;
	};

	typedef struct queue1 queue1;

	void enqueue(queue *head);
	queue createqueue();
	queue1 createqueue1();
	node *createNode();
	void display(queue head,queue1 head1);
	void dequeue(queue *head,queue1 *head1);

	int main ()
{
		int pilih;
		queue head;
		queue1 head1;
		head = createqueue();

	do
	{
		system("cls");

			printf("  (*)                       (*)  \n");
			printf("  |-| MASUKKAN PILIHAN ANDA |-|  \n");
			printf("  (*)                       (*)  \n");
			printf("1. Masukkan antrian 		     \n");
			printf("2. Tampilkan antrian		     \n");
			printf("3. Hapus antrian lalu pindah meja\n");
			printf("4. Exit                      \n");
			printf("<>-------------------------<>\n\n");
			printf("pilihan anda : ");
			scanf("%i",&pilih);

			switch(pilih)
			{
				case 1 : enqueue(&head);
						 break;
				case 2 : display(head,head1);
						 break;

				case 3 : dequeue(&head,&head1);
						 break;

			   default : printf("HAH?!?!?!"); getch();
			}
	}while (pilih != 4);
}

	node *createNode ()
	{
   		node *newPtr;
   		newPtr = (node *)malloc(sizeof(newPtr));
   		return(newPtr);
	}

	queue createqueue ()
	{
   		 queue head;
	 	 head.count = 0;
	 	 head.top = NULL;
	 	 return(head);
	}

	queue1 createqueue1 ()
	{
   		 queue1 head1;
	 	 head1.count = 0;
	 	 head1.top = NULL;
	 	 return(head1);
	}

	void enqueue(queue *head)
	{
		char menu[5][50],pilih,r=-1;
		int jumlah[10],a=0,nopesan;
		node *ppl,*temp;

		while (pilih != 'n')
		{
			printf("\nMasukkan pesanan anda : ");
			scanf("%s",&menu[a]);
			printf("Masukkan jumlah pesanan : ");
			scanf("%i",&jumlah[a]);
			a++;
			r++;
			fflush(stdin);
			if(a==4)
			{
				printf("pesanan anda penuh");
				break;
			}
			printf("mau nambah ? y/n : ");

			scanf("%c",&pilih);
		}

		ppl = (node *)malloc(sizeof(node));

		for(int b=0; b<=4; b++)
		{
			strcpy(ppl->pesanan[b],menu[b]);
			ppl->jumlah[b] = jumlah[b];
		}

			if (r!=4)
			{
				for (r=r+1; r<=4; r++)
				{
					strcpy(ppl->pesanan[r],"kosong");
					fflush(stdin);
					ppl->jumlah[r] = 0;
				}
			}

		ppl->next = NULL;

		temp = head->top;

		if(head->top==NULL)
		{
			head->top = ppl;
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			ppl->next = temp->next;
			temp ->next = ppl;
		}

			head->count=(head->count)+1;
			nopesan = head->count;
			ppl->nopesan = nopesan;
	}

	void display (queue head,queue1 head1)
{
	int i,e,nomeja;
   system("cls");
   node *temp,*temp1;
   temp = head.top;
   temp1 = head1.top;
   i = head1.count;
   nomeja = 1;

   if(head.count==0)
   {
         printf("\n\tNULL\n");
   }
   else
   {
   	     while(temp)
   	     {
   	     	   printf("\n\t+---------+ ");
   	     	   printf("\n\t|");
   	     	   printf("\n\t| nomor pesanan : %d",temp->nopesan);

   	     	for(int c=0; c<=4; c++)
   	     	{
   	           printf("\n\t| pesanan : %s ",temp->pesanan[c]);
   	           printf("\n\t| jumlah	   : %d ",temp->jumlah[c]);
   	        }
   	    	   printf("\n\t|");
   	           printf("\n\t+---------+\n\n ");

			   temp = temp->next;
   	     }
   }

   if(head1.count==0)
   {
         printf("\n\tNULL\n");
   }
   else
   {
   	     for(int a=1;a<=5;a++)
   	     {
   	     	if(temp1->next!=head.top || a==1)
   	     	{
   	     	   printf("\n\t+---------+ circular");
   	     	   printf("\n\t|");
   	     	   printf("\n\t| nomor pesanan : %d",temp1->nopesan);

   	     	for(int c=0; c<=4; c++)
   	     	{
   	           printf("\n\t| pesanan : %s ",temp1->pesanan[c]);
   	           printf("\n\t| jumlah	   : %d ",temp1->jumlah[c]);
   	        }
   	    	   printf("\n\t|");
   	           printf("\n\t+---------+\n\n ");

			   temp1 = temp1->next;
   	     	}
   	 	 }
   }

   temp1 = head1.top;
   e=head.count/5;

    if(head.count < 5)
   {
         printf("\n\tNULL\n");
   }
   else
   {
   	     for(int a=1;a<=e;a++)
   	     {
   	     	   printf("\n\t+---------+ circular");
   	     	   printf("\n\t|");
   	           printf("\n\t| no meja : %i ",nomeja);
   	    	   printf("\n\t|");
   	           printf("\n\t+---------+\n\n ");

   	    	   nomeja++;
			   temp1 = temp1->prev1;
   	     }
   }
   getch();
}

	void dequeue (queue *head,queue1 *head1)
	{
		system("cls");

		node *temp,*temp1;


		temp = head->top;
		head->top = temp->next;
		printf("dequeue : %d",temp->nopesan);
		getch();
		temp->next = NULL;

		if(head1->count % 5 == 0 && head1->count != 0)
		{
			head1->top->next1 = temp;
			temp->prev1 = head->top;
		}

		if(head1->count%5==0)
		{
			head1->top=temp;
			temp->next = head1->top;
		}
		else
		{
			temp->next = head1->top->next;
			head1->top->next = temp;
		}
		head1->count=(head1->count)+1;
	//	head->count=(head->count)-1;



	}

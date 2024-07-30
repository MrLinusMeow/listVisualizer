#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char key;
	struct node* next;
} node;
typedef node** list;

list initList();

list initList(){
	node* head = (node*) malloc(sizeof *head);
	node* z = (node*) malloc(sizeof *z);
	node** list = (node**)malloc((sizeof head) + (sizeof z));
	head->next = z;
	head->key = 'S';

	z->next = z;
	z->key = 'l';

	list[0] = head;
	list[1] = z;
	return list;
}

node* addAfter( char k, node* t){
	node* new = (node*)malloc(sizeof *new);
	new->key = k;
	new->next = t->next;
	t->next = new;
	return new;
}


int main(){
	list l = initList();

	l[2] = (node*)malloc(sizeof *l);
	l[2] = addAfter('a', l[0]);

	l[3] = (node*)malloc(sizeof *l);
	l[3] = addAfter('g', l[0]);

	l[4] = (node*)malloc(sizeof *l);
	l[4] = addAfter('r', l[0]);

	l[5] = (node*)malloc(sizeof *l);
	l[5] = addAfter('e', l[0]);

	printf("Creating list:\n");
	printf("\thead: %c \e[91m[%p]\e[0m->\e[96m[%p]\e[0m\n", l[0]->key, l[0], l[1]);
	printf("\tbutt: %c \e[96m[%p]\e[0m->\e[96m[%p]\e[0m\n", l[1]->key, l[1], l[1]->next);
	printf("\n\t+ %c \e[92m[%p]\e[0m->\e[96m[%p]\e[0m\n", l[2]->key, l[2], l[2]->next);
	printf("\t^ \e[91m[head]\e[0m->\e[92m[%p]\e[0m\n", l[2]);
	printf("\n\t+ %c \e[93m[%p]\e[0m->\e[92m[%p]\e[0m\n", l[3]->key, l[3], l[3]->next);
	printf("\t^ \e[91m[head]\e[0m->\e[93m[%p]\e[0m\n", l[3]);
	printf("\n\t+ %c \e[94m[%p]\e[0m->\e[93m[%p]\e[0m\n", l[4]->key, l[4], l[4]->next);
	printf("\t^ \e[91m[head]\e[0m->\e[94m[%p]\e[0m\n", l[4]);
	printf("\n\t+ %c \e[95m[%p]\e[0m->\e[94m[%p]\e[0m\n", l[5]->key, l[5], l[5]->next);
	printf("\t^ \e[91m[head]\e[0m->\e[95m[%p]\e[0m\n", l[5]);

	printf("\nResult:\n");
	node* t = l[0];
	char c = '1';
	for(int i = 0; ; ++i){
		if(c >= '2' && c <= '5') c = '6'-(char)i;
		if(i == 6) {printf("\t%c \e[9%cm[%p]\e[0m\n\t...\n", t->key, c, t); break;}
		printf("\t%c \e[9%cm[%p]\e[0m\n", t->key, c, t);
		printf("\t  V\n");
		if(i==0) ++c;
		if(i==4) c = '6';
		t = t->next;
	}

	free(l);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char key;
	struct node* next;
} node;
typedef node** list;

list initList(){
	node* head = (node*) malloc(sizeof *head);
	node* butt = (node*) malloc(sizeof *butt);
	node** list = (node**) malloc((sizeof head) + (sizeof butt));

	head->next = butt;
	head->key = 0xff;

	butt->next = butt;
	butt->key = 0x0;

	list[0] = head;
	list[1] = butt;
	printf("\thead: %x \e[92;1m[%p]\e[0m->\e[91;1m[%p]\e[0m\n", list[0]->key, list[0], list[0]->next);
	printf("\tbutt: %x \e[91;1m[%p]\e[0m->\e[91;1m[%p]\e[0m\n", list[1]->key, list[1], list[1]->next);
	return list;
}

node* addAfter( char k, node* t){
	node* new = (node*) malloc(sizeof *new);
	new->key = k;
	new->next = t->next;
	t->next = new;
	printf("\n\t+add %2x \e[96;1m[%p]\e[0m-> %2x \e[94;1m[%p]\e[0m\n", new->key, new, new->next->key, new->next);
	return new;
}

void delAfter( node* t){
	printf("\n\t-del %2x \e[97;100;1m[%p]\e[0m\n", t->next->key, t->next);
	node* x = (node*) malloc(sizeof *x);
	x = t->next->next;
	free(t->next);
	t->next = x;
}

void switchPositionOfNext(node* A, node* B){
	printf("\n\tswitching position: %2x \e[30;103m[%p]\e[0m <=> %2x \e[30;103m[%p]\e[0m\n", A->next->key, A->next, B->next->key, B->next);
	node* t = (node*) malloc(sizeof t->next);
	t = A->next->next;
	A->next->next = B->next->next;
	B->next->next = t;
	t = A->next;
	A->next = B->next;
	B->next = t;
}

void switchKeys(node* a, node* b){
	printf("\n\tswitching key values: \e[30;103m%2x\e[0m [%p] <=> \e[30;103m%2x\e[0m [%p]\n", a->key, a, b->key, b);
	node* t = (node*) malloc(sizeof t->key);
	t->key = a->key;
	a->key = b->key;
	b->key = t->key;
	free(t);
}

int main(){
	printf("Creating list:\n");
	list l = initList();
	for(int i = 2; i < 26 ; i++){
		l[i] = (node*) malloc(sizeof *l);
	}
	for(int i = 2; i < 26 ; i++){
		l[i] = addAfter((char)i+'a', l[0]);
		if(i==12) {
			delAfter(l[i]);
		}
		if(i==17) {
			switchPositionOfNext(l[i-1], l[8]);
		}
		if(i==4) {
			switchKeys(l[2],l[i]);
		}
		if(i==24) {
			delAfter(l[i]);
		}
	}

	printf("\nResult:\n");
	node* t = l[0];
	char x = '2';
	char y = '1';
	for(int i = 0; ; ++i){
		y = (y % 58) ? y : '0';
		if(y == '0') ++x;
		if( (x == '9') && (y == '9') ) x = '2';
		
		if(t == t->next) {printf("\t%2x \e[38:5:%c%cm[%p]\e[0m\n\t...\n", t->key, x, y, t); break;}
		
		printf("\t%2x \e[38:5:%c%cm[%p]\e[0m\n", t->key, x, y, t);
		printf("\t  V\n");
		t = t->next;
		++y;
	}

	free(l);
	return 0;
}

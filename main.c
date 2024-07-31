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
	node** list = (node**)malloc((sizeof head) + (sizeof butt));

	head->next = butt;
	head->key = 1;

	butt->next = butt;
	butt->key = '\0';

	list[0] = head;
	list[1] = butt;
	printf("\thead: %x \e[92;1m[%p]\e[0m->\e[91;1m[%p]\e[0m\n", list[0]->key, list[0], list[0]->next);
	printf("\tbutt: %x \e[91;1m[%p]\e[0m->\e[91;1m[%p]\e[0m\n", list[1]->key, list[1], list[1]->next);
	return list;
}

node* addAfter( char k, node* t){
	node* new = (node*)malloc(sizeof *new);
	new->key = k;
	new->next = t->next;
	t->next = new;
	node* head = (*(&t));
	head->key += 1;
	printf("\n\t+add %2x \e[96;1m[%p]\e[0m-> %2x \e[94;1m[%p]\e[0m\n", new->key, new, new->next->key, new->next);
	printf("\t\e[92;1m[head key]\e[0m + 1 = %2x\n", head->key);
	return new;
}

void delAfter( node* t){
	printf("\t-del %2x \e[90;1m[%p]\e[0m\n", t->next->key, t->next);
	node* x = (node*) malloc(sizeof *x);
	x = t->next->next;
	free(t->next);
	t->next = x;
	node* head = *(&t);
	head->key -= (head->key != 0);
	printf("\t\e[92;1m[head key]\e[0m - 1 = %2x\n", head->key);
}

int main(){
	list l = initList();

	printf("Creating list:\n");
	l[2] = (node*)malloc(sizeof *l);
	l[2] = addAfter('n', l[0]);

	l[3] = (node*)malloc(sizeof *l);
	l[3] = addAfter('i', l[0]);

	l[4] = (node*)malloc(sizeof *l);
	l[4] = addAfter('p', l[0]);

	l[5] = (node*)malloc(sizeof *l);
	l[5] = addAfter('s', l[0]);
	delAfter( l[0]);

	printf("\nResult:\n");
	node* t = l[0];
	char c = '1';
	for(int i = 0; ; ++i){
		if(c >= '2' && c <= '5') c = '6'-(char)i;
		if(t == t->next) {printf("\t%2x \e[9%cm[%p]\e[0m\n\t...\n", t->key, c, t); break;}
		printf("\t%2x \e[9%cm[%p]\e[0m\n", t->key, c, t);
		printf("\t  V\n");
		if(i==0) ++c;
		if(i==4) c = '6';
		t = t->next;
	}

	free(l);
	return 0;
}

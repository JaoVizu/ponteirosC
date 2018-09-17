#include <stdio.h>
#include <stdlib.h>
typedef struct numero {
	int n;
} Numero;

int comPonteiro(Numero *n);
int semPonteiro(Numero n);

int main(){
	Numero number;
	printf("\n**** COM PONTEIRO ****\n");
	printf("Without function(no referency) -> %d\n", number.n);
	printf("With a function  -> %d\n", comPonteiro(&number));
	printf("Memory reference -> %d\n", number.n);
	printf("Chamando funcao sem ponteiro ->%d\n",semPonteiro(number));
	return 0;
}

int comPonteiro(Numero *n){
	n->n = 6;
	return n->n;
}
int semPonteiro(Numero n){
	return n.n;
}
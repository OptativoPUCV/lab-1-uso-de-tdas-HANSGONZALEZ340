#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for (int k = 1 ; k <= 10 ; k++)
   {
      int* valor = (int*) malloc(sizeof(int));
      *(valor) = k;
      pushBack(L, valor); //sin puntero, ya que lo recibe como puntero
   }

   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int tamano = get_size(L);
   int* elemento = first(L);
   for (int k = 0 ; k < tamano ; k++)
   {
      suma += *elemento; //se necesita desreferencia
      elemento = next(L);
   }
   return suma; //estaba return 0;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int tamano = get_size(L);
   int* elemento = first(L);
   for (int k = 0 ; k < tamano ; k++)
   {
      if (*elemento == elem) 
      {
         popCurrent(L);
      }
      elemento = next(L);
   }

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();
   int* dato;
   while ((dato = pop(P1)) != NULL){
      push(aux, dato);
   }
   while ((dato = popFront(aux)) != NULL){
      push(P1, dato);
      push(P2, dato);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* L = create_stack();
   char *c = cadena;

   while (*c){
      if (*c == '(' || *c == '{' || *c == '['){
         push(L, c);
      } else if (*c == ')' || *c == '}' || *c == ']'){
         if (get_size(L)== 0){
            return 0;
         } 
         char *sea = pop(L);
         if ((*c == ')' && *sea != '(') || (*c == '}' && *sea != '{') || (*c == ']' && *sea != '['))
         {
            return 0;
         }
      }
      c++;     
   }

   return (get_size(L) == 0) ? 1 : 0;
}


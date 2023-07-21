#include <iostream>
#include <cstdlib>
using namespace std;
struct t_no{
int id;
struct t_no *prox;
}typedef no;
void imprimir(no *cabeca){
  no *aux = cabeca;
  while(aux != NULL){
    cout<<aux->id<<endl;
    aux = aux->prox;
  }
}
void buscar(no *cabeca, int n){
  no *aux = cabeca;
  while(aux != NULL){
    if(aux->id == n){
      cout<<"numero encontrado"<<n<<endl;
      return;
    }
    else{
      aux = aux->prox;
    }
  }
  cout<<"nao encontrado"<<endl;
}
int inserir(no **cabeca, int id){
  no *aux = (no*)malloc(sizeof(no));
  no *temp = NULL;
  aux->id = id;
  aux->prox = NULL;
  if(*cabeca == NULL){
    *cabeca = aux;
  }
  else{
    temp = *cabeca;
    while(temp->prox != NULL){
      temp = temp->prox;
    }
    temp->prox =aux;
  }
  return 1;
}
int excluir(no **cabeca, int id){
  no *temp = *cabeca;
  no *ant = NULL;
  while(temp != NULL){
    if(temp->id == id){
      if(ant != NULL){
      ant->prox = temp->prox;
      }
      else{
      *cabeca = temp->prox;
      }
    free(temp);
    return 1;
  }
  else{
    ant = temp;
    temp = temp->prox;
  }
}
}
void quantidade(no *cabeca){
  no *aux = cabeca;
  int acum = 1; //aqui parto do pressuposto de que a cabeça é == a um valor
  while(aux->prox != NULL){
   
    acum++;
    aux = aux->prox;
   
  }

  cout<<"a quantidade e : "<<acum<<endl;
}

int uni_list(no **cabeca, no **cabeca2){
  no *aux = *cabeca;
  while(aux->prox != NULL){
    aux = aux ->prox;
  }
   aux->prox = *cabeca2;
    *cabeca = *cabeca2;
}

int main(){
no *lista = NULL;
no *lista2 = NULL;
  
  inserir(&lista, 10);
  inserir(&lista, 5);
  inserir(&lista, 20);
  inserir(&lista, 30);
  
  
  inserir(&lista2, 10);
  inserir(&lista2, 5);
  inserir(&lista2, 20);
  inserir(&lista2, 30);
  imprimir(lista);
  quantidade(lista);
  buscar(lista,200);
  return 1;
}
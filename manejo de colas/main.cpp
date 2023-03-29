#include <iostream>
#include <stdlib.h>
#include "pilas.h"
 
using namespace std;

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
struct cola
{
	nodo *delante;
	nodo *atras;
};

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void encolar(struct cola &q, int valor)
{
	struct nodo *aux = new(struct nodo); // crea una estructura noda para que sea asignado el nuevo valor y lo llama aux
	aux->nro=valor;// al elemento nro de aux le asigno valor
	aux->sgte=NULL;// al elemento sgte de aux le asigno NULL
	if(q.delante==NULL)//si q.adelante es igual a NULL, es decir que la cola está vacia, 
		q.delante = aux;// le asigna a q.adelante el valor de aux;q.delante 100pre apunta al primer elemnento de la cola.
	else // de lo contrario
		q.atras->sgte= aux; // le asigna al elmento sgte de q.atras el valor de aux
	q.atras=aux;// q.atras es igual a aux; q.tras 100pre apunta al ultimo valor de la cola.
} 
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
int desencolar(struct cola &q)
{
	int num; // crea una variable de tipo entera
	struct nodo *aux;// crea un variable tipo nodo que es puntero a aux.
	aux= q.delante;// aux será q.delanten que ya está asignado como el 1er elemento de la cola
	num=aux->nro;//num es igual a el elemento nro del auxiliar
	q.delante=(q.delante)->sgte;//q.delante será igual al elemento sgte de q.delante, es decir el 2do elemento de la cola
	delete(aux); // se elimina el nodo aux creado al principio del procedimiento
	return num; // retorna num para ser mostrado en pantalla.
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void mostrarCola(struct cola q)
{
	struct nodo *aux;// crea un nodo tipo puntero auxiliar
	aux=q.delante;// aux es igual a q.deltante, es decir el primer elemento de la cola
	while(aux!=NULL)// mientras qeu aux sea diferente de NULL
	{
		cout<<"  "<<aux->nro;//imprime un pantalla el elemento nro de auxiliar
		aux=aux->sgte;// y auxiliar ahora es elemento sgt de aux
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void vaciacola(struct cola &q)
{
	struct nodo *aux;// crea un nodo auxiliar
	while(q.delante != NULL)//mientras que q.delante dea diferente de NuLL
	{
		aux=q.delante; //aux sera igual a q.delante
		q.delante= aux->sgte; //q.delante es igual el elemento sgte de aux
		delete (aux); // se borra el nodo aux.
	}
	q.delante=NULL;
	q.atras=NULL;	
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
void invertir_cola(struct cola &q,ptrPila &p)
{
	struct nodo *aux;// crea un nodo auxiliar
	while(q.delante != NULL)//mientras que q.delante dea diferente de NuLL
	{
		aux=q.delante; //aux sera igual a q.delante
		q.delante= aux->sgte; //q.delante es igual el elemento sgte de aux
		push(p,aux->nro);
	}
	vaciacola(q);
	//mostrar_pilax(p);
	ptrPila aux1=p;
	while(aux1!=NULL)
	{
		encolar(q,aux1->nro);
		aux1=aux1->sgte;
	}
	mostrarCola(q);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void informarX(struct cola &q,int x)
{
	struct nodo *aux;
	aux=q.delante;
	while(aux!=NULL)
	{
		if(aux->nro==x)	
		{
			cout<<x<<" se encuentra en cola";
			break;
		}
		else if(aux->sgte == NULL)
		{
			cout<<x<<" No se encuentra en la cola";
			break;	
		}
		else
			aux=aux->sgte;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void ascendente(struct cola &q)
{
	struct nodo *aux;
	aux=q.delante;
	while(aux!= NULL)
	{
		if((aux->nro) < (aux->sgte->nro) )
			{
				if(aux->sgte->sgte == NULL)	
					{
						cout<<"esta ordenada ascendentemente";
						break;
					}
				else
					aux=aux->sgte;
			}
		else
			{
				cout<<"No esta ordenada ascendentemente";
				break;
			}				
	}
	delete(aux);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void cola1(struct cola &q1)
{
	int n;
	int q;
	cout<<"\nentre un numero para encolar:";cin>>n;
	encolar(q1,n);
	cout<<"\nsi desea continuar encolando presione 1: ";cin>>q;
	if(q==1)
		cola1(q1);
	else
		cout<<"\nse termino de encolar la cola 1.";
}

void cola2(struct cola &q2)
{
	int n;
	int q;
	cout<<"\nentre un numero para encolar:";cin>>n;
	encolar(q2,n);
	cout<<"\nsi desea continuar encolando presione 1: ";cin>>q;
	if(q==1)
		cola2(q2);
	else
		cout<<"\nse termino de encolar la cola 2.";
}

void compararColas(struct cola &q1,struct cola &q2)
{
	struct nodo *aux1 ;
	struct nodo *aux2 ;
	aux1=q1.delante;
	aux2=q2.delante;
	while(aux1!=NULL and aux2!=NULL)
	{
		if(aux1->nro == aux2->nro)
		{
			if(aux1->sgte->sgte == NULL and aux2->sgte->sgte==NULL)
			{
				cout<<"\nLas colas 1 y 2 son iguales ";
				break;
			}
			else
			{
				aux1=	aux1->sgte;
				aux2=	aux2->sgte;
			}
		}
		else
		{
			cout<<"\nlas colas 1 y 2 No son iguales";
			break;
		}	
	}
	
	delete(aux1);
	delete(aux2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void posX(struct cola &q,int x,int pos)
{
	struct nodo *aux;
	struct cola q3;
	q3.delante=NULL;
	q3.atras=NULL;
	aux=q.delante;
	int cont=1;
	
	while(aux!=NULL)
	{
		if(cont==pos)
		{
			encolar(q3,x);
		}
		else
		{
			encolar(q3,aux->nro);	
			aux=aux->sgte;
		}
		cont++;
	}
	q=q3;
	delete(aux);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void organizarColas(struct cola &q,struct cola &q1,struct cola &q2,int x)
{
	struct nodo *aux;
	aux=q.delante;
//	struct nodo *aux1;
//	aux1=q1.delante;
//	struct nodo *aux2;
//	aux2=q2.delante;
	
	while(aux!= NULL)
	{
		if(aux->nro > x)
		{
			encolar(q1,aux->nro);
			aux=aux->sgte;
		}
		else
		{
			encolar(q2,aux->nro);
			aux=aux->sgte;
		}	
	}
	delete(aux);
	mostrarCola(q1);
	cout<<"\n\n";
	mostrarCola(q2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

void menu()
{
	cout<<"\n\t implementacion de colas en c++\t\n";
	cout<<"1. encolar\n";
	cout<<"2. desencolar\n";
	cout<<"3. mostrar cola\n";
	cout<<"4. vaciar cola\n";
	cout<<"5. invertir cola \n";
	cout<<"6. informar si un elemento x esta en la cola\n";
	cout<<"7. indicar si la cola se encuentra ordenada ascendentemente\n";
	cout<<"8. indicar si las cola 1 y cola 2 son iguales\n";
	cout<<"9. agregar x en la pos de una cola\n";
	cout<<"10. elementos mayores y menores a x en colas diferente\n";
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	ptrPila p = NULL; 
	struct cola q;
	struct cola q1;
	struct cola q2;
	
	q.delante = NULL;
	q.atras= NULL;

	q1.delante = NULL;
	q1.atras= NULL;
	
	q2.delante = NULL;
	q2.atras= NULL;
	
	int dato;
	int op;
	int x;
	
	do{
		menu();
		cin>>op;
		switch(op)
		{
			case 1:
				cout<<"NRO  a encolar : ";cin>>dato;
				encolar(q,dato);
				cout<<"\n\n\t Numero "<< dato<< " encolado..\n\n";
				break;
			case 2:
				x = desencolar(q);
				cout<<"numero "<<x<<" desencolado";
				break;
			case 3:
				cout<<"Mostrando cola\n\n";
				if(q.delante!=NULL)
					mostrarCola(q);
				else
				 	cout<<"Cola vacia";
				break;
			case 4:
				cout<<"Vaciar cola\n\n";
				vaciacola(q);
				cout<<"PilaVacia";
				break;
			case 5:
				cout<<"cola invertida: \n";
				invertir_cola(q,p);
				break;
			case 6:
				int n;
				cout<<"enter un numero para mirar si está en la cola: ";cin>>n;
				informarX(q,n);
				break;
			case 7:
				ascendente(q);
				break;
			case 8:
				cola1(q1);
				cola2(q2);
				compararColas(q1,q2);
				break;
			case 9:
				int u;
				int o;
				cout<<"\nentre un elemento x: ";cin>>u;
				cout<<"\nentre una posicion: ";cin>>o;
				posX(q,u,o);
				break;
			case 10:
				int f;
				cout<<"entre un elemento x para organiazar las colas: ";cin>>f;
				organizarColas(q,q1,q2,f);
				break;
				
			
			
		}
		cout<<endl<<endl;
		system("pause");system("cls");
	}while(op!=5);
}

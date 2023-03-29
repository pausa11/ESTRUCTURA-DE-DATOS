#include "listas.h"
#include "pilas.h"
 
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------*/

void menu()
{
	cout<<"\n\t Lista enlazada simple\n\n"<<endl;
	cout<<"1. insertar el inicio."<<endl;
	cout<<"2. insertar al final."<<endl;
	cout<<"3. insertar en una posicion."<<endl;
	cout<<"4. Mostrar lista"<<endl;
	cout<<"5. Buscar elemento."<<endl;
	cout<<"6. Eliminar elemento X"<<endl;
	cout<<"7. Eliminar elementos con valor X"<<endl;
	cout<<"8. numero de veces x en una lista."<<endl;
	cout<<"9. Invertir lista."<<endl;
	cout<<"10. Promedio de valores de la lista."<<endl;
	cout<<"11. devolver el dato mayor."<<endl;
	cout<<"12. indicar si esta ordenada ascendentemente."<<endl;
	cout<<"13. salir"<<endl;
	cout<<"\n Ingrese una opcion: "<<endl;
}

/*---------------------------------------------------------------------------------------------------------------------------*/

void vecesX(Tlista &lista,int x)
{
	Tlista aux;
	aux=lista;
	int cont=0;
	while(aux!=NULL)
	{
		if(aux->nro==x)
		{
			if(aux->sgte->sgte==NULL)
			{
				cont++;	
				cout<<"\nel valor "<<x<<" se encuentra en la lista "<<cont<<" veces."<<endl;
				aux=aux->sgte;
			}
			else
			{
				cont++;	
				aux=aux->sgte;	
			}
			
		}
		else
			aux=aux->sgte;		
	}
	delete(aux);
}

/*---------------------------------------------------------------------------------------------------------------------------*/

void invertirLista(Tlista &lista,ptrPila &p)
{
	Tlista aux,aux1;
	aux=lista;
	aux1=NULL;
	while(aux != NULL)
	{
		push(p,aux->nro);
		aux=aux->sgte;
	}
	while(p!=NULL)
	{
		insertarFinal(aux1,p->nro);
		p=p->sgte;
	}
	lista=aux1;
}

/*---------------------------------------------------------------------------------------------------------------------------*/

void promedioLista(Tlista &lista)
{
	int cont=0;
	int cont1=0;
	Tlista aux;
	aux=lista;
	while(aux!= NULL)
	{
		cont++;
		cont1=cont1+aux->nro;
		aux=aux->sgte;
	}
	float promedio= cont1/(float)cont;
	printf("\nel promedio es de %.2f", promedio); 
	delete(aux);
}

/*---------------------------------------------------------------------------------------------------------------------------*/

void datoMayor(Tlista &lista)
{
	Tlista aux;
	aux=lista;
	int cont=0;
	while(aux!= 0)
	{
		if(cont<aux->nro)
		{
			cont=aux->nro;	
			aux=aux->sgte;
		}	
		else
			aux=aux->sgte;
	}
	cout<<"\nel dato mayor es: "<<cont;
	delete(aux);
}

/*---------------------------------------------------------------------------------------------------------------------------*/

void ascendente(Tlista &lista)
{
	Tlista aux;
	aux= lista;
	
	while(aux!=NULL)
	{
		if(aux->nro < aux->sgte->nro)
		{
			if(aux->sgte->sgte==NULL)
			{
				cout<<"\nesta organizada ascendentemente.";
				aux=aux->sgte;
			}
			aux=aux->sgte;
		}
		else
		{
			cout<<"\nNo esta ordenada ascendentemente.";
			break;
		}
	}
}

/*---------------------------------------------------------------------------------------------------------------------------*/

int main()
{	
	ptrPila p=NULL;
	Tlista lista=NULL;
	int _op;
	int _dato;
	int pos;
	system("color 0b");
	do
	{
		menu();
		cin>>_op;
		switch(_op)
		{
			case 1:
				cout<<"\n Numero a insertar: ";
				cin>>_dato;
				insertarInicio(lista, _dato);
				break;
			case 2:
				cout<<"\n Numero a insertar: ";
				cin>>_dato;
				insertarFinal(lista,_dato);
				break;
			case 3:
				cout<<"\n Numero a insertar: ";
				cin>>_dato;
				cout<<"posicion: ";
				cin>>pos;
				insertarElemento(lista,_dato,pos);
				break;
			case 4:
				cout<<"\n\n Mostrando lista\n\n";
				MostrarLista(lista);
				break;
			case 5:
				cout<<"\n valor a buscar: ";
				cin>>_dato;
				buscarElemento(lista,_dato);
				break;
			case 6:
				cout<<"\n Valor a eliminar: ";
				cin>>_dato;
				eliminarElemento(lista,_dato);
				break;
			case 7:
				cout<<"\n valor repetidos a eliminar: ";
				cin>>_dato;
				eliminarRepetidos(lista,_dato);
				break;
			case 8:
				int e;
				cout<<"\nentre un numero para saber cuantas veces esta en la lista: ";
				cin>>e;
				vecesX(lista,e);
				break;
			case 9:
				invertirLista(lista,p);
				break;
			case 10:
				promedioLista(lista);
				break;
			case 11:
				datoMayor(lista);
				break;
			case 12:
				ascendente(lista);
				break;
		}
		cout<<endl<<endl;
		system("pause");
		system("cls");
	}while(_op!=8);
	system("pause");
	return 0;
}

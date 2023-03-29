#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct nodo//estructura llamada "nodo"
{
     int nro;
     struct nodo *sgte;/*puntero a una estructura de tipo "nodo" llamado "sgte"Esto permite crear una estructura enlazada, donde cada nodo contiene un 
	 número entero y un puntero al siguiente nodo en la lista.*/
};
typedef nodo *ptrPila; //variable que sea un puntero a una estructura "nodo"

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void push(ptrPila &p, int valor)/*push(p,dato); La función "push" recibe dos argumentos: un puntero a la pila ("p") y el valor que se va a agregar a la pila ("valor").
El primer argumento es un puntero por referencia, lo que significa que se puede modificar el valor al que apunta el puntero dentro de la función y que ese 
cambio también afectará al valor fuera de la función.*/
{
    ptrPila aux;
    aux= new(struct nodo); /*Dentro de la función, se crea un nuevo nodo utilizando la sintaxis "new(struct nodo)", lo que asigna memoria para un nuevo nodo de 
	tipo "nodo" y devuelve un puntero al mismo. Este nuevo nodo se almacena en una variable llamada "aux".*/
    aux->nro= valor;/*se asigna el valor "valor" al miembro "nro" del nodo "aux" utilizando la sintaxis "aux->nro = valor". Luego, se establece el puntero "sgte" 
	del nodo "aux" para que apunte a la pila original "p" utilizando la sintaxis "aux->sgte = p".*/
    aux->  sgte=p;
    p=aux;/*Finalmente, se actualiza el puntero de la pila "p" para que apunte al nuevo nodo "aux" utilizando la sintaxis "p = aux". Esto significa que el nuevo nodo 
	se ha agregado correctamente a la pila y se convierte en el nuevo elemento superior de la misma.*/
} 

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int pop(ptrPila &p)//funcion para sacar el ultimo elemento de la pila; se le entrega &p de tipo puntero de nodo
{
    int num; //variable num de tipo entero.
    ptrPila aux; //variable tipo puntero de nodo llamado aux

    aux=p; // aux será igual a la pila p
    num= aux->nro;// num será igual al elemento nro de la pila aux

    p=aux-> sgte; //p Será igual a el elemento sgt de la pila aux
    delete(aux); // se elimina la pila aux

    return num; // returna el numero para mosrtrar que fue sacado en pantalla
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void mostrar_pilax(ptrPila p)// Funcion para mostrar la pila
{
    ptrPila aux; // crea una pila auxiliar
    aux=p; // la pila auxiliar será igual a p
    while(aux != NULL) // ciclo "while" mientras que aux sea diferente de null; es decir hasta que llegue a la ultima parte del nodo
    {
        cout<<"\t"<<aux->nro<<endl; // imprime en pantalla al elemento nro del auxuliar
        aux= aux-> sgte; // auxiliar sera el elemento sgte de la fila
    }
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void destruir_pila(ptrPila &p) // funcion para destruir una pila
{
    ptrPila aux; // crea una pila axiliar
    while(p != NULL) // mientras que p sea diferente de null hace un ciclo
    {
        aux=p; // aux sera igual a p
        p= aux-> sgte; // p sera el elemento sgte de auxuliar
        cout<<"%d"<<aux<<endl; // imprime en pantalla al auxiliar 
        delete(aux);// elimina a axiliar;
    }
}

void invertir_pila(ptrPila &p)//&p indica que está trabajando en la direccion de memoria de p;
{
	ptrPila Pilaux;// puntero tipo nodo que apunta a una pila auxiliar;
	Pilaux= NULL;// le decimos a pila aux que sea nuLL, es decir 0
	while(p != NULL)// mientras que el valor en la direccion de memoria sea diferente de 0
	{
		push(Pilaux,pop(p)); // se llama a push para que meta pilaaux, que es igual a null en el primer momento, y de valor le entrega a pop de retorna un num 
		//pop, a su vez le devuelve el primer elemento de la pila, por eso mismo se invierte.
	}
	p=Pilaux; // redefine a la direccion de memoria p(&p) como Pilaux, es decir se entrega invertido
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void Mostrar_x(ptrPila &p, int valor)//funcion mostrar si un elemento X se encuentra en la pila, se le entrega la cabeza de la pila y un entero
{
	ptrPila aux; // le entraga una pila aux
	aux = p;// la pila auxiliar contiene lo mismo que p
	while(aux != NULL) // mientras que el auxiliar sea diferente del NULL
	{
		if(valor == aux->nro) // se pregunta si el valor que entro el usuario es igual al valor nro del auxiliar
		{
			cout<<"el valor "<<valor<<" se encuentra en la pila"; // si es verdad imprime el valor que se encuentra en la lista
			break;// se para el ejecucion del ciclo
		}
		else if (valor != aux->nro) // de lo contrario
		{
			if(aux->sgte == NULL)
			{
				cout<<"\n\tNo se encuentra en la pila";
				break;
			}
			else
				aux= aux-> sgte; // aux vale lo que vale el elemento sgte de aux
		} 
	}	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*void Asendente(ptrPila &p)
{
	ptrPila aux;
	aux=p;
	ptrPila cont;
	cont=p;
	cont=cont->sgte;
	for(aux;aux!=NULL;aux=aux->sgte)
	{
		if((cont->nro)<(aux->nro)) 
    //	if(cont<aux) 
		{
			cout<<cont->nro<<" es menor que "<<aux->nro;
			cout<<", está en orden asendente\n"; 
			cont=cont->sgte	;
		}	
		else
		{
			cout<<"no está en orden asendente\n";
			cout<<cont<<" no es mayor que "<<aux<<endl;
			cout<<cont->nro<<" no es mayor que "<<aux->nro;
			break;
		}
	}
	
}*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void Ascendente(ptrPila p) 
{
    if (p == NULL || p->sgte == NULL) 
	{
        // Caso base: la pila está vacía o tiene un solo elemento, no se puede determinar el orden
        cout << "La pila no tiene suficientes elementos para determinar el orden." << endl;
        return;
    }

    ptrPila anterior = p;
    ptrPila actual = p->sgte;

    while (actual != NULL) 
	{
        if (actual->nro <= anterior->nro) 
		{
            // Los elementos no están en orden ascendente
            cout << "Los elementos de la pila no están en orden ascendente." << endl;
            return;
        }

        anterior = actual;
        actual = actual->sgte;
    }

    // Si llegamos aquí, la pila está en orden ascendente
    cout << "Los elementos de la pila están en orden ascendente." << endl;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void PilaUno(ptrPila &p1)
{
	int dato;
	int x;
	cout<<"Numero a apilar: "; cin>>dato;
	push(p1,dato);
    cout<<"\n\n\t\tNumero "<< dato << " apilado...\n\n";
    cout<<"escriba 1 si desea continuar apilando: ";
	cin>>x;
    if (x == 1)
    	PilaUno(p1);
    else
    {
    	cout<<"Pila apilada: ";
    	mostrar_pilax(p1);
	}
}

void PilaDos(ptrPila &p2)
{
	int dato;
	int x;
	cout<<"Numero a apilar: "; cin>>dato;
	push(p2,dato);
    cout<<"\n\n\t\tNumero "<< dato << " apilado...\n\n";
    cout<<"escriba 1 si desea continuar apilando: ";
	cin>>x;
    if (x == 1)
    	PilaDos(p2);
    else
    {
    	cout<<"Pila apilada: ";
    	mostrar_pilax(p2);
	}
}

void compararPilas(ptrPila &p1,ptrPila &p2)
{
	ptrPila aux1=p1;
	ptrPila aux2=p2;
	
	while(aux1!=NULL and aux2!=NULL )
	{
		if(aux1->nro == aux2->nro)
		{
			if(aux1->sgte ==NULL and aux2->sgte==NULL)
			{
				cout<<"SON IGUALES";
				break;
			}
			else
			{
				aux1= aux1->sgte;
				aux2= aux2->sgte;	
			}	
		}
		else
		{
			cout<<"No son iguales"	;
			break;
		}
	}
}

/*void compararPilas(ptrPila p1, ptrPila p2) 
{
    // Check for empty stacks
    if (p1 == NULL || p2 == NULL) 
	{
        cout << "No son iguales" << endl;
        return;
    }
    
    // Initialize flag variable and counter
    bool igual = true;
    int i = 0;
    
    // Loop through the stacks
    for (ptrPila aux1 = p1, aux2 = p2; aux1 != NULL && aux2 != NULL; aux1 = aux1->sgte, aux2 = aux2->sgte) 
	{
        i++;
        if (aux1->nro != aux2->nro) 
		{
            igual = false;
            break;
        }
    }
    
    // Check whether the stacks are equal
    if (igual && aux1 == NULL && aux2 == NULL) 
	{
        cout << "SON IGUALES" << endl;
    } 
	else 
	{
        cout << "No son iguales" << endl;
    }
}*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void sacar_x(ptrPila &p, int x)
{
	ptrPila aux=p;
	ptrPila aux2=NULL;
	for(aux->nro;aux!=NULL;aux=aux->sgte)
	{
		if(aux->nro != x)
		{
			push(aux2,aux->nro);
		}
	}
	mostrar_pilax(aux2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void x_pos(ptrPila &p,int x,int pos)
{
	ptrPila aux=p;
	ptrPila aux2=NULL;
	int i=1;
	while(aux != NULL)
	{
		if(pos==i)
		{
			push(aux2,x);
			
		}
			
		else
		{
			push(aux2,aux->nro);
			aux=aux->sgte;
		
		}
			
	i++;	
	}
	mostrar_pilax(aux2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void orden(ptrPila &p1,ptrPila &p2,ptrPila &p,int u)
{
	ptrPila aux=p;
	while(aux!= NULL)
	{
		if(aux->nro > u)
			push(p1,aux->nro);
		else
			push(p2,aux->nro);
	aux=aux->sgte;
	}
	mostrar_pilax(p1);
	cout<<"\n\n\n";
	mostrar_pilax(p2);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void menu()
{
    cout<<"\nImplementcion de pilas en c++\n\n";
    cout<<"1. Apilar\n";
    cout<<"2. desapilar\n";
    cout<<"3. Mostrar pila\n";
    cout<<"4. Destruir pila\n";
    cout<<"5. invertir pila\n";
    cout<<"6. Mostrar si una valor está en la pila\n";
    cout<<"7. Indica si una pila se encuentra en orden asendente\n";
    cout<<"8. inidicar si las pilas p1 y p2 son iguales\n"; 
    cout<<"9.Hacer una función que reciba una pila de objetos y saque de la pila el objeto X (siexiste)\n";
    cout<<"10. Agrega el elemento X en la posición pos de la pila P\n";
    cout<<"11. deja en la pila P1 los elementos de P mayores que X y en P2 los otros\n";
    cout<<"12. Salir\n";
    cout<<"Ingrese opcion: ";
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    ptrPila p = NULL; /*inicializando el puntero "p" a NULL, lo que significa que la pila está vacía.*/
    ptrPila p1 = NULL;
    ptrPila p2 = NULL;
    int dato;
    int op;
    int x;
    system("color 0b");
    do
    {
        menu(); cin>>op;
        switch(op)
        {
        case 1:/*Si el usuario selecciona la opción 1, se le solicita que ingrese un número ("dato") y se llama a la función "push" para agregarlo a la pila. 
			Luego, se muestra un mensaje indicando que el número se ha agregado correctamente.*/
			cout<<&p<<endl;
            cout<<"Numero a apilar: "; cin>>dato;
            push(p,dato);
            cout<<"\n\n\t\tNumero "<< dato << " apilado...\n\n";
            break;
        case 2:
            x=pop(p);
            cout<<"\n\n\t Numero "<<x<<"desapilado..\n\n";
            break;
        case 3:
            cout<<"\n\nMostrando Pila";
            if(p!=NULL)
                mostrar_pilax(p);
            else
                cout<<"\n\n\tPila vacia..!";
            break;
        case 4:
            destruir_pila(p);
            cout<<  "\n\n\t\tPila eliminada..!";
            break;
        case 5:
        	cout<<"\n\n\t\tPila original..\n\n";
        	mostrar_pilax(p);
        	invertir_pila(p);
        	cout<<"\n\n\t\tPila inveertida..\n\n!";
        	mostrar_pilax(p);
        	break;
        case 6:
        	int x;
        	cout<<"entre un valor para saber si se encuentra en la pila: "<<endl;
        	cin>>x;
        	Mostrar_x(p,x);
        	break;
        case 7:
        	Ascendente(p); 
        	break;
        case 8:
        	cout<<"crear pila Nro 1\n";
        	PilaUno(p1);
        	cout<<"crear pila Nro 2\n";
        	PilaDos(p2);
        	compararPilas(p1,p2);
        	break;
        case 9:
        	int dato;
        	cout<<"entre un valor para ser sacado de la lista: ";
        	cin>>dato;
        	sacar_x(p,dato);
        	break;
        case 10:
        	int n;
        	int pos;
        	cout<<"\nentre un dato para ser agregado: ";cin>>n;
        	cout<<"\nentre una posicion para ser agregado: ";cin>>pos;
        	x_pos(p,n,pos);
        	break;
        case 11:
        	int u;
        	cout<<"entre un elemento x: ";
        	cin>>u;
        	orden(p1,p2,p,u);
        	break;
        case 12:
        	cout<<"gracias por usarme";
        	system("cls");
        	return 0;
        	break;
        }
        cout<<endl<<endl;
        system("pause");system("cls");
    }while(op!=5);
    return 0;
}

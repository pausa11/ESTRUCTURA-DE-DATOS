//Programa para organizacion de datos por medio de arboles binarios

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;                                     //para no usar std::cout

/***********************************************************************************************************************/

struct nodo{                                            //estructura de un nodo
     int nro;                                           //valor del nodo
     nodo *izq;                                         //puntero al hijo izquierdo
	 nodo *der;                                         //puntero al hijo derecho
};                                                      //fin de la estructura nodo                               
typedef nodo *ABB;                                      //definicion de ABB

/***********************************************************************************************************************/

ABB crearNodo(int x)                        
{
     ABB nuevoNodo = new(struct nodo);                  //crea un nodo
     nuevoNodo->nro = x;                                //asigna el valor
     nuevoNodo->izq = NULL;                             //puntero izquierdo a NULL
     nuevoNodo->der = NULL;                             //puntero derecho a NULL
     return nuevoNodo;                                  //retorna el nuevo nodo
}

/***********************************************************************************************************************/

void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)                
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

/***********************************************************************************************************************/

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

/***********************************************************************************************************************/

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

/***********************************************************************************************************************/

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}
/***********************************************************************************************************************/
void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
     //global=n;
}

/***********************************************************************************************************************/
 

bool buscar(ABB arbol, int dato)
{
     int r=0;   // 0 indica que lo encontre

     if(arbol==NULL)
        return r;

     if(dato<arbol->nro)
         r = buscar(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = buscar(arbol->der, dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}

/***********************************************************************************************************************/
/*El error específico de el código para eliminar un elemento de un árbol binario de búsqueda es que no maneja 
correctamente el caso en el que el nodo a eliminar tiene dos hijos. En ese caso, en lugar de encontrar el sucesor inmediato 
(el nodo con el valor siguiente más grande) y reemplazar el valor del nodo a eliminar con el valor del sucesor, 
 código simplemente reemplaza el valor del nodo a eliminar con el valor del nodo más grande en su subárbol izquierdo y 
 luego elimina ese nodo. Este enfoque no garantiza que el árbol mantenga su propiedad de ser un árbol de búsqueda binario.*/

/*void eliminar(ABB &arbol,int x)
{
    ABB aux1,aux2;
    if(arbol==NULL) return;                                                 
    if(x>arbol->nro)
         eliminar(arbol->der,x);
    if(x<arbol->nro)
        eliminar(arbol->izq,x);
    if(x==arbol->nro)
    {
        if(arbol->der==NULL && arbol->izq==NULL) //Si el nodo es hoja
        {
            arbol=NULL;
            return;
        }
        if(arbol->der!=NULL && arbol->izq==NULL)
        {
            arbol=arbol->der;
            return;
        }
            aux1=arbol;
            aux2=arbol->izq;
            while(aux2->der!=NULL)
            {
                aux1=aux2;
                aux2=aux2->der;
            }
            arbol->nro=aux2->nro;
            if(aux1==arbol)
                arbol->izq=aux2->izq;
            else
            aux1->der=aux2->izq;
    }
}*/

void eliminar(ABB &arbol, int x) {
    if (arbol == NULL) return;
    if (x < arbol->nro)
    {
        eliminar(arbol->izq, x);
    } 
    else if (x > arbol->nro) 
    {
        eliminar(arbol->der, x);
    } 
    else
     {
        if (arbol->izq == NULL && arbol->der == NULL) 
        { // Nodo hoja
            delete arbol;
            arbol = NULL;
        } else if (arbol->izq == NULL) 
        { // Nodo con un hijo derecho
            ABB temp = arbol;
            arbol = arbol->der;
            delete temp;
        } else if (arbol->der == NULL) 
        { // Nodo con un hijo izquierdo
            ABB temp = arbol;
            arbol = arbol->izq;
            delete temp;
        } else 
        { // Nodo con dos hijos
            ABB temp = arbol->der;
            while (temp->izq != NULL)
            {
                temp = temp->izq;
            }
            arbol->nro = temp->nro;
            eliminar(arbol->der, temp->nro);
        }
    }
}


/***********************************************************************************************************************/


int main()
{
    ABB arbol = NULL;
    int x;
    int op;
    int dato;
    do
    {
        system("cls");
        cout<<"1. Insertar\n2.Eliminar\n3. Buscar\n4. Ver el Arbol\n5. Recorrer el arbol en En-orden\n6. Recorrer el arbol en Pre-orden\n7. Recorrer el arbol en Post-orden\n8. Salir\n ";
        cout<<"Ingrese una opcion: ";
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Ingrese un numero: ";
                cin>>x;
                insertar(arbol,x);
                break;
            case 2:
                cout<<"Ingrese un numero: ";
                cin>>x;
                eliminar(arbol,x);
                break;
            case 3:
                cout<<"Ingrese un numero: ";
                cin>>dato;
                if(buscar(arbol,dato)==1)
                    cout<<"El numero se encuentra en el arbol";
                else
                    cout<<"El numero no se encuentra en el arbol";
                getch();
                break;
            case 4:
                verArbol(arbol,0);
                getch();
                break;
            case 5:
                cout<<"Recorrido en orden: ";
                enOrden(arbol);
                getch();
                break;
            case 6:
                cout<<"Recorrido en pre-orden: ";
                preOrden(arbol);
                getch();
                break;
            case 7:
                cout<<"Recorrido en post-orden: ";
                postOrden(arbol);
                getch();
                break;
            
        }
    }while(op!=8);
    return 0;
}
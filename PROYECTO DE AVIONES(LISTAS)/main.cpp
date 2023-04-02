#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;												//para no tener que poner std:: antes de cada funcion

/********************************************************************************************************************************/

struct Vuelo														//estructura de vuelos								
{	
	char NroDeVuelo[7];												//elemento Nro de vuelo;
	char Origen[9];													//elemento origen
	char Destino[9];												//elemento destino
	char MatriculaAvion[7];											//elemento matricula de avion
	char NombrePiloto[20];											//elemento nombre del piloto
	char HoraVuelo[5];												//elemento hora de vuelo
	char FechaVuelo[7];												//elemento fecha de vuelo	
	int Estado;														//elemento estado		
	struct Vuelo *Sgte;												//stuctura que apunta a la dir de memoria sgte
	struct Pasajeros *ListaPasajeros;
};
typedef struct Vuelo *DatosVuelo; 									//un typedef para definir a una variable tipo puntero de manera mas sencilla

/********************************************************************************************************************************/

struct Pasajeros													//estructura de pasajeros
{
	char NroDeVuelo[7];												//elemento Nro de vuelo;
	char Cedula[10];												//elemnto cedula;
	char NombrePersona[20];											//Elemento Nombre de la persona
	char Telefono[10];												//elemento telefono
	int Estado;														//elemento estado
	struct Pasajeros *Sgte;											//stuctura que apunta a la dir de memorua sgte
};
typedef struct Pasajeros *DatosPasajero;							//un typedef para definir a una variable tipo puntero de manera mas sencilla

/********************************************************************************************************************************/

char cadena[20];													//variable global para guardar los datos del archivo

/********************************************************************************************************************************/

/*
Nombre del proceso: AbrirArchivo(DatosVuelo &Vuelos)
Objetivo:       Extraer de un fichero la informacion y organizarla en listas
Parametros:     DatosVuelo &Vuelos, La lista de los vuelos donde se va a guardar la informacion
Retorna:        Deja en la Lista los datos de los vuelos
Ejemplo:        (En el archivo)
                123456 MED BOG 222222 FELIPEMONTENEGRO 0900 200421 0
                (En la lista)
                Vuelos->NroDeVuelo = 123456
                Vuelos->Origen= MED
                Vuelos->Destino= BOG
                Vuelos->MatriculaAvion= 222222
                Vuelos->NombrePiloto= FELIPEMONTENEGRO
                Vuelos->HoraVuelo= 0900
                Vuelos->FechaVuelo= 200421
                Vuelos->Estado= 0
*/

/********************************************************************************************************************************/

void AbrirArchivo(DatosVuelo &Vuelos)
{
	DatosVuelo Aux;													//Variable para guardar los datos del archivo
    int i;															//Variable para el for
	ifstream leer;													//Variable para leer el archivo
	leer.open("Vuelos.txt",ios::in);								//Abre el archivo

	if (leer.good())												//Verifica si el archivo se abrio correctamente
	{
		cout<<"El archivo fue abierto correctamente..."<<endl;  	//Mensaje de confirmacion										 	
	}
	else
	{
		cout<<"El archivo no se pudo abrir..."<<endl;   			//Mensaje de error
		return;                                                     //Sale del proceso
	}

	while(!leer.eof())                                            	//Mientras no sea el final del archivo
	{
		Aux = new(Vuelo);											//Reserva memoria para el nuevo nodo
		leer>>cadena;												//Lee la cadena
		strcpy(Aux->NroDeVuelo,cadena);								//Copia la cadena en el nodo
    	fflush(stdin);												//Verificador de caracteres							
      	leer>>cadena;
	  	strcpy(Aux->Origen,cadena);
      	fflush(stdin);
      	leer>>cadena;
      	strcpy(Aux->Destino,cadena);
      	fflush(stdin);
      	leer>>cadena;
		strcpy(Aux->MatriculaAvion,cadena);
    	fflush(stdin);
    	leer>>cadena;
      	strcpy(Aux->NombrePiloto,cadena);
      	fflush(stdin);
      	leer>>cadena;
	  	strcpy(Aux->HoraVuelo,cadena);
      	fflush(stdin);
      	leer>>cadena;
	  	strcpy(Aux->FechaVuelo,cadena);
      	fflush(stdin);
	  	leer>>cadena;
	  	Aux->Estado = atof(cadena);
	  	Aux->Sgte = Vuelos;
	  	Vuelos = Aux;
	}
	leer.close();
}

/********************************************************************************************************************************/

// abrir archivo pasajero y guardar en lista
void AbrirArchivoPasajero(DatosPasajero &Usuarios)
{
	DatosPasajero Aux;												//Variable para guardar los datos del archivo
	int i;															//Variable para el for
	ifstream leer;													//Variable para leer el archivo
	leer.open("Pasajeros.txt",ios::in);								//Abre el archivo

	if (leer.good())												//Verifica si el archivo se abrio correctamente
	{
		cout<<"El archivo fue abierto correctamente..."<<endl;  	//Mensaje de confirmacion										 	
	}
	else
	{
		cout<<"El archivo no se pudo abrir..."<<endl;   			//Mensaje de error
		return;                                                     //Sale del proceso
	}

	while(!leer.eof())                                            	//Mientras no sea el final del archivo
	{
		Aux = new(Pasajeros);										//crea un nuevo espacio de memoria en la estructura pasajeros
		leer>>cadena;												//del archivo leer, saca la cadena
		strcpy(Aux->NroDeVuelo,cadena);								//copia el string y se lo asigna a la variable nuemero de vuelo
		fflush(stdin);												//verificador de caracteres
	  	leer>>cadena;												//lee la cadena 
	  	strcpy(Aux->Cedula,cadena);									//se lo asigna a cedula, este proceso se repite con los demas datos del struct
	  	fflush(stdin);
	  	leer>>cadena;
	  	strcpy(Aux->NombrePersona,cadena);
	  	fflush(stdin);
	  	leer>>cadena;
		strcpy(Aux->Telefono,cadena);
		fflush(stdin);
		leer>>cadena;
	  	Aux->Estado = atof(cadena);
	  	Aux->Sgte = Usuarios;
	  	Usuarios= Aux;
	}
	leer.close();
}

/********************************************************************************************************************************/

void MostrarListaVuelos(DatosVuelo vuelo)							//Mostrar lista vuelos
{
	int i=0;														//Variable para el for								
	
	while(vuelo != NULL)											//Mientras no sea el final de la lista
	{
		cout<<' '<<i+1<<")"<<vuelo->Destino<<" "<<					//Muestra los datos de la lista
		vuelo->Origen<<" "<<vuelo->NroDeVuelo<<" "<<				//Destino, origen, numero de vuelo, matricula de avion, nombre del piloto...
		vuelo->MatriculaAvion<<" "<<vuelo->NombrePiloto<<" "<<
		vuelo->HoraVuelo<<" "<<vuelo->FechaVuelo<<" "<<vuelo->Estado<<endl<<endl;
		vuelo = vuelo->Sgte;										//Avanza al siguiente nodo
		i++;														//Aumenta el contador							
	}
}

/********************************************************************************************************************************/

//Mostrar lista pasajeros
void MostrarListaPasajeros(DatosPasajero pasajero)						
{
	int i=0;														//Variable para el for
	
	while(pasajero != NULL)											//Mientras no sea el final de la lista
	{
		cout<<' '<<i+1<<")"<<pasajero->NroDeVuelo<<" "<<			//Muestra los datos de la lista
		pasajero->Cedula<<" "<<pasajero->NombrePersona<<" "<<			
		pasajero->Telefono<<" "<<pasajero->Estado<<endl<<endl;
		pasajero = pasajero->Sgte;									//Avanza al siguiente nodo					
		i++;														//Aumenta el contador
	}
}

/********************************************************************************************************************************/

//Una funcion que relacione los vuelos con los pasajeros
void RelacionarVuelosPasajeros(DatosVuelo Vuelos, DatosPasajero Usuarios)	
{
    DatosPasajero pasajero = Usuarios;								//Variable para recorrer la lista de pasajeros		
    while (pasajero != NULL) {										//Mientras no sea el final de la lista
        DatosVuelo vuelo = Vuelos;									//Variable para recorrer la lista de vuelos
        while (vuelo != NULL) 
		{
            if (strcmp(pasajero->NroDeVuelo, vuelo->NroDeVuelo) == 0)	//Si el numero de vuelo del pasajero es igual al numero de vuelo del vuelo
			 {
                DatosPasajero aux = new(Pasajeros);					//crea un nuevo espacio de memoria en la estructura pasajeros
                strcpy(aux->NroDeVuelo, pasajero->NroDeVuelo);		//copia los datos del pasajero al auxiliar
                strcpy(aux->Cedula, pasajero->Cedula);				//copia los datos del pasajero al auxiliar
                strcpy(aux->NombrePersona, pasajero->NombrePersona);//copia los datos del pasajero al auxiliar
                strcpy(aux->Telefono, pasajero->Telefono);			//copia los datos del pasajero al auxiliar
                aux->Estado = pasajero->Estado;						//copia los datos del pasajero al auxiliar
                aux->Sgte = vuelo->ListaPasajeros;					//copia los datos del pasajero al auxiliar
                vuelo->ListaPasajeros = aux;						//copia los datos del auxiliar al vuelo
                break;												//Sale del ciclo		
            }
            vuelo = vuelo->Sgte;									//Avanza al siguiente nodo
        }
        if (vuelo == NULL) 											//Si no se encontro el vuelo
		{
            cout << "No se encontro el vuelo " << pasajero->NroDeVuelo << endl;		//Muestra mensaje de error
        }
        pasajero = pasajero->Sgte;									//Avanza al siguiente nodo	
    }
}

/********************************************************************************************************************************/

void MostrarPasajerosPorVuelo(DatosVuelo Vuelos)					//Mostrar pasajeros por vuelo
 {
	char NroDeVuelo[10];											//Variable para el numero de vuelo
	cout << "Ingrese el numero de vuelo: ";							//Pide el numero de vuelo
	cin >> NroDeVuelo;												//Guarda el numero de vuelo
	DatosVuelo vuelo = Vuelos;										//Variable para recorrer la lista de vuelos
	while (vuelo != NULL) 											//Mientras no sea el final de la lista
	{
		if (strcmp(vuelo->NroDeVuelo, NroDeVuelo) == 0) 			//Si el numero de vuelo del vuelo es igual al numero de vuelo ingresado
		{
			DatosPasajero pasajero = vuelo->ListaPasajeros;			//Variable para recorrer la lista de pasajeros
			while (pasajero != NULL) 								//Mientras no sea el final de la lista					
			{
				cout << pasajero->Cedula << " " << pasajero->NombrePersona << " " << pasajero->Telefono << " " << pasajero->Estado << endl;	//Muestra los datos del pasajero
				pasajero = pasajero->Sgte;							//Avanza al siguiente nodo	
			}
			break;													//Sale del ciclo
		}
		vuelo = vuelo->Sgte;										//Avanza al siguiente nodo
	}
	if (vuelo == NULL) 												//Si no se encontro el vuelo
	{
		cout << "No se encontro el vuelo " << NroDeVuelo << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//Funcion para mostrar si un vuelo ya despego o no
void MostrarEstadoVuelo(DatosVuelo Vuelos)							//Mostrar estado del vuelo
{
	char NroDeVuelo[10];											//Variable para el numero de vuelo
	cout << "Ingrese el numero de vuelo: ";							//Pide el numero de vuelo		
	cin >> NroDeVuelo;												//Guarda el numero de vuelo
	DatosVuelo vuelo = Vuelos;										//Variable para recorrer la lista de vuelos			
	while (vuelo != NULL) 											//Mientras no sea el final de la lista			
	{
		if (strcmp(vuelo->NroDeVuelo, NroDeVuelo) == 0) 			//Si el numero de vuelo del vuelo es igual al numero de vuelo ingresado
		{
			if (vuelo->Estado == 1)									//Si el estado del vuelo es 1
			{
				cout << "El vuelo ya despego" << endl;				//Muestra mensaje de ya despego
			}
			else													//Si el estado del vuelo es 0
			{
				cout << "El vuelo esta programado" << endl;			//Muestra mensaje de programado
			}
			break;													//Sale del ciclo			
		}
		vuelo = vuelo->Sgte;										//Avanza al siguiente nodo			
	}
	if (vuelo == NULL) 												//Si no se encontro el vuelo		
	{
		cout << "No se encontro el vuelo " << NroDeVuelo << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//Funcion para mostrar si un pasajero ya abordo o no
void MostrarEstadoPasajero(DatosPasajero Pasajero)					//Mostrar estado del pasajero	
{
	char Cedula[10];												//Variable para la cedula
	cout << "Ingrese la cedula del pasajero: ";						//Pide la cedula
	cin >> Cedula;													//Guarda la cedula
	DatosPasajero pasajero = Pasajero;								//Variable para recorrer la lista de pasajeros
	while (pasajero != NULL)										//Mientras no sea el final de la lista
	 {	
		if (strcmp(pasajero->Cedula, Cedula) == 0) 					//Si la cedula del pasajero es igual a la cedula ingresada
		{
			if (pasajero->Estado == 1)								//Si el estado del pasajero es 1
			{
				cout << "El pasajero aun no abordo" << endl;			//Muestra mensaje de ya abordo
			}
			else													//Si el estado del pasajero es 0
			{
				cout << "El pasajero ya abordo" << endl;		//Muestra mensaje de aun no abordo
			}
			break;													//Sale del ciclo
		}
		pasajero = pasajero->Sgte;									//Avanza al siguiente nodo					
	}
	if (pasajero == NULL) 											//Si no se encontro el pasajero
	{
		cout << "No se encontro el pasajero " << Cedula << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//Funcion para agregar vuelos
void AgregarVuelo(DatosVuelo &Vuelos)								//Agregar vuelo
{
	DatosVuelo vuelo = new(Vuelo);									//Crea un nuevo nodo
	cout << "Ingrese el destino(PER): ";							//Pide los datos del vuelo
	cin >> vuelo->Destino;											//Guarda los datos del vuelo en el nodo creado
	cout << "Ingrese el origen: ";		
	cin >> vuelo->Origen;
	cout << "Ingrese el numero de vuelo: ";
	cin >> vuelo->NroDeVuelo;
	cout << "Ingrese la matricula del avion: ";
	cin >> vuelo->MatriculaAvion;
	cout << "Ingrese el nombre del piloto: ";
	cin >> vuelo->NombrePiloto;
	cout << "Ingrese la hora del vuelo: ";
	cin >> vuelo->HoraVuelo;
	cout << "Ingrese la fecha del vuelo: ";
	cin >> vuelo->FechaVuelo;
	vuelo->Estado = 0;												//El estado del vuelo es 0					
	vuelo->ListaPasajeros = NULL;									//La lista de pasajeros del vuelo es NULL
	vuelo->Sgte = Vuelos;											//El siguiente nodo del vuelo es el primero de la lista
	Vuelos = vuelo;													//El primer nodo de la lista es el nuevo nodo creado
}

/********************************************************************************************************************************/

//Funcion Cuando se hace un vuelo, se debe modificar el estado del vuelo a realizado.

void ModificarEstadoVuelo(DatosVuelo Vuelos)						//Modificar estado del vuelo
{
	char NroDeVuelo[10];											//Variable para el numero de vuelo
	cout << "Ingrese el numero de vuelo: ";							//Pide el numero de vuelo
	cin >> NroDeVuelo;												//Guarda el numero de vuelo
	DatosVuelo vuelo = Vuelos;										//Variable para recorrer la lista de vuelos
	while (vuelo != NULL) 											//Mientras no sea el final de la lista
	{
		if (strcmp(vuelo->NroDeVuelo, NroDeVuelo) == 0) 			//Si el numero de vuelo del vuelo es igual al numero de vuelo ingresado
		{
			if(vuelo->Estado == 1)									//Si el estado del vuelo es 1
			{
				cout << "El estado cambio, vuelo ya reprogrmado" << endl;				//Muestra mensaje de ya despego
				vuelo->Estado = 0;									//El estado del vuelo es 0
			}
			else													//Si el estado del vuelo es 0
			{
				cout << "El estado ha cambiafo, vuelo ya despego" << endl;			//Muestra mensaje de programado
				vuelo->Estado = 1;									//El estado del vuelo es 1
			}
			break;													//Sale del ciclo
		}
		vuelo = vuelo->Sgte;										//Avanza al siguiente nodo
	}
	if (vuelo == NULL)												 //Si no se encontro el vuelo
	{
		cout << "No se encontro el vuelo " << NroDeVuelo << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//funcion que permita registrar cuando un pasajero pasa a bordo.
void ModificarEstadoPasajero(DatosPasajero &Pasajero)				//Modificar estado del pasajero
{
	char Cedula[10];												//Variable para la cedula
	cout << "Ingrese la cedula del pasajero: ";						//Pide la cedula
	cin >> Cedula;													//Guarda la cedula				
	DatosPasajero pasajero = Pasajero;								//Variable para recorrer la lista de pasajeros
	while (pasajero != NULL) 										//Mientras no sea el final de la lista
	{	
		if (strcmp(pasajero->Cedula, Cedula) == 0) 					//Si la cedula del pasajero es igual a la cedula ingresada
		{
			pasajero->Estado = 1;									//El estado del pasajero es 1
			break;													//Sale del ciclo				
		}
		pasajero = pasajero->Sgte;									//Avanza al siguiente nodo
	}
	if (pasajero == NULL) 											//Si no se encontro el pasajero
	{
		cout << "No se encontro el pasajero " << Cedula << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//funcion para agregar pasajeros a la lista de pasajeros.
void AgregarPasajero(DatosPasajero &Persona)						//Agregar pasajero
{
	DatosPasajero pasajero = new (Pasajeros);						//Crea un nuevo nodo
	cout<<"Ingrese el Nro de vuelo: ";								//Pide el numero de vuelo
	cin>>pasajero->NroDeVuelo;										//Guarda el numero de vuelo
	cout<<"Ingrese la cedula: ";									//Pide la cedula
	cin>>pasajero->Cedula;											//Guarda la cedula
	cout<<"Ingrese el nombre: ";									//Pide el nombre
	cin>>pasajero->NombrePersona;									//Guarda el nombre
	cout<<"Ingrese el telefono: ";									//Pide el telefono
	cin>>pasajero->Telefono;										//Guarda el telefono
	cout<<"Ingrese el estado: ";									//Pide el estado
	cin>>pasajero->Estado;											//Guarda el estado
	pasajero->Sgte = Persona;										//El siguiente nodo del pasajero es el primero de la lista de pasajeros
	Persona = pasajero;												//El primer nodo de la lista de pasajeros es el nuevo nodo creado
}

/********************************************************************************************************************************/

//Funcion para hacer una lista de vuelos con estado 0
void MostrarVuelosSinDespegar(DatosVuelo Vuelos)					//Mostrar estado del vuelo
{
	DatosVuelo vuelo = Vuelos;										//Variable para recorrer la lista de vuelos
	while (vuelo != NULL) 											//Mientras no sea el final de la lista
	{
		if (vuelo->Estado == 0) 									//Si el estado del vuelo es 0
		{
			cout << "Nro de vuelo: " << vuelo->NroDeVuelo << endl;	//Muestra el numero de vuelo
			cout << "Estado: " << vuelo->Estado << endl;			//Muestra el estado
		}
		vuelo = vuelo->Sgte;										//Avanza al siguiente nodo
	}
}

/********************************************************************************************************************************/

//Funcion que muestra los vuelos con estado 1
void MostrarVuelosDespegados(DatosVuelo Vuelos)						//Mostrar estado del vuelo
{
	DatosVuelo vuelo = Vuelos;										//Variable para recorrer la lista de vuelos
	while (vuelo != NULL) 											//Mientras no sea el final de la lista
	{
		if (vuelo->Estado == 1) 									//Si el estado del vuelo es 1
		{
			cout << "Nro de vuelo: " << vuelo->NroDeVuelo << endl;	//Muestra el numero de vuelo
			cout << "Estado: " << vuelo->Estado << endl;			//Muestra el estado
		}
		vuelo = vuelo->Sgte;										//Avanza al siguiente nodo
	}
}

/********************************************************************************************************************************/

//Dada la cédula de una persona, obtener un listado de los vuelos que ha realizado y de los vuelos que tiene programado realizar.
void ListaEstadoPasajero(DatosPasajero Pasajero)					//Mostrar estado del pasajero
{
	char Cedula[10];												//Variable para la cedula
	cout << "Ingrese la cedula del pasajero: ";						//Pide la cedula
	cin >> Cedula;													//Guarda la cedula
	DatosPasajero pasajero = Pasajero;								//Variable para recorrer la lista de pasajeros
	while (pasajero != NULL) 										//Mientras no sea el final de la lista
	{
		if (strcmp(pasajero->Cedula, Cedula) == 0) 					//Si la cedula del pasajero es igual a la cedula ingresada
		{
			cout << "Nro de vuelo: " << pasajero->NroDeVuelo << endl;	//Muestra el numero de vuelo
			if(pasajero->Estado == 1)								//Si el estado del pasajero es 0
			{
				cout << "Estado: " << "Vuelo programado" << endl;	//Muestra el estado
			}
			else													//Si el estado del pasajero es 1
			{
				cout << "Estado: " << "Vuelo realizado" << endl;	//Muestra el estado
			}
			break;													//Sale del ciclo
		}
		pasajero = pasajero->Sgte;									//Avanza al siguiente nodo
	}
	if (pasajero == NULL) 											//Si no se encontro el pasajero
	{
		cout << "No se encontro el pasajero " << Cedula << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//Funcion para registrar pasajero que pasa a bordo
void RegistrarPasajero(DatosPasajero &Pasajero)						//Registrar pasajero que pasa a bordo
{
	char Cedula[10];												//Variable para la cedula
	cout << "Ingrese la cedula del pasajero: ";						//Pide la cedula
	cin >> Cedula;													//Guarda la cedula
	DatosPasajero pasajero = Pasajero;								//Variable para recorrer la lista de pasajeros
	while (pasajero != NULL) 										//Mientras no sea el final de la lista
	{
		if (strcmp(pasajero->Cedula, Cedula) == 0) 					//Si la cedula del pasajero es igual a la cedula ingresada
		{
			pasajero->Estado = 2;									//Cambia el estado del pasajero a 1
			cout << "Pasajero registrado" << endl;					//Muestra mensaje de confirmacion
			break;													//Sale del ciclo
		}
		pasajero = pasajero->Sgte;									//Avanza al siguiente nodo
	}
	if (pasajero == NULL) 											//Si no se encontro el pasajero
	{
		cout << "No se encontro el pasajero " << Cedula << endl;	//Muestra mensaje de error
	}
}

/********************************************************************************************************************************/

//funcion menu
void Menu()															//Menu			
	{
		system("cls");												//Limpia la pantalla
		cout << "1. Agregar Vuelo" << endl;							//Muestra el menu
		cout << "2. Agregar Pasajero" << endl;	
		cout << "3. Mostrar listado de vuelos programados,realizados "<< endl;
		cout << "4. Mostrar listado de pasajeros por vuelo" << endl;
		cout << "5. Dada la cedula, mostrar vuelos" << endl;
		cout << "6. Cuando se hace un vuelo, se debe modificar el estado del vuelo a realizado." << endl;
		cout << "7. Mostrar Lista Vuelos" << endl;
		cout << "8. Mostrar Lista Pasajeros" << endl;
		cout << "9. Registrar pasajero que pasa a bordo." << endl;
		cout << "10. Salir" << endl;
		cout << "Ingrese una opcion: ";
	}

/********************************************************************************************************************************/

main()																//Funcion principal									
{
    DatosVuelo Vuelos = NULL;										//Lista de vuelos
	DatosPasajero Persona= NULL;									//Lista de pasajeros			
	int Op;															//Variable para el menu
	int Dato;														//Variable para el menu								
	int Pos;														//Variable para el menu			
	int X;															//Variable para el menu				

	AbrirArchivo(Vuelos);											//Abre el archivo de vuelos
	AbrirArchivoPasajero(Persona);									//Abre el archivo de pasajeros			
	RelacionarVuelosPasajeros(Vuelos,Persona);						//Relaciona los vuelos con los pasajeros


	do
	{
		Menu();														//Llama a la funcion Menu
		cin>>Op;
		switch (Op)													//Switch para las opciones del menu							
		{
		case 1:														//Si la opcion es 1
			AgregarVuelo(Vuelos);									//Llama a la funcion AgregarVuelo
			break;
		case 2:
			AgregarPasajero(Persona);								//Llama a la funcion AgregarPasajero
			break;
		case 3:
			cout<<endl<<endl<<"Vuelos Programados: "<<endl<<endl;	//Muestra los vuelos sin despegar
			MostrarVuelosSinDespegar(Vuelos);						//Llama a la funcion MostrarVuelosSinDespegar
			cout<<endl<<endl<<"Vuelos Realizados: "<<endl<<endl;	//Muestra los vuelos despegados
			MostrarVuelosDespegados(Vuelos);						//Llama a la funcion MostrarVuelosDespegados
			break;
		case 4:
			MostrarPasajerosPorVuelo(Vuelos);						//Llama a la funcion MostrarPasajerosPorVuelo
			break;
		case 5:
			ListaEstadoPasajero(Persona);							//Llama a la funcion ListaEstadoPasajero
			break;
		case 6:
			ModificarEstadoVuelo(Vuelos);							//Llama a la funcion ModificarEstadoVuelo
			break;
		case 7:
			MostrarListaVuelos(Vuelos);								//Llama a la funcion MostrarListaVuelos
			break;
		case 8:
			MostrarListaPasajeros(Persona);							//Llama a la funcion MostrarListaPasajeros
			break;
		case 9:
			RegistrarPasajero(Persona);								//Llama a la funcion RegistrarPasajero
			break;
		}
		cout<<endl<<endl;
		system("pause");
		system("cls");
	}while(Op!=10);													//Mientras la opcion sea diferente de 9
	system("pause");												//Pausa el programa					
	return 0;														//Termina el programa						
}

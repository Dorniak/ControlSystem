#pragma once
#include "Obstaculo.h"
#include "reader.h"
#include "DataAnalisys.h"
#include "OpenGl.h"

#define FlagTratamiento 0
#define FlagTratamiento 1
#define FlagTratamiento 2
#define FlagTratamiento 3
#define FlagWarning 4
#define FlagPausa 5
#define FlagAnalisysOn 6
#define FlagOpenGlOn 7


using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;

ref class Control {
public:
	//Constructor
	Control();
	//Lista de Obstaculos
	List<Obstaculo^>^ Obstaculos;
	//Lista de puntos
	List<Punto3D^>^ Puntos;
	//Lista de conclusiones
	List<int>^ Conclusiones;
	//Array de flags que sincroniza los threads
	cli::array<bool>^ Flags;
	//Conjunto de parametros que necesita el DataAnalisys en tiempo de ejecucion
	cli::array<double>^ ArrayDataAnalisys;
	//Pone el flag de conclusion a 1 para que la aplicacion que lo recoja sepa que las conclusiones estan listas
	void setFlagTratamiento();
	void Iniciar();
	void reActivar();
	//Funcion que le dice al OpenGl que los puntos estan listos para ser dibujados
	void DibujarPuntos();
	//Funcion que le dice al OpenGl que los obstaculos estan listos para ser dibujados
	void DibujarObstaculos();
	//Array de threads para apagarlos y encenderlos
	cli::array<Thread^>^ Threads = gcnew cli::array<Thread^>(3);
	//Funcion encargada de dibujar los puntos
	void guardarPuntos(List<Punto3D^>^ Punt);
	void guardarObstaculos(List<Obstaculo^>^ Obst);
private:
	void pausarThreads();
	//Parametros de arranque para los threads
	cli::array<Object^>^ dataThreads=gcnew cli::array<Object^>(10);
	//Objeto DataAnalisys
	DataAnalisys ^Analisys;
	//Objeto OpenGl
	OpenGl ^Dibujador;
	//Objeto DataReader
	DataReader ^Reader;
	//Funcion final de la que se sacan las conclusiones del vehiculo
	void interpretarConclusiones();
	//Funcion que inicia cada objeto con todos los parametros necesarios
	void IniciarThreads();
};
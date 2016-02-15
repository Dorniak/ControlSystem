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
	List<Obstaculo^>^ Obstaculos;
	List<Punto3D^>^ Puntos;
	List<int>^ Conclusiones;
	cli::array<bool>^ Flags;
	cli::array<double>^ ArrayDataAnalisys;
	void setFlagTratamiento();
	void Iniciar();
	void reActivar();
	void DibujarObstaculos();
	//Objeto OpenGl
private:
	cli::array<Object^>^ dataThreads=gcnew cli::array<Object^>(10);
	DataAnalisys ^Analisys;
	OpenGl ^Dibujador;
	DataReader ^Reader;
	//Objetos Reader y Analisys
	void interpretarConclusiones();
	void IniciarThreads();
protected:
	
};
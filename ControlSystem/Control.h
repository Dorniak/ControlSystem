#pragma once
#include "Obstaculo.h"
#include "reader.h"
#include "DataAnalisys.h"
#include "OpenGl.h"

#define FlagTratamiento 1
#define FlagTratamiento 2
#define FlagTratamiento 3
#define FlagWarning 4
#define FlagPausa 5


using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;

ref class Control {
public:
	//Constructor
	Control();
	List<Obstaculo^>^ Obstaculos = gcnew List<Obstaculo^>();
	List<Punto3D^>^ Puntos = gcnew List<Punto3D^>();
	List<int>^ Conclusiones = gcnew List<int>();
	List<int>^ Flags = gcnew List<int>();
	void setFlagTratamiento();
	//Objeto OpenGl
private:
	//Objetos Reader y Analisys
	void interpretarConclusiones();
protected:
	
};
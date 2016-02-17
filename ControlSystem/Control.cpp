#include "Control.h"

Control::Control()
{
	Obstaculos = gcnew List<Obstaculo^>();
	Puntos = gcnew List<Punto3D^>();
	Conclusiones = gcnew List<int>();
	Flags = gcnew cli::array<bool>(10);
	ArrayDataAnalisys = gcnew cli::array<double>(10);
}
//Es el encargado de poner el flag de fin de tratamiento a 1 a la vez 
// que llama a la funcion de interpretar conclusiones
void Control::setFlagTratamiento()
{
	Flags[FlagTratamiento]=1;
	interpretarConclusiones();
}

void Control::interpretarConclusiones()
{
	throw gcnew System::NotImplementedException();
}

void Control::Iniciar()
{
	if (Flags[FlagAnalisysOn]==true) {
		//Crear objeto DataAnalisys
		Analisys = gcnew DataAnalisys();
	}
	if (Flags[FlagOpenGlOn] == true) {
		//Crear objeto OpenGl
		Dibujador = gcnew OpenGl();
	}
	//Crear objeto DataReader
	Reader = gcnew DataReader();
	IniciarThreads();
}

void Control::IniciarThreads()
{
	dataThreads[0]=this;
	Analisys->Analisys(this);
}

void Control::reActivar()
{
	IniciarThreads();
}

void Control::DibujarPuntos()
{
	Dibujador->modificarPuntos(Puntos);
}

void Control::DibujarObstaculos()
{
	Dibujador->modificarObstaculos(Obstaculos);
}

void Control::guardarPuntos(List<Punto3D^>^ Punt)
{
	Puntos = Punt;
	DibujarPuntos();
	//Control de colision
	if (Flags[FlagTratamiento] == 0) {
		Flags[FlagWarning] = 1;
		pausarThreads();
	}
	Flags[FlagTratamiento] = 0;
}

void Control::guardarObstaculos(List<Obstaculo^>^ Obst)
{
	Obstaculos = Obst;
	DibujarObstaculos();
	//Control de collision
	if (Flags[FlagTratamiento] == 1) {
		Flags[FlagWarning] = 1;
		pausarThreads();
	}
	Flags[FlagTratamiento] = 1;
}

void Control::pausarThreads()
{
	for (int i = 0; i < Threads->Length; i++) {
		Threads[i]->Abort();
	}
}



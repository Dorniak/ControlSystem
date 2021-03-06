#pragma once
#pragma once
#pragma warning( disable : 4244 ) //Life is not perfect
#include "Punto3D.h"
#include <cliext/vector>
#include "OpenGl.h"
#using "System.dll"

//Vector de flags
#define FlagTratamiento 0
#define FlagTratamiento 1
#define FlagTratamiento 2
#define FlagTratamiento 3
#define FlagWarning 4
#define FlagPausa 5
#define FlagAnalisysOn 6
#define FlagOpenGlOn 7
#define FlagLogOn 8


using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;

using namespace System::Collections::Generic;
ref class DataReader
{

public:
	DataReader(IPEndPoint^ LaserIpEndPoint);
	~DataReader();

	void ReadData(List<Punto3D^>^ puntosControl, cli::array<Object^>^ ParamReader, cli::array<bool>^ Flags, cli::array<Thread^>^ Threads, OpenGl^ Dibujador);
	void ReadDataThread();
	void Kill();

	double getAngle(int channel);
	bool read;
	cli::array<Double>^ InterpolateAzimuth(cli::array<Byte>^& ReceiveBytes, int *corte, double *azi);
	cli::array<Double>^ ExtractDistances(cli::array<Byte>^& ReceiveBytes);
	cli::array<Double>^ ExtractIntensities(cli::array<Byte>^& ReceiveBytes);
	int frame;
	String^ path;


private:
	OpenGl^ Dibujador;
	void copiarPuntos();

	//array de parametros del DataReader
	cli::array<Object^>^ ArrayDataReader;
	//Puntero al array de thread
	cli::array<Thread^>^ Threads;
	//Puntero al array de flags
	cli::array<bool>^ Flags;
	//LIsta en la que se guardan los puntos
	List<Punto3D^>^ puntosControl;




	bool log = true;
	List<Punto3D^>^ Puntos = gcnew List<Punto3D^>;

	/*Client for the UDP connection*/
	UdpClient^ ClientLIDAR;

	/*Client configuration object.Also here is save the info about client(LIDAR)*/
	IPEndPoint^ LaserIpEndPoint;
	Thread^ thread_reader;
	StreamWriter^ loger;
	//Objeto thread del Reader
	Thread^ thread_Reader;
};


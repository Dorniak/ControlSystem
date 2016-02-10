#pragma once
#pragma once
#pragma warning( disable : 4244 ) //Life is not perfect
#include "Punto3D.h"
#include <cliext/vector>


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

	cli::array<Object^> ^ parameters_in;
	void ReadData(cli::array<Object^>^ data);
	void StopReadData();
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

	/*Client for the UDP connection*/
	UdpClient^ ClientLIDAR;

	/*Client configuration object.Also here is save the info about client(LIDAR)*/
	IPEndPoint^ LaserIpEndPoint;
	Thread^ thread_reader;
	StreamWriter^ loger;
};


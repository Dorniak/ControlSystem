//#include "Control.h"
using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
void Main(cli::array<String^>^ args)
{
	List<int>^ a = gcnew List<int>();
	List<int>^ b = a;
	b->Add(5);
	Console::WriteLine("Lista a", a->Count);
	Console::WriteLine("Lista b", b->Count);
}
#include "Control.h"

Control::Control()
{
	
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

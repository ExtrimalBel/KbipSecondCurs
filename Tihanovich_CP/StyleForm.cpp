//#include "Stdafx.h"
#include "StyleForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Tihanovich_CP::StyleForm form;
	Application::Run(%form);
}

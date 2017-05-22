#include "GUIForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GUI::GUIForm form;
	Application::Run(%form);
}

void MarshalString(String ^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}


System::Void GUI::GUIForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
	this->label1->Text = folderBrowserDialog1->SelectedPath;
	System::String ^ temp = this->label1->Text;
	std::string folder;
	MarshalString(temp, folder);
	folderPath = _strdup(folder.c_str());
	
	return;
}

System::Void GUI::GUIForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	char * argvArray[7];
	std::string temp = "simbly";

	argvArray[0] = _strdup(temp.c_str());
	argvArray[1] = folderPath;
	
	std::string x[] = { "simbly","pathActually","*.h","*.cpp","/m","/f","/r" };
	for (int i = 2; i < 7; i++) {
		const char* xx = x[i].c_str();
		argvArray[i] = _strdup(xx);
	}

	return System::Void();
}

System::Void GUI::GUIForm::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

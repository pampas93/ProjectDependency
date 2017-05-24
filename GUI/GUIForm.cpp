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


void GUI::GUIForm::AnalyzerMain()
{
	bridgerObj->start(folderPath);
	return;
}

System::Void GUI::GUIForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		this->label1->Text = folderBrowserDialog1->SelectedPath;
		System::String ^ temp = this->label1->Text;
		std::string folder;
		MarshalString(temp, folder);
		folderPath = _strdup(folder.c_str());
		this->label2->Text = "Build Dependency (Click once)";
		this->button3->Hide();
	}

	return;
}

System::Void GUI::GUIForm::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (folderPath == NULL) {
		this->label2->Text = "Select a Folder";
	}
	else {
		this->label2->Text = "Building Dependencies, Please Do not click anything";
		AnalyzerMain();
		//bridgerObj->start(folderPath);
		this->label2->Text = "Done";
		this->button3->Show();
	}

	return ;
}

System::Void GUI::GUIForm::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}

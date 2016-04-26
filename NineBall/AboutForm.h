#pragma once
#include "LastDisplayedName.h"
namespace NineBall {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  info1;
	protected:
	private: System::Windows::Forms::Label^  writtenBy;
	private: System::Windows::Forms::Label^  info2;
	private: System::Windows::Forms::Label^  placeHolder;
	private: System::Windows::Forms::Label^  webInfo;
	private: System::Windows::Forms::LinkLabel^  webLink;
	private: typedef LastDisplayedName::LastDisplayed_Name nameLastDisplayed;
	
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->info1 = (gcnew System::Windows::Forms::Label());
			this->writtenBy = (gcnew System::Windows::Forms::Label());
			this->info2 = (gcnew System::Windows::Forms::Label());
			this->placeHolder = (gcnew System::Windows::Forms::Label());
			this->webInfo = (gcnew System::Windows::Forms::Label());
			this->webLink = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// info1
			// 
			this->info1->Dock = System::Windows::Forms::DockStyle::Top;
			this->info1->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->info1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->info1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"info1.Image")));
			this->info1->Location = System::Drawing::Point(0, 0);
			this->info1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->info1->Name = L"info1";
			this->info1->Size = System::Drawing::Size(737, 81);
			this->info1->TabIndex = 0;
			this->info1->Text = L"Nine Ball, Version:";
			this->info1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// writtenBy
			// 
			this->writtenBy->Dock = System::Windows::Forms::DockStyle::Top;
			this->writtenBy->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->writtenBy->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->writtenBy->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"writtenBy.Image")));
			this->writtenBy->Location = System::Drawing::Point(0, 81);
			this->writtenBy->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->writtenBy->Name = L"writtenBy";
			this->writtenBy->Size = System::Drawing::Size(737, 52);
			this->writtenBy->TabIndex = 1;
			this->writtenBy->Text = L"Written in C++";
			this->writtenBy->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// info2
			// 
			this->info2->Dock = System::Windows::Forms::DockStyle::Top;
			this->info2->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->info2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->info2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"info2.Image")));
			this->info2->Location = System::Drawing::Point(0, 133);
			this->info2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->info2->Name = L"info2";
			this->info2->Size = System::Drawing::Size(737, 56);
			this->info2->TabIndex = 3;
			this->info2->Text = L"Pool table and ball images created by Erika Fomich.";
			this->info2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// placeHolder
			// 
			this->placeHolder->Dock = System::Windows::Forms::DockStyle::Top;
			this->placeHolder->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->placeHolder->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->placeHolder->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"placeHolder.Image")));
			this->placeHolder->Location = System::Drawing::Point(0, 189);
			this->placeHolder->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->placeHolder->Name = L"placeHolder";
			this->placeHolder->Size = System::Drawing::Size(737, 61);
			this->placeHolder->TabIndex = 5;
			this->placeHolder->Text = L" Special thanks to our C++ Teacher, Dr. Lawrence Yapp, for his assitance. ";
			this->placeHolder->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// webInfo
			// 
			this->webInfo->Dock = System::Windows::Forms::DockStyle::Top;
			this->webInfo->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->webInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->webInfo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"webInfo.Image")));
			this->webInfo->Location = System::Drawing::Point(0, 250);
			this->webInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->webInfo->Name = L"webInfo";
			this->webInfo->Size = System::Drawing::Size(737, 54);
			this->webInfo->TabIndex = 6;
			this->webInfo->Text = L"For updates and the latest version, please visit our web page at:";
			this->webInfo->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// webLink
			// 
			this->webLink->Dock = System::Windows::Forms::DockStyle::Top;
			this->webLink->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"webLink.Image")));
			this->webLink->LinkColor = System::Drawing::Color::Blue;
			this->webLink->Location = System::Drawing::Point(0, 304);
			this->webLink->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->webLink->Name = L"webLink";
			this->webLink->Size = System::Drawing::Size(737, 70);
			this->webLink->TabIndex = 7;
			this->webLink->TabStop = true;
			this->webLink->Text = L"http://www.google.com/";
			this->webLink->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->webLink->VisitedLinkColor = System::Drawing::Color::Blue;
			this->webLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::webLink_LinkClicked);
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(737, 376);
			this->Controls->Add(this->webLink);
			this->Controls->Add(this->webInfo);
			this->Controls->Add(this->placeHolder);
			this->Controls->Add(this->info2);
			this->Controls->Add(this->writtenBy);
			this->Controls->Add(this->info1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"About Nine Ball";
			this->Load += gcnew System::EventHandler(this, &AboutForm::AboutForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AboutForm_Load(System::Object^  sender, System::EventArgs^  e)
	{	
		String^ version = Application::ProductVersion;
		int idx1, idx2;
		idx1 = version->IndexOf('.');
		if (idx1 > -1)
		{
			idx2 = version->IndexOf('.', idx1 + 1);
			if (idx2 > -1)
			{
				version = version->Substring(0, idx2 ) + 2;
			}
		}
		//
		info1->Text += " " + version;
		
		
		if (LastDisplayedName::NameLastDisplayed == (int)nameLastDisplayed::NotRunYet)
		{
			int seed = DateTime::Now.Ticks;
			Random^ rnd = gcnew Random(seed);
			int val = rnd->Next(1, 3);
			if (val == 1)
			{
				writtenBy->Text = "Written in C++, by Orion Supergan and Matt Fomich";
				LastDisplayedName::NameLastDisplayed = (int)nameLastDisplayed::Orion;				
			}
			else if (val == 2)
			{
				writtenBy->Text = "Written in C++, by Matt Fomich and Orion Supergan";
				LastDisplayedName::NameLastDisplayed = (int)nameLastDisplayed::Matt;				
			}
		}
		else if (LastDisplayedName::NameLastDisplayed == (int)nameLastDisplayed::Matt)
		{
			writtenBy->Text = "Written in C++, by Orion Supergan and Matt Fomich";
			LastDisplayedName::NameLastDisplayed = (int)nameLastDisplayed::Orion;			
		}
		else
		{
			writtenBy->Text = "Written in C++, by Matt Fomich and Orion Supergan";
			LastDisplayedName::NameLastDisplayed = (int)nameLastDisplayed::Matt;			
		}
		
		
	}
private: System::Void webLink_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
	try
	{
		System::Diagnostics::Process::Start(webLink->Text);
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error: " + ex->ToString());
	}

}
};
}

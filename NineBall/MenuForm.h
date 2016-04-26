#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <mmsystem.h>
#include "AboutForm.h"


namespace NineBall {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	/// <summary>
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public: static enum class menuItems
	{
		play,		
		generalhelp,
		about,
		playonline,
		exit,
		none
	};
			String^ helpFile = "C:\\NineBall\\NineBallHelp.pdf";
			typedef MenuForm::menuItems items;
			array< Byte >^ menus = gcnew array< Byte >(5);
			Byte selectedMenu;
			Byte oldSelectedMenu;
			System::Drawing::Font^ itemFont = gcnew System::Drawing::Font("Calibri", 16.200);
	private: System::Windows::Forms::Timer^  showFormTimer;
	public:


	private: System::Windows::Forms::Label^  spacerLabel;
	private: System::Windows::Forms::Label^  leftSpacerLabel;
	private: System::Windows::Forms::Label^  rightSpacerLabel;
	private: System::Windows::Forms::Label^  play1;



	private: System::Windows::Forms::Label^  help3;
	private: System::Windows::Forms::Label^  about4;
	private: System::Windows::Forms::Label^  playOnline;
	private: System::Windows::Forms::Label^  exit;


	public:
		System::Drawing::Font^ itemSelectedFont = gcnew System::Drawing::Font("Calibri", 16.200, System::Drawing::FontStyle::Bold);

	public:
		MenuForm(void)
		{
			InitializeComponent();
			// Make an array of bytes to keep track of
			// the menu items.
			for (int i = 0; i < 5; i++)
			{
				menus[i] = 0;
			}
		}

		menuItems GetSelectedItem()
		{
			return (menuItems)selectedMenu;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^  components;

	protected:	 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->showFormTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->spacerLabel = (gcnew System::Windows::Forms::Label());
			this->leftSpacerLabel = (gcnew System::Windows::Forms::Label());
			this->rightSpacerLabel = (gcnew System::Windows::Forms::Label());
			this->play1 = (gcnew System::Windows::Forms::Label());
			this->help3 = (gcnew System::Windows::Forms::Label());
			this->about4 = (gcnew System::Windows::Forms::Label());
			this->playOnline = (gcnew System::Windows::Forms::Label());
			this->exit = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// showFormTimer
			// 
			this->showFormTimer->Interval = 60;
			this->showFormTimer->Tick += gcnew System::EventHandler(this, &MenuForm::showFormTimer_Tick);
			// 
			// spacerLabel
			// 
			this->spacerLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->spacerLabel->Location = System::Drawing::Point(0, 0);
			this->spacerLabel->Name = L"spacerLabel";
			this->spacerLabel->Size = System::Drawing::Size(1011, 104);
			this->spacerLabel->TabIndex = 12;
			// 
			// leftSpacerLabel
			// 
			this->leftSpacerLabel->Dock = System::Windows::Forms::DockStyle::Left;
			this->leftSpacerLabel->Location = System::Drawing::Point(0, 104);
			this->leftSpacerLabel->Name = L"leftSpacerLabel";
			this->leftSpacerLabel->Size = System::Drawing::Size(392, 552);
			this->leftSpacerLabel->TabIndex = 19;
			// 
			// rightSpacerLabel
			// 
			this->rightSpacerLabel->Dock = System::Windows::Forms::DockStyle::Right;
			this->rightSpacerLabel->Location = System::Drawing::Point(619, 104);
			this->rightSpacerLabel->Name = L"rightSpacerLabel";
			this->rightSpacerLabel->Size = System::Drawing::Size(392, 552);
			this->rightSpacerLabel->TabIndex = 32;
			// 
			// play1
			// 
			this->play1->Dock = System::Windows::Forms::DockStyle::Top;
			this->play1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->play1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"play1.Image")));
			this->play1->Location = System::Drawing::Point(392, 104);
			this->play1->Name = L"play1";
			this->play1->Size = System::Drawing::Size(227, 60);
			this->play1->TabIndex = 33;
			this->play1->Text = L"Play";
			this->play1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->play1->Click += gcnew System::EventHandler(this, &MenuForm::play1_Click);
			this->play1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuForm::play1_MouseDown);
			// 
			// help3
			// 
			this->help3->Dock = System::Windows::Forms::DockStyle::Top;
			this->help3->ForeColor = System::Drawing::Color::White;
			this->help3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"help3.Image")));
			this->help3->Location = System::Drawing::Point(392, 164);
			this->help3->Name = L"help3";
			this->help3->Size = System::Drawing::Size(227, 60);
			this->help3->TabIndex = 36;
			this->help3->Text = L"General Help";
			this->help3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->help3->Click += gcnew System::EventHandler(this, &MenuForm::help3_Click);
			this->help3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuForm::help3_MouseDown);
			// 
			// about4
			// 
			this->about4->Dock = System::Windows::Forms::DockStyle::Top;
			this->about4->ForeColor = System::Drawing::Color::White;
			this->about4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"about4.Image")));
			this->about4->Location = System::Drawing::Point(392, 224);
			this->about4->Name = L"about4";
			this->about4->Size = System::Drawing::Size(227, 60);
			this->about4->TabIndex = 37;
			this->about4->Text = L"About Nine Ball";
			this->about4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->about4->Click += gcnew System::EventHandler(this, &MenuForm::about4_Click);
			this->about4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuForm::about4_MouseDown);
			// 
			// playOnline
			// 
			this->playOnline->Dock = System::Windows::Forms::DockStyle::Top;
			this->playOnline->ForeColor = System::Drawing::Color::White;
			this->playOnline->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playOnline.Image")));
			this->playOnline->Location = System::Drawing::Point(392, 284);
			this->playOnline->Name = L"playOnline";
			this->playOnline->Size = System::Drawing::Size(227, 60);
			this->playOnline->TabIndex = 39;
			this->playOnline->Text = L"Close This Menu";
			this->playOnline->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->playOnline->Click += gcnew System::EventHandler(this, &MenuForm::playOnline_Click);
			this->playOnline->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuForm::playOnline_MouseDown);
			// 
			// exit
			// 
			this->exit->Dock = System::Windows::Forms::DockStyle::Top;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exit->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit->ForeColor = System::Drawing::Color::White;
			this->exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.Image")));
			this->exit->Location = System::Drawing::Point(392, 344);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(227, 60);
			this->exit->TabIndex = 40;
			this->exit->Text = L"Exit";
			this->exit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->exit->Click += gcnew System::EventHandler(this, &MenuForm::exit_Click);
			this->exit->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MenuForm::exit_MouseDown);
			// 
			// MenuForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Fuchsia;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1011, 656);
			this->ControlBox = false;
			this->Controls->Add(this->exit);
			this->Controls->Add(this->playOnline);
			this->Controls->Add(this->about4);
			this->Controls->Add(this->help3);
			this->Controls->Add(this->play1);
			this->Controls->Add(this->rightSpacerLabel);
			this->Controls->Add(this->leftSpacerLabel);
			this->Controls->Add(this->spacerLabel);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MenuForm";
			this->Opacity = 0.01;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->TransparencyKey = System::Drawing::Color::Fuchsia;
			this->Load += gcnew System::EventHandler(this, &MenuForm::MenuForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MenuForm::MenuForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MenuForm_Load(System::Object^  sender, System::EventArgs^  e)
	{		
		showFormTimer->Start();
	}

	protected:
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override
		{
			// This allows users to select menu items
			// with up and down keys. They can also
			// use the mouse, but this is added for
			// ease of use.
			if ((Char)keyData == (int)Keys::Down)
			{
				// Set old selected menu item
				// so we can change the appearance
				// to 'de-selected'.
				oldSelectedMenu = selectedMenu;
				// Play the ball hitting ball sound.
				playSound();
				// Set selectd menu byte value.
				if (selectedMenu < 4)
				{
					selectedMenu += 1;
				}
				else
				{
					selectedMenu = 0;
				}
				setActiveMenuItem();
			}
			else if ((Char)keyData == (int)Keys::Up)
			{
				oldSelectedMenu = selectedMenu;
				playSound();
				if (selectedMenu > 0)
				{
					selectedMenu -= 1;
				}
				else
				{
					selectedMenu = 4;
				}
				setActiveMenuItem();
			}
			else if ((Char)keyData == (int)Keys::Enter)
			{
				clickMenuItem();
			}
			//
			// Return the all messages to this window.
			return __super::ProcessCmdKey(msg, keyData);
		}


		void clickMenuItem()
		{
			switch (selectedMenu)
			{
			case (BYTE)menuItems::play:
				play1_MouseDown(nullptr, nullptr);
				play1_Click(nullptr, nullptr);
				break;
			case (BYTE)menuItems::playonline:
				play1_MouseDown(nullptr, nullptr);
				play1_Click(nullptr, nullptr);
				break;
			case (BYTE)menuItems::generalhelp:
				help3_MouseDown(nullptr, nullptr);
				help3_Click(nullptr, nullptr);
				break;
			case (BYTE)menuItems::about:
				about4_MouseDown(nullptr, nullptr);
				about4_Click(nullptr, nullptr);
				break;
			case (BYTE)menuItems::exit:
				exit_MouseDown(nullptr, nullptr);
				exit_Click(nullptr, nullptr);
				break;
			}
		}

		void setActiveMenuItem()
		{
			// De-select previously selected menu item.
			switch (oldSelectedMenu)
			{
			case (BYTE)menuItems::play:
				play1->Font = itemFont;
				play1->ForeColor = Color::White;
				//play1->BorderStyle = System::Windows::Forms::BorderStyle::None;
				break;
			case (BYTE)menuItems::playonline:
				playOnline->Font = itemFont;
				playOnline->ForeColor = Color::White;
				//play1->BorderStyle = System::Windows::Forms::BorderStyle::None;
				break;
			case (BYTE)menuItems::generalhelp:
				help3->Font = itemFont;
				help3->ForeColor = Color::White;
				//help3->BorderStyle = System::Windows::Forms::BorderStyle::None;
				break;
			case (BYTE)menuItems::about:
				about4->Font = itemFont;
				about4->ForeColor = Color::White;
				//about4->BorderStyle = System::Windows::Forms::BorderStyle::None;
				break;
			case (BYTE)menuItems::exit:
				exit->Font = itemFont;
				exit->ForeColor = Color::White;
				//exit->BorderStyle = System::Windows::Forms::BorderStyle::None;
				break;
			}
			//
			switch (selectedMenu)
			{
			case (BYTE)menuItems::play:
				play1->Font = itemSelectedFont;
				play1->ForeColor = Color::FromArgb(230, 238, 140);
				//play1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				break;
			case (BYTE)menuItems::playonline:
				playOnline->Font = itemSelectedFont;
				playOnline->ForeColor = Color::FromArgb(230, 238, 140);
				//play1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				break;
			case (BYTE)menuItems::generalhelp:
				help3->Font = itemSelectedFont;
				help3->ForeColor = Color::FromArgb(230, 238, 140);
				//help3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				break;
			case (BYTE)menuItems::about:
				about4->Font = itemSelectedFont;
				about4->ForeColor = Color::FromArgb(230, 238, 140);
				//about4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				break;
			case (BYTE)menuItems::exit:
				exit->Font = itemSelectedFont;
				exit->ForeColor = Color::FromArgb(230, 238, 140);
				//exit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				break;
			}
			this->Refresh();
		}

	private: static void playSound()
	{
		// Stop any currently playing sound, like the startup music.
		PlaySound(NULL, NULL, SND_FILENAME);
		// Play the hit ball sound.
		PlaySound(L"C:\\NineBall\\Sounds\\BallHit.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	}


	private: System::Void play1_Click(System::Object^  sender, System::EventArgs^  e)
	{

		Thread::Sleep(100);
		this->Close();
	}

	private: System::Void playOnline_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Thread::Sleep(100);
		this->Close();
	}

	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Thread::Sleep(100);
		this->Close();
	}
	private: System::Void about4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Thread::Sleep(100);
		AboutForm^ about = gcnew AboutForm();
		// Make form center to this one, and slightly
		// above it on the Y-axis.
		int left = this->Left + (this->Width / (double)2) - (about->Width / (double)2);
		int topOffset = 50;
		int top = this->Top + (this->Height / (double)2) - (about->Height / (double)2) - topOffset;

		about->Left = left;
		about->Top = top;

		about->ShowDialog();
	}

	private: System::Void help3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Thread::Sleep(100);
		try
		{			
			if (System::IO::File::Exists(helpFile))
			{
				System::Diagnostics::Process::Start(helpFile);
			}
			else
			{
				MessageBox::Show("Error: The help file at: " + helpFile +
					" does not exist.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message, "Error", 
				MessageBoxButtons::OK , MessageBoxIcon::Exclamation );
				
		}
	}

	private: System::Void play1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		oldSelectedMenu = selectedMenu;
		selectedMenu = (Byte)items::play;
		setActiveMenuItem();
		this->Refresh();
	}

	private: System::Void playOnline_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		oldSelectedMenu = selectedMenu;
		selectedMenu = (Byte)items::playonline;
		setActiveMenuItem();
		this->Refresh();
	}

	private: System::Void help3_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		oldSelectedMenu = selectedMenu;
		selectedMenu = (Byte)items::generalhelp;
		setActiveMenuItem();
		this->Refresh();
	}

	private: System::Void about4_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		oldSelectedMenu = selectedMenu;
		selectedMenu = (Byte)items::about;
		setActiveMenuItem();
		this->Refresh();
	}

	private: System::Void exit_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		oldSelectedMenu = selectedMenu;
		selectedMenu = (Byte)items::exit;
		setActiveMenuItem();
		this->Refresh();
	}

	private: System::Void showFormTimer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->Opacity == 1)
		{
			showFormTimer->Stop();
		}
		else
		{
			this->Opacity += .1;
			this->Refresh();
		}
	}

	private: System::Void MenuForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::Escape)
		{
			selectedMenu = 9;
			this->Close();
		}
	}
	
};
}

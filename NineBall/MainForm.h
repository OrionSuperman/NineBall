#pragma once
#include "BilliardBall.h"
#include"Direction.h"
#include "MenuForm.h"
#include "AboutForm.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <math.h>

using namespace System;
using namespace System::Threading;
using namespace System::Collections::Generic;

namespace NineBall {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class MainForm : public System::Windows::Forms::Form
	{
		typedef MenuForm::menuItems mainMenuItem;
		bool gameOver = false;
		bool networkGame = false;
		bool firstHit;
		bool goodHit;
		bool playerScored;
		bool lineWasStraight;
		Byte zeroBall = 1;
		List<Byte> ballsInPlay;
		int player1ScoresInARow = 0;
		int player2ScoresInARow = 0;
		bool breaking = true;
		bool exiting = false;
		bool addCompositeStyle = false;
		bool ballsMoving = false;
		double friction = .989; // set to .990; after break.
		float bounceFriction = .90;
		List<BilliardBall^> balls;
		Thread^ soundThread;
		Graphics^ gr;
		Point qstart;
		Point qctr;
		Point aimPt;
		Point cueEndPt;
		static LPCTSTR currentSound;
		bool drawline;
		bool moveCueBall;
		const int POCKET_WIDTH = 20;
		const int BALL_WIDTH = 34;
		const int BALL_HEIGHT = 34;
		const int BALL_RADIUS = 17;

		ref struct sounds
		{
			static const LPCTSTR StartupMusic = L"C:\\NineBall\\Sounds\\Intro.wav";
			static const LPCTSTR Break = L"C:\\NineBall\\Sounds\\Break.wav";
			static const LPCTSTR ballHit = L"C:\\NineBall\\Sounds\\BallHit.wav";
			static const LPCTSTR ballHitHard = L"C:\\NineBall\\Sounds\\BallHit_Hard.wav";
			static const LPCTSTR shoot = L"C:\\NineBall\\Sounds\\Shoot.wav";
			static const LPCTSTR ballInPocket = L"C:\\NineBall\\Sounds\\Ball_In.wav";
		};

		enum class walls
		{
			allOK,
			topWall = 89,
			leftWall = 96,
			bottomWall = 534,
			rightWall = 885,
		}wall;

		enum class players
		{
			player1,
			player2
		};

		const int HALFWAY_POINT = (int)walls::leftWall +
			(((int)walls::rightWall - (int)walls::leftWall) / 2);

	private: System::Windows::Forms::Label^  labelPlayer1;
	private: System::Windows::Forms::Label^  labelPlayer2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  poolTable;
	private: System::Windows::Forms::Label^  titleLabel;
	private: NineBall::BilliardBall^  cueball;
	private: NineBall::BilliardBall^  ball1;
	private: NineBall::BilliardBall^  ball2;
	private: NineBall::BilliardBall^  ball3;
	private: NineBall::BilliardBall^  ball4;
	private: NineBall::BilliardBall^  ball7;
	private: NineBall::BilliardBall^  ball5;
	private: NineBall::BilliardBall^  ball6;
	private: NineBall::BilliardBall^  ball8;
	private: NineBall::BilliardBall^  ball9;
	private: System::Windows::Forms::Timer^  startupTimer;

	private: System::Windows::Forms::ContextMenuStrip^  rightClickMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  spotCueBallMenuItem;

	private: System::Windows::Forms::ToolStripSeparator^  separator;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mainMenuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rackBallsToolStripMenuItem;

	public:

		MainForm(void)
		{
			InitializeComponent();
			//
			// Add all billiard balls.
			balls.Add(cueball);
			balls.Add(ball1);
			balls.Add(ball2);
			balls.Add(ball3);
			balls.Add(ball4);
			balls.Add(ball5);
			balls.Add(ball6);
			balls.Add(ball7);
			balls.Add(ball8);
			balls.Add(ball9);
			//
			for (int i = 1; i < 10; i++)
			{
				ballsInPlay.Add((Byte)i);
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:
	private:
		/// <summary>
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->labelPlayer1 = (gcnew System::Windows::Forms::Label());
			this->rightClickMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->rackBallsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->spotCueBallMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->separator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ball7 = (gcnew NineBall::BilliardBall());
			this->ball3 = (gcnew NineBall::BilliardBall());
			this->ball5 = (gcnew NineBall::BilliardBall());
			this->ball4 = (gcnew NineBall::BilliardBall());
			this->ball6 = (gcnew NineBall::BilliardBall());
			this->ball8 = (gcnew NineBall::BilliardBall());
			this->ball9 = (gcnew NineBall::BilliardBall());
			this->ball2 = (gcnew NineBall::BilliardBall());
			this->ball1 = (gcnew NineBall::BilliardBall());
			this->cueball = (gcnew NineBall::BilliardBall());
			this->poolTable = (gcnew System::Windows::Forms::Label());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->labelPlayer2 = (gcnew System::Windows::Forms::Label());
			this->startupTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->rightClickMenu->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// labelPlayer1
			// 
			this->labelPlayer1->AutoSize = true;
			this->labelPlayer1->ContextMenuStrip = this->rightClickMenu;
			this->labelPlayer1->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayer1->ForeColor = System::Drawing::Color::White;
			this->labelPlayer1->Location = System::Drawing::Point(141, 82);
			this->labelPlayer1->Name = L"labelPlayer1";
			this->labelPlayer1->Size = System::Drawing::Size(91, 29);
			this->labelPlayer1->TabIndex = 0;
			this->labelPlayer1->Text = L"Player 1";
			this->labelPlayer1->Visible = false;
			// 
			// rightClickMenu
			// 
			this->rightClickMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->rightClickMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->rackBallsToolStripMenuItem,
					this->mainMenuToolStripMenuItem, this->spotCueBallMenuItem, this->separator, this->exitToolStripMenuItem, this->testToolStripMenuItem
			});
			this->rightClickMenu->Name = L"rightClickMenu";
			this->rightClickMenu->Size = System::Drawing::Size(176, 158);
			this->rightClickMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::rightClickMenu_Opening);
			// 
			// rackBallsToolStripMenuItem
			// 
			this->rackBallsToolStripMenuItem->Name = L"rackBallsToolStripMenuItem";
			this->rackBallsToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->rackBallsToolStripMenuItem->Text = L"Rack Balls";
			this->rackBallsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::rackBallsToolStripMenuItem_Click);
			// 
			// mainMenuToolStripMenuItem
			// 
			this->mainMenuToolStripMenuItem->Name = L"mainMenuToolStripMenuItem";
			this->mainMenuToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->mainMenuToolStripMenuItem->Text = L"Main Menu";
			this->mainMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::mainMenuToolStripMenuItem_Click);
			// 
			// spotCueBallMenuItem
			// 
			this->spotCueBallMenuItem->Name = L"spotCueBallMenuItem";
			this->spotCueBallMenuItem->Size = System::Drawing::Size(175, 24);
			this->spotCueBallMenuItem->Text = L"&SpotCue Ball";
			this->spotCueBallMenuItem->Click += gcnew System::EventHandler(this, &MainForm::moveTheCueBallSpotToolStripMenuItem_Click);
			// 
			// separator
			// 
			this->separator->Name = L"separator";
			this->separator->Size = System::Drawing::Size(172, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->exitToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->exitToolStripMenuItem->Text = L"&Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(175, 24);
			this->testToolStripMenuItem->Text = L"Test";
			this->testToolStripMenuItem->Visible = false;
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::testToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->ContextMenuStrip = this->rightClickMenu;
			this->panel1->Controls->Add(this->ball7);
			this->panel1->Controls->Add(this->ball3);
			this->panel1->Controls->Add(this->ball5);
			this->panel1->Controls->Add(this->ball4);
			this->panel1->Controls->Add(this->ball6);
			this->panel1->Controls->Add(this->ball8);
			this->panel1->Controls->Add(this->ball9);
			this->panel1->Controls->Add(this->ball2);
			this->panel1->Controls->Add(this->ball1);
			this->panel1->Controls->Add(this->cueball);
			this->panel1->Controls->Add(this->poolTable);
			this->panel1->Location = System::Drawing::Point(94, 147);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1011, 656);
			this->panel1->TabIndex = 6;
			// 
			// ball7
			// 
			this->ball7->AddY = false;
			this->ball7->Angle = 0;
			this->ball7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball7->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball7.BallImage")));
			this->ball7->Destination = System::Drawing::Point(0, 0);
			this->ball7->Distance = 0;
			this->ball7->FirstPos_X = 0;
			this->ball7->FirstPos_Y = 0;
			this->ball7->ForeColor = System::Drawing::Color::White;
			this->ball7->Location = System::Drawing::Point(737, 295);
			this->ball7->MoveVal = 0;
			this->ball7->Moving = false;
			this->ball7->Name = L"ball7";
			this->ball7->PosX = 0;
			this->ball7->PosY = 0;
			this->ball7->Size = System::Drawing::Size(34, 34);
			this->ball7->Slope = 0;
			this->ball7->SpeedX = 0;
			this->ball7->SpeedY = 0;
			this->ball7->StartPos = System::Drawing::Point(737, 295);
			this->ball7->TabIndex = 15;
			this->ball7->Tag = L"7";
			this->ball7->Y_intercept = 0;
			// 
			// ball3
			// 
			this->ball3->AddY = false;
			this->ball3->Angle = 0;
			this->ball3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball3->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball3.BallImage")));
			this->ball3->Destination = System::Drawing::Point(0, 0);
			this->ball3->Distance = 0;
			this->ball3->FirstPos_X = 0;
			this->ball3->FirstPos_Y = 0;
			this->ball3->ForeColor = System::Drawing::Color::White;
			this->ball3->Location = System::Drawing::Point(679, 295);
			this->ball3->MoveVal = 0;
			this->ball3->Moving = false;
			this->ball3->Name = L"ball3";
			this->ball3->PosX = 0;
			this->ball3->PosY = 0;
			this->ball3->Size = System::Drawing::Size(34, 34);
			this->ball3->Slope = 0;
			this->ball3->SpeedX = 0;
			this->ball3->SpeedY = 0;
			this->ball3->StartPos = System::Drawing::Point(679, 295);
			this->ball3->TabIndex = 14;
			this->ball3->Tag = L"3";
			this->ball3->Y_intercept = 0;
			// 
			// ball5
			// 
			this->ball5->AddY = false;
			this->ball5->Angle = 0;
			this->ball5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball5->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball5.BallImage")));
			this->ball5->Destination = System::Drawing::Point(0, 0);
			this->ball5->Distance = 0;
			this->ball5->FirstPos_X = 0;
			this->ball5->FirstPos_Y = 0;
			this->ball5->ForeColor = System::Drawing::Color::White;
			this->ball5->Location = System::Drawing::Point(708, 278);
			this->ball5->MoveVal = 0;
			this->ball5->Moving = false;
			this->ball5->Name = L"ball5";
			this->ball5->PosX = 0;
			this->ball5->PosY = 0;
			this->ball5->Size = System::Drawing::Size(34, 34);
			this->ball5->Slope = 0;
			this->ball5->SpeedX = 0;
			this->ball5->SpeedY = 0;
			this->ball5->StartPos = System::Drawing::Point(708, 278);
			this->ball5->TabIndex = 13;
			this->ball5->Tag = L"5";
			this->ball5->Y_intercept = 0;
			// 
			// ball4
			// 
			this->ball4->AddY = false;
			this->ball4->Angle = 0;
			this->ball4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball4->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball4.BallImage")));
			this->ball4->Destination = System::Drawing::Point(0, 0);
			this->ball4->Distance = 0;
			this->ball4->FirstPos_X = 0;
			this->ball4->FirstPos_Y = 0;
			this->ball4->ForeColor = System::Drawing::Color::White;
			this->ball4->Location = System::Drawing::Point(708, 346);
			this->ball4->MoveVal = 0;
			this->ball4->Moving = false;
			this->ball4->Name = L"ball4";
			this->ball4->PosX = 0;
			this->ball4->PosY = 0;
			this->ball4->Size = System::Drawing::Size(34, 34);
			this->ball4->Slope = 0;
			this->ball4->SpeedX = 0;
			this->ball4->SpeedY = 0;
			this->ball4->StartPos = System::Drawing::Point(708, 346);
			this->ball4->TabIndex = 12;
			this->ball4->Tag = L"4";
			this->ball4->Y_intercept = 0;
			// 
			// ball6
			// 
			this->ball6->AddY = false;
			this->ball6->Angle = 0;
			this->ball6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball6->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball6.BallImage")));
			this->ball6->Destination = System::Drawing::Point(0, 0);
			this->ball6->Distance = 0;
			this->ball6->FirstPos_X = 0;
			this->ball6->FirstPos_Y = 0;
			this->ball6->ForeColor = System::Drawing::Color::White;
			this->ball6->Location = System::Drawing::Point(737, 328);
			this->ball6->MoveVal = 0;
			this->ball6->Moving = false;
			this->ball6->Name = L"ball6";
			this->ball6->PosX = 0;
			this->ball6->PosY = 0;
			this->ball6->Size = System::Drawing::Size(34, 34);
			this->ball6->Slope = 0;
			this->ball6->SpeedX = 0;
			this->ball6->SpeedY = 0;
			this->ball6->StartPos = System::Drawing::Point(737, 328);
			this->ball6->TabIndex = 11;
			this->ball6->Tag = L"6";
			this->ball6->Y_intercept = 0;
			// 
			// ball8
			// 
			this->ball8->AddY = false;
			this->ball8->Angle = 0;
			this->ball8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball8->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball8.BallImage")));
			this->ball8->Destination = System::Drawing::Point(0, 0);
			this->ball8->Distance = 0;
			this->ball8->FirstPos_X = 0;
			this->ball8->FirstPos_Y = 0;
			this->ball8->ForeColor = System::Drawing::Color::White;
			this->ball8->Location = System::Drawing::Point(765, 312);
			this->ball8->MoveVal = 0;
			this->ball8->Moving = false;
			this->ball8->Name = L"ball8";
			this->ball8->PosX = 0;
			this->ball8->PosY = 0;
			this->ball8->Size = System::Drawing::Size(34, 34);
			this->ball8->Slope = 0;
			this->ball8->SpeedX = 0;
			this->ball8->SpeedY = 0;
			this->ball8->StartPos = System::Drawing::Point(765, 312);
			this->ball8->TabIndex = 10;
			this->ball8->Tag = L"8";
			this->ball8->Y_intercept = 0;
			// 
			// ball9
			// 
			this->ball9->AddY = false;
			this->ball9->Angle = 0;
			this->ball9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball9->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball9.BallImage")));
			this->ball9->Destination = System::Drawing::Point(0, 0);
			this->ball9->Distance = 0;
			this->ball9->FirstPos_X = 0;
			this->ball9->FirstPos_Y = 0;
			this->ball9->ForeColor = System::Drawing::Color::White;
			this->ball9->Location = System::Drawing::Point(708, 312);
			this->ball9->MoveVal = 0;
			this->ball9->Moving = false;
			this->ball9->Name = L"ball9";
			this->ball9->PosX = 0;
			this->ball9->PosY = 0;
			this->ball9->Size = System::Drawing::Size(34, 34);
			this->ball9->Slope = 0;
			this->ball9->SpeedX = 0;
			this->ball9->SpeedY = 0;
			this->ball9->StartPos = System::Drawing::Point(708, 312);
			this->ball9->TabIndex = 9;
			this->ball9->Tag = L"9";
			this->ball9->Y_intercept = 0;
			// 
			// ball2
			// 
			this->ball2->AddY = false;
			this->ball2->Angle = 0;
			this->ball2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball2->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball2.BallImage")));
			this->ball2->Destination = System::Drawing::Point(0, 0);
			this->ball2->Distance = 0;
			this->ball2->FirstPos_X = 0;
			this->ball2->FirstPos_Y = 0;
			this->ball2->ForeColor = System::Drawing::Color::White;
			this->ball2->Location = System::Drawing::Point(679, 328);
			this->ball2->MoveVal = 0;
			this->ball2->Moving = false;
			this->ball2->Name = L"ball2";
			this->ball2->PosX = 0;
			this->ball2->PosY = 0;
			this->ball2->Size = System::Drawing::Size(34, 34);
			this->ball2->Slope = 0;
			this->ball2->SpeedX = 0;
			this->ball2->SpeedY = 0;
			this->ball2->StartPos = System::Drawing::Point(679, 328);
			this->ball2->TabIndex = 8;
			this->ball2->Tag = L"2";
			this->ball2->Y_intercept = 0;
			// 
			// ball1
			// 
			this->ball1->AddY = false;
			this->ball1->Angle = 0;
			this->ball1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->ball1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ball1->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball1.BallImage")));
			this->ball1->Destination = System::Drawing::Point(0, 0);
			this->ball1->Distance = 0;
			this->ball1->FirstPos_X = 0;
			this->ball1->FirstPos_Y = 0;
			this->ball1->ForeColor = System::Drawing::Color::White;
			this->ball1->Location = System::Drawing::Point(650, 312);
			this->ball1->MoveVal = 0;
			this->ball1->Moving = false;
			this->ball1->Name = L"ball1";
			this->ball1->PosX = 0;
			this->ball1->PosY = 0;
			this->ball1->Size = System::Drawing::Size(34, 34);
			this->ball1->Slope = 0;
			this->ball1->SpeedX = 0;
			this->ball1->SpeedY = 0;
			this->ball1->StartPos = System::Drawing::Point(650, 312);
			this->ball1->TabIndex = 7;
			this->ball1->Tag = L"1";
			this->ball1->Y_intercept = 0;
			// 
			// cueball
			// 
			this->cueball->AddY = false;
			this->cueball->Angle = 0;
			this->cueball->BackColor = System::Drawing::Color::Gainsboro;
			this->cueball->BallImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cueball.BallImage")));
			this->cueball->Destination = System::Drawing::Point(0, 0);
			this->cueball->Distance = 0;
			this->cueball->FirstPos_X = 0;
			this->cueball->FirstPos_Y = 0;
			this->cueball->ForeColor = System::Drawing::Color::White;
			this->cueball->Location = System::Drawing::Point(237, 312);
			this->cueball->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->cueball->MoveVal = 0;
			this->cueball->Moving = false;
			this->cueball->Name = L"cueball";
			this->cueball->PosX = 0;
			this->cueball->PosY = 0;
			this->cueball->Size = System::Drawing::Size(34, 34);
			this->cueball->Slope = 0;
			this->cueball->SpeedX = 0;
			this->cueball->SpeedY = 0;
			this->cueball->StartPos = System::Drawing::Point(237, 312);
			this->cueball->TabIndex = 1;
			this->cueball->Tag = L"0";
			this->cueball->Y_intercept = 0;
			this->cueball->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::cueball_MouseDown);
			this->cueball->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::cueball_MouseMove);
			// 
			// poolTable
			// 
			this->poolTable->ContextMenuStrip = this->rightClickMenu;
			this->poolTable->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"poolTable.Image")));
			this->poolTable->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->poolTable->Location = System::Drawing::Point(0, 0);
			this->poolTable->Name = L"poolTable";
			this->poolTable->Size = System::Drawing::Size(1011, 656);
			this->poolTable->TabIndex = 6;
			this->poolTable->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::poolTable_MouseDown);
			this->poolTable->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::poolTable_MouseMove);
			// 
			// titleLabel
			// 
			this->titleLabel->ContextMenuStrip = this->rightClickMenu;
			this->titleLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(0, 0);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(1260, 68);
			this->titleLabel->TabIndex = 7;
			this->titleLabel->Text = L"Nine Ball  ";
			this->titleLabel->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// labelPlayer2
			// 
			this->labelPlayer2->AutoSize = true;
			this->labelPlayer2->ContextMenuStrip = this->rightClickMenu;
			this->labelPlayer2->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayer2->ForeColor = System::Drawing::Color::DimGray;
			this->labelPlayer2->Location = System::Drawing::Point(996, 82);
			this->labelPlayer2->Name = L"labelPlayer2";
			this->labelPlayer2->Size = System::Drawing::Size(91, 29);
			this->labelPlayer2->TabIndex = 8;
			this->labelPlayer2->Text = L"Player 2";
			this->labelPlayer2->Visible = false;
			// 
			// startupTimer
			// 
			this->startupTimer->Tick += gcnew System::EventHandler(this, &MainForm::startupTimer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1260, 800);
			this->ContextMenuStrip = this->rightClickMenu;
			this->ControlBox = false;
			this->Controls->Add(this->labelPlayer2);
			this->Controls->Add(this->labelPlayer1);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->rightClickMenu->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		play_Sound(sounds::StartupMusic);
		centerPoolTable();
		startupTimer->Start();
	}

	private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	private: System::Void cueball_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//
		if (e->Button == ::MouseButtons::Left)
		{
			if (!drawline && !moveCueBall)
			{
				panel1->Cursor = Cursors::Cross;
				gr = poolTable->CreateGraphics();
				qstart = cueball->Location;
				qctr.X = qstart.X + cueball->Width / 2 + 1;
				qctr.Y = qstart.Y + cueball->Height / 2 + 1;
				drawline = true;
			}
			else if (moveCueBall)
			{
				moveCueBall = false;
				panel1->Cursor = Cursors::Default;
			}
		}
	}

	private: void sendAimPoint(Point aimpt)
	{
		try
		{

			System::IO::File::WriteAllText("H:\\Nineball\\data.nine", aimpt.X + Environment::NewLine + aimpt.Y);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->ToString());
		}

	}

	private: Point readAimPoint()
	{
		try
		{
			System::IO::StreamReader^ sr =
				gcnew System::IO::StreamReader("C:\\Nineball\\data.nine");
			String^ x;
			String^ y;
			x = sr->ReadLine();
			y = sr->ReadLine();
			sr->Close();
			return Point(int::Parse(x), int::Parse(y));
		}
		catch (Exception^ ex)
		{
			return (Point(-1, -1));
			MessageBox::Show("Error: " + ex->ToString());
		}
	}

	private: void remoteHitBall()
	{
		aimPt = readAimPoint();
		if (aimPt.X == -1)
		{
			return;
		}
		play_Sound(sounds::shoot);
		drawline = false;
		//
		// Set add composite flag to true, 
		// which makes moving objects look
		// better.
		addCompositeStyle = true;
		//
		poolTable->Refresh();
		// Attempt to convert aim point to cue end point.
		cueEndPt = Point(aimPt.X - 17, aimPt.Y - 17);
		//
		// The point conversion seems to be between 17 and
		// 18, but 17 seems to work most of the time.
		// For those times that the vertical or horizontal
		// line is off by one pixel, a bool named 'lineWasStraight'
		// was set in the pool table mouse move event.
		if (lineWasStraight && (cueball->Location.X != cueEndPt.X ||
			cueball->Location.Y != cueEndPt.Y))
		{
			// Change either x or y to make the direction
			// fully vertical or horizontal.
			Math::Abs(cueball->Left - cueEndPt.X) < Math::Abs(cueball->Top - cueEndPt.Y) ?
				cueEndPt.X = cueball->Location.X : cueEndPt.Y = cueball->Location.Y;
		}
		double checkDist = (GetDistance(cueEndPt, cueball->Location)) / (double)10;;
		if (checkDist > 25)
		{
			checkDist = 25;
		}
		cueball->Distance = checkDist;
		cueball->Moving = true;
		cueball->Angle = GetAngle(cueball->Location, cueEndPt);
		cueball->FirstPos_X = cueball->Left;
		cueball->FirstPos_Y = cueball->Top;
		// Reset playerScored to false.
		// It will be set to true if the player scores,
		// in the ballInPocket function.
		playerScored = false;
		moveBalls();
		if (breaking)
		{
			breaking = false;
			friction = .935;
		}
		//
		// Reset add composite flag to false,
		// so that the focus line is visible
		// when we draw it.
		addCompositeStyle = false;
		//		
		panel1->Cursor = Cursors::Default;

	}

	private: System::Void poolTable_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (drawline)
		{
			if (e->Button == ::MouseButtons::Left)
			{
				play_Sound(sounds::shoot);
				soundThread->Join(20);
				drawline = false;
				//
				// Set add composite flag to true, 
				// which makes moving objects look
				// better.
				addCompositeStyle = true;
				//
				poolTable->Refresh();
				// Attempt to convert aim point to cue end point.
				cueEndPt = Point(aimPt.X - 17, aimPt.Y - 17);
				//
				// The point conversion seems to be between 17 and
				// 18, but 17 seems to work most of the time.
				// For those times that the vertical or horizontal
				// line is off by one pixel, a bool named 'lineWasStraight'
				// was set in the pool table mouse move event.

				// This is disabled in network game, until we can pass
				// this value to the other game.
				if (!networkGame && lineWasStraight && (cueball->Location.X != cueEndPt.X ||
					cueball->Location.Y != cueEndPt.Y))
				{

					// Change either x or y to make the direction
					// fully vertical or horizontal.
					Math::Abs(cueball->Left - cueEndPt.X) < Math::Abs(cueball->Top - cueEndPt.Y) ?
						cueEndPt.X = cueball->Location.X : cueEndPt.Y = cueball->Location.Y;
				}
				double checkDist = (GetDistance(cueEndPt, cueball->Location)) / (double)10;;
				if (checkDist > 25)
				{
					checkDist = 25;
				}
				cueball->Distance = checkDist;
				cueball->Moving = true;
				cueball->Angle = GetAngle(cueball->Location, cueEndPt);
				cueball->FirstPos_X = cueball->Left;
				cueball->FirstPos_Y = cueball->Top;
				// Reset playerScored to false.
				// It will be set to true if the player scores,
				// in the ballInPocket function.
				playerScored = false;
				moveBalls();
				if (breaking)
				{
					breaking = false;
					friction = .990;
				}
				//
				// Reset add composite flag to false,
				// so that the focus line is visible
				// when we draw it.
				addCompositeStyle = false;
				//		
				panel1->Cursor = Cursors::Default;



			}
		}
		else if (moveCueBall)
		{
			moveCueBall = false;
			panel1->Cursor = Cursors::Default;
		}
	}

	private: Direction getDirection(BilliardBall^ ball)
	{
		if (ball->Left == 0 || ball->Top == 0)
		{
			MessageBox::Show("Error at: getDirection(). Either the 'ball->Left' " +
				Environment::NewLine + "or the 'ball->Top' property is zero." +
				Environment::NewLine + "ball->Left = " + ball->Left + Environment::NewLine +
				"ball->Top = " + ball->Top);
		}

		bool ok = false;
		if (ball->Left > ball->FirstPos_X)
		{
			if (ball->FirstPos_Y > ball->Top)
			{
				ok = true;
				Dir = Direction::upper_right;
			}
			else if (ball->FirstPos_Y < ball->Top)
			{
				ok = true;
				Dir = Direction::lower_right;
			}
			else
			{
				ok = true;
				Dir = Direction::right;
			}
		}
		else if (ball->Left < ball->FirstPos_X) // (&endptX < &startptX)
		{
			if (ball->FirstPos_Y >  ball->Top) // (&startptY > &endptY)
			{
				ok = true;
				Dir = Direction::upper_left;
			}
			else if (ball->FirstPos_Y < ball->Top)  // (&startptY < &endptY)
			{
				ok = true;
				Dir = Direction::lower_left;
			}
			else
			{
				ok = true;
				Dir = Direction::left;
			}
		}
		else // Both x values equal.
		{
			if (ball->FirstPos_Y >  ball->Top) // (&startptY > &endptY)
			{
				ok = true;
				Dir = Direction::up;
			}
			else if (ball->FirstPos_Y < ball->Top) // (&startptY < &endptY)
			{
				ok = true;
				Dir = Direction::down;
			}
			else
			{
				// todo: Check if ball is out of bounds, and remove
				// ball by setting visible to false.
				if (boundaryCheck(ball->Left, ball->Top))
				{
					play_Sound(sounds::ballInPocket);
					soundThread->Join(10);
					ball->Visible = false;
				}
				
				// todo: log the error.

				//MessageBox::Show("Error at: getDirection(). Ball location = " + ball->Location);

				ok = true;
				Dir = Direction::unknown;

			}
		}
		if (!ok)
		{
			MessageBox::Show("Error at getdirection(). Bad logic. Check the code.");
		}
		return Dir;
	}


	private: bool boundaryCheck(float x, float y)
	{
		// Returns true if point is within the play
		// boundaries, otherwise false.
		return (x >= (int)walls::leftWall &&
			y >= (int)walls::topWall &&
			x <= (int)walls::rightWall &&
			y <= (int)walls::bottomWall);
	}

	private: bool boudaryErrorCheck(BilliardBall^ ball)
	{
		// Returns true if ball is out of boundaries
		// of play area, otherwise it returns false.
		bool ret = false;
		if (ball->Left < (int)walls::leftWall ||
			ball->Top < (int)walls::topWall ||
			ball->Left >(int)walls::rightWall ||
			ball->Top >(int)walls::bottomWall)
		{
			ret = true;
		}
		return ret;
	}


	private: void RackBalls()
	{
		balls.Clear();
		balls.Add(cueball);
		balls.Add(ball1);
		balls.Add(ball2);
		balls.Add(ball3);
		balls.Add(ball4);
		balls.Add(ball5);
		balls.Add(ball6);
		balls.Add(ball7);
		balls.Add(ball8);
		balls.Add(ball9);
		for each (BilliardBall^ ball in balls)
		{
			ball->Moving = false;
			ball->Distance = 0;
			ball->Location = ball->StartPos;
			ball->Show();
		}
		ballsInPlay.Clear();
		for (int i = 1; i < 10; i++)
		{
			ballsInPlay.Add((Byte)i);
		}
		player1ScoresInARow = 0;
		player2ScoresInARow = 0;
		labelPlayer1->Show();
		labelPlayer2->Show();
		spotCueBallMenuItem->Enabled = true;
		this->Refresh();
	}



	private: bool distanceBetweenBalls(BilliardBall^ ball1, BilliardBall^ ball2)
	{
		double b1x = ball1->Top;
		double b1y = ball1->Left;
		double b2x = ball2->Top;
		double b2y = ball2->Left;

		double distance = Math::Sqrt(((b2x - b1x)*(b2x - b1x)) + ((b2y - b1y)*(b2y - b1y)));
		if (distance <= BALL_HEIGHT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	private: double GetDistance(PointF p1, PointF p2)
	{
		double distance = Math::Sqrt(((p2.X - p1.X)*(p2.X - p1.X)) + ((p2.Y - p1.Y)*(p2.Y - p1.Y)));
		return distance;
	}

	private: float GetAngle(PointF p1, PointF p2)
	{
		float xDiff = p2.X - p1.X;
		float yDiff = p2.Y - p1.Y;

		return Math::Atan2(yDiff, xDiff);
		// * (180 / Math::PI)
		// -See more at : http ://wikicode.wikidot.com/get-angle-of-line-between-two-points#sthash.A3inVwqW.dpuf

	}	

	private: bool ballInPocket(BilliardBall^ ball, walls wall)
	{
		bool ballIn = false;
		switch (wall)
		{
		case walls::topWall:
			if (ball->Left <= (int)walls::leftWall + POCKET_WIDTH ||
				ball->Left >= (int)walls::rightWall - POCKET_WIDTH ||
				(ball->Left > HALFWAY_POINT - 20 && ball->Left < HALFWAY_POINT + 20))
			{
				//this->Refresh();
				ball->Visible = false;
				ballIn = true;
			}
			break;
		case walls::leftWall:
			if (ball->Top <= (int)walls::topWall + POCKET_WIDTH ||
				ball->Top >= (int)walls::bottomWall - POCKET_WIDTH)
			{
				//this->Refresh();
				ball->Visible = false;
				ballIn = true;
			}
			break;
		case walls::bottomWall:
			if (ball->Left <= (int)walls::leftWall + POCKET_WIDTH ||
				ball->Left >= (int)walls::rightWall - POCKET_WIDTH ||
				(ball->Left > HALFWAY_POINT - 20 && ball->Left < HALFWAY_POINT + 20))
			{
				//this->Refresh();
				ball->Visible = false;
				ballIn = true;
			}
			break;
		case walls::rightWall:
			if (ball->Top <= ((int)walls::topWall + POCKET_WIDTH) ||
				ball->Top >= ((int)walls::bottomWall - POCKET_WIDTH))
			{
				ball->Visible = false;
				//this->Refresh();
				ballIn = true;
			}
			break;
		}
		if (ballIn)
		{
			play_Sound(sounds::ballInPocket);
			soundThread->Join(20);
			if (ballsInPlay.Count > 0)
			{
				playerScored = ballsInPlay[0] == Convert::ToByte(ball->Tag) && goodHit;
			}
			else
			{
				playerScored = goodHit;
			}

			// Yield to the playsound thread,
			// so it plays with no delay.
			//Thread::Sleep(10);
			//this->Refresh();
			if (ball != cueball)
			{
				// Remove the ball from balls in play list,
				ballsInPlay.Remove(Convert::ToByte(ball->Tag));
			}

		}
		return ballIn;
	}


	private: void moveBallIntoBoundaries(BilliardBall^ ball)
	{

		// todo: figure out why this occasionally happens.
		// Move destination back inside boundaries; 
		// move it to the nearest wall that it is closest
		// to.
		if (ball->Left < (int)(walls::leftWall))
		{
			int newX = (int)(walls::leftWall) + 5;
			ball->Angle = GetAngle(ball->Location, Point(newX, ball->Top));
			ball->Left = newX;
			ball->PosX = ball->Left;
			ball->PosY = ball->Top;
		}
		else if (ball->Left > (int)(walls::rightWall))
		{
			int newX = (int)(walls::leftWall) - 5;
			ball->Angle = GetAngle(ball->Location, Point(newX, ball->Top));
			ball->Left = newX;
			ball->PosX = ball->Left;
			ball->PosY = ball->Top;
		}
		//
		if (ball->Top < (int)(walls::topWall))
		{
			int newY = (int)(walls::topWall) + 5;
			ball->Angle = GetAngle(ball->Location, Point(ball->Left, newY));
			ball->Top = newY;
			ball->PosX = ball->Left;
			ball->PosY = ball->Top;
			//ball->Top = (int)(walls::topWall) + 5;
		}
		else if (ball->Top > (int)(walls::bottomWall))
		{
			ball->Top = (int)(walls::bottomWall) - 5;
		}
	}

	private: void bounceFromTopWall(BilliardBall^ ball)
	{
		double reflectAngle = (Math::PI / -2) - ((Math::PI / -2) + ball->Angle) + (2 * Math::PI);
		ball->Angle = reflectAngle;
		ball->SpeedX = ball->Distance * Math::Cos(ball->Angle);
		ball->SpeedY = ball->Distance * Math::Sin(ball->Angle);
		this->Refresh();
	}

	private: void bounceFromLeftWall(BilliardBall^ ball)
	{
		{
			double reflectAngle = (0 - ball->Angle) + Math::PI;
			if (reflectAngle > Math::PI)
			{
				reflectAngle = reflectAngle - (2 * Math::PI);
			}
			ball->Angle = reflectAngle;
			ball->SpeedX = ball->Distance * Math::Cos(ball->Angle);
			ball->SpeedY = ball->Distance * Math::Sin(ball->Angle);
		}
	}

	private: void bounceFromRightWall(BilliardBall^ ball)
	{
		double reflectAngle = (0 - ball->Angle) + Math::PI;
		if (reflectAngle > Math::PI)
		{
			reflectAngle = reflectAngle - (2 * Math::PI);
		}
		ball->Angle = reflectAngle;
		ball->SpeedX = ball->Distance * Math::Cos(ball->Angle);
		ball->SpeedY = ball->Distance * Math::Sin(ball->Angle);
	}

	private: void bounceFromBottomWall(BilliardBall^ ball)
	{
		double reflectAngle;
		reflectAngle = (Math::PI / -2) - ((Math::PI / -2) + ball->Angle) + (2 * Math::PI);
		ball->Angle = reflectAngle;
		ball->SpeedX = ball->Distance * Math::Cos(ball->Angle);
		ball->SpeedY = ball->Distance * Math::Sin(ball->Angle);
	}

	


	private: bool checkWallsAndPockets_New(BilliardBall^ ball)
	{
		// Line Formulas.
		//
		// m = change of y / change of x
		// y-intercept, or 'b' = y - (m * x)
		// y = mx + b
		// x = (y - b) / m

		if (ball->Location == Point(ball->FirstPos_X, ball->FirstPos_Y))
		{
			// This is the first time the ball is moving.
			return false;
		}
		// Get current destination point.
		if (ball->PosX == ball->Left && ball->PosY == ball->Top)
		{
			if (!boundaryCheck(ball->PosX, ball->PosY))
			{
				MessageBox::Show("Error At checkWallsAndPockets. " + Environment::NewLine +
					"The ball position is out of bounds.");
			}
			return false;
		}

		getDirection(ball);
		if (Dir == Direction::unknown)
		{
			MessageBox::Show("Fatal Error at: checkWallsAndPockets(). getDirection() method returned direction 'unknown'.");
			ballsMoving = false;
			ball->Moving = false;
			Application::Exit();
			return false;
		}
		wall = wallCheck(ball);
		if (wall == walls::allOK)
		{
			return false;
		}
		else if (ballInPocket(ball, wall))
		{
			return false;
		}
		//
		switch (wall)
		{
		case walls::topWall:
			bounceFromTopWall(ball);
			break;
		case walls::leftWall:
			bounceFromLeftWall(ball);
			break;
		case walls::bottomWall:
			bounceFromBottomWall(ball);
			break;
		case walls::rightWall:
			bounceFromRightWall(ball);
			break;
		}
		//
		ball->Distance *= bounceFriction;
		this->Refresh();
		// The ball was bounced, so return true.
		return true;
	}


	private: void setDestinationPoint(BilliardBall^ ball)
	{
		ball->SpeedX = ball->Distance * Math::Cos(ball->Angle);
		ball->SpeedY = ball->Distance * Math::Sin(ball->Angle);
		ball->PosX += ball->SpeedX;
		ball->PosY += ball->SpeedY;
		checkWallsAndPockets(ball);
		ball->Location = Point(ball->PosX, ball->PosY);
		//this->Refresh();
		ball->Distance *= friction;
		// Prevent balls from 'disappearing' and
		// 'reappearing' on the other side of the
		// pool table.
		if (ball->Distance > 10)
		{
			this->Refresh();
		}
		else if (ball->Distance < 0.0435)
		{
			ball->Moving = false;
			ball->Distance = 0;
		}
	}

			 //ORION NOTE: WOO! This finally is working. The balls bounce off each other
			 // at correct angles. The only problem is factoring in the correct speed
			 // based off angle.
			 // I tried a few ways but was unable to get it to work. Basically, the closer
			 // to 90 degrees it hits, the less speed should be imparted onto the hit ball, 
			 // the closer to 0, or dead on, the more should be transferred.

			 // MATT NOTE: Ball collisions was the most difficult problem to solve.
			 // Orion's checkBallCollision() method uses trigonometry to get the
			 // correct angles.

			 // Do Not modify this method without backing up the code first.	
			 //
	private: void checkBallCollision(BilliardBall^ striker, BilliardBall^ struck)
	{
		if (distanceBetweenBalls(striker, struck))
		{
			play_Sound(sounds::ballHit);
			soundThread->Join(20);
			//Thread::Sleep(10);
			if (firstHit)
			{
				firstHit = false;
				// Its a good hit if the ball struck the
				// first ball in the ballin play list.
				// ball in sequence. Since this is 
				// the first hit, one of these balls
				// should be the cue ball.				
				if (ballsInPlay.Count > 0)
				{
					goodHit = (ballsInPlay[0] == Convert::ToByte(striker->Tag) ||
						ballsInPlay[0] == Convert::ToByte(struck->Tag));
				}
		
			}
			struck->Moving = true;
			double velocityStrike = 0;
			double velocityStruck = 0;
			double struckBallAngle = GetAngle(striker->Location, struck->Location);
			double strikerBallAngle = GetAngle(struck->Location, striker->Location);

			double angleDiff =
				(Math::Abs(Math::Abs(struckBallAngle) -
				Math::Abs(striker->Angle)));

			if (strikerBallAngle > striker->Angle)
			{
				striker->Angle = striker->Angle + (1 / (strikerBallAngle - striker->Angle));
			}
			else
			{
				striker->Angle = striker->Angle - (1 / (striker->Angle - strikerBallAngle));
			}
			struck->Angle = struckBallAngle;
			double distance = GetDistance(striker->Location, struck->Location);
			struck->PosX += (BALL_WIDTH - distance) * Math::Cos(struckBallAngle);
			struck->PosY += (BALL_WIDTH - distance) * Math::Sin(struckBallAngle);
			struck->FirstPos_X = struck->PosX;
			struck->FirstPos_Y = struck->PosY;

			// Call checkWallsAndPockets() to make
			// sure the struck ball is not headed past a wall
			//on this location change.			
			checkWallsAndPockets(struck);
			struck->Location = Point(struck->PosX, struck->PosY);
			//this->Refresh();

			double angleMulti = (Math::PI - angleDiff) / Math::PI;
			if (angleMulti < .1)
			{
				angleMulti = .1;
			}
			if (angleMulti > .9)
			{
				angleMulti = .9;
				if (striker->Angle >= 0)
				{
					striker->Angle -= Math::PI;
				}
				else
				{
					striker->Angle += Math::PI;
				}
			}

			struck->Distance = (striker->Distance * (angleMulti));
			striker->Distance = (striker->Distance *  (1 - angleMulti));

			//double stop = striker->Distance;			
		}
	}

			 //ORION NOTE: This function should not take an argument, instead it just runs, and inside the while loop
			 // is a for-each loop that iterates through each ball and does the action.
	private: void moveBalls()
	{
		// ORION NOTE: these next lines of code can be in a for-each loop that is set each balls starting posx and y and moving to true.

		// Keep track of next ball before they 
		// drop, so we can keep score.
		if (ballsInPlay.Count > 0)
		{
			zeroBall = ballsInPlay[0];
		}
		int count = 0;
		firstHit = true;
		for each (BilliardBall^ ball in balls)
		{
			ball->PosX = ball->Left;
			ball->PosY = ball->Top;
			//ball->Moving = true;
		}

		cueball->PosX = cueball->Left;
		cueball->PosY = cueball->Top;
		ballsMoving = true;

		while (ballsMoving)
		{
			ballsMoving = false;
			for each (BilliardBall^ striker in balls)
			{
				if (striker->Moving && striker->Visible && striker->Distance > .21)
				{
					ballsMoving = true;
					setDestinationPoint(striker);
					for each (BilliardBall^ struck in balls)
					{
						if (struck != striker && struck->Visible)
						{
							checkBallCollision(striker, struck);
						}
					}
				}
				for each (BilliardBall^ ball in balls)
				{
					for each (BilliardBall^ ball2 in balls)
					{

						if (ball != ball2 && distanceBetweenBalls(ball, ball2))
						{
							ball2->Distance += .1;
						}
					}
				}
			}

			this->Refresh();
			//Thread::Sleep(10);			
		}
		for each (BilliardBall^ ball in balls)
		{
			// Set each ball->Moving property to
			// false.
			ball->Moving = false;
			if (ball->Visible && !boundaryCheck(ball->Left, ball->Top))
			{
				moveBallIntoBoundaries(ball);
			}
		}
		this->Refresh();
		bool spotCue = false;
		// Remove backwards in loop, always the
		// last ball in the list, because index
		// values change each time ball is removed,
		// and it is easier to decrement 'i' when
		// element is removed, than to try to 
		// calculate what the last index value
		// should be in the loop, if we were
		// looping forward.		
		for (int i = balls.Count - 1; i >= 0; i--)
		{
			if (!balls[i]->Visible)
			{
				if (balls[i] != cueball)
				{
					balls.RemoveAt(i);
					i--;
				}
				else
				{
					spotCue = true;
				}
			}
		}
		if (!gameOver)
		{
			keepScore(spotCue);
		}
		if (spotCue || !cueball->Visible)
		{
			spotCueBall();
		}
		else
		{
			spotCueBallMenuItem->Enabled = false;
		}
	}

	private: void endGame(players winningPlayer)
	{
		gameOver = true;
		play_Sound(sounds::StartupMusic);
		if (winningPlayer == players::player1)
		{
			titleLabel->Text = "Player 1 Wins!";
		}
		else
		{
			titleLabel->Text = "Player 2 Wins!";
		}
	}

	private: void changeScoreLabel(bool scored)
	{
		if (scored)
		{
			if (player1ScoresInARow > 1)
			{
				play_Sound(sounds::StartupMusic);
				titleLabel->Text = "Player 1 is running the table!";
			}
			else if (player2ScoresInARow > 1)
			{
				play_Sound(sounds::StartupMusic);
				titleLabel->Text = "Player 2 is running the table!";
			}
		}
		else
		{
			titleLabel->Text = "Nine Ball";
			player2ScoresInARow = 0;
			player2ScoresInARow = 0;
		}

	}

	private: void keepScore(bool scratched)
	{
		// Switch players if not a good hit, or if
		// the next ball did not go in.
		bool switchPlayer = false;
		// Check if player won the game.
		if (ballsInPlay.Count == 0 || !ballsInPlay.Contains(Convert::ToByte(ball9->Tag)))
		{
			players player;
			// See who won.
			if (labelPlayer1->ForeColor == Color::White)
			{
				if (goodHit)
				{
					player = players::player1;
				}
				else
				{
					player = players::player2;
				}
			}
			else
			{
				if (goodHit)
				{
					player = players::player2;
				}
				else
				{
					player = players::player1;
				}
			}
			endGame(player);
			return;
		}
		else if (goodHit && !scratched)
		{

			if (playerScored)
			{

				if (labelPlayer1->ForeColor == Color::White)
				{
					// Player 1 was the one that scored.
					player1ScoresInARow++;
					player2ScoresInARow = 0;
				}
				else
				{
					player2ScoresInARow++;
					player1ScoresInARow = 0;
				}
				changeScoreLabel(true);
			}
			else
			{
				// This means that the correct ball was hit,
				// but that ball was not sunk.
				// It is the other player's turn now.
				switchPlayer = true;
				changeScoreLabel(false);
			}
		}
		else
		{
			switchPlayer = true;
			spotCueBallMenuItem->Enabled = scratched;
		}
		if (switchPlayer)
		{
			if (labelPlayer1->ForeColor == Color::White)
			{
				labelPlayer1->ForeColor = Color::DimGray;
				labelPlayer2->ForeColor = Color::White;
			}
			else
			{
				labelPlayer2->ForeColor = Color::DimGray;
				labelPlayer1->ForeColor = Color::White;
			}
		}
	}

	private: void spotCueBall()
	{
		int spotX = (int)walls::leftWall + 200;
		int spotY = (int)walls::topWall + 100;
		Point pt(spotX, spotY);
		bool ok = true;
		do
		{
			for each (BilliardBall^ ball in balls)
			{
				ok = true;
				if (ball != cueball)
				{
					if (GetDistance(pt, ball->Location) < 100)
					{
						ok = false;
						if (pt.Y < (int)walls::bottomWall - 50)
						{
							pt.Y += 20;
						}
						else if (pt.X > (int)walls::leftWall + 50)
						{
							pt.X -= 20;
						}
						break;
					}
				}
			}
		} while (!ok);
		// Wait a while before spotting.
		Thread::Sleep(500);
		// Spot the q ball.
		cueball->Location = pt;
		cueball->Visible = true;
		//this->Refresh();

	}

			 // Checks the border walls and returns
			 // the wall that the ball would hit
			 // first at the next iteration of the
			 // move loop. Point is destination point.
			 // If no walls will be hit it returns "Walls::AllOK".		
	private: walls wallCheck(BilliardBall^ ball)
	{
		walls wall = walls::allOK;
		switch (Dir)
		{
		case Direction::upper_right:
			if (ball->PosX >= (int)walls::rightWall)
			{
				if (ball->PosY <= (int)walls::topWall)
				{
					// Determine which wall would have
					// been hit first.
					if (ball->PosX - (int)walls::rightWall > (int)walls::topWall - ball->PosY)
					{
						wall = walls::rightWall;
					}
					else
					{
						wall = walls::topWall;
					}
				}
				else
				{
					wall = walls::rightWall;
				}
			}
			else if (ball->PosY <= (int)walls::topWall)
			{
				wall = walls::topWall;
			}
			break;
		case Direction::upper_left:
			if (ball->PosX <= (int)walls::leftWall)
			{
				if (ball->PosY <= (int)walls::topWall)
				{
					// Determine which wall would have
					// been hit first.
					if ((int)walls::leftWall - ball->PosX > (int)walls::topWall - ball->PosY)
					{
						wall = walls::leftWall;
					}
					else
					{
						wall = walls::topWall;
					}
				}
				else
				{
					wall = walls::leftWall;
				}
			}
			else if (ball->PosY <= (int)walls::topWall)
			{
				wall = walls::topWall;
			}
			break;
		case Direction::lower_right:
			if (ball->PosX >= (int)walls::rightWall)
			{
				if (ball->PosY >= (int)walls::bottomWall)
				{
					// Determine which wall would have
					// been hit first.
					if (ball->PosX - (int)walls::rightWall > ball->PosY - (int)walls::bottomWall)
					{
						wall = walls::rightWall;
					}
					else
					{
						wall = walls::bottomWall;
					}
				}
				else
				{
					wall = walls::rightWall;
				}
			}
			else if (ball->PosY >= (int)walls::bottomWall)
			{
				wall = walls::bottomWall;
			}
			break;
		case Direction::lower_left:
			if (ball->PosX <= (int)walls::leftWall)
			{
				if (ball->PosY >= (int)walls::bottomWall)
				{
					// Determine which wall would have
					// been hit first.
					if ((int)walls::leftWall - ball->PosX > ball->PosY - (int)walls::bottomWall)
					{
						wall = walls::leftWall;
					}
					else
					{
						wall = walls::bottomWall;
					}
				}
				else
				{
					wall = walls::leftWall;
				}
			}
			else if (ball->PosY >= (int)walls::bottomWall)
			{
				wall = walls::bottomWall;
			}
			break;
		case Direction::right:
			if (ball->PosX >= (int)walls::rightWall)
			{
				wall = walls::rightWall;
			}
			break;
		case Direction::left:
			if (ball->PosX <= (int)walls::leftWall)
			{
				wall = walls::leftWall;
			}
			break;
		case Direction::up:
			if (ball->PosY <= (int)walls::topWall)
			{
				wall = walls::topWall;
			}
			break;
		case Direction::down:
			if (ball->PosY >= (int)walls::bottomWall)
			{
				wall = walls::bottomWall;
			}
			break;
		default:
			throw gcnew Exception(
				"Exception at: MainForm::wallCheck(). No value for Direction parameter (direct) was set.");
			break;
		}
		//
		return wall;
	}

	private: void play_Sound(LPCTSTR sound)
	{
		currentSound = sound;
		soundThread = gcnew Thread(gcnew ThreadStart(playSoundThread));
		soundThread->Priority = System::Threading::ThreadPriority::AboveNormal;
		soundThread->IsBackground = true;
		soundThread->Start();
	}


	private: static void playSoundThread()
	{

		if (currentSound == sounds::ballInPocket)
		{
			PlaySound(currentSound, NULL, SND_FILENAME | SND_ASYNC);// | SND_NOSTOP | SND_NODEFAULT);
		}
		else
		{
			PlaySound(currentSound, NULL, SND_FILENAME | SND_ASYNC);// | SND_NODEFAULT);
		}

	}

	private: void centerPoolTable()
	{
		int w = this->Left + this->Width / 2;
		int h = this->Top + this->Height / 2;
		int inW = panel1->Width / 2;
		int inH = panel1->Height / 2;
		panel1->Left = w - inW;
		panel1->Top = h - inH;
		//
		labelPlayer1->Location = Point(panel1->Left + 50, panel1->Top - 50);
		labelPlayer2->Location = Point(panel1->Right - 150, panel1->Top - 50);

	}

	private: System::Void poolTable_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (drawline)
		{
			poolTable->Refresh();
			aimPt = poolTable->PointToClient(poolTable->Cursor->Position);
			if (cueball->Top <= (int)walls::topWall && aimPt.Y <=
				(int)walls::topWall + BALL_HEIGHT)
			{
				aimPt.Y = (int)walls::topWall + BALL_RADIUS + 1;
			}
			else if (cueball->Top >= (int)walls::bottomWall && aimPt.Y >=
				(int)walls::bottomWall + 19)
			{
				aimPt.Y = (int)walls::bottomWall + BALL_RADIUS + 1;
			}
			else if (cueball->Left <= (int)walls::leftWall && aimPt.X <=
				(int)walls::leftWall + 19)
			{
				aimPt.X = (int)walls::leftWall + BALL_RADIUS + 1;
			}
			else if (cueball->Left >= (int)walls::rightWall && aimPt.X >=
				(int)walls::rightWall + 19)
			{
				aimPt.X = (int)walls::rightWall + BALL_RADIUS + 1;
			}
			lineWasStraight = (qctr.X == aimPt.X || qctr.Y == aimPt.Y);
			gr->DrawLine(Pens::White, qctr, aimPt);
		}
		else if (moveCueBall)
		{
			cueball->Location = Point(
				poolTable->PointToClient(poolTable->Cursor->Position).X - 17,
				poolTable->PointToClient(poolTable->Cursor->Position).Y - 17);
		}

	}

	private: System::Void cueball_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (drawline)
		{
			this->Refresh();
			aimPt = poolTable->PointToClient(poolTable->Cursor->Position);
			gr->DrawLine(Pens::White, qctr, aimPt);
		}
		else if (moveCueBall)
		{
			cueball->Location = Point(
				poolTable->PointToClient(poolTable->Cursor->Position).X - 17,
				poolTable->PointToClient(poolTable->Cursor->Position).Y - 17);
			this->Refresh();
		}
	}

	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Escape)
		{
			if (drawline)
			{
				drawline = false;
				panel1->Cursor = Cursors::Default;
				this->Refresh();
			}
			else
			{
				this->ContextMenuStrip->Show(this, this->MousePosition);
			}
		}
	}

	public: property System::Windows::Forms::CreateParams^ CreateParams
	{
	public: System::Windows::Forms::CreateParams^ get() override
	{
		System::Windows::Forms::CreateParams^ overrideParams = Form::CreateParams;
		//
		// Make your changes to overrideParams members here.
		if (addCompositeStyle)
		{
			overrideParams->ExStyle |= 0x02000000; // Turn on WS_EX_COMPOSITED
		}
		return overrideParams;
	}
	}

	private: void performMainMenuSelection(mainMenuItem item)
	{
		switch (item)
		{
		case mainMenuItem::play:
			RackBalls();
			break;
		case mainMenuItem::exit:
			Application::Exit();
			break;

		}
	}

	private: void showMainMenu()
	{
		MenuForm^ menu = gcnew MenuForm();
		menu->Location = Point(this->Left + panel1->Left + poolTable->Left + 5,
			this->Top + panel1->Top + poolTable->Top + 75);
		menu->ShowDialog(this);
		performMainMenuSelection(menu->GetSelectedItem());
	}

	private: System::Void startupTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
		startupTimer->Stop();
		this->Refresh();
		Thread::Sleep(50);
		showMainMenu();
		play_Sound(nullptr);
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void moveTheCueBallSpotToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		panel1->Cursor = Cursors::Hand;
		moveCueBall = true;
	}
	private: System::Void rightClickMenu_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		if (moveCueBall)
		{
			moveCueBall = false;
			panel1->Cursor = Cursors::Default;
			e->Cancel = true;
		}
		else if (drawline)
		{
			drawline = false;
			this->Refresh();
		}
	}

	private: System::Void mainMenuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		showMainMenu();
	}
	private: System::Void rackBallsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		RackBalls();
	}
	private: System::Void testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		bool b = distanceBetweenBalls(ball1, ball2);
		MessageBox::Show("balls touching = " + b);
	}
	};
}


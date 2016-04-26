#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace NineBall {

	/// <summary>
	/// Summary for BilliardBall
	/// </summary>
	public ref class BilliardBall : public System::Windows::Forms::UserControl
	{
	public:
		BilliardBall()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			auto path = gcnew System::Drawing::Drawing2D::GraphicsPath();
			path->AddEllipse(0, 0, this->Width, this->Height);
			this->Region = gcnew System::Drawing::Region(path);
			delete path;
			this->ForeColor = Color::White;
			this->ResumeLayout(false);
		}

		List<Point> Moves;
		
				
		property Image^ BallImage
		{
			Image^ get();
			void set(Image^);
		}

		property bool Moving
		{
			bool get();
			void set(bool);
		}

		property bool AddY
		{
			bool get();
			void set(bool);
		}

		property double MoveVal
		{
			double get();
			void set(double);
		}

		property double SpeedX
		{
			double get();
			void set(double);
		}

		property double SpeedY
		{
			double get();
			void set(double);
		}

		
		property double PosY
		{
			double get();
			void set(double);
		}
		
		property double PosX
		{
			double get();
			void set(double);
		}

		property double FirstPos_X
		{
			double get();
			void set(double);
		}

		property double FirstPos_Y
		{
			double get();
			void set(double);
		}
		
		property double Distance
		{
			double get();
			void set(double);
		}

		property double Slope
		{
			double get();
			void set(double);
		}

		property float Angle
		{
			float get();
			void set(float);
		}

		property double Y_intercept
		{
			double get();
			void set(double);
		}

		property Point Destination
		{
			Point get();
			void set(Point);
		}

		property Point StartPos
		{
			Point get();
			void set(Point);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BilliardBall()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Image^ n_image;
		bool n_moving = false;
		bool n_addY = false;
		double n_posX;
		double n_posY;
		double n_firstPosX;
		double n_test;
		double n_firstPosY;
		double n_distance;
		double n_moveVal;
		double n_speedY;
		double n_speedX;
		double n_slope;
		float n_angle;
		double n_y_intercept;
		Point n_dest;
		Point n_startPos;
		//double incrementVal;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// BilliardBall
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->Name = L"BilliardBall";
			this->Size = System::Drawing::Size(34, 34);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BilliardBall::BilliardBall_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void BilliardBall_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		e->Graphics->CompositingMode = CompositingMode::SourceCopy;
		e->Graphics->CompositingQuality = CompositingQuality::AssumeLinear;

		if (n_moving)  // global flag to render fastest, but reduce quality.
		{
			e->Graphics->InterpolationMode = InterpolationMode::Default;
			e->Graphics->SmoothingMode = SmoothingMode::HighSpeed;			
			e->Graphics->PixelOffsetMode = PixelOffsetMode::HighSpeed;			
		}
		else
		{
			// set high quality for scaling and rendering.
			e->Graphics->InterpolationMode = InterpolationMode::HighQualityBilinear;
			e->Graphics->SmoothingMode = SmoothingMode::HighSpeed;
			e->Graphics->PixelOffsetMode = PixelOffsetMode::HighQuality;
		}
		//if (!n_moving)
		{
			//return;
			//
			e->Graphics->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::GammaCorrected;
			e->Graphics->CompositingMode = System::Drawing::Drawing2D::CompositingMode::SourceOver;
			//e->Graphics->Clear(Color::Gray);
			e->Graphics->DrawImage(n_image, -1, -1, 36, 36);
		}
	}


	public: property System::Windows::Forms::CreateParams^ CreateParams
	{
	public: System::Windows::Forms::CreateParams^ get() override
	{
		System::Windows::Forms::CreateParams^ overrideParams = System::Windows::Forms::UserControl::CreateParams;
		//
		// Make your changes to overrideParams members here.
		overrideParams->ExStyle |= 0x02000000; // Turn on WS_EX_COMPOSITED
		return overrideParams;
	}
	}

	};
}

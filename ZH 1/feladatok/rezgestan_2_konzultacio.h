#pragma once

namespace WindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(335, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(396, 424);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(71, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(71, 57);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(71, 102);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(71, 152);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 26);
			this->textBox4->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 153);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(71, 193);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 26);
			this->textBox5->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 194);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"label5";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(71, 225);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 26);
			this->textBox6->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 226);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"label6";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 399);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 52);
			this->button1->TabIndex = 13;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 250;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 463);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Konstansok
	double m, b, k, dt, xk, xk1;
	bool fut = false;

	// Rajzoló függvény
	Pen^ toll;
	Graphics^ gr;
	Bitmap^ bm;

	void rajzol() {
		// Törölni kell az eddigi rajzot
		gr->Clear(SystemColors::Control);

		gr->DrawLine(toll, 10, 0, 100, 0);
		
		const double x0 = 100;
		const double lepes = 10;

		gr->DrawRectangle(toll, 40, x0 + lepes * xk, 20, 20);

		double ymax = x0 + lepes * xk;

		for (int i = 0; i < 3; i++) {
			gr->DrawLine(toll, 45, i * ymax / 3, 25, (i + 0.5) * ymax / 3);
			gr->DrawLine(toll, 25, (i + 0.5) * ymax / 3, 45, (i + 1) * ymax / 3);
		}

		gr->DrawRectangle(toll, 50, ymax / 2 - 5, 10, 10);
		gr->DrawLine(toll, 55, 0, 55, ymax / 2 - 5);
		gr->DrawLine(toll, 55, ymax / 2 + 5, 55, ymax);
		gr->DrawLine(toll, 50, ymax / 2 - 5, 50, ymax / 2 - 10);
		gr->DrawLine(toll, 60, ymax / 2 - 5, 60, ymax / 2 - 10);

		pictureBox1->Image = bm;
	}

	// Gomb függvény (start, stop, beolvasás)
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (fut) {
			timer1->Stop();
			fut = false;
			button1->Text = "Start";
		}
		else {
			fut = true;
			m = Convert::ToDouble(textBox1->Text);
			b = Convert::ToDouble(textBox2->Text);
			k = Convert::ToDouble(textBox3->Text);
			dt = Convert::ToDouble(textBox4->Text);
			xk = Convert::ToDouble(textBox5->Text);
			xk1 = Convert::ToDouble(textBox6->Text);
			
			button1->Text = "Stop";
			timer1->Start();
		}
	}

	// Start függvény
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = "m = ";
		label2->Text = "b = ";
		label3->Text = "k = ";
		label4->Text = "dt = ";
		label5->Text = "x[0] = ";
		label6->Text = "x[-1] = ";

		this->Text = "Rezgestan";
		button1->Text = "Start";

		toll = gcnew Pen(Color::Black);
		bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(bm);
	}

	// Timer, idõlépések
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		double xk_regi = xk;
		// xk kiszámolása (új)
		// x[k-1] = xk
		const double g = 9.81;

		xk = 2 * xk - xk1 + dt * b / m * (-xk + xk1) - dt * dt * k / m * xk1 + dt * dt * g;
		xk1 = xk_regi;

		rajzol();
	}
};
}

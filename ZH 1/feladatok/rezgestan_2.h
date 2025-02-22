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
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;


	private: System::Windows::Forms::PictureBox^ pictureBox1;



	protected:
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 16;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 292);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 62);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(117, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(117, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(117, 86);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(117, 119);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 26);
			this->textBox4->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(117, 152);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 26);
			this->textBox5->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 122);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 155);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 200);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 20);
			this->label6->TabIndex = 12;
			this->label6->Text = L"label6";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(117, 197);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 26);
			this->textBox6->TabIndex = 11;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(248, 32);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(477, 322);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 381);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	Bitmap^ rajz;
	Graphics^ gr;
	Pen^ toll;
	SolidBrush^ ecset;

	const double g = -9.81;
	cli::array<double>^ z;
	double dt, m, b, k;

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Rezgestan";
		button1->Text = "Start";
		label1->Text = "m = [kg]";
		label2->Text = "b = [N/ms]";
		label3->Text = "k = [N/m]";
		label4->Text = "dt = [s]";
		label5->Text = "x[k] = [m]";
		label6->Text = "x[k-1] = [m]";

		ecset = gcnew SolidBrush(Color::Black);
		toll = gcnew Pen(Color::Black);
		rajz = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(rajz);
		z = gcnew cli::array<double>{ 0,0 };
	}

	void rajzol() {
		// Képernyőtörlés
		gr->Clear(SystemColors::Control);
		
		// Felfüggesztés
		gr->DrawLine(toll, 60, 10, 180, 10);
		for (int i = 0; i < 8; i++)
			gr->DrawLine(toll, i * 14 + 65, 10, i * 14 + 80, 0);

		// Tömeg
		const int nullpont = 100; // z(0) koordináta
		const int tomegmeret = 40; // px

		gr->DrawRectangle(toll, 100, nullpont - z[0] - tomegmeret / 2, tomegmeret, tomegmeret);

		// Csillapítás
		const int csillapmeret = 20; // px
		gr->DrawLine(toll, 130, 10, 130, (nullpont - z[0] - tomegmeret / 2) / 2 - csillapmeret / 2);
		gr->DrawLine(toll, 130, nullpont - z[0] - tomegmeret / 2, 130, (nullpont - z[0] - tomegmeret / 2) / 2 + csillapmeret / 2);
		gr->DrawRectangle(toll, 130 - csillapmeret / 2, (nullpont - z[0] - tomegmeret / 2) / 2 - csillapmeret / 2, csillapmeret, csillapmeret);
		gr->DrawLine(toll, 130 - csillapmeret / 2, (nullpont - z[0] - tomegmeret / 2) / 2 - csillapmeret / 2, 130 - csillapmeret / 2, (nullpont - z[0] - tomegmeret / 2) / 2 - csillapmeret / 2 - 5);
		gr->DrawLine(toll, 130 + csillapmeret / 2, (nullpont - z[0] - tomegmeret / 2) / 2 - csillapmeret / 2, 130 + csillapmeret / 2, (nullpont - z[0] - tomegmeret / 2) / 2 - csillapmeret / 2 - 5);

		// Rugó
		gr->DrawLine(toll, 110, 10, 110, 20);
		gr->DrawLine(toll, 110, (nullpont - z[0] - tomegmeret / 2), 110, nullpont - z[0] - tomegmeret / 2 - 20);
		
		for (int i = 0; i < 5; i++) {
			const double delta = (nullpont - z[0] - tomegmeret / 2 - 40) / 5;
			const double top = 20;
			gr->DrawLine(toll, 110.0f, top + delta * i, 115.0, top + delta * (i + 0.5));
			gr->DrawLine(toll, 115.0f, top + delta * (i + 0.5), 110.0, top + delta * (i + 1));
		}

		pictureBox1->Image = rajz;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// z[0] = z[k-1], z[1] = z[k-2]
		double regiz = z[0];

		z[0] = 2 * z[0] - z[1] + dt * b / m * (-z[0] + z[1]) - dt * dt * k / m * z[1] + dt * dt * g;
		z[1] = regiz;

		rajzol();
	}
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		rajzol();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (timer1->Enabled) {
			timer1->Stop();
			button1->Text = "Start";
		}
		else {
			m = Convert::ToDouble(textBox1->Text);
			b = Convert::ToDouble(textBox2->Text);
			k = Convert::ToDouble(textBox3->Text);
			dt = Convert::ToDouble(textBox4->Text);
			z[0] = Convert::ToDouble(textBox5->Text);
			z[1] = Convert::ToDouble(textBox6->Text);

			timer1->Start();
			button1->Text = "Stop";
		}
	}
};
}

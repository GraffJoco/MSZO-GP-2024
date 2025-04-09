#pragma once

namespace WindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; // List<T>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // StreamReader, StreamWriter

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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	private:
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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 279);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(69, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(231, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 335);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 359);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		ref struct pont {
			double x, y;

			pont(double x, double y) : x(x), y(y) {}
		};

		List<pont^>^ pontok;
		String^ xnev;
		String^ ynev;
		Pen^ toll;
		Bitmap^ bm;
		Graphics^ gr;

		double ypont;
		bool van_pont = false;

		// Form load fv, program elejére
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Text = "Interpolalas";

		label1->Text = "x = ";
		label2->Text = "";

		button1->Text = "Fajl megnyitasa";
		openFileDialog1->Filter = "Tabulatoros CSV|*.csv";

		toll = gcnew Pen(Color::Black);
		bm = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(bm);
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
			MessageBox::Show("Nem sikerult a fajlt megnyitni!");
			return;
		}

		String^ utvonal = openFileDialog1->FileName;
		StreamReader^ fajl = gcnew StreamReader(utvonal);
		String^ sor;
		cli::array<String^>^ sorelemek;

		sor = fajl->ReadLine();
		sorelemek = sor->Split('\t');
		xnev = sorelemek[0];
		ynev = sorelemek[1];

		pontok = gcnew List<pont^>();
		
		while (!fajl->EndOfStream) {
			sor = fajl->ReadLine();
			sorelemek = sor->Split('\t');

			double x = Convert::ToDouble(sorelemek[0]);
			double y = Convert::ToDouble(sorelemek[1]);

			pontok->Add(gcnew pont(x, y));
		}

		rajzol();

		MessageBox::Show("Fajl olvasas sikeres");
	}

	void rajzol() {
		gr->Clear(SystemColors::Control);
		double xmin = pontok[0]->x;
		double xmax = pontok[pontok->Count - 1]->x;

		double ymin = pontok[0]->y, ymax = pontok[0]->y;
		for (int i = 0; i < pontok->Count; i++) {
			if (pontok[i]->y < ymin) ymin = pontok[i]->y;
			if (pontok[i]->y > ymax) ymax = pontok[i]->y;
		}

		double xlepes =  pictureBox1->Width / (xmax - xmin);
		double ylepes =  pictureBox1->Height / (ymax - ymin);

		double x0 = Math::Abs(xmin) * xlepes;
		double y0 = pictureBox1->Height - Math::Abs(ymin) * ylepes;

		gr->DrawLine(toll, x0, 0, x0, pictureBox1->Height);
		gr->DrawLine(toll, 0, y0, pictureBox1->Width, y0);

		for (int i = 1; i < pontok->Count; i++) {
			gr->DrawLine(toll, (float)(pontok[i - 1]->x * xlepes), pictureBox1->Height - pontok[i - 1]->y * ylepes,
				pontok[i]->x * xlepes, pictureBox1->Height - pontok[i]->y * ylepes);
		}

		if (van_pont) {
			toll->Color = Color::Red;
			gr->DrawLine(toll, 0, pictureBox1->Height - ypont * ylepes, 
				pictureBox1->Width, pictureBox1->Height - ypont * ylepes);
			toll->Color = Color::Black;
		}

		pictureBox1->Image = bm;
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
			double xkoord = Convert::ToDouble(textBox1->Text);
			double ykoord = 0;

			if (xkoord < pontok[0]->x || xkoord > pontok[pontok->Count - 1]->x)
				return;

			for (int i = 0; i < pontok->Count; i++) {
				if (pontok[i]->x > xkoord) {
					ykoord = (pontok[i]->y - pontok[i - 1]->y) * (xkoord - pontok[i - 1]->x)
						/ (pontok[i]->x - pontok[i - 1]->x) + pontok[i-1]->y;
					
					ypont = ykoord;
					van_pont = true;
					break;
				}
			}

			if (van_pont) {
				label2->Text = Convert::ToString(ykoord);
				rajzol();
			}
		}
		catch (...) {

		}
	}
};
}

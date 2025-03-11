#pragma once

namespace WindowsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label2;




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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(165, 32);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(477, 322);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 29);
			this->button1->TabIndex = 16;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 142);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 17;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 18;
			this->label1->Text = L"label1";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"CSV fájlok|*.csv";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 334);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"label2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 381);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
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
		String^ xtengely, ^ytengely;
		double xmax, ymax, xmin, ymin;
		double kijeloltX = double::NaN;
		Pen^ toll;
		Bitmap^ rajz;
		Graphics^ gr;
	
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		button1->Text = "Fájl megnyitása";
		label2->Text = "";
		label1->Text = "";
		textBox1->Enabled = false;
		openFileDialog1->Title = "Fájl megnyitása";
		toll = gcnew Pen(Color::Black);

		rajz = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(rajz);

		pontok = gcnew List<pont^>();

		// Azonnali újraméretezés
		
		this->Form1_Resize(sender, e);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Hibás nyitás esetén törlünk mindent
		if (openFileDialog1->ShowDialog() != Windows::Forms::DialogResult::OK) {
			pictureBox1->Image = nullptr;
			label2->Text = "";
			label1->Text = "";
			textBox1->Enabled = false;
			return;
		}

		// using namespace System::IO kell, vagy ez IO::StreamReader lesz
		StreamReader^ fajl = gcnew StreamReader(openFileDialog1->FileName);

		String^ sor = fajl->ReadLine();
		cli::array<String^>^ sorelemek = sor->Split('\t');

		xtengely = sorelemek[0];
		ytengely = sorelemek[1];

		while (!fajl->EndOfStream) {
			sor = fajl->ReadLine();

			if (sor->Length == 0) continue;

			sorelemek = sor->Split('\t');

			pontok->Add(gcnew pont(Convert::ToDouble(sorelemek[0]), Convert::ToDouble(sorelemek[1])));
		}

		xmax = pontok[0]->x;
		xmin = pontok[0]->x;
		ymax = pontok[0]->y;
		ymin = pontok[0]->y;

		for (size_t i = 1; i < pontok->Count; i++) {
			if (pontok[i]->x > xmax) xmax = pontok[i]->x;
			if (pontok[i]->x < xmin) xmin = pontok[i]->x;
			if (pontok[i]->y > ymax) ymax = pontok[i]->y;
			if (pontok[i]->y < ymin) ymin = pontok[i]->y;
		}

		textBox1->Enabled = true;
		label1->Text = xtengely + "=";
		rajzol();
	}

	PointF lekepez(pont^ p) {
		// 0-1 skálára redukáljuk a koordinátákat
		const float x = (p->x - xmin) / (xmax - xmin);
		// 1-ből kivonjuk, mert y normál esetben lefele megy
		const float y = 1 - (p->y - ymin) / (ymax - ymin);

		// Koordinátatrafóval visszaadjuk
		return PointF(x * pictureBox1->Width, y * pictureBox1->Height);
	}

	void rajzol() {
		gr->Clear(SystemColors::Control);
		
		// grafikon vonalai
		toll->Color = Color::DarkBlue;
		for (size_t i = 1; i < pontok->Count; i++) {
			gr->DrawLine(toll, lekepez(pontok[i-1]), lekepez(pontok[i]));
		}

		// tengelyek
		toll->Color = Color::Black;
		gr->DrawLine(toll, lekepez(gcnew pont(xmin, 0)), lekepez(gcnew pont(xmax, 0)));
		gr->DrawLine(toll, lekepez(gcnew pont(0, ymin)), lekepez(gcnew pont(0, ymax)));
		gr->DrawLine(toll, lekepez(gcnew pont(0, ymax)), PointF::Add(lekepez(gcnew pont(0, ymax)), SizeF(-4, 10)));
		gr->DrawLine(toll, lekepez(gcnew pont(0, ymax)), PointF::Add(lekepez(gcnew pont(0, ymax)), SizeF(4, 10)));
		gr->DrawLine(toll, lekepez(gcnew pont(xmax, 0)), PointF::Add(lekepez(gcnew pont(xmax, 0)), SizeF(-10, 4)));
		gr->DrawLine(toll, lekepez(gcnew pont(xmax, 0)), PointF::Add(lekepez(gcnew pont(xmax, 0)), SizeF(-10, -4)));

		for (double i = Math::Ceiling(ymin); i < ymax; i += 1.0) {
			PointF egyik = lekepez(gcnew pont(0, i));
			egyik.X += 10;
			PointF masik = egyik;
			masik.X -= 20;

			gr->DrawLine(toll, egyik, masik);
		}
		for (double i = Math::Ceiling(xmin); i < xmax; i += 1.0) {
			PointF egyik = lekepez(gcnew pont(i, 0));
			egyik.Y += 10;
			PointF masik = egyik;
			masik.Y -= 20;

			gr->DrawLine(toll, egyik, masik);
		}

		toll->Color = Color::DarkRed;
		if (!double::IsNaN(kijeloltX)) {
			gr->DrawLine(toll, lekepez(gcnew pont(kijeloltX, ymin)), lekepez(gcnew pont(kijeloltX, ymax)));
		}

		pictureBox1->Image = rajz;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// try-catch: ha errort dobna, akkor külön erre írt kód fut le helyette
		// (MOO tétel volt, tehát nem mondhatjátok, hogy ez nem volt anyag)
		try {
			label2->Text = "";
			kijeloltX = Convert::ToDouble(textBox1->Text);

			if (kijeloltX < xmin || kijeloltX > xmax) kijeloltX = double::NaN;

			rajzol();

			// Interpolálás
			if (kijeloltX != double::NaN) {
				for (size_t i = 0; i < pontok->Count - 1; i++) {
					if (kijeloltX > pontok[i]->x) {
						const double y = (kijeloltX - pontok[i]->x) / (pontok[i + 1]->x - pontok[i]->x)
							* (pontok[i + 1]->y - pontok[i]->y) + pontok[i]->y;

						label2->Text = String::Format("{0}({1}) = {2}", xtengely, kijeloltX, y);
					}
				}
			}

		}
		catch (...) {
			kijeloltX = double::NaN;
		}
	}
	private: System::Void Form1_Resize(System::Object^ sender, System::EventArgs^ e) {
		button1->Left = 50;
		label1->Left = 50;
		label2->Left = 50;
		
		pictureBox1->Left = 150;
		pictureBox1->Top = 50;

		pictureBox1->Width = this->Width - 200;
		pictureBox1->Height = this->Height - 100;

		rajz = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(rajz);
		toll = gcnew Pen(Color::Black);

		if (pontok) rajzol();
	}
};
}

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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 100;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(145, 431);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 84);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 537);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	// Többdimenziós tömbnél típus után paraméterrel lehet megadni a dimenziókat
	cli::array<bool, 2>^ grid;
	bool fut = false;

	Bitmap^ rajz;
	Graphics^ gr;
	SolidBrush^ ecset;

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->button1->Text = "Start";
		rajz = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
		gr = Graphics::FromImage(rajz);
		ecset = gcnew SolidBrush(Color::Black);

		grid = gcnew cli::array<bool, 2>(20, 20);
		
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				grid[i, j] = false;
			}
		}
	}
	
	void Conway() {
		cli::array<int, 2>^ eloszomszedok = gcnew cli::array<int, 2>(20, 20);

		// Első körben megszámoljuk az élő szomszédokat
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				eloszomszedok[i, j] = 0;

				// ez a Min, Max dolog csak garantálja, hogy x, y a [0;20[ intervallumba marad
				// (nem címzünk ki)
				for (int x = Math::Max(i - 1, 0); x < Math::Min(20, i + 2); x++) {
					for (int y = Math::Max(j - 1, 0); y < Math::Min(20, j + 2); y++) {
						if ((x != i || y != j) && grid[x, y]) eloszomszedok[i, j]++;
					}
				}
			}
		}

		// Második körben frissítjük a cellákat az új értékekkel,
		// valamint rajzolunk
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if ((grid[i, j] && eloszomszedok[i, j] == 2) || eloszomszedok[i, j] == 3) {
					grid[i, j] = true;
					ecset->Color = Color::White;
				}
				else {
					grid[i, j] = false;
					ecset->Color = Color::Black;
				}
				gr->FillRectangle(ecset, i * 20, j * 20, 20, 20);
			}
		}

		pictureBox1->Image = rajz;
	}

	// Cellák frissítése kattintásnál
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Abszolút koordinátákból relatívat csinálunk
		Point relPos = pictureBox1->PointToClient(MousePosition);
		const int cellaX = relPos.X / 20;
		const int cellaY = relPos.Y / 20;
		
		// Cellát invertáljuk, újrarajzoljuk
		grid[cellaX, cellaY] = !grid[cellaX, cellaY];
		ecset->Color = grid[cellaX, cellaY] ? Color::White : Color::Black;
		gr->FillRectangle(ecset, cellaX * 20, cellaY * 20, 20, 20);
		pictureBox1->Image = rajz;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Conway();
	}
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Conway();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (fut) {
			timer1->Stop();
			button1->Text = "Start";
			fut = false;
		}
		else {
			fut = true;
			timer1->Start();
			button1->Text = "Stop";
		}
	}
};
}

#include <random>
#include <ctime>
#include <string>
#include <functional>

#pragma once

namespace TimetableGeneratorGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dgv;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	public: static array<String^>^ units = gcnew array<String^>(8);
		  static array<String^>^ weekday = gcnew array<String^>{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
		  static array<String^>^ times = gcnew array<String^>{ "8.00am to 11.00am, ", "11.00am to 2.00pm, ", "2.00pm to 5.00pm, " };
		  int sizes = units->Length;
		  int i = 0;
		  int n, j;
		  String^ day1;
		  String^ day2;
		  String^ day3;
		  String^ day4;
		  String^ day5;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dgv = (gcnew System::Windows::Forms::DataGridView());
			this->col1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(3, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(472, 22);
			this->textBox1->TabIndex = 0;
			// 
			// dgv
			// 
			this->dgv->AllowUserToAddRows = false;
			this->dgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->col1, this->Column1 });
			this->dgv->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv->Location = System::Drawing::Point(0, 0);
			this->dgv->Name = L"dgv";
			this->dgv->RowHeadersWidth = 51;
			this->dgv->RowTemplate->Height = 24;
			this->dgv->Size = System::Drawing::Size(727, 366);
			this->dgv->TabIndex = 1;
			this->dgv->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &Form1::dgv_RowsRemoved);
			// 
			// col1
			// 
			this->col1->HeaderText = L"Number";
			this->col1->MinimumWidth = 6;
			this->col1->Name = L"col1";
			this->col1->ReadOnly = true;
			this->col1->Width = 125;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Unit";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter upto 8 units:";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(3, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 36);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(510, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 33);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Generate";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(610, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 33);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Randomize";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->dgv);
			this->splitContainer1->Size = System::Drawing::Size(727, 466);
			this->splitContainer1->SplitterDistance = 96;
			this->splitContainer1->TabIndex = 6;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->button3);
			this->splitContainer2->Panel2->Controls->Add(this->button4);
			this->splitContainer2->Panel2->Controls->Add(this->button2);
			this->splitContainer2->Size = System::Drawing::Size(727, 518);
			this->splitContainer2->SplitterDistance = 466;
			this->splitContainer2->TabIndex = 6;
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(411, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(93, 33);
			this->button4->TabIndex = 4;
			this->button4->Text = L"New Set";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 518);
			this->Controls->Add(this->splitContainer2);
			this->Name = L"Form1";
			this->Text = L"Timetable Generator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv))->EndInit();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		units[i] = textBox1->Text;
		dgv->Rows->Add(i + 1, textBox1->Text);
		i++;
		textBox1->Text = "";
		textBox1->Focus();

		if (i == sizes)
		{
			button1->Enabled = false;
			textBox1->Enabled = false;
			i = 0;
			//Array::Clear(units, 0, units->Length);
			button2->Visible = true;
		}
		else {
			button2->Visible = false;
		}
	}
	private: System::Void dgv_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
		if (dgv->RowCount < units->Length)
		{
			button1->Enabled = true;
			textBox1->Enabled = true;
			button2->Visible = false;
			i = dgv->RowCount;
		}
	}
	public: static void Shuffle(array<String^>^ items)
	{
		Random^ rand = gcnew Random();

		// For each spot in the array, pick
		// a random item to swap into that spot.
		for (int i = 0; i < items->Length - 1; i++)
		{
			int j = rand->Next(i, items->Length);
			auto temp = items[i];
			items[i] = items[j];
			items[j] = temp;
		}
	}

	private: void generate() {
		srand((unsigned int)time(0));
		for each (DataGridViewRow ^ var in dgv->Rows)
		{
			units[var->Index] = var->Cells[1]->Value->ToString()->Trim();
		}
		Shuffle(units);
		//Shuffle(times);
		//std::random_shuffle(units[0], units[units->Length-1]);
		//std::random_shuffle(times[0], times[times->Length-1]);
		day1 = times[0] + units[0] + ", " + times[1] + units[1];
		day2 = times[1] + units[2] + ", " + times[2] + units[3];
		day3 = times[0] + units[4] + ", " + times[2] + units[5];
		day4 = times[1] + units[6];
		day5 = times[2] + units[7];
		Shuffle(weekday);
		//std::random_shuffle(weekday[0], weekday[units->Length-1]);
		String^ a = weekday[0] + ", " + day1;
		String^ b = weekday[1] + ", " + day2;
		String^ c = weekday[2] + ", " + day3;
		String^ d = weekday[3] + ", " + day4;
		String^ e = weekday[4] + ", " + day5;
		//array<String^>^ wkd = gcnew array<String^>{ a, b, c, d, e };
		StreamWriter^ sw;
		try {
			sw = gcnew StreamWriter("timetable.csv");
			//TODO: sw = File::AppendText("timetable.csv");
		}
		catch (IOException^ ex)
		{
			MessageBox::Show(this, "Cannot proceed as required because required file is in use by another process", this->Text, MessageBoxButtons::OK, MessageBoxIcon::Error);
			Application::Exit();
		}
		// Done: Create timetable.csv and write to it, display on dgv then display msgbox asking if user is satisfied with shuffle. If yes, append to timetable.

		/*
		int k = 0;

		while (k < wkd->Length)
		{
			if (wkd[k]->Contains(weekday[k]))
			{
				dgv->Rows->Add(k + 1, wkd[k]);
				sw->WriteLine(wkd[k]);
				k++;
			}
		}
		sw->Close();
		*/

		sw->WriteLine("Units");

		//Monday
		if (a->StartsWith("Monday"))
		{
			//dgv->Rows->Add(a);
			sw->WriteLine(a);
		}
		else if (b->StartsWith("Monday"))
		{
			sw->WriteLine(b);
		}
		else if (c->StartsWith("Monday"))
		{
			sw->WriteLine(c);
		}
		else if (d->StartsWith("Monday"))
		{
			sw->WriteLine(d);
		}
		else if (e->StartsWith("Monday"))
		{
			sw->WriteLine(e);
		}

		//Tuesday
		if (a->StartsWith("Tuesday"))
		{
			sw->WriteLine(a);
		}
		else if (b->StartsWith("Tuesday"))
		{
			sw->WriteLine(b);
		}
		else if (c->StartsWith("Tuesday"))
		{
			sw->WriteLine(c);
		}
		else if (d->StartsWith("Tuesday"))
		{
			sw->WriteLine(d);
		}
		else if (e->StartsWith("Tuesday"))
		{
			sw->WriteLine(e);
		}

		//Wednesday
		if (a->StartsWith("Wednesday"))
		{
			sw->WriteLine(a);
		}
		else if (b->StartsWith("Wednesday"))
		{
			sw->WriteLine(b);
		}
		else if (c->StartsWith("Wednesday"))
		{
			sw->WriteLine(c);
		}
		else if (d->StartsWith("Wednesday"))
		{
			sw->WriteLine(d);
		}
		else if (e->StartsWith("Wednesday"))
		{
			sw->WriteLine(e);
		}

		//Thursday
		if (a->StartsWith("Thursday"))
		{
			sw->WriteLine(a);
		}
		else if (b->StartsWith("Thursday"))
		{
			sw->WriteLine(b);
		}
		else if (c->StartsWith("Thursday"))
		{
			sw->WriteLine(c);
		}
		else if (d->StartsWith("Thursday"))
		{
			sw->WriteLine(d);
		}
		else if (e->StartsWith("Thursday"))
		{
			sw->WriteLine(e);
		}

		//Friday
		if (a->StartsWith("Friday"))
		{
			sw->WriteLine(a);
		}
		else if (b->StartsWith("Friday"))
		{
			sw->WriteLine(b);
		}
		else if (c->StartsWith("Friday"))
		{
			sw->WriteLine(c);
		}
		else if (d->StartsWith("Friday"))
		{
			sw->WriteLine(d);
		}
		else if (e->StartsWith("Friday"))
		{
			sw->WriteLine(e);
		}
		sw->WriteLine();
		sw->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(this, "Close any open .csv files.", this->Text, MessageBoxButtons::OK, MessageBoxIcon::Warning);
		generate();
		view();
		repeat();
	}

	private: void repeat() {
		auto msg = MessageBox::Show("Randomize again? Close any open .csv files.", this->Text, MessageBoxButtons::YesNo);
		this->Focus();
		if (msg == System::Windows::Forms::DialogResult::Yes) {
			Shuffle(units);

			//Shuffle(times);

			//std::random_shuffle(units[0], units[units->Length-1]);
			//std::random_shuffle(times[0], times[times->Length-1]);

			day1 = times[0] + units[0] + ", " + times[1] + units[1];
			day2 = times[1] + units[2] + ", " + times[2] + units[3];
			day3 = times[0] + units[4] + ", " + times[2] + units[5];
			day4 = times[1] + units[6];
			day5 = times[2] + units[7];
			Shuffle(weekday);

			//std::random_shuffle(weekday[0], weekday[units->Length-1]);

			String^ a = weekday[0] + ", " + day1;
			String^ b = weekday[1] + ", " + day2;
			String^ c = weekday[2] + ", " + day3;
			String^ d = weekday[3] + ", " + day4;
			String^ e = weekday[4] + ", " + day5;
			StreamWriter^ sw;
			try {
				sw = File::AppendText("timetable.csv");
				//sw = gcnew StreamWriter("timetable.csv");
			}
			catch (IOException^ ex)
			{
				MessageBox::Show(this, "Cannot proceed as required because required file is in use by another process", this->Text, MessageBoxButtons::OK, MessageBoxIcon::Error);
				Application::Exit();
			}
			sw->WriteLine("Units");

			//Monday
			if (a->StartsWith("Monday"))
			{
				//dgv->Rows->Add(a);
				sw->WriteLine(a);
			}
			else if (b->StartsWith("Monday"))
			{
				sw->WriteLine(b);
			}
			else if (c->StartsWith("Monday"))
			{
				sw->WriteLine(c);
			}
			else if (d->StartsWith("Monday"))
			{
				sw->WriteLine(d);
			}
			else if (e->StartsWith("Monday"))
			{
				sw->WriteLine(e);
			}

			//Tuesday
			if (a->StartsWith("Tuesday"))
			{
				sw->WriteLine(a);
			}
			else if (b->StartsWith("Tuesday"))
			{
				sw->WriteLine(b);
			}
			else if (c->StartsWith("Tuesday"))
			{
				sw->WriteLine(c);
			}
			else if (d->StartsWith("Tuesday"))
			{
				sw->WriteLine(d);
			}
			else if (e->StartsWith("Tuesday"))
			{
				sw->WriteLine(e);
			}

			//Wednesday
			if (a->StartsWith("Wednesday"))
			{
				sw->WriteLine(a);
			}
			else if (b->StartsWith("Wednesday"))
			{
				sw->WriteLine(b);
			}
			else if (c->StartsWith("Wednesday"))
			{
				sw->WriteLine(c);
			}
			else if (d->StartsWith("Wednesday"))
			{
				sw->WriteLine(d);
			}
			else if (e->StartsWith("Wednesday"))
			{
				sw->WriteLine(e);
			}

			//Thursday
			if (a->StartsWith("Thursday"))
			{
				sw->WriteLine(a);
			}
			else if (b->StartsWith("Thursday"))
			{
				sw->WriteLine(b);
			}
			else if (c->StartsWith("Thursday"))
			{
				sw->WriteLine(c);
			}
			else if (d->StartsWith("Thursday"))
			{
				sw->WriteLine(d);
			}
			else if (e->StartsWith("Thursday"))
			{
				sw->WriteLine(e);
			}

			//Friday
			if (a->StartsWith("Friday"))
			{
				sw->WriteLine(a);
			}
			else if (b->StartsWith("Friday"))
			{
				sw->WriteLine(b);
			}
			else if (c->StartsWith("Friday"))
			{
				sw->WriteLine(c);
			}
			else if (d->StartsWith("Friday"))
			{
				sw->WriteLine(d);
			}
			else if (e->StartsWith("Friday"))
			{
				sw->WriteLine(e);
			}
			sw->WriteLine();
			sw->Close();
			view();
			repeat();
		}
		else if (msg == System::Windows::Forms::DialogResult::No)
		{
			MessageBox::Show("Saved to csv file. You can format the raw data from there.", this->Text, MessageBoxButtons::OK);
			button3->Visible = true;
			button4->Visible = true;
		}
	}

	private: void view() {
		dgv->DataSource = nullptr;
		//dgv->ColumnHeadersVisible=false;
		dgv->Columns[0]->Visible = false;
		dgv->Columns[1]->Visible = false;
		button2->Enabled = false;
		array<String^>^ raw_text = System::IO::File::ReadAllLines("timetable.csv");
		array<String^>^ data_col;
		int x = 0;
		DataTable^ my_datatable = gcnew DataTable();
		for each (String ^ text_line in raw_text)
		{
			data_col = text_line->Split(', ');
			if (x == 0)
			{
				for (int i = 0; i <= data_col->Length - 1; i++)
				{
					my_datatable->Columns->Add(data_col[i]);
				}
				x++;
			}
			else
			{
				//dgv->ColumnCount = my_datatable->Columns->Count;
				my_datatable->Rows->Add(data_col);
			}
		}
		dgv->DataSource = my_datatable;
		dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		dgv->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		button3->Visible = false;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		repeat();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		dgv->DataSource = nullptr;
		dgv->Columns[0]->Visible = true;
		dgv->Columns[1]->Visible = true;
		button1->Enabled = true;
		textBox1->Enabled = true;
		button2->Visible = false;
		button2->Enabled = true;
		button3->Visible = false;
		button4->Visible = false;
	}
	};
}
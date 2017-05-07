#include <iostream>
#include "ClosesClass.h"
#pragma once


namespace Tihanovich_CP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// ������ ��� StyleForm
	/// </summary>
	public ref class StyleForm : public System::Windows::Forms::Form
	{
	public:
		ClosesCollection ^ Clos;
	private: System::Windows::Forms::ComboBox^  BoxOfCloses;
	private: System::Windows::Forms::Button^  PrevModel;
	private: System::Windows::Forms::Button^  NextModel;
	private: System::Windows::Forms::Label^  NameModel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;

	public:



	public:
		ClosesCollection ^LegsCol;
		ClosesCollection ^TorsCol;
		ClosesCollection ^ObyvCol;
		ClosesCollection ^ClosesCol;
		ClosesCollection ^ModelCol;
		StyleForm(void)
		{
			InitializeComponent();
			//
			ClosesBox->AllowDrop = true;
			ModelBox->AllowDrop = true;
			LegsCol = gcnew ClosesCollection("./legs");
			TorsCol = gcnew ClosesCollection("./tors");
			ObyvCol = gcnew ClosesCollection("./obyv");
			ClosesCol = gcnew ClosesCollection("./closes");
			ModelCol = gcnew ClosesCollection("./models");
			BoxOfCloses->SelectedIndex = 0;
			ShowClos(LegsCol->GetPathOfPicture());
			g1 = ModelBox->CreateGraphics();
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~StyleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		int pbw, pbh;
		int pbX, pbY;
		int typec;
		Image ^Closes;
		Image ^Tors;
		Image ^Legs;
		Image ^Model;
		Image ^Obyv;
		bool IsTorsSet = false;
		bool IsLegsSet = false;
		bool IsClosesSet = false;
		bool IsObyvSet = false;
		Graphics ^ g1;
	private: System::Windows::Forms::PictureBox^  ModelBox;

	private: System::Windows::Forms::PictureBox^  ClosesBox;
	private: System::Windows::Forms::Button^  PrevClosB;
	private: System::Windows::Forms::Button^  NextClosB;
	protected:





	protected:



			 /// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StyleForm::typeid));
			this->ModelBox = (gcnew System::Windows::Forms::PictureBox());
			this->ClosesBox = (gcnew System::Windows::Forms::PictureBox());
			this->PrevClosB = (gcnew System::Windows::Forms::Button());
			this->NextClosB = (gcnew System::Windows::Forms::Button());
			this->BoxOfCloses = (gcnew System::Windows::Forms::ComboBox());
			this->PrevModel = (gcnew System::Windows::Forms::Button());
			this->NextModel = (gcnew System::Windows::Forms::Button());
			this->NameModel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModelBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClosesBox))->BeginInit();
			this->SuspendLayout();
			// 
			// ModelBox
			// 
			this->ModelBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ModelBox.BackgroundImage")));
			this->ModelBox->Location = System::Drawing::Point(648, 87);
			this->ModelBox->Name = L"ModelBox";
			this->ModelBox->Size = System::Drawing::Size(220, 300);
			this->ModelBox->TabIndex = 0;
			this->ModelBox->TabStop = false;
			this->ModelBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &StyleForm::ModelBox_DragDrop);
			this->ModelBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &StyleForm::ModelBox_DragEnter);
			// 
			// ClosesBox
			// 
			this->ClosesBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ClosesBox.BackgroundImage")));
			this->ClosesBox->Location = System::Drawing::Point(70, 87);
			this->ClosesBox->Name = L"ClosesBox";
			this->ClosesBox->Size = System::Drawing::Size(220, 300);
			this->ClosesBox->TabIndex = 1;
			this->ClosesBox->TabStop = false;
			this->ClosesBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &StyleForm::ClosesBox_DragDrop);
			this->ClosesBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &StyleForm::ClosesBox_DragEnter);
			this->ClosesBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &StyleForm::ClosesBox_MouseDown);
			// 
			// PrevClosB
			// 
			this->PrevClosB->Location = System::Drawing::Point(70, 437);
			this->PrevClosB->Name = L"PrevClosB";
			this->PrevClosB->Size = System::Drawing::Size(88, 23);
			this->PrevClosB->TabIndex = 2;
			this->PrevClosB->Text = L"����������";
			this->PrevClosB->UseVisualStyleBackColor = true;
			this->PrevClosB->Click += gcnew System::EventHandler(this, &StyleForm::PrevClosB_Click);
			// 
			// NextClosB
			// 
			this->NextClosB->Location = System::Drawing::Point(205, 437);
			this->NextClosB->Name = L"NextClosB";
			this->NextClosB->Size = System::Drawing::Size(85, 23);
			this->NextClosB->TabIndex = 3;
			this->NextClosB->Text = L"���������";
			this->NextClosB->UseVisualStyleBackColor = true;
			this->NextClosB->Click += gcnew System::EventHandler(this, &StyleForm::NextClosB_Click);
			// 
			// BoxOfCloses
			// 
			this->BoxOfCloses->FormattingEnabled = true;
			this->BoxOfCloses->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"����", L"�����", L"����", L"������" });
			this->BoxOfCloses->Location = System::Drawing::Point(169, 481);
			this->BoxOfCloses->Name = L"BoxOfCloses";
			this->BoxOfCloses->Size = System::Drawing::Size(121, 21);
			this->BoxOfCloses->TabIndex = 4;
			this->BoxOfCloses->SelectedIndexChanged += gcnew System::EventHandler(this, &StyleForm::comboBox1_SelectedIndexChanged);
			this->BoxOfCloses->TextUpdate += gcnew System::EventHandler(this, &StyleForm::comboBox1_TextUpdate);
			// 
			// PrevModel
			// 
			this->PrevModel->Location = System::Drawing::Point(648, 437);
			this->PrevModel->Name = L"PrevModel";
			this->PrevModel->Size = System::Drawing::Size(84, 23);
			this->PrevModel->TabIndex = 5;
			this->PrevModel->Text = L"����������";
			this->PrevModel->UseVisualStyleBackColor = true;
			this->PrevModel->Click += gcnew System::EventHandler(this, &StyleForm::PrevModel_Click);
			// 
			// NextModel
			// 
			this->NextModel->Location = System::Drawing::Point(784, 437);
			this->NextModel->Name = L"NextModel";
			this->NextModel->Size = System::Drawing::Size(84, 23);
			this->NextModel->TabIndex = 6;
			this->NextModel->Text = L"���������";
			this->NextModel->UseVisualStyleBackColor = true;
			this->NextModel->Click += gcnew System::EventHandler(this, &StyleForm::NextModel_Click);
			// 
			// NameModel
			// 
			this->NameModel->AutoSize = true;
			this->NameModel->Location = System::Drawing::Point(724, 484);
			this->NameModel->Name = L"NameModel";
			this->NameModel->Size = System::Drawing::Size(81, 13);
			this->NameModel->TabIndex = 7;
			this->NameModel->Text = L"����� ������";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(67, 484);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"����� �������";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(648, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"��������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StyleForm::button1_Click_1);
			// 
			// StyleForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 531);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NameModel);
			this->Controls->Add(this->NextModel);
			this->Controls->Add(this->PrevModel);
			this->Controls->Add(this->BoxOfCloses);
			this->Controls->Add(this->NextClosB);
			this->Controls->Add(this->PrevClosB);
			this->Controls->Add(this->ClosesBox);
			this->Controls->Add(this->ModelBox);
			this->Name = L"StyleForm";
			this->Text = L"StyleForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModelBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClosesBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:System::Void ShowClos(String ^PPath)
		{
					ClosesBox->SizeMode = PictureBoxSizeMode::AutoSize;
					ClosesBox->Image = gcnew Bitmap(PPath);
		}
		private: System::Void ShowModel()
		{
					 g1->Clear(Color::White);
					 g1->DrawImage(Model, 0, 0);
					 if (IsLegsSet)
					 {
						 g1->DrawImage(Legs, 0, 0);
					 }
					 if (IsTorsSet)
					 {
						 g1->DrawImage(Tors, 0, 0);
					 }
					 if (IsObyvSet)
					 {
						 g1->DrawImage(Obyv, 0, 0);
					 }
					 if (IsClosesSet)
					 {
						 IsTorsSet = false;
						 IsLegsSet = false;
						 g1->DrawImage(Closes, 0, 0);
					 }
					
		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
}
private: System::Void PrevClosB_Click(System::Object^  sender, System::EventArgs^  e)
{
			 if (typec == 0)
			 {
				 LegsCol->PrevPicture();
				 ShowClos(LegsCol->GetPathOfPicture());
			 }
			 if (typec == 1)
			 {
				 ObyvCol->PrevPicture();
				 ShowClos(ObyvCol->GetPathOfPicture());
			 }
			 if (typec == 2)
			 {
				 TorsCol->PrevPicture();
				 ShowClos(TorsCol->GetPathOfPicture());
			 }
			 if (typec == 3)
			 {
				 ClosesCol->PrevPicture();
				 ShowClos(ClosesCol->GetPathOfPicture());
			 }

}
private: System::Void NextClosB_Click(System::Object^  sender, System::EventArgs^  e)
{
			 if (typec == 0)
			 {
				 LegsCol->NextPicture();
				 ShowClos(LegsCol->GetPathOfPicture()); 
			 }
			 if (typec == 1)
			 {
				 ObyvCol->NextPicture();
				 ShowClos(ObyvCol->GetPathOfPicture());
			 }
			 if (typec == 2)
			 {
				 TorsCol->NextPicture();
				 ShowClos(TorsCol->GetPathOfPicture());
			 }
			 if (typec == 3)
			 {
				 ClosesCol->NextPicture();
				 ShowClos(ClosesCol->GetPathOfPicture());
			 }
		
}
private: System::Void ClosesBox_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
		
}
private: System::Void StyleForm_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{

}
private: System::Void ClosesBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
			 PictureBox ^ pb = ClosesBox;
			 pb->Select();
			 pb->DoDragDrop(ClosesBox->Image, DragDropEffects::Copy);
}
private: System::Void ModelBox_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
			 if (e->Data->GetDataPresent(DataFormats::Bitmap))
			 {
				 e->Effect = DragDropEffects::Copy;
			 }
			 else
			 {
				 e->Effect = DragDropEffects::None;
			 }
}
private: System::Void ModelBox_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
			 if (typec == 0)
			 {
				 IsLegsSet = true;
				 IsClosesSet = false;
				 Legs = safe_cast<Bitmap^>(e->Data->GetData(DataFormats::Bitmap));
			 }
			 if (typec == 1)
			 {
				 IsObyvSet = true;
				 Obyv = safe_cast<Bitmap^>(e->Data->GetData(DataFormats::Bitmap));
			 }
			 if (typec == 2)
			 {
				 IsTorsSet = true;
				 IsClosesSet = false;
				 Tors = safe_cast<Bitmap^>(e->Data->GetData(DataFormats::Bitmap));
			 }
			 if (typec == 3)
			 {
				 IsClosesSet = true;
				 IsTorsSet = false;
				 IsLegsSet = false;
				 Closes = safe_cast<Bitmap^>(e->Data->GetData(DataFormats::Bitmap));
			 }
			 ShowModel();
			
			 
}
private: System::Void ClosesBox_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
			 if (e->Data->GetDataPresent(DataFormats::Bitmap))
			 {
				 e->Effect = DragDropEffects::Copy;
			 }
			 else
			 {
				 e->Effect = DragDropEffects::None;
			 }
}
private: System::Void comboBox1_TextUpdate(System::Object^  sender, System::EventArgs^  e)
{

}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
			 switch (BoxOfCloses->SelectedIndex)
			 {
			 case 0:
				 typec = 0;
				 ShowClos(LegsCol->GetPathOfPicture());
				 break;
			 case 1:
				 ShowClos(ObyvCol->GetPathOfPicture());
				 typec = 1;
				 break;
			 case 2:
				 ShowClos(TorsCol->GetPathOfPicture());
				 typec = 2;
				 break;
			 case 3:
				 typec = 3;
				 ShowClos(ClosesCol->GetPathOfPicture());
			 }
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e)
{
			 IsTorsSet = false;
			 IsLegsSet = false;
			 IsClosesSet = false;
			 IsObyvSet = false;
			 ShowModel();
}
private: System::Void PrevModel_Click(System::Object^  sender, System::EventArgs^  e)
{
			 ModelCol->PrevPicture();
			 Model = Image::FromFile(ModelCol->GetPathOfPicture());
			 ShowModel();
}
private: System::Void NextModel_Click(System::Object^  sender, System::EventArgs^  e)
{
			 ModelCol->NextPicture();
			 Model = Image::FromFile(ModelCol->GetPathOfPicture());
			 ShowModel();
}
};
}

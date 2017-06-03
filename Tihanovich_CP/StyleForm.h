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
	/// Сводка для StyleForm
	/// </summary>
	public ref class StyleForm : public System::Windows::Forms::Form
	{
	public:
		// Объект который работает с картинками модели
		ClosesCollection ^ Clos;
	private: System::Windows::Forms::ComboBox^  BoxOfCloses;
	private: System::Windows::Forms::Button^  PrevModel;
	private: System::Windows::Forms::Button^  NextModel;
	private: System::Windows::Forms::Label^  NameModel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;

	public:


		private:

			int typec; // Тип выбранного инструмента-одежды
			//Картинки в которых находится выбранная одежда
			Image ^Closes;
			Image ^Tors;
			Image ^Legs;
			Image ^Model;
			Image ^Obyv;
			// Булевые переменный, которые указывают какая одежда надета
			bool IsTorsSet = false;
			bool IsLegsSet = false;
			bool IsClosesSet = false;
			bool IsObyvSet = false;
			bool lcheck = false;
			// Объект нужный для отрисовки модели
			Graphics ^ g1;
	public:
		// Объекты, требующиеся для работами с файлами одежды
		ClosesCollection ^LegsCol;
		ClosesCollection ^TorsCol;
		ClosesCollection ^ObyvCol;
		ClosesCollection ^ClosesCol;

	private: System::Windows::Forms::CheckBox^  LegsCheck;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::HelpProvider^  helpProvider1;
	private: System::Windows::Forms::Button^  helpB;
	public:
		ClosesCollection ^ModelCol;
		StyleForm(void)
		{
			InitializeComponent();
			//
			ClosesBox->AllowDrop = true;
			ModelBox->AllowDrop = true;
			// Создаем объекты для работы с картинками
			LegsCol = gcnew ClosesCollection("./legs");
			TorsCol = gcnew ClosesCollection("./tors");
			ObyvCol = gcnew ClosesCollection("./obyv");
			ClosesCol = gcnew ClosesCollection("./closes");
			ModelCol = gcnew ClosesCollection("./models");
			ModelBox->Visible = true;
			g1 = ModelBox->CreateGraphics(); // Создаем объект Graphics который будет рисовать в ModelBox
			BoxOfCloses->SelectedIndex = 0; // В списке типов одежды переключаемся на первый элемент
			ShowClos(LegsCol->GetPathOfPicture()); // Получаем путь к первому файлу из LegsCol
			//ShowModel(ModelCol->GetPathOfPicture());
			Model = Image::FromFile(ModelCol->GetPathOfPicture()); // Загружаем первую модель в Model
			g1->Clear(Color::Red); // Очищаем g1 красным цветом
			g1->DrawImage(Model, 0, 0, 220, 300); // Рисуем модель
			int i;
			//ModelBox->BackColor = Color::Transparent;
			ShowModel(); // Вызываем метод показа модели
			timer1->Enabled = true; // Запускаем таймер, который нужен для корректного отображения модели в первый раз
			//TODO: добавьте код конструктора
			//
			this->helpProvider1->HelpNamespace = "help.chm";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~StyleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		
	private: System::Windows::Forms::PictureBox^  ModelBox;

	private: System::Windows::Forms::PictureBox^  ClosesBox;
	private: System::Windows::Forms::Button^  PrevClosB;
	private: System::Windows::Forms::Button^  NextClosB;
	private: System::ComponentModel::IContainer^  components;
	protected:





	protected:



			 /// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
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
			this->LegsCheck = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->helpB = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModelBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClosesBox))->BeginInit();
			this->SuspendLayout();
			// 
			// ModelBox
			// 
			this->ModelBox->BackColor = System::Drawing::Color::Red;
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
			this->ClosesBox->BackColor = System::Drawing::Color::Red;
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
			this->PrevClosB->Text = L"Предыдущий";
			this->PrevClosB->UseVisualStyleBackColor = true;
			this->PrevClosB->Click += gcnew System::EventHandler(this, &StyleForm::PrevClosB_Click);
			// 
			// NextClosB
			// 
			this->NextClosB->Location = System::Drawing::Point(205, 437);
			this->NextClosB->Name = L"NextClosB";
			this->NextClosB->Size = System::Drawing::Size(85, 23);
			this->NextClosB->TabIndex = 3;
			this->NextClosB->Text = L"Следующий";
			this->NextClosB->UseVisualStyleBackColor = true;
			this->NextClosB->Click += gcnew System::EventHandler(this, &StyleForm::NextClosB_Click);
			// 
			// BoxOfCloses
			// 
			this->BoxOfCloses->FormattingEnabled = true;
			this->BoxOfCloses->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Ноги", L"Обувь", L"Торс", L"Платья" });
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
			this->PrevModel->Text = L"Предыдущая";
			this->PrevModel->UseVisualStyleBackColor = true;
			this->PrevModel->Click += gcnew System::EventHandler(this, &StyleForm::PrevModel_Click);
			// 
			// NextModel
			// 
			this->NextModel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->NextModel->Location = System::Drawing::Point(784, 437);
			this->NextModel->Name = L"NextModel";
			this->NextModel->Size = System::Drawing::Size(84, 23);
			this->NextModel->TabIndex = 6;
			this->NextModel->Text = L"Следующая";
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
			this->NameModel->Text = L"Выбор модели";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(67, 484);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Выбор нарядов";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(648, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Очистить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StyleForm::button1_Click_1);
			// 
			// LegsCheck
			// 
			this->LegsCheck->AutoSize = true;
			this->LegsCheck->Location = System::Drawing::Point(648, 398);
			this->LegsCheck->Name = L"LegsCheck";
			this->LegsCheck->Size = System::Drawing::Size(203, 17);
			this->LegsCheck->TabIndex = 11;
			this->LegsCheck->Text = L"Обувь сверху(например для сапог)";
			this->LegsCheck->UseVisualStyleBackColor = true;
			this->LegsCheck->CheckedChanged += gcnew System::EventHandler(this, &StyleForm::LegsCheck_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &StyleForm::timer1_Tick);
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"./help.chm";
			// 
			// helpB
			// 
			this->helpB->Location = System::Drawing::Point(13, 13);
			this->helpB->Name = L"helpB";
			this->helpB->Size = System::Drawing::Size(75, 23);
			this->helpB->TabIndex = 12;
			this->helpB->Text = L"Справка";
			this->helpB->UseVisualStyleBackColor = true;
			this->helpB->Click += gcnew System::EventHandler(this, &StyleForm::helpB_Click);
			// 
			// StyleForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 531);
			this->Controls->Add(this->helpB);
			this->Controls->Add(this->LegsCheck);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StyleForm";
			this->helpProvider1->SetShowHelp(this, true);
			this->Text = L"Создание стиля";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ModelBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ClosesBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:System::Void ShowClos(String ^PPath) // Метод показывающий текущий элемент одежды в ClosesBox
		{
					ClosesBox->SizeMode = PictureBoxSizeMode::AutoSize;
					ClosesBox->Image = gcnew Bitmap(PPath);
		}
		private: System::Void ShowModel() // Метод показывающий модель и одежду в ModelBox
		{
					 ModelBox->Height = 300;
					 ModelBox->Width = 220;
					 ModelBox->SizeMode = PictureBoxSizeMode::Zoom;
					 g1->Clear(Color::Red);
					 g1->DrawImage(Model, 0, 0, 220, 300);
					 if (lcheck)
					 {
						 if (IsLegsSet)
						 {
							 g1->DrawImage(Legs, 0, 0, 220, 300);
						 }
						 if (IsObyvSet)
						 {
							 g1->DrawImage(Obyv, 0, 0, 220, 300);
						 }
					 }
					 else
					 {
						 if (IsObyvSet)
						 {
							 g1->DrawImage(Obyv, 0, 0, 220, 300);
						 }
						 if (IsLegsSet)
						 {
							 g1->DrawImage(Legs, 0, 0, 220, 300);
						 }
					 }
					 if (IsTorsSet)
					 {
						 g1->DrawImage(Tors, 0, 0,220,300);
					 }
					 
					 if (IsClosesSet)
					 {
						 IsTorsSet = false;
						 IsLegsSet = false;
						 g1->DrawImage(Closes, 0, 0,220,300);
					 }
					
		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
}
private: System::Void PrevClosB_Click(System::Object^  sender, System::EventArgs^  e) // Переключаем на предыдущий элемент одежды
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
private: System::Void NextClosB_Click(System::Object^  sender, System::EventArgs^  e) // На следующий
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
private: System::Void ClosesBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) // Начало DragonDrop-а
{
			 PictureBox ^ pb = ClosesBox;
			 pb->Select();
			 pb->DoDragDrop(ClosesBox->Image, DragDropEffects::Copy);  // Начинаем перемещение
}
private: System::Void ModelBox_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) // Задаем эффект
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
private: System::Void ModelBox_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) // При опускании на ModelBox заносим перемещаемую картинку в соответствующую переменную
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
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) // Если выбрали другой тип одежды то загрузим нужную картинку в ClosesBox
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
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) // Событие убирающее одежду с модели
{
			 IsTorsSet = false;
			 IsLegsSet = false;
			 IsClosesSet = false;
			 IsObyvSet = false;
			 ShowModel();
}
private: System::Void PrevModel_Click(System::Object^  sender, System::EventArgs^  e) // Выбираем и отрисовываем предыдущую модель
{
			 ModelCol->PrevPicture();
			 Model = Image::FromFile(ModelCol->GetPathOfPicture());
			 ShowModel();
}
private: System::Void NextModel_Click(System::Object^  sender, System::EventArgs^  e) // Выбираем и отрисовываем следующую модель
{
			 ModelCol->NextPicture();
			 Model = Image::FromFile(ModelCol->GetPathOfPicture());
			 ShowModel();
}
private: System::Void LegsCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) // При установки галочки обувь будет рисоваться поверх штанов
{
			 if (LegsCheck->Checked == true)
				 lcheck = true;
			 else
				 lcheck = false;
			 ShowModel();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) // Событие требуеться для первоначальной отрисовки модели, после этого данный таймер не используется
{
			 timer1->Enabled = false;
			 ShowModel();
}
private: System::Void helpB_Click(System::Object^  sender, System::EventArgs^  e)
{
			 Help::ShowHelp(this, helpProvider1->HelpNamespace);
}
};
}

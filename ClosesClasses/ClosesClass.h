using namespace System;
using namespace System::IO;


public ref class ClosesCollection
{
public:
	String ^aPath;
	DirectoryInfo ^di;
	array<FileInfo^> ^fi; // Массив файлов
	System::Collections::Generic::List<String^> ^imgList; // Лист картинок
	int cImg; // Индекс текущей картинки
	int CountImg;
	ClosesCollection(String ^Path)
	{
		//dwdw
		di = gcnew DirectoryInfo(Path); // Создаем объект DirectoryInfo 
		aPath = di->FullName;
		fi = di->GetFiles(); // Заполняем fi информацией о всех пнгшках в папке
		imgList = gcnew System::Collections::Generic::List<String^>; // Создаём List картинок
		imgList->Clear(); // Очищяем
		for each (FileInfo ^ fc in fi) // Из fi добавляем информацию в ImgList
		{
			imgList->Add(fc->Name);
		}
		CountImg = imgList->Count - 1; // Последний индекс
		cImg = 0; // Обнуляем индекс
	}
	
	String ^ GetPathOfPicture() // Метод получения пути к файлу
	{
		return(aPath + "\\" + imgList[cImg]);
	}
	void NextPicture() // Переключаемся на следующий путь
	{
		if (cImg == CountImg) cImg = 0;
		else cImg++;
	}
	void PrevPicture() // Переключаемся на предыдущий путь
	{
		if (cImg == 0) cImg = CountImg;
		else cImg--;
	}
};
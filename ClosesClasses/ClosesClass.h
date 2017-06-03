using namespace System;
using namespace System::IO;


public ref class ClosesCollection
{
public:
	String ^aPath;
	DirectoryInfo ^di;
	array<FileInfo^> ^fi; // ������ ������
	System::Collections::Generic::List<String^> ^imgList; // ���� ��������
	int cImg; // ������ ������� ��������
	int CountImg;
	ClosesCollection(String ^Path)
	{
		//dwdw
		di = gcnew DirectoryInfo(Path); // ������� ������ DirectoryInfo 
		aPath = di->FullName;
		fi = di->GetFiles(); // ��������� fi ����������� � ���� ������� � �����
		imgList = gcnew System::Collections::Generic::List<String^>; // ������ List ��������
		imgList->Clear(); // �������
		for each (FileInfo ^ fc in fi) // �� fi ��������� ���������� � ImgList
		{
			imgList->Add(fc->Name);
		}
		CountImg = imgList->Count - 1; // ��������� ������
		cImg = 0; // �������� ������
	}
	
	String ^ GetPathOfPicture() // ����� ��������� ���� � �����
	{
		return(aPath + "\\" + imgList[cImg]);
	}
	void NextPicture() // ������������� �� ��������� ����
	{
		if (cImg == CountImg) cImg = 0;
		else cImg++;
	}
	void PrevPicture() // ������������� �� ���������� ����
	{
		if (cImg == 0) cImg = CountImg;
		else cImg--;
	}
};
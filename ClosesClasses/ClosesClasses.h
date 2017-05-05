// ClosesClasses.h

#pragma once

using namespace System;
using namespace System::IO;

namespace ClosesClasses {

	public ref class ClosesCollection
	{
	public:
		String ^aPath;
		DirectoryInfo ^di;
		array<FileInfo^> ^fi;
		System::Collections::Generic::List<String^> ^imgList;
		int cImg;
		int CountImg;
		ClosesCollection(String ^Path)
		{
			di = gcnew DirectoryInfo(Path);
			aPath = di->FullName;
			FillList(aPath);
		}
		void FillList(String ^aPath)
		{
			fi = di->GetFiles();
			imgList->Clear();
			for each (FileInfo ^ fc in fi)
			{
				imgList->Add(fc->Name);
			}
			CountImg = imgList->Count;
			cImg = 0;
		}
			String ^ GetPathOfPicture()
			{
				return(aPath + "\\" + imgList[cImg]);
			}
			void NextPicture()
			{
				if (cImg == CountImg) cImg = 0;
				else cImg++;
			}
			void PrevPicture()
			{
				if (cImg = 0) cImg = CountImg;
				else cImg--;
			}
	};
}

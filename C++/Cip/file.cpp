//#include <iostream>
//#include <io.h>
//#include <stdio.h>
//#include <vector>
//using namespace std;
//vector<string> vec_path;
//
//bool TraverseDirectory(std::string path)
//{
//	__int64  Handle;
//	struct __finddata64_t  FileInfo;
//	string strFind = path + "\\*";
//
//	if ((Handle = _findfirst64(strFind.c_str(), &FileInfo)) == -1L)
//	{
//		printf("û���ҵ�ƥ�����Ŀ\n");
//		return false;
//	}
//	do
//	{
//		//�ж��Ƿ�����Ŀ¼
//		if (FileInfo.attrib & _A_SUBDIR)
//		{
//			//�ж������ļ���
//			//������ж���������Ҫ������ . �� ..
//			if ((strcmp(FileInfo.name, ".") != 0) && (strcmp(FileInfo.name, "..") != 0))
//			{
//				string newPath = path + "\\" + FileInfo.name;
//				TraverseDirectory(newPath);
//			}
//		}
//		else	//�ж����ļ�
//		{
//			string newPath = path + "\\" + FileInfo.name;
//			//�Զ������
//			vec_path.push_back(newPath);
//		}
//	} while (_findnext64(Handle, &FileInfo) == 0);
//
//	_findclose(Handle);
//	return true;
//}
//int main()
//{
//	string input_path = "E:\\CODE\\GitHub\\ComputerTeconlogyExpermient\\C++\\test";
//	//���õݹ��㷨
//	TraverseDirectory(input_path);
//	for (int i = 0; i < vec_path.size(); i++)//�����ά��̬���� 
//	{
//	
//		cout << vec_path[i] << endl;
//		cout << "\n";
//	}
//	return 0;
//}
//

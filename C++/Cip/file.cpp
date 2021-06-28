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
//		printf("没有找到匹配的项目\n");
//		return false;
//	}
//	do
//	{
//		//判断是否有子目录
//		if (FileInfo.attrib & _A_SUBDIR)
//		{
//			//判断是子文件夹
//			//下面的判断条件很重要，过滤 . 和 ..
//			if ((strcmp(FileInfo.name, ".") != 0) && (strcmp(FileInfo.name, "..") != 0))
//			{
//				string newPath = path + "\\" + FileInfo.name;
//				TraverseDirectory(newPath);
//			}
//		}
//		else	//判断是文件
//		{
//			string newPath = path + "\\" + FileInfo.name;
//			//自定义操作
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
//	//调用递归算法
//	TraverseDirectory(input_path);
//	for (int i = 0; i < vec_path.size(); i++)//输出二维动态数组 
//	{
//	
//		cout << vec_path[i] << endl;
//		cout << "\n";
//	}
//	return 0;
//}
//

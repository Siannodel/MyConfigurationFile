// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CONFIGURATIONFILE_DLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CONFIGURATIONFILE_DLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#pragma once

#ifdef CONFIGURATIONFILE_DLL_EXPORTS
#define CONFIGURATIONFILE_DLL_API __declspec(dllexport)
#else
#define CONFIGURATIONFILE_DLL_API __declspec(dllimport)
#endif

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
// 此类是从 ConfigurationFile_dll.dll 导出的
class CONFIGURATIONFILE_DLL_API ConfigurationFile {
public:
	// TODO:  在此添加您的方法。
	ConfigurationFile();
	ConfigurationFile(const string path);
	ConfigurationFile &operator=(const string path);
	~ConfigurationFile();

	string const getpath();
	void printdata();

	void Modifydata(string module, string key, string value);
	void Modifydata(string module, string key, int value);
	void Modifydata(string module, string key, double value);
	void Modifydata(string module, string key, bool value);

	bool Deletedata(string module, string key);

	string getdata_str(string module, string key);
	int getdata_int(string module, string key);
	double getdata_double(string module, string key);
	bool getdata_bool(string module, string key);

	void WritetoFile();
private:
	string filepath;
	map<string, map<string, string>> dictionary;
	bool ifmodify = false;
};



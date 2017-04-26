// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CONFIGURATIONFILE_DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CONFIGURATIONFILE_DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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
// �����Ǵ� ConfigurationFile_dll.dll ������
class CONFIGURATIONFILE_DLL_API ConfigurationFile {
public:
	// TODO:  �ڴ�������ķ�����
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



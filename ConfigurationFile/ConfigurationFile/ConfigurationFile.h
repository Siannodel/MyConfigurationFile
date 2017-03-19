#pragma once
#ifndef CONFIGURATION_FILE
#define CONFIGURATION_FILE

#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;
class ConfigurationFile{
public:
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
	bool ifmodify=false;
};
#endif // !CONFIGURATION_FILE
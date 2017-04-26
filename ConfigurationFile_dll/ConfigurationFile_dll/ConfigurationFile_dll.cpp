// ConfigurationFile_dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "ConfigurationFile_dll.h"

ConfigurationFile::ConfigurationFile()
{

}
ConfigurationFile::ConfigurationFile(const string path)
{
	filepath = path;
	ifstream filestream(filepath);
	string line;
	string modulename;
	while (getline(filestream, line))
	{
		if (line[0] == '[')
		{
			modulename = line.substr(line.find_first_of('[') + 1, line.length() - 2);
			map<string, string> module;
			dictionary.insert({ modulename,module });
		}
		else
		{
			string key = line.substr(0, line.find_first_of(string(" =")));
			string value = line.substr(line.find_last_of(string(" =")) + 1);
			dictionary[modulename].insert({ key,value });
		}
	}
}
ConfigurationFile &ConfigurationFile::operator=(const string path)
{
	filepath = path;
	ifstream filestream(filepath);
	string line;
	string modulename;
	while (getline(filestream, line))
	{
		if (line[0] == '[')
		{
			modulename = line.substr(line.find_first_of('[') + 1, line.length() - 2);
			map<string, string> module;
			dictionary.insert({ modulename,module });
		}
		else
		{
			string key = line.substr(0, line.find_first_of('='));
			string value = line.substr(line.find_first_of('=') + 1);
			dictionary[modulename].insert({ key,value });
		}
	}
	return *this;
}
ConfigurationFile::~ConfigurationFile()
{
	if (ifmodify)
		WritetoFile();
}
string const ConfigurationFile::getpath()
{
	return filepath;
}
void ConfigurationFile::printdata()
{
	cout << filepath << endl;
	for (auto i : dictionary)
	{
		cout << "[" << i.first << "]" << endl;
		for (auto j : i.second)
			cout << j.first << "=" << j.second << endl;
	}
}
void ConfigurationFile::Modifydata(string module, string key, string value)
{
	dictionary[module][key] = value;
	ifmodify = true;
}
void ConfigurationFile::Modifydata(string module, string key, int value)
{
	dictionary[module][key] = to_string(value);
	ifmodify = true;
}
void ConfigurationFile::Modifydata(string module, string key, double value)
{
	dictionary[module][key] = to_string(value);
	ifmodify = true;
}
void ConfigurationFile::Modifydata(string module, string key, bool value)
{
	if (value)
		dictionary[module][key] = "true";
	else
		dictionary[module][key] = "false";
	ifmodify = true;
}
bool ConfigurationFile::Deletedata(string module, string key)
{
	bool i = dictionary.find(module)->second.erase(key);
	if (dictionary.find(module)->second.empty())
		dictionary.erase(module);
	ifmodify = true;
	return i;
}
string ConfigurationFile::getdata_str(string module, string key)
{
	return dictionary.find(module)->second.find(key)->second;
}
int ConfigurationFile::getdata_int(string module, string key)
{
	return stoi(dictionary.find(module)->second.find(key)->second);
}
double ConfigurationFile::getdata_double(string module, string key)
{
	return stod(dictionary.find(module)->second.find(key)->second);
}
bool ConfigurationFile::getdata_bool(string module, string key)
{
	if (dictionary.find(module)->second.find(key)->second == "true")
		return true;
	else
		return false;
}
void ConfigurationFile::WritetoFile()
{
	ofstream file_stream(filepath);
	for (auto i : dictionary)
	{
		file_stream << "[" << i.first << "]" << endl;
		for (auto j : i.second)
			file_stream << j.first << "=" << j.second << endl;
	}
	ifmodify = false;
}

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <io.h>
using namespace std;


void CreateFolder(const char* path)
{
	CreateDirectoryA(path, NULL);
}

bool useless(char sign)
{
	switch (sign)
	{
	case '[':
	case ',': return true;
		break;
	default: return false;
		break;
	}
}

bool alreadyInstalled(string mod)
{
	if (access(("installed_modules/" + mod).c_str(), 0) == 0)
	{
		cout << mod << " is already installed.\n";
		cout << "All done." << endl;
		return 0;
	}
	
}

void installModules(string mod)
{
	int count = 0;
	ifstream packages("all_packages.json", ios::in);

	CreateFolder("D:\\installed_modules");
	string anotherTrash;
	while (!packages.eof())
	{
		getline(packages, anotherTrash);
		if (anotherTrash.find(mod))
		{
			int number = 0;
			string package = "";
			string* install = new string[10];
			int position = anotherTrash.find(mod);
			if (position != std::string::npos)
			{
				int start = anotherTrash.find('[');
				while (anotherTrash[start] != ']')
				{
					if (useless(anotherTrash[start]))
					{
						install[number] = package;
						number++;
						start++;
					}
					else if (anotherTrash[start] == '"')
					{
						start++;
					}
					else package += anotherTrash[start];
					start++;
				}

			}
			if (number == 1)
			{
				cout << "In order to install" << mod << ", we need " << install[0] << "." << endl;
				cout << "Installing " << install[0] << endl;
				CreateFolder(("installed_modules/"+ install[0]).c_str());
				alreadyInstalled(install[0]);
				installModules(install[0]);
			}
			if (number > 1)
			{
				cout << "In order to install" << mod << ", we need" << install[0] << "and" << install[1] << "." << endl;
				cout << "Installing" << install[0] << endl;
				string temp = "installed_modules/" + install[0];
				CreateFolder(temp.c_str());
				alreadyInstalled(install[0]);
				installModules(install[0]);
				cout << "Installing" << install[1] << endl;
				temp = "installed_modules/" + install[1];
				CreateFolder(temp.c_str());
				alreadyInstalled(install[1]);
				installModules(install[1]);
			}
		}
	}
	packages.close();
}
int main()
{

	ifstream dependencies("dependencies.json", ios::in);
	if (!dependencies)
	{
		cout << "File couldn`t be opened." << endl;
		return 1;
	}

	string* deps = new string[100];
	int count = 0;
	string trash;
	string important="";
	while (!dependencies.eof())
	{
		if (dependencies)
		{
			getline(dependencies, trash);
			if (trash.find("dependencies"))
			{
				int found = trash.find("dependencies");
				if (found != std::string::npos)
				{
					int i = found + 15;
					while (trash[i] != ']')
					{
						if (useless(trash[i]))
						{
							deps[count] = important;
							count++;
							i++;
						}
						else{
							important += trash[i];
							i++;
						}
					}
					
				}
			}
		}
	}
	dependencies.close();


	for (int i = 0; i < count;i++)
	{
		installModules(deps[i]);
	}
	cout << "All done." << endl;
	return 0;
	}

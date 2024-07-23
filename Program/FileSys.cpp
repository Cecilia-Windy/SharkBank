#include "SharkInit.h"
#include <direct.h>
#include <Windows.h>
#include <fstream>
#include <io.h>
#include <iostream>
#include <cmath>

using std::string;

std::fstream File_System::User_File("Temp.txt");
string File_System::Path = "E:\\SharkBank\\"; //std::string Path = "C:\\Program Files\\SharkBank\\Data";

File_System::File_System()
{
	using std::endl;

	if ("Admin" == UserName || "Administrator" == UserName) { Bank_MS::Money = Bank_SS::shares = Bank_DCS::DC_Money = INFINITY; }
	else 
	{
		if (::_access(Path.c_str(), 0) == -1)bool flag = ::_mkdir(Path.c_str());
		if (::_access((Path + UserName).c_str(), 0) == -1)bool flag = ::_mkdir((Path + UserName).c_str());
		if (::_access((Path + UserName + "Msys.txt").c_str(), 0) == -1)
		{
			User_File.open(((Path + UserName + "\\") + UserName + "Msys.txt"), std::ios_base::out | std::ios_base::app);
			User_File << " 0.0";
			F_Flush();

			User_File.open(((Path + UserName + "\\") + UserName + "Ssys.txt"), std::ios_base::out | std::ios_base::app);
			User_File << " 0";
			F_Flush();

			User_File.open(((Path + UserName + "\\") + UserName + "DCsys.txt"), std::ios_base::out | std::ios_base::app);
			User_File << " 0.0";
			F_Flush();
		}
		F_Read("Msys", Bank_MS::Money);

		F_Read("Ssys", Bank_SS::shares);

		F_Read("DCsys", Bank_DCS::DC_Money);
	}
	
	std::cout << "Shark Init is Booting" << std::endl
		<< "Loading ... " << std::endl << std::endl;
}

File_System::~File_System(){ }

bool File_System::F_Write(string Sys,double s)
{
	using std::endl;

	User_File.open((Path + UserName + "\\") + UserName + Sys + ".txt", std::ios_base::out | std::ios_base::trunc);
	if (!User_File.is_open())
	{
		std::cerr << endl << "[SHARK]" << endl << "Coundn't open the file." << endl << "Exit." << endl;
		F_Flush();
		exit(EXIT_FAILURE);
	}
	else
	{
		User_File << s;
		F_Flush();
	}
	return true;
}

void File_System::F_Read(std::string Sys, double& Data)
{
    using std::endl;
	
	User_File.open((Path + UserName + "\\") + UserName + Sys + ".txt", std::ios_base::in);
	if (!User_File.is_open())
	{
		std::cerr << endl << "[SHARK]" << endl << "Coundn't open the file." << endl << "Exit." << endl;
		F_Flush();
		exit(EXIT_FAILURE);
	}
	else
	{
		User_File >> Data;
		F_Flush();
		User_File.open(((Path + UserName + "\\") + UserName + "Msys.txt"), std::ios_base::out | std::ios_base::trunc);
		F_Flush();
	}
}

void File_System::F_Read(std::string Sys, long long& Data)
{
    using std::endl;
	
	User_File.open((Path + UserName + "\\") + UserName + Sys + ".txt", std::ios_base::in);
	if (!User_File.is_open())
	{
		std::cerr << endl << "[SHARK]" << endl << "Coundn't open the file." << endl << "Exit." << endl;
		F_Flush();
		exit(EXIT_FAILURE);
	}
	else
	{
		User_File >> Data;
		F_Flush();
		User_File.open(((Path + UserName + "\\") + UserName + "Msys.txt"), std::ios_base::out | std::ios_base::trunc);
		F_Flush();
	}
}


inline void File_System::F_Flush()
{
	User_File.flush();
	User_File.close();
	User_File.clear();
}

#include "SharkInit.h"
#include <direct.h>
#include <Windows.h>
#include <fstream>
#include <io.h>
#include <iostream>
#include <cmath>

using std::string;

std::fstream File_System::User_File("Temp.dat");
struct File_System::Temp_DataD TDD { 0.0 }; //Temp Data (Double)
struct File_System::Temp_DataL TDL { 0 }; //Temp Data (Double)
string File_System::Path = "E:\\Data\\";

File_System::File_System()
{
	using std::endl;

	if ("Admin" == UserName || "Administrator" == UserName) { Bank_MSI::Money = Bank_SSI::shares = Bank_DCSI::DC_Money = INFINITY; }
	else 
	{
		if (::_access(Path.c_str(), 0) == -1)bool flag = ::_mkdir(Path.c_str());
		if (::_access((Path + UserName + "Msys.dat").c_str(), 0) == -1)
		{
			TDD.s = 0.0;
			TDL.s = 0.0;

			User_File.open((Path + UserName + "Msys.dat"), std::ios_base::out | std::ios_base::app | std::ios_base::binary);
			User_File.write((const char*)&TDD, sizeof(TDD));
			F_Flush();

			User_File.open((Path + UserName + "Ssys.dat"), std::ios_base::out | std::ios_base::app | std::ios_base::binary);
			User_File.write((const char*)&TDL, sizeof(TDL));
			F_Flush();

			User_File.open((Path + UserName + "DCsys.dat"), std::ios_base::out | std::ios_base::app | std::ios_base::binary);
			User_File.write((const char*)&TDD, sizeof(TDD));
			F_Flush();
		}
		Bank_MSI::Money = F_Read<double>("Msys");
		User_File.open((Path + UserName + "Msys.dat"), std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
		F_Flush();
		TDD.s = 0.0;

		Bank_SSI::shares = F_Read<long>("Ssys");
		User_File.open((Path + UserName + "Ssys.dat"), std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
		F_Flush();
		TDL.s = 0.0;

		Bank_DCSI::DC_Money = F_Read<double>("DCsys");
		User_File.open((Path + UserName + "DCsys.dat"), std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
		F_Flush();
		TDD.s = 0.0;
	}
	
	std::cout << "Shark Init is Booting" << std::endl
		<< "Loading ... " << std::endl << std::endl;
}

File_System::~File_System(){ }

bool File_System::F_Write(string Sys,double s_)
{
	using std::endl;

	TDD.s = s_;

	User_File.open(Path + UserName + Sys + ".dat", std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
	if (!User_File.is_open())
	{
		std::cerr << endl << "[SHARK]" << endl << "Coundn't open the file." << endl << "Exit." << endl;
		F_Flush();
		exit(EXIT_FAILURE);
	}
	else
	{
		User_File.write((const char*)&TDD, sizeof(TDD));
		F_Flush();
	}
	return true;
}
template <typename Anytype>
Anytype File_System::F_Read(string Sys)
{
	using std::endl;
	struct Temp_DataR{ Anytype s; }TD;
	
	User_File.open(Path + UserName + Sys + ".dat", std::ios_base::in | std::ios_base::binary);
	if (!User_File.is_open())
	{
		std::cerr << endl << "[SHARK]" << endl << "Coundn't open the file." << endl << "Exit." << endl;
		F_Flush();
		exit(EXIT_FAILURE);
	}
	else
	{
		User_File.write((const char*)&TD, sizeof(TD));
		F_Flush();
	}

	return TD.s;
}

inline void File_System::F_Flush()
{
	User_File.flush();
	User_File.close();
	User_File.clear();
}

#pragma once
#include <string>
#include <cstdio>
#include <string>

#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <string>
#include <iostream>
#include <Wininet.h>
#include <wininet.h>
#include <string>
#pragma comment(lib, "wininet.lib")

using namespace std;


namespace Login
{

	std::string replaceAll2(std::string subject, const std::string& search, const std::string& replace);
	string DownloadString2(string URL);
	string hwid();
}
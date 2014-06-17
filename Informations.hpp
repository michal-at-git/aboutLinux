#include <string>
#include <fstream>
#include <iostream>
#include <sys/utsname.h>
#include <regex>

	using std::string;

class Informations {
private:
	string distName;
	string distVer;
	string kernel;
	string platform;
	
	
public:
	Informations() {

		this->genDataFromUname();
		this->genDataFromOsRelease();
// 		sysInfo.
	}
	
	string getKernelVer() {
		return this->kernel;
	}

	string getPlatform(){
		return this->platform;
	}
	string getDistVer() {
		return this->distVer;
	}
	string getDistName() {
		return this->distName;
	}
	
private:
	void genDataFromUname() {
		
		struct utsname sysInfo;
		
		
		uname(&sysInfo);
		
		this->kernel = sysInfo.release;
		this->platform = sysInfo.machine;
	}
	
	void genDataFromOsRelease() {
		string strBuffer;
		
		std::fstream os_release;
		
		os_release.open("/etc/os-release", std::ios::in);
		std::regex name("(NAME)(.*)");
		std::regex version("(VERSION=)(.*)");
		
		
		if(os_release.good()) 
			while(std::getline(os_release, strBuffer)) {
				if(std::regex_match(strBuffer, name)) {					
					this->distName = strBuffer.substr(6, (strBuffer.size()-6)-1);
				}
				else if(std::regex_match(strBuffer, version)) {
					this->distVer = strBuffer.substr(9, ((strBuffer.size()-9)-1));
				}
			}
		else 
			std::cerr << "Error while opening /etc/os-release";
		
		os_release.close();	
		
		
		
		
		
		
	}
};

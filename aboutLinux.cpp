#include "Window.hpp" 
#include "Informations.hpp"
#include "Console.hpp"

int main(int argc, char * argv[]) {
  
  Informations aboutLinux;
  QString kernel = QString::fromStdString(aboutLinux.getKernelVer());
  QString platform = QString::fromStdString(aboutLinux.getPlatform());
  QString osName = QString::fromStdString(aboutLinux.getDistName());
  QString osVer = QString::fromStdString(aboutLinux.getDistVer());
  
  if(argc > 1 && !strcmp(argv[1],"-t")) {

    Console::display(kernel, platform, osName, osVer);
    
  } else {
	
	DataStruct inf();
	
	
	DataStruct str(kernel, platform, osName, osVer);
	
  	QApplication app(argc, argv); 
   	Window gui(str);
  	return app.exec();
  }	
}

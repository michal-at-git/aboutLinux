#include <QTextStream>
#include <QString>


class Console {


public:
  static void display(QString kernel, QString platform, QString osName, QString osVer) {
      QTextStream cout(stdout);
      
      const QString bgwhite = "\e[107m";

    
      const QString green = "\e[32m";
      const QString white = "\e[97m";
      const QString black = "\e[30m";
      
      
      const QString underline = "\e[4m";  
      const QString bold = "\e[1m";
      const QString reset =  "\e[m";
      cout << bgwhite << black << bold << "Informations about your Linux distribution " << reset << endl;
      cout << white << bold << "Distribution: " << reset << white << osName << endl;
      cout << white << bold << "Version: " << reset << white << osVer << reset << endl;
      cout << white << bold << "Kernel: " << reset << white << kernel << reset << endl;
      cout << white << bold << "Platform: " << reset << white << platform << reset << endl;
  }
};

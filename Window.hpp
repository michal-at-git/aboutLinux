#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QtCore>
#include <QtGui>

class DataStruct {
public:
	QString kernel;
	QString platform;
	QString osName;
	QString osVer;
	
	DataStruct() {
		
	}
	
	DataStruct(QString kernel, QString platform, QString osName, QString osVer) {
		this->kernel = kernel;
		this->platform = platform;
		this->osName = osName;
		this->osVer = osVer;		
	}
};

class Window : public QObject {
	
	
public:
 QWidget	mainWindow;
 QTextBrowser *mainTextBrowser;
 QPushButton *closeButton;
 
 Window(DataStruct distro) {
	QVBoxLayout mainLayout;
	mainTextBrowser = new QTextBrowser();
	closeButton = new QPushButton("Close");
	QString mainText = "<h1>";
	mainText.append(distro.osName);
	mainText.append("</h1>");
	
	mainText.append("<p><b>Version:</b> ");
	mainText.append(distro.osVer);
	mainText.append("</p>");
	
	mainText.append("<p><b>Kernel version:</b> ");
	mainText.append(distro.kernel);
	mainText.append("</p>");
	
	mainText.append("<p><b>Platform:</b> ");
	mainText.append(distro.platform);
	mainText.append("</p>");
	mainTextBrowser->setText(mainText);
	
	closeButton->setFixedSize(100, 30);
	mainLayout.addWidget(mainTextBrowser);

	mainLayout.addWidget(closeButton, 0, Qt::AlignRight);
	mainWindow.setLayout(&mainLayout);
	mainWindow.setWindowTitle("Informations about your Linux distribution");
	mainWindow.setFixedSize(800,500);
	
	
	//signals
	
	mainWindow.connect(closeButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	
	mainWindow.show();
 }
};

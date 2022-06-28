#include "main_window.hpp"
#include <QApplication>
#include <QDebug>
#include <string>
using std::string;
int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	MainWindow w;
	w.show();

	return QApplication::exec();
}

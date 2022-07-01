#pragma once
#include "button_panel.hpp"
#include "message_widget.hpp"
#include "repl_widget.hpp"
#include <QDebug>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QWidget>
#include <fstream>
#include <string>
using std::string;
constexpr int WIDTH = 500;
constexpr int HEIGHT = 350;
class MainWindow: public QWidget {
	Q_OBJECT
  public:
	MainWindow(QWidget *parent = nullptr) {
		setFixedSize(HEIGHT, WIDTH);
		view = new QMenu("View");
		edit = new QMenu("Edit");
		help = new QMenu("Help");
		menuBar = new QMenuBar;
		menuBar->addMenu(view);
		menuBar->addMenu(edit);
		menuBar->addMenu(help);
		menuBar->setFixedHeight(30);

		layout = new QGridLayout;
		result_box = new QLineEdit(" ");
		result_box->setFixedHeight(100);
		buttonpanel = new ButtonPanel(this);
		buttonpanel->setFixedHeight((HEIGHT - menuBar->height() - result_box->height()));

		layout->addWidget(menuBar, 0, 0, 1, 6);
		layout->addWidget(result_box, 1, 0, 1, 6);
		layout->addWidget(buttonpanel, 2, 0, 1, 6);
		setStyleSheet("background-color: #d6e3f2;");
		setLayout(layout);

		result_box->setReadOnly(true);
		result_box->setStyleSheet("background-color: #FFFFFF;");
		result_box->setAlignment(Qt::AlignRight);
		//increase the font size of the result box
		result_box->setFont(QFont("Arial", 20));
		//QObject::connect(interpreter, SIGNAL(drawGraphic(QGraphicsItem *)), canvas_widget, SLOT(addGraphic(QGraphicsItem *)));
	}
	static QString setButtonText(int i) {
		if (i == 0) {
			return "MC";
		}
		if (i == 1) {
			return "MR";
		}
		if (i == 2) {
			return "MS";
		}
		if (i == 3) {
			return "M+";
		}
		if (i == 4) {
			return "M-";
		}
		if (i == 5) {
			return "<--";
		}
		if (i == 6) {
			return "CE";
		}
		if (i == 7) {
			return "C";
		}
		if (i == 8) {
			return "+-";
		}
		if (i == 9) {
			return "sqrt";
		}
		if (i == 10) {
			return "7";
		}
		if (i == 11) {
			return "8";
		}
		if (i == 12) {
			return "9";
		}
		if (i == 13) {
			return "/";
		}
		if (i == 14) {
			return "%";
		}
		if (i == 15) {
			return "4";
		}
		if (i == 16) {
			return "5";
		}
		if (i == 17) {
			return "6";
		}
		if (i == 18) {
			return "*";
		}
		if (i == 19) {
			return "1/x";
		}
		if (i == 20) {
			return "1";
		}
		if (i == 21) {
			return "2";
		}
		if (i == 22) {
			return "3";
		}
		if (i == 23) {
			return "-";
		}
		if (i == 24) {
			return "=";
		}
		if (i == 25) {
			return "0";
		}
		if (i == 26) {
			return "0";
		}
		if (i == 27) {
			return ".";
		}
		if (i == 28) {
			return "+";
		}
		if (i == 29) {
			return "=";
		}
		if (i == 30) {
			return ")";
		}
		return "error";
	}

	/*signals:
	void message(QString message);*/
  public slots:
	void on_button_clicked(int i) {
		if (i >= 9 && i <= 26) {
			result_box->setText(result_box->text() + ButtonPanel::setButtonText(i));
		}
	}

  private:
	QGridLayout *layout;
	QMenuBar *menuBar;
	QMenu *view;
	QMenu *edit;
	QMenu *help;
	ButtonPanel *buttonpanel;
	QLineEdit *result_box;
	double memory = 0;
	//MessageWidget *message_widget;
};
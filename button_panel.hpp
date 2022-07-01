#pragma once
#include <iostream>
#include <QGridLayout>
#include <QMenuBar>
#include <QPushButton>

class ButtonPanel: public QWidget {
  public:
	ButtonPanel(QWidget *parent = nullptr) {
		layout = new QGridLayout;
		setStyleSheet("background-color: #d6e3f2;");

		for (int i = 0; i < 28; i++) {
			buttons[i] = new QPushButton(setButtonText(i));
			buttons[i]->setStyleSheet("background-color: #ecf7f7;");
			if (i == 24) layout->addWidget(buttons[24], 6, 0, 1, 2);
			else if (i == 25) layout->addWidget(buttons[25], 6, 2);
			else if (i == 26) layout->addWidget(buttons[26], 6, 3);
			else if (i == 27) layout->addWidget(buttons[27], 5, 4, 2, 1);
			else layout->addWidget(buttons[i], i / 5, i % 5);
			//connect(button, &QPushButton::clicked, this, &MainWindow::button_clicked);
		}
		setLayout(layout);

		//when a button is pressed, emit a signal with the button's index
		for (int i = 0; i < 28; i++) {
			connect(buttons[i], &QPushButton::clicked, this, &ButtonPanel::button_clicked);
		}


		//QObject::connect(interpreter, SIGNAL(drawGraphic(QGraphicsItem *)), canvas_widget, SLOT(addGraphic(QGraphicsItem *)));
	}
	static QString setButtonText(int i) {
		if (i == 0) return "MC";
		if (i == 1) return "MR";
		if (i == 2) return "MS";
		if (i == 3) return "M+";
		if (i == 4) return "M-";
		if (i == 5) return "<--";
		if (i == 6) return "CE";
		if (i == 7) return "C";
		if (i == 8) return "+-";
		if (i == 9) return "sqrt";
		if (i == 10) return "7";
		if (i == 11) return "8";
		if (i == 12) return "9";
		if (i == 13) return "/";
		if (i == 14) return "%";
		if (i == 15) return "4";
		if (i == 16) return "5";
		if (i == 17) return "6";
		if (i == 18) return "*";
		if (i == 19) return "1/x";
		if (i == 20) return "1";
		if (i == 21) return "2";
		if (i == 22) return "3";
		if (i == 23) return "-";
		if (i == 24) return "0";
		if (i == 25) return ".";
		if (i == 26) return "+";
		if (i == 27) return "=";
		return "error";
	}

	/*signals:
	void message(QString message);*/

  private:
	QGridLayout *layout = nullptr;
	QPushButton *buttons[28];
};
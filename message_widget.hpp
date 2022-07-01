#pragma once
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPalette>
#include <QString>
#include <QWidget>
class QLineEdit;

class MessageWidget: public QWidget {
	Q_OBJECT
  public:
	MessageWidget(QWidget *parent = nullptr):
		QWidget(parent) {
		m_messageLineEdit = new QLineEdit(" ");
		m_messageLineEdit->setReadOnly(true);

		layout = new QHBoxLayout;
		layout->addWidget(m_messageLineEdit);
		setLayout(layout);
		setStyleSheet("background-color: #FFFFFF;");
	}

  public slots:
	void info(const QString &message) {
		m_messageLineEdit->setText(message);
	}

  private:
	QLineEdit *m_messageLineEdit;
	QHBoxLayout *layout;
};

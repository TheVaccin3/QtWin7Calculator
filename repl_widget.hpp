#pragma once

//#include <QDebug>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QWidget>

class REPLWidget: public QWidget {
	Q_OBJECT
  public:
	REPLWidget(QWidget *parent = nullptr):
		QWidget(parent) {
		realLabel = new QLabel("slisp> ");
		m_REPL_input = new QLineEdit();
		layout = new QHBoxLayout;
		layout->addWidget(realLabel);
		layout->addWidget(m_REPL_input);
		setLayout(layout);
		//QObject::connect(m_REPL_input, SIGNAL(textEdited(const QString)), this, SLOT(changed()));
	}

  protected:
	void keyPressEvent(QKeyEvent *e) override {
		//if (e->key() == Qt::Key::Key_Return) {
		//	if (!m_REPL_input->text().isEmpty()) {
		//		history.insert(history.begin() + 1, m_REPL_input->text());
		//		history_index = history.begin();
		//		lineEntered(m_REPL_input->text());
		//		m_REPL_input->clear();
		//	}
		//} else if (e->key() == Qt::Key::Key_Up) {
		//	if (history_index != history.end() - 1) { history_index++; }
		//	m_REPL_input->setText(*history_index);
		//} else if (e->key() == Qt::Key::Key_Down) {
		//	if (history_index != history.begin()) { history_index--; }
		//	m_REPL_input->setText(*history_index);
		//}

		QWidget::keyPressEvent(e);
	}
  signals:
	void lineEntered(QString entry);

  //private slots:
	//void changed() { history_index = history.begin(); }

  private:
	QLineEdit *m_REPL_input;
	QLabel *realLabel;
	QHBoxLayout *layout;
};

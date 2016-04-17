#ifndef _xfs_Example_h_
#define _xfs_Example_h_

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

#include <QtGui/QPixmap>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QStyle>

class TitleBar : public QWidget
{
	Q_OBJECT
public:
	TitleBar( QWidget *parent );
	

public slots:
	void showSmall();
	
	void showMaxRestore();

protected:
	void mousePressEvent( QMouseEvent *me );

	void mouseMoveEvent( QMouseEvent *me );


private:
	QToolButton *minimize;
	QToolButton *maximize;
	QToolButton *close;
	QPixmap restorePix, maxPix;
	bool maxNormal;
	QPoint startPos;
	QPoint clickPos;
};

class Frame : public QFrame
{
public:

	Frame();

	// Allows you to access the content area of the frame
	// where widgets and layouts can be added
	QWidget *contentWidget() const;

	TitleBar *titleBar() const;

	void mousePressEvent( QMouseEvent *e );


	void mouseMoveEvent( QMouseEvent *e );
	

	void mouseReleaseEvent( QMouseEvent *e );
	
private:
	TitleBar *m_titleBar;
	QWidget *m_content;
	QPoint m_old_pos;
	bool m_mouse_down;
	bool left, right, bottom;
};






#endif

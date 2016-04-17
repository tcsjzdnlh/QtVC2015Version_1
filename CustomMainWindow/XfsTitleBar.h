#ifndef _xfs_XfsTitleBar_h_
#define _xfs_XfsTitleBar_h_

#include <QtWidgets/QWidget>
class QToolButton;
class QLabel;
class QHBoxLayout;

class CXfsTitleBar : public QWidget
{
	Q_OBJECT
public:
	CXfsTitleBar( QWidget *_pParent = nullptr );

	void Init();

	void SetWindowTitle( const QString &_title );

public slots:
	void ShowMax();

private:	
	QToolButton		*m_pAppIcon;
	
	QLabel			*m_pTitle;

	QToolButton		*m_pMin;
	QToolButton		*m_pMax;
	QToolButton		*m_pClose;

	QHBoxLayout		*m_pLay_0;

	QWidget			*m_pParentWidget;
};


#endif
#ifndef _xfs_WACP_h_
#define _xfs_WACP_h_

#include <QtWidgets/QWidget>

class QCheckBox;
class QRadioButton;
class QGroupBox;
class QSpinBox;
class QPushButton;

class CWACP : public QWidget
{
	Q_OBJECT
public:
	CWACP( QWidget *_pParent = nullptr );
	
	void Init();

private:
	QWidget			*m_pBeWatchedWnd;
	// widget type
	QGroupBox		*m_pWindowFlagsGrpBx;

	// geometry

};


#endif
#ifndef _xfs_BWW_h_
#define _xfs_BWW_h_

#include <QtWidgets/QWidget>
class QVBoxLayout;

class CBWW : public QWidget
{
	Q_OBJECT
public:
	CBWW( QWidget *_pParent = nullptr );

	void Init();

private:
	QVBoxLayout			*m_pLay_0;
};


#endif
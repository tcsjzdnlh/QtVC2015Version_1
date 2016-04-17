#ifndef _xfs_XfsMainWindow_h_
#define _xfs_XfsMainWindow_h_

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>

class QPixmap;
class CXfsTitleBar;
class QVBoxLayout;

class CXfsMainWindow : public QFrame
{
	Q_OBJECT
public:
	CXfsMainWindow( QWidget *_pParent = nullptr );

	void Init();

	QWidget *GetClient() const;
protected:
	//void paintEvent( QPaintEvent *_e ) override;

private:
	QPixmap			*m_pBackground;

	CXfsTitleBar	*m_pTitleBar;
	QWidget			*m_pClient;
	QVBoxLayout		*m_pLay_0;
};


#endif
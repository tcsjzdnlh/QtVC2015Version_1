#include "XfsMainWindow.h"
#include "moc_XfsMainWindow.cpp"
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include "XfsTitleBar.h"
#include <QtWidgets/QVBoxLayout>

CXfsMainWindow::CXfsMainWindow( QWidget *_pParent /*= nullptr */ )
	:QFrame(_pParent)
{
	Init();
}

void CXfsMainWindow::Init()
{
	m_pBackground = new QPixmap;
	m_pBackground->load( "./images/background.jpg" );

	
	setFrameShape( Panel );
	setMouseTracking( true );
	
	// title bar, client
	m_pTitleBar = new CXfsTitleBar( this );
	m_pClient = new QWidget;

	m_pLay_0 = new QVBoxLayout;
	m_pLay_0->addWidget( m_pTitleBar );
	m_pLay_0->setMargin( 0 );
	m_pLay_0->setSpacing( 0 );
	

	QVBoxLayout *pLay_1_0 = new QVBoxLayout;
	pLay_1_0->addWidget( m_pClient );
	pLay_1_0->setMargin( 5 );
	pLay_1_0->setSpacing( 0 );


	m_pLay_0->addLayout( pLay_1_0 );


	setLayout( m_pLay_0 );
}

QWidget * CXfsMainWindow::GetClient() const
{
	return m_pClient;
}

//void CXfsMainWindow::paintEvent( QPaintEvent * _e )
//{
//	QMainWindow::paintEvent( _e );
//
//	QPainter painter( this );
//	painter.drawTiledPixmap( rect(), *m_pBackground );
//}

#include "XfsTitleBar.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QStyle>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QApplication>
#include "moc_XfsTitleBar.cpp"
#include <QtGui/QPixmap>

CXfsTitleBar::CXfsTitleBar( QWidget *_pParent /*= nullptr */ )
	:QWidget(_pParent), m_pParentWidget( _pParent )
{
	Init();
}

void CXfsTitleBar::Init()
{
	m_pAppIcon = new QToolButton;
	
	m_pTitle = new QLabel;
	
	m_pMin = new QToolButton;
	m_pMax = new QToolButton;
	m_pClose = new QToolButton;

	m_pAppIcon->setIcon( style()->standardPixmap( QStyle::SP_DesktopIcon ) );
	
	m_pMin->setIcon( style()->standardPixmap( QStyle::SP_TitleBarMinButton ) );
	m_pMax->setIcon( style()->standardPixmap( QStyle::SP_TitleBarMaxButton ) );
	m_pClose->setIcon( style()->standardPixmap( QStyle::SP_TitleBarCloseButton ) );

	m_pClose->setMinimumHeight( 20 );
	m_pMax->setMinimumHeight( 20 );
	m_pMin->setMinimumHeight( 20 );

	m_pLay_0 = new QHBoxLayout;
	m_pLay_0->addWidget( m_pAppIcon );
	m_pLay_0->addWidget( m_pTitle );	
	m_pLay_0->addWidget( m_pMin );
	m_pLay_0->addWidget( m_pMax );
	m_pLay_0->addWidget( m_pClose );

	m_pLay_0->insertStretch( 2, 500 );
	m_pLay_0->setSpacing( 0 );
	
	
	setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );


	if( !parentWidget() )
	{
		setWindowFlags( Qt::FramelessWindowHint );

		connect( m_pClose, SIGNAL( clicked() ), qApp, SLOT( quit() ) );

		m_pMin->setEnabled( false );
		m_pMax->setEnabled( false );
	}
	else
	{
		connect( m_pClose, SIGNAL( clicked() ), m_pParentWidget, SLOT( close() ) );
		connect( m_pMin, SIGNAL( clicked() ), m_pParentWidget, SLOT( showMinimized() ) );
		connect( m_pMax, SIGNAL( clicked() ), this, SLOT( ShowMax() ) );
	}
	
	SetWindowTitle( "custom title bar" );

	setAutoFillBackground( true );
	setBackgroundRole( QPalette::Highlight );

	setLayout( m_pLay_0 );

	
}

void CXfsTitleBar::SetWindowTitle( const QString & _title )
{
	//QWidget *pParent = qobject_cast< QWidget* >( parent() );

	QWidget *pParent = parentWidget();

	if( pParent )
	{
		pParent->setWindowTitle( _title );		
	}
	
	m_pTitle->setText( _title );

}

void CXfsTitleBar::ShowMax()
{
	if( m_pParentWidget->isMaximized() )
	{
		m_pParentWidget->showNormal();
		m_pMax->setIcon( style()->standardPixmap( QStyle::SP_TitleBarMaxButton ) );
	}
	else
	{
		m_pParentWidget->showMaximized();
		m_pMax->setIcon( style()->standardPixmap( QStyle::SP_TitleBarNormalButton ) );
	}
}

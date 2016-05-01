#include "XfsLogger.h"
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QApplication>
#include "moc_XfsLogger.cpp"

CXfsLogger::CXfsLogger( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	Init();
}

void CXfsLogger::Init()
{	
	m_pRecorder = new QTextEdit;

	QVBoxLayout *pLay_0 = new QVBoxLayout;
	pLay_0->addWidget( m_pRecorder );
	
	setLayout( pLay_0 );

	setWindowTitle( "XfsLogger" );
	
	setGeometry( 0, 30, 300, 600 );
	//setGeometry( 50, 50, 300, 600 );
	//move( 0, 0 );
	

	connect( this, SIGNAL( CloseApp() ), qApp, SLOT( quit() ) );
}

void CXfsLogger::Log( const QString & _txt )
{
	m_strContents += _txt;

	if( !m_strContents.isEmpty() )
	{
		if( !m_strContents.endsWith("\n") )
		{
			m_strContents += "\n";
			m_pRecorder->setText( m_strContents );
		}
	}
}

void CXfsLogger::closeEvent( QCloseEvent * _e )
{
	QWidget::closeEvent( _e );
	emit CloseApp();
}

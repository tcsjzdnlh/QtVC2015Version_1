#include "BWW.h"
#include "moc_BWW.cpp"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>

CBWW::CBWW( QWidget *_pParent /*= nullptr */ )
	/*:QWidget( _pParent, Qt::WindowType::Sheet )*/
	/*:QWidget( _pParent, Qt::WindowType::Drawer )*/
	/*:QWidget( _pParent, Qt::WindowType::Popup )*/
	//:QWidget( _pParent, Qt::WindowType::Desktop )
	:QWidget( _pParent, Qt::WindowType::Window )

{
	Init();
}

void CBWW::Init()
{
	////QTextEdit *pW = new QTextEdit;
	//QWidget *pW = new QWidget( nullptr, /*this,*/ /* windowFlags() |*/ Qt::WindowType::Dialog );
	//
	////pW->setWindowFlags( Qt::WindowType::Dialog );
	////pW->setWindowModality( Qt::WindowModality::WindowModal );
	////pW->setWindowModality( Qt::WindowModality::ApplicationModal );


	//pW->raise();
	////pW->lower();
	//QPalette refPalette = pW->palette();
	////refPalette.setBrush( QPalette::Window, Qt::yellow );
	//refPalette.setColor( QPalette::Window, Qt::darkBlue );
	//pW->setPalette( refPalette );
	//pW->setAutoFillBackground( true );

	//pW->show();


	// -----------------------------
	//QWidget *pW = new QWidget( this );
	//
	////pW->setWindowFlags( Qt::WindowType::Dialog );
	////pW->setWindowModality( Qt::WindowModality::WindowModal );
	//pW->setWindowModality( Qt::WindowModality::ApplicationModal );


	//QPalette refPalette = pW->palette();
	//refPalette.setColor( QPalette::Window, Qt::darkBlue );
	//pW->setPalette( refPalette );
	//pW->setAutoFillBackground( true );

	//QTextEdit *pText = new QTextEdit( pW );
	////pText->move( 100, 100 );


	// ----------
	//QWidget *pW = new QWidget( nullptr, Qt::WindowType::Sheet );
	//pW->setWindowTitle( "sheet" );
	//pW->show();

	// ------------
	//QWidget *pW = new QWidget;
	//pW->setWindowTitle( "modality window" );
	//pW->setWindowModality( Qt::WindowModality::ApplicationModal );
	//pW->show();

	// --------------
	//QDialog *pDlg = new QDialog;
	//pDlg->setWindowTitle( "dialog" );
	//pDlg->open();


	// ---------------
	//QWidget *pW = new QWidget(nullptr, Qt::WindowType::Drawer);
	//pW->setWindowTitle( "drawer" );
	//pW->show();

	// ---------------
	//QWidget *pW = new QWidget(dynamic_cast<QWidget*>( QApplication::desktop() ), Qt::WindowType::Popup );
	//pW->setWindowTitle( "popup" );
	//pW->show();

	// ---------------
	//QWidget *pW = new QWidget( /*this*/ nullptr, 
	//						   Qt::WindowType::Tool /*| Qt::WindowStaysOnTopHint*/ | Qt::FramelessWindowHint );	
	//pW->setWindowTitle( "tool" );
	//pW->show();


	//setAttribute( Qt::WidgetAttribute::WA_MacAlwaysShowToolWindow );
	//QWidget *pW = new QWidget( this,
	//						   Qt::WindowType::Tool /*| Qt::WindowStaysOnTopHint*/ /*| Qt::FramelessWindowHint*/ );
	//pW->setWindowTitle( "tool" );
	//pW->show();


	// ---------------
	//QWidget *pW = new QWidget( nullptr, Qt::WindowType::ToolTip );
	//pW->setWindowTitle( "tooltip" );
	//pW->show();

	// ----------
	//QTextEdit *pText = new QTextEdit(this);



	//m_pLay_0 = new QVBoxLayout;
	//m_pLay_0->addWidget( pW );
	//m_pLay_0->addWidget( pText );
	
	
	//setLayout( m_pLay_0 );


	//pW->exec();
	//W->
}

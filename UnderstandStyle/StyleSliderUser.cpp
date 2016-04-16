#include "StyleSliderUser.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QSlider>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QStyle>
#include "ArthurStyle.h"
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QPushButton>
#include <QtCore/QList>
#include <QtWidgets/QProxyStyle>
#include <QtWidgets/QCommonStyle>
#include <QtWidgets/QCheckBox>

#include "StyleSlider.h"
#include "moc_StyleSliderUser.cpp"

CStyleSliderUser::CStyleSliderUser( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{
	Init();
}

void CStyleSliderUser::Init()
{	
	//m_pStyle = new QProxyStyle( "windows" );
	//m_pStyle = new QCommonStyle;
	//m_pStyle = new ArthurStyle;
	m_pStyle = new CStyleSlider;
	
	m_pVolume = new QSlider;
	m_pVolume->setOrientation( Qt::Orientation::Horizontal );
	m_pVolume->setStyle( m_pStyle );
	
	InitGroupBox();
	

	m_pLay_0 = new QVBoxLayout;
	m_pLay_0->addWidget( m_pVolume );
	m_pLay_0->addWidget( m_pDownloadGBx );


	setLayout( m_pLay_0 );
	resize( 500, 400 );
}

void CStyleSliderUser::InitGroupBox()
{
	m_pDownloadGBx = new QGroupBox;
	//m_pDownloadGBx->setCheckable( true );
	//m_pDownloadGBx->setTitle( "" );
	m_pDownloadGBx->setTitle( "download" );

	
	
	QRadioButton *pRBtn_1 = new QRadioButton;
	pRBtn_1->setText( "first" );

	QRadioButton *pRBtn_2 = new QRadioButton;
	pRBtn_2->setText( "second" );

	QPushButton *pPushBtn_1 = new QPushButton;
	pPushBtn_1->setText( "hello" );

	QCheckBox *pCBox = new QCheckBox;

	QVBoxLayout *pLay_1_0 = new QVBoxLayout;
	pLay_1_0->addWidget( pRBtn_1 );
	pLay_1_0->addWidget( pRBtn_2 );
	pLay_1_0->addWidget( pPushBtn_1 );
	pLay_1_0->addWidget( pCBox );

	m_pDownloadGBx->setLayout( pLay_1_0 );

	m_pDownloadGBx->setStyle( m_pStyle );

	QList<QWidget*> lstWidget = m_pDownloadGBx->findChildren<QWidget*>();
	for( auto pWidget : lstWidget )
	{
		pWidget->setStyle( m_pStyle );
	}

}

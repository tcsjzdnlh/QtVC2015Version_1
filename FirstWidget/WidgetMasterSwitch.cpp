#include "WidgetMasterSwitch.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtCore/QMetaEnum>
#include <QtWidgets/QGroupBox>
#include "moc_WidgetMasterSwitch.cpp"
#include "XfsLogger.h"


extern CXfsLogger *g_pLogger;

CWidgetMasterSwitch::CWidgetMasterSwitch( QWidget *_pParent /*= nullptr */ )
	:QWidget( _pParent )
{

}

void CWidgetMasterSwitch::Init( QWidget *_pBWW )
{
	m_pBWW = _pBWW;

	constexpr uint uiBtns = EControlBtns::eNativeAndAlienWidget + 1;

	QMetaEnum meBtns = QMetaEnum::fromType<EControlBtns>();

	m_pLay_0 = new QGridLayout( this );

	for( int i = 0; i < uiBtns; ++i )
	{
		m_pSwitchBtns[i] = new QPushButton( meBtns.valueToKey( i ) );
		connect( m_pSwitchBtns[i], SIGNAL( clicked() ), this, SLOT( BtnClicked() ) );

		uint uiRow = i / 4;
		uint uiColumn = i % 4;
		m_pLay_0->addWidget( m_pSwitchBtns[i], uiRow, uiColumn );
	}
}

QSize CWidgetMasterSwitch::sizeHint() const
{
	return QSize(600, 400);
}

void CWidgetMasterSwitch::BtnClicked()
{
	QPushButton *pBtn = qobject_cast< QPushButton* >( sender() );
	g_pLogger->Log( QString( "clicked button : %1" ).arg( pBtn->text() ) );
}

#include "Book.h"
#include "moc_Book.cpp"
#include "XfsLogger.h"

#include <QtCore/QMetaEnum>

extern CXfsLogger *g_pLogger;

void test_qt_core::q_enum_macro::test()
{
	CBook yuwen;

	QMetaEnum meDays = QMetaEnum::fromType<CBook::EDays>();

	g_pLogger->Log( QString( "enum scope is: %1" ).arg( meDays.scope() ) );
	g_pLogger->Log( QString( "enum name : %1" ).arg( meDays.name() ) );
	g_pLogger->Log( meDays.isFlag() ? "enum is flag" : "enum is'nt flag" );
	g_pLogger->Log( QString( "enum key number : %1" ).arg( QString::number( meDays.keyCount() ) ) );



	for( int i = 0; i < meDays.keyCount(); ++i )
	{
		g_pLogger->Log( QString( "index %1, key is : %2, value is: %3" )
						.arg( i ).arg( meDays.key( i ) ).arg(meDays.value(i) ));
		//g_pLogger->Log(QString("value"))
	}
}

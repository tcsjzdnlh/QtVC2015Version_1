#include "WinVistaStyle.h"

CWinVistaStyle::CWinVistaStyle( QStyle * _pStyle )
	:QProxyStyle(_pStyle)
{
}

CWinVistaStyle::CWinVistaStyle( const QString & _key )
	:QProxyStyle(_key)
{
}

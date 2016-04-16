#ifndef _xfs_WinVistaStyle_h_
#define _xfs_WinVistaStyle_h_

#include <QtWidgets/QProxyStyle>
#include <QtWidgets/QStyleFactory>

class CWinVistaStyle : public QProxyStyle
{
public:
	CWinVistaStyle( QStyle *_pStyle = nullptr );
	CWinVistaStyle( const QString &_key );
};



#endif

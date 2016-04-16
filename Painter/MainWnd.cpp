#include "MainWnd.h"
#include "moc_MainWnd.cpp"
#include <QtGui/QPainterPath>
#include <QtGui/QPainter>
#include <QtGui/QPen>


CMainWnd::CMainWnd( QWidget *_pParent )
	:QWidget(_pParent)
{
	InitPainterPath();
}

void CMainWnd::InitPainterPath()
{		
	m_pPath = new QPainterPath;
	
	//DrawCubicBezierCurves();
	DrawAnything();
}

void CMainWnd::DrawCubicBezierCurves()
{
	m_pPath->addRect( 20, 20, 60, 60 );
	m_pPath->moveTo( 0, 0 );
	m_pPath->cubicTo( 99, 0, 50, 50, 99, 99 );
	m_pPath->cubicTo( 0, 99, 50, 50, 0, 0 );
}

void CMainWnd::DrawAnything()
{
	m_pPath->cubicTo( 50, 50, 300, 25, 200, 200 );
}

void CMainWnd::paintEvent( QPaintEvent * _e )
{
	QPainter painter( this );
	//painter.setRenderHint( QPainter::Antialiasing, true );
	painter.fillRect( 0, 0, 100, 100, Qt::white );

	painter.setPen( QPen( QColor( 79, 106, 25 ), 1,
						  Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin ) );

	painter.setBrush( QColor( 122, 163, 39 ) );
	
	painter.drawPath( *m_pPath );

}

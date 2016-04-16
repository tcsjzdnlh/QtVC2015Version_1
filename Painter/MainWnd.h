#ifndef _xfs_MainWnd_h_
#define _xfs_MainWnd_h_

#include <QtWidgets/QWidget>

class QPainterPath;

class CMainWnd : public QWidget
{
	Q_OBJECT
public:
	CMainWnd( QWidget *_pParent = nullptr );

private:
	void InitPainterPath();
	void DrawCubicBezierCurves();
	void DrawAnything();

protected:
	void paintEvent( QPaintEvent *_e ) override;

private:
	QPainterPath		*m_pPath;
};



#endif

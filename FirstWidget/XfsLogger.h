#ifndef _xfs_XfsLogger_h_
#define _xfs_XfsLogger_h_

#include <QtWidgets/QWidget>

class QString;
class QTextEdit;

class CXfsLogger : public QWidget
{
	Q_OBJECT
public:
	CXfsLogger( QWidget *_pParent = nullptr );
	void Init();

	void Log( const QString &_txt );

signals:
	void CloseApp();
protected:
	void closeEvent( QCloseEvent *_e ) override;

private:
	QTextEdit		*m_pRecorder;
	QString			m_strContents;
};


#endif
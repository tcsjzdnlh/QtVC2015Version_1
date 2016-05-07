#ifndef _xfs_WidgetMasterSwitch_h_
#define _xfs_WidgetMasterSwitch_h_

#include <QtWidgets/QWidget>
class QPushButton;
class QGridLayout;
class QGroupBox;

class CWidgetMasterSwitch : public QWidget
{
	Q_OBJECT
public:
	CWidgetMasterSwitch( QWidget *_pParent = nullptr );

	void Init( QWidget *_pBWW );

public:
	QSize sizeHint() const override;

public slots:
	void BtnClicked();

public:
	enum EControlBtns
	{
		eWTHA = 0,							// widget type/hint/attribute
		eWidgetChildAndLevel,				// widget level and child widget											
		eComposite,
		eCustomWidgetAndPainting,
		eHintAndSizePolicy,
		eGeometry,
		eEvent,
		eStyle,
		eTransParencyAndDoubleBuffering,
		eCreateTranslucentWidget,
		eNativeAndAlienWidget,
	};
	Q_ENUM(EControlBtns)

private:
	// be watched widget
	QWidget				*m_pBWW;
	QWidget				*m_pBWWChild;

	QGridLayout			*m_pLay_0;

	QPushButton			*m_pSwitchBtns[eNativeAndAlienWidget + 1];
	// widget type/hints/attribute

	// top-leve and child widget
	// ....

	// composite widget

	// custom widgets and painting


	// size hints and size policy

	// geometry

	// events
	QGroupBox		*m_pEventGrpBx;

	// style
	QGroupBox		*m_pStyleGrpBx;

	// transparency and double buffering
	QGroupBox		*m_pTranslucent;

	// creating translucent windows

	// native widgets vs aliens widgets
};


#endif
#ifndef _xfs_StyleSliderUser_h_
#define _xfs_StyleSliderUser_h_

#include <QtWidgets/QWidget>
class QVBoxLayout;
class QSlider;
class QStyle;
class QGroupBox;


class CStyleSliderUser : public QWidget
{
	Q_OBJECT
public:
	CStyleSliderUser( QWidget *_pParent = nullptr );

	void Init();
private:
	void InitGroupBox();

private:
	QVBoxLayout			*m_pLay_0;
	
	QStyle				*m_pStyle;

	QSlider				*m_pVolume;
	QGroupBox			*m_pDownloadGBx;

};



#endif

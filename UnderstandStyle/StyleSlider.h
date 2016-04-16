#ifndef xfs_StyleSlider_h_
#define xfs_StyleSlider_h_

#include <QtWidgets/QCommonStyle>


class CStyleSlider : public QCommonStyle
{
	Q_OBJECT
public:
	CStyleSlider(QObject *_pParent = nullptr);

public:
	void polish( QPalette &_palette ) override;
	void polish( QWidget *_pWidget ) override;
	void polish( QApplication *_pApp ) override;

	void unpolish( QWidget *_pWidget ) override;
	void unpolish( QApplication *_pApp ) override;

public:
	void drawComplexControl( ComplexControl _cc, const QStyleOptionComplex *_pOption,
							 QPainter *_pPainter, const QWidget *_pWidget = nullptr ) const override;

	void drawControl( ControlElement _ce, const QStyleOption *_pOption,
					  QPainter *_pPainter, const QWidget *_pWidget = nullptr ) const override;

	void drawPrimitive( PrimitiveElement _pe, const QStyleOption *_pOption,
						QPainter *_pPainter, const QWidget *_pWidget = nullptr ) const override;


	QRect subControlRect( ComplexControl _cc, const QStyleOptionComplex *_pOption,
						  SubControl _sc, const QWidget *_pWidget = nullptr ) const override;
	
	QRect subElementRect( SubElement _se, const QStyleOption *_pOption,
						  const QWidget *_pWidget = nullptr ) const override;


	int styleHint( StyleHint _sh, const QStyleOption *_pOption = nullptr, 
				   const QWidget *_pWidget = nullptr, QStyleHintReturn * pData = nullptr ) const override;
	
	int pixelMetric( PixelMetric _pm, const QStyleOption *_pOption = nullptr, 
					 const QWidget *_pWidget = nullptr ) const override;

	int layoutSpacing( QSizePolicy::ControlType _controltype1, QSizePolicy::ControlType _controltype2,
					   Qt::Orientation _orientation, const QStyleOption *_pOption = nullptr,
					   const QWidget *_pWidget = nullptr ) const override;


	QSize sizeFromContents( QStyle::ContentsType _ct, const QStyleOption *_pOption,
							const QSize &_size, const QWidget *_pWidget = nullptr ) const override;

private:
	void DrawHoverRect( QPainter *_pPainter, const QRect &_rect ) const;


protected:
	enum ESliderHints
	{
		eSlider_Height = 27,
		eSlider_Handle_Width = 13,
		eSlider_Handle_Height = 27,
		eSlider_Groove_Height = 9,		
	};

};





#endif

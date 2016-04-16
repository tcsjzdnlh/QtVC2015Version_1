#include "StyleSlider.h"
#include "moc_StyleSlider.cpp"
#include <QtWidgets/QStyleOptionSlider>
#include <QtGui/QPainter>
#include <QtGui/QPixmapCache>
#include <QtGui/QPainterPath>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>

#include "MainWnd.h"

extern CMainWnd *g_pWnd;

extern QPixmap cached( const QString &img );


CStyleSlider::CStyleSlider( QObject * _pParent )
{
}

void CStyleSlider::polish( QPalette & _palette )
{
}

void CStyleSlider::polish( QWidget *_pWidget )
{
	
	if( qobject_cast<QPushButton*>(_pWidget)
		|| qobject_cast<QRadioButton*>(_pWidget)
		|| qobject_cast<QSlider*>(_pWidget) )
	{		
		_pWidget->setAttribute( Qt::WidgetAttribute::WA_Hover );
	}
	
}

void CStyleSlider::polish( QApplication * _pApp )
{
}

void CStyleSlider::unpolish( QWidget * _pWidget )
{
}

void CStyleSlider::unpolish( QApplication * _pApp )
{
}

void CStyleSlider::drawComplexControl( ComplexControl _cc, const QStyleOptionComplex *_pOption, QPainter *_pPainter, const QWidget *_pWidget /*= nullptr */ ) const
{
	switch( _cc )
	{
		case CC_Slider:
		{
			auto pSliderOption = qstyleoption_cast<const QStyleOptionSlider* >( _pOption );
			if( pSliderOption )
			{
								
				_pPainter->save();

				bool bHover = ( pSliderOption->state & State_Enabled )
								&& ( pSliderOption->state & State_MouseOver );
				if(  bHover )
				{
					QRect rectModerated = _pWidget->rect().adjusted( 0, 4, 0, -4 );
					DrawHoverRect( _pPainter, rectModerated);
				}

				if( _pOption->subControls & QStyle::SubControl::SC_SliderGroove )
				{
					QRect rectGroove = subControlRect( CC_Slider, _pOption, SC_SliderGroove, _pWidget );
					
					if( !rectGroove.isValid() ) return;
					

					QPixmap pmGroove( ":/res/images/slider_bar.png" );
					_pPainter->drawPixmap( rectGroove, pmGroove );

				}
				if(_pOption->subControls & QStyle::SubControl::SC_SliderHandle)
				{
					QRect rectHandle = subControlRect( CC_Slider, _pOption, SC_SliderHandle, _pWidget );
					
					if( !rectHandle.isValid() ) return;
				

					QPixmap pmHandle( ":/res/images/slider_thumb_on.png" );
					_pPainter->drawPixmap( rectHandle, pmHandle );
				}


				_pPainter->restore();
			}
			break;
		}
		case CC_GroupBox:
		{
			const QStyleOptionGroupBox *pOptionGBx = qstyleoption_cast< const QStyleOptionGroupBox* >( _pOption );
			
			if( pOptionGBx != nullptr )
			{
				QStyleOptionGroupBox optioncopy( *pOptionGBx );				
				optioncopy.subControls &= ~QStyle::SubControl::SC_GroupBoxLabel;
				QCommonStyle::drawComplexControl( _cc, &optioncopy, _pPainter, _pWidget );


				if( pOptionGBx->subControls & QStyle::SubControl::SC_GroupBoxLabel )
				{
					QRect textRect;

					_pPainter->save();

					// draw title background
					{
						QRect rectGroupBox = _pOption->rect;

						QPixmap leftTitle = cached( ":res/images/title_cap_left.png" );
						QPixmap rightTitle = cached( ":res/images/title_cap_right.png" );
						QPixmap stretchTitle = cached( ":res/images/title_stretch.png" );

						int iTextWidth = optioncopy.fontMetrics.width( optioncopy.text ) + leftTitle.width() + rightTitle.width() + 20;
						QRect stretchRect = subControlRect( _cc, _pOption, SC_GroupBoxLabel, _pWidget );
						
						textRect = stretchRect;

						_pPainter->drawPixmap( stretchRect.topLeft().x() - leftTitle.width() , stretchRect.topLeft().y(), leftTitle );						
						_pPainter->drawTiledPixmap( stretchRect, stretchTitle );
						_pPainter->drawPixmap( stretchRect.topRight().x() + 1, 0, rightTitle );
						//_pPainter->drawPixmap( stretchRect.x() + stretchRect.width(), 0, rightTitle );

					}
					// draw title text
					{
						int iOpacity = 31;
						// 1						
						_pPainter->setPen( QColor( 0, 0, 0, iOpacity ) );
						_pPainter->drawText( textRect.translated( 0, 1 ), Qt::AlignHCenter | Qt::AlignVCenter, optioncopy.text );
						// 2
						_pPainter->drawText( textRect.translated( 2, 1 ), Qt::AlignHCenter | Qt::AlignVCenter, optioncopy.text );
						// 3
						_pPainter->setPen( QColor( 0, 0, 0, iOpacity * 2 ) );
						_pPainter->drawText( textRect.translated( 1, 1 ), Qt::AlignHCenter | Qt::AlignVCenter, optioncopy.text );
						// 4
						_pPainter->setPen( Qt::white );
						_pPainter->drawText( textRect, Qt::AlignHCenter | Qt::AlignVCenter, optioncopy.text );
					}

					_pPainter->restore();
				}
				
			}
			
			break;
		}
		default:
			QCommonStyle::drawComplexControl( _cc, _pOption, _pPainter, _pWidget );
			break;
	}
}

void CStyleSlider::drawControl( ControlElement _ce, const QStyleOption *_pOption, QPainter *_pPainter, const QWidget *_pWidget /*= nullptr */ ) const
{
	
	switch( _ce )
	{
		case CE_RadioButtonLabel:
		{
			const QStyleOptionButton *pOption = qstyleoption_cast< const QStyleOptionButton* >( _pOption );
			if( !pOption ) break;
			
			if( pOption->text.isEmpty() )
			{
				QCommonStyle::drawControl( _ce, _pOption, _pPainter, _pWidget );
			}
			else
			{
				_pPainter->save();
				_pPainter->setPen( Qt::black );
				_pPainter->drawText( pOption->rect, Qt::AlignmentFlag::AlignVCenter, pOption->text );
				_pPainter->restore();
			}
		

			break;
		}

		case CE_PushButtonLabel:
		{
			const QStyleOptionButton *pOption = qstyleoption_cast< const QStyleOptionButton* >( _pOption );
			if( !pOption ) break;
			
			if( pOption->text.isEmpty() )
			{
				QCommonStyle::drawControl( _ce, _pOption, _pPainter, _pWidget );
			}
			else
			{
				_pPainter->save();
				_pPainter->setPen( Qt::black );
				_pPainter->drawText( pOption->rect, Qt::AlignVCenter | Qt::AlignHCenter, pOption->text );
				_pPainter->restore();
			}

			break;
		}
		//case CE_PushButton:
		//{
		//	const QStyleOptionButton * pOption = qstyleoption_cast< const QStyleOptionButton* >( _pOption );
		//	if( !pOption ) break;


		//	_pPainter->save();

		//	QRect rWidget = _pWidget->rect();
		//	QRect rSE_PushButton_Contents = subElementRect( SE_PushButtonContents, _pOption, _pWidget );
		//	QRect rSE_PushButton_FocusRect = subElementRect( SE_PushButtonFocusRect, _pOption, _pWidget );

		//	_pPainter->setPen( Qt::red );
		//	_pPainter->drawRect( rWidget );

		//	_pPainter->setPen( Qt::blue );
		//	_pPainter->drawRect( rSE_PushButton_Contents );

		//	_pPainter->setPen( Qt::green );
		//	_pPainter->drawRect( rSE_PushButton_FocusRect );


		//	g_pWnd->Log( QString( "push button widget rect is --> x1: %1, y1: %2, x2: %3, y2: %4 " )
		//				 .arg( rWidget.left() ).arg( rWidget.top() )
		//				 .arg( rWidget.right() ).arg( rWidget.bottom() ));

		//	g_pWnd->Log( QString( "push button contents rect is --> x1: %1, y1: %2, x2: %3, y2: %4 " )
		//				 .arg( rSE_PushButton_Contents.left() ).arg( rSE_PushButton_Contents.top() )
		//				 .arg( rSE_PushButton_Contents.right() ).arg( rSE_PushButton_Contents.bottom() ) );

		//	g_pWnd->Log( QString( "push button focus rect is --> x1: %1, y1: %2, x2: %3, y2: %4 " )
		//				 .arg( rSE_PushButton_FocusRect.left() ).arg( rSE_PushButton_FocusRect.top() )
		//				 .arg( rSE_PushButton_FocusRect.right() ).arg( rSE_PushButton_FocusRect.bottom() ) );

		//	_pPainter->restore();
		//	break;
		//}
		default:
		{
			QCommonStyle::drawControl( _ce, _pOption, _pPainter, _pWidget );
			break;
		}
	}
}

void CStyleSlider::drawPrimitive( PrimitiveElement _pe, const QStyleOption *_pOption, QPainter *_pPainter, const QWidget *_pWidget /*= nullptr */ ) const
{
	switch( _pe )
	{
		case PE_IndicatorRadioButton:
		{
			const QStyleOptionButton *pOption = qstyleoption_cast< const QStyleOptionButton* >( _pOption );
			if( !pOption ) break;
			
			bool bHover = ( pOption->state & QStyle::StateFlag::State_Enabled ) 
							&& ( pOption->state & QStyle::StateFlag::State_MouseOver );
						
			if( bHover )
			{							
				DrawHoverRect( _pPainter, _pWidget->rect() ); // 主调函数 是 const, 被掉函数必须也是const				
			}

			QPixmap pmRadio;
			
			if( pOption->state & QStyle::StateFlag::State_Sunken )
			{
				pmRadio = cached( ":res/images/radiobutton-on.png" );
			}
			else if( pOption->state & QStyle::StateFlag::State_On )
			{
				pmRadio = cached( ":res/images/radiobutton_on.png" );
			}
			else
			{
				pmRadio = cached( ":res/images/radiobutton_off.png" );
			}

			_pPainter->drawPixmap( pOption->rect.topLeft(), pmRadio );
			
			break;
		}
		case PE_FrameFocusRect:
		{
			break;
		}
		
		//case PE_PanelButtonBevel:
		//case PE_FrameDefaultButton:
		//case PE_FrameButtonBevel:
		case PE_PanelButtonCommand:
		{
			const QStyleOptionButton *pOption = qstyleoption_cast< const QStyleOptionButton* >( _pOption );
			if( !pOption ) break;
						
			QPixmap pmLeftBtn;
			QPixmap pmRightBtn;
			QPixmap pmMidBtn;
			
			bool bDown = ( pOption->state & State_Sunken ) && ( pOption->state & State_Enabled );
			if( bDown )
			{
				pmLeftBtn = cached( ":res/images/button_pressed_cap_left.png" );
				pmRightBtn = cached( ":res/images/button_pressed_cap_right.png" );
				pmMidBtn = cached( ":res/images/button_pressed_stretch.png" );
			}
			else
			{
				pmLeftBtn = cached( ":res/images/button_normal_cap_left.png" );
				pmRightBtn = cached( ":res/images/button_normal_cap_right.png" );
				pmMidBtn = cached( ":res/images/button_normal_stretch.png" );
			}

			_pPainter->drawPixmap( pOption->rect.topLeft(), pmLeftBtn );
			_pPainter->drawPixmap( pOption->rect.topRight() - QPoint( pmRightBtn.width(), 0 ), pmRightBtn );
			
			const QRect &r = pOption->rect;
			QRect rStretchBtn;
			rStretchBtn.setX( r.left() + pmLeftBtn.width() );
			rStretchBtn.setY( r.top() );
			rStretchBtn.setWidth( r.width() - pmLeftBtn.width() - pmRightBtn.width() );
			rStretchBtn.setHeight( r.height() );

			_pPainter->drawTiledPixmap( rStretchBtn, pmMidBtn );


			bool bHover = ( pOption->state & State_Enabled ) && ( pOption->state & State_MouseOver );
			if( bHover )
			{
				QRect rBtn = _pWidget->rect().adjusted( 3, 5, -3, -5 );
				_pPainter->fillRect( rBtn, QColor( 31, 127, 31, 63 ) );
			}

			break;
		}
		case PE_FrameGroupBox:
		{
			const QStyleOptionFrame *pOption = qstyleoption_cast< const QStyleOptionFrame* >( _pOption );
			if( !pOption ) return;

			const QRect &r = pOption->rect;
			_pPainter->save();
			_pPainter->setPen( Qt::red );
			QRect redFrame = r.adjusted( 0, 0, -1, -1 );
			_pPainter->drawRect( redFrame );
			//_pPainter->drawRect( r );
			_pPainter->restore();

			_pPainter->setPen( Qt::NoPen );

			QPixmap pmTitleStretch = cached( ":res/images/title_stretch.png" );
			

			// four corners
			QPixmap pmTopLeft = cached( ":res/images/groupframe_topleft.png" );
			QPixmap pmTopRight = cached( ":res/images/groupframe_topright.png" );
			QPixmap pmbottomLeft = cached( ":res/images/groupframe_bottom_left.png" );
			QPixmap pmbottomRight = cached( ":res/images/groupframe_bottom_right.png" );

			
			QPixmap pmTopStretch = cached( ":res/images/groupframe_top_stretch.png" );
			QPixmap pmLeftStretch = cached( ":res/images/groupframe_left_stretch.png" );
			QPixmap pmRightStretch = cached( ":res/images/groupframe_right_stretch.png" );
			QPixmap pmBottomStretch = cached( ":res/images/groupframe_bottom_stretch.png" );

			
			int iTopFrameOffset = pmTitleStretch.height() / 2 - 2;

			QPoint ptTopLeft = r.topLeft() + QPoint( 0, iTopFrameOffset );
			_pPainter->drawPixmap( ptTopLeft, pmTopLeft );
						
			QPoint ptTopRight = r.topRight() + QPoint( 0, iTopFrameOffset ) - QPoint( pmTopRight.width() - 1, 0 );
			_pPainter->drawPixmap( ptTopRight, pmTopRight );
			
			QPoint ptBottomLeft = r.bottomLeft() - QPoint( 0, pmbottomLeft.height() - 1 );
			_pPainter->drawPixmap( ptBottomLeft, pmbottomLeft );
			
			QPoint ptBottomRight = r.bottomRight() - QPoint( pmbottomRight.width() - 1, pmbottomRight.height() - 1 );
			_pPainter->drawPixmap( ptBottomRight, pmbottomRight );

			QRect rectLeftStretch;
			rectLeftStretch.setX( r.x() );
			rectLeftStretch.setY( r.y() + iTopFrameOffset + pmTopLeft.height() );
			rectLeftStretch.setWidth( pmLeftStretch.width() );
			rectLeftStretch.setHeight( r.height() - iTopFrameOffset - pmTopLeft.height() - pmbottomLeft.height() );
			_pPainter->drawTiledPixmap( rectLeftStretch, pmLeftStretch );
			
			QRect rectTopStretch;
			rectTopStretch.setX( r.x() + pmTopLeft.width() );
			rectTopStretch.setY( r.y() + iTopFrameOffset );
			rectTopStretch.setWidth( r.width() - pmTopLeft.width() - pmTopRight.width() );
			rectTopStretch.setHeight( pmTopStretch.height() /*pmTopLeft.height()*/  );
			_pPainter->drawTiledPixmap( rectTopStretch, pmTopStretch );

			QRect rectRightStretch;
			rectRightStretch.setX( r.right() - pmRightStretch.width() + 1  );
			rectRightStretch.setY( r.y() + iTopFrameOffset + pmTopRight.height() );
			rectRightStretch.setWidth( pmRightStretch.width() );
			rectRightStretch.setHeight( r.height() - iTopFrameOffset - pmTopRight.height() - pmbottomRight.height() );
			_pPainter->drawTiledPixmap( rectRightStretch, pmRightStretch );
			

			QRect rectBottomStretch;
			rectBottomStretch.setX( r.x() + pmbottomLeft.width() );
			rectBottomStretch.setY( r.bottom() - pmBottomStretch.height() + 1 );
			rectBottomStretch.setWidth( r.width() - pmbottomLeft.width() - pmbottomRight.width() );
			rectBottomStretch.setHeight( pmBottomStretch.height() );
			_pPainter->drawTiledPixmap( rectBottomStretch, pmBottomStretch );

			break;
		}
		default:
			QCommonStyle::drawPrimitive( _pe, _pOption, _pPainter, _pWidget );
			break;
	}
		
}

QRect CStyleSlider::subControlRect( ComplexControl _cc, const QStyleOptionComplex * _pOption, SubControl _sc, const QWidget * _pWidget ) const
{
	QRect rect;
	rect = QCommonStyle::subControlRect( _cc, _pOption, _sc, _pWidget );

	switch( _cc )
	{
		case CC_Slider:
		{
			switch( _sc )
			{
				case SC_SliderGroove:
				{
					rect.setHeight( eSlider_Groove_Height );
					rect.moveTop( eSlider_Groove_Height );
					break;
				}
				case SC_SliderHandle:
				{
					rect.setWidth( eSlider_Handle_Width );
					rect.setHeight( eSlider_Handle_Height );
					break;
				}
				default:
					break;

			}
			break;
		}
		case CC_GroupBox:
		{
			const QStyleOptionGroupBox *pOption = qstyleoption_cast< const QStyleOptionGroupBox* >( _pOption );
			if( pOption == nullptr ) break;
			
			switch( _sc )
			{
				case SC_GroupBoxContents:
				{
					rect.adjust( 0, -8, 0, 0 );
					break;
				}
				case SC_GroupBoxFrame:
				{
					rect = pOption->rect;
					break;
				}
				case SC_GroupBoxLabel:
				{
					QPixmap leftTitle = cached( ":res/images/title_cap_left.png" );
					QPixmap rightTitle = cached( ":res/images/title_cap_right.png" );
					QPixmap stretchTitle = cached( ":res/images/title_stretch.png" );

					int iTextWidth = _pOption->fontMetrics.width( pOption->text ) + leftTitle.width() + rightTitle.width() + 20;

					rect = QRect( pOption->rect.center().x() - iTextWidth / 2 + leftTitle.width(),
								  0,
								  iTextWidth - leftTitle.width() - rightTitle.width(),
								  stretchTitle.height() );

					break;
				}
				default:
					break;
			}
			
			
			
			break;
		}
		default:
			QCommonStyle::subControlRect( _cc, _pOption, _sc, _pWidget );
			break;
	}


	return rect;
}

QRect CStyleSlider::subElementRect( SubElement _se, const QStyleOption * _pOption, const QWidget * _pWidget ) const
{
	QRect rect;
	switch( _se )
	{
		case SE_RadioButtonClickRect:
		{
			rect = _pWidget->rect();

			break;
		}
		case SE_RadioButtonContents:
		{
			rect = _pWidget->rect().adjusted( 30, 0, 0, 0 );
			break;
		}
		default:
		{
			rect = QCommonStyle::subElementRect( _se, _pOption, _pWidget );
			break;
		}
	}

	if( qobject_cast<const QRadioButton*>(_pWidget) )
	{
		rect = rect.adjusted( 5, 0, -5, 0 );
	}
	
	return rect;
}

int CStyleSlider::styleHint( StyleHint _sh, const QStyleOption * _pOption, const QWidget * _pWidget, QStyleHintReturn * pData ) const
{
	int sh;

	sh = QCommonStyle::styleHint( _sh, _pOption, _pWidget );

	return sh;
}

int CStyleSlider::pixelMetric( PixelMetric _pm, const QStyleOption * _pOption, const QWidget * _pWidget ) const
{
	int pm;

	if( _pm == PM_SliderLength )
	{
		return 13;
	}

	pm = QCommonStyle::pixelMetric( _pm, _pOption, _pWidget );

	return pm;
}

int CStyleSlider::layoutSpacing( QSizePolicy::ControlType _controltype1, QSizePolicy::ControlType _controltype2, Qt::Orientation _orientation, const QStyleOption * _pOption, const QWidget * _pWidget ) const
{
	int ls;

	ls = QCommonStyle::layoutSpacing( _controltype1, _controltype2, _orientation, _pOption, _pWidget );

	return ls;
}

QSize CStyleSlider::sizeFromContents( QStyle::ContentsType _ct, const QStyleOption * _pOption, const QSize & _size, const QWidget * _pWidget ) const
{
	QSize size;

	size = QCommonStyle::sizeFromContents( _ct, _pOption, _size, _pWidget );

	switch( _ct )
	{
		case CT_RadioButton:
		{
			size += QSize( 20, 0 );
			break;
		}
		case CT_Slider:
		{
			size.setHeight( eSlider_Height );
			break;
		}
		case CT_PushButton:
		{
			size.setHeight( 26 );
			break;
		}
		default:
			break;
	}

	return size;
}

void CStyleSlider::DrawHoverRect( QPainter *_pPainter, const QRect &_rect ) const
{
	_pPainter->save();

	qreal h = _rect.height();
	qreal h2 = h / qreal( 2 );

	QPainterPath path;
	path.setFillRule( Qt::FillRule::WindingFill );

	path.addRect( _rect.x() + h2, _rect.y(), _rect.width() - h, _rect.height() );
	path.addEllipse( _rect.x(), _rect.y(), h, h );
	path.addEllipse( _rect.right() - h, _rect.y(), h, h );

	_pPainter->setPen( Qt::NoPen );
	_pPainter->setBrush( QColor(191, 215, 191) );
	_pPainter->setRenderHint( QPainter::Antialiasing );
	
	_pPainter->drawPath( path );

	_pPainter->restore();
}


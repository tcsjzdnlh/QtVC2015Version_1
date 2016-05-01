#include "Testor.h"
#include <QtWidgets/QWidget>
#include "XfsLogger.h"
#include "BWW.h"

CXfsLogger *g_pLogger = nullptr;

namespace first_widget
{	
	namespace xfs_widget
	{
		void test()
		{
			QWidget *pW = new QWidget;
			pW->setAcceptDrops( true );

			pW->show();			
		}
	}

	namespace widget_function
	{
		void test()
		{
			//CXfsLogger *pLogger = new CXfsLogger;
			
			QWidget *pW = new QWidget;
			pW->setWindowModified( true );
			pW->setWindowTitle( "hello" );
			pW->show();
			
			//g_pLogger->Log( pW->isWindowModified() ? "Yes" : "No" );
			//
			//g_pLogger->Log( pW->windowTitle() );
			//
			//g_pLogger->activateWindow();
			//g_pLogger->Log( pW->isActiveWindow() ? "active window" : "not active" );

			//
			//g_pLogger->Log( QString("logger pos is, x:%1, y:%2 ")
			//				.arg(g_pLogger->pos().x())
			//				.arg(g_pLogger->pos().y()) );
		}
	}

	namespace widget_windowflags
	{
		namespace windowtype_desktop
		{
			void test()
			{
				QWidget *pW = new QWidget( nullptr, Qt::WindowType::Desktop );
				pW->show();
			}
		}

		namespace windowtype_splashscreen
		{
			void test()
			{
				QWidget *pW = new QWidget( nullptr, Qt::WindowType::SplashScreen );
				pW->show();

			}
		}

	}

	namespace hints_for_toplevel_windows
	{
		namespace MSWindowsFixedSizeDialogHint
		{
			// has a parent
			//void test()
			//{
			//	

			//	QWidget *pParent = new QWidget;
			//	QWidget *pW = new QWidget( pParent, Qt::WindowType::MSWindowsFixedSizeDialogHint );
			//	pW->setWindowTitle( "hello" );
			//	QPalette refPalette = pW->palette();
			//	refPalette.setColor( QPalette::Window, Qt::darkCyan );
			//	pW->setPalette( refPalette );
			//	pW->setAutoFillBackground( true );
			//	//pW->show();

			//	pParent->show();
			//}
			
			// no parent, as a top-level window
			void test()
			{
				QWidget *pW = new QWidget( nullptr, Qt::WindowType::MSWindowsFixedSizeDialogHint );

				pW->show();				
			}
		}
	}
}


void CTestor::Test()
{
	g_pLogger = new CXfsLogger;
	//g_pLogger->show();

	{
		using namespace first_widget;
		//xfs_widget::test();
		//widget_function::test();
		//widget_windowflags::windowtype_desktop::test();
		//widget_windowflags::windowtype_splashscreen::test();
		hints_for_toplevel_windows::MSWindowsFixedSizeDialogHint::test();
		
	}
}

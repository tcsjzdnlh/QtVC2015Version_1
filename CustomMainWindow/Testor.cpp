#include "Testor.h"
#include "XfsMainWindow.h"

CXfsMainWindow *g_pMainWnd = nullptr;

CTestor::CTestor()
{
	Init();
}

void CTestor::Init()
{
	CXfsMainWindow *pMainWnd = new CXfsMainWindow;
	g_pMainWnd = pMainWnd;

	pMainWnd->resize( 600, 500 );
	//pMainWnd->show();
}

// --------****---------------------****---------------------****---------------------****-------------
// --------****---------------------****---------------------****---------------------****-------------
// --------****---------------------****---------------------****---------------------****-------------

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTextEdit>

namespace test_mainwindow
{
	namespace custom_frame
	{

		void test()
		{
			g_pMainWnd->setWindowFlags( Qt::FramelessWindowHint );

		
			QVBoxLayout *pLay = new QVBoxLayout( g_pMainWnd->GetClient() );
			pLay->setMargin( 0 );
			pLay->addWidget( new QTextEdit );
			

			g_pMainWnd->show();
		}
	}
}



void CTestor::Test()
{
	{
		using namespace test_mainwindow;
		custom_frame::test();
	}

	g_pMainWnd->show();
}
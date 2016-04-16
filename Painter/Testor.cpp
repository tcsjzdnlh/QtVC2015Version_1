#include "Testor.h"
#include "MainWnd.h"


QWidget *g_pWnd = nullptr;

namespace test_painter
{
	namespace painter_path
	{
		void test()
		{


		}
	}
}




void CTestor::Test()
{
	g_pWnd = new CMainWnd;

	{
		using namespace test_painter;
		painter_path::test();
	}



	g_pWnd->show();
}
#include "Testor.h"
#include <QtWidgets/QWidget>

namespace first_widget
{
	namespace xfs_widget
	{
		void test()
		{
			QWidget *pW = new QWidget;
			pW->show();
		}
	}
}


void CTestor::Test()
{
	{
		using namespace first_widget;
		xfs_widget::test();
	}
}

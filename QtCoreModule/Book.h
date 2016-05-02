#ifndef _xfs_Book_h_
#define _xfs_Book_h_

#include <QtCore/QObject>


namespace test_qt_core
{
	namespace q_enum_macro
	{
		// Q_ENUM(...)

		class CBook : public QObject
		{
			Q_OBJECT
		public:
			enum  EDays { monday = 5, tusday = 7 };
			Q_ENUM( EDays )
		};



		void test();

	}
}



#endif

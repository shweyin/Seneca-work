 +// Final Project Milestone 1
+//
+// Version 1.0
+// Date
+// Author
+// Description
+//
+//
+//
+//
+// Revision History
+// -----------------------------------------------------------
+// Name Shweyin              Date 3/16/2018                Reason
 /////////////////////////////////////////////////////////////////
 #ifndef AMA_DATE_H
 #define AMA_DATE_H
-#include <iostream>
-using namespace std;
-
-#define NO_ERROR 0
-#define CIN_FAILED 1
-#define YEAR_ERROR 2
-#define MON_ERROR 3
-#define DAY_ERROR 4
 
 namespace AMA {
 
@@ -31,18 +23,15 @@ namespace AMA {
 	public:
 		Date();
 		Date(int, int, int);
-		bool operator==(const Date&) const;
-		bool operator!=(const Date&) const;
-		bool operator<(const Date&) const;
-		bool operator>(const Date&) const;
-		bool operator<=(const Date&) const;
-		bool operator>=(const Date&) const;
+		bool operator==(const Date& rhs) const;
+		bool operator!=(const Date& rhs) const;
+		bool operator<(const Date& rhs) const;
+		bool operator>(const Date& rhs) const;
+		bool operator<=(const Date& rhs) const;
+		bool operator>=(const Date& rhs) const;
 		int errCode() const;
 		bool bad() const;
-		istream& read(std::istream&);
-		ostream& write(std::ostream&) const;
-		istream& operator>>(Date&);
-		ostream& operator<<(Date&);
+
 	};
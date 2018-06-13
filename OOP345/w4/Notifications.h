// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018

#include "Message.cpp"
const int msg_array_size = 10;
namespace sict
{
	class Notifications {
		Message msg_array[msg_array_size];
	public:
		Notifications(std::ifstream& ifstr);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void display(std::ostream&) const;
	};
}
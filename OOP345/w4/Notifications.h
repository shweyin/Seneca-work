// Workshop 4 - Containers
// Shweyin Than
// 6/12/2018

#include "Message.h"
const int max_msg_size = 10;
namespace sict
{
	class Notifications {
		std::vector <Message> msg_vector;
	public:
		Notifications(std::ifstream&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void display(std::ostream&) const;
	};
}
#include "ErrorState.h"

namespace AMA
{
	ErrorState::ErrorState(const char* con_string)
	{
		if (con_string)
		{
			message(con_string);
		}
	}
	ErrorState::~ErrorState()
	{
		delete[] error_msg;
	}
	void ErrorState::clear()
	{
		if (strlen(error_msg) != 0)
		{
			delete[] error_msg;
			error_msg = nullptr;
		}
	}
	
	bool ErrorState::isClear() const
	{
		return !error_msg;
	}
	void ErrorState::message(const char* msg_string)
	{
		clear();
		int length = strlen(msg_string);
		error_msg = new char[length + 1];
		strcpy(error_msg, msg_string);
	}
	const char* ErrorState::message() const
	{
		return error_msg;
	}
	std::ostream& ErrorState::write(std::ostream& ostr) const
	{
		if (!ErrorState::isClear())
		{
			ostr << error_msg;
		}
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const ErrorState& ostr_ErrorState)
	{
		ostr_ErrorState.write(ostr);
		//ostr << ostr_ErrorState.message() << std::endl;
		return ostr;
	}
}
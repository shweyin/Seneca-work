#include "ErrorState.h"

namespace AMA
{
	ErrorState::ErrorState(const char* con_string)
	{
		if (con_string)
		{
			message(con_string);
		}
		else
		{
			clear();
		}
	}
	ErrorState::~ErrorState()
	{
		delete[] error_msg;
	}
	void ErrorState::clear()
	{
		error_msg_delete();
		error_msg = new char[empty_size];
		strcpy(error_msg, "Empty!");
	}
	void ErrorState::error_msg_delete()
	{
		if (error_msg)
		{
			delete[] error_msg;
		}
	}
	bool ErrorState::isClear() const
	{
		return (strcmp(error_msg, "Empty!") == 0);
	}
	void ErrorState::message(const char* msg_string)
	{
		error_msg_delete();
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
#include "ErrorState.h"

namespace AMA
{
	ErrorState::ErrorState(const char *)
	{
	}
	ErrorState::~ErrorState()
	{
	}
	void ErrorState::clear()
	{
	}
	bool ErrorState::isClear() const
	{
		return false;
	}
	void ErrorState::message(const char *)
	{
	}
	const char * ErrorState::message() const
	{
		return nullptr;
	}
	std::ostream & operator<<(const ErrorState &)
	{
		// TODO: insert return statement here
	}
}
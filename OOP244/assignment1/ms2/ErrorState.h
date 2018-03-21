#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>


namespace AMA
{
	class ErrorState
	{
		char* error_msg;
	public:
		explicit ErrorState(const char* = nullptr);
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
	};
	std::ostream& operator<<(const ErrorState&);
}
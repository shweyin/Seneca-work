#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>


namespace AMA
{
	const int empty_size = 7;

	class ErrorState
	{
		char* error_msg;
		void error_msg_delete();
	public:
		explicit ErrorState(const char* = nullptr);
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
		std::ostream& write(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
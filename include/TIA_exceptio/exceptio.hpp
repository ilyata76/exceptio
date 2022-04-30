#pragma once

#include <stdint.h>
#include <cstring>

#ifndef Exceptio_TIA_HPP
#define Exceptio_TIA_HPP

#define INT_PLUG INT16_MIN
#define STR_PLUG "\0"

// MAIN CLASS
class Exceptio_TIA {
	protected:
		int16_t index; // -32k +32k
		const char* description;
		const char* comment;

	public:
	//
		// INDEX - number of 16-bit integer for your enumeration and lists (if you see INT_PLUG you made a mistake)
		Exceptio_TIA(int16_t index);

		// INDEX - number of 16-bit integer for your enumeration and lists (if you see INT_PLUG you made a mistake)
		// DESCRIPTION - string which should describe the problem
		Exceptio_TIA(int16_t index, const char* description);

		// DESCRIPTION - string which should describe the problem
		Exceptio_TIA(const char* description);

		// DESCRIPTION - string which should describe the problem
		// COMMENT - optional str
		Exceptio_TIA(const char* description, const char* comment);

		// INDEX - number of 16-bit integer for your enumeration and lists (if you see INT_PLUG you made a mistake)
		// DESCRIPTION - string which should describe the problem
		// COMMENT - optional str
		Exceptio_TIA(int16_t index, const char* description, const char* comment);
	//
		bool operator == (Exceptio_TIA& a);
	//
	protected:
		int16_t get_raw_index();
		const char* get_raw_description();
		const char* get_raw_comment();

		// Checks whether the index was entered or entered correctly (if yes returns not 0)
		friend bool checking_index_for_out(Exceptio_TIA&);
		// Checks whether the description string was entered (if yes returns not 0)
		friend bool checking_description_for_out(Exceptio_TIA&);
		// Checks whether the comment string was entered (if yes returns not 0)
		friend bool checking_comment_for_out(Exceptio_TIA&);
	//
	public:
		int16_t get_index();
		const char* get_description();
		const char* get_comment();

};

// childs by Exceptio_TIA?
#endif
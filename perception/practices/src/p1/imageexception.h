#ifndef _ImageException_H_
#define _ImageException_H_

/**
 * @file    imageexception.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <exception>
#include <string>

using namespace std;

class ImageException : public std::exception
{
	std::string _what;
	
public:	
	ImageException(std::string what) throw() : _what(what) {}
	virtual ~ImageException() throw() {}
	virtual const char* what() const throw() { return _what.c_str(); }
};

#endif

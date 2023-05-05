#ifndef BASE_H
#define BASE_H

#include <memory>
#include <string>
#include "logger.h"
class Object {
public:
	virtual std::string toString() = 0;
	// big 3
	Object() {
		(&Logger::getInstance())->debug("Object constructor");
	}
	Object(const Object& object) {
		(&Logger::getInstance())->debug("Object copy constructor");
	}
	virtual ~Object() {
		(&Logger::getInstance())->debug("Object destructor");
	}
};
#endif
/*
 * GeneralException.cpp
 *
 *  Created on: 1 Jan 2021
 *      Author: xmaster
 */

#include "GeneralException.h"

GeneralException::GeneralException(std::string messsage) : std::runtime_error(messsage) {
}

GeneralException::~GeneralException() {
}


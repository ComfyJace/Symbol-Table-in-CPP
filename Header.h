#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <variant>
#include <memory>


enum class DataType {
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	VOID_PTR
};

std::string dataTypeToString(DataType type);



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

class SymbolTable {
public:
    // Define the variant type to store different data types
    using SymbolValue = std::variant<int, char, float, double, void*>;

    // Store a new variable in the table
    void store(const std::string& name, SymbolValue value, DataType type);

    // Update an existing variable in the table
    void update(const std::string& name, SymbolValue value);

    // Print the symbol table (for debugging)
    void print() const;

private:
    // Internal storage for the symbol table
    std::unordered_map<std::string, std::pair<SymbolValue, DataType>> table;
};

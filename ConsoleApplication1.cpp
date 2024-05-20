#include "Header.h"

// Define the SymbolTable class
class SymbolTable {
public:
    // Define the variant type to store different data types
    using SymbolValue = std::variant<int, char, float, double, void*>;

    // Store a new variable in the table
    void store(const std::string& name, SymbolValue value, DataType type) {
        table[name] = { value, type };
    }

    // Update an existing variable in the table
    void update(const std::string& name, SymbolValue value) {
        if (table.find(name) != table.end()) {
            table[name].first = value;
        }
        else {
            std::cerr << "Variable not found in symbol table." << std::endl;
        }
    }

    // Print the symbol table (for debugging)
    void print() const {
        for (const auto& [key, val] : table) {
            std::cout << "Variable: " << key << ", Type: " << dataTypeToString(val.second) << std::endl;
            std::visit([](const auto& v) { std::cout << v; }, val.first);
            std::cout << std::endl;
        }
    }

private:
    // Internal storage for the symbol table
    std::unordered_map<std::string, std::pair<SymbolValue, DataType>> table;
};

// Function to convert DataType to string
std::string dataTypeToString(DataType type) {
    switch (type) {
    case DataType::INT: return "INT";
    case DataType::CHAR: return "CHAR";
    case DataType::FLOAT: return "FLOAT";
    case DataType::DOUBLE: return "DOUBLE";
    case DataType::VOID_PTR: return "VOID_PTR";
    default: return "UNKNOWN";
    }
}
int main() {
    // Declaring symbol table as a temporary variable
    SymbolTable symbolTable;

    // Store a variable in the symbol table
    symbolTable.store("myCSOPESYGrade", 100, DataType::INT);

    // Print the symbol table
    symbolTable.print();

    // Declaring symbol table as a unique pointer
    std::unique_ptr<SymbolTable> symbolTablePtr = std::make_unique<SymbolTable>();

    // Store a variable in the symbol table
    symbolTablePtr->store("myCSOPESYGrade", 100, DataType::INT);

    // Print the symbol table
    symbolTablePtr->print();

    return 0;
}

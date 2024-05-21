#include "Header.h"

// Define the SymbolTable class
class SymbolTable {
public:
    // Create an alias for the data type of the value to be stored 
    using SymbolValue = std::variant<int, char, float, double, void*>;

    /**
    * This function stores a value and datatype into a table
    * 
    * @param name - name for the key value pair.
    * @param value - value to be stored. Could be a variant of the primitive data types(int, char, float, double, or void*)
    * @param type - the data type of the value 
    * @return nothing
    */ 
    void store(const std::string& name, SymbolValue value, DataType type) {
        table[name] = { value, type };
    }

    /**
    * This function updates a value in the table given the name of the variable. Prints an error if the variable is not found, else it prints it was a success
    * 
    * @param name - name for the key value pair.
    * @param value - value to be stored. Could be a variant of the primitive data types(int, char, float, double, or void*)
    * @return nothing
    */ 
    void update(const std::string& name, SymbolValue value) {
        if (table.find(name) != table.end()) {
            table[name].first = value;
            std::cout << "Value updated succefully" << std::endl;
        }
        else {
            std::cerr << "Variable not found in symbol table." << std::endl;
        }
    }

    /**
    * This function is prints the values stored in the unordered map
    * @return nothing
    */
    void print() const {
        for (const auto& [key, val] : table) {
            std::cout << "Variable: " << key << ", Type: " << dataTypeToString(val.second) << " ";
            std::visit([](const auto& v) { std::cout << "value: " << v << std::endl; }, val.first);
            
        }
    }

private:
    // create an unordered map for the symbol table
    std::unordered_map<std::string, std::pair<SymbolValue, DataType>> table;
};

// Function to convert DataType to string; only used for debugging and printing the datatype values in the symbol table
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
    // Declare symbol table as a temporary variable
    SymbolTable symbolTable;
    int myCSOPESYGrade = 100;
  
    // Store a variable in the symbol table
    std::cout << "Symbol table as a temporary variable\n" << std::endl;
    symbolTable.store("myCSOPESYGrade", myCSOPESYGrade, DataType::INT);

    // Print the symbol table
    symbolTable.print();
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Symbol table as a unique pointer\n" << std::endl;

    // Declaring symbol table as a unique pointer
    std::unique_ptr<SymbolTable> symbolTablePtr = std::make_unique<SymbolTable>();
   
    // Store a variable in the symbol table
    symbolTablePtr->store("myCSOPESYGrade", myCSOPESYGrade, DataType::INT);

    // Print the symbol table
    symbolTablePtr->print();

    return 0;
}

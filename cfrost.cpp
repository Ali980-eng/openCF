#include <filesystem>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

namespace cfrost {
    namespace data {
        std::unordered_map<std::string, std::string> var_types;
        std::unordered_map<std::string, std::string> obj;
        std::unordered_map<std::string, std::string> func;
        std::unordered_map<std::string, std::string> prefix;
        const std::unordered_map<std::string, std::string> postfix{
            {"bool", "bl"},
            {"char", "ch"},
            {"short", "si16"},
            {"int", "si32"},
            {"long", "si64"},
            {"float", "f32"},
            {"double", "f64"},
            {"str", "chptr"},
            {"uint8_t", "ui8"},
            {"uint16_t", "ui16"},
            {"uint32_t", "ui32"},
            {"uint64_t", "ui64"},
            {"int8_t", "si8"},
            {"int16_t", "si16"},
            {"int32_t", "si32"},
            {"int64_t", "si64"},
            {"const", "co"}
        };
    }

    namespace tools {
        bool is_type(const std::string& command) noexcept {
            if(command == "bool") return true;
            else if(command == "char") return true;
            else if(command == "short") return true;
            else if(command == "int") return true;
            else if(command == "long") return true;
            else if(command == "float") return true;
            else if(command == "double") return true;
            else if(command == "str") return true;
            else if(command == "uint8_t") return true;
            else if(command == "uint16_t") return true;
            else if(command == "uint32_t") return true;
            else if(command == "uint64_t") return true;
            else if(command == "int8_t") return true;
            else if(command == "int16_t") return true;
            else if(command == "int32_t") return true;
            else if(command == "int64_t") return true;
            else if(command == "const") return true;
            else return false;
        }
    }

    enum token_type {
        none,
        type,
        var,
        symbol,
        object,
        prefix,
        prefix_name,
        prefix_symbol,
        function,
        function_symbol,
        function_name,
        ignore
    };

    struct token {
        char t;
        token_type type;
        std::string tok;
    };

    void preformater(const std::filesystem::path& source) noexcept {
        for(const auto& entry : std::filesystem::directory_iterator(source)) {
            if(entry.is_directory()) preformater(entry.path());
            else if(entry.path().extension() == ".c") {
                std::ifstream file(entry.path());
                std::string command;
                std::queue<std::string> formatted;
                while(std::getline(file, command)) {
                    if(command)
                }
                file.close();
                std::ofstream out(entry.path());
                while(std::string )
                out << formatted;
                out.close();
            }
        }
    }

    const std::queue<token> lexer(const std::string& command) noexcept {
        std::queue<token> tokens;
        token temp = {" ", token_type::none};
        bool is_new_name = false;
        for(char c : command) {
            if( c == '(' ||
                c == ')' ||
                c == '{' ||
                c == '}' ||
                c == '[' ||
                c == '=' ||
                c == '!' ||
                c == '-' ||
                c == '+' ||
                c == '/' ||
                c == '*' ||
                c == '&' ||
                c == '|' ||
                c == '\''||
                c == '\"'||
                c == ';'
            ) {
                temp.t = c;
                temp.type = token_type::symbol;
            } else if(c == ':') {
                temp.t = c;
                temp.type = token_type::prefix_symbol;
            } else if(temp.tok == "func") {
                temp.t = c;
                temp.type = token_type::function;
            } else if(c != ' ') {
                temp.tok += c;
                continue;
            }
            if(temp.tok == "prefix") temp.type = token_type::prefix;
            else if(temp.tok == "object") temp.type = token_type::object;
            tokens.push(temp);
            temp = token{" ", ' ', token_type::none};
        }
    }

    const std::string formater(const std::queue<token>& tokens) noexcept;
}

int main() {
    return 0;
}
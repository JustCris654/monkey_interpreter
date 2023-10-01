#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

namespace TOKEN {
const std::string ILLEGAL = "ILLEGAL";
const std::string END_OF_FILE = "EOF";

// Identifiers + literals
const std::string IDENT = "IDENT";
const std::string INT = "INT";

// Operators
const std::string ASSIGN = "=";
const std::string PLUS = "+";

// Delimeters
const std::string COMMA = ",";
const std::string SEMICOLON = ";";

const std::string LPAREN = "(";
const std::string RPAREN = ")";
const std::string LBRACE = "{";
const std::string RBRACE = "}";

// Keywords
const std::string FUNCTION = "FUNCTION";
const std::string LET = "LET";

} // namespace TOKEN

typedef std::string
    TokenType; // should contain only values defined in the TOKEN namespace

typedef struct {
    TokenType   type;
    std::string literal;
} Token;
#endif

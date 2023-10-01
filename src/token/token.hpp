#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <unordered_map>

typedef std::string
    TokenType; // should contain only values defined in the TOKEN namespace

namespace TOKEN {
const TokenType ILLEGAL = "ILLEGAL";
const TokenType END_OF_FILE = "EOF";

// Identifiers + literals
const TokenType IDENT = "IDENT";
const TokenType INT = "INT";

// Operators
const TokenType ASSIGN = "=";
const TokenType PLUS = "+";

// Delimeters
const TokenType COMMA = ",";
const TokenType SEMICOLON = ";";

const TokenType LPAREN = "(";
const TokenType RPAREN = ")";
const TokenType LBRACE = "{";
const TokenType RBRACE = "}";

// Keywords
const TokenType FUNCTION = "FUNCTION";
const TokenType LET = "LET";

const std::unordered_map<std::string, TokenType> keywords{
    {"fn", TOKEN::FUNCTION}, {"let", TOKEN::LET}};
} // namespace TOKEN

typedef struct {
    TokenType   type;
    std::string literal;
} Token;

TokenType lookupIdent(std::string &);
#endif

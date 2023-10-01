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
const TokenType MINUS = "-";
const TokenType BANG = "!";
const TokenType ASTERISK = "*";
const TokenType SLASH = "/";

// less than - greater than
const TokenType LT = "<";
const TokenType GT = ">";

const TokenType EQ = "==";
const TokenType NOT_EQ = "!=";

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
const TokenType TRUE = "TRUE";
const TokenType FALSE = "FALSE";
const TokenType IF = "IF";
const TokenType ELSE = "ELSE";
const TokenType RETURN = "RETURN";

const std::unordered_map<std::string, TokenType> keywords{
    {"fn", TOKEN::FUNCTION},   {"let", TOKEN::LET}, {"true", TOKEN::TRUE},
    {"false", TOKEN::FALSE},   {"if", TOKEN::IF},   {"else", TOKEN::ELSE},
    {"return", TOKEN::RETURN},
};
} // namespace TOKEN

typedef struct {
    TokenType   type;
    std::string literal;
} Token;

TokenType lookupIdent(std::string &);
#endif

#ifndef _TOKEN_H
#define _TOKEN_H

#include <string>

typedef std::string TokenType;

typedef struct {
  TokenType type;
  std::string literal;
} Token;

#endif

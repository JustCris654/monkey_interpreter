#include "token.hpp"

TokenType lookupIdent(std::string &identifier) {
    auto match = TOKEN::keywords.find(identifier);
    if (match != TOKEN::keywords.end()) {
        return match->second;
    }

    return TOKEN::IDENT;
}

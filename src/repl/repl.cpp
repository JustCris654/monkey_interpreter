#include "repl.hpp"
#include "token.hpp"

void start() {

    std::string line;

    while (1) {
        std::cout << PROMPT;
        std::getline(std::cin, line);

        if (line.compare("quit") == 0 || line.compare("exit") == 0) {
            return;
        }

        Lexer lexer{line};

        Token tok = lexer.nextToken();
        while (tok.type != TOKEN::END_OF_FILE) {

            printf(
                "Token : { type: %s, literal: %s }\n", tok.type.c_str(),
                tok.literal.c_str());

            tok = lexer.nextToken();
        }
    }
}

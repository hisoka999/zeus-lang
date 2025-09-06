#pragma once
#include <algorithm>

#include "parser/Parser.h"

namespace types {
    struct TypeCheckResult {
        std::vector<parser::ParserMessasge> messages;

        [[nodiscard]] bool hasError() const {
            return std::ranges::any_of(
                messages, [](const auto &msg) { return msg.outputType == parser::OutputType::ERROR; });
        }
    };

    void type_check(const std::vector<std::unique_ptr<ast::ASTNode> > &nodes, TypeCheckResult &result);
}

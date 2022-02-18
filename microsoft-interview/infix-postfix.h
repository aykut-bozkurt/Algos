#pragma once

#include <string>

std::string infix_to_postfix(const std::string& infix);

int eval_postfix(const std::string& postfix);

#ifndef REELIA_EXPRESSION_HPP
#define REELIA_EXPRESSION_HPP

#include <string>

class ReeliaParser; // Forward declaration

/**
 * Expression Evaluator for the REELIA language
 * Implements a recursive descent parser that handles mathematical expressions
 * with proper operator precedence.
 */
class ExpressionEvaluator {
private:
  ReeliaParser &parser;

  // Helper functions for expression parsing
  bool isSpace(char c);
  void skipWhitespace(std::string::const_iterator &it,
                      const std::string::const_iterator &end);
  bool match(std::string::const_iterator &it,
             const std::string::const_iterator &end, char expected);

  // Recursive descent parser levels
  int parsePrimary(std::string::const_iterator &it,
                   const std::string::const_iterator &end);
  int parseTerm(std::string::const_iterator &it,
                const std::string::const_iterator &end);
  int parseAdditive(std::string::const_iterator &it,
                    const std::string::const_iterator &end);
  int parseShift(std::string::const_iterator &it,
                 const std::string::const_iterator &end);
  int parseRelational(std::string::const_iterator &it,
                      const std::string::const_iterator &end);
  int parseEquality(std::string::const_iterator &it,
                    const std::string::const_iterator &end);
  int parseBitwiseAnd(std::string::const_iterator &it,
                      const std::string::const_iterator &end);
  int parseBitwiseXor(std::string::const_iterator &it,
                      const std::string::const_iterator &end);
  int parseBitwiseOr(std::string::const_iterator &it,
                     const std::string::const_iterator &end);
  int parseLogicalAnd(std::string::const_iterator &it,
                      const std::string::const_iterator &end);
  int parseLogicalOr(std::string::const_iterator &it,
                     const std::string::const_iterator &end);
  int parseConditional(std::string::const_iterator &it,
                       const std::string::const_iterator &end);
  int parseFunction(std::string::const_iterator &it,
                    const std::string::const_iterator &end);

public:
  ExpressionEvaluator(ReeliaParser &p) : parser(p) {}

  // Evaluate a complete expression string
  int evaluate(const std::string &expr);
};

#endif // REELIA_EXPRESSION_HPP
#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b)
{
    if ((b > 0 && a > INT_MAX - b) ||
        (b < 0 && a < INT_MIN - b))
    {
        throw std::overflow_error("overflow/underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b)
{
    if ((b < 0 && a > INT_MAX - b) ||
        (b > 0 && a < INT_MIN + b))
    {
        throw std::overflow_error("overflow/underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b)
{
    if ((a > INT_MAX / b) || (a < INT_MIN / b))
    {
        throw std::overflow_error("overflow/underflow");
    }
    return a * b;
}

int Calculator::div(int a, int b)
{
    if (b == 0)
        throw std::invalid_argument("Division by zero");
    if (a == INT_MIN && b == -1)
        throw std::overflow_error("overflow/underflow");
    return a / b;
}
#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    ~RPN();
	RPN(const RPN &s_RPN);
	RPN &operator=(RPN const &s_RPN);
	float calculate(const std::string& expression);

private:
};

#endif

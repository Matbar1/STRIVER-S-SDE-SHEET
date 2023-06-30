class Solution {
public:
   int myAtoi(std::string str) {
    int sign = 1;
    int i = 0;
    int result = 0;

    // Ignore leading whitespace
    while (str[i] == ' ')
        i++;

    // Handle the sign
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert the digits
    while (isdigit(str[i])) {
        int digit = str[i] - '0';

        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

};
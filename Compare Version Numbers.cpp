class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
    std::istringstream iss1(version1);
    std::istringstream iss2(version2);
    int num1, num2;
    char dot;

    while (iss1 || iss2) {
        if (iss1 >> num1) {
            iss1 >> dot;
        } else {
            num1 = 0;
        }

        if (iss2 >> num2) {
            iss2 >> dot;
        } else {
            num2 = 0;
        }

        if (num1 < num2)
            return -1;
        else if (num1 > num2)
            return 1;

        num1 = 0;
        num2 = 0;
    }
return 0;
    }
        
    
};
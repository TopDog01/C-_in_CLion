#include <iostream>
#include <cstring>

bool substr(const char* str1, const char* str2)
{
    if (*str2 == '\0')
    {
        return true;
    }
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if (len2 > len1)
    {
        return false;
    }
    for (size_t i = 0; i <= len1 - len2; i++) {
        size_t j;
        for  (j = 0; j < len2; j++){
            if (str1[i + j] != str2[j]){
                break;
            }
        }
        if (j == len2){
            return true;
        }
    }
    return false;
}

int main()
{
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    std::cout << (substr(a, b) ? "true" : "false") << " ";
    std::cout << (substr(a, c) ? "true" : "false") << std::endl;

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman(int num)
{
    char *roman = malloc(32);
    roman[0] = '\0';

    char *onesMapping [] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char *tensMapping [] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *hundredsMapping [] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *thousandsMapping [] = {"", "M", "MM", "MMM",};
    
    int ones = num % 10;
    int tens = (num / 10) % 10;
    int hundreds = (num / 100) % 10;
    int thousands = (num / 1000) % 10;

    roman = strcat(roman, thousandsMapping[thousands]);
    roman = strcat(roman, hundredsMapping[hundreds]);
    roman = strcat(roman, tensMapping[tens]);
    roman = strcat(roman, onesMapping[ones]);

    return roman;
}

int main()
{

    char *result = intToRoman(3749);
    printf("%s", result);

    free(result);

    return 0;
}
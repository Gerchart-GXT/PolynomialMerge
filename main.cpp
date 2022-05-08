#include "mergeHandle.h"

void menu()
{
    puts("——————————");
    puts("Welcome to Polynomial merge system!!!");
    puts("——————————");
    puts("Input Standard:");
    puts("If you want to input : ");
    puts("\"-x+2x-3x^{-4}+5x^{6}\"");
    puts("Please enter it as : ");
    puts("\"-x+2x-3x{-4}+5x{6}\"");
    puts("");
    puts("Ps1 : please input without \" and \"space\" ");
    puts("Ps2 : You can alse choose any unary variable other than 'x'");
    puts("Ps3 : It is not necessary to arrange the ascending (descending) power");
    puts("Ps4 : Please insure the input numbers are in range of: [-2^31~2^31-1]——(int range)");
    puts("");
    puts("After reading the above tips, please press any key to start input!");
    getchar();
}
int main()
{
    auto list = new Linklist();
    std::string s1, s2;
    menu();
    puts("Please input 1st Polynomial:");
    std::cin >> s1;
    list = divIntoList(list, s1);
    puts("Please input 2nd Polynomial:");
    std::cin >> s2;
    list = divIntoList(list, s2);
    puts("The ans is( with descending order ): ");
    std::cout
        << "   "
        << s1 << std::endl
        << " + "
        << s2 << std::endl
        << " = ";
    printAllItems(list);
    puts("\nCaculate finished!");
    puts("Press any key to exit!");
    getchar();
    getchar();
    return 0;
}
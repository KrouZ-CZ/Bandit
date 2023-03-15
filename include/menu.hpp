#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class menu
{
private:
    int money;
    void draw();
    int select();
    int get_balance();
public:
    menu();
    void main();
};
#include "repl.h"

using namespace std;

int main()
{
    /*string temp;
    char* pass = new char[30];
    cin >> temp;
    if (temp == "register") { //!strcmp(str, "register")
        std::ofstream user_info_write;
        cin >> temp;
        user_info_write.open(temp + ".txt");
        cin >> temp;
        user_info_write << temp << endl;
        user_info_write.close();
    }
    else if (temp == "login") {
        std::ifstream user_info_read;
        cin >> temp;
        user_info_read.open(temp + ".txt");
        user_info_read >> pass;
        cin >> temp;
        if (pass == temp) {
            std::cout << "ba4ka!\n";
        }
        user_info_read.close();
    }
    delete[] pass;*/
    //printHangman(1);
    repl game;
    game.run();
    return 0;
}

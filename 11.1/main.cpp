#include "subject.h"
#include "real_subject.h"
#include "proxy.h"
#include <iostream>
#include <thread>  //add -pthread if you use gcc/g++ to compile it
#include <chrono>

using namespace std;

int main()
{
    //cout << "Main thread id: " << std::this_thread::get_id() << endl;

    ImageProxy Image1("./image_1.txt", "Dog Image");
    ImageProxy Image2("./image_2.txt", "Cat Image");

    for(int i = 0; i < 5; i++)
    {
        cout << "Flip to 1st picture..." << endl;
        Image1.paint();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Flip to 2nd picture..." << endl;
        Image2.paint();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}


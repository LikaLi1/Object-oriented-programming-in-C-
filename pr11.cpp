#include <iostream>
using namespace std;

#define PI 3.141592653589793

int main() {
    cout << "PI: " << PI << endl;
    return 0;
}


#include <iostream>
using namespace std;

#define SUM(a, b) ((a) + (b))

int main() {
    int x = 5, y = 10;
    cout << "Sum: " << SUM(x, y) << endl;
    return 0;
}


#include <iostream>
using namespace std;

#define MUL(a, b) a * b 
//((a) * (b)) 
int main() {
    int result = MUL(2 + 3, 4);
    cout << "Pesult: " << result << endl;
    return 0;
}


#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x))

int main() {
    cout << "Square 5: " << SQUARE(5) << endl;
    cout << "Square (1 + 2): " << SQUARE(1 + 2) << endl;
    return 0;
}


#include <iostream>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int x = 5, y = 10;
    cout << "Min: " << MIN(x, y) << endl;
    return 0;
}


#include <iostream>
using namespace std;

#define DEBUG

#ifdef DEBUG
    #define DEBUG_LOG(x) cout << "DEBUG: " << x << endl;
#else
    #define DEBUG_LOG(x)
#endif

int main()
{
    DEBUG_LOG("Test message");
}


#include <iostream>
using namespace std;

#define DEBUG

int main() {
#ifdef DEBUG
    cout << "Debug mode ON" << endl;
#endif
    return 0;
}


#include <iostream>
using namespace std;

int main() {
#ifndef RELEASE
    cout << "RELEASE not found" << endl;
#endif
    return 0;
}


#include <iostream>
using namespace std;

#define VERSION 1

int main() {
#if VERSION == 1
    cout << "v1" << endl;
#else
    cout << "Other version" << endl;
#endif
    return 0;
}


#ifndef MY_HEADER_H
#define MY_HEADER_H

void myFunction();

#endif


#include <iostream>
using namespace std;

#define LOG(x) \
    cout << "File: " << __FILE__ \
         << ", Line: " << __LINE__ \
         << ", Message: " << x << endl;

int main() {
    LOG("Hello, this is a log message");
    return 0;
}


#include <iostream>
using namespace std;

#define PRINT(x)
    cout << #x << " = " << x << endl;

int main() {
    int a = 10;
    double b = 3.14;
    string str = "HI";

    PRINT(a);
    PRINT(b);
    PRINT(str);

    return 0;
}


#include <iostream>
using namespace std;

#define CONCATENATE(a, b) a##b

int main() {
    int var_1 = 5;
    int var_2 = 10;
    int var_3 = 15;
  
    cout << "var_1 = " << CONCATENATE(var_, 1) << endl;
    cout << "var_2 = " << CONCATENATE(var_, 2) << endl;
    cout << "var_3 = " << CONCATENATE(var_, 3) << endl;

    return 0;
}


#include <iostream>
using namespace std;
#define PRINT_VAR(x) cout << #x << " = " << x << endl;

int main()
{
    int a = 10;
    PRINT_VAR(a);
}


#include <iostream>
using namespace std;

#define CHECK(x) 
    do { 
        if (!(x)) { 
            cout << "Error: condition failed (" << #x << ")" << endl; \
        } 
    } while (0)

int main() {
    int a = 5;

    CHECK(a > 0);
    CHECK(a < 0);

    return 0;
}


#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define START_TIMER(start_time) 
    auto start_time = high_resolution_clock::now();

#define END_TIMER(start_time) 
    auto end_time = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(end_time - start_time); 
    cout << "Time elapsed: " << duration.count() << " ms" << endl;

int main() {
    START_TIMER(t1)
    for (int i = 0; i < 1000000; ++i);

    END_TIMER(t1)

    return 0;
}


#include <iostream>
using namespace std;

#define CHECK_PTR(p)
    if ((p) == nullptr) {
        cout << "Pointer " << #p << " is nullptr!" << endl;
    }

int main() {
    int* ptr1 = nullptr;
    int value = 42;
    int* ptr2 = &value;

    CHECK_PTR(ptr1);
    CHECK_PTR(ptr2);

    return 0;
}


#include <iostream>
using namespace std;

#define MY_ASSERT(cond)
    do {
        if (!(cond)) {
            cout << "Assertion failed: " << #cond << endl;
        }
    } while (0)

int main() {
    int a = 5;

    MY_ASSERT(a > 0);
    MY_ASSERT(a < 0);

    return 0;
}


#include <iostream>
using namespace std;

#ifdef DEBUG
    #define DEBUG_LOG(msg) \
        cout << "DEBUG: File: " << __FILE__ \
             << ", Line: " << __LINE__ \
             << ", Message: " << msg << endl;
#else
    #define DEBUG_LOG(msg) ((void)0)
#endif

int main() {
    DEBUG_LOG("Hi!");

    int x = 42;
    DEBUG_LOG("x: " << x);

    return 0;
}

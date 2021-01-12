/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* y) : value(v), name(y)
    {
       
    }   
    
    int value;
    std::string name;

};

struct MyFirstStruct                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float myFloat1 { 8.0f }, myFloat2 { 6.0f };
    float floatMethod2(float* updatedValue)      //12
    {
        if(updatedValue != nullptr)
        {
            std::cout << "U's myFloat1 value: " << this->myFloat1 << std::endl;
            this->myFloat1 = *updatedValue;
            std::cout << "U's myFloat1 updated value: " << this->myFloat1 << std::endl;
            while( std::abs(this->myFloat2 - this->myFloat1) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                this->myFloat2 -= 1.0f;
            }
            std::cout << "U's myFloat2 updated value: " << this->myFloat2 << std::endl;
        }
        
        return this->myFloat2 * this->myFloat1;
    }
};

struct MySecondStruct
{
    static float floatMethod1(U* that, float* updatedValue )        //10
    {
        if(that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's myFloat1 value: " << that->myFloat1 << std::endl;
            that->myFloat1 = *updatedValue;
            std::cout << "U's myFloat1 updated value: " << that->myFloat1 << std::endl;
            while( std::abs(that->myFloat2 - that->myFloat1) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that->myFloat2 -= 1.0f;
            }
            std::cout << "U's myFloat2 updated value: " << that->myFloat2 << std::endl;
        }
        
        return that->myFloat2 * that->myFloat1;
    }
};
        
int main()
{
    T num1(1 , "num1");                                             //6
    T num2(2 , "num2");                                             //6
    
    MyFirstStruct f;                                            //7
    auto* smaller = f.compare(&num1 , &num2);   
    
    if(smaller != nullptr)
    {                             //8
        std::cout << "the smaller one is << " << (*smaller).name << std::endl; //9
    }      
    
    U float1;
    float updatedValue = 5.f;
    std::cout << "[static func] float1's multiplied values: " << MySecondStruct::floatMethod1(&float1, &updatedValue) << std::endl;                  //11
    
    U myLittleU;
    std::cout << "[member func] myLittleU's multiplied values: " << myLittleU.floatMethod2(&updatedValue) << std::endl;
}

        
        
        
        
        
        
        

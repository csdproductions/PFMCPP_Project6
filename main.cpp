/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;   
        return nullptr;
    }
};

struct U
{
    float myFloat1 { 8.0f }, myFloat2 { 6.0f };
    float floatMethod2(const float& updatedValue)      //12
    {

        std::cout << "U's myFloat1 value: " << this->myFloat1 << std::endl;
        this->myFloat1 = updatedValue;
        std::cout << "U's myFloat1 updated value: " << this->myFloat1 << std::endl;
        while( std::abs(this->myFloat2 - this->myFloat1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            this->myFloat2 -= 1.0f;
        }
        std::cout << "U's myFloat2 updated value: " << this->myFloat2 << std::endl;
   
        return this->myFloat2 * this->myFloat1;
    }
};

struct MySecondStruct
{
    static float floatMethod1(U& that, const float& updatedValue )        //10
    { 
        std::cout << "U's myFloat1 value: " << that.myFloat1 << std::endl;
        that.myFloat1 = updatedValue;
        std::cout << "U's myFloat1 updated value: " << that.myFloat1 << std::endl;
        while( std::abs(that.myFloat2 - that.myFloat1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.myFloat2 -= 1.0f;
        }
        std::cout << "U's myFloat2 updated value: " << that.myFloat2 << std::endl;
      
        return that.myFloat2 * that.myFloat1;
    }
};
        
int main()
{
    T num1(1 , "num1");                                             //6
    T num2(2 , "num2");                                             //6
    
    MyFirstStruct f;                                            //7
    auto* smaller = f.compare(num1 , num2);   
    
    if(smaller != nullptr)
    {                             //8
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }      
    
    U float1;
    float updatedValue = 5.f;
    std::cout << "[static func] float1's multiplied values: " << MySecondStruct::floatMethod1(float1, updatedValue) << std::endl;                   
    U myLittleU;
    std::cout << "[member func] myLittleU's multiplied values: " << myLittleU.floatMethod2(updatedValue) << std::endl;
}

        
        
        
        
        
        
        

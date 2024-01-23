# The Orthodox Canonical Class Form (OCCF)

### In C++98 and C++03 the OCCF had four different methods that the C++ compiler is willing to generate:
- **A default constructor**: used internally to initialize objects and data members when no other value is available.
- **A copy constructor**: used in the implementation of call-by-value parameters.
- **An assignment operator**: used to assign one value to another.
- **A destructor**: Invoked when an object is deleted.

--- 
```cpp
class A final
{
   public:
      A ();
      A (const A &a);
      ~A ();
      A & operator = (const A &a);
};
```

---
### In C++11 the orthodox canonical class form has changed by including two new member functions:
- Move constructor
- Move assignment operator
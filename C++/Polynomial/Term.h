template<typename T>
struct Term{
    T at_x;
    int power;
    Term *next;
    Term(): at_x(T()), power(0), next(nullptr){}
    Term(const T& item, const int& pow, Term *ptr= nullptr): at_x(item), power(pow), next(ptr){}
    ~Term() = default;
};

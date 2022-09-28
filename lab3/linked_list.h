#include <iostream>
#include <string>

class Sorted_List
{

private:
    struct Node
    {
        int value{};
        Node *next{};
    };

    Node *head{};

public:


    Sorted_List();
    ~Sorted_List();

    bool is_empty() const;

    void insert(int value, Node *curr);

    void insert(int value);

    std::string print_list() const;

    void remove(int value1);

    void clear_list();

    //Sorted_List &operator=(Sorted_List const &original);
};

struct Patient{
    char name[255], month[255];
    int date, year;
};

struct Node{
    Patient list;
    Node *next, *prev;
} *head, *tail, *curr;

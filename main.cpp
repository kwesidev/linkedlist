#include <iostream> 
//kwesidev
//playing around with LinkedList

using namespace std;

struct nodeType {
    int info;
    nodeType*link;
};

//global variables;
//global functions;

nodeType *first;


void deletenode();
void destroylist();
void insertnode();
nodeType* search(int);
void showmenu();

void displaydata();

nodeType* buildListForward() {
    nodeType *first, *newNode, *last;
    int num;
    cout << "Enter a list of integers ending with -999."
            << endl;
    cin >> num;
    first = NULL;
    while (num != -999) {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = NULL;
        if (first == NULL) {
            first = newNode;
            last = newNode;
        } else {
            last->link = newNode;
            last = newNode;
        }
        cin >> num;
    } //end while

    return first;
}

int main() {

    unsigned int choi;
    showmenu();
    cin>>choi;
    while (choi != -999) {
        switch (choi) {

            case 1:
                first = buildListForward();
                break;

            case 2:
                insertnode();

                break;

            case 3:

                deletenode();


                break;

            case 4:
                cout << "*************************************************" << endl;
                displaydata();
                cout << "*************************************************" << endl;
                break;
            default:
                cout << "Invalid value";

        }

        showmenu();
        cin>>choi;

    }


    return 0;
}

void displaydata() {
    nodeType*current;

    current = first;

    while (current != NULL) {
        cout << current->info << endl;
        current = current->link;
    }


}

nodeType* search(int i) {
    bool found = false;

    nodeType*current;
    current = first;

    while ((current != NULL)&&(found == false)) {
        if (current->info == i)
            found = true;

        else

            current = current->link;

    }


    if (found == false)
        return NULL;


    return current;
}

void deletenode() {

    int num;
    cout << "Element to be deleted ? ";
    cin>>num;

    nodeType*before, *current;
    if (first->info == x) //delete if its first element in the list
    {
        current = first;
        first = first->link;

        delete current;
        return;
    }

    bool found = false;

    current = first->link;
    before = first;



    while ((current != NULL)&&(found == false)) {

        if (current->info == x)
            found = true;
        else {
            current = current->link;
            before = before->link;
        }

    }

    if (found == false) {

        cout << "Cannot delete because the element does not exists" << endl;
        return;
    }


    before->link = current->link;
    delete current;


}

void showmenu() {
    cout << "1):Enter numbers" << endl;
    cout << "2):Inser Node after a particular number " << endl;
    cout << "3):Delete a node" << endl;
    cout << "4):Display DATA" << endl;
}

void insertnode() {
    int number;
    cout << "Enter a  number to be inserted after" << endl;

    cin>>x;

    nodeType*current, *newnode;
    current = search(x);
    if (current == NULL) {
        cerr << "Node cannot be inserted !!" << endl;
        return;
    }
    newnode = new nodeType;
    cout << "Enter the number you want to insert" << endl;
    cin>>x;
    newnode->info = x;
    newnode->link = current->link;
    current->link = newnode;
}

void destroylist() {

    if (first == NULL) //terminate if list is empty
        return;

    nodeType*current;

    nodeType*temp;

    current = first;

    while (current->link != NULL) {

        temp = current;
        delete temp;

        current = current->link;

    }

}

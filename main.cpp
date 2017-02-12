#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include "BigInteger.h"

using namespace std;

ostream& operator<<(ostream& out, const Node& node) {
    Node n2 = node;
    Node* p = &n2;
    out << p->data << " ";
    while(p->next) {
        p = p->next;
        out << p->data << " ";
    }
    return out;
}


ostream &operator<<(ostream &out, const BigInteger &bigInteger)  {
    string str = "";
    Node *head = bigInteger.num->head;
    while (head) {
        str += to_string(head->data);
        head = head->next;
    }
    reverse(str.begin(), str.end());
    if (str == "")
        str = "0";
    out << str;
    return out;
}


int main (int argc, char* argv[]) {

    // below reads the input file
    // in your next projects, you will implement that part as well
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;

    ifstream infile(argv[1]);
    string line;
    vector<string> input;
    freopen(argv[2],"w",stdout);

    for (int i = 0; i < 2004; ++i) {
        for(int j=0; j<3;++j) {

            string numb;
            infile >> numb;
            cout << numb <<" ";

        }
        cout<<endl;
    }

}
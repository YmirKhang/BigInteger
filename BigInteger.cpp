
#include "BigInteger.h"
#include <algorithm>


    // Constructor by number

    BigInteger::BigInteger(int number) {
        num = new LinkedList();
        int c;
        while(number!=0){
            c= number%10;
            num->pushTail(c);
            number= number/10;
        }

    }

    //Contstruct from String
    BigInteger::BigInteger(const string &bigInteger) {
        int i,a,len=0;

        num= new LinkedList();


        for(i=0;bigInteger[i]!='\0';i++){
            len++;
        }
                for(i=len-1;i>=0;i--){
            a= bigInteger[i] -'0';
            num->pushTail(a);
        }

    }
    //Copy Constructor
    BigInteger::BigInteger(const BigInteger &other) {
        num = new LinkedList();
        *num = *other.num;
    }
    //Destructor, destructs the num which is newly allocated every instantiation.
    BigInteger::~BigInteger() {
        delete num;
    }
    // Plus operator overloaded to add 2 big integers
    BigInteger BigInteger::operator+(const BigInteger &list) {
        LinkedList* res = new LinkedList;
        LinkedList* op1;
        op1 = new LinkedList(*num);
        LinkedList* op2;
        op2 = new LinkedList(*list.num);
       *res= *op1 + *op2;
        BigInteger *result = new BigInteger;
        *result->num= *res;
        //to shift the carries left
        int carry=0;
        Node *head = result->num->head;
        while (head) {
            head->data = head->data + carry;
            carry = head->data / 10;
            head->data = head->data % 10;
            head = head->next;
        }

        if(carry!=0){

            result->num->pushTail(carry);
        }

        BigInteger *returned=new BigInteger(*result);
        return *returned;

    }
    //* operator overloaded to mult two big integers. This function calls the other * operator to complete the multiplication
    BigInteger BigInteger::operator*(const BigInteger &list) {
        BigInteger op1(*this);
        BigInteger op2(list);
        BigInteger result(0);
        BigInteger temp(0);

        Node *head = op2.num->head;
        int inc = 0;
        while(head){
            temp.num = new LinkedList();
            //calls the integer multiplication
            temp = op1*head->data;
            for(int i=0;i<inc;i++){
                temp.num->pushHead(0);
            }
            result = result + temp;
            head = head->next;
            inc++;

        }



        return result;
    }
    // * operator overloaded for big integer and integer multiplication
    BigInteger BigInteger::operator*(int i) {
        LinkedList* res = new LinkedList;
        *res= *num;
        BigInteger *result = new BigInteger;
        *result->num=*res;
        Node *head = result->num->head;
        Node *head2 = result->num->head;
            while(head){
                head->data=head->data*i;
                head = head->next;
            }

        int carry=0;
            while(head2){
                head2->data=head2->data+carry;
                carry=head2->data/10;
                head2->data = head2->data%10;
                head2 =head2->next;

            }
        //to shift the carries if they still exist.
        if(carry!=0){
            while(carry>9){
                result->num->pushTail(carry%10);
                carry= carry/10;
            }
            result->num->pushTail(carry);

        }
        BigInteger *returned = new BigInteger(*result);
        return *returned;

    }
    // assignment operator overloaded
    BigInteger& BigInteger::operator=(const BigInteger &list) {
        delete this->num;
        num = new LinkedList();
        Node *temp = list.num->head;
            while(temp){
                this->num->pushTail(temp->data);
                temp=temp->next;
            }
        return *this;
    }


/*ostream &operator<<(ostream &out, const BigInteger &bigInteger)  {
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
*/
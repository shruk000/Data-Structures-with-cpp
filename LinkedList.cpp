#include <iostream>
using namespace std;

class list{

    private:

    class node{
    public:
        int value;
        node *next;
    };
    node *head;
    int length=0;

    node* traverseEnd(){
        node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        return temp;
    }





    public :
    list(){
        head=nullptr;
        length=0;
    }
    list(int val){
        head=(node *)malloc(sizeof(node));
        head->value=val;
        head->next=nullptr;
        length++;
    }

   

    list* insertEnd(int val){
        node* temp=(node *)malloc(sizeof(node));
        temp->value=val;
        temp->next=nullptr;
        traverseEnd()->next=temp;
        length++;
        return this;
    }

    list* insertStart(int val){
        node* temp=(node *)malloc(sizeof(node));
        temp->value=val;
        temp->next=head;
        head=temp;
        length++;
        
        return this;
    }

    list* printList(){
        node *temp=head;
        cout<<": ";
        while(temp!=nullptr){
            cout<<temp->value<<" <- ";
            temp=temp->next;
        }
        return this;
    }


    // reversing using linkes Attached..
    void reverseList(){
        node* temp=head;
        if((temp==nullptr)||(temp->next==nullptr)){
            cout<<"no reverse needed";
            return;
        }
        node* forwardPointer=temp->next->next;
        node* backPointer=temp;
        node* current=temp->next;
        backPointer->next=nullptr;

        while(forwardPointer!=nullptr){
            current->next=backPointer;
            backPointer=current;
            current=forwardPointer;
            forwardPointer=forwardPointer->next;
        }
        current->next=backPointer;
        backPointer=current;
        head=current;
        return;

    }

    bool deleteFirst(){
        if(head==nullptr){
            return false;
        }
        node *del=head;

        head=head->next;
        free(del);
        length--;
        return true;
    }
    

   // pos start from 1.... first element =1
    bool deleteElementPos(int pos){
        if(pos>length){
            cout<<endl<<"length is much shorter   Length= "<< length<<endl;
        }
     
        if(pos==1){
            return deleteFirst();
        }
        node *temp=head;

        
        
        while(temp->next!=nullptr){
            pos--;
            if(pos==1){
                node *del=temp->next;
                temp->next=temp->next->next;
                free(del);
                length--;
                return true;
            }
            temp=temp->next;
        }
        return false;
    }



};




int main(){
    list test1=list(1);
    test1.insertEnd(2);
    test1.insertStart(4)->insertStart(5)->insertStart(8);

    
    test1.printList();
    test1.reverseList();
    test1.printList();

    // cout<<" output-- " <<test1.deleteElementPos(8)<<endl;
    // test1.printList();



return 0;
}
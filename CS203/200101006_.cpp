#include<iostream>
using namespace std;

//Circular Doubly LinkedList Class

class circularDoublyLinkedList{
    public:
    int data;
    circularDoublyLinkedList *next;
    circularDoublyLinkedList *previous;
    circularDoublyLinkedList(){
        data = 0;
        next = NULL;
        previous = NULL;
    }
};


circularDoublyLinkedList* createNew(){
    circularDoublyLinkedList *newNode = new circularDoublyLinkedList;
    return newNode;
}
void addB(circularDoublyLinkedList *&head, circularDoublyLinkedList *&tail,int data){
    if(head == NULL){
        circularDoublyLinkedList *newNode = createNew();
        newNode->data = data;
        head = newNode;
        tail = newNode;
        newNode->previous = tail;
        newNode->next = head;
        return;
    }
    circularDoublyLinkedList *newNode = createNew();
    newNode->data = data;
    newNode->next = head;
    newNode->previous = tail;
    head = newNode;
    tail->next = head;
}

void addE(circularDoublyLinkedList* &head, circularDoublyLinkedList* &tail,int data){
    if(head == NULL){
        addB(head, tail,data);
        return;
    }
    circularDoublyLinkedList *newNode = createNew();
    newNode->data = data;
    newNode->next = head;
    newNode->previous = tail;
    tail = newNode;
   
}
bool isMirrorPoint(circularDoublyLinkedList * &head, circularDoublyLinkedList * &tail,circularDoublyLinkedList * &point){
    circularDoublyLinkedList* backward=point->previous, *forward=point->next;
    while(forward != backward){
        if(forward->data != backward->data){
            return false;
        }
        forward=forward->next;
        backward = backward->previous;
    }
    return true;
}
int index(circularDoublyLinkedList * &head, circularDoublyLinkedList * &tail,circularDoublyLinkedList * temp){
    int index = 0;
    circularDoublyLinkedList *temporary = head;
    while(temporary!=temp){
        index++;
        temporary = temporary->next;
    }
    return index;
}
void printMirrorPointStatus(circularDoublyLinkedList * &head, circularDoublyLinkedList * &tail){
    int totalPoints = 0;
    int arr[50];
    circularDoublyLinkedList *temp = head;
    while(temp != tail){
        if(isMirrorPoint(head,tail,temp)){
            arr[totalPoints++] = index(head,tail,temp);
        }
        temp = temp->next;
    }
    cout<<"Total mirror points: "<<totalPoints<<" ";
    for(int i = 0; i<totalPoints; i++)
    cout<<arr[i]<<" ";
}
//Function to see the current status of the list.
void printList(circularDoublyLinkedList * &head, circularDoublyLinkedList * &tail){
    if(head!=NULL){
        circularDoublyLinkedList *temp = head;
        while(temp!=tail){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    cout<<temp->data<<" ";
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    circularDoublyLinkedList *head;
    circularDoublyLinkedList *tail;
    int command = 0;
    while(command<10){
        int code;
        cin>>code;
        switch(code){
            case 1 : {
                head = NULL;
                tail = NULL;
                command++;
             
            }
            break;
            case 2 : {
                int value;
                cin>>value;
                addB(head,tail,value);
                command+=2;
            
            }
            break;
            case 3 : {
                int value;
                cin>>value;
                addE(head,tail,value);
                command+=2;
               
            }
            break;
            case 4 : {
                printMirrorPointStatus(head,tail);
             
                command++;
            }
            break;
            default : cout<<"Unknown command"<<endl;
        }
    }
   
}

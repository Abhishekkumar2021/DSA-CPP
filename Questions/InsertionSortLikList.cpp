#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertAtCorrectPosition(ListNode * &head, ListNode* node){
    if(head==NULL)
    head = node;
    else{
        ListNode*temp = head;
        ListNode*prev = NULL;
        while(temp!=NULL && temp->val < node->val){
            prev = temp;
            temp= temp->next;
        }
        if(prev==NULL){
            node->next = head;
            head = node; 
        }else{
            node->next = prev->next;
            prev->next = node;
        }
    }
}
ListNode* insertionSortList(ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;
    ListNode*sorted = NULL;
    ListNode*current = head;
    while(current!=NULL){
        ListNode*temp = current;
        current=current->next;
        temp->next = NULL;
        insertAtCorrectPosition(sorted,temp);
    }
    return sorted;
}
void solve(){
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        ListNode* newNode = new ListNode(x);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<"\n";
    // ListNode* newNode1 = new ListNode(4);
    //     insertAtCorrectPosition(head,newNode1) ;
    // ListNode* newNode2 = new ListNode(8);
    //     insertAtCorrectPosition(head,newNode2) ;
    // ListNode* newNode3 = new ListNode(90);
    //     insertAtCorrectPosition(head,newNode3) ;
    ListNode* temp2 = insertionSortList(head);
    while(temp2!=NULL){
        cout<<temp2->val<<" ";
        temp2=temp2->next;
    }
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}
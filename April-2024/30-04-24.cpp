//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        while (l1 && l1->data == 0)
            l1 = l1->next;
        while (l2 && l2->data == 0)
            l2 = l2->next;
        if(!l1 && !l2)
            return new Node(0);
       stack<int>stk1,stk2;
        while(l1){
            stk1.push(l1->data);
            l1=l1->next;
        }
        while(l2){
            stk2.push(l2->data);
            l2=l2->next;
        }
        Node* temp=NULL;
        int carry=0;
        while(!stk1.empty() || !stk2.empty() || carry){
            int digit1= !stk1.empty() ? stk1.top() : 0;
            int digit2= !stk2.empty() ? stk2.top() : 0;
            int sum=digit1+digit2+carry;
            carry=sum/10;
            Node* newNode=new Node(sum%10);
            newNode->next=temp;
            temp=newNode;
            if(!stk1.empty())
                stk1.pop();
            if(!stk2.empty())
                stk2.pop();
        }
        return temp;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends

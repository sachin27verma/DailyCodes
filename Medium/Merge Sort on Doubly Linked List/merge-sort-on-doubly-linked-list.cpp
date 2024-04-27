//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    Node *findmiddle(Node *head)
    {
        if(!head || !head->next)
        return head;
        Node *slow=head;
        Node *fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node *merge(Node *left,Node *right)
    {
        if(!left)
        return right;
        if(!right)
        return left;
        if(left->data < right->data)
        {
            left->next=merge(left->next,right);
            left->next->prev=left;
            left->prev=NULL;
            return left;
        }
        else
        {
            right->next=merge(left,right->next);
            right->next->prev=right;
            right->prev=NULL;
            return right;
        }
    }
    
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        
        if(!head || !head->next)
        return head;
        
        Node *mid=findmiddle(head);
        Node *nextomiddle=mid->next;
        mid->next=NULL;
        nextomiddle->prev=NULL;
        Node *left=sortDoubly(head);
        Node *right=sortDoubly(nextomiddle);
        return merge(left,right);
        
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
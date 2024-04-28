//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node *beforemiddle(Node *head)
    {
        Node *temp=NULL;
        if(!head || !head->next)
        return temp;
        Node *slow=head;
        Node *fast=head->next;
        while(fast && fast->next)
        {
            temp=slow;
            
            slow=slow->next;
            fast=fast->next->next;
        }
        int ct=oe(head);
        if(ct%2==0)
        {
            return slow;
        }
        else
        {
            return temp;
        }
        
    }
    int oe(Node *head)
    {
        int ct=0;
        while(head)
        {
            head=head->next;
            ct++;
        }
        return ct;
    }
    Node* deleteMid(Node* head)
    {
        if(!head->next)
        {
            return NULL;
        }
        // Your Code Here
        Node *middle=beforemiddle(head);
        // int ct=oe(head);
        // // cout <<ct<<endl;
        // if(ct%2==0)
        // {
        //     middle=middle->next->next;
        // }
        // else
        // {
        middle->next=middle->next->next;
            
        // }
        return head;
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends
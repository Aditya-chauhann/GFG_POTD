//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}


// } Driver Code Ends
class Solution {
  public:
    void convert(Node *head, TreeNode *&root) 
{
    queue<TreeNode *> q;
    Node *temp = head;

    TreeNode *curr = (TreeNode *)malloc(sizeof(TreeNode));
    curr->data = head->data;
    curr->left = NULL;
    curr->right = NULL;
    root = curr;
    q.push(curr);;
    while(q.size())
    {
         int len = q.size();
         for(int i = 0 ; i < len; i++)
         {
            TreeNode *temp1 = q.front();
            q.pop();
            //cout << temp1->data << " ";
            temp = temp->next;
            if(temp)
            {
                TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
                new_node->data  = temp->data;
                new_node->left  = NULL;
                new_node->right = NULL;
                temp1->left = new_node;
                q.push(temp1->left);
            }
            else
            {
                temp1->left = NULL;
                //temp1->right = NULL;
                return;
            }
            temp = temp->next;
            if(temp)
            {
                TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
                new_node->data  = temp->data;
                new_node->left  = NULL;
                new_node->right = NULL;
                temp1->right = new_node;
                q.push(temp1->right);
            }
            else
            {
                //temp1->left = NULL;
                temp1->right = NULL;
                return;
            }
            
         }
    }
}
};


//{ Driver Code Starts.

int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        Solution obj;

        obj.convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends

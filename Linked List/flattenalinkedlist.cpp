// Problem- Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// solution -
class compare{
    public:
        int operator()(Node *a, Node *b){
            return b->data<a->data;
        }
};

Node *flatten(Node *root)
{
    priority_queue<Node *, vector<Node*>, compare> pq;
    Node * temp=root;
    while(temp!=NULL)
    {
        pq.push(temp);
        temp=temp->next;
    }
    Node * head=new Node(0);
    temp=head;
    while(!pq.empty())
    {
        Node * t=pq.top();
        pq.pop();
        temp->bottom=t;
        temp=temp->bottom;
        if(t->bottom!=NULL)
        {
            pq.push(t->bottom);
        }
    }
    return head->bottom;
}

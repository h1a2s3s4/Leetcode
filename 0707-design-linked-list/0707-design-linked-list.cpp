class MyLinkedList {
public:
    ListNode*first=NULL;
    MyLinkedList() {
         
    }
    
    int get(int index) {
        ListNode*p=first;
        int count=0;
        while(count!=index&&p!=NULL){
            p=p->next;
            count++;
        }
        if(p==NULL){
            return -1;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode*curr=new ListNode(val);
        if(first==NULL){
            first=curr;
        }
        else{
            curr->next=first;
            first=curr;
        }
    }
    
    void addAtTail(int val) {
        ListNode*curr=new ListNode(val);
        if(first==NULL){
            first=curr;
        }
        else{
            ListNode*p=first;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=curr;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return ;
        }
        ListNode*curr=new ListNode(val);
        int count=0;
        ListNode*p=first;
        while(count<(index-1)&&p!=NULL){
            p=p->next;
            count++;
        }
        if(p!=NULL){
            curr->next=p->next;
            p->next=curr;
        }
    }
    
    void deleteAtIndex(int index) {
        if(first==NULL){
            return ;
        }
        if(index==0){
            ListNode*temp=first;
            first=first->next;
            delete temp;
            return ;

        }
        int count=0;
        ListNode*p=first;
        while(count<(index-1)&&p!=NULL){
            p=p->next;
            count++;
        }
        if(p!=NULL&&p->next!=NULL){
            ListNode*temp=p->next;
            p->next=temp->next;
            delete temp;

        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
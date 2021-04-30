// kth smallest in a bst

/*stack<Node*> stk;  
    Node *tmp = root;
    while(tmp != NULL){
        stk.push(tmp);
        tmp = tmp->left;
    } 
    int i = 1;
    while(i < k and !stk.empty()){
        tmp = stk.top();
        stk.pop();
        Node *tmp2 = tmp->right;
        while(tmp2 != NULL){
            stk.push(tmp2);
            tmp2 = tmp2->left;
        }
        i++;
    }
    if(stk.empty() and k) return -1;
    tmp = stk.top();
    return tmp->data;*/
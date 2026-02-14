int similar(TreeNode T1,TreeNode T2){
    int lefts,rights;
    if(T1==NULL&&T2==NULL)
        return 1;
    else if(T1==NULL&&T2==NULL)
        return 0;
    else{
        lefts=similar(T1->left,T2->right);
        rights=similar(T1->right,T2->right);
        return lefts&&rights;
    }
}
void get_next(SString t,int next[]){
    int i=1;
    int j=0;
    next[1]=0;
    while(i<t.length){
        if(j==0||t.ch[i]==t.ch[j]){
            ++i;++j;
            next[i]=j;
        }else j=next[j];
    }
}
void get_nextval(SString t,int nextval[]){
    int i=1;
    int j=0;
    nextval[1]=0;
    while(i<t.length){
        if(j==0||t.ch[i]==t.ch[j]){
            ++i;++j;
            if(t.ch[i]!=t.ch[j])nextval[i]=j;
            else nextval[i]=nextval[j];
        }else j=nextval[j];
    }
}
int index_kmp(SString s,SString t,int pos,int next[]){
    int i=pos,j=1;
    while(i<=s.length&&j<=t.length){
        if(s.ch[i]==s.ch[j]){
            ++i;++j;
        }else j=next[j];
    }
    if(j>t.length)return i-t.length;
    else return 0;
}//数组下标从0开始 
void get_next(char *txt,int *next,int txt_size)
{
    int j=0,k=-1;
    next[j]=-1;
    while(j<txt_size-1)
    {
        if(k==-1 ||txt[j]==txt[k])
        {
            ++j;++k;
            next[j]=k;
        }
        else k=next[k];
    }
}
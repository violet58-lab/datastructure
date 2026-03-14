void quickSort(int arr[],int start,int end){//快速排序，很重要
    if(start>=end)return;
    int left=start,right=end,pivot=arr[left];//以第一个为基准
    while(left<right){
        while(left<right && arr[right]>=pivot)right--;
        arr[left] = arr[right];//遇到比基准小的，丢到左边去
        while(left<right && arr[left]<=pivot)left++;
        arr[right] = arr[left];//遇到比基准大的，丢到右边去
    }
    arr[left] = pivot;//相遇的位置就是存放基准的位置了
    quickSort(arr,start,left-1);
    quickSort(arr,right+1,end);
}//不稳定
int quickSort1(int arr[],int start,int end,int k){
    if(start>=end)return arr[start];//递归到区间长度只剩1，直接返回
    int left=start,right=end,pivot=arr[left];//以第一个为基准
    while(left<right){
        while(left<right && arr[right]>=pivot)right--;
        arr[left] = arr[right];//遇到比基准小的，丢到左边去
        while(left<right && arr[left]<=pivot)left++;
        arr[right] = arr[left];//遇到比基准大的，丢到右边去
    }
    arr[left] = pivot;//相遇的位置就是存放基准的位置了
    if(left == k-1)return arr[left];
    else if(left > k-1)
        return quickSort1(arr,start,left-1,k);
    else
        return quickSort1(arr,left+1,end,k);
}
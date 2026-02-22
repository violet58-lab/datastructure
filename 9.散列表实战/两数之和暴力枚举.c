//力扣01
int * result(int i,int j,int * returnSize){
    *returnSize = 2;
    int * result = malloc(sizeof(int)*2);
    result[0] = i;
    result[1] = j;
    return result;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i=0;i<numsSize;++i){
        for(int j=0;j<numsSize;++j){
            if(i==j)continue;
            if(nums[i]+nums[j] == target)return result(i,j,returnSize);
        }
    }
    return NULL;
}
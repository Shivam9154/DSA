func permute(nums []int) [][]int {
    var ans [][]int
    solve(&ans,0,nums)
    return ans
}

func solve(ans *[][]int, index int, nums[]int){
    if index>=len(nums){
        temp:=make([]int,len(nums))
        copy(temp,nums)
        *ans=append(*ans,temp)
        return 
    }
    for i:=index;i<len(nums);i++{
        nums[index],nums[i] = nums[i],nums[index]
        solve(ans,index+1,nums)
        nums[i],nums[index] = nums[index],nums[i]
    }
}

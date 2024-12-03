def findtheduplicatenumber(nums):
    slow =  nums[0]
    fast = nums[0]

    # do while loop
    while True:
        slow = nums[slow] # move one step, nums[slow] will return the value of the index, and that will be the next index
        fast = nums[nums[fast]] # move two steps, nums[nums[fast]] will return the value of the index, and that will be the next index, and then we get the value of that index

        if slow == fast:
            break

    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]

    return slow

nums = [1, 3, 2, 2]
print(findtheduplicatenumber(nums)) # 2
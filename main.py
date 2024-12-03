# remove duplicate elements from a list
# using two pointer methof

def remove_duplicates(arr):
    left = 0
    right = 1

    while right < len(arr):
        if arr[left] == arr[right]:
            right += 1
        else:
            left += 1
            arr[left] = arr[right]
            right += 1
    return arr[:left+1]

arr = [1, 2, 2, 3, 4, 4, 4, 5, 5]
print(remove_duplicates(arr)) # [1, 2, 3, 4, 5]
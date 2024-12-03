# You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

# You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

#     You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
#     Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
#     Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

# Given the integer array fruits, return the maximum number of fruits you can pick.

 

# Example 1:

# Input: fruits = [1,2,1]
# Output: 3
# Explanation: We can pick from all 3 trees.

# Example 2:

# Input: fruits = [0,1,2,2]
# Output: 3
# Explanation: We can pick from trees [1,2,2].
# If we had started at the first tree, we would only pick from trees [0,1].

# Example 3:

# Input: fruits = [1,2,3,2,2]
# Output: 4
# Explanation: We can pick from trees [2,3,2,2].
# If we had started at the first tree, we would only pick from trees [1,2].

def totalFruit(fruits):
    start = 0
    end = 0
    max_fruit = 0
    fruit_count = {}
    while end < len(fruits):
        # Check fruit at index end is in count or not if yes then increment if no then add and set value to 1
        if fruits[end] not in fruit_count:
            fruit_count[fruits[end]] = 1
        else:
            fruit_count[fruits[end]] += 1
        
        # if the len of fruits in fruit_count goes above len 2, indicating it is exceding our two backet rule
        # then we have to remove the fruit at the start index
        while len(fruit_count) > 2:
            fruit_count[fruits[start]] -= 1
            if fruit_count[fruits[start]] == 0:
                del fruit_count[fruits[start]]
            start += 1
        max_fruit = max(end - start + 1, max_fruit)
        end += 1
    return max_fruit

# Time complexity: O(n)
# Space complexity: O(1)

fruits = [1,2,1]
print(totalFruit(fruits))
fruits = [0,1,2,2]
print(totalFruit(fruits))
fruits = [1,2,3,2,2]
print(totalFruit(fruits))
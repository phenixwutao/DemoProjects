// Ace_Leetcode_Blind75_2025
//### 001 File: 0001-two-sum/README.md
# Two Sum (Leetcode #1)

Leetcode's 'Two Sum' question is a classic problem that tests your understanding of array manipulation, hash maps, and time complexity optimization. Let's break it down step-by-step:

### **Understanding the Question**

In the 'Two Sum' problem, you are given an array of integers, `nums`, and an integer `target`. Your task is to find two distinct indices in the array such that the sum of the numbers at those indices equals the `target`.

You need to return the indices of the two numbers, and the solution should satisfy the following conditions:

* There must be exactly **one solution** (no repeated pairs).
    
* You **cannot use the same element twice**.
    

For example, given `nums = [2, 7, 11, 15]` and `target = 9`, the solution would return `[0, 1]` because `2 + 7 = 9`.

### **Brute Force Approach**

The simplest approach is to use two nested loops to check all possible pairs of numbers in the array. Here's the pseudocode for the brute force approach:

```python
for i in range(len(nums)):
    for j in range(i + 1, len(nums)):
        if nums[i] + nums[j] == target:
            return [i, j]
```

* **Explanation:**
    
    * The outer loop picks an element, and the inner loop checks every subsequent element to find a pair that sums to the target.
        
* **Time Complexity:**  
    This approach takes `O(n^2)`, where nnn is the length of the array. This is because for each element, you are iterating over the remaining elements to find a matching pair.
    
* **Space Complexity:**  
    The space complexity is `O(1)`, as no extra data structures are used except for a constant number of variables.
    

### **Efficient Solution**

The brute force solution is inefficient for large datasets. To improve, we can use a **hashmap** (or dictionary) to store numbers and their indices while iterating through the array. The provided efficient solution achieves this in a single pass.

Here’s the Python solution code provided:

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        
        for i in range(len(nums)):
            complement = target - nums[i]
            
            if complement in hashmap:
                return [hashmap[complement], i]
            
            hashmap[nums[i]] = i
```

* **Explanation:**
    
    * **hashmap = {}:** We use a hashmap (or dictionary) to store the elements as keys and their indices as values.
        
    * **complement = target - nums\[i\]:** For each element `nums[i]`, we compute its complement, which is the value we need to find in the hashmap to reach the target sum.
        
    * **if complement in hashmap:** If the complement exists in the hashmap, that means we have already encountered the number that, when added to `nums[i]`, equals the target.
        
    * **return \[hashmap\[complement\], i\]:** If the complement is found, return the indices of the two numbers.
        
    * **hashmap\[nums\[i\]\] = i:** If the complement is not found, store the current number and its index in the hashmap for future reference.
        

### **Time and Space Complexity**

* **Time Complexity:**  
    The time complexity of this solution is `O(n)`, where `n` is the length of the input array. This is because we only traverse the array once, and both the lookup and insertion operations in a hashmap are `O(1)` on average.
    
* **Space Complexity:**  
    The space complexity is `O(n)`, where `n` is the number of elements in the array. This is because we are storing up to `n` elements in the hashmap.
    

### Conclusion

The optimized solution using a hashmap reduces the time complexity from `O(n^2)` in the brute force approach to `O(n)`. It’s efficient and works well even with large datasets, making it an ideal solution for this problem.

By understanding and implementing this technique, you can effectively tackle similar problems that involve pair sums or finding elements in arrays based on certain conditions.


README for [Two Sum (Leetcode #1)](https://blog.unwiredlearning.com/two-sum) was compiled from the Unwired Learning Blog.  
//### 002 File: 0003-longest-substring-without-repeating-characters/README.md
 # Longest Substring Without Repeating Characters (Leetcode #3)
 
 The 'Longest Substring Without Repeating Characters' is one of Leetcode's classic problems that tests your understanding of efficient string manipulation. Let's walk through the problem step-by-step, explore both brute force and efficient solutions, and see how we can arrive at the best approach.

## Understanding the Problem Statement

The problem asks us to find the length of the longest substring without repeating characters in a given string. A substring is defined as a contiguous sequence of characters within a string. For example, given the string **s = "abcabcbb"**, the answer is **3**, since the longest substring without repeating characters is **"abc"**.

The challenge here is to efficiently determine this length while avoiding unnecessary operations, especially as the string size grows.

## Brute Force Approach

The brute force solution to this problem involves generating all possible substrings and checking each one for repeated characters. We can summarize the brute force approach in the following steps:

1. Start by iterating through each character in the string.
    
2. For each character, create all possible substrings starting from that character.
    
3. Check if the current substring has all unique characters.
    
4. Track the maximum length of the substrings without any repeating characters.
    

Although conceptually simple, this method is highly inefficient for long strings because it involves examining multiple overlapping substrings. The time complexity of this approach is **O(n^3)** since generating substrings and verifying uniqueness both require substantial operations.

## Hint to Solve the Problem Efficiently

Instead of generating all substrings, consider the possibility of sliding a window across the string to dynamically track the longest substring without repeating characters. You can think of this "window" as a way of expanding and shrinking the range of characters you are examining.

To solve the problem efficiently, you will need to:

1. Maintain a record of the characters you have seen, along with their positions.
    
2. Adjust the window when you encounter a repeating character to ensure it only includes unique characters.
    

## Efficient Solution

The most efficient solution to this problem is achieved using the **Sliding Window** technique along with a **HashMap** (or dictionary). The idea is to maintain two pointers, a left and a right pointer, which represent the current window of unique characters. Here is the step-by-step solution based on the uploaded code:

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index_map = {}
        max_length = 0
        left = 0
        
        for right in range(len(s)):
            if s[right] in char_index_map and char_index_map[s[right]] >= left:
                left = char_index_map[s[right]] + 1
            
            char_index_map[s[right]] = right
            max_length = max(max_length, right - left + 1)
        
        return max_length
```

In this solution:

1. **char\_index\_map** is a dictionary that stores the index of each character in the string.
    
2. **left** and **right** pointers represent the current window of unique characters.
    
3. As you iterate with **right**, whenever you encounter a character that is already in the window (i.e., between **left** and **right** pointers), you adjust the **left** pointer to exclude the repeated character.
    
4. Finally, you compute the maximum window length (**max\_length**) as you go along.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of the above solution is **O(n)**, where **n** is the length of the string. Each character is visited only once, thanks to the sliding window approach, making this solution efficient.
    
* **Space Complexity**: The space complexity is **O(min(n, m))**, where **n** is the length of the string and **m** is the size of the character set (e.g., 26 for lowercase alphabets). We use additional space to store character indices in **char\_index\_map**.
    

## Conclusion

The **Sliding Window** approach provides an optimal solution for the "Longest Substring Without Repeating Characters" problem by reducing redundant operations and ensuring each character is processed only once. This method is ideal for balancing both time and space efficiency compared to the brute force approach.


README for [Longest Substring Without Repeating Characters (Leetcode #3)](https://blog.unwiredlearning.com/longest-substring-without-repeating-characters) was compiled from the Unwired Learning Blog.  
//### 003 File: 0005-longest-palindromic-substring/README.md
# Longest Palindromic Substring (Leetcode #5)

Finding the longest palindromic substring in a given string is one of the most frequently asked questions in coding interviews, especially for roles that involve algorithms and data structures. This problem not only tests your understanding of dynamic programming but also helps you master how to optimize complex solutions. In this blog, we will explore a brute force method, delve into an efficient approach using dynamic programming, and break down the time and space complexities involved. Let's dive in!

## Understanding the Problem Statement

The goal of the "Longest Palindromic Substring" problem is to find the longest substring within a given string that reads the same backward as forward. The input is a string of characters, and you need to return the longest palindromic substring. For example, if the input string is "babad", the answer could be "bab" or "aba".

## Brute Force Approach

The most intuitive way to solve this problem is the brute force method, where we generate all possible substrings and check whether each one is a palindrome. This can be done by iterating over all possible starting and ending points of the substring and then reversing each substring to verify if it matches the original.

In Python, the brute force approach might look something like this:

1. Iterate over all pairs of start and end indices.
    
2. Check if the substring is a palindrome by reversing it.
    
3. Keep track of the longest palindrome found.
    

The brute force solution will have a time complexity of O(n^3) since it takes O(n^2) to generate all substrings and O(n) to check if each substring is a palindrome.

## Hint to Solve the Problem Efficiently

A more efficient approach involves using dynamic programming to keep track of palindromes in a 2D table. The key idea here is that a substring is a palindrome if its boundary characters are equal and the substring within those boundaries is also a palindrome. By storing these intermediate results, we can avoid redundant calculations.

## Efficient Solution

Here is the provided efficient solution that leverages dynamic programming to reduce the time complexity:

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s
        dp = [[False] * n for _ in range(n)]
        
        # Initialize start position and max length of the palindrome
        start, max_length = 0, 1

        # Base case: single character palindromes
        for i in range(n):
            dp[i][i] = True

        # Base case: two-character palindromes
        for i in range(n-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True                
            if dp[i][i+1]:
                start, max_length = i, 2

        # General case
        for length in range(3, n+1):  
            for i in range(n-length+1):
                j = i + length - 1
                if s[i] == s[j] and dp[i+1][j-1]:
                    dp[i][j] = True
                    start, max_length = i, length

        return s[start:start+max_length]
```

**Explanation of the Code**

* **Initialization**: We first initialize a 2D list `dp` to store whether a substring is a palindrome. `dp[i][j]` is True if the substring from `i` to `j` is a palindrome.
    
* **Base Cases**: We initialize all single-character substrings as palindromes (`dp[i][i] = True`). We also handle the two-character substrings.
    
* **General Case**: We iterate through possible substring lengths, starting from 3. For each substring of a given length, we check if its boundary characters are the same and if the substring within those boundaries is also a palindrome.
    
* **Return Value**: We track the starting position and length of the longest palindromic substring found, which allows us to return the desired result.
    

## Time and Space Complexity

* **Time Complexity**: The efficient solution has a time complexity of O(n^2). This is because we fill out a 2D table of size `n x n` by iterating over all substrings of increasing length.
    
* **Space Complexity**: The space complexity is also O(n^2), as we store the results for all possible substrings in a 2D list. This helps in avoiding redundant calculations and contributes to the optimized solution.
    

## Conclusion

The "Longest Palindromic Substring" problem can initially seem challenging, especially with the brute force approach being highly inefficient. However, with the help of dynamic programming, we can significantly reduce the time complexity and solve the problem effectively. Mastering this efficient approach will not only help you tackle similar problems but also improve your overall problem-solving skills for coding interviews.

README for [Longest Palindromic Substring (Leetcode #5)](https://blog.unwiredlearning.com/longest-palindromic-substring) was compiled from the Unwired Learning Blog.  
//### 004 File: 0011-container-with-most-water/README.md
# Container With Most Water (Leetcode #11)

In this blog, we will solve LeetCode's 'Container With Most Water' question. We'll start by explaining the problem, discussing a brute-force approach, giving you a hint, and ultimately providing an efficient solution along with its time and space complexity analysis.

## Understanding the Problem Statement

The problem asks you to find two vertical lines from a given array of heights that together with the x-axis, can contain the maximum amount of water. The heights are represented by an array where each element represents the height of a vertical line. You need to identify the pair of lines that, together with the x-axis, form a container capable of holding the most water.

To illustrate: Imagine the heights as the walls of a container and the x-axis as the base. The goal is to find the largest possible container, i.e., the maximum area enclosed by the container walls. You are given an array of non-negative integers, and the area between any two lines is calculated as the product of the distance between the lines and the minimum height of the two lines.

## Brute Force Approach

The brute-force approach to solve this problem is relatively simple: iterate over all possible pairs of lines, calculate the area for each pair, and keep track of the maximum area.

In Python, the brute-force solution would look like:

```python
# Brute-Force Approach
def max_area_bruteforce(height):
    max_area = 0
    n = len(height)
    for i in range(n):
        for j in range(i + 1, n):
            area = min(height[i], height[j]) * (j - i)
            max_area = max(max_area, area)
    return max_area
```

The nested loop goes through each possible pair of indices and calculates the area, storing the maximum found. However, this approach has a time complexity of **O(n^2)**, which makes it inefficient for large input sizes.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, think about reducing the number of comparisons. Instead of checking every possible pair, consider the impact of the width and height on the area. You can use a two-pointer technique to start from the edges and move towards the middle, always keeping track of the maximum area.

The idea here is that by maximizing the width initially and then trying to find a taller line as you move the pointers, you can keep finding areas that have the potential to be the largest.

## Efficient Solution

Here is the efficient solution using the two-pointer technique:

```python
# Efficient Solution
def max_area(height):
    left = 0
    right = len(height) - 1
    max_area = 0

    while left < right:
        # Calculate the area for the current pair of pointers
        area = min(height[left], height[right]) * (right - left)
        # Update the maximum area if the current area is larger
        max_area = max(max_area, area)

        # Move the pointer with the shorter line
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_area
```

**Explanation**

In this solution, we initialize two pointers: `left` at the beginning of the list and `right` at the end. We calculate the area between the two pointers and update the maximum area if the current area is larger.

The key decision is which pointer to move. To maximize the area, we always move the pointer pointing to the shorter line, hoping to find a taller line in subsequent steps that will increase the area. We continue until the two pointers meet.

This approach drastically reduces the number of computations compared to the brute-force solution.

## Time and Space Complexity

* **Time Complexity**: The efficient solution has a time complexity of **O(n)**, where `n` is the number of elements in the input array. This is because each pointer only moves from one end to the other, leading to a single pass through the array.
    
* **Space Complexity**: The space complexity is **O(1)** since we are using only a fixed amount of extra space, independent of the input size.
    

The two-pointer technique offers a significant improvement over the brute-force approach and efficiently solves the problem in linear time.

## Conclusion

The 'Container With Most Water' problem is a classic example that demonstrates how a seemingly complex problem can be solved efficiently using the two-pointer technique. By strategically moving the pointers and reducing the problem space, we can find the optimal solution in linear time, which is a significant improvement over the brute-force approach. Understanding this technique can help you solve many other problems where maximizing or minimizing a value is involved while considering multiple elements in an array. Always remember, efficient problem-solving is about reducing unnecessary calculations and focusing on the core logic.


README for [Container With Most Water (Leetcode #11)](https://blog.unwiredlearning.com/container-with-most-water) was compiled from the Unwired Learning Blog.  
//### 005 File: 0015-3sum/README.md
# 3Sum (Leetcode #15)

The "3Sum" problem is one of the most popular algorithm challenges on Leetcode, often encountered by developers preparing for technical interviews. The goal is to identify unique triplets in an integer array that sum up to zero. While it seems straightforward at first glance, solving it efficiently requires a solid understanding of sorting, searching techniques, and eliminating duplicates. In this blog, we'll explore both the brute force and efficient approaches to solving the "3Sum" problem, and help you gain a deeper understanding of its complexities.

## Understanding the Problem Statement

The Leetcode problem **"15. 3Sum"** is a classic algorithm problem where you are tasked to find unique triplets in an array that add up to zero. Given an integer array `nums`, your job is to find all distinct triplets `[nums[i], nums[j], nums[k]]` such that they add up to zero, and all indices `i`, `j`, `k` are distinct.

For instance, given the array `nums = [-1, 0, 1, 2, -1, -4]`, the solution would be `[[ -1, -1, 2], [-1, 0, 1]]`. Here, the challenge is not only to find the triplets but also to ensure they are unique, meaning no duplicate solutions.

The array may contain both positive and negative integers, and it's your task to use an efficient algorithm to solve this within a reasonable time limit. Let’s dive into how we can achieve this.

## Brute Force Approach

A straightforward approach to solving this problem is to use three nested loops to iterate through all possible combinations of numbers. Essentially, we would pick three elements at different indices and check if they sum to zero. Here is a rough idea of how the brute force solution might look:

1. Iterate through the array, using three nested loops.
    
2. Check each combination and see if the sum equals zero.
    
3. Store the combination if it satisfies the condition and isn’t a duplicate.
    

While simple to understand, this approach suffers from high computational complexity. Specifically, it has a time complexity of **O(N^3)**, making it impractical for large input arrays due to its inefficiency. This method would also require extra handling to ensure no duplicate triplets are included, further complicating things.

## Hint to Solve the Problem Efficiently

Before diving into the efficient solution, here's a hint for optimizing the brute force approach:

* Sort the array first. This allows you to efficiently avoid duplicate triplets and make use of a more strategic searching method.
    
* Consider how you might reduce three nested loops to just two using a two-pointer technique.
    

Sorting and using two pointers can significantly reduce unnecessary computations and help eliminate duplicates with ease.

## Efficient Solution

The efficient approach leverages sorting and the two-pointer technique. Here's how we can solve the problem step-by-step:

1. **Sort the Array**: Begin by sorting the array. This helps in easily skipping over duplicates and using two pointers effectively.
    
2. **Iterate with a Fixed Pointer**: Use a loop to fix one number, then apply a two-pointer approach for the remaining sub-array.
    
3. **Two-Pointer Technique**: For each fixed element, use two pointers to find the remaining two elements that sum to zero. Start with one pointer at the next element (`left`), and the other pointer at the end (`right`) of the array.
    
4. **Check and Adjust Pointers**: If the sum of the three elements is zero, add it to the result. If the sum is less than zero, increment the `left` pointer; if it's greater, decrement the `right` pointer. This helps in narrowing down the search efficiently.
    

Here’s the code that implements this approach (based on your provided code):

```python
class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = []
        
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue  # Skip duplicates for the first number
            
            left, right = i + 1, len(nums) - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total == 0:
                    result.append([nums[i], nums[left], nums[right]])
                    
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1  # Skip duplicates for the second number
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1  # Skip duplicates for the third number
                    
                    left += 1
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    right -= 1
        
        return result
```

## Time and Space Complexity

The **time complexity** of this efficient solution is **O(N^2)**, where `N` is the number of elements in the array. Here's why:

* Sorting the array takes **O(N log N)**.
    
* After sorting, we iterate through the array, and for each element, we use the two-pointer technique, which takes **O(N)** time.
    
* Therefore, the overall complexity becomes **O(N log N) + O(N^2) ≈ O(N^2)** for large values of `N`.
    

The **space complexity** is **O(1)** (ignoring the space used for output), as we are not using any additional data structures that grow with input size. The solution modifies pointers in-place and only requires extra space for storing the result.

## Conclusion

The "3Sum" problem is a great example of how simple techniques like sorting and the two-pointer approach can drastically improve efficiency compared to a brute force solution. Understanding the problem, trying the brute force approach, and then optimizing is a powerful problem-solving strategy in algorithm challenges.

By mastering these concepts, you can handle not only the "3Sum" problem but also a wide range of other problems that rely on finding combinations or subsets of elements efficiently.


README for [3Sum (Leetcode #15)](https://blog.unwiredlearning.com/3sum) was compiled from the Unwired Learning Blog.  
//### 006 File: 0019-remove-nth-node-from-end-of-list/README.md
# Remove Nth Node From End of List (Leetcode #19)

The "Remove Nth Node From End of List" problem from Leetcode is a common question in coding interviews, particularly when dealing with linked lists. In this blog, we'll cover the problem statement, discuss a brute force approach, give hints, and present an efficient solution with its time and space complexity.

## Understanding the Problem Statement

You are given a singly linked list and need to remove the Nth node from the end of the list. The problem's goal is to modify the list in-place and return its head after removing the node. For example, given the list 1 → 2 → 3 → 4 → 5 and N = 2, the resulting list should be 1 → 2 → 3 → 5.

## Brute Force Approach

A common brute force approach to solve this problem would be:

1. First, traverse through the entire linked list to determine its length, `L`.
    
2. Calculate the position of the Nth node from the start: `L - N + 1`.
    
3. Traverse the linked list again to this calculated position.
    
4. Update pointers to remove the desired node.
    

This approach, however, requires two passes through the list, which makes it inefficient for larger linked lists.

## Hint to Solve the Problem Efficiently

A more efficient solution can be implemented by utilizing the "two-pointer technique". By using two pointers—one called `fast` and one called `slow`—you can keep a gap of `n` nodes between them and traverse the list in a single pass. This technique helps to directly reach the node that needs to be removed without the need to calculate its position.

## Efficient Solution

Let's walk through an efficient approach that uses only one pass, based on the given code:

```python
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)  # Create a dummy node to simplify edge cases
        dummy.next = head
        slow, fast = dummy, head
        
        # Move fast pointer so that the gap between slow and fast is n nodes apart
        for _ in range(n):
            fast = fast.next
        
        # Move fast to the end, maintaining the gap
        while fast:
            fast = fast.next
            slow = slow.next
        
        # Skip the desired node
        slow.next = slow.next.next

        # Return head of the modified list
        return dummy.next
```

**Explanation:**

1. A dummy node is created to handle edge cases (e.g., when the node to be removed is the head).
    
2. Two pointers—`slow` and `fast`—are initialized, with the `fast` pointer starting at the head and the `slow` pointer starting at the dummy node.
    
3. The `fast` pointer moves ahead by `n` nodes, creating a gap of `n` nodes between `slow` and `fast`.
    
4. Both pointers move one node at a time until `fast` reaches the end of the list.
    
5. The `slow` pointer is now just before the node that needs to be removed. The next pointer of `slow` is updated to skip the node to be removed.
    
6. Finally, the modified list's head is returned.
    

## Time and Space Complexity

* **Time Complexity:** The time complexity for this solution is **O(N)**, where `N` is the number of nodes in the linked list. This is because we only make one pass through the list.
    
* **Space Complexity:** The space complexity is **O(1)**, as we are only using a few pointers and not allocating any extra space for data structures that grow with the input size.
    

The two-pointer approach is efficient and ideal for solving this problem in a single traversal, making it a significant improvement over the brute force approach.

## Conclusion

The "Remove Nth Node From End of List" problem is a great example of how linked list problems can often be solved efficiently using pointer manipulation. By understanding the two-pointer technique, we can solve this problem in a single traversal, optimizing both time and space complexity. This approach not only demonstrates an efficient solution but also highlights the importance of using dummy nodes to simplify edge cases in linked list operations. Mastering these techniques will greatly enhance your ability to solve similar linked list problems in coding interviews.


README for [Remove Nth Node From End of List (Leetcode #19)](https://blog.unwiredlearning.com/remove-nth-node-from-end-of-list) was compiled from the Unwired Learning Blog.  
//### 007 File: 0020-valid-parentheses/README.md
# Valid Parentheses (Leetcode #20)

The 'Valid Parentheses' problem is a staple in coding interviews and serves as an excellent test of your understanding of stacks and data structures. It challenges your ability to correctly match different types of brackets, ensuring that they are properly nested and ordered. In this blog, we will explore a naive approach to solving this problem, provide a hint for an efficient solution, and then dive into an optimal approach using a stack. By the end, you'll have a thorough understanding of how to solve this problem efficiently.

## Understanding the Problem Statement

The 'Valid Parentheses' problem is a classic question often found in coding interviews. You are given a string that contains only the characters '(', ')', '\[', '\]', '{', and '}'. Your task is to determine if the input string is valid. A string is considered valid if the brackets are correctly closed in the correct order, meaning every opening bracket has a corresponding closing bracket, and they are nested properly.

For instance, the string "()\[\]{}" is valid because every type of bracket is closed correctly. However, "(\]" is not valid since the brackets are mismatched. Similarly, "(\[)\]" is not valid as the brackets are not properly nested.

## Brute Force Approach

One naive way to solve the problem is to iteratively search for matched pairs of parentheses and remove them from the string until there are no more pairs to remove. This method works by repeatedly replacing occurrences of "()", "\[\]", and "{}" with an empty string until none are left.

Although this approach will eventually determine if the string is valid, it is inefficient. The repeated scanning and string modification can lead to a time complexity of O(n^2) for a worst-case scenario, where 'n' is the length of the string. This approach also consumes extra space as it involves creating new strings during each iteration.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, think about using a data structure that allows you to easily track the order of opening brackets and quickly match them when closing brackets are found. Consider using a stack, which follows a Last In, First Out (LIFO) principle. Each time you encounter an opening bracket, push it onto the stack. When you encounter a closing bracket, check if it matches the most recently added opening bracket.

## Efficient Solution

Here is the efficient solution that makes use of a stack, as shown in the provided code:

```python
class Solution:
    def isValid(self, s: str) -> bool:
        # Initialize an empty stack to keep track of opening brackets
        stack = []

        # A mapping of closing brackets to their corresponding opening brackets
        bracket_map = {')': '(', ']': '[', '}': '{'}

        # Iterate through each character in the string
        for character in s:
            if character in bracket_map:
                # If stack is not empty and the top of the stack matches the corresponding opening bracket
                if stack and stack[-1] == bracket_map[character]:
                    stack.pop()
                else:
                    return False
            else:
                # If the character is an opening bracket, push it onto the stack
                stack.append(character)

        # After processing all characters, return True if the stack is empty (all brackets matched), else False
        return not stack
```

**Explanation**:

* We use a stack to keep track of opening brackets.
    
* Whenever an opening bracket ('(', '\[', '{') is encountered, it is pushed onto the stack.
    
* When a closing bracket (')', '\]', '}') is encountered, we check if the stack is non-empty and if the top element of the stack matches the corresponding opening bracket. If it matches, we pop the element from the stack. If it doesn’t match or the stack is empty, we return `False`.
    
* At the end of the iteration, if the stack is empty, it means that all brackets have been matched properly, and we return `True`.
    

## Time and Space Complexity

* **Time Complexity**: O(n), where 'n' is the length of the input string. We traverse the string once, and each push and pop operation on the stack takes constant time, O(1).
    
* **Space Complexity**: O(n), where 'n' is the length of the input string. In the worst case, all characters in the string could be opening brackets, leading to a stack of size 'n'.
    

This solution is efficient and provides the correct result in a single pass through the string, making it significantly better than the brute force approach.

## Conclusion

The 'Valid Parentheses' problem is an excellent demonstration of how using the right data structure can make a significant difference in the efficiency of your solution. By leveraging a stack, we can solve this problem with linear time complexity, ensuring that every bracket is properly matched and nested. Whether you're preparing for coding interviews or just looking to improve your problem-solving skills, understanding this approach will serve you well in tackling similar problems involving balanced sequences.


README for [Valid Parentheses (Leetcode #20)](https://blog.unwiredlearning.com/valid-parentheses) was compiled from the Unwired Learning Blog.  
//### 008 File: 0021-merge-two-sorted-lists/README.md
# Merge Two Sorted Lists (Leetcode #21)

The "Merge Two Sorted Lists" problem is a classic LeetCode problem often asked in technical interviews. It tests your understanding of linked lists and your ability to effectively merge two data structures.

## Understanding the Problem Statement

Given two sorted linked lists `list1` and `list2`, merge them into one sorted linked list. The merged list should be formed by splicing together the nodes of the original two lists. The solution should return the merged linked list.

For example:

* Input: `list1 = [1, 2, 4]`, `list2 = [1, 3, 4]`
    
* Output: `[1, 1, 2, 3, 4, 4]`
    

The key challenge is to maintain the sorted order while combining both linked lists.

## Brute Force Approach

One simple approach would be to traverse both linked lists, add all the elements to an array, and then sort the array. Afterward, we could create a new linked list using the sorted values. Here’s how this brute-force approach works:

1. Traverse through both `list1` and `list2`, adding each node’s value to an array.
    
2. Sort the array in ascending order.
    
3. Create a new linked list using the sorted values.
    

While this approach works, it does not utilize the fact that both lists are already sorted, resulting in a higher time complexity. Sorting the entire combined list costs `O((m+n) log(m+n))` where `m` and `n` are the lengths of `list1` and `list2`, respectively. Also, this solution consumes extra space for the array.

## Hint to Solve the Problem Efficiently

Since both lists are already sorted, we can merge them in a way similar to the "merge" step in the Merge Sort algorithm. Use two pointers to traverse both lists, compare the nodes, and form a new linked list without using additional space for storage.  

## Efficient Solution

Let's walk through an efficient solution that directly merges the two linked lists using the provided code:

```python
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()  # Initialize a dummy node
        node = dummy

        # Traverse both lists and attach the smaller node
        while list1 and list2:
            if list1.val < list2.val:
                node.next = list1
                list1 = list1.next
            else:
                node.next = list2
                list2 = list2.next
            node = node.next

        # Attach any remaining nodes
        if list1 is not None:
            node.next = list1
        else:
            node.next = list2

        return dummy.next  # Return the merged list
```

The solution utilizes a dummy node to simplify the merging process. Here's how it works:

* **Initialize a Dummy Node:**  
    A dummy node is initialized to act as the start of the merged list. This makes it easier to return the merged list at the end since `dummy.next` points to the beginning of our result.
    
* **Two Pointers Traversing the Lists:**  
    We use two pointers, starting at the head of `list1` and `list2`. We compare the values at each pointer and attach the smaller value to our current node (`node`). This helps maintain the sorted order while merging.
    
* **Attach Remaining Nodes:**  
    After the while loop, one of the linked lists may still have nodes left. We attach these remaining nodes to our merged list directly.
    

The use of a dummy node helps avoid edge cases where managing the head of the merged list can become cumbersome.

## Time and Space Complexity

* **Time Complexity:**  
    The time complexity of this solution is `O(m + n)`, where `m` and `n` are the lengths of `list1` and `list2`, respectively. This is because each node is visited exactly once.
    
* **Space Complexity:**  
    The space complexity is `O(1)` since we are not using any extra data structures except the linked list nodes themselves. The solution builds the merged list in place, keeping the space utilization efficient.
    

## **Conclusion**

The "Merge Two Sorted Lists" problem is a great exercise for practicing linked list manipulation and understanding how to efficiently merge sorted data structures. The efficient solution provided here uses a dummy node to simplify the process and maintains an optimal time complexity of `O(m + n)`, making it a very effective approach for merging two sorted linked lists. Practicing this type of problem helps improve your skills in solving similar problems where merging and sorting come into play, providing an excellent foundation for more advanced data structure questions.


README for [Merge Two Sorted Lists](https://blog.unwiredlearning.com/merge-two-sorted-lists) was compiled from the Unwired Learning Blog.  
//### 009 File: 0023-merge-k-sorted-lists/README.md
# Merge k Sorted Lists (Leetcode #23)

The "Merge k Sorted Lists" problem is a well-known challenge in technical interviews, often used to assess a candidate's ability to efficiently manipulate linked lists and implement advanced merging techniques. The problem asks you to merge `k` sorted linked lists into one sorted linked list. This requires careful thought to maintain efficiency, especially when dealing with a large number of lists.

In this blog, we'll explore both a brute force approach and an efficient divide and conquer solution to solve this problem, explaining each step in detail.

## Understanding the Problem Statement

The "Merge k Sorted Lists" is a common problem in coding interviews and requires a good understanding of linked lists and efficient merging techniques. The problem is defined as follows: Given an array of `k` linked lists, each of which is sorted in ascending order, merge all these linked lists into one sorted linked list and return it.

Imagine you are provided with multiple linked lists, each of which is already sorted, and your task is to combine them into a single sorted linked list. The challenge is to do this as efficiently as possible.

**Example:**

* **Input:** `lists = [1 -> 4 -> 5, 1 -> 3 -> 4, 2 -> 6]`
    
* **Output:** `1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6`
    

The output must be a single linked list that merges all the input linked lists in a sorted manner.

## Brute Force Approach

The brute force solution involves collecting all nodes from the linked lists, storing their values in an array, sorting the array, and then reconstructing a linked list from the sorted values.

**Steps:**

1. Traverse all the linked lists and store the values of each node in an array.
    
2. Sort the array.
    
3. Create a new linked list using the sorted values.
    

**Time Complexity:**

* This approach has a time complexity of `O(N log N)`, where `N` is the total number of nodes in all the linked lists.
    
* Sorting the array takes `O(N log N)`, and the time to recreate the linked list is `O(N)`.
    

**Space Complexity:**

* Storing all the node values requires `O(N)` extra space.
    

Although straightforward, this approach is inefficient for large values of `k` and `N` since it does not take advantage of the sorted nature of the linked lists.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, think about how you can dynamically keep track of the smallest value among all the heads of the linked lists. A good way to accomplish this is by using a **divide and conquer** strategy. By merging the lists in pairs recursively, you can efficiently manage the merging process and keep the time complexity lower compared to a brute force approach.

## Efficient Solution

The provided code utilizes a **divide and conquer** technique to solve the problem. Here's how it works:

1. If there are no lists, return `None`.
    
2. If there is only one list, return it.
    
3. Split the list of linked lists into two halves and recursively merge each half.
    
4. Merge the two halves using a helper function `mergeTwoLists()`.
    

**Code Explanation:**

```python
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists) == 0:
            return None
        if len(lists) == 1:
            return lists[0]

        # Divide the list of linked lists into two halves and merge each half recursively
        mid = len(lists) // 2
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])

        # Merge the two halves
        return self.mergeTwoLists(left, right)
    
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        node = dummy

        # Merge both lists while there are still nodes in l1 and l2
        while l1 and l2:
            if l1.val < l2.val:
                node.next = l1
                l1 = l1.next
            else:
                node.next = l2
                l2 = l2.next
            node = node.next

        # If one list is exhausted, append the other list
        node.next = l1 or l2
        
        return dummy.next
```

**Explanation:**

* The `mergeKLists()` function divides the list of linked lists into two halves until a base case of one list is reached.
    
* It then uses the helper function `mergeTwoLists()` to merge the two halves.
    
* The `mergeTwoLists()` function merges two sorted linked lists into one sorted linked list using a dummy node to simplify pointer operations.
    

## Time and Space Complexity

* **Time Complexity:**
    
    * The time complexity of this approach is `O(N log k)`, where `N` is the total number of nodes, and `k` is the number of linked lists.
        
    * This is because we divide the `k` lists into two halves recursively (`log k` divisions), and each merge operation takes `O(N)` time.
        
* **Space Complexity:**
    
    * The space complexity is `O(1)` for the merging operation since we are modifying pointers in the linked lists directly.
        
    * However, the recursive approach uses additional space in the function call stack, resulting in `O(log k)` space complexity for the recursion.
        

## Conclusion

The divide and conquer approach provides a more efficient way to solve the "Merge k Sorted Lists" problem compared to the brute force approach. By splitting the list of linked lists and merging them recursively, the time complexity is reduced significantly, making this approach more suitable for larger inputs.


README for [Merge k Sorted Lists (Leetcode #23)](https://blog.unwiredlearning.com/merge-k-sorted-lists) was compiled from the Unwired Learning Blog.  
//### 010 File: 0033-search-in-rotated-sorted-array/README.md
# Search in Rotated Sorted Array (Leetcode #33)

he problem **"Search in Rotated Sorted Array"** is a common interview question that challenges one's understanding of searching techniques. You are given a sorted array that has been rotated at some pivot, and you need to find the target value within this array. The goal is to do this efficiently in logarithmic time, making binary search a natural fit.

## Understanding the Problem Statement

Searching for a value in a rotated sorted array can be a tricky problem, especially when trying to do it in an efficient manner. This problem is a frequent topic in coding interviews and tests your ability to adapt standard search algorithms to handle a unique situation. In this blog, we will explore different approaches to solve this problem, starting from a straightforward brute force solution and moving to a more optimized approach using binary search.

The given array is sorted but then rotated, meaning that the original sorted order is disrupted. For example, consider the array `[4, 5, 6, 7, 0, 1, 2]`. This array was originally sorted as `[0, 1, 2, 4, 5, 6, 7]` but was then rotated to create the final sequence. Your task is to write a function to determine if a given target number exists in this rotated array and return its index or `-1` if it does not exist.

## Brute Force Approach

A common approach to solve this problem would be to iterate through each element of the array and check if it matches the target value. Essentially, this is a linear search, and the pseudocode might look like this:

```python
for i in range(len(nums)):
    if nums[i] == target:
        return i
```

This solution has a time complexity of **O(N)** where `N` is the number of elements in the array. This can be inefficient, especially for large arrays, since each element must be checked until the target is found.

## Hint to Solve the Problem Efficiently

A more efficient way to solve this problem is to leverage the fact that the given array is **partially sorted**. If you use a binary search, you can achieve logarithmic time complexity by focusing on specific sections of the array that are sorted. Note that at least one half of the array must always be sorted, even after rotation. This property is crucial in finding the target more efficiently.

## Efficient Solution

Here is the solution code provided, which efficiently solves the problem using a modified binary search:

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            # Check if the mid element is the target
            if nums[mid] == target:
                return mid

            # If the left half is sorted
            if nums[mid] >= nums[left]:
                # Check if target lies in the left half
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            # If the right half is sorted
            else:
                # Check if target lies in the right half
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return -1
```

In this approach, the **left** and **right** pointers are initialized to mark the boundaries of the array. The **mid** index is calculated using `left + (right - left) // 2` to avoid overflow. We then perform the following checks:

1. If `nums[mid]` is equal to the target, we have found the target and return `mid`.
    
2. If the left half of the current section (`nums[left]` to `nums[mid]`) is sorted, we check whether the target lies within this range. If it does, we adjust `right` to `mid - 1`; otherwise, we move the `left` pointer to `mid + 1`.
    
3. If the right half is sorted, we perform a similar check for that half.
    

These logical checks allow us to decide in each iteration which half of the array we can safely discard, eventually locating the target in **O(log N)** time.

## Time and Space Complexity

The time complexity of this efficient solution is **O(log N)**, where `N` is the number of elements in the array. This is due to the nature of binary search, where the problem size is divided in half at each step.

The space complexity is **O(1)**, as we do not use any extra space apart from a few variables to track indices. All operations are performed in place, making this approach highly efficient for large datasets.

## Conclusion

The "Search in Rotated Sorted Array" problem is an excellent example of how modifying classic algorithms, like binary search, can yield efficient solutions to more complex variations of common problems. By understanding the properties of rotated arrays and employing binary search, we can solve the problem in logarithmic time, which is much more efficient compared to a brute force linear search. Mastering this technique will not only help in interviews but also improve your problem-solving skills in real-world scenarios involving partially sorted data.


README for [Search in Rotated Sorted Array (Leetcode #33)](https://blog.unwiredlearning.com/search-in-rotated-sorted-array) was compiled from the Unwired Learning Blog.  
//### 011 File: 0039-combination-sum/README.md
# Combination Sum (Leetcode #39)

The Combination Sum problem is an interesting challenge from LeetCode that deals with discovering all unique combinations from a given list of numbers that sum up to a specific target value. Let's dive into this problem step by step to understand how to solve it efficiently.

## Understanding the Problem Statement

You are given an array of **candidates**, which contains positive integers, and a **target** value. The goal is to find all unique combinations from the candidates that sum up to the given target value. You may use each number in the candidates list as many times as needed.

To make it clear:

* **Input**: candidates = \[2, 3, 6, 7\], target = 7
    
* **Output**: \[\[7\], \[2, 2, 3\]\]
    

**Rules to Note**:

* The same number may be used multiple times, but each combination should be unique.
    
* The order of elements in a combination does not matter.
    

## Brute Force Approach

The brute force approach to this problem involves generating all possible combinations and checking whether they match the target sum. This solution works by considering each candidate and recursively forming all possible combinations.

**Steps**:

1. Recursively include each element in the current combination.
    
2. Continue the process until the sum of the current combination matches the target or exceeds it.
    
3. If the target is reached, store the combination as a valid result.
    
4. If the sum exceeds the target, discard that combination.
    

This approach works, but it has a high computational cost due to the number of repeated recursive calls and the many combinations generated, including invalid ones. The efficiency of this brute force solution can be further improved by avoiding unnecessary branches.

## Hint to Solve the Problem Efficiently

One of the ways to efficiently solve this problem is by employing **Depth First Search (DFS)** with backtracking. In the provided code, notice the strategic use of recursion combined with selective branching. This helps to reduce the number of combinations that need to be explored.

Here’s a key hint: focus on controlling the recursive function so that it only considers combinations that are **within the constraints** (i.e., the current sum does not exceed the target). This ensures that unnecessary work is eliminated early on, saving computation time.

## Efficient Solution

Below is the Python solution that leverages DFS along with backtracking to find all valid combinations that sum up to the target value:

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        all_combinations = []

        def dfs(index, current_combination, current_sum):

            # If the current sum equals the target, we've found a valid combination.
            if current_sum == target:
                all_combinations.append(current_combination)
                return

            # If we've considered all candidates or the current sum exceeds the target, backtrack.
            if index >= len(candidates) or current_sum > target:
                return
            
            # Include the current candidate and recurse
            dfs(index, current_combination + [candidates[index]], current_sum + candidates[index])
            
            # Move to the next candidate without including the current one
            dfs(index + 1, current_combination, current_sum)

        # Start the DFS with an empty combination and a sum of 0.
        dfs(0, [], 0)
        return all_combinations
```

**Explanation**:

* The `dfs` function is used to perform depth-first search.
    
* The function takes the current index, the current combination, and the current sum as arguments.
    
* We keep adding candidates to the combination while ensuring the sum does not exceed the target.
    
* Backtracking is applied when we either reach a valid solution (sum equals target) or exceed the target, which ensures we explore only viable paths.
    

The main advantage here is that we minimize the number of combinations generated, only exploring the ones that are likely to reach the target.

## Time and Space Complexity

**Time Complexity**: The time complexity is **O(2^n)**, where **n** is the number of elements in the candidates array. This is because, in the worst case, we may need to explore all possible subsets of candidates to find the valid combinations. However, due to pruning of unnecessary branches, the solution is significantly faster than the brute force approach.

**Space Complexity**: The space complexity is **O(target)** due to the recursion stack. The maximum depth of the recursion is determined by how many times we add candidates to reach the target value, so it depends on the size of the target.

## Conclusion

This efficient solution to the Combination Sum problem makes use of DFS and backtracking to intelligently explore potential combinations while minimizing the computational overhead. This method is effective, scalable, and helps in efficiently finding the correct combinations without generating all possible subsets.


README for [Combination Sum (Leetcode #39)](https://blog.unwiredlearning.com/combination-sum) was compiled from the Unwired Learning Blog.  
//### 012 File: 0048-rotate-image/README.md
# Rotate Image (Leetcode #48)

When tackling coding problems, efficient solutions save time and resources. In this blog, we’ll explore how to solve Leetcode problem 48, 'Rotate Image.' We'll start by understanding the problem, cover a common brute force approach, then move to a more efficient solution to give you an edge. Whether you're preparing for technical interviews or simply sharpening your coding skills, this guide will provide a thorough breakdown, ensuring you master the logic behind matrix rotation.

## Understanding the Problem Statement

The problem 'Rotate Image' asks you to rotate a given n × n 2D matrix by 90 degrees (clockwise) **in place**. This means modifying the original matrix without using additional memory. The matrix is a square array of integers where you need to transform each element such that the entire matrix is rotated by 90 degrees clockwise.

For example:

**Input:**

```python
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]
```

**Output:**

```python
[
 [7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]
]
```

The problem requires you to implement the solution in place, meaning you should not use extra space for another matrix to perform the transformation.

## Brute Force Approach

A straightforward approach to solving this problem involves creating a new matrix of the same size to store the rotated values. You can iterate through each element in the original matrix and place it in the corresponding position in the new matrix.

For instance, given an element at row `i` and column `j`, you would place it in the new matrix at position `j` and column `n - i - 1`. This approach works, but it requires O(n^2) extra space, which contradicts the problem's requirements of an **in-place** solution.

**Pseudocode for Brute Force:**

```python
create new_matrix of size n x n
for i from 0 to n-1:
    for j from 0 to n-1:
        new_matrix[j][n - i - 1] = matrix[i][j]
copy new_matrix back to matrix
```

While this brute force method is easy to understand, it does not meet the problem's space complexity requirements.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, we need to avoid the use of an extra matrix. Instead, think about rotating the elements in layers, like peeling an onion. Imagine the matrix divided into several concentric layers—rotate each layer one at a time by swapping elements in groups of four.

## Efficient Solution

The efficient solution, as provided in the attached code, involves rotating the matrix **in place** by processing each layer of the matrix, starting from the outermost layer and moving inwards. Here's a detailed breakdown:

1. The matrix is divided into layers, and each layer is rotated separately.
    
2. For each layer, the elements in groups of four are swapped clockwise.
    
3. We iterate through the elements in each layer, saving one element as a temporary value and then proceeding to rotate the other three to their respective positions, finally placing the temporary value in its correct spot.
    

**Python Code:**

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        # Iterate over each layer of the matrix
        for i in range(n // 2):
            for j in range(i, n - i - 1):
                # Save the temp element
                temp = matrix[i][j]

                # Move bottom-left element to top-left
                matrix[i][j] = matrix[n - j - 1][i]

                # Move bottom-right element to bottom-left
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]

                # Move top-right element to bottom-right
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]

                # Assign temp element to top-right
                matrix[j][n - i - 1] = temp
```

**Step-by-Step Explanation**

* **Layers**: The matrix is divided into layers, each represented by `i`, which ranges from `0` to `n // 2 - 1`.
    
* **Elements in Each Layer**: We iterate over each element in the layer using `j`, which ranges from `i` to `n - i - 1`.
    
* **Swapping Elements**: For each element, we perform a four-way swap:
    
    1. Save the top element (`temp`).
        
    2. Move the element from the left side to the top.
        
    3. Move the element from the bottom to the left.
        
    4. Move the element from the right to the bottom.
        
    5. Finally, move the saved element (`temp`) to the right.
        

This solution effectively rotates the matrix in place without using extra space.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n^2)**. This is because we iterate over each element of the matrix once, and each element is moved exactly once.
    
* **Space Complexity**: The space complexity is **O(1)**, as we do not use any extra data structures that grow with the input size. The rotation is done entirely within the input matrix.
    

## Conclusion

The 'Rotate Image' problem is a classic question that tests your understanding of in-place algorithms and matrix manipulation. While the brute force approach is easy to conceptualize, it does not meet the space requirements of the problem. The efficient solution provided here optimally rotates the matrix layer by layer, ensuring no extra space is used. Mastering this problem gives you a great foundation for dealing with more advanced in-place transformation problems in technical interviews.

Keep practicing problems like these to solidify your understanding of in-place operations and matrix transformations. Happy coding!

README for [Rotate Image (Leetcode #48)](https://blog.unwiredlearning.com/rotate-image) was compiled from the Unwired Learning Blog.  
//### 013 File: 0049-group-anagrams/README.md
# Group Anagrams (Leetcode #49)

Anagrams are words or phrases formed by rearranging the letters of another, using all the original letters exactly once. In Leetcode Problem 49, you're asked to group an array of strings into collections where each group contains anagrams.

## Understanding the Problem Statement

The problem is stated as follows: Given an array of strings, group the anagrams together.

**Example:**

Input: `strs = ["eat", "tea", "tan", "ate", "nat", "bat"]`

Output: `[ ["eat", "tea", "ate"], ["tan", "nat"], ["bat"] ]`

Each group contains words that are anagrams of each other. Note that the order within each group or the groups themselves does not matter.

## Brute Force Approach

The brute force approach is to compare each word with every other word to check if they are anagrams. This inggvolves sorting each word and comparing its sorted version with others, which allows us to determine if they match.

**Steps:**

1. For each word in the array, sort its letters.
    
2. Compare the sorted version with other words.
    
3. Group words with the same sorted version.
    

The brute force method is inefficient because sorting each word takes `O(L log L)` time, and comparing all possible pairs has a time complexity of `O(N^2)`. Thus, this approach can become very slow for large inputs.

## Hint to Solve the Problem Efficiently

The hint for an efficient solution is to use a hash map to avoid redundant comparisons. Instead of sorting each word, you can use a different characteristic that uniquely represents anagrams. Specifically, you can use character counts as keys in a dictionary to keep track of words that are anagrams.

## Efficient Solution

The provided code takes advantage of hashing to group anagrams efficiently.

**Steps of the Efficient Solution:**

1. Create an empty dictionary (`anagram_map`) where each key is a unique representation of a group of anagrams.
    
2. Iterate over each word in the input list:
    
    * For each word, create a list of 26 zeros representing the character count for each letter in the alphabet (since we're only dealing with lowercase English letters).
        
    * Update the character count for each letter in the word.
        
    * Convert the character count list into a tuple and use it as a key in the dictionary.
        
    * Append the word to the list corresponding to that key.
        
3. Return the values of the dictionary as the result.
    

Here's a simplified version of the efficient code:

```plaintext
from collections import defaultdict

def groupAnagrams(strs):
    anagram_map = defaultdict(list)
    
    for word in strs:
        # Create a count of 26 zeros for each letter in the alphabet
        count = [0] * 26
        
        for char in word:
            count[ord(char) - ord('a')] += 1
        
        # Use the tuple of counts as the key
        anagram_map[tuple(count)].append(word)
    
    return list(anagram_map.values())
```

**Explanation:**

* We use a list of size 26 to count the frequency of each letter in a word. This list is then converted to a tuple so it can be used as a key in the dictionary (`anagram_map`).
    
* The dictionary (`anagram_map`) stores lists of words that are anagrams, indexed by their character count.
    
* Finally, the result is the list of all the values in the dictionary.
    

## Time and Space Complexity

**Time Complexity:**

* Constructing the character count list for each word takes `O(L)`, where `L` is the length of the word.
    
* Iterating over all `N` words in the input list takes `O(N * L)` time, where `N` is the number of words and `L` is the average length of the words.
    
* Thus, the overall time complexity is `O(N * L)`.
    

**Space Complexity:**

* We use a dictionary to store the groups of anagrams. In the worst case, every word could be an anagram of every other word, leading to `O(N * L)` space for the dictionary.
    
* Additionally, we use `O(N * L)` space for storing the character counts as keys in the dictionary.
    
* Thus, the overall space complexity is `O(N * L)`.
    

This solution is significantly more efficient than the brute force approach because it avoids repeatedly sorting strings and instead uses a fixed-size representation for each word, making it suitable for large inputs.

## Conclusion

Leetcode Problem 49, Group Anagrams, is a great example of how to use hashing to solve problems more efficiently. The brute force approach of sorting each word and comparing is impractical for large datasets, whereas using character counts as keys in a hash map provides an elegant and efficient solution. By understanding the properties of anagrams and leveraging data structures like dictionaries, you can solve this problem in `O(N * L)` time complexity, which is well-suited for larger inputs. This approach highlights the importance of choosing the right data representation and algorithm to achieve optimal performance.


README for [Group Anagrams (Leetcode #49)](https://blog.unwiredlearning.com/group-anagram) was compiled from the Unwired Learning Blog.  
//### 014 File: 0053-maximum-subarray/README.md
# Maximum Subarray (Leetcode #53)

If you've ever encountered an interview question that asked you to find the maximum sum of a contiguous subarray, you were likely facing Leetcode's **Maximum Subarray** problem. It may sound simple, but for many programmers, it's an interesting challenge that requires a good understanding of both brute force and optimized approaches. Let's walk through this problem step by step to understand how to solve it.

## Understanding the Problem Statement

The **Maximum Subarray** problem asks you to determine the contiguous subarray within a one-dimensional array of integers that has the largest sum. Given an array, you need to find the maximum possible sum of any of its contiguous subarrays.

For instance, consider the array `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`. The subarray `[4, -1, 2, 1]` has the largest sum, which equals 6. Your goal is to implement a function that returns this maximum sum efficiently.

## Brute Force Approach

One common approach to solving this problem is to use **brute force**. In this approach, you would consider all possible subarrays of the given array, calculate their sums, and keep track of the highest sum encountered.

Here's a quick outline of how the brute force method would work:

* Iterate through every possible starting point of the subarray.
    
* For each starting point, iterate through every possible ending point.
    
* Calculate the sum for each of these subarrays, and track the maximum value.
    

While this approach is easy to understand, it is computationally expensive. Its time complexity is **O(n^2)**, which makes it impractical for large input arrays due to its inefficiency.

## Hint to Solve the Problem Efficiently

To solve this problem more efficiently, think about how you can calculate the sum of subarrays without recalculating overlapping portions multiple times. Instead of keeping track of all subarrays, focus on finding the maximum sum ending at each position. Consider whether extending the previous subarray is beneficial or whether starting fresh with the current element is a better choice.

## Efficient Solution

The efficient solution to this problem is implemented using an algorithm called **Kadane's Algorithm**. The code for the solution can be found below:

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # the sum of the subarray ending at the current index
        current_sum = nums[0]
        
        # This will store the maximum sum found so far
        max_sum = nums[0]
        
        # Iterate through the array starting from the second element
        for i in range(1, len(nums)):
            # Update current_sum to be the maximum of:
            # 1. The current element itself (which means starting a new subarray)
            # 2. The current element + current_sum (which means extending the existing subarray)
            current_sum = max(nums[i], current_sum + nums[i])
            
            # Update max_sum to be the maximum of max_sum and current_sum
            max_sum = max(max_sum, current_sum)
        
        # Return the maximum sum found
        return max_sum
```

In Kadane's Algorithm, we maintain two variables: `current_sum` and `max_sum`. `current_sum` keeps track of the sum of the subarray ending at the current index, while `max_sum` holds the maximum sum found so far.

* For each element, we decide whether to start a new subarray or to add the current element to the existing subarray by choosing the maximum between `nums[i]` and `current_sum + nums[i]`.
    
* We then compare `current_sum` with `max_sum` to keep track of the overall maximum value.
    

This dynamic programming approach ensures that we are considering each element only once, allowing for a very efficient solution.

## Time and Space Complexity

The **time complexity** of Kadane's Algorithm is **O(n)**, where `n` is the number of elements in the array. This is because we traverse the array only once, and at each step, we perform a constant amount of work.

The **space complexity** is **O(1)** because we are using only a fixed amount of extra space, regardless of the size of the input array. This makes Kadane's Algorithm both time and space efficient.

## Conclusion

The **Maximum Subarray** problem is an excellent example of the power of dynamic programming. By switching from a brute force approach to Kadane's Algorithm, we reduce the computation time from **O(n^2)** to **O(n)**. This makes our solution suitable even for large arrays. Understanding and applying Kadane's Algorithm is an essential skill for solving maximum subarray problems efficiently.

Happy coding, and may your subarrays always have maximum sums!

README for [Maximum Subarray (Leetcode #53)](https://blog.unwiredlearning.com/maximum-subarray) was compiled from the Unwired Learning Blog.  
//### 015 File: 0054-spiral-matrix/README.md
# Spiral Matrix (Leetcode #54)

The Spiral Matrix problem is a fascinating coding challenge that tests your ability to navigate a two-dimensional array in a non-linear order. This is a popular Leetcode problem, designed to help programmers develop a better understanding of matrix manipulation. In this blog, we will take a closer look at the Spiral Matrix problem, explore a brute force approach to solve it, and then work through an efficient solution. We will also evaluate the time and space complexity of the given code.

## Understanding the Problem Statement

The **Spiral Matrix** problem provides you with an `m x n` matrix, and the goal is to return all elements of the matrix in spiral order. The spiral order means starting from the top-left of the matrix and traversing in a clockwise direction until all elements are covered. The movement proceeds rightwards along rows, downwards along columns, then leftwards and upwards while changing direction whenever necessary to complete the entire matrix traversal.

For example, given the following input matrix:

```python
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
```

The output will be: `[1, 2, 3, 6, 9, 8, 7, 4, 5]`, where we traverse the matrix in a spiral pattern.

## Brute Force Approach

A typical brute force approach to solve this problem is to manually traverse the matrix and simulate the directions of traversal (right, down, left, and up). You would start from the top-left corner and keep track of each visited element using an auxiliary data structure like a `visited` matrix. Whenever you hit a boundary or a previously visited cell, you would change direction. This approach, while easy to understand, involves maintaining an extra `visited` matrix, which adds unnecessary space complexity.

Such a solution could be implemented in a straightforward manner using a set of conditional statements, but it tends to be quite inefficient due to the overhead of managing an extra data structure and the need to check visited elements repeatedly.

## Hint to Solve the Problem Efficiently

The key to solving the Spiral Matrix problem efficiently is to use four boundary pointers. These pointers, namely `rowBegin`, `rowEnd`, `colBegin`, and `colEnd`, allow you to keep track of the traversal limits as you proceed in a spiral direction. By updating these boundaries as you progress, you effectively reduce the matrix size and ensure that each element is visited exactly once without using any auxiliary storage for tracking.

## Efficient Solution

Below is an efficient solution provided for the Spiral Matrix problem. Let's walk through the code.

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:   
        # Initialize the boundaries
        rowBegin, rowEnd = 0, len(matrix) - 1
        colBegin, colEnd = 0, len(matrix[0]) - 1
        
        # Resultant list
        result = []
        
        while rowBegin <= rowEnd and colBegin <= colEnd:
            # colBegin to colEnd along the rowBegin boundary
            for i in range(colBegin, colEnd + 1):
                result.append(matrix[rowBegin][i])
            rowBegin += 1
            
            # rowBegin to rowEnd along the colEnd boundary
            for i in range(rowBegin, rowEnd + 1):
                result.append(matrix[i][colEnd])
            colEnd -= 1
            
            if rowBegin <= rowEnd:
                # colEnd to colBegin along the rowEnd boundary
                for i in range(colEnd, colBegin - 1, -1):
                    result.append(matrix[rowEnd][i])
                rowEnd -= 1
            
            if colBegin <= colEnd:
                # rowEnd to rowBegin along the colBegin boundary
                for i in range(rowEnd, rowBegin - 1, -1):
                    result.append(matrix[i][colBegin])
                colBegin += 1
        
        return result
```

**Explanation:**

1. **Initialization:** Four pointers are used to track the boundaries of the matrix. `rowBegin` and `rowEnd` indicate the start and end of the current row boundaries, while `colBegin` and `colEnd` are used for the column boundaries.
    
2. **Traversal:** The matrix is traversed in four steps:
    
    * Move right across the current top boundary (`rowBegin`).
        
    * Move down along the rightmost boundary (`colEnd`).
        
    * Move left across the current bottom boundary (`rowEnd`), if applicable.
        
    * Move up along the leftmost boundary (`colBegin`), if applicable.
        
3. **Boundary Updates:** After each step, the respective boundary pointer is updated to shrink the matrix traversal area.
    
4. **Condition Checks:** To prevent redundant operations, the code checks whether `rowBegin <= rowEnd` and `colBegin <= colEnd` before attempting to traverse along the reduced boundaries.
    

## Time and Space Complexity

**Time Complexity:** The time complexity of this solution is **O(m × n)**, where `m` is the number of rows and `n` is the number of columns in the matrix. This is because each element in the matrix is visited exactly once, resulting in an efficient traversal.

**Space Complexity:** The space complexity is **O(1)** if we do not consider the output list, as the traversal is done in-place without using additional data structures. However, the space complexity becomes **O(m × n)** if we consider the space required to store the result.

## Conclusion

The Spiral Matrix problem is a great example of how efficiently navigating boundaries can lead to an optimal solution. By leveraging four boundary pointers, we avoid the need for extra space to keep track of visited elements, thus optimizing both time and space complexities. The efficient solution presented here demonstrates how careful management of boundaries and conditional checks can help solve complex traversal problems effectively.

We hope this blog has helped you understand how to approach the Spiral Matrix problem and that you can now implement a more optimized solution. Keep practicing such problems to sharpen your matrix manipulation skills!

README for [Spiral Matrix (Leetcode #54)](https://blog.unwiredlearning.com/spiral-matrix) was compiled from the Unwired Learning Blog.  
//### 016 File: 0055-jump-game/README.md
# Jump Game (Leetcode #55)

Leetcode's "Jump Game" is a fascinating problem that challenges your understanding of greedy algorithms and array traversal. It's a problem often asked during technical interviews, making it important to grasp both its naive and optimized solutions. In this blog, we'll take a deep dive into understanding the problem, discussing a common brute force solution, and finally exploring a more efficient solution backed by the code provided.

## Understanding the Problem Statement

The "Jump Game" problem presents you with an array of non-negative integers, where each element represents your maximum jump length from that position. Your goal is to determine whether you can reach the last index starting from the first index. For example, given the array `[2, 3, 1, 1, 4]`, you start at index `0` and can jump up to `2` steps. From there, you can continue jumping to eventually reach the last index. However, given an array like `[3, 2, 1, 0, 4]`, you will find yourself unable to make it to the last index.

## Brute Force Approach

One common brute force approach is to explore all possible jump paths recursively. At each index, you attempt to jump to every possible position within the given range, checking if any path leads to the last index. The key idea is to start from index `0` and recursively try all reachable positions until you either reach the last index or exhaust all options.

This brute force solution has significant drawbacks, including exponential time complexity due to the redundant exploration of paths. As you might imagine, this approach quickly becomes impractical for larger arrays, making optimization necessary.

## Hint to Solve the Problem Efficiently

Instead of exhaustively trying every path, consider tracking the farthest index you can reach as you iterate through the array. If, at any point, you reach an index that is beyond your current reach, you can conclude that reaching the end is impossible. This optimization relies on the concept of "greedily" advancing as far as possible at each step.

## Efficient Solution

The efficient solution leverages a greedy algorithm to minimize unnecessary calculations. The code provided uses a variable `maxReach` to keep track of the farthest index that can be reached at any given point. As you iterate through the array, you continuously update `maxReach` to be the maximum of its current value or the farthest index reachable from the current position (`i + nums[i]`). If at any point the current index exceeds `maxReach`, it means you cannot proceed further, and the function returns `False`. Otherwise, if you successfully traverse the array and `maxReach` reaches or exceeds the last index, the function returns `True`.

Here is the code:

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # stores the farthest index we can reach
        maxReach = 0
        
        # Iterate through each index in the array
        for i in range(len(nums)):
            # If the current index is greater than the farthest we can reach,
            # it means we cannot reach this index, hence return False
            if i > maxReach:
                return False
            
            # Update maxReach to be the maximum of its current value
            # and the farthest index we can reach from the current index
            maxReach = max(maxReach, i + nums[i])
        
        # If we have iterated through the array and maxReach is at least the last index,
        # it means we can reach the end, hence return True
        return maxReach >= len(nums) - 1
```

## Time and Space Complexity

The time complexity of this solution is **O(n)**, where `n` is the length of the array. This is because we only iterate through the array once, updating `maxReach` as we go. The space complexity is **O(1)**, as we are using a constant amount of extra space regardless of the input size. This efficient time and space usage make the greedy approach a significant improvement over the brute force method.

## **Conclusion**

The "Jump Game" problem serves as a perfect example of how a brute force solution can be optimized using a greedy strategy to achieve linear time complexity. Understanding this problem helps you build intuition for approaching similar array traversal challenges. By focusing on maximizing reach at each step, you can solve this problem efficiently and handle even the largest inputs with ease.

README for [Jump Game (Leetcode #55)](https://blog.unwiredlearning.com/jump-game) was compiled from the Unwired Learning Blog.  
//### 017 File: 0056-merge-intervals/README.md
# Merge Intervals (Leetcode #56)

The 'Merge Intervals' problem is a classic challenge you may encounter in coding interviews or competitive programming. It requires an understanding of sorting and working with interval data, making it an excellent test of algorithmic thinking. This blog post will help you grasp the concept, explore common solutions, and ultimately solve it efficiently using Python.

## Understanding the Problem Statement

The 'Merge Intervals' problem on LeetCode asks you to merge overlapping intervals from a given list. You are provided with an array of intervals where each interval is represented as a pair of start and end times. The goal is to merge all overlapping intervals and return a list of non-overlapping intervals.

For example, given intervals `[[1, 3], [2, 6], [8, 10], [15, 18]]`, you should return `[[1, 6], [8, 10], [15, 18]]`. The overlapping intervals `[1, 3]` and `[2, 6]` are merged to form `[1, 6]`.

## Brute Force Approach

A brute force approach to solve this problem would involve comparing each interval with every other interval to see if they overlap, and then merging them accordingly. This requires maintaining a status of whether an interval has been merged or not, leading to a large amount of nested looping.

While this approach is conceptually straightforward, its inefficiency becomes apparent when working with large input sizes. The need to compare every interval with every other one results in an `O(n^2)` complexity, which is impractical for larger datasets. Hence, we seek a more efficient solution.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, the key insight is to **sort the intervals** by their start times. By ensuring all intervals are processed in a sorted order, we can reduce the number of comparisons needed, since we only need to consider merging consecutive intervals.

## Efficient Solution

Below is the efficient Python solution from the provided code. Let’s break it down step-by-step to understand the logic:

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Step 1: Sort the intervals by the start time
        intervals.sort()

        # Step 2: Initialize the result array with the first interval
        merged = [intervals[0]]

        # Step 3: Iterate over the intervals and merge when necessary
        for i in range(1, len(intervals)):
            if intervals[i][0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], intervals[i][1])
            else:
                merged.append(intervals[i])

        return merged
```

**Step-by-Step Breakdown:**

1. **Sorting the Intervals**: The first step is to sort the given intervals by their starting points. This helps in systematically comparing each interval with the one immediately preceding it.
    
2. **Initializing the Result Array**: We start by initializing a result list (`merged`) with the first interval, assuming it will serve as the foundation for merging other intervals.
    
3. **Iterative Merging**: We iterate through the sorted intervals starting from the second interval. If the start of the current interval is less than or equal to the end of the last interval in `merged`, it means there is an overlap, and we merge the two by updating the end time. Otherwise, we add the current interval to `merged` as a non-overlapping interval.
    

## Time and Space Complexity

* **Time Complexity**: The sorting step takes `O(n log n)`, and the iteration over the intervals takes `O(n)`. Thus, the overall time complexity of this solution is `O(n log n)`.
    
* **Space Complexity**: The space complexity is `O(n)` if we consider the space needed for the merged intervals. However, since no additional data structures apart from the result list are used, the extra space usage is minimal, making it an efficient solution.
    

## Conclusion

The 'Merge Intervals' problem is a great example of how sorting can simplify the problem-solving process. By using sorting and iterating through the list only once, the above solution provides an efficient way to merge overlapping intervals without the heavy overhead of a brute force approach. With a time complexity of `O(n log n)`, this solution is suitable for practical use, even with larger inputs.

I hope this guide has helped you understand the nuances of solving the 'Merge Intervals' problem efficiently. Now it's your turn to implement this solution and try it with different test cases!

README for [Merge Intervals (Leetcode #56)](https://blog.unwiredlearning.com/merge-intervals) was compiled from the Unwired Learning Blog.  
//### 018 File: 0057-insert-interval/README.md
# Insert Interval (Leetcode #57)

The 'Insert Interval' problem is a common interview question that challenges your understanding of arrays and interval management. In this blog post, we'll take a closer look at how to efficiently solve the problem, breaking down both the naive and optimized approaches. By the end of this guide, you'll have a deeper understanding of how to merge overlapping intervals and insert new intervals into a sorted list.

## Understanding the Problem Statement

The problem, Leetcode 57: Insert Interval, gives you a list of non-overlapping intervals sorted by their start times and a new interval that you need to insert into the list. The task is to ensure that the final list is non-overlapping and sorted. The new interval might overlap with some of the existing intervals, and the solution should merge any overlapping ones.

**Example**

Suppose you have the list of intervals `[[1, 3], [6, 9]]` and a new interval `[2, 5]`. After inserting the new interval and merging any overlapping intervals, the output should be `[[1, 5], [6, 9]]`.

## Brute Force Approach

A brute force approach to this problem would involve iterating through the entire list of intervals to find where the new interval should be placed, inserting it, and then scanning the entire list again to merge overlapping intervals. This solution requires multiple passes through the list, leading to increased time complexity. Although this approach may be intuitive, it is far from optimal for larger inputs. Specifically, you would:

1. Insert the new interval in its correct position.
    
2. Iterate through the list and merge any overlapping intervals.
    
3. Return the final merged list.
    

This method involves multiple passes through the list and hence results in **O(n^2)** time complexity in the worst case, which isn't efficient.

## Hint to Solve the Problem Efficiently

The key to optimizing the solution is to divide the intervals into three categories:

1. Intervals that end before the new interval starts (“left”).
    
2. Intervals that overlap with the new interval (“merge”).
    
3. Intervals that start after the new interval ends (“right”).
    

By categorizing intervals this way, you can simplify the merging process to just one pass through the list, leading to a much more efficient solution.

## Efficient Solution

Let’s dive into the efficient solution provided in the code:

```python
class Solution:
    def insert(self, intervals, newInterval) -> List[List[int]]:
        left, right = [], []
        start, end = newInterval

        for i in intervals:
            # i ends before new_interval starts
            if i[1] < start:  
                left.append(i)

            # i starts after new_interval ends
            elif i[0] > end:  
                right.append(i)

            # i overlaps with new_interval
            else:  
                start = min(start, i[0])
                end = max(end, i[1])

        return left + [[start, end]] + right
```

**Explanation**

1. **Initialization**: Create two lists, `left` and `right`, to store intervals that are clearly not overlapping with the new interval. Extract `start` and `end` values from `newInterval`.
    
2. **Iterating Through Intervals**:
    
    * For each interval, check if it ends before `newInterval` starts. If so, add it to `left`.
        
    * If an interval starts after `newInterval` ends, add it to `right`.
        
    * Otherwise, the intervals overlap, and you need to merge them by updating the `start` and `end`.
        
3. **Final Result**: Combine the `left`, the merged interval, and the `right` intervals to get the final output.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n)**, where `n` is the number of intervals. The solution requires only one pass through the list, and every interval is processed once.
    
* **Space Complexity**: The space complexity is **O(n)**, as we use additional lists (`left` and `right`) to store intervals, but these lists are just reordering of the original intervals.
    

## Conclusion

The 'Insert Interval' problem is a great example of how breaking a problem into smaller, manageable parts can lead to a more efficient solution. By categorizing the intervals and only merging when necessary, we achieve a linear-time solution that is both simple and effective. The key takeaway here is to avoid multiple passes through the data whenever possible and instead leverage categorization to streamline operations.

Try implementing this efficient solution on your own, and you’ll be better equipped to tackle similar interval-based problems in coding interviews!

README for [Insert Interval (Leetcode #57)](https://blog.unwiredlearning.com/insert-interval) was compiled from the Unwired Learning Blog.  
//### 019 File: 0062-unique-paths/README.md
# Unique Paths (Leetcode #62)

Navigating through the Leetcode problem “Unique Paths” can be an intriguing challenge for aspiring programmers. Whether you are a beginner or a seasoned coder, understanding the efficient ways to solve this problem not only sharpens your dynamic programming skills but also enhances your ability to create optimal solutions for related challenges. In this blog, we will delve into a detailed explanation of the problem, explore a brute force approach, and then solve it efficiently with the help of a dynamic programming solution.

## Understanding the Problem Statement

The Leetcode problem 62. Unique Paths is about finding how many distinct paths exist from the top-left corner to the bottom-right corner of an `m x n` grid. The movement is restricted to either right or down at any point in time. This implies that, starting from `(0, 0)`, you must find a way to reach `(m-1, n-1)` while only moving in the allowed directions.

To put it simply, given the constraints of the grid, your job is to find how many different ways you can travel across the grid using just right and down movements.

## Brute Force Approach

A common brute force approach would involve exploring all possible paths from the starting point to the destination. This can be implemented using recursion where, at each cell, you make recursive calls to move either to the right or down. The final result will be the sum of all possible ways to reach the destination.

The recursive approach can be represented as follows:

1. Start from the cell `(0, 0)`.
    
2. For each cell, move either to the right or down until you reach the bottom-right corner.
    
3. Count each successful attempt that reaches the destination.
    

However, this approach becomes highly inefficient as the grid size increases. The overlapping subproblems lead to exponential complexity, making the solution impractical for large values of `m` and `n`.

## Hint to Solve the Problem Efficiently

To solve this problem more efficiently, you can use dynamic programming (DP) to avoid redundant calculations. The main idea is to break down the problem into smaller subproblems and store their results, so you don’t have to compute them repeatedly. Consider filling a matrix where each cell represents the number of ways to reach that cell from the top-left.

## Efficient Solution

The provided solution efficiently solves the problem using a dynamic programming (DP) table to keep track of the number of unique paths to each cell.

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Step 1 and 2: Initialize DP array with 1s
        dp = [[1]*n for _ in range(m)]  
    
        # Step 2: Fill in the dp with unique paths to each cell
        for i in range(1, m):          
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        # Step 3: Return the result from the bottom-right cell
        return dp[m-1][n-1]
```

**Explanation of the Code:**

1. **Initialization:** The `dp` table is initialized with 1s. This is because there is only one way to reach any cell in the first row or first column—by moving exclusively right or down, respectively.
    
2. **Filling the DP Table:** For every other cell, the number of ways to reach that cell is the sum of the number of ways to reach the cell directly above (`dp[i-1][j]`) and the number of ways to reach the cell to the left (`dp[i][j-1]`). This builds on smaller subproblems to compute the solution for the entire grid.
    
3. **Final Output:** The final answer is stored in the bottom-right cell (`dp[m-1][n-1]`), which contains the number of unique paths to reach that point.
    

## Time and Space Complexity

* **Time Complexity:** The time complexity of this solution is `O(m * n)`, as we iterate through all cells of the `m x n` grid once.
    
* **Space Complexity:** The space complexity is `O(m * n)` due to the storage requirement for the `dp` matrix. However, this can be optimized to `O(n)` by using a 1D array since we only need the current and previous row values at each step.
    

## Conclusion

The Unique Paths problem is an excellent exercise for learning dynamic programming, as it allows you to transform a recursive approach into an efficient DP solution. By utilizing a DP table, we avoid redundant calculations and solve the problem optimally. Remember, whenever you encounter overlapping subproblems, dynamic programming is a great tool to simplify the solution and achieve optimal performance.

Dynamic programming might feel challenging at first, but with practice, it will become one of the most powerful tools in your coding toolkit!

README for [Unique Paths (Leetcode #62)](https://blog.unwiredlearning.com/unique-paths) was compiled from the Unwired Learning Blog.  
//### 020 File: 0070-climbing-stairs/README.md
# Climbing Stairs (Leetcode 70)

The "Climbing Stairs" problem is a popular challenge often encountered in coding interviews. It provides a great opportunity to learn about dynamic programming and how to optimize a naive approach into an efficient solution. In this blog, we will explore different approaches to solving the problem, including brute force and an efficient dynamic programming solution.

## Understanding the Problem Statement

The "Climbing Stairs" problem is a common question in coding interviews and on platforms like LeetCode. The task is quite simple: given a staircase with *n* steps, you can either climb 1 or 2 steps at a time. The question is: in how many distinct ways can you climb to the top? For instance, if there are 3 steps, the distinct ways to reach the top are (1, 1, 1), (1, 2), and (2, 1), totaling 3 ways.

## Brute Force Approach

A straightforward approach to solving this problem would be using recursion, where each call represents climbing either 1 or 2 steps. For every step, you can make two choices: step 1 or step 2. By breaking down the problem recursively, you essentially form a tree of possible outcomes. This approach, however, becomes very inefficient as the number of steps increases, with repeated calculations leading to exponential time complexity.

## Hint to Solve the Problem Efficiently

The key to solving this problem lies in observing that it has overlapping subproblems. The number of ways to reach step *n* is the sum of the number of ways to reach step *n-1* and step *n-2*. This observation indicates that we can apply a dynamic programming approach to solve it efficiently.

## Efficient Solution

The efficient solution involves using a dynamic programming technique, as provided in the code below:

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        # Base case: if n is 1, there's only one way.
        if n == 1:
            return n
        
        # Initialize a list to store the number of ways to reach each step.
        dp = [0] * (n + 1)
        dp[1], dp[2] = 1, 2
        
        # Start calculating from the 3rd step up to the nth step.
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
            
        # dp[n] contains the total number of ways to climb n stairs.
        return dp[n]
```

This solution leverages an array `dp` where `dp[i]` represents the number of distinct ways to reach step `i`. We start by initializing `dp[1]` and `dp[2]` since the number of ways to reach the first and second steps are known directly (1 and 2 ways, respectively). From the third step onward, each step can be reached either from the previous step or by skipping a step, leading to the relation `dp[i] = dp[i - 1] + dp[i - 2]`.

## Time and Space Complexity

The time complexity of this solution is **O(n)** because we calculate the number of ways for each step from 1 to *n* exactly once. The space complexity is **O(n)** due to the use of the `dp` array to store the results for each step. While this is efficient, further optimization is possible by reducing the space complexity to **O(1)** if only the last two results are stored instead of maintaining a full array.

## Conclusion

The "Climbing Stairs" problem is a great example to demonstrate the power of dynamic programming. While a brute force approach may seem straightforward, it quickly becomes impractical for larger inputs. By leveraging dynamic programming, we can reduce both time and space complexities to create a more efficient solution. Understanding this problem helps build a strong foundation in recognizing and solving overlapping subproblems, a crucial skill for tackling more advanced coding challenges.


README for [Climbing Stairs (Leetcode 70)](https://blog.unwiredlearning.com/climbing-stairs) was compiled from the Unwired Learning Blog.  
//### 021 File: 0073-set-matrix-zeroes/README.md
# Set Matrix Zeroes (Leetcode #73)

In this blog post, we will solve a popular problem from LeetCode - the "Set Matrix Zeroes" problem. It's an interesting challenge that can be approached in various ways, from basic brute force to more efficient solutions. Here, we will explore the problem, discuss the naive approach, and eventually arrive at a more optimized solution.

## Understanding the Problem Statement

The problem asks you to modify a given matrix such that if an element in the matrix is zero, you need to set its entire row and column to zero. This has to be done **in place**, meaning you can't use any additional matrix. The problem can be tricky, especially when trying to achieve optimal time and space complexity.

To better understand, let's consider an example. If given the matrix:

```python
[
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]
```

The modified output should be:

```python
[
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]
```

The challenge is to mark the rows and columns with zero efficiently while keeping the algorithm's space usage minimal.

## Brute Force Approach

A simple brute-force approach involves creating an additional matrix of the same dimensions to track where the zeros should go. You iterate through the matrix, and whenever you find a zero, you mark the corresponding row and column in the additional matrix. After identifying all such positions, you modify the original matrix accordingly.

This method is straightforward, but it requires extra space proportional to the size of the matrix, which results in **O(m \* n)** space complexity. This may not be acceptable for larger matrices, as it defies the requirement of doing it **in place**.

## Hint to Solve the Problem Efficiently

The key to solving the problem efficiently lies in using the **first row and first column** of the matrix itself to store the information about which rows and columns should be zeroed. By doing so, we can eliminate the need for an extra matrix, thus reducing space complexity.

## Efficient Solution

Let's walk through the efficient solution provided in the code:

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows, cols = len(matrix), len(matrix[0])
        first_row_zero, first_col_zero = False, False
        
        # if the first row or first column need to be zeroed
        for i in range(rows):
            if matrix[i][0] == 0:
                first_col_zero = True
                break
                
        for j in range(cols):
            if matrix[0][j] == 0:
                first_row_zero = True
                break
        
        # Use first row and column to mark zero rows and columns
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        # Zero out marked rows and columns
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        # Zero out the first column if needed
        if first_col_zero:
            for i in range(rows):
                matrix[i][0] = 0
        
        # Zero out the first row if needed
        if first_row_zero:
            for j in range(cols):
                matrix[0][j] = 0
```

In this solution, we first check if the **first row** and **first column** need to be zeroed. We use two boolean flags (`first_row_zero` and `first_col_zero`) to track this.

Next, we traverse through the rest of the matrix, and whenever we find a zero, we mark the corresponding **first row** and **first column** elements as zero. This allows us to use the first row and column as a reference for zeroing the rest of the matrix.

Finally, we traverse the matrix again, zeroing out elements based on the markers in the first row and column. In the end, we handle the first row and first column separately, if needed.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(m \* n)**, where `m` is the number of rows and `n` is the number of columns. This is because we traverse the entire matrix a few times, but each traversal is linear.
    
* **Space Complexity**: The space complexity is **O(1)**, as we are not using any additional data structures, just a few boolean variables.
    

## Conclusion

The "Set Matrix Zeroes" problem is an excellent exercise for understanding in-place modification of data structures while keeping track of necessary information efficiently. By using the first row and column as markers, we are able to significantly improve space efficiency compared to the brute-force approach.

Try implementing this solution and see how it can be applied to similar matrix-related problems. Happy coding!

README for [Set Matrix Zeroes (Leetcode #73)](https://blog.unwiredlearning.com/set-matrix-zeroes) was compiled from the Unwired Learning Blog.  
//### 022 File: 0076-minimum-window-substring/README.md
# Minimum Window Substring (Leetcode #76)

The "Minimum Window Substring" problem is a classic challenge often featured in coding interviews, especially on platforms like LeetCode. It requires a blend of logical thinking and an understanding of efficient algorithms, making it a great test of problem-solving skills. The objective is to find the smallest substring of a given string that contains all the characters of another string. This guide will walk you through understanding the problem, exploring a brute force solution, and ultimately implementing an optimized approach using the sliding window technique.

## Understanding the Problem Statement

The "Minimum Window Substring" problem from LeetCode, labeled as problem number 76, is one that challenges your problem-solving skills and knowledge of efficient sliding window techniques. Given two strings `s` (the source string) and `t` (the target string), the task is to find the minimum window in `s` which will contain all the characters in `t` (including duplicates, if any) in any order. If no such window exists, you return an empty string.

In simpler terms, you need to find the smallest substring of `s` that includes every character from `t`. For instance, given `s = "ADOBECODEBANC"` and `t = "ABC"`, the minimum window substring is `"BANC"`. The goal is to determine the optimal window in which all characters of `t` are found.

## Brute Force Approach

The brute force solution involves checking all possible substrings of `s` to find the smallest one that contains all characters of `t`. Essentially, we iterate through every substring of `s`, and for each substring, we verify if all characters from `t` are present.

However, this approach is very inefficient, with a time complexity of `O(N^3)` for strings of length `N`, because we are generating every possible substring, checking for the presence of characters, and doing this for each character in `s`. It is not feasible for large inputs and quickly becomes impractical.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, you need to utilize the "Sliding Window" technique, which allows you to keep track of a current window that expands and contracts as needed. Here are a few hints to help you:

1. Use two pointers, `left` and `right`, to represent the current window in `s`. Start by expanding the window by moving `right` to include characters until all characters of `t` are present.
    
2. Once all characters are included, start contracting the window from the `left` to minimize the size, while ensuring all characters of `t` are still present.
    
3. Utilize a character frequency map to keep track of the characters from `t` in the current window.
    

## Efficient Solution

The efficient approach leverages the sliding window technique. Below is the step-by-step explanation of the code:

1. **Initialization**: Create two pointers, `left` and `right`, both initially set to the start of the string `s`. Use two dictionaries, `dict_t` to store the frequency of characters in `t`, and `window_counts` to store the frequency of characters in the current window.
    
2. **Expand the Window**: Move the `right` pointer to expand the window, adding characters to `window_counts`. Keep track of how many target characters have been fully matched.
    
3. **Contract the Window**: Once all characters from `t` are in the current window, attempt to minimize the window by moving the `left` pointer to the right. Update the result whenever a smaller valid window is found.
    
4. **Update the Result**: Throughout the process, maintain variables to store the minimum window's length and its position.
    

Here's the solution code based on the provided efficient approach:

```python
from collections import Counter, defaultdict

def minWindow(s: str, t: str) -> str:
    if not s or not t:
        return ""

    # Count all characters in t
    dict_t = Counter(t)
    required = len(dict_t)

    # Use two pointers to create the sliding window
    left, right = 0, 0
    formed = 0
    window_counts = defaultdict(int)
    min_len = float("inf")
    min_left, min_right = 0, 0

    while right < len(s):
        char = s[right]
        window_counts[char] += 1

        if char in dict_t and window_counts[char] == dict_t[char]:
            formed += 1

        while left <= right and formed == required:
            char = s[left]

            if right - left + 1 < min_len:
                min_len = right - left + 1
                min_left, min_right = left, right

            window_counts[char] -= 1
            if char in dict_t and window_counts[char] < dict_t[char]:
                formed -= 1

            left += 1

        right += 1

    return "" if min_len == float("inf") else s[min_left:min_right + 1]
```

In this solution, we use a sliding window approach to efficiently track the required characters. The dictionary `window_counts` keeps track of how many times a character appears in the current window, while `formed` ensures that all characters in `t` are fully present. The outer loop moves the `right` pointer to expand the window, and the inner loop moves `left` to minimize the window size.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(N + M)`, where `N` is the length of `s` and `M` is the length of `t`. In the worst case, each character of `s` is visited twice by both `left` and `right` pointers, giving us a linear complexity.
    
* **Space Complexity**: The space complexity is `O(N + M)` because we are using dictionaries to store character frequencies from both `s` and `t`. The additional space used is proportional to the number of unique characters in both strings.
    

This efficient solution ensures that we minimize the length of the substring while only expanding or contracting the window as necessary, making it a much better alternative to the brute force approach.

## Conclusion

The "Minimum Window Substring" problem is an excellent example of how an optimized sliding window approach can significantly improve the performance compared to a brute force solution. By carefully expanding and contracting the window, and leveraging character frequency maps, we achieve a time-efficient solution that is well-suited for real-world applications. Mastering this problem helps in honing one's ability to deal with substring-related challenges and sharpens overall problem-solving skills. Remember, understanding when to use the sliding window technique is key to solving many similar problems efficiently. Keep practicing, and you'll find yourself more comfortable with these types of algorithmic challenges.


README for [Minimum Window Substring (Leetcode #76)](https://blog.unwiredlearning.com/minimum-window-substring) was compiled from the Unwired Learning Blog.  
//### 023 File: 0079-word-search/README.md
# Word Search (Leetcode #79)

The "Word Search" problem is a challenging LeetCode problem where you are given a grid (board) filled with characters and a target word. The objective is to determine if the target word can be constructed by sequentially moving through adjacent cells in the grid. The cells can be connected either horizontally or vertically, and each letter can only be used once in a particular path.

## Understanding the Problem Statement

In the "Word Search" problem, you are given a 2D board of characters and a target word. The goal is to determine if the word can be found in the board by sequentially adjacent cells. You can move horizontally or vertically between adjacent cells, but you cannot use the same cell more than once in constructing the word. For example, given a board:

```python
[['A', 'B', 'C', 'E'],
 ['S', 'F', 'C', 'S'],
 ['A', 'D', 'E', 'E']]
```

and a word "ABCCED", the result is `True` since the word can be traced through the board starting at the top-left.

This problem can be challenging because you must explore all possible paths from each starting point and backtrack when necessary, ensuring each letter is used exactly once in each potential word match.

The "Word Search" problem is a popular LeetCode challenge that asks you to determine if a given word can be constructed by sequentially adjacent cells on a grid of letters. Adjacent cells are defined as being either horizontally or vertically neighboring. Each letter must be used only once, which means we cannot revisit a cell. This problem often tests one's ability to effectively traverse a matrix in a recursive manner, making it an excellent candidate to apply Depth-First Search (DFS).

## Brute Force Approach

The brute force approach to solve this problem is to check every cell of the board, treating each cell as a possible starting point for the word. From each cell, we recursively search in all possible directions (up, down, left, and right) until we either find the word or exhaust all possibilities. Although this approach can technically work, it is quite inefficient, especially when the grid size is large or the word length is significant. Each incorrect path has to be retraced, which makes it time-consuming.

## Hint to Solve the Problem Efficiently

A more efficient solution requires using the Depth-First Search (DFS) technique. The key observation here is that we can perform a recursive DFS search, starting from each cell, while keeping track of the word character we are currently trying to match. During the search, we must ensure that we do not revisit any character that we have already used, and also avoid exploring cells that go beyond the bounds of the board.

## Efficient Solution

The efficient solution, as seen in the provided code, uses DFS to search for the target word starting from any cell that matches the first character of the word. Here is a step-by-step breakdown of the provided code:

* **Class and Function Definition**: The solution is implemented in a class named `Solution`, with the main function `exist()` which takes in a `board` and the `word` to search for.
    
* **DFS Function**: A nested function `dfs(i, j, k)` is defined to perform the DFS operation. The parameters `i` and `j` are the current row and column indices, and `k` is the index of the current character in the word that we are trying to match.
    
* **Base Condition**: The DFS function returns `True` if `k` matches the length of the word, indicating that the entire word has been successfully matched.
    
* **Boundary and Character Check**: The function checks if the current cell `(i, j)` is out of bounds or if the current character does not match the corresponding character in the word. If either condition is true, it returns `False`.
    
* **Recursive Calls**: If the character matches, the current cell is temporarily marked as visited by setting it to a non-letter character (e.g., `/`) to avoid revisiting. Then, the DFS function is recursively called for all adjacent cells (up, down, left, and right).
    
* **Backtracking**: After all possible moves from a given cell have been tried, the cell value is restored, allowing it to be used in other recursive paths.
    
* **Iterate Over Board**: Finally, the function iterates over each cell of the board, initiating the DFS search if the character matches the first character of the word.
    

The solution effectively uses backtracking to manage the state of each cell, ensuring that we do not use the same cell twice for matching the word, while also restoring the board to its original state after exploring each path.

## Time and Space Complexity

* **Time Complexity**: The time complexity of the solution is `O(N * 3^L)`, where `N` is the total number of cells in the board and `L` is the length of the word. This is because each cell can potentially lead to three other recursive calls (excluding the direction it came from).
    
* **Space Complexity**: The space complexity is `O(L)` where `L` is the length of the word. This space is used for the recursion stack in the worst-case scenario, which occurs when the entire word is explored.
    

The use of backtracking ensures that the board is always restored to its original state after exploring each possibility, which is key to efficiently solving the problem without using additional memory for storing the state of the board.

## Conclusion

The "Word Search" problem is a great exercise in understanding how to effectively navigate a grid using recursion and backtracking. By carefully managing the state of each cell and ensuring that we explore all possible paths without repetition, we can significantly optimize our solution. Understanding the depth-first search strategy and the importance of backtracking in this context can help in tackling similar problems involving matrix traversal.

README for [Word Search (Leetcode #79)](https://blog.unwiredlearning.com/word-search) was compiled from the Unwired Learning Blog.  
//### 024 File: 0091-decode-ways/README.md
# Decode Ways (Leetcode #91)

Have you ever wondered how a sequence of numbers could be translated into meaningful text, similar to decoding a secret message? The **"Decode Ways"** problem is a classic challenge that invites you to determine how many ways a given sequence of digits can be decoded into letters. In this blog, we'll explore how to solve this problem using different approaches, starting with a brute force method and eventually moving towards a more efficient solution using dynamic programming.

## Understanding the Problem Statement

The **"Decode Ways"** problem involves decoding a string of digits, where each character represents a digit between '1' and '9'. These digits map to letters in the alphabet as follows:

* '1' maps to 'A'
    
* '2' maps to 'B'
    
* ...
    
* '26' maps to 'Z'
    

Given a string `s` consisting of only digits, the objective is to determine the number of ways it can be decoded into letters. The rules are:

* Each digit can be decoded on its own (if it is between '1' and '9').
    
* A pair of two consecutive digits can also be decoded if it represents a valid character (i.e., a number between '10' and '26').
    
* Sequences starting with '0' are invalid and cannot be decoded.
    

For example:

* Input: "12" Output: 2 Explanation: "12" can be decoded as "AB" (1, 2) or "L" (12).
    
* Input: "226" Output: 3 Explanation: "226" can be decoded as "BZ" (2, 26), "VF" (22, 6), or "BBF" (2, 2, 6).
    

## Brute Force Approach

A straightforward way to solve this problem is through a brute force approach, which involves recursively considering every possible way to split the given string:

1. Start with the first character and check if it forms a valid letter ('1' to '9'). If it does, recursively proceed with the rest of the string.
    
2. Similarly, check if the first two characters together form a valid letter ('10' to '26'). If so, recursively decode the remainder of the string.
    

This method explores all possible decoding paths. While this approach is simple, it is highly inefficient due to the repeated recalculation of overlapping subproblems, especially for long strings.

**Drawbacks of the Brute Force Approach:**

* **Time Complexity:** The time complexity is exponential, as it involves exploring every possible combination of valid splits.
    
* **Space Complexity:** The recursive calls lead to a significant usage of the call stack, increasing space complexity.
    

## Hint to Solve the Problem Efficiently

The dynamic programming approach aims to solve this problem by storing intermediate results to avoid recalculating the same subproblems. By utilizing an array (`dp`) to keep track of the number of ways to decode substrings of various lengths, we can build on previous results to derive the final answer in a more efficient manner.

## Efficient Solution

The efficient solution for the **"Decode Ways"** problem uses dynamic programming, as illustrated in the provided code below:

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0

        n = len(s)
        dp = [0] * (n + 1)

        # Base cases
        dp[0], dp[1] = 1, 1

        for i in range(2, n + 1):
            # Single digit decode
            if 1 <= int(s[i-1:i]) <= 9:
                dp[i] += dp[i-1]

            # Two digit decode
            if 10 <= int(s[i-2:i]) <= 26:
                dp[i] += dp[i-2]

        return dp[n]
```

**Explanation:**

* **Base Cases:**
    
    * `dp[0]` is set to 1, representing an empty string that can be decoded in one way.
        
    * `dp[1]` is set to 1 because a single valid digit can be decoded in one way, as long as it is not '0'.
        
* **Iterative Calculation:**
    
    * We iterate over the string starting from index 2.
        
    * For each character, we check if the single-digit value (`s[i-1:i]`) is valid (between '1' and '9'). If it is, we add the number of ways to decode up to the previous character (`dp[i-1]`).
        
    * We also check if the two-digit value (`s[i-2:i]`) is valid (between '10' and '26'). If so, we add the number of ways to decode up to the character before the last two (`dp[i-2]`).
        

This approach avoids redundant calculations by storing intermediate results, making it far more efficient than the brute force approach.

## Time and Space Complexity

* **Time Complexity:** The time complexity of the dynamic programming solution is **O(n)**, where `n` is the length of the input string. This is because we iterate over the entire string once, and each operation takes constant time.
    
* **Space Complexity:** The space complexity is **O(n)** due to the use of the `dp` array of size `n + 1`. However, this could be further optimized to **O(1)** by using just two variables to keep track of the last two results instead of maintaining an entire array.
    

## Conclusion

The **"Decode Ways"** problem is a great exercise for understanding how to apply dynamic programming to problems involving overlapping subproblems and multiple recursive calls. By storing intermediate results and building upon them, we can achieve a significant reduction in time complexity compared to the brute force approach. We hope this blog has given you a clear understanding of both the brute force and dynamic programming approaches to solving this problem, and provided you with insights into optimizing your solutions for similar challenges.

README for [Decode Ways  (Leetcode #91)](https://blog.unwiredlearning.com/decode-ways) was compiled from the Unwired Learning Blog.  
//### 025 File: 0098-validate-binary-search-tree/README.md
# Validate Binary Search Tree (Leetcode #98)

The "Validate Binary Search Tree" (BST) is a popular problem from Leetcode (problem #98) that often challenges developers during coding interviews. In this blog, we will cover everything you need to solve this problem, including a common brute-force approach, a hint to get you thinking in the right direction, and a more efficient solution.

## Understanding the Problem Statement

The problem asks you to determine whether a given binary tree is a valid binary search tree. A valid BST has the following properties:

* The left subtree of a node contains only nodes with values less than the node's value.
    
* The right subtree of a node contains only nodes with values greater than the node's value.
    
* Both the left and right subtrees must also be valid binary search trees.
    

The input is the root of a binary tree, and you need to return `true` if it is a valid BST and `false` otherwise. This requires you to navigate the binary tree and ensure all nodes respect the properties of a BST.

## Brute Force Approach

A simple brute-force approach to solving this problem is to perform an in-order traversal of the tree and store the values in a list. If the in-order traversal yields a sorted list with strictly increasing values, then the tree is a valid BST. This approach involves three major steps:

1. Perform an in-order traversal of the binary tree and store the values in a list.
    
2. Iterate through the list to check if the elements are sorted in strictly increasing order.
    
3. If all elements are in order, return `true`; otherwise, return `false`.
    

While this approach works, it is not the most efficient, as it requires additional memory to store the nodes' values in a list.

## Hint to Solve the Problem Efficiently

Think about the properties of a BST and how you can verify these properties while traversing the tree. Instead of storing the nodes in a list, can you maintain a boundary for each node to check whether it is valid? Consider how you might keep track of the valid range for each node as you traverse the tree.

## Efficient Solution

The provided solution uses an in-order traversal to validate the BST property. Let's break down how the code works efficiently to solve the problem.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # List to store the values of nodes in in-order traversal
        io_list = []
        
        # Populate the io_list with the in-order traversal of the tree
        self.helper(root, io_list)

        # Assume the tree is a BST initially
        is_bst = True
        # Keep track of the previous value in the in-order traversal
        prev = io_list[0]

        # Iterate through the in-order list to check if it's sorted in increasing order
        for i in range(1, len(io_list)):
            # If the current value is not greater than the previous value, it's not a BST
            if io_list[i] <= prev:
                is_bst = False
            prev = io_list[i]

        # Return the final result
        return is_bst

    def helper(self, tree_node, io_list):
        # Base case: if the node is None, return
        if tree_node is None:
            return

        # Recursive call on the left subtree
        self.helper(tree_node.left, io_list)
        # Append the current node's value to the in_order_list
        io_list.append(tree_node.val)
        # Recursive call on the right subtree
        self.helper(tree_node.right, io_list)
```

**Explanation**:

1. **In-Order Traversal**: The helper function is used to perform an in-order traversal of the tree, storing the node values in `io_list`. An in-order traversal of a BST should produce a sorted list.
    
2. **Checking BST Property**: Once we have the in-order traversal list, we iterate through it to verify that each value is greater than the previous one. If we find any value that violates this property, we conclude that the tree is not a BST.
    

This solution effectively captures the properties of a BST by leveraging in-order traversal and verifying the ordering.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(N)`, where `N` is the number of nodes in the tree. This is because we traverse all nodes in the binary tree exactly once.
    
* **Space Complexity**: The space complexity is also `O(N)` due to the storage of node values in the list `io_list`. Additionally, the recursion stack in the worst case could require `O(N)` space if the tree is unbalanced.
    

While this approach has some memory overhead, it provides a clear and simple solution to validate the BST property efficiently.

## Conclusion

The "Validate Binary Search Tree" problem is an excellent exercise for understanding the fundamental properties of binary search trees. By using an in-order traversal, you can efficiently verify whether a tree satisfies the BST property. While there are multiple ways to solve this problem, the efficient approach presented here balances clarity and simplicity, making it a reliable method for tackling BST validation. Understanding both the brute-force and optimized methods will help you be well-prepared for similar coding challenges in the future.


README for [Validate Binary Search Tree (Leetcode #98)](https://blog.unwiredlearning.com/validate-binary-search-tree) was compiled from the Unwired Learning Blog.  
//### 026 File: 0100-same-tree/README.md
# Same Tree (Leetcode #100)

The "Same Tree" problem is a classic question that tests your understanding of binary tree structures and your ability to solve problems using recursion. In this post, we'll take a look at the problem, discuss a brute-force approach, provide hints, and share an efficient solution. Let's dive in!

## Understanding the Problem Statement

The problem "Same Tree" asks whether two given binary trees are structurally identical and have identical node values.

In other words, given two binary trees, you need to determine if they are the same—meaning they have the same shape and each corresponding node contains the same value.

For example:

```python
yamlCopy codeInput: p = [1, 2, 3], q = [1, 2, 3]
Output: true

Input: p = [1, 2], q = [1, null, 2]
Output: false
```

## Brute Force Approach

A straightforward way to solve this problem is to perform level-order traversal (or breadth-first traversal) on both trees simultaneously and compare the nodes at every level. If at any point you find that a node in one tree does not match the corresponding node in the other, the trees are not the same.

However, using level-order traversal can be unnecessarily complex for this problem, as it requires additional data structures (e.g., queues) to hold nodes at each level. This brute-force approach often leads to higher memory usage, making it less efficient.

## Hint to Solve the Problem Efficiently

Instead of using a brute-force traversal approach, consider a recursive solution. Since each node has only a left and right child, recursion can easily handle the comparison by navigating through both trees simultaneously. The recursion will check if both nodes are `None`, and if they aren’t, it will compare their values and proceed to their respective children.

## Efficient Solution

Below is an efficient solution that uses recursion to solve the problem. We will determine if the given trees `p` and `q` are the same using a recursive approach, as shown in the provided code:

```python
pythonCopy code# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Base case: if both trees are empty
        if p == None and q == None:
            return True
        
        # Trees are not the same if either of them is empty or values are different
        if p == None or q == None or p.val != q.val:
            return False
        
        # Check recursively for left and right subtrees
        left_compare = self.isSameTree(p.left, q.left)
        right_compare = self.isSameTree(p.right, q.right)

        return left_compare and right_compare
```

In this solution:

* We start by handling the base case where both trees are empty (`None`). If both are empty, then they are considered identical.
    
* If one of the trees is empty or the values at the current nodes differ, we return `False`.
    
* Otherwise, we recursively check the left and right children of both trees.
    
* Finally, we return the combined result of the left and right subtree comparisons.
    

## Time and Space Complexity

* **Time Complexity**: `O(N)`  
    The time complexity is `O(N)` where `N` is the number of nodes in each tree. In the worst case, we need to visit every node in both trees to ensure they are identical.
    
* **Space Complexity**: `O(H)`  
    The space complexity is `O(H)` where `H` is the height of the tree. This is due to the space taken up by the recursive call stack. In the worst case, for a skewed tree, this could be as high as `O(N)`, while for a balanced tree, it will be `O(log N)`.
    

## Conclusion

The "Same Tree" problem is an excellent example of using recursion to solve problems with hierarchical structures like trees. While brute-force methods can be effective, leveraging recursion leads to a more intuitive and efficient solution.

If you're preparing for coding interviews, understanding this recursive approach will help you solve other similar problems involving binary trees.

Try coding this up and running it on a few different test cases to build your understanding. Keep practicing, and soon these recursive patterns will become second nature!


README for [Same Tree (Leetcode #100)](https://blog.unwiredlearning.com/same-tree) was compiled from the Unwired Learning Blog.  
//### 027 File: 0102-binary-tree-level-order-traversal/README.md
# Binary Tree Level Order Traversal (Leetcode #102)

The Binary Tree Level Order Traversal question is a popular problem from LeetCode that involves traversing a binary tree level by level, similar to reading a book from top to bottom, left to right. In this blog post, we will break down the question, provide a common brute-force approach, a hint, and then dive into the efficient solution according to the provided code.

## Understanding the Problem Statement

The problem is to traverse a binary tree in level order and return each level as a list of nodes. Each level should be represented in a list, and all levels should be combined into a single list of lists.

For example, consider the following binary tree:

```python
       3
      / \
     9  20
       /  \
      15   7
```

The output should be:

```python
[
  [3],
  [9, 20],
  [15, 7]
]
```

The goal is to return a nested list where each inner list represents nodes at the same level of the tree.

## Brute Force Approach

The brute-force way to solve this problem is to perform a depth-first search (DFS) and keep track of the level of each node. The idea is to use a recursive function that traverses each node, passing the level as a parameter and appending the node value to a corresponding list. However, maintaining and updating the levels in this manner can be quite cumbersome, especially for larger trees.

In DFS, managing nodes at each level explicitly and organizing them into the desired format can require additional bookkeeping, making it less efficient in terms of both runtime and space usage.

## Hint to Solve the Problem Efficiently

To solve this problem more efficiently, consider using a breadth-first search (BFS) approach. The BFS approach is particularly well-suited for level-order traversal since it processes nodes level by level, making it straightforward to organize nodes into levels as needed.

The provided solution code uses a queue to implement BFS, which allows us to efficiently traverse the tree while keeping track of the nodes at each level.

## Efficient Solution

The provided efficient solution uses a queue to achieve a level-order traversal of the binary tree. Here is a step-by-step explanation:

```python
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
    
        result, queue = [], [root]

        # Continue until there are no nodes left in the queue
        while queue:
            # Store the number of nodes at the current level
            level_size = len(queue)
            level = []
            
            # Iterate over all nodes at the current level
            for _ in range(level_size):
                node = queue.pop(0)
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(level)
        
        return result
```

Here’s a breakdown of how this code works:

1. **Initialization**: We initialize an empty list `result` to store the level-wise node values and a `queue` that initially contains the root node.
    
2. **Traversal**: The while loop continues as long as there are nodes in the queue. At each iteration, we determine the number of nodes at the current level (`level_size`) and initialize an empty list (`level`) to store the node values for the current level.
    
3. **Processing Each Level**: For each node at the current level, we remove the node from the queue, append its value to the `level` list, and add its left and right children (if they exist) to the queue.
    
4. **Appending Levels**: Once all nodes at the current level have been processed, we append the `level` list to `result`.
    
5. **Returning Result**: Finally, the `result` list, containing all levels, is returned.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(N)**, where **N** is the number of nodes in the binary tree. Each node is visited once, and all operations involving each node (like adding children to the queue) take constant time.
    
* **Space Complexity**: The space complexity is **O(N)**. In the worst case, the queue will contain all nodes at the current level, which can be up to **N/2** nodes for a complete binary tree, resulting in **O(N)** space usage.
    

Using a queue for BFS helps ensure that each level of the tree is processed in sequence, making this approach both efficient and easy to implement.

## Conclusion

The Binary Tree Level Order Traversal problem is an excellent example of when to use breadth-first search (BFS) for efficient tree traversal. By leveraging a queue, we can ensure that nodes are processed level by level, which makes organizing them straightforward and efficient. The provided solution is optimal in terms of both time and space complexity, making it a robust approach for level-order traversal of binary trees. Whether you're preparing for coding interviews or enhancing your problem-solving skills, understanding and implementing BFS for tree problems is a valuable technique to master.


README for [Binary Tree Level Order Traversal (Leetcode #102)](https://blog.unwiredlearning.com/binary-tree-level-order-traversal) was compiled from the Unwired Learning Blog.  
//### 028 File: 0104-maximum-depth-of-binary-tree/README.md
# Maximum Depth of Binary Tree (Leetcode #104)

The problem of finding the "Maximum Depth of Binary Tree" is a common question in technical interviews, particularly for those involving data structures and algorithms. It tests your understanding of binary trees and the ability to implement efficient traversal techniques. In this blog post, we will explore different approaches to solve this problem, starting with a brute force method and then moving on to a more optimized solution. We will also analyze the time and space complexities involved.

## Understanding the Problem Statement

The question "Maximum Depth of Binary Tree" asks us to determine the maximum depth (or height) of a binary tree, which represents the longest path from the root node down to the farthest leaf node. A binary tree is a data structure made up of nodes, where each node has a value and at most two children: a left child and a right child.

The depth of a binary tree is defined as the number of nodes along the longest path from the root to a leaf. For example, an empty tree has a depth of 0, while a tree with just a single node has a depth of 1.

## Brute Force Approach

A common brute-force approach to solving this problem involves using recursion. We can traverse all nodes of the binary tree to find the maximum depth by recursively finding the maximum depth of the left and right subtrees, then taking the greater of the two values and adding 1 (for the current node). This approach is straightforward but not necessarily the most efficient due to potential stack overflow with deep recursion.

Here is a simple example of the brute force approach:

```python
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```

The brute force solution uses recursion to traverse all nodes, and while it works well for small trees, it can result in inefficiency and stack overflow for larger trees.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, consider using an iterative approach with a stack to perform depth-first traversal. This method can avoid the pitfalls of recursion (such as stack overflow) and can be more suitable for large trees. The solution relies on the use of a stack to keep track of nodes and their respective depths.

## Efficient Solution

The provided code employs an iterative approach using a stack to determine the maximum depth of the binary tree. This method avoids the issues of recursion depth by explicitly managing the traversal stack.

```python
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        max_depth = 0
        
        # Stack of (node, depth) pairs
        stack = [(root, 1)]

        while stack:
            node, depth = stack.pop()
            
            if node:
                max_depth = max(max_depth, depth)
                if node.left:
                    stack.append((node.left, depth + 1))                    
                if node.right:
                    stack.append((node.right, depth + 1))

        return max_depth
```

In this approach, we initialize a stack with the root node and depth 1. The stack stores pairs of nodes and their respective depths. As we iterate, we pop nodes from the stack, update the maximum depth, and push the children nodes (if they exist) with incremented depth values back onto the stack. This ensures we traverse every node, updating the maximum depth as we go.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(N)**, where **N** is the number of nodes in the binary tree. This is because we need to visit each node exactly once to determine the maximum depth.
    
* **Space Complexity**: The space complexity of the solution is **O(N)** in the worst case. In the worst-case scenario, the binary tree is completely unbalanced (i.e., all nodes are on one side), resulting in a stack that grows to **N** nodes. For a balanced tree, the space complexity would be **O(log N)** due to the height of the tree being **log N**.
    

## Conclusion

Finding the maximum depth of a binary tree is a fundamental problem that helps in understanding the basics of tree traversal. While a brute-force recursive approach can solve the problem, an iterative approach using a stack is more efficient and avoids potential pitfalls associated with recursion, especially for larger trees. By using iterative depth-first traversal, we can ensure a robust solution that handles both balanced and unbalanced trees effectively.

Understanding different methods to solve this problem provides valuable insight into tree traversal techniques and their respective advantages and trade-offs. Whether you are preparing for an interview or enhancing your problem-solving skills, mastering both approaches is essential.


README for [Maximum Depth of Binary Tree (Leetcode #104)](https://blog.unwiredlearning.com/maximum-depth-of-binary-tree) was compiled from the Unwired Learning Blog.  
//### 029 File: 0105-construct-binary-tree-from-preorder-and-inorder-traversal/README.md
# Construct Binary Tree from Preorder and Inorder Traversal (Leetcode #105)

Reconstructing a binary tree from its traversal sequences is a common problem in computer science, particularly in the domain of tree data structures. This problem not only tests your understanding of tree traversal techniques but also challenges your ability to use recursion effectively. In this blog, we will discuss how to construct a binary tree from given preorder and inorder traversal sequences, explore a brute force approach, and then delve into a more efficient solution.

## Understanding the Problem Statement

In this problem, you are given the preorder and inorder traversal sequences of a binary tree, and your task is to reconstruct the original binary tree.

The **preorder traversal** visits nodes in the order: root, left subtree, right subtree. The **inorder traversal** visits nodes in the order: left subtree, root, right subtree. Using both of these traversals, you can determine the structure of the entire binary tree.

For instance, suppose you have the following preorder and inorder sequences:

* Preorder: `[3, 9, 20, 15, 7]`
    
* Inorder: `[9, 3, 15, 20, 7]`
    

Your task is to use these two sequences to build the binary tree from scratch.

## Brute Force Approach

A common brute force approach to solving this problem would be to first identify the root element from the preorder sequence, then locate it in the inorder sequence to divide the sequence into left and right subtrees. This process is repeated recursively to build the entire tree.

However, this approach is inefficient since every recursive call involves searching through the inorder sequence to find the root element, leading to high time complexity due to repeated linear scans. Specifically, if we denote the length of the sequences as `n`, the time complexity of this brute force approach is **O(n^2)**, which becomes infeasible for larger inputs.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, think about how you can minimize the repeated searching in the inorder sequence. By precomputing a mapping from value to index in the inorder sequence, you can reduce the time complexity of each lookup from **O(n)** to **O(1)**.

## Efficient Solution

The provided code leverages a dictionary to map each value in the inorder sequence to its index, allowing for constant-time lookups. This reduces the time complexity significantly. Below, I will walk you through the solution:

```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # Create a map to efficiently find the index of any element in inorder list
        io_map = {}
        for i in range(len(inorder)):
            io_map[inorder[i]] = i

        # Call recursive helper function to build the tree
        return self.splitTree(preorder, io_map, 0, 0, len(inorder) - 1)

    def splitTree(self, preorder, io_map, rootIndex, left, right):
        # Base case: if the left index exceeds the right index, subtree is empty
        if left > right:
            return None

        # Create the root node with the current root element
        root = TreeNode(preorder[rootIndex])

        # Find the index of the root element in inorder list
        mid = io_map[preorder[rootIndex]]

        # Recursively build the left subtree
        if mid > left:
            root.left = self.splitTree(preorder, io_map, rootIndex + 1, left, mid - 1)

        # Recursively build the right subtree
        if mid < right:
            root.right = self.splitTree(preorder, io_map, rootIndex + mid - left + 1, mid + 1, right)

        return root
```

**Explanation**:

1. The `buildTree` function initializes a map (`io_map`) to store the index of each element from the inorder list.
    
2. The `splitTree` function is then called recursively to construct the binary tree.
    
    * The root is created using the current element from the preorder list.
        
    * Using `io_map`, the position of this root element in the inorder list is found, which helps determine the boundaries of the left and right subtrees.
        
    * The function then recursively constructs the left and right subtrees by adjusting the preorder index and the boundaries accordingly.
        

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n)**, where `n` is the number of nodes in the tree. This is because each node is visited once, and with the help of the dictionary (`io_map`), each lookup takes constant time.
    
* **Space Complexity**: The space complexity is **O(n)** as well. The dictionary takes **O(n)** space to store the indices of the inorder sequence, and the recursion stack may also use up to **O(n)** space in the worst case, such as when the tree is highly unbalanced.
    

## Conclusion

Reconstructing a binary tree from its preorder and inorder traversal sequences can seem challenging at first, but with an efficient approach, it becomes quite manageable. By leveraging a dictionary to avoid repeated searches in the inorder list, we achieve a significant performance boost compared to the brute force approach. This problem is an excellent example of how thoughtful data structure choices can lead to more efficient algorithms, ultimately making our solutions scalable and practical for larger inputs.


README for [Construct Binary Tree from Preorder and Inorder Traversal (Leetcode #105)](https://blog.unwiredlearning.com/construct-binary-tree-from-preorder-and-inorder-traversal) was compiled from the Unwired Learning Blog.  
//### 030 File: 0121-best-time-to-buy-and-sell-stock/README.md
# Best Time to Buy and Sell Stock (Leetcode #121)

LeetCode's "121. Best Time to Buy and Sell Stock" is a popular question that challenges you to determine the best profit you can achieve from a series of stock prices, given the constraint that you can only buy and sell once. This question tests your ability to effectively use optimization techniques to minimize costs and maximize profits.

## Understanding the Problem Statement

The problem statement is as follows: You are given an array `prices` where `prices[i]` represents the stock price on day `i`. You need to determine the maximum profit you can achieve by buying and selling the stock once. If no profit is possible, you should return `0`. Note that you cannot sell a stock before buying one.

## Brute Force Approach

A common initial approach to this problem is to use a brute force solution. In this approach, you would iterate over all possible pairs of days to determine which combination of buying and selling yields the highest profit. Essentially, you:

* Iterate through every day `i` and for each day `i`, iterate through the subsequent days `j` to compute `prices[j] - prices[i]`.
    
* Track the maximum profit obtained during these comparisons.
    

The brute force solution has a time complexity of `O(n^2)` because it involves nested loops to compare every possible pair of buy and sell days. While this solution is straightforward, it is inefficient for large input sizes, leading to poor performance.

## Hint to Solve the Problem Efficiently

The key to optimizing the brute force solution lies in finding a way to avoid redundant calculations. Instead of evaluating all pairs, think about tracking the lowest buying price as you traverse the list, while also calculating the profit if you were to sell on the current day. By keeping track of the minimum price seen so far and the maximum profit at each step, you can achieve a linear time solution.

## Efficient Solution

Below is an efficient solution for the problem, based on the code provided:

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # minimum buy price is the first price
        buy_price = prices[0]

        # the minimum profit is zero
        profit = 0

        for i in range(1, len(prices)):

            # if the current price is less, update the buy_price
            if prices[i] < buy_price:
                buy_price = prices[i]
            else:
                # else check if we can get a better profit
                current_profit = prices[i] - buy_price
                profit = max(current_profit, profit)

        return profit
```

This solution works by iterating through the list of prices only once, maintaining two key variables:

1. **buy\_price**: Keeps track of the lowest price seen so far, which represents the ideal day to buy the stock.
    
2. **profit**: Tracks the maximum profit obtained up to the current day.
    

During each iteration, if the current price is lower than `buy_price`, we update `buy_price`. Otherwise, we calculate the profit by subtracting `buy_price` from the current price, and update `profit` if the current profit is greater than the previously recorded maximum.

## Time and Space Complexity

* **Time Complexity**: The efficient solution has a time complexity of `O(n)` because it involves a single pass through the `prices` array of length `n`. Each price is considered exactly once, making this approach much more optimal compared to the brute force solution.
    
* **Space Complexity**: The space complexity is `O(1)` since we are only using a constant amount of extra space (`buy_price` and `profit`) to store interim values. There is no additional space requirement that grows with the input size.
    

## Conclusion

By leveraging an iterative approach that maintains the minimum buying price and maximum profit, you can solve the "Best Time to Buy and Sell Stock" problem in an efficient manner. This solution highlights the importance of tracking optimal subproblems while iterating through an array, which is a common strategy in optimization problems.


README for [Best Time to Buy and Sell Stock (Leetcode #121)](https://blog.unwiredlearning.com/best-time-to-buy-and-sell-stock) was compiled from the Unwired Learning Blog.  
//### 031 File: 0124-binary-tree-maximum-path-sum/README.md
# Binary Tree Maximum Path Sum (Leetcode #124)

In this blog post, we’re going to dive into a classic algorithm problem from LeetCode - "Binary Tree Maximum Path Sum." This problem challenges our understanding of tree traversal techniques and how to efficiently manage potential paths through a binary tree to achieve the maximum sum.

## Understanding the Problem Statement

The "Binary Tree Maximum Path Sum" problem involves finding the maximum path sum in a given binary tree. Here, a path is defined as any sequence of nodes starting from some node and ending at any other node along the parent-child connections. Importantly, paths don't have to pass through the root.

The task is to return the highest possible sum of node values from any such path within the given tree. For instance, if a tree contains negative values, our answer may just be a single node that holds the maximum value.

## Brute Force Approach

A brute force approach to solve this problem could involve attempting to calculate the path sum for all possible paths that exist in the tree. This could be done by considering each node as a potential "root" of a subtree and recursively finding paths through all possible combinations. This method quickly becomes inefficient as the number of nodes increases, leading to a time complexity of O(2^n) where n is the number of nodes. The overlapping subproblems, combined with recalculating the path sums again and again, make this approach impractical for large trees.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, consider employing a Depth-First Search (DFS) strategy that traverses the tree only once, while keeping track of the maximum sum encountered during this traversal. Utilize recursion to accumulate the path sum, and always return the maximum possible contribution that the current node and its subtrees can provide.

The key idea here is to consider the possibility of a "new path" starting at the current node, which could lead to a higher sum than merely continuing along an existing path. By balancing between starting new paths and continuing previous ones, you ensure that the global maximum is always updated correctly.

## Efficient Solution

The provided code leverages a DFS approach to solve the problem in an efficient manner. Here's a step-by-step breakdown of how it works:

```python
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = float('-inf')

        def dfs(node):
            if not node:
                return 0

            # Recursive call on left and right child
            left_gain = max(dfs(node.left), 0)
            right_gain = max(dfs(node.right), 0)

            # Update max_sum if it's better to start a new path
            price_newpath = node.val + left_gain + right_gain
            nonlocal max_sum
            max_sum = max(max_sum, price_newpath)

            # For recursion return the max gain if continue the same path
            return node.val + max(left_gain, right_gain)

        dfs(root)
        return max_sum
```

**Explanation**

1. **Initialization**: We define `max_sum` to keep track of the global maximum path sum encountered. Initially, it's set to negative infinity.
    
2. **DFS Function**: The `dfs(node)` function is used to traverse the binary tree recursively.
    
    * If the current node is `None`, we simply return 0 because it cannot contribute to any path sum.
        
    * We then make recursive calls for both the left and right children of the current node.
        
    * **Left and Right Gain**: We use `max(dfs(node.left), 0)` to ignore any negative contributions from the left or right subtree, thus ensuring that only positive contributions are counted.
        
3. **Calculating New Path**: At each node, we calculate the potential new path sum (`price_newpath`) by summing the value of the current node with the contributions from both left and right subtrees.
    
4. **Update Maximum Sum**: We then update the `max_sum` variable to store the highest value encountered during our traversal.
    
5. **Recursion**: The function returns the maximum gain achieved by extending either to the left or right child, helping the parent node in further calculations.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n)**, where n is the number of nodes in the binary tree. Each node is visited exactly once, and the operations performed at each node are O(1).
    
* **Space Complexity**: The space complexity is **O(h)**, where h is the height of the tree. This is due to the recursive call stack, which can reach up to the height of the tree. In the worst case of a skewed tree, the height could be equal to the number of nodes, leading to O(n) space complexity. However, for a balanced tree, the space complexity would be O(log n).
    

The efficient solution presented here ensures that the traversal of the tree is optimal, and the algorithm effectively tracks the maximum path sum using a DFS approach with dynamic updates to the global `max_sum`.

## Conclusion

The "Binary Tree Maximum Path Sum" problem is an excellent example of how recursion and depth-first search can be used to solve complex tree traversal problems efficiently. By focusing on both local and global maximum sums during the traversal, the solution ensures that every potential path is considered. The approach discussed here avoids recalculations and minimizes time complexity, making it ideal for large binary trees. Understanding this solution helps build a strong foundation for solving other tree-related algorithmic challenges effectively.


README for [Binary Tree Maximum Path Sum (Leetcode #124)](https://blog.unwiredlearning.com/binary-tree-maximum-path-sum) was compiled from the Unwired Learning Blog.  
//### 032 File: 0125-valid-palindrome/README.md
# Valid Palindrome (Leetcode #125)

In this blog, we will explore how to solve the Leetcode problem '125. Valid Palindrome.' We will start by understanding the problem statement, move through a common brute force approach, provide a hint to guide you towards the efficient solution, and then dive into the efficient solution in detail.

## Understanding the Problem Statement

The problem requires determining if a given string is a **valid palindrome**. A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward, ignoring spaces, punctuation, and case.

Given a string `s`, the goal is to check if it is a valid palindrome. To do this, we need to ignore non-alphanumeric characters and consider only letters and numbers. Additionally, letter case should be ignored, meaning `A` should be treated the same as `a`.

For example:

* **Input**: `s = "A man, a plan, a canal: Panama"`
    
* **Output**: `true`
    
* **Input**: `s = "race a car"`
    
* **Output**: `false`
    

## Brute Force Approach

A brute force approach to solve this problem would be as follows:

1. **Filter the String**: Iterate through the string, and add only alphanumeric characters to a new list or string while converting them to lowercase.
    
2. **Check for Palindrome**: Use two pointers, one at the start and one at the end of the new string or list, and check if characters at both ends are equal. If any mismatch is found, return `false`. If the entire iteration completes without finding a mismatch, return `true`.
    

This approach, while easy to understand, is inefficient due to the overhead involved in creating a new string or list with only alphanumeric characters, especially if the given string is very large. Additionally, iterating through the filtered list twice—once for filtering and once for checking—can be time-consuming.

## Hint to Solve the Problem Efficiently

To solve the problem more efficiently, you can use a **two-pointer approach** directly on the original string without creating a separate list of filtered characters. Instead, use two pointers to traverse the string from both ends, skipping non-alphanumeric characters in place. This approach allows you to save time and space.

Think about how you can move the two pointers inward while checking for character equality and skipping irrelevant characters (such as punctuation and spaces).

## Efficient Solution

Let's dive into the efficient solution, based on the provided code:

```python
import re

def isPalindrome(s):
    # Step 1: Initialize two pointers
    left, right = 0, len(s) - 1

    # Step 2: Traverse the string from both ends
    while left < right:
        # Skip non-alphanumeric characters on the left
        while left < right and not s[left].isalnum():
            left += 1
        # Skip non-alphanumeric characters on the right
        while left < right and not s[right].isalnum():
            right -= 1
        
        # Compare characters
        if s[left].lower() != s[right].lower():
            return False
        
        # Move both pointers inward
        left += 1
        right -= 1
    
    return True
```

**Step-by-Step Explanation**:

1. **Initialize Two Pointers**: Set up two pointers, `left` and `right`, to start from the beginning and end of the string, respectively. This allows you to compare characters from both ends.
    
    ```python
    left, right = 0, len(s) - 1
    ```
    
2. **Skip Non-Alphanumeric Characters**: As you traverse the string, skip any character that is not alphanumeric. This is done using a while loop for both `left` and `right` pointers. This ensures that only letters and numbers are considered.
    
    ```python
    while left < right and not s[left].isalnum():
        left += 1
    while left < right and not s[right].isalnum():
        right -= 1
    ```
    
3. **Compare Characters**: Convert both characters to lowercase and compare them. If a mismatch is found, return `False`. Otherwise, continue moving both pointers inward.
    
    ```python
    if s[left].lower() != s[right].lower():
        return False
    
    left += 1
    right -= 1
    ```
    
4. **Return True**: If the pointers have successfully crossed each other without finding a mismatch, the string is a valid palindrome, and `True` is returned.
    
    ```python
    return True
    ```
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(n)`, where `n` is the length of the string. This is because each character in the string is processed at most once, and the two-pointer approach ensures that we traverse the string in a single pass.
    
* **Space Complexity**: The space complexity is `O(1)`, since we are using only a constant amount of extra space (the two pointers). Unlike the brute force approach, we are not creating an additional string or list to store the filtered characters.
    

## Conclusion

The efficient solution to determine if a given string is a valid palindrome uses a two-pointer approach to traverse the string from both ends, skipping irrelevant characters, and comparing the alphanumeric characters directly. This approach is optimal in terms of both time and space, making it ideal for large input strings where efficiency is crucial.


README for [Valid Palindrome (Leetcode #125)](https://blog.unwiredlearning.com/valid-palindrome) was compiled from the Unwired Learning Blog.  
//### 033 File: 0128-longest-consecutive-sequence/README.md
# Longest Consecutive Sequence (Leetcode #128)

In this blog, we'll walk through how to solve Leetcode's **128\. Longest Consecutive Sequence** problem. We will begin by explaining the problem, examining a common brute-force approach, providing hints for optimization, and finally delving into an efficient solution. By the end, you should understand the different strategies to solve this problem and why the efficient approach is preferred.

## Understanding the Problem Statement

**Problem Statement:** Given an unsorted array of integers, find the length of the longest consecutive elements sequence. Your solution must run in **O(n)** time complexity.

**Example:**

Input: `nums = [100, 4, 200, 1, 3, 2]`  
Output: `4`  
Explanation: The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore, its length is `4`.

The challenge here lies in efficiently finding the longest sequence of consecutive numbers. The numbers can appear in any order, and the sequence doesn't necessarily need to be contiguous in the input array.

## Brute Force Approach

The brute-force approach to solve this problem is straightforward:

1. Iterate through each element of the array.
    
2. For each element, try to determine the length of the consecutive sequence starting from that element.
    
3. Use a nested loop to find if the next consecutive number exists in the array.
    

This approach involves repeatedly scanning the array to check for consecutive elements, leading to a time complexity of **O(n²)**. Given the problem's requirement for **O(n)** time complexity, this brute-force solution is not efficient enough for larger inputs.

## Hint to Solve the Problem Efficiently

To solve this problem in **O(n)** time, we need to avoid repeatedly scanning the array. Think about utilizing a data structure that allows for **O(1)** lookup times. Specifically, a **set** can be a very helpful tool here.

The idea is to store all elements in a set and then iterate through the array while trying to build the longest sequence possible, but only under certain conditions. This avoids redundant work and helps achieve linear time complexity.

## Efficient Solution

Below is an efficient solution to the problem, which leverages a **set** to achieve the desired **O(n)** complexity.

```
# Efficient Solution for Longest Consecutive Sequence
def longestConsecutive(nums):
    if not nums:
        return 0
    
    num_set = set(nums)  # Create a set of numbers for O(1) lookups
    longest_streak = 0
    
    for num in num_set:
        # Check if 'num' is the start of a sequence
        if num - 1 not in num_set:
            current_num = num
            current_streak = 1
            
            # Increment the sequence
            while current_num + 1 in num_set:
                current_num += 1
                current_streak += 1
            
            # Update the longest streak found so far
            longest_streak = max(longest_streak, current_streak)
    
    return longest_streak
```

## **Explanation of the Code**

1. **Create a Set:** First, we convert the list into a set (`num_set`) to enable **O(1)** lookups.
    
2. **Iterate Through the Set:** For each number in the set, check if it is the start of a sequence by verifying that `(num - 1)` is not in the set. This ensures that we only start counting when we have found the beginning of a sequence.
    
3. **Build the Sequence:** Once we identify a sequence's starting point, we use a `while` loop to determine how long the sequence extends by checking if `(current_num + 1)` is in the set.
    
4. **Update Longest Streak:** After finding the length of the current sequence, we update the `longest_streak` if the current sequence is longer.
    

## Time and Space Complexity

**Time Complexity:** The time complexity of this solution is **O(n)**. Creating the set takes **O(n)** time, and iterating through the set also takes **O(n)** time. Each lookup in the set is **O(1)**, and each number is processed at most twice (once for identifying the start of a sequence and once during sequence building).

**Space Complexity:** The space complexity is **O(n)**, as we need extra space to store the elements in a set. This is necessary to achieve the efficient **O(1)** lookups.

## Conclusion

In this blog, we covered how to solve the **Longest Consecutive Sequence** problem using both brute-force and optimized approaches. The brute-force method is inefficient for large datasets, while the efficient solution leverages a set to achieve **O(n)** time complexity. Understanding when and how to use sets for quick lookups is key to optimizing problems involving sequences or unique elements.

We hope this helps you solve similar problems more effectively! Feel free to try implementing the solution and see how it performs on various test cases.


README for [Longest Consecutive Sequence (Leetcode #128)](https://blog.unwiredlearning.com/longest-consecutive-sequence) was compiled from the Unwired Learning Blog.  
//### 034 File: 0133-clone-graph/README.md
# Clone Graph (Leetcode #133)

The Clone Graph problem is a popular graph-related question often asked in technical interviews and coding assessments. It tests your understanding of graph traversal techniques and your ability to create independent copies of complex data structures. In this blog, we'll delve into the problem, explore a brute force approach, and then provide an efficient solution to help you understand how to tackle this challenge effectively.

## Understanding the Problem Statement

The problem presented in LeetCode 133, **Clone Graph**, is about copying an entire graph. Given a reference to a node in an undirected graph, the task is to return a deep copy of the graph. Each node has a value and a list of neighbors. The graph might be disconnected, and there could be cycles, which means a node can be its own neighbor or part of a cycle.

In simple terms, you are provided with a node that represents a complex network, and your job is to create an identical network but as an independent copy. The challenge comes from preserving the relationships between nodes while ensuring none of the original references are reused.

## Brute Force Approach

The brute force approach to solving this problem involves **DFS (Depth First Search)** or **BFS (Breadth First Search)** with naive copying. You could start by visiting each node and copying its value. But, as nodes have references to other nodes, the naive approach would end up in an endless cycle if there are loops, or cause incorrect connections in the case of shared neighbors. This naive implementation lacks the mechanism to keep track of nodes that have already been cloned, causing inefficiencies and logical issues.

## Hint to Solve the Problem Efficiently

A successful approach involves using a **HashMap** (or dictionary) to keep track of already cloned nodes. This way, you can ensure that nodes are only cloned once, and all relationships are maintained. Think of it as a mapping of nodes in the original graph to their corresponding clones in the new graph.

## Efficient Solution

Below is an efficient solution based on **Breadth First Search (BFS)**:

The given solution uses a dictionary called `cloned_nodes` to map each original node to its corresponding cloned node. It begins by checking if the provided node is `None`, in which case, it returns `None` (as there is nothing to clone). The algorithm proceeds as follows:

1. **Initialization**: A dictionary called `cloned_nodes` is created to store the mapping of original nodes to their clones. The input node is cloned first, and both the original node and its clone are placed in the dictionary.
    
2. **Queue Setup**: A queue is initialized with the original node to help with the BFS traversal.
    
3. **BFS Traversal**: During traversal, for every node in the queue, its neighbors are iterated over.
    
    * If a neighbor is not yet cloned, it is cloned and added to the `cloned_nodes` dictionary and the queue for future exploration.
        
    * The neighbor is added to the neighbors list of the cloned version of the current node.
        
4. **Returning the Result**: Finally, the clone of the starting node is returned, which contains references to all other cloned nodes, thus representing the complete deep copy of the original graph.
    

Here is the efficient solution code for reference:

```python
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
    
        # Mapping from original to cloned node
        cloned_nodes = {}
        
        # Initialize the "queue" with the first node
        queue = [node]
        
        # Clone the first node and add it to the cloned nodes map
        cloned_nodes[node] = Node(node.val)
        
        # BFS traversal
        while queue:
            current_node = queue.pop(0)
            
            for neighbor in current_node.neighbors:
                if neighbor not in cloned_nodes:
                    # Clone and store the neighbor if it's not yet cloned
                    cloned_nodes[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                
                # Add the clone of the neighbor to the current node's clone neighbors list
                cloned_nodes[current_node].neighbors.append(cloned_nodes[neighbor])
        
        return cloned_nodes[node]
```

## Time and Space Complexity

The **Time Complexity** of the above solution is **O(N + M)**, where **N** is the number of nodes and **M** is the number of edges. This is because each node and edge is processed exactly once during the BFS traversal.

The **Space Complexity** is also **O(N)**, as we need extra space for storing cloned nodes in the dictionary and for maintaining the queue during BFS. The number of cloned nodes is proportional to the number of original nodes, and the queue holds references to nodes that need to be processed.

Using BFS and the hashmap-based tracking ensures we efficiently maintain relationships while avoiding repeated cloning, which makes this solution robust and performant for any graph structure, whether it has cycles, disconnected parts, or complex neighbor relationships.

## Conclusion

The Clone Graph problem is an excellent way to practice graph traversal techniques and understand how to handle complex data structures involving references. By using a BFS approach combined with a HashMap to keep track of cloned nodes, we can efficiently create a deep copy of any undirected graph. This solution ensures that all relationships are preserved while avoiding unnecessary re-cloning, making it suitable for even complex and cyclic graphs. Practicing problems like this will help you build a strong foundation in graph algorithms and data structure manipulation, which are critical skills for technical interviews and real-world software development.


README for [Clone Graph (Leetcode #133)](https://blog.unwiredlearning.com/clone-graph) was compiled from the Unwired Learning Blog.  
//### 035 File: 0139-word-break/README.md
# Word Break (Leetcode #139)

The Word Break problem is a classic challenge in dynamic programming and string manipulation that comes up frequently during technical interviews. It tests your ability to segment strings effectively using a given set of words. In this blog, we will dive into solving the Word Break problem, covering a brute force approach, an efficient solution, and analyzing their respective complexities.

## Understanding the Problem Statement

The Word Break problem asks if a given string (`s`) can be segmented into space-separated sequences of one or more dictionary words. Given an input string and a dictionary of words, the goal is to determine if the entire string can be split such that every segment is present in the dictionary.

For example:

* **Input:**
    
    * `s = "leetcode"`
        
    * `wordDict = ["leet", "code"]`
        
* **Output:** `true`
    
* **Explanation:** `"leetcode"` can be segmented as `"leet code"` which are both words present in the dictionary.
    

The problem requires checking all possible segmentations of the string, making it an interesting problem for exploring both brute force and optimized techniques.

## Brute Force Approach

A common approach to solve this problem is through **recursion**. In the brute force solution, we attempt to partition the string in all possible ways and check if each substring exists in the dictionary. Here is a high-level overview of how a brute force solution would work:

1. Start with the first character of the string.
    
2. Incrementally form substrings and check if each substring exists in the given word dictionary.
    
3. Recur for the remaining part of the string if a valid segment is found.
    

This approach is straightforward but highly inefficient due to repeated calculations and overlapping subproblems. As the length of the string increases, the time complexity becomes exponential, which is impractical for large inputs.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, we can use **dynamic programming** to avoid redundant computations. The hint is to use a boolean array where each element represents whether the substring up to that index can be segmented using words from the dictionary.

## Efficient Solution

Below is an efficient solution based on the provided code, which uses dynamic programming to solve the Word Break problem:

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)
        res = [False] * (len(s) + 1)
        res[0] = True
        
        # Iterate through all positions in the string
        for i in range(len(s) + 1):
            # Check all words in the wordSet
            for word in wordSet:
                if (res[i] and (i + len(word)) <= len(s) and s[i : i + len(word)] in wordSet):
                    res[i + len(word)] = True
        
        return res[-1]
```

**Explanation:**

* The solution uses a dynamic programming array (`res`) of length `len(s) + 1`, where `res[i]` is `True` if the substring `s[:i]` can be segmented using the words in the dictionary.
    
* We initialize `res[0]` to `True` because an empty string can always be segmented.
    
* We iterate through the string, and for each position, we check all words in the dictionary to see if the substring from the current position matches any word and can form a valid segment.
    
* If a match is found, we update the dynamic programming array to reflect that the substring can be segmented.
    
* The result is returned by checking `res[len(s)]`, which indicates if the entire string can be segmented.
    

## Time and Space Complexity

* **Time Complexity:** The time complexity is **O(n \* m)**, where `n` is the length of the string `s` and `m` is the total number of words in the dictionary. For each position in the string, we iterate over all words, and the substring check takes constant time on average due to the use of a hash set.
    
* **Space Complexity:** The space complexity is **O(n)**, where `n` is the length of the string `s`. We use a dynamic programming array of size `n + 1` to store results for each position in the string.
    

## Conclusion

The Word Break problem is a great example of how dynamic programming can be applied to improve efficiency over brute force approaches. By using a DP array and leveraging the set data structure for fast lookups, we can significantly reduce the time required to solve the problem. Understanding these approaches not only helps in solving similar problems in interviews but also strengthens core algorithmic concepts.

Feel free to try different test cases on your own and see how the optimized solution outperforms the naive one. Happy coding!

README for [Word Break (Leetcode #139)](https://blog.unwiredlearning.com/word-break) was compiled from the Unwired Learning Blog.  
//### 036 File: 0141-linked-list-cycle/README.md
# Linked List Cycle (Leetcode #141)

Linked lists are a fundamental data structure in computer science, often used for their dynamic memory allocation and ease of insertion and deletion. However, they come with their own set of challenges, one of which is cycle detection. In this blog, we will explore Leetcode Problem 141, **Linked List Cycle**, and discuss various approaches to solve it, including an efficient two-pointer technique.

## Understanding the Problem Statement

Leetcode Problem 141, titled **Linked List Cycle**, presents us with the task of determining whether a linked list has a cycle in it. A linked list is said to have a cycle if, at some point, a node’s `next` pointer leads back to a previously visited node, effectively creating an infinite loop.

The question provides us with the head of a singly linked list and asks if this linked list contains a cycle. If a cycle exists, we must return `true`; otherwise, return `false`.

## Brute Force Approach

One of the more intuitive ways to solve this problem is by using a **hash set**. The idea here is to traverse the linked list and store each node we visit in the hash set. If we encounter a node that we have already seen before, we know that a cycle exists. Otherwise, we continue until we reach the end of the list.

Here is a simple version of the brute force solution:

* Create an empty hash set.
    
* Traverse the linked list, storing each node in the hash set.
    
* If the node already exists in the hash set, return `true` (indicating a cycle).
    
* If the list ends, return `false` (indicating no cycle).
    

While the brute force solution works, it requires additional space proportional to the number of nodes in the linked list.

## Hint to Solve the Problem Efficiently

The provided solution uses a technique that avoids additional data structures to track nodes. Consider the idea of **using two pointers** with different speeds: one slow pointer and one fast pointer. Think about how these two pointers can help determine whether there is a cycle in the list.

## Efficient Solution

The optimal solution is known as the **Floyd's Cycle-Finding Algorithm** or the **Tortoise and Hare Algorithm**. The core idea is to use two pointers that traverse the linked list at different speeds.

Here is the efficient code solution:

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # Initialize the two pointers
        slow, fast = head, head
        
        # Traverse the list with the two pointers
        while fast is not None and fast.next is not None:
            slow = slow.next  # Move the slow pointer one step
            fast = fast.next.next  # Move the fast pointer two steps
            
            # If there's a cycle, the two pointers will meet
            if slow == fast:
                return True
        
        # If the fast pointer reaches the end, there's no cycle
        return False
```

In this solution, we initialize two pointers, `slow` and `fast`, both starting at the head of the linked list. The **slow pointer** moves one step at a time, while the **fast pointer** moves two steps at a time. If there is a cycle in the linked list, eventually, the fast pointer will catch up to the slow pointer. If the fast pointer reaches the end of the list (`None`), there is no cycle.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this approach is **O(n)**, where **n** is the number of nodes in the linked list. The reason is that both pointers will traverse at most the entire linked list, and in the case of a cycle, they will meet within two complete traversals of the cycle length.
    
* **Space Complexity**: The space complexity of this approach is **O(1)**, since we are not using any extra data structures to store nodes, only two pointers. This makes it significantly more space-efficient than the hash set approach.
    

## Conclusion

Leetcode 141 presents a classic problem involving linked lists and cycle detection. While a brute force approach using a hash set can solve the problem, the **Floyd's Cycle-Finding Algorithm** is a more elegant and space-efficient solution. By employing two pointers moving at different speeds, we can detect a cycle in **O(n)** time and **O(1)** space, making it an ideal choice for this problem. Understanding this algorithm helps in mastering linked list manipulations and developing efficient problem-solving skills for more advanced data structure challenges.


README for [Linked List Cycle (Leetcode #141)](https://blog.unwiredlearning.com/linked-list-cycle) was compiled from the Unwired Learning Blog.  
//### 037 File: 0142-linked-list-cycle-ii/README.md
# Linked List Cycle II (Leetcode #142)

Linked lists are fundamental data structures that are widely used in various computational problems. One of the interesting challenges involving linked lists is detecting if a cycle exists within the list, and if so, determining the starting point of that cycle. Leetcode's problem 142, Linked List Cycle II, is a classic problem that tests your understanding of linked lists and how to effectively solve problems related to cycles. In this blog, we will explore the problem, discuss a common brute-force approach, and then dive into an efficient solution using Floyd's Tortoise and Hare algorithm.

## Understanding the Problem Statement

Leetcode's 142. Linked List Cycle II is an interesting problem involving linked lists. The problem requires determining if a given linked list has a cycle, and if so, returning the starting node of the cycle. If no cycle exists, the function should return `None`.

To clarify, a linked list contains a cycle if some node in the list is reachable again by continuously following its next pointer. In other words, the linked list forms a loop.

**Example:**

Consider the linked list:

```python
3 -> 2 -> 0 -> -4
     ^         |
     |_________|
```

In this example, the linked list contains a cycle starting at node 2.

The task is to find and return the node at which the cycle begins.

## Brute Force Approach

A common brute-force approach to solving this problem involves using a data structure, such as a set, to keep track of all visited nodes. As you traverse through the linked list, you add each node to the set. If a node is revisited, it indicates the start of a cycle.

**Steps for Brute Force Approach:**

1. Initialize an empty set.
    
2. Traverse the linked list node by node.
    
3. For each node, check if it is already present in the set.
    
4. If found, return the current node as it is the start of the cycle.
    
5. If the traversal reaches the end without finding a cycle, return `None`.
    

While this method works, it requires `O(n)` space for storing visited nodes, making it inefficient for large linked lists.

## Hint to Solve the Problem Efficiently

The efficient solution relies on using two pointers, often referred to as the **slow** and **fast** pointers. The idea is that if there's a cycle, the slow and fast pointers will eventually meet. Once they meet, a specific technique allows us to find the exact node where the cycle begins.

To solve the problem efficiently, think of how you can leverage these two pointers to detect the cycle and then find its start without using extra space.

## Efficient Solution

The code provided implements the **Floyd's Tortoise and Hare Algorithm**, a popular cycle detection technique. Here is the breakdown of the solution:

```python
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = head
        fast = head

        # Advance both pointers at different speeds until they meet
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

            # If they meet, start from the head again and move at the same speed
            if slow == fast:
                while head != slow:
                    head = head.next
                    slow = slow.next
                return slow

        # If no cycle is detected, return None
        return None
```

**Explanation:**

1. **Initialization:** Start by initializing two pointers, `slow` and `fast`, both pointing to the head of the linked list.
    
2. **Cycle Detection:** Move the `slow` pointer one step at a time and the `fast` pointer two steps at a time. If there is a cycle, the `slow` and `fast` pointers will eventually meet.
    
3. **Finding the Start of the Cycle:** Once the pointers meet, reset one pointer to the head of the list. Move both pointers one step at a time until they meet again. The meeting point is the start of the cycle.
    
4. **Return Value:** If no cycle is found, return `None`.
    

## Time and Space Complexity

* **Time Complexity:** The time complexity of this solution is `O(n)`, where `n` is the number of nodes in the linked list. In the worst case, both pointers traverse the entire list.
    
* **Space Complexity:** The space complexity is `O(1)` since no extra space is used apart from the pointers.
    

This solution is optimal for the problem as it uses constant space and efficiently detects the cycle and its starting point.

## Conclusion

The efficient approach to solving Leetcode 142 relies on the Floyd's Tortoise and Hare algorithm. By using two pointers, we can detect the presence of a cycle and identify its starting node without extra memory overhead. This method is both time-efficient and space-efficient, making it a preferred solution for this problem.


README for [Linked List Cycle II (Leetcode #142)](https://blog.unwiredlearning.com/linked-list-cycle-ii) was compiled from the Unwired Learning Blog.  
//### 038 File: 0143-reorder-list/README.md
# Reorder List (Leetcode #143)

LeetCode's problem 143, **"Reorder List,"** is a challenging yet rewarding question. Here, I'll walk you through the problem, a common brute force solution, and then guide you to the efficient solution using the attached code, helping you understand how to reorder a linked list step by step.

## Understanding the Problem Statement

The task requires us to reorder a given singly linked list, defined as:

* Given the head of a singly linked list, modify it in such a way that the nodes are reordered from their original sequence in the pattern: first node, last node, second node, second last node, and so on.
    
* Specifically, given a list like `1 -> 2 -> 3 -> 4 -> 5`, the reordered list should be `1 -> 5 -> 2 -> 4 -> 3`.
    

The aim is to do this **in-place** without altering the node values or using extra memory in the form of a new list.

## Brute Force Approach

The brute force approach to solve this problem involves copying all the elements of the linked list to an array or a list, rearranging the values in the desired order, and then repopulating the original linked list. Though straightforward, this approach violates the in-place requirement of the problem and requires **O(n)** additional space.

* **Steps:** Traverse the linked list and store its nodes in an array. Then, using two pointers, reorder them into the specified pattern and rebuild the linked list accordingly.
    
* **Time Complexity:** This approach takes **O(n)** for the traversal and reordering but also uses **O(n)** space, which is not ideal.
    

## Hint to Solve the Problem Efficiently

Instead of storing nodes in a list, think of breaking down the list in two parts, reversing one half, and then merging them back. Imagine the process as finding the **middle point** of the list and strategically reordering.

## Efficient Solution

The attached code uses a three-step approach to solve the problem efficiently while ensuring we keep the space complexity at **O(1)**. Here is a breakdown:

1. **Find the Middle of the Linked List**
    
    We use two pointers, `slow` and `fast`, to find the middle node of the list. The `fast` pointer moves twice as fast as the `slow` pointer, meaning by the time `fast` reaches the end of the list, `slow` will be at the middle. This gives us the split point to divide the list into two halves.
    
    ```python
    slow, fast = head, head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    ```
    
2. **Reverse the Second Half of the List**
    
    The next step involves reversing the second half of the list, starting from the node `slow`. We use three pointers: `previous`, `current`, and `next_temp` to reverse the nodes iteratively until we reach the end of the list.
    
    ```python
    previous, current = None, slow
    while current:
        next_temp = current.next
        current.next = previous
        previous = current
        current = next_temp
    ```
    
    At the end of this step, `previous` will point to the new head of the reversed second half.
    
3. **Merge the Two Halves**
    
    Finally, we merge the two halves together. We use two pointers, `first` and `second`, representing the first and second halves respectively. We alternate linking nodes from each half, ensuring the new reordered structure is achieved.
    
    ```python
    first, second = head, previous
    while second.next:
        temp1, temp2 = first.next, second.next
        first.next = second
        second.next = temp1
        first, second = temp1, temp2
    ```
    

## Time and Space Complexity

* **Time Complexity:** The solution takes **O(n)** time since each of the three main steps (finding the middle, reversing the second half, and merging) involves a linear traversal of the linked list.
    
* **Space Complexity:** The solution operates with **O(1)** additional space, making it an in-place solution that satisfies the problem's constraints.
    

## Conclusion

The problem requires us to reorder a singly linked list in a particular pattern, and while a brute force approach may seem feasible, the efficient method involves using pointer manipulation to achieve an in-place solution. By dividing, reversing, and merging the list, we achieve the desired outcome effectively with a linear time complexity and constant space complexity.


README for [Reorder List (Leetcode #143)](https://blog.unwiredlearning.com/reorder-list) was compiled from the Unwired Learning Blog.  
//### 039 File: 0152-maximum-product-subarray/README.md
# Maximum Product Subarray (Leetcode #152)

Finding the maximum product subarray in an array of integers is a classic coding problem that helps in understanding the nuances of dynamic programming and array traversal. In this blog, we'll break down the problem, discuss a brute force solution, and provide an efficient approach to solving the "Maximum Product Subarray" problem, as seen on LeetCode. By the end, you'll have a clear understanding of how to efficiently solve this problem using a given Python code.

## Understanding the Problem Statement

The problem statement for "Maximum Product Subarray" (LeetCode #152) asks us to determine the contiguous subarray (containing at least one number) within a given array `nums` that has the largest product. The array can contain both positive and negative numbers, and may include zeros. This variability adds complexity, since multiplying by a negative number can make a large positive number negative, and multiplying by zero resets the product to zero.

To put it simply, you need to identify a section of the array whose product is the maximum possible value compared to all other subarrays.

## Brute Force Approach

A common brute force solution to solve this problem is to iterate through every possible subarray, compute their product, and then track the maximum product found. Here's a general idea:

1. Iterate through each element in the array as the starting point.
    
2. For each starting point, iterate through subsequent elements to form subarrays.
    
3. Calculate the product of elements in each subarray and update the maximum product if the current product is greater.
    

This approach is easy to understand but has a high time complexity of O(n²), making it inefficient for larger inputs due to nested loops.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, it's essential to consider that the product of negative numbers can lead to a larger positive product if managed carefully. Maintaining both a minimum and a maximum product at each step helps handle negative numbers and zeros effectively. You should track both the prefix and suffix products, as these can help ensure that we don't miss any potential maximum product, even when encountering zeros.

## Efficient Solution

Below, we explain the efficient solution using the provided Python code. This solution involves iterating through the array while maintaining prefix and suffix products, ensuring that the result is updated with the maximum product encountered. Here's the code:

```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        left_product, right_product = 1, 1
        result = nums[0]

        for i in range(n):
            # if any of left or right product become 0, update it to 1
            if left_product == 0:
                left_product = 1
            if right_product == 0:
                right_product = 1

            # prefix product
            left_product *= nums[i]

            # suffix product
            right_product *= nums[n - 1 - i]

            result = max(result, max(left_product, right_product))

        return result
```

**Explanation**:

1. **Initialization**: We initialize `left_product` and `right_product` to 1, and `result` to the first element of the array.
    
2. **Loop Through Array**: We iterate through the array from both ends simultaneously:
    
    * The prefix product (`left_product`) multiplies elements from left to right.
        
    * The suffix product (`right_product`) multiplies elements from right to left.
        
3. **Handling Zeros**: Whenever a product becomes zero, it's reset to 1 to avoid the propagation of zeros, which could nullify subsequent products.
    
4. **Update Result**: The `result` is updated at each step to keep track of the maximum product found so far.
    
5. **Return Result**: After the loop completes, the maximum product is returned.
    

This solution efficiently computes the result in a single pass through the array, leveraging prefix and suffix calculations to capture the maximum product subarray.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is O(n), where `n` is the length of the array. This is because we only iterate through the array once, making it significantly faster than the brute force approach.
    
* **Space Complexity**: The space complexity is O(1), as we only use a few extra variables (`left_product`, `right_product`, and `result`) regardless of the input size.
    

## Conclusion

The "Maximum Product Subarray" problem is an excellent example of how managing multiple state variables (like prefix and suffix products) can help solve a problem efficiently, even in the presence of negative numbers and zeros. While the brute force approach provides a simple solution, the efficient solution we discussed is much more suitable for larger inputs due to its linear time complexity. Understanding and implementing such efficient techniques is crucial for tackling array-related problems in competitive programming and technical interviews.

README for [Maximum Product Subarray (Leetcode #152)](https://blog.unwiredlearning.com/maximum-product-subarray) was compiled from the Unwired Learning Blog.  
//### 040 File: 0153-find-minimum-in-rotated-sorted-array/README.md
# Find Minimum in Rotated Sorted Array (Leetcode #153)

In this blog, we will explore how to solve the problem of finding the minimum element in a rotated sorted array. This is a common interview question that tests your understanding of array manipulations and efficient search algorithms. We will start by explaining the problem, then discuss a brute force approach, provide a hint for an efficient solution, and finally present the optimal approach using binary search.

## Understanding the Problem Statement

The given problem is to find the minimum element in a rotated sorted array. Imagine a sorted array that has been rotated, meaning that some of its elements from the beginning have been moved to the end, without changing their order. For instance, a sorted array like `[1, 2, 3, 4, 5]` could be rotated to become `[4, 5, 1, 2, 3]`. Your goal is to find the minimum element in such an array, and the task must be solved in an efficient manner.

## Brute Force Approach

A simple approach to solve this problem is to iterate through the entire array, comparing each element to find the minimum value. You could start from the first element and keep updating a variable that holds the minimum value as you progress through the array. This approach would look something like this:

1. Initialize `min_val` to the first element of the array.
    
2. Iterate through the array.
    
3. Update `min_val` if the current element is smaller.
    
4. Return `min_val` at the end.
    

While this approach works, it has a time complexity of O(n), where `n` is the length of the array, and it does not utilize the sorted property of the array, which limits its efficiency.

## Hint to Solve the Problem Efficiently

The problem gives a sorted, rotated array, which suggests that it might be more efficient to solve it by leveraging binary search. The key observation here is that in a rotated sorted array, there is always a point where the order is broken, and that is where the smallest element lies. The hint is to use a divide-and-conquer strategy to take advantage of the sorted nature of the array.

## Efficient Solution

To solve this problem efficiently, we can use a binary search approach. The goal is to reduce the problem size in each iteration, eventually zeroing in on the minimum value. Let’s look at the solution provided:

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            # If the middle element is greater than the rightmost element,
            # it indicates that the smallest element is in the right half.
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        # At the end of the loop, left will be pointing at the smallest element.
        return nums[left]
```

**Explanation of the Code**

1. **Initial Setup**: We start by defining two pointers, `left` and `right`, which initially point to the first and last elements of the array.
    
2. **Binary Search Loop**: While `left` is less than `right`, we calculate the midpoint, `mid`.
    
3. **Update Pointers**: The crucial check here is comparing `nums[mid]` to `nums[right]`:
    
    * If `nums[mid]` is greater than `nums[right]`, it means the smallest value must be to the right of `mid`, so we set `left = mid + 1`.
        
    * Otherwise, the smallest value is to the left or could be `mid` itself, so we adjust `right = mid`.
        
4. **Final Result**: When `left` meets `right`, they both point to the smallest element, which is returned.
    

This binary search-based approach has a time complexity of O(log n) because the array is divided into halves in each iteration, and the space complexity is O(1), as no additional space is used.

## Time and Space Complexity

* **Time Complexity**: The solution has a time complexity of O(log n). This is because the binary search reduces the problem size by half in each iteration, making it very efficient for large arrays.
    
* **Space Complexity**: The space complexity is O(1), as no additional data structures are used, and all operations are done in constant space.
    

This efficient approach is ideal for solving the problem quickly, especially when working with large datasets.

## Conclusion

In this blog, we discussed how to find the minimum element in a rotated sorted array. We began with a brute force solution and then moved on to an efficient solution using binary search, which significantly reduces the time complexity from O(n) to O(log n). This approach is not only faster but also uses constant space, making it highly suitable for large arrays. Understanding this problem helps improve your skills in array manipulation and binary search, which are key components in many technical interviews.


README for [Find Minimum in Rotated Sorted Array (Leetcode #153)](https://blog.unwiredlearning.com/find-minimum-in-rotated-sorted-array) was compiled from the Unwired Learning Blog.  
//### 041 File: 0167-two-sum-ii-input-array-is-sorted/README.md
# Two Sum II - Input Array Is Sorted (Leetcode #167)

The 'Two Sum II - Input Array Is Sorted' problem from LeetCode is an interesting challenge that tests your ability to efficiently solve a problem using pointers. Let's explore the problem, common brute-force methods, and then dive into the efficient solution with the provided code.

## Understanding the Problem Statement

The problem provides you with a sorted array of integers and a target value. Your goal is to find two numbers from this sorted array such that they add up to the given target. You must return the indices of the two numbers, and the solution should use **1-indexed** positions. Importantly, you are guaranteed that there is exactly one solution, and you cannot use the same element twice.

For instance, given the sorted array `[2, 7, 11, 15]` and target `9`, the numbers `2` and `7` add up to `9`. The answer should be `[1, 2]`.

## Brute Force Approach

A naive way to solve this problem is to use a nested loop to iterate over all possible pairs in the array and find the indices whose elements add up to the target. This brute-force approach looks something like this:

```python
for i in range(len(numbers)):
    for j in range(i + 1, len(numbers)):
        if numbers[i] + numbers[j] == target:
            return [i + 1, j + 1]
```

While this solution is easy to implement, it has a **time complexity of O(n^2)**, which is inefficient for larger input arrays. The double loop makes it computationally expensive.

## Hint to Solve the Problem Efficiently

Because the input array is **sorted**, you can use a more efficient approach by taking advantage of the sorted order. The problem can be solved using two pointers, one starting from the left and one from the right of the array. By moving these pointers intelligently, you can efficiently find the required indices.

## Efficient Solution

The provided code uses the two-pointer technique, which allows us to solve the problem in **O(n)** time complexity. Here's the code:

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Initialize two pointers: left at the start, right at the end.
        left, right = 0, len(numbers) - 1

        while left < right:
            current_sum = numbers[left] + numbers[right]

            # Return the 1-indexed positions if the target sum is found.
            if current_sum == target:
                return [left + 1, right + 1]  
            
            # Move the left pointer to the right if the sum is less than the target.
            elif current_sum < target:
                left += 1
            
            # Move the right pointer to the left if the sum is greater than the target.
            elif current_sum > target:
                right -= 1

        return []
```

In this solution:

* **Left and Right Pointers**: The `left` pointer starts at the beginning of the array, and the `right` pointer starts at the end.
    
* **Sum Evaluation**: At each iteration, you calculate the `current_sum` of the elements at the `left` and `right` pointers.
    
    * If `current_sum` equals the target, you've found the answer and return the indices (`left + 1` and `right + 1` to convert to 1-indexed positions).
        
    * If `current_sum` is less than the target, you increment the `left` pointer to increase the sum.
        
    * If `current_sum` is greater than the target, you decrement the `right` pointer to decrease the sum.
        

This approach ensures that each element is visited at most once, resulting in a **time complexity of O(n)**, which is a significant improvement over the brute-force method.

## Time and Space Complexity

* **Time Complexity**: The two-pointer approach has a time complexity of **O(n)** because both pointers traverse the list from opposite ends and meet in the middle. This is much faster compared to the **O(n^2)** complexity of the brute-force solution.
    
* **Space Complexity**: The solution has a **space complexity of O(1)** since we are only using a fixed amount of additional space for the pointers, making this solution both time and space efficient.
    

## Conclusion

The 'Two Sum II - Input Array Is Sorted' problem can be solved with either a brute-force approach or the more efficient two-pointer technique. Using the two-pointer method takes full advantage of the sorted input array and leads to an optimal solution in terms of time and space complexity.


README for [Two Sum II - Input Array Is Sorted (Leetcode #167)](https://blog.unwiredlearning.com/two-sum-ii-input-array-is-sorted) was compiled from the Unwired Learning Blog.  
//### 042 File: 0190-reverse-bits/README.md
# Reverse Bits (Leetcode #190)

Leetcode's "Counting Bits" problem is a fascinating challenge that tests our understanding of binary numbers and efficient problem-solving. In this blog, we will walk through the problem, explore a common brute-force approach, and then provide you with a hint to solve it efficiently. We'll conclude by explaining an optimal solution step-by-step and analyzing its time and space complexity.

## Understanding the Problem Statement

In the "Counting Bits" problem (Leetcode 338), we are given a non-negative integer `n`, and the task is to return an array `ans` of length `n + 1`, where `ans[i]` is the number of `1` bits in the binary representation of the number `i`. Essentially, you need to count the number of `1`s (also known as set bits) for each number from `0` to `n` and return all those counts in an array.

For example:

* **Input**: `n = 5`
    
* **Output**: `[0, 1, 1, 2, 1, 2]`
    
* **Explanation**: The binary representations are `0 -> 0`, `1 -> 1`, `2 -> 10`, `3 -> 11`, `4 -> 100`, `5 -> 101`. Hence, the counts of set bits are `0, 1, 1, 2, 1, 2` respectively.
    

## Brute Force Approach

A straightforward way to solve this problem is to iterate through each number from `0` to `n` and count the number of `1`s in its binary representation. This can be done by repeatedly shifting the bits of each number and counting how many bits are set. Here is a brief explanation of the brute-force approach:

1. Create an empty list to store the counts.
    
2. Loop through each number from `0` to `n`.
    
3. For each number, use bitwise operations to count the `1` bits.
    
4. Append the count to the result list.
    

However, the brute force approach is not efficient for larger values of `n`, as it requires a significant amount of computation for each number, leading to a higher time complexity.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, we can leverage the properties of binary representation. Notice that if `i` is even, its set bits are equal to the set bits of `i // 2`. If `i` is odd, its set bits are one more than the set bits of `i // 2`. This observation allows us to compute the number of set bits in constant time for each number based on the previously computed values.

## Efficient Solution

The provided code takes advantage of the above observation to efficiently solve the problem. Here is the code and an explanation of how it works:

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        # Initialize a list to store the result
        result = [0] * (n + 1)
        
        # If n is 0, simply return the result list (which is [0])
        if n == 0:
            return result
        
        # The number of 1's in the binary representation of 1 is 1
        result[1] = 1
        
        # Loop through numbers from 2 to n
        for i in range(2, n + 1):
            if i % 2 == 0:
                result[i] = result[i // 2]
            else:
                result[i] = result[i // 2] + 1
        
        return result
```

**Explanation**:

1. **Initialization**: We initialize a list `result` of size `n + 1` with all values set to `0`.
    
2. **Base Cases**: If `n` is `0`, we directly return `[0]`. We also set `result[1] = 1` since `1` has one set bit.
    
3. **Loop through** `2` **to** `n`: For each number `i`, we determine the number of set bits based on whether `i` is even or odd:
    
    * If `i` is even, `result[i] = result[i // 2]`.
        
    * If `i` is odd, `result[i] = result[i // 2] + 1`.
        

This approach is efficient because it calculates each value in constant time using previously computed values, resulting in an optimal solution.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(n)` since we iterate through all numbers from `0` to `n`, and each computation takes constant time.
    
* **Space Complexity**: The space complexity is `O(n)` due to the additional space needed to store the result array of size `n + 1`.
    

## Conclusion

The "Counting Bits" problem is a great way to understand the efficiency of dynamic programming and the power of using previously computed results to optimize the solution. By recognizing patterns in the binary representation of numbers, we are able to achieve an efficient `O(n)` solution instead of the costly brute-force approach. This problem also emphasizes the importance of recognizing subproblems and utilizing existing results for more efficient computation.

README for [Reverse Bits (Leetcode #190)](https://blog.unwiredlearning.com/reverse-bits) was compiled from the Unwired Learning Blog.  
//### 043 File: 0191-number-of-1-bits/README.md
# Number of 1 Bits (Leetcode #191)

Finding the number of 1 bits in a binary representation of a number is a common problem in computer science. In this blog, we'll take you through the solution to the problem "Number of 1 Bits," also known as calculating the Hamming Weight. We'll discuss a brute-force approach, provide hints to tackle the problem efficiently, and ultimately dive into the provided optimized code. Let's begin!

## Understanding the Problem Statement

The problem is simple: You are given an unsigned integer, and you need to determine how many '1' bits are present in its binary representation. This is also called finding the Hamming Weight of the number.

For example:

* Input: `n = 11` (binary representation: `00000000000000000000000000001011`)
    
* Output: `3`
    

The output is `3` because the binary representation of `11` contains three '1' bits.

## Brute Force Approach

A brute-force way to solve this problem involves converting the integer to its binary string representation and then counting the '1' characters in that string.

Here's a simple implementation of the brute-force solution:

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
```

In this approach, we convert `n` to a binary string using `bin(n)` and then simply count the number of '1' bits. While this method is easy to understand, it is not the most efficient in terms of bitwise operations.

## Hint to Solve the Problem Efficiently

To solve the problem more efficiently, consider using bitwise operations. Remember that we can use bit manipulation to check each bit of the number directly, without converting it to a string.

The provided code follows an efficient approach using bitwise operations to minimize unnecessary computations and keep the solution within constant time.

## Efficient Solution

The code provided takes a bitwise approach by iterating through each bit of a 32-bit integer. Here is the provided solution:

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0

        # Assuming a 32-bit integer
        for _ in range(32):  
            # Check the LSB
            count = count + (n & 1)

            # Right shift the bits of n
            n = n >> 1                

        return count
```

**Explanation**:

1. **Initialize** `count`: We start by initializing a variable `count` to `0`. This will be used to store the number of '1' bits.
    
2. **Iterate through 32 Bits**: Since we are assuming a 32-bit integer, we loop 32 times.
    
3. **Check the Least Significant Bit (LSB)**: In each iteration, we use the bitwise AND operation (`n & 1`) to check if the least significant bit is `1`. If it is, we increment `count`.
    
4. **Right Shift** `n`: After checking the LSB, we right-shift `n` by 1 (`n >> 1`) to process the next bit in the following iteration.
    
5. **Return the** `count`: After iterating through all 32 bits, we return the value of `count`.
    

This solution is both space-efficient and computationally efficient, as it directly manipulates the bits of the integer without needing additional storage or conversions.

## Time and Space Complexity Analysis

* **Time Complexity**: `O(1)` - The loop runs for a constant 32 iterations, regardless of the input value.
    
* **Space Complexity**: `O(1)` - No extra space is used apart from the variable `count`.
    

Thus, this solution operates in constant time and constant space, making it very efficient for this problem.

## Conclusion

The "Number of 1 Bits" problem provides a great opportunity to practice bitwise operations, which are a powerful tool in optimizing solutions for binary representation problems. While the brute-force method using string operations is easy to understand, the bitwise approach used in the provided solution is significantly more efficient and teaches us about bit manipulation techniques.

We hope this guide has helped you understand both a simple and an efficient way to solve this problem. Happy coding!

README for [Number of 1 Bits (Leetcode #191)](https://blog.unwiredlearning.com/number-of-1-bits) was compiled from the Unwired Learning Blog.  
//### 044 File: 0198-house-robber/README.md
# House Robber (Leetcode 198)

The House Robber problem is a classic example of a dynamic programming challenge that is commonly featured in coding interviews. It requires you to maximize your earnings from robbing houses while adhering to specific constraints that prevent robbing two adjacent houses. In this blog, we'll walk through a brute force solution, provide hints, and present an efficient dynamic programming approach to solve the problem.

## Understanding the Problem Statement

The **House Robber** problem is a popular interview question that helps assess one's ability to solve dynamic programming challenges. The problem is simple to describe: Given an array of non-negative integers representing the amount of money in each house, determine the maximum amount of money you can rob without robbing two adjacent houses.

To illustrate, imagine a neighborhood where each house has a specific amount of cash. If you rob any house, you cannot rob the adjacent house. The task is to determine how to maximize your earnings while following this constraint. For example:

Input: `nums = [2, 7, 9, 3, 1]`  
Output: `12`  
Explanation: Rob house 1 (cash = 2), skip house 2, rob house 3 (cash = 9), and rob house 5 (cash = 1). Total = 2 + 9 + 1 = 12.

## Brute Force Approach

The simplest way to solve this problem is using a **recursive approach**, trying to consider all possible combinations of robbing houses. For each house, you either rob it and move to the house after the next one or skip it and move to the next house. This approach involves checking every possible combination, leading to exponential time complexity. Here's a basic version of this approach:

* Define a recursive function that takes the current index of the house.
    
* For each house, you have two options: rob it or skip it.
    
* Calculate the maximum sum for each possibility and return the larger value.
    

While this approach is easy to understand, it is not efficient. Its time complexity is **O(2^n)**, as it branches out with each decision, leading to a lot of redundant calculations.

## Hint to Solve the Problem Efficiently

The provided code hints at using a **dynamic programming** approach to eliminate redundant calculations. The idea is to use a table to store the maximum amount that can be robbed up to each house, thus avoiding recalculating the same subproblems.

## Efficient Solution

The optimal solution for the **House Robber** problem involves using **dynamic programming** to track the maximum amount of money that can be robbed up to each house without alerting the police. Let’s walk through the solution provided in the code:

1. **Edge Cases**: If the list is empty, return `0`, since there are no houses to rob. If there is only one house, the answer is simply the value in that house.
    
2. **Dynamic Programming Table Setup**: Create a `dp` array where `dp[i]` represents the maximum amount of money that can be robbed up to house `i`.
    
    * Initialize `dp[0]` to `nums[0]` (the first house).
        
    * Initialize `dp[1]` to the maximum of `nums[0]` and `nums[1]`, as you can only rob one of the first two houses.
        
3. **Filling the DP Table**: Use a loop to fill in the `dp` table for all remaining houses:
    
    * For each house `i` from index `2` onward, decide whether to rob house `i` (and add it to `dp[i-2]`) or skip it and take the value of `dp[i-1]`.
        
    * `dp[i] = max(dp[i-2] + nums[i], dp[i-1])`
        
4. **Result**: Finally, the maximum money that can be robbed is stored in `dp[-1]`.
    

Here’s the code:

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
            
        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-2] + nums[i], dp[i-1])
        
        return dp[-1]
```

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n)**, where `n` is the number of houses. This is because we iterate through the list of houses once, calculating the maximum possible sum for each house.
    
* **Space Complexity**: The space complexity is **O(n)** due to the `dp` array used to store the maximum amount robbed up to each house. However, this can be further optimized to **O(1)** by only keeping track of the last two values instead of maintaining the entire `dp` array.
    

## Conclusion

The House Robber problem is a great exercise in understanding how dynamic programming can simplify complex problems by breaking them down into subproblems and storing intermediate results. By using dynamic programming, we avoid redundant calculations, thereby significantly improving efficiency. This approach makes it possible to solve the problem in linear time, making it suitable for larger inputs and real-world scenarios.


README for [House Robber (Leetcode 198)](https://blog.unwiredlearning.com/house-robber) was compiled from the Unwired Learning Blog.  
//### 045 File: 0200-number-of-islands/README.md
# Number of Islands (Leetcode #200)

In this blog, we will explore the "Number of Islands" problem, a common coding question that helps in understanding grid traversal techniques. We'll break down the problem, explore different approaches, and provide an optimized solution.

## Understanding the Problem Statement

The "Number of Islands" problem challenges developers to determine how many distinct islands are present in a given 2D grid map. Each cell in the grid can either be land ('1') or water ('0'), and an island is formed by connecting adjacent lands horizontally or vertically. This problem is frequently asked in technical interviews and tests one's understanding of graph traversal techniques and efficient handling of matrix data structures.

## Brute Force Approach

The brute force solution to the "Number of Islands" problem involves iterating over each cell in the grid. Whenever we encounter a land cell ('1'), we count it as a potential island, then proceed to mark all the connected land cells as water ('0') to ensure that the same island is not counted multiple times. This can be done using simple iteration or a naive search. However, this approach may involve repeated traversals of the same sections of the grid, which results in inefficiency.

## Hint to Solve the Problem Efficiently

An efficient way to solve the problem is to think about how to traverse each part of the grid only once and mark it effectively. Consider implementing a Depth First Search (DFS) or Breadth First Search (BFS) approach that will help to mark all connected land cells as visited. This ensures that once an island is counted, we don't recount any of its parts.

## Efficient Solution

Below is an efficient solution that follows the provided code, leveraging Depth First Search (DFS) to explore and mark islands:

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        # Depth First Search (DFS) function to mark visited land
        def dfs(i, j):
            # Base case: if the index is out of bounds or the cell is water ('0'), return
            if (i < 0 or i >= len(grid) or
                j < 0 or j >= len(grid[0]) or grid[i][j] == '0'):
                return
            
            grid[i][j] = '0'  # Mark as visited
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)

        count = 0

        # Iterate through each cell in the grid
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    dfs(i, j)
                    count += 1

        return count
```

In this solution, we define a nested `dfs()` function that takes the current cell coordinates (`i`, `j`). The `dfs()` function is called recursively to traverse all adjacent land cells, marking them as visited by changing their value to '0'. This ensures that we don't count the same island multiple times.

## Time and Space Complexity

* **Time Complexity:** The time complexity of this solution is **O(M \* N)**, where **M** is the number of rows and **N** is the number of columns in the grid. Each cell is visited once, and the DFS operation runs in constant time relative to the number of cells.
    
* **Space Complexity:** The space complexity is **O(M \* N)** in the worst case due to the recursion stack, especially if the entire grid is filled with land. In the average scenario, the space complexity depends on the depth of the recursion.
    

## Conclusion

The "Number of Islands" problem is a great way to practice grid traversal techniques, particularly using Depth First Search (DFS) or Breadth First Search (BFS). By implementing an efficient solution, we can minimize redundant operations and achieve optimal performance. Mastering this approach not only helps in solving similar problems involving grids but also strengthens your understanding of recursion and graph algorithms, which are key components of technical interviews.


README for [Number of Islands (Leetcode #200)](https://blog.unwiredlearning.com/number-of-islands) was compiled from the Unwired Learning Blog.  
//### 046 File: 0206-reverse-linked-list/README.md
# Reverse Linked List (Leetcode #206)

Linked Lists are fundamental data structures, and many problems revolve around manipulating them in some way. The problem '206. Reverse Linked List' asks us to reverse a singly linked list, a basic yet crucial exercise to build your problem-solving skills in linked lists. Let’s break down the problem, explore a common brute force approach, and discuss the efficient solution, along with the time and space complexity.

## Understanding the Problem Statement

In this problem, you are given the head of a singly linked list, and you need to reverse it. Essentially, this means that the last node should become the first node, the second-last node should become the second node, and so on until the original first node is the last one.

The main objective is to return the head of this newly reversed linked list.

Example:

* **Input**: 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; None
    
* **Output**: 5 -&gt; 4 -&gt; 3 -&gt; 2 -&gt; 1 -&gt; None
    

## Brute Force Approach

The brute force approach involves using an auxiliary data structure to store the nodes of the linked list. Here’s how it typically works:

1. Traverse the linked list and store all the node values in an array or list.
    
2. Then iterate over this array in reverse order to recreate the linked list, pointing each node to its preceding one.
    

While this approach is easy to implement and might seem straightforward, it has high space complexity since we use an additional list to store the node values.

* **Time Complexity**: O(N) - We need to traverse all nodes twice, once to collect data and once to recreate the list.
    
* **Space Complexity**: O(N) - Extra space is used to store node values in an array.
    

## Hint to Solve the Problem Efficiently

To solve this problem efficiently without using extra space, think about manipulating the pointers of the nodes in-place rather than copying the data into another data structure. We can reverse the linked list by reassigning each node’s `next` pointer to its previous node, proceeding one node at a time.

## Efficient Solution

Let’s walk through the provided solution which is implemented in Python:

```python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize two pointers, previous and current.
        # Previous will eventually become the new head of the reversed list.
        previous, current = None, head

        # Traverse the list until we reach the end.
        while current:
            # Temporarily store the next node.
            temp = current.next
            
            # Reverse the 'next' pointer of the current node to point to previous node.
            current.next = previous
            
            # Move the previous pointer up to the current node.
            previous = current
            
            # Proceed to the next node in the original list.
            current = temp
        
        # After the loop, current will be None and previous will be the new head of the reversed list.
        head = previous
        return head
```

The idea here is simple but very effective. We use two pointers, `previous` and `current`, to reverse the `next` pointers of each node in the linked list as we traverse through it.

* **previous** initially points to `None` since the new tail (original head) will point to `None`.
    
* **current** starts from the head of the original list.
    
* As we iterate through the list, the next node is stored temporarily in a variable (`temp`) to prevent losing the reference.
    
* The `next` pointer of the current node is then reversed to point to the previous node.
    
* Both pointers (`previous` and `current`) are moved one step forward until the end of the list.
    

The process stops when we reach the end (`current` is `None`). At this point, `previous` points to the new head of the reversed list.

## Time and Space Complexity

* **Time Complexity**: O(N) - Where N is the number of nodes in the linked list. Each node is visited once, resulting in a linear time complexity.
    
* **Space Complexity**: O(1) - The solution is done in-place, using constant space. No extra data structures are needed other than pointers to keep track of nodes, making this solution efficient in terms of space usage.
    

The efficient approach to solving this problem not only improves your understanding of linked lists but also emphasizes the importance of optimizing pointer manipulations. By focusing on reassigning node pointers in-place, we achieve optimal time and space complexity, a crucial skill for tackling linked list challenges.

## Conclusion

Reversing a linked list is a foundational problem that helps you develop a solid understanding of linked list manipulations. The brute force approach offers a simple solution but at the cost of increased space complexity. On the other hand, the efficient in-place solution not only reduces space usage but also strengthens your ability to manage pointers effectively. Mastering this problem will make it easier to tackle more advanced linked list challenges and deepen your understanding of fundamental data structures.


README for [Reverse Linked List (Leetcode #206)](https://blog.unwiredlearning.com/reverse-linked-list) was compiled from the Unwired Learning Blog.  
//### 047 File: 0207-course-schedule/README.md
# Course Schedule (Leetcode 207)

The "Course Schedule" problem is a popular challenge that tests your understanding of graph traversal and cycle detection. Given a number of courses and their prerequisites, the task is to determine if it is possible to complete all the courses. This blog will walk you through a brute force approach, provide a hint for an optimized solution, and finally present an efficient method to solve the problem.

## Understanding the Problem Statement

The "Course Schedule" problem on LeetCode, numbered 207, is a classic problem that asks if you can finish all the courses given their prerequisites. Essentially, you are given a list of courses (represented by numbers) and a list of pairs that specify the prerequisites for these courses. The goal is to determine whether it is possible to complete all the courses while respecting the prerequisites. This is very much like finding whether it is possible to complete a list of tasks, each of which depends on the completion of other tasks.

In more technical terms, the question asks if there is a cycle in the dependency graph of courses. If a cycle exists, it means that there is no possible order to take all the courses, and the answer would be "False." Otherwise, the answer is "True."

## Brute Force Approach

A common brute force approach to solve the problem involves trying all possible orders of taking the courses and checking whether any sequence satisfies all the prerequisites. One way to do this is to perform a topological sort on all possible orders of courses to check if such an order exists that fulfills all the conditions. However, this approach is highly inefficient due to the factorial number of possibilities, making it impractical for large inputs. This is due to the fact that topological sorting in a brute force way can take too much time and space, especially when the graph is complex and contains many nodes (courses).

## Hint to Solve the Problem Efficiently

Instead of trying all possible orders, think about using Depth-First Search (DFS) to detect if there is a cycle in the graph. The key is to use DFS to traverse through each course and its prerequisites. If you encounter a course that is already in the current traversal path, then you have detected a cycle, which means it is not possible to finish all the courses. The provided code uses a clever approach to build the graph and checks for cycles efficiently, which avoids the need for an exhaustive search.

## Efficient Solution

The efficient solution uses Depth-First Search (DFS) to detect cycles in the course prerequisite graph. Let's walk through the provided code:

1. **Graph Representation**: The graph is represented using an adjacency list where each course points to its prerequisites.
    
    ```python
    graph = [[] for _ in range(numCourses)]
    ```
    
    Here, each index in the `graph` list represents a course, and the value is a list of other courses that are prerequisites for the current course.
    
2. **Building the Graph**: The graph is built in reverse order, where each course points to its prerequisites.
    
    ```python
    for pair in prerequisites:
        graph[pair[0]].append(pair[1])
    ```
    
3. **Cycle Detection with DFS**: A `cycle` array is used to keep track of nodes currently in the traversal path.
    
    ```python
    cycle = [False] * numCourses
    ```
    
    The DFS function is used to traverse each course. If the current course is already in the cycle (visited again in the same path), it returns `False` indicating a cycle.
    
    ```python
    def dfs(course):
        if cycle[course]:
            return False
        if graph[course] is None:
            return True
        
        cycle[course] = True
        for prereq in graph[course]:
            if dfs(prereq) is False:
                return False
        cycle[course] = False
        graph[course] = []
        return True
    ```
    
    * If a cycle is detected, `False` is returned, indicating it is not possible to finish all courses.
        
    * If no cycle is detected, the course's prerequisites are marked as completed by setting `graph[course] = []`.
        
4. **Checking All Courses**: Finally, we iterate through all courses to ensure that each one can be completed without a cycle.
    
    ```python
    for i in range(numCourses):
        if dfs(i) is False:
            return False
    return True
    ```
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of the solution is `O(V + E)`, where `V` is the number of courses (`numCourses`) and `E` is the number of dependencies (prerequisites). This is because each node and edge is processed once in the DFS traversal.
    
* **Space Complexity**: The space complexity is also `O(V + E)` due to the storage requirements of the graph and the recursion stack used by the DFS. The `cycle` array and the graph representation both take `O(V + E)` space.
    

This approach is efficient because it processes each course and its prerequisites in a linear fashion, avoiding the combinatorial explosion of the brute force approach.

## Conclusion

The "Course Schedule" problem is a great example of how graph traversal techniques like DFS can be used to solve practical problems involving dependencies. By detecting cycles in the graph representation of courses and their prerequisites, we can efficiently determine whether it is possible to complete all courses. This problem helps build an understanding of cycle detection, graph representation, and recursive thinking, which are crucial skills for tackling complex graph-related problems.


README for [Course Schedule (Leetcode 207)](https://blog.unwiredlearning.com/course-schedule) was compiled from the Unwired Learning Blog.  
//### 048 File: 0208-implement-trie-prefix-tree/README.md
# Implement Trie (Prefix Tree) (Leetcode #208)

Tries, also known as Prefix Trees, are an important data structure used to efficiently store and search collections of strings. They are particularly useful when dealing with scenarios that involve prefix-based searching, such as autocomplete systems. In this blog, we will explore how to implement a Trie for solving Leetcode Problem 208, which involves creating an efficient data structure that can perform insert, search, and prefix operations on words.

## Understanding the Problem Statement

The problem asks you to implement a data structure called a Trie, also known as a Prefix Tree. A Trie is used to store a collection of strings, primarily to support efficient prefix searches. You need to design three primary functions:

* **Insert** a word into the Trie.
    
* **Search** if a word exists in the Trie.
    
* **startsWith** to determine if any word in the Trie starts with a given prefix.
    

For example, inserting "cat", "cap", and "dog" will store all these words in such a way that the shared characters can be used to optimize space. Searching for "cap" will return true, while searching for "car" will return false.

## Brute Force Approach

A brute force way to implement this problem is by using an array or a list to store all the words. For each search operation, you would iterate through the entire list, checking each word until you find a match or exhaust the list. Similarly, for the prefix operation, you would need to iterate through every word, checking if it begins with the desired prefix.

While this approach is simple to implement, it becomes inefficient when the dataset grows larger. The search and prefix operations have a time complexity of **O(n × m)**, where **n** is the number of words and **m** is the average length of the words, making this approach slow for large datasets.

## Hint to Solve the Problem Efficiently

Instead of storing individual words, think of storing the words in a hierarchical structure, where each character represents a node. This hierarchical structure would allow you to share prefixes between words, thus reducing redundancy. Each node should keep track of its children and whether it is the end of a word.

## Efficient Solution

A more efficient approach is to use a Trie, which is a tree-like data structure where each node represents a character. The provided code efficiently implements this solution:

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root        
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True
```

The **TrieNode** class represents each node of the Trie, containing a dictionary of children and a flag to indicate the end of a word.

The **Trie** class has three functions:

* **insert(word)**: Iterates through each character in the word, and either traverses or creates a new node in the children dictionary for each character. Finally, it marks the end of the word.
    
* **search(word)**: Checks if the word exists by traversing through each character, returning **True** if the final node is marked as the end.
    
* **startsWith(prefix)**: Checks if a given prefix exists by traversing each character, returning **True** if all characters are found.
    

## Time and Space Complexity

* **Insert Operation**: The time complexity is **O(m)**, where **m** is the length of the word to be inserted. Each character of the word is processed only once.
    
* **Search Operation**: The time complexity is also **O(m)**, where **m** is the length of the word. We traverse each character to check if the word exists.
    
* **startsWith Operation**: Similarly, the time complexity is **O(m)**, where **m** is the length of the prefix.
    

The space complexity for the Trie is **O(n × m)**, where **n** is the number of words and **m** is the average length of each word. Each node may have multiple children, resulting in an overall space usage that depends on the size of the input dataset. However, this structure is still efficient compared to storing individual words, especially when words share prefixes.

## Conclusion

Implementing a Trie is an efficient way to handle prefix-based searches and can significantly improve performance compared to brute force methods. Tries are widely used in applications like search engines, autocomplete systems, and dictionaries, where fast retrieval of words or prefixes is critical. By breaking down words into individual characters and organizing them in a hierarchical structure, Tries help reduce redundancy and optimize search operations. Hopefully, this guide has helped you understand how to implement a Trie and leverage it effectively to solve Leetcode Problem 208.


README for [Implement Trie (Prefix Tree) (Leetcode #208)](https://blog.unwiredlearning.com/implement-trie-prefix-tree) was compiled from the Unwired Learning Blog.  
//### 049 File: 0211-design-add-and-search-words-data-structure/README.md
# Design Add and Search Words Data Structure (Leetcode #211)

Designing a data structure that can handle adding words and searching with wildcards is an interesting challenge that tests your understanding of tries and recursive search techniques. Let’s solve the LeetCode problem "211. Design Add and Search Words Data Structure" step by step.

## Understanding the Problem Statement

The challenge requires you to create a data structure that supports:

1. **addWord(word)** - Adds a word into the data structure.
    
2. **search(word)** - Searches for a word that may contain the special wildcard character `'.'`. The `'.'` wildcard can match any letter.
    

Consider this example:

* **addWord("chat")**
    
* **search("chat")** returns `true` since the word was added.
    
* **search("ch.t")** returns `true` since the wildcard character `'.'` can match `'a'`.
    
* **search("bat")** returns `false` since this word was never added.
    

Your task is to implement a structure that efficiently supports these operations.

## Brute Force Approach

A brute force approach might be to store all the words in a list and iterate through the list to find matching words whenever a search request is made. This approach would involve a character-by-character comparison and extra logic to handle the wildcard `'.'`, effectively leading to a lot of redundant computations. It becomes highly inefficient when dealing with a large number of words.

**Complexity of the Brute Force Approach**

The time complexity of this brute force approach would be **O(N \* L)**, where **N** is the number of words stored and **L** is the average length of the words. The search operation is especially costly, as it requires iterating over all stored words.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, think of using a **Trie** data structure. A Trie, or prefix tree, provides an efficient way to store words and facilitates fast lookups. In addition, a recursive Depth First Search (DFS) can be used to navigate through the Trie nodes to handle wildcard searches.

## Efficient Solution

The given code leverages a Trie to store words and recursively searches through nodes to handle the wildcard character. Here's how the solution works:

**TrieNode Class**

The `TrieNode` class represents individual nodes in the Trie. Each node has a dictionary called `children` to store references to child nodes and a boolean `is_end` to mark the end of a word.

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False
```

**WordDictionary Class**

The `WordDictionary` class handles adding and searching words:

1. **addWord(word)** - This function iterates through the characters in the word and adds them to the Trie, creating new nodes as necessary. The end of the word is marked by setting `is_end` to `True`.
    
2. **search(word)** - This function uses Depth First Search (DFS) to search for the word, handling the wildcard character `'.'` by exploring all possible child nodes.
    

```python
class WordDictionary:

    def __init__(self):
        self.root = TrieNode()        

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end = True        
        
    def search(self, word: str) -> bool:
        node = self.root

        def dfs(node, i):
            if i == len(word):
                return node.is_end
                
            if word[i] == '.':
                for child in node.children.values():
                    if dfs(child, i + 1):
                        return True
                return False

            if word[i] in node.children:
                return dfs(node.children[word[i]], i + 1)
            return False

        return dfs(node, 0)        
```

**How the Wildcard is Handled**

The key part of this solution is how the `'.'` character is handled in the `dfs()` function. When `'.'` is encountered, the algorithm iterates through all the children of the current node, recursively searching each child. This allows the `'.'` to match any character effectively.

## Time and Space Complexity

**Time Complexity**

* **addWord(word)**: The time complexity for adding a word is **O(L)**, where **L** is the length of the word. This is because we need to iterate through all characters of the word to add it to the Trie.
    
* **search(word)**: The time complexity for searching is **O(N)** in the worst case, where **N** is the total number of nodes in the Trie. This happens when using the wildcard character `'.'` and every node must be explored.
    

**Space Complexity**

The space complexity is **O(N \* L)**, where **N** is the number of words and **L** is the average length of the words. Each character in each word needs its own TrieNode, which leads to this complexity.

## Conclusion

This problem provides a great opportunity to understand the power of Tries in efficiently managing word-based data structures, particularly when wildcard searches are involved. By using a Trie and a recursive DFS approach, we can implement the `addWord` and `search` functions in a way that is both time-efficient and space-efficient for large datasets.


README for [Design Add and Search Words Data Structure (Leetcode #211)](https://blog.unwiredlearning.com/design-add-and-search-words-data-structure) was compiled from the Unwired Learning Blog.  
//### 050 File: 0212-word-search-ii/README.md
# Word Search II (Leetcode #212)

In this blog, we will discuss the brute force approach, provide hints for solving the problem efficiently, and dive into an optimal solution using a combination of Trie and DFS.

## Understanding the Problem Statement

Word Search II (Leetcode 212) is a popular backtracking problem where you're given a 2D board of letters and a list of words. The goal is to find all words from the list that exist in the board, where each word must be formed by sequentially adjacent letters (either horizontally or vertically), without reusing the same cell twice.

## Brute Force Approach

In the brute force approach, you would start by iterating over each cell in the board and attempting to find each word starting from that particular cell. This typically involves exploring all possible directions to try and match each character of a word. While easy to understand, this approach suffers from severe inefficiency as the same searches are repeated for each word, resulting in an exponential time complexity. As the board and word list grow, the brute force method becomes impractical due to high computational costs.

## Hint to Solve the Problem Efficiently

The provided solution involves using a **Trie** (prefix tree) to optimize the search process. A Trie is built to efficiently store and look up the words from the given list, which helps in reducing redundant searches during the depth-first traversal of the board. The combination of the Trie and Depth-First Search (DFS) drastically improves the performance, especially when dealing with large boards and numerous words.

## Efficient Solution

To efficiently solve the problem, we combine **DFS** and a **Trie** to minimize redundant computations and speed up the word search. Below is the efficient solution from the provided code:

1. **Building the Trie**: The `buildTrie` function takes the given list of words and constructs a Trie. Each node of the Trie represents a character, and the Trie as a whole represents all the words. This allows for quick lookups when attempting to match a word starting from any cell on the board.
    
2. **DFS for Word Search**: The `dfs` function performs depth-first search on the board, starting from any character that matches the root of the Trie. As each character is found, it moves deeper into the Trie, and ultimately, if a word is found, it is added to the result.
    
3. **Marking Visited Cells**: During the DFS, cells are marked as visited by temporarily changing their value. This avoids revisiting cells within the same path. After the DFS is complete, the cells are restored to their original values to maintain board integrity.
    
4. **Avoiding Duplicates**: Once a word is found, it is added to the result set and marked as found in the Trie to avoid duplicate entries in the final result.
    

Here's a summary of the approach used:

* **Trie Construction**: Efficiently represents words for quick lookup.
    
* **DFS Search**: Explores possible words starting from each board cell, backtracking as needed.
    
* **Result Set**: Keeps track of found words to avoid duplicates.
    

## Time and Space Complexity

**Time Complexity**: The solution has an average complexity of **O(M × N × 4^L)**, where **M** is the number of rows, **N** is the number of columns in the board, and **L** is the length of the longest word. The Trie lookup and pruning of search space help reduce unnecessary computations, making the solution much more efficient compared to a brute-force search.

**Space Complexity**: The space complexity is **O(W × L + M × N)**, where **W** is the number of words and **L** is the average length of the words. This includes space for storing the Trie as well as the recursion stack used during the DFS traversal. While the Trie structure can be memory-intensive, it is a necessary trade-off for the significant speed-up in search performance.

## Conclusion

Word Search II is a challenging problem that requires an optimized approach to handle large boards and multiple words efficiently. By combining the Trie data structure with depth-first search, we can significantly reduce redundant operations and speed up the word search process. This efficient solution not only highlights the power of combining different algorithms but also serves as a great exercise in improving the time complexity of typical brute-force approaches. With a solid understanding of Trie and DFS, solving complex word search problems becomes much more manageable.


README for [Word Search II (Leetcode #212)](https://blog.unwiredlearning.com/word-search-ii) was compiled from the Unwired Learning Blog.  
//### 051 File: 0213-house-robber-ii/README.md
# House Robber II (Leetcode 213)

The House Robber II problem (Leetcode 213) presents a variation of the classic House Robber problem, which challenges us to find the maximum amount of money we can rob from houses arranged in a circular neighborhood. Since the first and last houses are adjacent, this creates a unique constraint that prevents robbing both the first and the last house.

## Understanding the Problem Statement

Imagine you are a thief planning to rob houses along a circular street, where each house has a certain amount of money. The constraint is that you cannot rob two directly adjacent houses, and because the street is circular, the first and last houses are also considered adjacent. Your goal is to maximize the total amount you can rob without alerting the police.

For instance, if the houses contain money as `[2, 3, 2]`, you cannot rob the first and last house together. Hence, the maximum amount you can rob is `3`. However, if the houses are `[1, 2, 3, 1]`, the optimal approach would yield `4` by robbing houses `2` and `3`.

## Brute Force Approach

A straightforward brute force approach would involve trying all possible combinations of houses to rob, while adhering to the constraint that no two adjacent houses can be robbed. Since the circular layout adds complexity, we need to account for both the inclusion and exclusion of the first and last houses. We could recursively explore each combination, calculating the total loot each time. However, this approach results in an exponential time complexity due to the sheer number of combinations, making it impractical for larger inputs.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, think about breaking it down into simpler subproblems. Since robbing the first house prevents us from robbing the last one, we can split the problem into two scenarios:

1. Robbing houses from the first to the second-last house.
    
2. Robbing houses from the second to the last house.
    

By solving these two subproblems independently and taking the maximum result, we can effectively handle the circular constraint.

## Efficient Solution

The provided solution leverages dynamic programming to solve the problem efficiently by considering the two scenarios outlined above.

Here is the core of the solution:

1. **Base Cases**: If the input list is empty, return `0`. If it contains only one house, return the value of that house.
    
2. **Split the Problem**: Create two lists: one excluding the last house (`skip_last_house`) and one excluding the first house (`skip_first_house`).
    
3. **Helper Function for Robbery**: Use a helper function (`rob_helper`) to solve the linear version of the house robbery problem for both lists. The helper function applies a dynamic programming approach to calculate the maximum amount that can be robbed without alerting the police.
    
4. **Return the Maximum**: The final answer is the maximum value obtained from the two scenarios.
    

Here is the implementation:

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0            
        if len(nums) == 1:
            return nums[0]

        # Create 2 new lists
        skip_last_house = nums[:-1]
        skip_first_house = nums[1:]

        # Get the loot from both possibilities
        loot_skipping_last = self.rob_helper(skip_last_house)
        loot_skipping_first = self.rob_helper(skip_first_house)

        # Return the maximum of 2 loots
        return max(loot_skipping_last, loot_skipping_first)

    def rob_helper(self, nums):
        if len(nums) == 1:
            return nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        return dp[-1]
```

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(n)`, where `n` is the number of houses. This is because we iterate through the list of houses twice (once for each scenario).
    
* **Space Complexity**: The space complexity is also `O(n)` due to the use of an auxiliary `dp` array to store intermediate results. However, this could be optimized to `O(1)` by keeping track of only the last two values, which would further reduce the memory usage.
    

## Conclusion

The House Robber II problem is a classic example of how dynamic programming can be used to solve optimization problems with constraints. By breaking the circular dependency into two separate scenarios, we simplify the problem into a linear one that can be effectively managed using a helper function. This approach not only ensures optimal performance but also maintains clarity in handling complex conditions like circular arrangements. By leveraging dynamic programming, we achieve a solution that balances both time and space efficiency, making it suitable for large inputs.


README for [palindromic-substrings](https://leetcode.com/problems/palindromic-substrings) was compiled from the Unwired Learning Blog.  
//### 052 File: 0217-contains-duplicate/README.md
# Contains Duplicate (Leetcode #217)

In this blog, we'll be tackling LeetCode problem 217: **"Contains Duplicate"**. It's a classic problem that tests your ability to effectively manage and analyze a dataset to check for the existence of duplicate elements. We'll go over the problem description, explore a brute force approach, provide hints for improving your solution, and ultimately explain an efficient way to solve it. Let's dive in!

### Understanding the Problem Statement

You are given an integer array `nums`. Your task is to determine if any value appears **at least twice** in the array. In other words, we need to return `true` if there are any duplicates, and `false` otherwise.

**Example**:

* Input: `nums = [1, 2, 3, 1]`
    
* Output: `true` (since `1` appears twice)
    
* Input: `nums = [1, 2, 3, 4]`
    
* Output: `false` (since no element appears more than once)
    

The challenge is to come up with a solution that runs efficiently for large input arrays.

### The Brute Force Approach

The most straightforward way to solve this problem is to compare every element with every other element in the array. This brute force approach works, but it has a significant drawback when it comes to efficiency.

Here's how a brute force solution would look:

```python
# Brute Force Solution
def containsDuplicate(nums):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] == nums[j]:
                return True
    return False
```

In this solution, we use two nested loops to compare each element to every other element, which gives us a time complexity of **O(n^2)**. While this approach will give the correct answer, it's not suitable for large datasets because it takes too long to process.

### Hint to Solve the Problem Efficiently

The brute force approach works but is very inefficient for large input arrays. The key to improving our solution is to leverage a data structure that allows us to perform checks in constant time. In particular, using a **set** in Python can be very helpful here, as sets do not allow duplicates and offer average **O(1)** lookup times.

Consider how a set can help us easily determine if an element has already been seen in the array.

### The Efficient Solution

Let's walk through the efficient solution to the problem using a **set**. This solution ensures we are only iterating through the list once, and our operations within the loop are performed in constant time on average.

Here's the code:

```python
# Efficient Solution
def containsDuplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False
```

**Explanation**:

1. **Create a Set**: We start by creating an empty set named `seen` to keep track of numbers we've encountered.
    
2. **Iterate Through the List**: For each element in the list `nums`, we check if it is already in the set.
    
3. **Return True if Found**: If we find the element in the set, we know it is a duplicate, and we return `True`.
    
4. **Add the Number to Set**: If the element is not in the set, we add it to `seen`.
    
5. **Return False**: If we finish iterating through the list without finding any duplicates, we return `False`.
    

### Time and Space Complexity

* **Time Complexity**: The time complexity of the efficient solution is **O(n)**, where `n` is the number of elements in the array. We iterate through the list once, and the average time complexity for inserting and checking membership in a set is **O(1)**.
    
* **Space Complexity**: The space complexity is **O(n)** as well, because, in the worst case, we might need to store all `n` elements in the set if there are no duplicates.
    

### Summary

In this blog, we've covered LeetCode problem 217: "Contains Duplicate". We started with a brute force solution, which was straightforward but inefficient. By understanding the properties of a set, we improved our solution to achieve a time complexity of **O(n)** and a space complexity of **O(n)**, making it much more efficient for larger datasets.

If you're looking to enhance your problem-solving skills, always remember that finding the right data structure can make all the difference! Try implementing the efficient solution on your own, and you'll see how useful Python's set can be in situations like this.


Orignal Blog Source: [Contains Duplicate (Leetcode #217)](https://blog.unwiredlearning.com/contains-duplicate).  
//### 053 File: 0226-invert-binary-tree/README.md
# Invert Binary Tree (Leetcode #226)

Binary trees are a fundamental data structure in computer science, used in a wide range of applications from databases to network routing. One common problem that helps deepen understanding of binary tree manipulation is the 'Invert Binary Tree' problem. Inverting a binary tree involves swapping all left and right children nodes to produce a mirror image of the original tree. This guide will walk you through the problem statement, a brute-force solution, an efficient approach using recursion, and an analysis of the time and space complexity involved.

## Understanding the Problem Statement

The 'Invert Binary Tree' is a common LeetCode problem that asks you to invert a given binary tree, meaning you swap all the left and right children nodes throughout the entire tree. This problem is similar to producing a mirror image of the binary tree.

The input will be the root of the binary tree, and the expected output is the root of the newly inverted tree. For example:

* Input Tree:
    

```python
    4
   / \
  2   7
 / \ / \
1  3 6  9
```

* Output Tree (after inversion):
    

```python
    4
   / \
  7   2
 / \ / \
9  6 3  1
```

The goal is to efficiently reverse the given binary tree's structure.

## Brute Force Approach

A simple brute-force approach to solve this problem could involve manually traversing the entire binary tree, swapping each left and right child node at each level, starting from the root node and moving all the way down to the leaves.

This can be achieved using a queue to perform a level-order traversal (BFS) where we swap each child node at every level.

Pseudo-code for brute-force:

* Use a queue to start from the root.
    
* Traverse each node level by level.
    
* For each node, swap its left and right child nodes.
    

While this approach is straightforward, it is not the most efficient as it requires extra memory to store the nodes for traversal.

## Hint to Solve the Problem Efficiently

The key to solving this problem efficiently lies in recursion. Think of it this way: the process of inverting a binary tree can be broken down into smaller subproblems of inverting the left and right subtrees. Once those subtrees are inverted, you simply swap them.

## Efficient Solution

The provided code offers an elegant solution using recursion to invert the binary tree.

```python
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None

        # Swap the left and right children
        root.left, root.right = root.right, root.left

        # Recursively invert the left and right subtree
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
```

Let's break down the code:

* **Base Case**: If the `root` is `None`, return `None`. This ensures that the function stops at the leaf nodes and doesn't try to access non-existent child nodes.
    
* **Swapping Children**: The main action here is to swap `root.left` and `root.right`. This effectively inverts the current node.
    
* **Recursive Call**: After swapping the children of the current node, the function recursively calls itself on `root.left` and `root.right` to invert the remaining subtrees.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n)**, where `n` is the number of nodes in the binary tree. This is because each node is visited exactly once to perform the swap.
    
* **Space Complexity**: The space complexity of this solution is **O(h)**, where `h` is the height of the binary tree. This is due to the recursive nature of the solution, which takes up space on the call stack proportional to the height of the tree. In the worst case, for a skewed tree, this could be **O(n)**, while for a balanced tree, it would be **O(log n)**.
    

## Conclusion

Inverting a binary tree is an interesting exercise that tests your ability to think recursively. The provided solution is both concise and efficient, focusing on the principle of inverting subtrees and then combining those results to achieve the overall inversion. While brute-force approaches like BFS level-order traversal can solve the problem, a recursive approach is usually more elegant and straightforward. Feel free to implement this solution and experiment with other variations to deepen your understanding of tree traversal and recursion!


README for [Invert Binary Tree (Leetcode #226)](https://blog.unwiredlearning.com/invert-binary-tree) was compiled from the Unwired Learning Blog.  
//### 054 File: 0230-kth-smallest-element-in-a-bst/README.md
# Kth Smallest Element in a BST (Leetcode #230)

Finding specific elements in a Binary Search Tree (BST) is a common problem in computer science, often used to test knowledge of tree traversal techniques and understanding of BST properties. One such problem is determining the Kth smallest element in a BST, which requires an efficient approach to ensure optimal performance. In this blog, we will discuss the problem statement, explore a brute force approach, provide a hint for a more efficient solution, and then walk through an efficient solution with detailed time and space complexity analysis.

## Understanding the Problem Statement

The problem asks us to find the Kth smallest element in a Binary Search Tree (BST). A BST is a binary tree in which each node follows a specific order: the value of every node in the left subtree is smaller than the value of the root node, and the value of every node in the right subtree is greater. Given a BST and a value K, we need to find the value of the Kth smallest node in this tree.

For example, if the tree is:

```python
      3
     / \
    1   4
     \
      2
```

And `k = 1`, the answer is `1` because `1` is the smallest element in the tree.

## Brute Force Approach

A common brute force approach to solve this problem involves performing an in-order traversal of the BST and storing all the nodes' values in an array. In-order traversal of a BST results in the values being stored in a sorted order, which makes it easy to access the Kth smallest element. Once we have this sorted list, we simply return the K-1 indexed value from the list.

The brute force approach involves the following steps:

1. Perform an in-order traversal to store all the nodes in a list.
    
2. Retrieve the Kth smallest element by accessing the K-1 index.
    

However, this approach has a time complexity of O(N), where N is the number of nodes in the tree, and a space complexity of O(N) as well, due to storing all the nodes in an array.

## Hint to Solve the Problem Efficiently

Instead of storing all the values in an array, you can optimize the space usage by only keeping track of the count and stopping once you reach the Kth smallest element during the traversal. This eliminates the need for an entire array to store all the nodes.

## Efficient Solution

The provided code follows the brute force approach by performing an in-order traversal and storing the nodes' values in an array. Here is the given solution:

```python
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # List to store the values of nodes in in-order traversal
        io_list = []
        
        # Populate the io_list with the in-order traversal of the tree
        self.helper(root, io_list)

        return io_list[k-1]

    def helper(self, tree_node, io_list):
        # Base case: if the node is None, return
        if tree_node is None:
            return

        self.helper(tree_node.left, io_list)
        io_list.append(tree_node.val)
        self.helper(tree_node.right, io_list)
```

In this solution, the helper function performs an in-order traversal, and all the node values are stored in the `io_list`. After completing the traversal, we simply return the `k-1` element from the list, which represents the Kth smallest element.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(N)**, where `N` is the number of nodes in the BST. This is because we visit each node exactly once during the in-order traversal.
    
* **Space Complexity**: The space complexity is also **O(N)** due to the use of the `io_list` to store all node values. Additionally, the recursion stack space can take up to O(H), where `H` is the height of the tree, which in the worst case (skewed tree) could be O(N).
    

For an optimized solution, we could modify the in-order traversal to stop once we find the Kth element, thereby reducing the space complexity.

## Conclusion

Finding the Kth smallest element in a BST is a fundamental problem that helps to strengthen understanding of tree traversal and BST properties. While the brute force approach is straightforward, it is not the most efficient in terms of space usage. By optimizing the traversal process, we can achieve a more space-efficient solution. Understanding the trade-offs between time and space complexity is crucial when choosing the best approach for solving such problems. We hope this guide has helped you understand both the brute force and efficient ways to solve the Kth smallest element problem in a BST.


README for [Kth Smallest Element in a BST (Leetcode #230)](https://blog.unwiredlearning.com/kth-smallest-element-in-a-bst) was compiled from the Unwired Learning Blog.  
//### 055 File: 0235-lowest-common-ancestor-of-a-binary-search-tree/README.md
# Lowest Common Ancestor of a Binary Search Tree (Leetcode #235)

Finding the Lowest Common Ancestor (LCA) in a Binary Search Tree (BST) is a fundamental problem that often appears in technical interviews and coding challenges. The LCA of two nodes `p` and `q` in a BST is defined as the deepest node that is an ancestor to both `p` and `q`. Understanding how to efficiently find the LCA is key to mastering tree-based algorithms, especially when dealing with BSTs. In this blog, we will explore both a brute force approach and an efficient solution to solve this problem.

## Understanding the Problem Statement

In this problem, we are given a Binary Search Tree (BST) and two nodes, `p` and `q`, for which we need to find their Lowest Common Ancestor (LCA). The Lowest Common Ancestor is the deepest node that has both `p` and `q` as descendants. In simpler terms, it is the node that is common to both `p` and `q` and is farthest from the root of the tree.

For example, in a BST where `p` and `q` are two different nodes, the LCA would be the first node from the root where the paths to `p` and `q` diverge.

## Brute Force Approach

A brute force approach to solve this problem involves finding the paths from the root to the nodes `p` and `q` separately. We can traverse the BST starting from the root and store the nodes visited in each path until we reach `p` or `q`. Once both paths are available, we iterate over them to find the last common node, which would be the LCA. This method works, but it requires additional space to store the paths and takes more time to identify the common ancestor, especially when the BST is large.

## Hint to Solve the Problem Efficiently

A crucial property of the BST can make the problem easier to solve without storing the paths. In a BST:

* All values in the left subtree are smaller than the root.
    
* All values in the right subtree are greater than the root.
    

This property allows us to make a single traversal from the root to find the split point where `p` and `q` diverge. This split point will be the LCA.

## Efficient Solution

Below is the efficient solution that leverages the properties of a Binary Search Tree to find the LCA in a single traversal without storing any paths:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            # If both p and q are greater than root, go to right subtree
            if p.val > root.val and q.val > root.val:
                root = root.right
            # If both p and q are lesser than root, go to left subtree
            elif p.val < root.val and q.val < root.val:
                root = root.left
            else:
                # We have found the split point, i.e. the LCA node.
                return root
```

In this solution, we start at the root and iteratively move either left or right, depending on the values of `p` and `q` relative to the current node (`root`). If both `p` and `q` are greater than `root`, it means they lie in the right subtree, so we move to `root.right`. If both are smaller, we move to `root.left`. When we encounter a node that lies between `p` and `q` (or matches one of them), we have found our LCA.

## Time and Space Complexity

* **Time Complexity**: The time complexity for this solution is **O(h)**, where `h` is the height of the tree. In the worst case, this could be `O(n)` for an unbalanced tree or **O(log n)** for a balanced BST.
    
* **Space Complexity**: The space complexity is **O(1)**, as we are not using any additional data structures for storing paths or making recursive calls. Instead, the traversal is done iteratively, keeping space requirements minimal.
    

## Conclusion

The problem of finding the Lowest Common Ancestor in a BST can be solved using an efficient single traversal approach by leveraging the properties of BSTs. While the brute force approach works, it is not optimal for large trees. The efficient solution discussed in this blog provides a time-efficient and space-efficient way to determine the LCA, making it a preferred approach for solving this problem. Understanding this solution helps in strengthening one's grasp on tree traversal techniques and how to utilize BST properties effectively.


README for [Lowest Common Ancestor of a Binary Search Tree (Leetcode #235)](https://blog.unwiredlearning.com/lowest-common-ancestor-of-a-binary-search-tree) was compiled from the Unwired Learning Blog.  
//### 056 File: 0238-product-of-array-except-self/README.md
# Product of Array Except Self (Leetcode #238)

Leetcode problem 238, "Product of Array Except Self," is a popular coding problem that helps you enhance your understanding of array manipulation, efficient iteration, and avoiding redundant computations. Let's explore how to solve this problem in various ways, including a brute force approach and an efficient solution.

## Understanding the Problem Statement

You are given an array of integers `nums`, and you need to return an array `output` such that each element at index `i` is the product of all elements in the original array except the element at `i`. The problem comes with some constraints: you cannot use the division operator, and the solution must run in O(n) time complexity while using only constant extra space (excluding the output array).

**Example**

* **Input**: `nums = [1, 2, 3, 4]`
    
* **Output**: `[24, 12, 8, 6]`
    

The output indicates that for each index, we take the product of all elements except the one at the current index.

## Brute Force Approach

A common approach to solve this problem is by using a brute force method. The brute force approach involves iterating through each element and calculating the product of all other elements for that index. To achieve this:

1. Loop through each element in the input array.
    
2. Use a nested loop to calculate the product of all elements except the current element.
    

The code for a brute force approach would look something like this:

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = []
        for i in range(n):
            product = 1
            for j in range(n):
                if i != j:
                    product *= nums[j]
            result.append(product)
        return result
```

This approach works but has a significant drawback: it results in a time complexity of **O(n^2)** due to the nested loop. This solution is inefficient for large input arrays.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, we need to think about how to calculate the product for each element without repeatedly multiplying all the values every time. The key idea is to calculate products in two passes:

* **Left Product**: Calculate the cumulative product of elements to the left of the current element.
    
* **Right Product**: Calculate the cumulative product of elements to the right of the current element.
    

By combining these two values for each element, we can get the final product for each index without recalculating anything redundantly.

## Efficient Solution

The efficient solution involves using two auxiliary arrays to store the left and right products for each element, followed by combining them to get the result. Here is the code provided, which follows this idea:

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)

        # Array to store all left multiplication
        left = [1] * n
        for i in range(1, n):
            left[i] = left[i - 1] * nums[i - 1]

        # Array to store all right multiplication
        right = [1] * n
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]

        # Calculate the result array by multiplying left and right products
        result = [1] * n
        for i in range(n):
            result[i] = left[i] * right[i]

        return result
```

**Step-by-Step Explanation**

1. **Left Product Calculation**:
    
    * Create an array `left` where `left[i]` stores the product of all elements to the left of index `i`.
        
    * Initialize `left` as `[1] * n` because there are no elements to the left of the first element.
        
    * Iterate through the array from index 1 to `n-1`, and calculate `left[i]` as `left[i-1] * nums[i-1]`.
        
2. **Right Product Calculation**:
    
    * Create an array `right` where `right[i]` stores the product of all elements to the right of index `i`.
        
    * Initialize `right` as `[1] * n` because there are no elements to the right of the last element.
        
    * Iterate through the array from `n-2` to 0, and calculate `right[i]` as `right[i+1] * nums[i+1]`.
        
3. **Final Result Calculation**:
    
    * Create the `result` array by multiplying the corresponding elements from `left` and `right` arrays.
        
    * Set `result[i] = left[i] * right[i]` for each index `i`.
        

This solution calculates the product for each element in O(n) time, without using nested loops.

## Time and Space Complexity

* **Time Complexity**: The solution runs in **O(n)** time. We make three passes through the input array:
    
    1. One to compute the `left` products.
        
    2. One to compute the `right` products.
        
    3. One to compute the final result array. Each pass takes linear time, making the overall time complexity O(n).
        
* **Space Complexity**: The space complexity is **O(n)** due to the additional `left` and `right` arrays. However, the problem can be solved in **O(1)** extra space if we use the output array to store intermediate results (excluding the output array itself).
    

## Conclusion

The key to solving "Product of Array Except Self" efficiently is to recognize how you can precompute parts of the result (i.e., left and right products) and combine them in a meaningful way. This approach avoids using division, handles all elements in linear time, and minimizes redundant calculations. It's a perfect example of leveraging precomputation to solve complex problems elegantly and efficiently.


README for [Product of Array Except Self (Leetcode #238)](https://blog.unwiredlearning.com/product-of-array-except-self) was compiled from the Unwired Learning Blog.  
//### 057 File: 0242-valid-anagram/README.md
# Valid Anagram (Leetcode #242)

When tackling coding challenges, the "Valid Anagram" problem is an excellent way to understand strings and hashmaps better. Let's dive into the problem, explore different approaches, and break down an efficient solution step-by-step.

## Understanding the Problem Statement

The problem statement is:

> Given two strings, `s` and `t`, determine if `t` is an anagram of `s`.

An **anagram** is a word formed by rearranging the letters of a different word, using all the original letters exactly once. For instance, "listen" is an anagram of "silent".

The function should return `True` if the strings `s` and `t` are anagrams, and `False` otherwise.

**Example:**

* Input: `s = "anagram"`, `t = "nagaram"`
    
* Output: `True`
    
* Input: `s = "rat"`, `t = "car"`
    
* Output: `False`
    

## Brute Force Approach

A common brute force approach to solve this problem would be:

* **Sort the Strings**: Sort both strings `s` and `t`. If both sorted strings are equal, then `t` is an anagram of `s`.
    
* **Comparison**: Compare the two sorted strings to determine if they match.
    

**Code:**

```plaintext
s_sorted = sorted(s)
t_sorted = sorted(t)
return s_sorted == t_sorted
```

**Time Complexity**: The brute force approach requires sorting the strings, which would take **O(n log n)** time, where `n` is the length of the strings. Sorting is a common and straightforward way to solve the problem, but it is not the most efficient.

## Hint to Solve the Problem Efficiently

Think about **counting the frequency** of each character in both strings. If the character counts match, then the strings are anagrams. Using a hashmap or an array to track character frequencies can significantly improve the efficiency of the solution.

## Efficient Solution

The efficient way to solve this problem involves using a **hashmap (dictionary in Python)** to count the frequency of each character in both strings `s` and `t`. Here's how it can be done:

1. If the lengths of `s` and `t` are not the same, immediately return `False`. Two strings of different lengths cannot be anagrams.
    
2. Use a hashmap to count the occurrence of each character in `s`.
    
3. Decrement the count for each character found in `t`.
    
4. If any character count does not match, return `False`. Otherwise, return `True`.
    

**Code:**

```plaintext
def isAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    count = {}

    # Count the frequency of characters in s
    for char in s:
        count[char] = count.get(char, 0) + 1

    # Decrement the frequency based on characters in t
    for char in t:
        if char not in count:
            return False
        count[char] -= 1
        if count[char] < 0:
            return False

    return True
```

## Time and Space Complexity

* **Time Complexity**: **O(n)**, where `n` is the length of the strings `s` and `t`. The solution iterates over each character in `s` and `t` exactly once.
    
* **Space Complexity**: **O(1)** (considering constant space usage) or **O(k)**, where `k` is the number of unique characters in the input alphabet. Since we are storing character frequencies, the hashmap size will be proportional to the number of unique characters. In most scenarios involving only lowercase English letters, this space requirement is effectively constant.
    

## Conclusion

While the brute force solution sorts the strings, the efficient solution leverages a character frequency count, making it a linear-time approach. This type of problem highlights the importance of evaluating both time and space complexity to find an optimal solution, especially for larger inputs.

Use this efficient approach to ace the "Valid Anagram" question on LeetCode and understand the power of hashmaps in string problems!


README for [Valid Anagram (Leetcode #242)](https://blog.unwiredlearning.com/valid-anagram) was compiled from the Unwired Learning Blog.  
//### 058 File: 0252-meeting-rooms/README.md
# Meeting Rooms (Leetcode #252)

The "Meeting Rooms" problem is a classic interview question that tests your understanding of intervals, sorting, and detecting overlaps. In this blog, we will walk through this problem in detail, explore a common brute force approach, provide hints, and eventually discuss an efficient solution, justified by time and space complexity. Let's get started!

## Understanding the Problem Statement

You are given an array of meeting time intervals where each interval is represented as `[start, end]`. You need to determine if a person can attend all the meetings without any overlap. Essentially, you are asked whether there are any overlaps between the meetings.

For example:

```python
Input: [[0, 30], [5, 10], [15, 20]]
Output: False
```

In this example, meetings overlap, so the output is `False`. If all meetings were non-overlapping, the output would be `True`.

## Brute Force Approach

A common brute force approach involves comparing each pair of meetings to see if there is any overlap. To do this, you could iterate through all intervals and for each interval, compare it with every other interval to check if they overlap.

Pseudo-code for brute force solution:

```python
for i in range(len(intervals)):
    for j in range(i + 1, len(intervals)):
        if intervals[i][1] > intervals[j][0] and intervals[i][0] < intervals[j][1]:
            return False
return True
```

This solution checks every possible pair of intervals for overlaps, which is inefficient as it has a time complexity of `O(N^2)`, where `N` is the number of intervals.

## Hint to Solve the Problem Efficiently

To solve this problem more efficiently, think about sorting the intervals by their start time. Once sorted, a single pass through the intervals is enough to check if any two consecutive meetings overlap. This way, you don't need to compare every pair, making the solution significantly faster.

## Efficient Solution

The efficient approach involves first sorting the intervals based on the start times and then iterating through the sorted list to check for overlaps. Here is the Python code for the solution, based on the provided code:

```python
# Function to determine if a person can attend all meetings
def can_attend_meetings(intervals):
    # Step 1: Sort the intervals by start time
    intervals.sort()
    
    # Step 2: Check for any overlap between consecutive meetings
    for i in range(1, len(intervals)):
        if intervals[i][0] < intervals[i - 1][1]:
            return False
            
    return True
```

In this solution, we first sort the intervals by their starting times. Then, we iterate through the sorted intervals to check if the start time of the current meeting is earlier than the end time of the previous meeting. If it is, we return `False`, indicating there is an overlap. If no overlaps are found, we return `True`.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(N log N)` due to the sorting step, where `N` is the number of intervals. The subsequent iteration through the intervals has a time complexity of `O(N)`, making the overall complexity `O(N log N)`.
    
* **Space Complexity**: The space complexity of this solution is `O(1)` if the sorting is done in-place. Otherwise, it is `O(N)` if the sorting requires additional space.
    

## Conclusion

The "Meeting Rooms" problem is a great example to illustrate the power of sorting in simplifying interval problems. While the brute force approach has quadratic complexity, sorting allows us to reduce the number of comparisons, making the solution much more efficient. By sorting and then performing a single scan, we can determine if a person can attend all the meetings without overlap, achieving an optimal solution with `O(N log N)` time complexity. Practice and master this approach, as similar interval-based problems often appear in technical interviews.

README for [Meeting Rooms (Leetcode #252)](https://blog.unwiredlearning.com/meeting-rooms) was compiled from the Unwired Learning Blog.  
//### 059 File: 0253-meeting-rooms-ii/README.md
# Meeting Rooms II (Leetcode #253)

Managing meeting schedules in a busy office can feel like a puzzle. Today, we'll explore how to solve one such puzzle using a problem from LeetCode: **Meeting Rooms II**. This problem is a classic example of optimal resource allocation in a constrained environment, and we will look into the brute force approach as well as a more efficient method for solving it.

## Understanding the Problem Statement

Imagine that you're given a list of meeting intervals with their start and end times, and you need to determine the minimum number of meeting rooms required to hold all the meetings. Each meeting has a start and end time, and meetings can overlap. Your task is to find out how many meeting rooms are needed at the peak.

For instance, if the input is:

```python
[[0, 30], [5, 10], [15, 20]]
```

The output should be `2`, as two rooms are needed to accommodate overlapping meetings.

## Brute Force Approach

A common way to approach this problem is to iterate through all possible combinations of meeting intervals and check for overlaps. For every meeting, you can iterate through all the other meetings and count how many overlap with the current one. This approach is not very efficient, as it involves nested loops that have a time complexity of `O(n^2)`. This is particularly inefficient when dealing with a large number of meetings, as every meeting is checked against every other one.

The brute force approach gives you an idea of what needs to be done—managing overlaps—but it's not suitable when performance is critical.

## Hint to Solve the Problem Efficiently

Instead of comparing every meeting with all others, consider sorting the meeting times and using a greedy approach to manage the allocation. Think of splitting the meetings into their start and end times and using pointers to track the usage of meeting rooms.

## Efficient Solution

The provided solution uses a technique involving sorting both the start and end times of the meetings:

```python
# Efficient Solution

def minMeetingRooms(intervals):
    # Separate and sort start and end times
    start_times = sorted(interval.start for interval in intervals)
    end_times = sorted(interval.end for interval in intervals)

    start_pointer, end_pointer = 0, 0
    used_rooms = 0
    max_rooms = 0

    # Iterate over start times
    while start_pointer < len(intervals):
        if start_times[start_pointer] < end_times[end_pointer]:
            # A new room is needed
            used_rooms += 1
            start_pointer += 1
        else:
            # A room is freed up
            used_rooms -= 1
            end_pointer += 1
        
        # Update the maximum number of rooms needed
        max_rooms = max(max_rooms, used_rooms)

    return max_rooms
```

In this approach, both the start and end times are sorted separately. Two pointers are used to keep track of the current meeting that is starting and the meeting that is ending. As we iterate through the sorted start times, we either need a new room (if a meeting starts before another ends), or we release a room when the current meeting ends.

**How This Works**

* **Step 1:** Sort the start and end times.
    
* **Step 2:** Use pointers to iterate through the start and end arrays.
    
* **Step 3:** Track the number of rooms being used. Whenever a meeting starts before another ends, a room is allocated; otherwise, a room is freed.
    
* **Step 4:** Update the maximum number of rooms needed during this process.
    

This approach allows you to efficiently manage room allocation without explicitly checking every pair of meetings.

## Time and Space Complexity

* **Time Complexity:** Sorting both the start and end times takes `O(n log n)` time. Iterating over the start times and end times has a linear complexity of `O(n)`. Hence, the overall time complexity is `O(n log n)`, which is optimal for this type of problem.
    
* **Space Complexity:** The space complexity is `O(n)` because we store the start and end times in separate arrays. There is also additional space required for sorting, but it remains efficient in practice.
    

## Conclusion

The 'Meeting Rooms II' problem helps illustrate the importance of an optimal approach in situations where resources are constrained. The brute force method is a good conceptual starting point, but leveraging sorted data and an efficient tracking mechanism allows for significantly better performance. Sorting start and end times and managing with pointers is a smart and clean way to solve this problem. Consider using these principles when faced with similar resource allocation challenges.

README for [Meeting Rooms II (Leetcode #253)](https://blog.unwiredlearning.com/meeting-rooms-ii) was compiled from the Unwired Learning Blog.  
//### 060 File: 0261-graph-valid-tree/README.md
# Graph Valid Tree (Leetcode 261)

In this blog, we will explore the problem of determining whether a given graph forms a valid tree, commonly known as Leetcode problem 261. We will discuss the problem statement, a brute force approach, provide hints for an efficient solution, and break down the optimal solution with detailed complexity analysis. By the end of this blog, you will have a clear understanding of how to solve this problem efficiently.

## Understanding the Problem Statement

The problem "Graph Valid Tree" is about determining whether a given graph represents a valid tree. You are provided with `n` nodes labeled from `0` to `n-1` and a list of edges connecting them. The goal is to determine if these nodes and edges form a valid tree.

A graph is considered a tree if:

1. All nodes are connected (there is a path between any two nodes).
    
2. The graph has no cycles.
    
3. The number of edges should be exactly `n - 1`, which is a necessary condition for a tree.
    

In this problem, the input consists of:

* `n` - an integer representing the number of nodes.
    
* `edges` - a list of pairs representing the connections between nodes.
    

The task is to return `True` if the graph forms a valid tree, otherwise `False`.

## Brute Force Approach

A brute force approach to solve this problem could involve checking if the graph is both fully connected and contains no cycles. You could iterate through every node and check for connectivity using multiple traversal methods like Breadth-First Search (BFS) or Depth-First Search (DFS), while also checking for cycles.

However, a key limitation of such an approach is its inefficiency, particularly in cycle detection, as you might end up visiting nodes multiple times and creating unnecessary overhead.

## Hint to Solve the Problem Efficiently

The efficient solution involves using both a DFS and a key observation about the structure of trees: a valid tree must have exactly `n - 1` edges. If the number of edges is not `n - 1`, it is impossible for the graph to be a tree. You can use an adjacency list to represent the graph, and a DFS traversal to ensure there are no cycles and that all nodes are connected.

## Efficient Solution

Below is the efficient solution code that was provided:

```python
    def validTree(n, edges):
        # Check for the necessary condition of a tree (n-1 edges)
        if len(edges) != n - 1:  
            return False
        
        # Create an adjacency list
        graph = {i: [] for i in range(n)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = set()
        
        def dfs(node, parent):
            if node in visited:
                return False
            visited.add(node)
            
            for neighbor in graph[node]:
                # Ignore the edge leading back to the parent
                if neighbor == parent:  
                    continue
                
                # Attempt to visit each neighboring node using DFS.
                path_is_clear = dfs(neighbor, node)
                if path_is_clear is False:
                    return False
            
            return True
        
        # Start DFS from node 0; Check if it's fully connected and has no cycle
        return dfs(0, -1) and len(visited) == n
```

**Explanation of the Solution**

1. **Edge Count Check**: The first step is to verify if the number of edges is equal to `n - 1`. If not, it is not possible for the graph to be a valid tree.
    
2. **Graph Representation**: The graph is represented using an adjacency list, where each node points to its neighbors. This is efficient for traversal.
    
3. **DFS for Connectivity and Cycle Detection**: The `dfs` function is used to traverse the graph.
    
    * It checks if a node has already been visited, which indicates a cycle.
        
    * The DFS is initiated from node `0`, and we ignore the edge that leads back to the parent.
        
    * During the traversal, if a cycle is detected or if any node is unreachable, the function returns `False`.
        
4. **Final Validation**: Finally, the function returns `True` only if all nodes are visited (i.e., the number of visited nodes equals `n`). This ensures the graph is fully connected and free of cycles.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity is `O(N + E)`, where `N` is the number of nodes and `E` is the number of edges. This is because we traverse all nodes and edges during the DFS.
    
* **Space Complexity**: The space complexity is `O(N)` due to the adjacency list and the `visited` set. The recursion stack for DFS also takes up space in the worst case, which is proportional to `O(N)` in the case of a fully connected graph.
    

## Conclusion

In conclusion, solving the "Graph Valid Tree" problem requires understanding the fundamental properties of a tree, such as the edge count and connectivity. By leveraging depth-first search (DFS) and an adjacency list, we can efficiently determine if the given graph is a valid tree. Remember, ensuring that the graph has exactly `n - 1` edges is the first critical step, followed by checking for cycles and full connectivity. This solution provides an optimal way to solve the problem within acceptable time and space complexity limits.


README for [Graph Valid Tree (Leetcode 261)](https://blog.unwiredlearning.com/graph-valid-tree) was compiled from the Unwired Learning Blog.  
//### 061 File: 0268-missing-number/README.md
# Missing Number (Leetcode #268)

Leetcode's 268. Missing Number is a common problem faced by software engineers, testing their problem-solving skills and ability to optimize solutions. This blog aims to help you solve the Missing Number problem efficiently, providing insights into both a brute-force and an optimal solution. Whether you're preparing for an interview or just improving your coding skills, this guide will walk you through the concepts in an easy-to-understand way.

## Understanding the Problem Statement

The Missing Number problem asks you to find a missing element from a given list of integers, ranging from 0 to *n*. The list is of length *n* and contains *n* unique numbers, meaning that exactly one number from the complete range of 0 to *n* is missing. Your task is to determine which number is absent.

For example:

* **Input:** nums = \[3, 0, 1\]
    
* **Output:** 2
    

In this case, the numbers range from 0 to 3 (inclusive), and we notice that the number 2 is missing from the input array.

## Brute Force Approach

A common approach to solve this problem is to compare the sum of numbers in the given array to the sum of numbers from 0 to *n*. The sum of the first *n* natural numbers can be found using the formula:

**Sum(0 to n) = n \* (n + 1) / 2**

You can then iterate through the given array to compute the sum of its elements and find the difference between the expected sum and the actual sum. This difference will give you the missing number.

**Steps for Brute Force Approach:**

1. Calculate the expected sum using the formula.
    
2. Calculate the sum of all elements in the given array.
    
3. The difference between the expected sum and the actual sum is the missing number.
    

**Drawbacks:** Although this approach is easy to understand and implement, it requires an additional iteration over the list and an extra arithmetic operation, leading to a time complexity of **O(n)** and a space complexity of **O(1)**.

## Hint to Solve the Problem Efficiently

If you're familiar with bit manipulation, you might already know that XOR can be extremely helpful in solving problems related to pairing elements. The XOR operator allows us to efficiently cancel out matching numbers while keeping the unique number isolated. The provided code takes advantage of this characteristic to find the missing number in a single iteration.

## Efficient Solution

The provided solution makes use of the XOR operation to solve this problem efficiently in just one pass. Let's take a closer look at the code:

```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        xor = 0
        n = len(nums)

        # XOR all indices and all elements in nums
        for i in range(n):
            xor = xor ^ i ^ nums[i]

        # Finally XOR with n (since the range is from 0 to n)
        xor = xor ^ n

        return xor
```

In this solution, we initialize `xor` as 0 and iterate through the array. During each iteration, we XOR the current index `i` and the element at that index, `nums[i]`, with `xor`. After the loop completes, we also XOR `xor` with `n` (since the complete range is from 0 to *n*). This operation will cancel out all the numbers that appear twice, leaving only the missing number.

**Example Walkthrough:**

* Consider `nums = [3, 0, 1]`. Here, `n` is 3.
    
* During the loop, we XOR as follows:
    
    * `xor = 0 ^ 0 ^ 3 = 3`
        
    * `xor = 3 ^ 1 ^ 0 = 2`
        
    * `xor = 2 ^ 2 ^ 1 = 3`
        
* After the loop, XOR with `n`: `xor = 3 ^ 3 = 2`
    
* The missing number is 2.
    

## Time and Space Complexity

**Time Complexity:**

* The solution runs in **O(n)** time, as it involves a single pass through the array of length *n*. Each XOR operation takes constant time, leading to an efficient linear runtime.
    

**Space Complexity:**

* The space complexity is **O(1)** since no extra data structures are used and only a constant amount of additional memory is required.
    

## Conclusion

The Missing Number problem is an excellent example of how bit manipulation can help simplify and optimize solutions. While the brute-force approach is straightforward, the XOR method offers a more elegant and efficient solution. If you ever face problems where pairs of elements cancel each other out, XOR is a tool worth considering.

Mastering these techniques will help you tackle similar problems in coding interviews and expand your toolbox of efficient coding strategies. Give it a try and see how the XOR approach works in other scenarios!

README for [Missing Number (Leetcode #268)](https://blog.unwiredlearning.com/missing-number) was compiled from the Unwired Learning Blog.  
//### 062 File: 0269-alien-dictionary/README.md
# Alien Dictionary (Leetcode 269)

The Alien Dictionary problem is a challenging yet fascinating problem that involves determining the order of characters in an alien language based on the lexicographical order of words provided. In this blog, we will walk through the problem statement, explore a brute force approach, provide a hint for solving it efficiently, and ultimately dive into an optimal solution using graph theory.

## Understanding the Problem Statement

The Alien Dictionary problem presents a list of words from an unknown language, and your task is to determine the alphabet order of the characters in that language. You are given an ordered list of words and must derive the correct order of letters based on the differences between consecutive words.

The catch is that, since the words are sorted lexicographically in the alien language, you must infer the relative order of characters based on the provided list. Essentially, it’s similar to deriving an ordering for the characters that respect their relationships in a given dictionary.

The problem is analogous to creating a topological order for nodes in a graph, where nodes represent letters and directed edges represent their relative order.

## Brute Force Approach

A common brute-force approach would be to generate every possible permutation of the characters in the given list of words and check if each permutation satisfies the ordering constraints derived from the word list. This involves generating all possible character orders, then verifying if each order respects the given order in the words list. However, this approach is computationally impractical because the number of permutations grows factorially with the number of distinct characters, making it extremely inefficient for larger inputs.

## Hint to Solve the Problem Efficiently

Instead of generating all possible orders, think of this problem as a graph traversal problem. Each character in the language can be thought of as a node in a directed graph, and edges represent the precedence between characters based on the order of the given words. You can perform a Depth First Search (DFS) on the graph to obtain a valid character order while detecting any cycles that would make the ordering impossible.

## Efficient Solution

The efficient solution involves breaking down the problem into three main steps:

1. **Create the Graph**: Iterate through the list of words and compare adjacent words to determine character precedence. Each character is a node, and an edge between two nodes (characters) represents that one character must come before the other.
    
    ```python
    adj = {c: set() for word in words for c in word}
    
    for i in range(len(words) - 1):
        word1, word2 = words[i], words[i + 1]
        minLen = min(len(word1), len(word2))
        
        # Handle the case where order is impossible.
        if len(word1) > len(word2) and word1[:minLen] == word2[:minLen]:
            return ""  
        
        for j in range(minLen):
            if word1[j] != word2[j]:
                adj[word1[j]].add(word2[j])
                break
    ```
    
2. **Detect Cycles and Perform DFS**: To determine a valid ordering, perform a Depth First Search (DFS) on each character. During the DFS, track visited nodes to detect cycles, as cycles imply an impossible ordering. Use a dictionary to mark each node as visited (False for visiting, True for processed).
    
    ```python
    visited = {}  # False = visited but not processed, True = processed.
    order = []
    
    def dfs(c):
        if c in visited:
            return visited[c]  # If True, no cycle; if False, cycle detected.
        visited[c] = False
        for nei in adj[c]:
            if dfs(nei) == False:
                return False  # Cycle detected.
        visited[c] = True
        order.append(c)
        return True
    
    for c in adj:
        if c not in visited:
            if not dfs(c):
                return ""  # Cycle detected.
    ```
    
3. **Return the Result**: After the DFS traversal, the characters are appended in reverse post-order. Thus, we reverse the list to get the correct character order.
    
    ```python
    return "".join(order[::-1])
    ```
    

## Time and Space Complexity

* **Time Complexity**: The solution involves creating a graph with `O(N * M)` complexity, where `N` is the number of words and `M` is the average length of the words. Additionally, the DFS traversal runs in `O(V + E)` time, where `V` is the number of vertices (distinct characters) and `E` is the number of edges (precedence relations). Overall, the time complexity is `O(N * M + V + E)`, which is efficient compared to the brute-force approach.
    
* **Space Complexity**: The space complexity is `O(V + E)` due to storing the graph representation and the visited dictionary. The graph stores each character as a node and the relations as edges, resulting in linear space usage relative to the input size.
    

## Conclusion

The Alien Dictionary problem is a great way to understand graph traversal concepts and topological sorting. By representing characters as nodes and their relationships as directed edges, we can solve the problem using an efficient graph-based approach. Although the brute-force solution is impractical, the DFS-based solution provides a clear path to determining the character order while handling edge cases like cycles. Understanding these fundamental graph algorithms can be highly beneficial for tackling a wide range of similar problems in computer science.


README for [Alien Dictionary (Leetcode 269)](https://blog.unwiredlearning.com/alien-dictionary) was compiled from the Unwired Learning Blog.  
//### 063 File: 0295-find-median-from-data-stream/README.md
# Find Median from Data Stream (Leetcode #295)

In this blog, we will discuss the brute force approach, provide hints for solving the problem efficiently, and dive into an optimal solution using a combination of Trie and DFS.

## Understanding the Problem Statement

Word Search II (Leetcode 212) is a popular backtracking problem where you're given a 2D board of letters and a list of words. The goal is to find all words from the list that exist in the board, where each word must be formed by sequentially adjacent letters (either horizontally or vertically), without reusing the same cell twice.

## Brute Force Approach

In the brute force approach, you would start by iterating over each cell in the board and attempting to find each word starting from that particular cell. This typically involves exploring all possible directions to try and match each character of a word. While easy to understand, this approach suffers from severe inefficiency as the same searches are repeated for each word, resulting in an exponential time complexity. As the board and word list grow, the brute force method becomes impractical due to high computational costs.

## Hint to Solve the Problem Efficiently

The provided solution involves using a **Trie** (prefix tree) to optimize the search process. A Trie is built to efficiently store and look up the words from the given list, which helps in reducing redundant searches during the depth-first traversal of the board. The combination of the Trie and Depth-First Search (DFS) drastically improves the performance, especially when dealing with large boards and numerous words.

## Efficient Solution

To efficiently solve the problem, we combine **DFS** and a **Trie** to minimize redundant computations and speed up the word search. Below is the efficient solution from the provided code:

1. **Building the Trie**: The `buildTrie` function takes the given list of words and constructs a Trie. Each node of the Trie represents a character, and the Trie as a whole represents all the words. This allows for quick lookups when attempting to match a word starting from any cell on the board.
    
2. **DFS for Word Search**: The `dfs` function performs depth-first search on the board, starting from any character that matches the root of the Trie. As each character is found, it moves deeper into the Trie, and ultimately, if a word is found, it is added to the result.
    
3. **Marking Visited Cells**: During the DFS, cells are marked as visited by temporarily changing their value. This avoids revisiting cells within the same path. After the DFS is complete, the cells are restored to their original values to maintain board integrity.
    
4. **Avoiding Duplicates**: Once a word is found, it is added to the result set and marked as found in the Trie to avoid duplicate entries in the final result.
    

Here's a summary of the approach used:

* **Trie Construction**: Efficiently represents words for quick lookup.
    
* **DFS Search**: Explores possible words starting from each board cell, backtracking as needed.
    
* **Result Set**: Keeps track of found words to avoid duplicates.
    

## Time and Space Complexity

**Time Complexity**: The solution has an average complexity of **O(M × N × 4^L)**, where **M** is the number of rows, **N** is the number of columns in the board, and **L** is the length of the longest word. The Trie lookup and pruning of search space help reduce unnecessary computations, making the solution much more efficient compared to a brute-force search.

**Space Complexity**: The space complexity is **O(W × L + M × N)**, where **W** is the number of words and **L** is the average length of the words. This includes space for storing the Trie as well as the recursion stack used during the DFS traversal. While the Trie structure can be memory-intensive, it is a necessary trade-off for the significant speed-up in search performance.

## Conclusion

Word Search II is a challenging problem that requires an optimized approach to handle large boards and multiple words efficiently. By combining the Trie data structure with depth-first search, we can significantly reduce redundant operations and speed up the word search process. This efficient solution not only highlights the power of combining different algorithms but also serves as a great exercise in improving the time complexity of typical brute-force approaches. With a solid understanding of Trie and DFS, solving complex word search problems becomes much more manageable.


README for [Find Median from Data Stream (Leetcode #295)](https://blog.unwiredlearning.com/find-median-from-data-stream) was compiled from the Unwired Learning Blog.  
//### 064 File: 0297-serialize-and-deserialize-binary-tree/README.md
# Serialize and Deserialize Binary Tree (Leetcode #297)

Let's dive into the solution for Leetcode's problem 297, "Serialize and Deserialize Binary Tree," covering all aspects from understanding the question to efficient code explanations.

## Understanding the Problem Statement

The problem asks us to design an algorithm to serialize and deserialize a binary tree. In simpler terms:

1. **Serialize**: Convert a binary tree to a string representation.
    
2. **Deserialize**: Convert the string back to its original binary tree structure.
    

The problem is essentially about converting the binary tree into a string (serialization) and then reconstructing it from that string (deserialization). The objective is to ensure that you can perfectly reconstruct the original tree from the serialized data.

## Brute Force Approach

A common brute force approach for this problem might be to use an in-order or pre-order traversal of the tree to record node values. For instance:

* Traverse each node of the binary tree, storing the values in an array or string.
    
* Include special symbols to represent `null` values, which can help distinguish between different shapes of the tree.
    

However, this method has its limitations:

* It doesn't always capture the full tree structure.
    
* It may require additional work to keep track of missing nodes.
    
* Handling a binary tree's hierarchical nature in a linear format can be cumbersome.
    

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, think in terms of **Breadth-First Search (BFS)**, which will allow you to traverse the tree level by level. This approach ensures that all nodes are visited in the correct order, and you can easily capture `null` children with a placeholder (like `"N"` in our solution). The use of a queue data structure will help manage the nodes during traversal.

## Efficient Solution

The provided code utilizes a **BFS approach** to serialize and deserialize the binary tree. Let's break down each part of the solution.

**Serialization**

The `serialize` function converts the binary tree into a single string.

* **BFS Traversal**: Starting from the root, we traverse level by level.
    
* **Queue Management**: A queue is used to manage nodes at each level.
    
* **Null Nodes**: If a node is `None`, we add `"N"` to represent it. Otherwise, we add the node's value and push its children to the queue.
    
* **String Construction**: The values are joined with commas to form the final string representation.
    

**Code for Serialization:**

```python
pythonCopy codedef serialize(self, root):
    if not root:
        return ""
    queue = [root]
    result = []
    while queue:
        node = queue.pop(0)
        if node:
            result.append(str(node.val))
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append("N")
    return ",".join(result)
```

In this approach:

* Nodes are stored sequentially in a string.
    
* `N` is used to represent `None` nodes, ensuring that we capture the exact structure.
    

**Deserialization**

The `deserialize` function reconstructs the binary tree from the string representation.

* **Data Splitting**: The string is split by commas to get individual node values.
    
* **Queue Management**: We use a queue to manage the tree construction.
    
* **Node Reconstruction**: Starting from the root, we reconstruct the left and right children for each node using BFS.
    

**Code for Deserialization:**

```python
pythonCopy codedef deserialize(self, data):
    if not data:
        return None
    values = data.split(",")
    root = TreeNode(int(values[0]))
    queue = [root]
    i = 1
    while queue:
        node = queue.pop(0)
        if values[i] != "N":
            node.left = TreeNode(int(values[i]))
            queue.append(node.left)
        i += 1
        if values[i] != "N":
            node.right = TreeNode(int(values[i]))
            queue.append(node.right)
        i += 1
    return root
```

Here:

* The string is split to reconstruct individual nodes.
    
* The BFS approach is used again to construct the tree level by level, ensuring that each node is appropriately linked.
    

## Time and Space Complexity

* **Time Complexity**: Both serialization and deserialization have a time complexity of **O(N)**, where `N` is the number of nodes in the binary tree. This is because each node is visited exactly once during both processes.
    
* **Space Complexity**: The space complexity is also **O(N)**, where `N` is the number of nodes in the binary tree. This is due to:
    
    * The space required to store the serialized output.
        
    * The queue used in both serialization and deserialization to manage nodes.
        

## Conclusion

This BFS-based approach is efficient and ensures that the serialized data retains all structural information necessary for perfect reconstruction. It uses a queue to systematically traverse and manage the nodes, making the solution straightforward and effective.

If you have any questions or need further clarification, feel free to reach out!


README for [Serialize and Deserialize Binary Tree(Leetcode #297)](https://blog.unwiredlearning.com/serialize-and-deserialize-binary-tree) was compiled from the Unwired Learning Blog.  
//### 065 File: 0300-longest-increasing-subsequence/README.md
# Longest Increasing Subsequence (Leetcode #300)

The 'Longest Increasing Subsequence' problem is a common question that appears in coding interviews and technical assessments, particularly on platforms like LeetCode. This problem tests your understanding of dynamic programming and how to efficiently manage sequences within arrays. In this blog, we will walk through the question itself, discuss the brute-force solution, provide hints, and finally introduce an efficient solution along with the time and space complexity. If you're looking to master this problem, keep reading!

## Understanding the Problem Statement

The question asks you to find the length of the **longest increasing subsequence** in an array of integers. A subsequence is derived by deleting zero or more elements without changing the order of the remaining elements. The task is to return the length of the longest subsequence where each element is greater than the one before it.

For example:

```python
Input: nums = [10, 9, 2, 5, 3, 7, 101, 18]
Output: 4
Explanation: The longest increasing subsequence is [2, 3, 7, 101], which has a length of 4.
```

## Brute Force Approach

A simple, brute-force way to solve this problem would involve generating all possible subsequences, checking each one to determine if it's increasing, and then finding the length of the longest among them. However, this approach has an exponential time complexity of **O(2^n)**, since we are looking at all possible combinations of elements. This method is computationally expensive and impractical for larger arrays.

## Hint to Solve the Problem Efficiently

To solve this problem more efficiently, we need a strategy to keep track of previously computed results and use them for future calculations. The solution provided in the code makes use of **dynamic programming (DP)** to store the length of the increasing subsequence ending at each element.

The idea is to use a DP array where each index represents the length of the longest increasing subsequence ending at that position. By leveraging previously computed values, we can efficiently build up the solution in a single pass through the array.

## Efficient Solution

Here is an efficient dynamic programming approach to solve the problem, as given in the attached solution code:

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        dp = [1 for _ in range(len(nums))]
        max_length = 1

        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
                    max_length = max(max_length, dp[i])
        
        return max_length
```

In this solution:

* **Initialization**: We create a **dp** array with the same length as the input array, where each element is initialized to **1**. This is because the minimum length of an increasing subsequence containing just one element is **1**.
    
* **Nested Loop**: We iterate through the array with two loops. For each element at index **i**, we compare it with every previous element at index **j**.
    
* **Updating DP**: If the current element **nums\[i\]** is greater than **nums\[j\]**, it means we can extend the increasing subsequence ending at **j** by including **i**. Thus, **dp\[i\]** is updated as **max(dp\[i\], dp\[j\] + 1)**.
    
* **Result**: The value **max\_length** keeps track of the maximum length of the subsequence encountered so far.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity for this solution is **O(n^2)**, where **n** is the length of the input array. This is due to the nested loop where each element is compared with every previous element.
    
* **Space Complexity**: The space complexity is **O(n)** because we use an additional array of size **n** to store the length of the subsequence ending at each element.
    

## Conclusion

The 'Longest Increasing Subsequence' problem is a classic example where a brute-force solution might seem intuitive at first but is not feasible for larger inputs. Using dynamic programming allows us to significantly optimize the solution and make it practical for real-world applications. Mastering such problems helps in understanding the core concepts of dynamic programming, which is a crucial part of many technical interviews.

Give this problem a try, and remember, practice makes perfect when it comes to mastering dynamic programming techniques!

README for [Longest Increasing Subsequence (Leetcode #300)](https://blog.unwiredlearning.com/longest-increasing-subsequence) was compiled from the Unwired Learning Blog.  
//### 066 File: 0322-coin-change/README.md
# Coin Change (Leetcode 322)

The Coin Change problem is a fundamental question in computer science and is widely used to understand dynamic programming concepts. This blog will guide you through the problem, different approaches to solve it, and explain an efficient solution step by step.

## Understanding the Problem Statement

The **Coin Change** problem is a classic question in dynamic programming. Given an array of different denominations of coins and a target amount, the objective is to determine the minimum number of coins needed to make up that amount. If it is impossible to make the target amount using the given coins, you need to return -1.

For example, suppose you have coins with denominations `[1, 2, 5]` and an amount of `11`. The expected result would be `3`, as the optimal solution is `5 + 5 + 1`.

This problem is common in financial scenarios where you need to determine the fewest number of currency units required to make up a given value.

## Brute Force Approach

In a brute-force solution, the idea is to consider all possible combinations of coins and recursively explore every possible way to form the target amount. In this approach, you check each coin and recursively subtract it from the target amount, until either a valid combination is found or it becomes impossible.

The brute-force approach can be implemented with the following logic:

1. Start with the target amount.
    
2. Try every coin in the list by subtracting its value from the target amount.
    
3. Recur with the remaining amount.
    
4. Return the minimum number of coins used from all possible combinations.
    

This solution becomes extremely inefficient as the target amount and the number of coin denominations increase, leading to an exponential time complexity due to repeated calculations.

## Hint to Solve the Problem Efficiently

Instead of recalculating results repeatedly for the same subproblems, think about how to store and reuse previous results. This concept is key to reducing the computational overhead in dynamic programming. The code provided uses a **bottom-up dynamic programming approach** to solve the problem efficiently.

## Efficient Solution

The provided code uses a **dynamic programming** technique to solve the Coin Change problem in a more efficient way. Here's the approach:

1. **Initialization**: Create an array `dp` of length `amount + 1` where each element represents the minimum number of coins needed to achieve that amount. Initially, set every element to a value greater than the possible number of coins (`amount + 1`), as a way to signify that those amounts are initially unreachable. Set `dp[0] = 0` because zero coins are required to achieve an amount of zero.
    
2. **Iterate through Each Amount**: For each amount `i` from `1` to `amount`, iterate over each coin in the `coins` list.
    
    * If the current coin value is less than or equal to `i`, update `dp[i]` with the minimum value between `dp[i]` and `dp[i - coin] + 1`. This indicates that you are trying to find the optimal way to make up the current amount by adding one more coin to a previously calculated value.
        
3. **Return the Result**: After filling the `dp` array, the final answer will be in `dp[amount]`. If the value is still `amount + 1`, it means that it is impossible to form the amount with the given coins, so return `-1`. Otherwise, return `dp[amount]`.
    

Here is the provided code:

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        # No solution exists, return -1.
        if dp[amount] == amount + 1:
            return -1  
        
        return dp[amount]
```

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(amount \* n)**, where `amount` is the target value and `n` is the number of different coin denominations. This is because we iterate over all values from `1` to `amount` and, for each value, we iterate over all the coin denominations.
    
* **Space Complexity**: The space complexity is **O(amount)**. This is due to the use of the `dp` array, which stores the minimum number of coins required for each amount from `0` to `amount`.
    

By using dynamic programming, we eliminate the need for repeated calculations, leading to an optimal solution for large input values. The use of the `dp` array helps in storing previous results and significantly reduces the number of operations needed to compute the answer.

## Conclusion

The Coin Change problem is an excellent example of how dynamic programming can be used to solve problems involving optimization. While the brute force approach can be highly inefficient, using a dynamic programming solution drastically reduces the time complexity by storing and reusing results of overlapping subproblems. This bottom-up approach is both intuitive and effective for solving similar problems, making it a valuable tool in any programmer's toolkit. Understanding this problem can greatly enhance your skills in dynamic programming and problem-solving in general.


README for [Coin Change (Leetcode 322)](https://blog.unwiredlearning.com/coin-change) was compiled from the Unwired Learning Blog.  
//### 067 File: 0323-number-of-connected-components-in-an-undirected-graph/README.md
# Number of Connected Components in an Undirected Graph (Leetcode 323)

In this blog, we will explore how to determine the number of connected components in an undirected graph. Understanding connected components is crucial for analyzing the structure of a graph and solving many graph-related problems. We'll start by breaking down the problem, discussing a brute force approach, and then dive into an efficient solution using Depth-First Search (DFS).

## Understanding the Problem Statement

The problem requires determining how many connected components are present in an undirected graph. Given a number of nodes (from `0` to `n-1`) and a list of edges between them, a connected component is a set of nodes where there is a path between any pair of nodes within that set. The graph may be made up of multiple disjoint subgraphs, and we want to identify how many such connected subgraphs exist.

For example, imagine a graph with `n = 5` nodes, with edges between nodes `0-1` and `2-3`. Here, there are three connected components: `0-1`, `2-3`, and `4` (node `4` is isolated).

## Brute Force Approach

A brute force approach to solving this problem would involve treating each node as the starting point and performing a traversal, such as Depth-First Search (DFS) or Breadth-First Search (BFS), to identify all reachable nodes. Each time we discover a new set of nodes that haven’t been visited before, we can count it as a new component.

The brute force approach would essentially involve starting a traversal from every node and keeping track of visited nodes. The time complexity for this approach, given the repeated traversals, can be quite high, making it inefficient for larger graphs.

## Hint to Solve the Problem Efficiently

The key to optimizing this problem is to avoid redundant traversals by keeping track of visited nodes efficiently. Instead of starting from each node multiple times, we can start from each unvisited node only, marking all reachable nodes in a single traversal. This way, we ensure that each node is visited exactly once, reducing the computational overhead.

## Efficient Solution

The provided code offers a more efficient solution by leveraging DFS to identify connected components. Here's a step-by-step breakdown:

1. **Graph Representation**: The graph is represented as an adjacency list, where each node points to a list of its neighbors. This allows efficient traversal.
    
    ```python
    graph = {i: [] for i in range(n)}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    ```
    
2. **DFS Function**: The DFS function is defined to explore all nodes connected to a given starting node. It marks nodes as visited to prevent reprocessing.
    
    ```python
    def dfs(node):
        if visited[node]:
            return
        visited[node] = True
        for neighbor in graph[node]:
            dfs(neighbor)
    ```
    
3. **Counting Components**: We iterate over all nodes, and each time we find an unvisited node, we initiate a DFS traversal from that node, marking all reachable nodes. Each such initiation corresponds to finding a new connected component.
    
    ```python
    visited = [False] * n
    components = 0
    for i in range(n):
        if not visited[i]:
            dfs(i)
            components += 1
    return components
    ```
    

This solution ensures that each node and edge is processed only once, resulting in improved efficiency.

## Time and Space Complexity

* **Time Complexity**: The time complexity of the efficient solution is **O(n + e)**, where `n` is the number of nodes and `e` is the number of edges. This is because each node is visited once, and each edge is traversed twice (once from each endpoint).
    
* **Space Complexity**: The space complexity is **O(n + e)** as well, due to the storage requirements of the adjacency list and the visited array. The recursion stack for DFS can also add to the space complexity in the worst case.
    

This efficient approach ensures that the graph is processed with minimal overhead, making it suitable for larger graphs.

## Conclusion

To summarize, determining the number of connected components in an undirected graph can be approached in multiple ways. The brute force method may be easy to understand but is inefficient for larger graphs. Using an optimized DFS approach allows us to solve the problem efficiently, with a time complexity of **O(n + e)**. Understanding these concepts and applying efficient graph traversal techniques can help solve a wide range of graph-related problems effectively.


README for [Number of Connected Components in an Undirected Graph (Leetcode 323)](https://blog.unwiredlearning.com/number-of-connected-components-in-an-undirected-graph) was compiled from the Unwired Learning Blog.  
//### 068 File: 0338-counting-bits/README.md
# Counting Bits (Leetcode #338)

Leetcode's "Counting Bits" problem is a fascinating challenge that tests our understanding of binary numbers and efficient problem-solving. In this blog, we will walk through the problem, explore a common brute-force approach, and then provide you with a hint to solve it efficiently. We'll conclude by explaining an optimal solution step-by-step and analyzing its time and space complexity.

## Understanding the Problem Statement

In the "Counting Bits" problem (Leetcode 338), we are given a non-negative integer `n`, and the task is to return an array `ans` of length `n + 1`, where `ans[i]` is the number of `1` bits in the binary representation of the number `i`. Essentially, you need to count the number of `1`s (also known as set bits) for each number from `0` to `n` and return all those counts in an array.

For example:

* **Input**: `n = 5`
    
* **Output**: `[0, 1, 1, 2, 1, 2]`
    
* **Explanation**: The binary representations are `0 -> 0`, `1 -> 1`, `2 -> 10`, `3 -> 11`, `4 -> 100`, `5 -> 101`. Hence, the counts of set bits are `0, 1, 1, 2, 1, 2` respectively.
    

## Brute Force Approach

A straightforward way to solve this problem is to iterate through each number from `0` to `n` and count the number of `1`s in its binary representation. This can be done by repeatedly shifting the bits of each number and counting how many bits are set. Here is a brief explanation of the brute-force approach:

1. Create an empty list to store the counts.
    
2. Loop through each number from `0` to `n`.
    
3. For each number, use bitwise operations to count the `1` bits.
    
4. Append the count to the result list.
    

However, the brute force approach is not efficient for larger values of `n`, as it requires a significant amount of computation for each number, leading to a higher time complexity.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, we can leverage the properties of binary representation. Notice that if `i` is even, its set bits are equal to the set bits of `i // 2`. If `i` is odd, its set bits are one more than the set bits of `i // 2`. This observation allows us to compute the number of set bits in constant time for each number based on the previously computed values.

## Efficient Solution

The provided code takes advantage of the above observation to efficiently solve the problem. Here is the code and an explanation of how it works:

```python
class Solution:
    def countBits(self, n: int) -> List[int]:
        # Initialize a list to store the result
        result = [0] * (n + 1)
        
        # If n is 0, simply return the result list (which is [0])
        if n == 0:
            return result
        
        # The number of 1's in the binary representation of 1 is 1
        result[1] = 1
        
        # Loop through numbers from 2 to n
        for i in range(2, n + 1):
            if i % 2 == 0:
                result[i] = result[i // 2]
            else:
                result[i] = result[i // 2] + 1
        
        return result
```

**Explanation**:

1. **Initialization**: We initialize a list `result` of size `n + 1` with all values set to `0`.
    
2. **Base Cases**: If `n` is `0`, we directly return `[0]`. We also set `result[1] = 1` since `1` has one set bit.
    
3. **Loop through** `2` **to** `n`: For each number `i`, we determine the number of set bits based on whether `i` is even or odd:
    
    * If `i` is even, `result[i] = result[i // 2]`.
        
    * If `i` is odd, `result[i] = result[i // 2] + 1`.
        

This approach is efficient because it calculates each value in constant time using previously computed values, resulting in an optimal solution.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(n)` since we iterate through all numbers from `0` to `n`, and each computation takes constant time.
    
* **Space Complexity**: The space complexity is `O(n)` due to the additional space needed to store the result array of size `n + 1`.
    

## Conclusion

The "Counting Bits" problem is a great way to understand the efficiency of dynamic programming and the power of using previously computed results to optimize the solution. By recognizing patterns in the binary representation of numbers, we are able to achieve an efficient `O(n)` solution instead of the costly brute-force approach. This problem also emphasizes the importance of recognizing subproblems and utilizing existing results for more efficient computation.

README for [Counting Bits (Leetcode #338)](https://blog.unwiredlearning.com/counting-bits) was compiled from the Unwired Learning Blog.  
//### 069 File: 0347-top-k-frequent-elements/README.md
# Top K Frequent Elements (Leetcode #347)

In this blog, we will explore how to solve the Leetcode problem '347. Top K Frequent Elements.' We'll begin by understanding the problem, move through a common brute force approach, provide a hint to guide you towards the efficient solution, and finally explain the efficient solution in detail.

## Understanding the Problem Statement

The problem requires finding the **k most frequent elements** in a given list of integers. Given an integer array `nums` and an integer `k`, you need to return the `k` elements that appear most frequently. If there are multiple valid answers, any of them can be returned.

For example:

* **Input**: `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`
    
* **Output**: `[1, 2]`
    

The goal is to find the elements that occur most frequently in the given list and return exactly `k` such elements.

## Brute Force Approach

A common brute force approach to solving this problem would be:

1. **Count the Frequency**: Iterate through the list and count the frequency of each element. You could use a dictionary or a list to store the counts of each unique element.
    
2. **Sort by Frequency**: After counting, you would need to sort the unique elements by their frequency in descending order.
    
3. **Select Top K Elements**: Finally, select the top `k` elements from the sorted list.
    

This brute force method is simple but inefficient for large lists. Sorting the entire list based on frequency takes `O(n log n)` time, where `n` is the number of unique elements. In addition, counting the frequency takes `O(n)` time, making the entire approach fairly slow for large datasets.

## Hint to Solve the Problem Efficiently

To solve the problem more efficiently, consider using a **heap data structure**. The idea is to maintain the top `k` frequent elements without sorting the entire frequency list, which is where heaps come in handy.

The efficient solution consists of:

* Using a **dictionary** to count the frequencies of each element.
    
* Utilizing a **heap** to efficiently keep track of the `k` most frequent elements.
    

This approach helps reduce the time complexity significantly compared to the brute force approach.

## Efficient Solution

Let's dive into the efficient solution, following the code provided:

```python
from collections import Counter
import heapq

def topKFrequent(nums, k):
# Step 1: Count the frequency of each element
count = Counter(nums)  # O(n) time complexity

# Step 2: Use a heap to find the k most frequent elements
return heapq.nlargest(k, count.keys(), key=count.get)  # O(n log k) time complexity
```

**Step-by-Step Explanation**:

1. **Count Frequencies**: We use Python's `Counter` from the `collections` module to count the occurrences of each element in the list `nums`. This step takes `O(n)` time, where `n` is the number of elements in the list.
    
    ```python
    count = Counter(nums)  # count will be a dictionary-like object with frequencies
    ```
    
2. **Use a Heap**: After counting the frequencies, we use the `heapq.nlargest()` function to find the `k` most frequent elements. This function returns the `k` largest elements from the iterable based on a key function, which in this case is `count.get` to access the frequency of each element. Using a heap here allows us to maintain the top `k` elements efficiently without sorting the entire frequency list.
    
    ```python
    return heapq.nlargest(k, count.keys(), key=count.get)
    ```
    
    The use of `heapq.nlargest()` has a time complexity of `O(n log k)`, which is much more efficient than sorting the entire list.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of the solution is `O(n log k)`.
    
    * Counting the frequencies takes `O(n)` time.
        
    * Using the heap to extract the `k` most frequent elements takes `O(n log k)` time.
        
    * Therefore, the overall time complexity is dominated by `O(n log k)`.
        
* **Space Complexity**: The space complexity is `O(n)`. We require space for storing the frequency counts in a dictionary (`Counter`). The heap can take up to `k` space, but since `k <= n`, the space required is effectively `O(n)`.
    

## Conclusion

The efficient solution to finding the top `k` frequent elements leverages Python's `Counter` to count the occurrences of elements and `heapq.nlargest()` to retrieve the most frequent elements efficiently. This approach is particularly beneficial when dealing with larger datasets, as it reduces the need to sort the entire frequency dictionary.


README for [Top K Frequent Elements (Leetcode #347)](https://blog.unwiredlearning.com/top-k-frequent-elements) was compiled from the Unwired Learning Blog.  
//### 070 File: 0371-sum-of-two-integers/README.md
# Sum of Two Integers (Leetcode #371)

In this blog, we'll dive into an intriguing problem from LeetCode: **Sum of Two Integers (Problem 371)**. We'll explore a basic brute force approach, understand a hint to approach it more efficiently, and finally provide an optimal solution. This problem challenges us to sum two integers without using the addition or subtraction operators, making it an interesting exercise in bitwise operations.

## Understanding the Problem Statement

The problem asks us to find the sum of two integers **a** and **b** without using the **+** or **\-** operators. At first glance, it might sound unusual because we often rely on these operators for addition and subtraction. However, we can solve this using bitwise operations like **AND**, **XOR**, and **left shift**, which are fundamental to computer arithmetic.

## Brute Force Approach

A common brute force approach to solving this problem could be to repeatedly increment one of the numbers until we reach the sum. Essentially, we could use a loop to add **1** to **a** for **b** number of times. This approach would look like the following:

* If **b** is positive, increment **a** by **1** for each step until **b** is zero.
    
* If **b** is negative, decrement **a** similarly.
    

However, this approach would be highly inefficient for large values of **b**, as it requires **O(b)** iterations, which is not feasible for large numbers.

## Hint to Solve the Problem Efficiently

The key to solving this problem lies in understanding how addition can be represented using bitwise operations. Recall that:

* **XOR (a ^ b)** adds bits without considering any carry.
    
* **AND (a & b)** followed by a left shift (**&lt;&lt; 1**) helps us determine the carry bits.
    

By combining these two operations iteratively, we can achieve the desired sum without using the **+** operator.

## Efficient Solution

Here is the efficient solution provided in the attached code:

```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        # 32-bit integer max value
        MAX = 0x7FFFFFFF
        
        # Mask to get 32 bits
        mask = 0xFFFFFFFF

        while b != 0:
            # Calculate the carry bits
            carry = (a & b) & mask
            
            # XOR the bits for sum without carry
            a = (a ^ b) & mask
            
            # Shift the carry to add in the next higher bit position
            b = (carry << 1) & mask
        
        # If a is negative, return a's complement in Python's 32-bit format
        return a if a <= MAX else ~(a ^ mask)
```

Let's break down how this solution works:

1. **Initialize Constants**: We define **MAX** as the maximum value for a 32-bit integer and use **mask** to ensure we only deal with 32 bits.
    
2. **Loop Until No Carry**: The loop continues as long as there is a carry. The carry is calculated using **a & b**, which gives the positions where both **a** and **b** have **1s**.
    
3. **XOR for Sum**: We use **a ^ b** to add **a** and **b** without the carry.
    
4. **Shift Carry**: The carry is shifted left by one position so that it can be added to the next higher bit.
    
5. **Handle Negative Numbers**: If **a** exceeds the maximum positive value for a 32-bit integer, it means **a** is negative, and we return its complement.
    

This approach efficiently computes the sum in **O(1)** time complexity, as it only involves a fixed number of bitwise operations.

## Time and Space Complexity

* **Time Complexity**: The time complexity is **O(1)** because the number of operations is constant and does not depend on the size of **a** or **b**.
    
* **Space Complexity**: The space complexity is **O(1)** as we are only using a constant amount of extra space.
    

## Conclusion

The **Sum of Two Integers** problem is a great example of how we can leverage bitwise operations to perform arithmetic tasks without relying on traditional operators. By understanding the mechanics of **XOR** and **AND** operations, we can solve this problem in an efficient manner. If you're preparing for technical interviews, mastering such bitwise tricks can give you an edge, especially when faced with low-level manipulation challenges.

README for [Sum of Two Integers (Leetcode #371)](https://blog.unwiredlearning.com/sum-of-two-integers) was compiled from the Unwired Learning Blog.  
//### 071 File: 0392-is-subsequence/README.md
# Is Subsequence (Leetcode #392)

In this blog, we will explore the LeetCode problem "Is Subsequence." We'll break down the problem statement, look at a common brute force approach, provide a hint for an efficient solution, and ultimately discuss the optimal way to solve it. By the end of this blog, you'll have a clear understanding of how to tackle this problem effectively.

## Understanding the Problem Statement

The problem "Is Subsequence" asks you to determine whether a given string `s` is a subsequence of another string `t`. A subsequence is a sequence derived from another string by deleting some (or none) of the characters without changing the order of the remaining characters.

For example:

* `s = "abc"`, `t = "ahbgdc"` — In this case, `s` is a subsequence of `t`.
    
* `s = "axc"`, `t = "ahbgdc"` — Here, `s` is **not** a subsequence of `t` because the characters do not match in the required order.
    

The task is to return `true` if `s` is a subsequence of `t`, otherwise return `false`.

## Brute Force Approach

A naive approach to solve this problem could be generating all possible subsequences of the string `t` and then checking if `s` matches any of those subsequences. However, generating all subsequences involves exponential complexity, making it highly impractical for larger strings.

The brute force approach has a time complexity of **O(2^n)**, where `n` is the length of `t`. This complexity arises because we need to consider every possible combination of characters from `t`.

## Hint to Solve the Problem Efficiently

Instead of generating subsequences, we can iterate through `t` while attempting to "match" the characters of `s` in sequence. We use two pointers: one for `s` and one for `t`. By carefully moving these pointers, we can determine whether `s` can be found within `t` while maintaining the order of characters.

The key idea is:

* Use a pointer to track your position in both strings and move through `t` to see if all characters in `s` are matched.
    

## Efficient Solution

Here is an efficient solution that utilizes two pointers to iterate over the strings `s` and `t`:

```python
class Solution:
    def isSubsequence(self, str1: str, str2: str) -> bool:
        # Initialize pointers for both strings
        itr1, itr2 = 0, 0
        
        # Iterate while both pointers are within their respective strings
        while itr1 < len(str1) and itr2 < len(str2):
            # Compare characters; if they match, move both pointers
            if str1[itr1] == str2[itr2]:
                itr1 += 1
                itr2 += 1
            else:
                itr2 += 1  # Move pointer for str2 only

        # If 'itr1' has reached the length of 'str1', it means all characters are matched
        return itr1 == len(str1)
```

**How the Solution Works**

* **Pointers Initialization**: We start with two pointers: `itr1` for `str1` (i.e., `s`) and `itr2` for `str2` (i.e., `t`). Both pointers are initially set to 0.
    
* **Iteration**: The loop continues until one of the pointers reaches the end of its respective string. If the characters pointed to by `itr1` and `itr2` match, we increment both pointers. Otherwise, we move the pointer for `t` (`itr2`) only.
    
* **Final Check**: After the loop ends, if `itr1` has reached the end of `str1`, it means we successfully matched all characters of `s` within `t`.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n)**, where `n` is the length of `t`. We iterate through `t` while potentially moving the pointer for `s` whenever a match is found. Since both pointers traverse their strings linearly, the time complexity is linear relative to the length of `t`.
    
* **Space Complexity**: The space complexity of this solution is **O(1)**. The solution only uses a constant amount of extra space for the two pointers, and no additional data structures are needed.
    

## Conclusion

The efficient approach for solving the "Is Subsequence" problem avoids the need for generating all possible subsequences. Instead, by leveraging two pointers, we can traverse the strings effectively in linear time. This makes the solution optimal and well-suited for larger inputs.

If you have further questions or would like more examples, feel free to comment below or check out more tutorials on efficient string manipulation!


README for [Is Subsequence (Leetcode #392)](https://blog.unwiredlearning.com/is-subsequence) was compiled from the Unwired Learning Blog.  
//### 072 File: 0417-pacific-atlantic-water-flow/README.md
# Pacific Atlantic Water Flow (Leetcode #417)

The **Pacific Atlantic Water Flow** problem (LeetCode #417) is an interesting challenge that asks us to determine which land cells in a given matrix can flow to both the Pacific and Atlantic oceans. Given a matrix where each cell contains a height value, water can flow from one cell to another only if the other cell is of equal or lower elevation, and water can flow to the edges of the matrix, representing the oceans.

## Understanding the Problem Statement

The matrix consists of rows and columns representing land elevations, and we need to determine which cells have the capability to reach both oceans. The top and left edges of the matrix are adjacent to the Pacific Ocean, while the bottom and right edges are adjacent to the Atlantic Ocean.

Water can only flow **downhill or laterally**, meaning that it can flow from one cell to another if the other cell is of **equal or lesser height**. The task is to return all the coordinates from which water can reach **both the Pacific and Atlantic oceans**.

## Brute Force Approach

A common brute force approach would involve simulating the flow of water from every cell in the matrix and attempting to determine whether it reaches both oceans. This can be done using a depth-first search (DFS) or breadth-first search (BFS) for each individual cell in the matrix to explore all possible paths. Although this approach is straightforward, it becomes very **inefficient** as the size of the matrix grows due to redundant computations.

The time complexity of such an approach is **O(m \* n \* (m + n))**, where **m** and **n** are the number of rows and columns, respectively. This is because we perform a DFS/BFS starting from each cell in the matrix, resulting in substantial overlapping work.

## Hint to Solve the Problem Efficiently

To improve upon the brute force approach, consider **reversing the problem**: instead of starting from every cell and trying to determine whether it can reach both oceans, start from the oceans and try to determine which cells can be reached. By performing a DFS from all cells adjacent to the oceans, we can track the cells that are reachable by both the Pacific and Atlantic oceans.

## Efficient Solution

The provided solution leverages **two DFS searches** to efficiently determine which cells can reach both oceans. Here is the breakdown of the approach:

1. **Initialization**: Create two matrices to keep track of whether each cell is reachable from the **Pacific** and **Atlantic** oceans. Each matrix has the same dimensions as the input matrix, initialized to `False`.
    
2. **DFS Function**: Implement a DFS function that takes in the current cell coordinates and marks all reachable cells in the direction of increasing height.
    
3. **Pacific and Atlantic DFS**: Perform a DFS from all cells adjacent to the **Pacific Ocean** (top row and left column) to mark all cells that can reach the Pacific. Similarly, perform a DFS from all cells adjacent to the **Atlantic Ocean** (bottom row and right column).
    
4. **Find Intersecting Cells**: Iterate through the matrix to identify cells that are reachable from both the **Pacific** and **Atlantic** oceans.
    

Here is the efficient solution code:

```python
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights:
            return []
        
        m, n = len(heights), len(heights[0])
        pacificReachable = [[False for _ in range(n)] for _ in range(m)]
        atlanticReachable = [[False for _ in range(n)] for _ in range(m)]
        
        def dfs(row, col, reachable):
            reachable[row][col] = True
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dr, dc in directions:
                newRow, newCol = row + dr, col + dc
                if (0 <= newRow < m and 0 <= newCol < n and not reachable[newRow][newCol] and
                heights[newRow][newCol] >= heights[row][col]):
                    dfs(newRow, newCol, reachable)
        
        for i in range(m):
            dfs(i, 0, pacificReachable)
            dfs(i, n - 1, atlanticReachable)
        
        for j in range(n):
            dfs(0, j, pacificReachable)
            dfs(m - 1, j, atlanticReachable)
        
        result = []
        for i in range(m):
            for j in range(n):
                if pacificReachable[i][j] and atlanticReachable[i][j]:
                    result.append([i, j])
        
        return result
```

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(m \* n)**, where **m** is the number of rows and **n** is the number of columns. This is because each cell is visited once during the DFS for both oceans, resulting in a linear pass through the entire matrix.
    
* **Space Complexity**: The space complexity is **O(m \* n)** for storing the reachability matrices and **O(m \* n)** for the recursion stack in the worst case where all cells are traversed. Therefore, the overall space complexity is **O(m \* n)**.
    

## Conclusion

The Pacific Atlantic Water Flow problem can be efficiently solved by leveraging the idea of starting from the oceans and marking reachable cells using depth-first search. This approach reduces redundant calculations and allows for a more streamlined solution compared to the brute force method. By using two separate DFS traversals from the Pacific and Atlantic oceans, we can effectively identify the cells that have the ability to reach both bodies of water. This problem is an excellent example of how reversing the perspective can lead to a significant improvement in efficiency.


README for [Pacific Atlantic Water Flow (Leetcode #417)](https://blog.unwiredlearning.com/pacific-atlantic-water-flow) was compiled from the Unwired Learning Blog.  
//### 073 File: 0424-longest-repeating-character-replacement/README.md
# Longest Repeating Character Replacement (Leetcode #424)

Leetcode's problem "Longest Repeating Character Replacement" (Problem 424) is an intriguing challenge that tests your understanding of string manipulation and sliding window techniques. The problem statement is quite relatable for those dealing with character strings, and it also serves as a great exercise for coding interviews. Let's break down the question, explore different approaches, and finally walk through an efficient solution.

## Understanding the Problem Statement

You are given a string `s` and an integer `k`. You can replace up to `k` characters in the string, and your goal is to find the length of the longest substring containing the same letter you can get after making those replacements. The problem boils down to determining the longest contiguous substring where you can replace no more than `k` characters to make all the characters identical.

For instance, if you have the string `s = "AABABBA"` and `k = 1`, the output should be `4`, because you can replace one character (`B` at index 4) to make the substring "AABA".

## Brute Force Approach

A common brute-force approach for solving this problem is to check every possible substring, determining if you can make it uniform with no more than `k` changes. Here's a basic outline:

1. Iterate through all possible substrings.
    
2. For each substring, count how many changes are needed to make all characters the same.
    
3. Keep track of the maximum length that meets the `k`\-replacement requirement.
    

While this approach works, it is extremely inefficient, with a time complexity of `O(n^2)` or worse, given that each substring must be evaluated, and then modified accordingly. This quickly becomes impractical for larger strings.

## Hint to Solve the Problem Efficiently

The key to solving this problem efficiently is to use the **sliding window technique**. Instead of evaluating every possible substring, you can dynamically expand and contract a window over the string, keeping track of important metrics as you go along. This allows you to find the solution in linear time.

In the sliding window, you need to keep track of the **most frequent character** within the window. The number of other characters can be replaced to maximize the window length. If the number of replacements exceeds `k`, the window should be contracted from the left.

## Efficient Solution

Below is an efficient Python solution that leverages the sliding window technique. The core idea is to maintain a window of characters, adjusting its boundaries to maximize the number of identical characters after no more than `k` replacements.

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        max_len = 0
        left = 0
        max_freq = 0

        for right in range(len(s)):
            count[s[right]] = count.get(s[right], 0) + 1
            max_freq = max(max_freq, count[s[right]])

            while (right - left + 1) - max_freq > k:
                count[s[left]] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len
```

**Explanation**:

1. **Initialize Variables**: Start by defining a dictionary `count` to store character frequencies, `max_len` for tracking the maximum length found, and pointers `left` and `right` to define the sliding window boundaries.
    
2. **Expand Window**: Use `right` to expand the window and add characters to the frequency dictionary. Also, update `max_freq` to maintain the count of the most frequent character in the window.
    
3. **Contract Window**: If the current window size minus the frequency of the most frequent character exceeds `k`, it means we need to reduce the size of the window from the left to meet the constraint.
    
4. **Update Maximum Length**: Finally, update `max_len` to track the longest valid window found.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(n)`, where `n` is the length of the string. The sliding window ensures that each character is visited at most twice (once when expanding and once when contracting), resulting in a linear time complexity.
    
* **Space Complexity**: The space complexity is `O(1)` or `O(26)` to be precise, because the `count` dictionary can store up to 26 characters at most (considering only uppercase English letters), which is effectively a constant space requirement.
    

## Conclusion

The "Longest Repeating Character Replacement" problem is a great example of how the sliding window technique can dramatically reduce the complexity of a problem involving contiguous subarrays or substrings. The brute force solution, while conceptually straightforward, is inefficient for larger strings, whereas the sliding window approach yields a much more practical and performant solution.

If you're looking to improve your skills in tackling similar problems, mastering sliding window techniques like this is invaluable, especially in coding interviews.


README for [Longest Repeating Character Replacement (Leetcode #424))](https://blog.unwiredlearning.com/longest-repeating-character-replacement) was compiled from the Unwired Learning Blog.  
//### 074 File: 0435-non-overlapping-intervals/README.md
# Non-overlapping Intervals (Leetcode #435)

In this blog, we'll explore an interesting problem from LeetCode - the **435\. Non-overlapping Intervals** problem. We'll start by understanding the problem statement, look at a common brute force solution, and discuss a more efficient approach along with an analysis of its time and space complexity. If you've been practicing interval problems and looking to improve your greedy algorithm skills, this is the perfect problem to learn from.

## Understanding the Problem Statement

The **Non-overlapping Intervals** problem asks us to find the minimum number of intervals to remove in order to make the rest of the intervals non-overlapping. Each interval is given as an array of two integers, where the first represents the start and the second represents the end. The objective is to eliminate the overlapping intervals while keeping as many intervals as possible.

For example, consider these intervals: **\[\[1,3\], \[2,4\], \[3,5\]\]**. The goal is to remove the fewest number of intervals so that no two intervals overlap. In this case, we can remove either **\[1,3\]** or **\[2,4\]** to avoid overlap, which means the answer would be **1**.

## Brute Force Approach

A brute force approach to this problem would involve comparing every interval with every other interval to identify overlaps and then removing intervals accordingly. This would typically involve nested loops, resulting in **O(n^2)** time complexity. Specifically, we'd iterate over each interval, compare it with all others to find overlaps, and count how many intervals need to be removed to eliminate all overlaps.

While this approach works for smaller input sizes, it becomes inefficient as the number of intervals increases, due to the quadratic time complexity.

## Hint to Solve the Problem Efficiently

To solve this problem efficiently, think about sorting the intervals in a specific way that allows us to make optimal decisions about which intervals to keep and which to remove. Sorting can help in systematically processing intervals while reducing overlap as much as possible.

## Efficient Solution

The given solution follows a **greedy algorithm** approach, which is much more efficient than the brute force method. Let's break down the code provided:

```python
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # Sort intervals by start time
        intervals.sort()
        
        # Initialize the previous interval end time and count
        prev_end = intervals[0][1]
        count = 0
        
        for i in range(1, len(intervals)):
            if intervals[i][0] < prev_end:
                # Overlap detected, increment the count
                count += 1
                # Keep the interval with the smaller end to minimize future overlaps
                prev_end = min(prev_end, intervals[i][1])
            else:
                # No overlap, update the prev_end to current interval's end
                prev_end = intervals[i][1]
        
        return count
```

**Step-by-Step Explanation**

1. **Sorting the Intervals**: First, we sort the intervals based on their start times. Sorting helps us to process intervals sequentially.
    
2. **Tracking the End of Previous Interval**: We initialize `prev_end` with the end time of the first interval and set a counter `count` to track the number of overlaps that we need to remove.
    
3. **Iterating Over the Intervals**: Starting from the second interval, we check if the current interval overlaps with the previous one:
    
    * If there is an overlap (`intervals[i][0] < prev_end`), we increment the `count` and update `prev_end` to the minimum of the current and previous interval ends. This ensures that we keep the interval that ends earlier, thereby minimizing future overlaps.
        
    * If there is no overlap, we simply update `prev_end` to the end of the current interval.
        
4. **Return the Count**: Finally, we return the count of intervals that were removed.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n log n)**, where **n** is the number of intervals. This is due to the sorting step. The subsequent iteration through the intervals is **O(n)**, which is dominated by the sorting step.
    
* **Space Complexity**: The space complexity is **O(1)**, as we are not using any extra space that scales with the input size, aside from a few variables for tracking purposes.
    

## Conclusion

The **Non-overlapping Intervals** problem is a classic example of how a greedy algorithm can be used to efficiently solve interval scheduling problems. By sorting the intervals and making optimal choices at each step, we can minimize the number of intervals to remove. This solution is not only more elegant but also significantly more efficient than the brute force approach. Next time you come across an interval problem, consider how sorting and a greedy strategy might help you find the solution more effectively.

README for [Non-overlapping Intervals (Leetcode #435)](https://blog.unwiredlearning.com/non-overlapping-intervals) was compiled from the Unwired Learning Blog.  
//### 075 File: 0509-fibonacci-number/README.md
# Fibonacci Number (Leetcode 509)

The Fibonacci sequence is a classic problem often encountered in interviews and coding assessments. It starts with the numbers 0 and 1, and each subsequent number is the sum of the two preceding ones. In this blog, we will break down the problem of finding the nth Fibonacci number, explore the brute force approach, and finally present an efficient solution.

## Understanding the Problem Statement

The problem is simple: Given an integer `n`, find the nth Fibonacci number, where `F(0) = 0` and `F(1) = 1`. Each term of the sequence is defined as `F(n) = F(n-1) + F(n-2)` for `n > 1`. The challenge here is to compute the value efficiently as `n` grows larger.

## Brute Force Approach

The most straightforward approach to finding the Fibonacci number is by using recursion. In a brute force solution, you can directly define the Fibonacci function as:

```python
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        return self.fib(n-1) + self.fib(n-2)
```

This method directly follows the definition of the Fibonacci sequence but has significant drawbacks in terms of efficiency. The recursive approach repeatedly recalculates the same sub-problems, leading to an exponential time complexity, making it impractical for larger values of `n`.

## Hint to Solve the Problem Efficiently

To solve the problem more efficiently, consider how we can eliminate the need for redundant calculations. Think about using a data structure to store intermediate results and avoid repeating calculations.

## Efficient Solution

A more optimal way to solve the problem is to use Dynamic Programming. By storing the results of previous computations in an array, we can build the solution iteratively and avoid recalculating values. Below is an efficient implementation according to the provided code:

```python
class Solution:
    def fib(self, n: int) -> int:
        # Base case: if n is 0 or 1, return n directly
        if n <= 1:
            return n

        # Initialize a list (dp) to store computed Fibonacci numbers
        dp = [0] * (n+1)

        dp[0] = 0
        dp[1] = 1

        # Start calculating Fibonacci numbers from 2 to n
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]

        # Return the nth Fibonacci number
        return dp[n]
```

In this solution, an array `dp` is used to store the Fibonacci numbers as they are calculated, which eliminates the need for repeated recursive calls. The values are computed iteratively, allowing for much faster execution.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(n)`, as we need to compute each Fibonacci number from `2` to `n` only once.
    
* **Space Complexity**: The space complexity is `O(n)` due to the use of the list `dp` to store the Fibonacci numbers.
    

Although the space complexity can be further reduced to `O(1)` by keeping only the last two Fibonacci numbers in variables rather than an entire list, this approach strikes a balance between clarity and efficiency for learning purposes.

## Conclusion

The Fibonacci sequence is a fundamental problem that helps illustrate the importance of choosing the right approach for efficiency. While the brute force recursive solution is easy to understand, it quickly becomes impractical for large inputs due to its exponential time complexity. By applying dynamic programming, we can significantly improve the efficiency of the solution, reducing the time complexity to `O(n)`. This approach demonstrates how storing intermediate results can lead to much faster solutions for problems involving overlapping sub-problems, making it an essential tool in any programmer's toolkit.


README for [Fibonacci Number (Leetcode 509)](https://blog.unwiredlearning.com/fibonacci-number) was compiled from the Unwired Learning Blog.  
//### 076 File: 0572-subtree-of-another-tree/README.md
# Subtree of Another Tree (Leetcode #572)

Binary trees are an important data structure in computer science, and they often form the basis of many interesting coding problems. One such problem is determining whether a given tree is a subtree of another tree. In this blog, we'll discuss Leetcode Problem 572: **Subtree of Another Tree**. We'll explore both the brute force approach and an efficient solution to solve this problem, using Python code to illustrate each step. Let's dive in!

## Understanding the Problem Statement

In this Leetcode problem, we are given two binary trees, **root** and **subRoot**, and we need to determine if **subRoot** is a subtree of **root**. A subtree consists of a node in the tree and all of its descendants. Essentially, the subtree must be identical to some part of the given tree. For example, if you imagine cutting off one part of a tree and seeing if it matches another smaller tree, that's what we're trying to determine here.

## Brute Force Approach

The most straightforward approach to solve this problem is to consider every node in the **root** tree and try to determine if any of these nodes are identical to the **subRoot** tree. The idea is to perform a traversal of the **root** tree and, at each step, compare the subtree starting at the current node to **subRoot**. This solution uses a **depth-first traversal** to locate nodes, and for every potential starting point, it checks if the subtree matches **subRoot**.

The brute force approach is feasible, but not very efficient since it repeatedly performs tree comparisons for each possible subtree in **root**.

## Hint to Solve the Problem Efficiently

To solve the problem efficiently, a good approach is to make use of a helper function that checks if two trees are identical. The efficient solution involves reducing the number of comparisons by combining a direct tree traversal with a subtree comparison. The idea is to avoid unnecessary work by optimizing the traversal and comparison steps.

## Efficient Solution

The efficient solution, as outlined in the provided code, leverages two functions:

1. `isSubtree(root, subRoot)` - This function checks if **subRoot** is a subtree of **root**.
    
2. `isSameTree(p, q)` - This helper function checks if two trees, **p** and **q**, are identical.
    

The core logic of `isSubtree` function includes:

1. **Base cases**: If **subRoot** is `None`, then it is automatically a subtree of **root**. If **root** is `None` but **subRoot** is not `None`, it cannot be a subtree.
    
2. **Subtree Comparison**: We use the `isSameTree` function to check if **root** and **subRoot** are identical, which means that all nodes in both trees have the same value and structure.
    
3. **Recursive Call**: If the current node of **root** does not match **subRoot**, we recursively call `isSubtree` for the left and right children of **root**.
    

Here is the Python code for reference:

```python
class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        if subRoot is None:
            return True
        if root == None and subRoot != None:
            return False

        if self.isSameTree(root, subRoot):
            return True

        left_check = self.isSubtree(root.left, subRoot)
        right_check = self.isSubtree(root.right, subRoot)

        return left_check or right_check

    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        if p == None or q == None or p.val != q.val:
            return False

        left_compare = self.isSameTree(p.left, q.left)
        right_compare = self.isSameTree(p.right, q.right)

        return left_compare and right_compare
```

## Time and Space Complexity

* **Time Complexity**: The time complexity of the solution is **O(m × n)**, where **m** is the number of nodes in **root** and **n** is the number of nodes in **subRoot**. In the worst case, for each node in **root**, we could potentially compare it with every node in **subRoot**.
    
* **Space Complexity**: The space complexity is **O(n)** in the worst case due to the recursion stack used by the helper function `isSameTree`, where **n** is the height of the **root** tree. The recursive calls are made for each node, resulting in a linear stack depth in the worst scenario.
    

## Conclusion

The **Subtree of Another Tree** problem is a great exercise for understanding recursive tree traversal and comparison. While the brute force approach works, the efficient solution optimizes both time and space, making use of recursive calls and base conditions effectively. By using helper functions to check if two trees are identical, we can significantly reduce unnecessary comparisons and arrive at a more elegant solution. Understanding these approaches will not only help you solve this particular problem but also enhance your ability to think recursively for similar tree-based problems.


README for [Subtree of Another Tree (Leetcode #572)](https://blog.unwiredlearning.com/subtree-of-another-tree) was compiled from the Unwired Learning Blog.  
//### 077 File: 0643-maximum-average-subarray-i/README.md
# Maximum Average Subarray I (Leetcode #643)

Finding maximum average subarrays is a common problem that tests your understanding of sliding window techniques, which are essential for optimizing array operations. In Leetcode problem #643, we need to determine the maximum average of a subarray of length `k`. This challenge not only involves calculating averages efficiently but also learning how to manage subarray calculations without unnecessary redundancies. Let's break down the problem, understand the brute-force solution, and then delve into a more efficient approach.

## Understanding the Problem Statement

The goal of Leetcode problem #643, **Maximum Average Subarray I**, is to find the maximum average of any subarray of length `k` within a given list of integers `nums`. For instance, if you have an input array `nums = [1, 12, -5, -6, 50, 3]` and `k = 4`, the objective is to determine which subarray of size `k` yields the highest average value.

Key constraints include `1 <= k <= nums.length <= 10^5` and `-10^4 <= nums[i] <= 10^4`, which means the input can contain up to 100,000 elements. This makes an efficient solution critical due to the potentially large size of the array.

## Brute Force Approach

The brute-force method for solving this problem involves calculating the sum of each possible subarray of length `k` and then dividing by `k` to obtain the average. You would then track the highest average found among all subarrays. This can be accomplished through the following steps:

1. Initialize a variable to store the maximum average found so far.
    
2. Iterate through all possible starting points for subarrays of size `k`.
    
3. For each subarray, calculate the sum and then divide it by `k` to find the average.
    
4. Compare this average with the current maximum average and update if necessary.
    

While easy to understand, this brute-force approach is inefficient for large inputs due to its time complexity of `O(n * k)`, where `n` is the length of the array. Repeatedly recalculating the sum of overlapping subarrays results in many redundant operations.

## Hint to Solve the Problem Efficiently

Instead of recalculating the sum of each subarray from scratch, think about whether there's a way to avoid redundant computations when transitioning from one subarray to the next. Notice that each subarray overlaps with the previous one, and each sliding window operation only involves removing one element and adding a new one. This observation hints towards the **Sliding Window** technique, which can help you significantly reduce the number of operations required.

## Efficient Solution

To solve this problem more efficiently, we can use the **Sliding Window** approach to maintain a running sum of the current subarray of length `k`. As we slide the window across the array, we adjust the sum by subtracting the element that is left behind and adding the new element. This method avoids recalculating the sum from scratch for each subarray, resulting in a time complexity of `O(n)`, where `n` is the length of the array.

Here is the efficient solution provided:

```python
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # Sum for starting window
        current_sum = 0
        for i in range(k):
            current_sum += nums[i]

        max_sum = current_sum
        
        # Start sliding window
        start_index = 0
        end_index = k
        
        while end_index < len(nums):
            # Remove previous element
            current_sum -= nums[start_index]  
            start_index += 1
            
            # Add next element
            current_sum += nums[end_index]  
            end_index += 1
            
            # Update max sum
            max_sum = max(max_sum, current_sum)  
        
        # Return the average
        return max_sum / k
```

In the above code:

1. We first initialize `current_sum` by summing up the first `k` elements of the array.
    
2. We then use two pointers (`start_index` and `end_index`) to manage the window of length `k` as it slides from left to right across the array.
    
3. In each iteration, we update `current_sum` by subtracting the element at `start_index` and adding the element at `end_index`, effectively moving the window one position forward.
    
4. The maximum sum is updated whenever a new higher sum is found.
    
5. Finally, we return the average by dividing `max_sum` by `k`.
    

## Time and Space Complexity

**Time Complexity**: The time complexity of this solution is `O(n)`, where `n` is the length of the input array. This is because we iterate through the entire array once, and each update operation (adding and subtracting elements from `current_sum`) takes constant time.

**Space Complexity**: The space complexity is `O(1)` since the solution only uses a fixed amount of extra space (variables like `current_sum`, `max_sum`, etc.), regardless of the size of the input array.

By avoiding redundant computations and efficiently sliding the window across the array, this solution dramatically improves performance compared to the brute-force approach, making it feasible to handle large inputs as required by the problem constraints.

## Conclusion

The **Maximum Average Subarray I** problem is a great example of how optimizing calculations through efficient techniques like the sliding window can significantly improve performance. By avoiding redundant computations, we reduce the time complexity from `O(n * k)` in the brute-force approach to `O(n)`. This approach allows us to handle even large inputs effectively, making it an important technique for solving similar array-based problems. Understanding and applying the sliding window technique is crucial for optimizing many real-world applications where efficiency is key.


README for [Maximum Average Subarray I (Leetcode #643)](https://blog.unwiredlearning.com/maximum-average-subarray-i) was compiled from the Unwired Learning Blog.  
//### 078 File: 0647-palindromic-substrings/README.md
# Palindromic Substrings (Leetcode 647)

**Palindromic Substrings** is an interesting problem that requires us to determine the number of palindromic substrings within a given string. Let's walk through the question, a brute force approach, a hint for an efficient solution, and then dive into the optimized solution, along with the associated time and space complexity.

## Understanding the Problem Statement

The problem statement is simple: Given a string `s`, count how many substrings of `s` are palindromes. A **palindrome** is a string that reads the same backward as forward, such as "aba" or "racecar". Substrings of a string are continuous parts of that string, and the question is not about distinct substrings, but the count of all palindromic substrings that exist in the given string.

For instance, given the input `s = "aaa"`, the answer would be `6`. The palindromic substrings are: "a", "a", "a", "aa", "aa", "aaa".

## Brute Force Approach

A straightforward way to solve this problem is using a **brute force** approach where you generate all possible substrings of the given string and then check if each substring is a palindrome.

Steps for the brute force approach:

1. Generate all possible substrings using nested loops.
    
2. Check if each substring is a palindrome.
    
3. Keep a count of the palindromic substrings.
    

The brute force approach is very easy to understand, but it is inefficient for longer strings. Its time complexity is **O(N^3)**, where `N` is the length of the string (`O(N^2)` for generating all substrings and another `O(N)` for checking each substring).

## Hint to Solve the Problem Efficiently

To improve efficiency, we can leverage **dynamic programming** (DP) to reduce unnecessary repeated checks. The core idea is to use a DP table to store information about whether a substring is a palindrome. This will help avoid recalculating the status of overlapping substrings, thus improving performance.

If you're unsure how to proceed, think about how you can represent subproblems (e.g., palindromic substrings) in a way that lets you build on previous results without recalculating from scratch.

## Efficient Solution

The efficient solution leverages **dynamic programming** to solve the problem in **O(N^2)** time complexity. Here's the code snippet, which follows the given approach:

```python
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)

        # Initialize the DP table with False.
        dp = [[False] * n for _ in range(n)]
        count = 0

        # Base case: single characters
        for i in range(n):
            dp[i][i] = True
            count += 1

        # Base case: two consecutive characters
        for i in range(n-1):
            if s[i] == s[i+1]:
                dp[i][i+1] = True
                count += 1

        # DP case: substrings of length 3 to n
        for length in range(3, n+1):
            # Iterate through all starting indices for the current length.
            for i in range(n-length+1):
                # Calculate the ending index of the current substring.
                j = i+length-1

                # Check if the current substring is a palindrome.
                if s[i] == s[j] and dp[i+1][j-1]:
                    dp[i][j] = True
                    count += 1

        return count
```

**Explanation of the Solution:**

* **Base Case 1:** Every single character in the string is a palindrome by itself. Thus, we initialize all `dp[i][i]` to `True`.
    
* **Base Case 2:** If two consecutive characters are equal, they form a palindromic substring of length 2. We handle this separately to make subsequent logic easier.
    
* **Dynamic Programming Logic:** For substrings longer than 2 characters, we iterate over possible lengths and check whether the current substring's boundary characters match and if the inner substring (which is shorter) is also a palindrome. If both conditions are met, the substring is palindromic.
    

## Time and Space Complexity

* **Time Complexity:** The time complexity of the dynamic programming solution is **O(N^2)**. This is due to the nested loops: the outer loop iterates over the length of substrings (from 1 to `n`), and the inner loop iterates over all possible starting points for the substring.
    
* **Space Complexity:** The space complexity is also **O(N^2)** due to the DP table (`dp`), which stores information about whether each substring is a palindrome or not.
    

The dynamic programming approach makes this problem more efficient, especially for longer strings, as it avoids recalculating palindromic conditions for overlapping substrings.

This efficient solution is a significant improvement over the brute force approach, allowing for quicker results and efficient use of computational resources.

## Conclusion

In conclusion, the problem of counting palindromic substrings can be approached in multiple ways, but leveraging dynamic programming provides a clear edge in terms of efficiency. While the brute force approach is straightforward, it becomes computationally expensive as the input size grows. The dynamic programming solution, on the other hand, reduces redundant calculations by building on previous results, making it a more scalable option. Understanding the principles of breaking down problems and optimizing with DP is crucial for tackling similar problems effectively. This approach not only enhances problem-solving skills but also equips you with techniques that are widely applicable in competitive programming and real-world scenarios.


README for [Palindromic Substrings (Leetcode 647)](https://blog.unwiredlearning.com/palindromic-substrings) was compiled from the Unwired Learning Blog.  
//### 079 File: 0704-binary-search/README.md
# Binary Search (Leetcode #704)

Binary Search is a fundamental algorithm often used to quickly find an element in a sorted array. This blog will help you understand how to solve the LeetCode problem 704 - 'Binary Search'. We'll go through a brute force approach first, and then look at an efficient solution to achieve optimal results.

## Understanding the Problem Statement

The problem statement asks you to find a target element within a sorted integer array. If the target exists in the array, you need to return its index; otherwise, return -1. The given array is sorted in ascending order, and you need to solve the problem with O(log n) time complexity if possible.

## Brute Force Approach

A common but less efficient way to solve this problem is to use a linear search. In this approach, you iterate through each element in the array until you find the target element:

* Start from the beginning of the array.
    
* Compare each element with the target.
    
* If the element matches the target, return its index.
    
* If you reach the end of the array without finding the target, return -1.
    

The brute force approach works, but it is inefficient for large arrays since its time complexity is O(n), which means it requires traversing each element in the worst case.

## Hint to Solve the Problem Efficiently

Notice that the given array is sorted. When dealing with sorted data, Binary Search is usually the preferred method to significantly reduce the time complexity. This involves repeatedly dividing the search interval in half, focusing on narrowing down the potential positions of the target value.

## Efficient Solution

The provided solution makes use of the Binary Search algorithm to solve the problem in a more optimal way. Let's look at how the code works:

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Initialize the pointers for the start and end of the array
        left, right = 0, len(nums) - 1

        # Continue searching while the search space is valid
        while left <= right:
            # Calculate the middle index of the current search space
            # Using left + (right - left) // 2 to avoid integer overflow
            mid = left + (right - left) // 2

            # Check if the middle element is the target
            if nums[mid] == target:
                return mid  # Target found, return its index
            elif nums[mid] > target:
                # If the middle element is greater than the target,
                # narrow the search to the left half of the array
                right = mid - 1
            else:
                # If the middle element is less than the target,
                # narrow the search to the right half of the array
                left = mid + 1

        # Target not found in the array, return -1
        return -1
```

**Explanation**

* **Initialization**: Start with two pointers, `left` at the beginning and `right` at the end of the array.
    
* **While Loop**: The loop runs as long as `left` is less than or equal to `right`, indicating there is still a valid range to search.
    
* **Middle Calculation**: Calculate the midpoint using `left + (right - left) // 2` to prevent potential integer overflow. The middle value is checked against the target.
    
* **Adjust Search Space**: If the middle value matches the target, return its index. If the middle value is greater than the target, adjust the `right` pointer to search the left half. Otherwise, adjust the `left` pointer to search the right half.
    
* **Return Statement**: If the loop ends without finding the target, return `-1`.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is O(log n), as the search space is divided by half in each iteration.
    
* **Space Complexity**: The space complexity is O(1) because we are using only constant extra space.
    

This efficient approach, Binary Search, is far superior to the brute force method for larger datasets, making it an ideal solution when working with sorted arrays.

## Conclusion

Binary Search is a powerful technique for quickly finding elements in a sorted array. By leveraging the divide-and-conquer strategy, it significantly reduces the time complexity compared to a linear search, making it ideal for large datasets. Understanding and implementing Binary Search can be a valuable skill when working with sorted data structures, and it serves as a fundamental building block for more advanced algorithms. Always consider using Binary Search when dealing with sorted arrays to achieve optimal efficiency.


README for [Binary Search (Leetcode #704)](https://blog.unwiredlearning.com/binary-search) was compiled from the Unwired Learning Blog.  
//### 080 File: 0739-daily-temperatures/README.md
# Daily Temperatures (Leetcode #739)

The "Daily Temperatures" problem is a popular challenge on LeetCode, often used to test your ability to solve problems involving arrays and stacks. In this guide, we will break down the problem, explore a basic brute force approach, and then provide an efficient solution using a stack. By the end, you'll understand both the logic and the computational considerations involved in solving this problem effectively.

## Understanding the Problem Statement

The "Daily Temperatures" problem on LeetCode (Problem 739) is an interesting challenge where you're given a list of daily temperatures, and your goal is to find out how many days you have to wait until a warmer temperature occurs for each day. If no warmer temperature is ahead, you simply return 0 for that day.

For example, given the input `[73, 74, 75, 71, 69, 72, 76, 73]`, the output should be `[1, 1, 4, 2, 1, 1, 0, 0]`. Each value in the output corresponds to the number of days you must wait to experience a warmer day.  

## Brute Force Approach

The brute force way to solve this problem is to iterate over each temperature and, for each day, look ahead in the list to find the next warmer temperature. This would involve two nested loops:

* The outer loop goes through each temperature in the list.
    
* The inner loop searches for the next higher temperature, moving one day at a time.
    

Here's a simple representation of the brute force approach:  

```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n
        for i in range(n):
            for j in range(i + 1, n):
                if temperatures[j] > temperatures[i]:
                    result[i] = j - i
                    break
        return result
```

While this solution works, its time complexity is **O(n^2)**, which can be very inefficient for large inputs, resulting in a lot of unnecessary comparisons.

## Hint to Solve the Problem Efficiently

The key to solving this problem more efficiently is to avoid redundant comparisons and utilize an auxiliary data structure to keep track of indices. One very helpful data structure for such problems involving "next greater element" type queries is a **stack**.

To solve the problem efficiently, think about iterating through the temperatures from right to left. By doing so, you can leverage a stack to keep track of the indices of temperatures that are waiting to find a warmer day.

**Efficient Solution Using Stack**  
The given solution uses a stack to keep track of indices where the temperature is yet to find a warmer day. Here is the efficient implementation:  

```python
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n
        stack = []

        for i in range(n - 1, -1, -1):
            # Popping all indices with a lower or equal temperature than the current index
            while stack and temperatures[i] >= temperatures[stack[-1]]:
                stack.pop()

            # If the stack still has elements, then the next warmer temperature exists!
            if stack:
                result[i] = stack[-1] - i

            # Inserting current index in the stack
            stack.append(i)

        return result
```

In this implementation, the list is traversed from right to left. Here’s how it works:

* The **stack** keeps the indices of temperatures where we are yet to determine the next warmer day.
    
* For each temperature, we **pop** elements from the stack until we find a warmer temperature or the stack becomes empty.
    
* If the stack still has elements after the popping process, it means we found a warmer temperature in the future, and the result is updated accordingly.
    
* Finally, we push the current index onto the stack.
    

This approach is efficient because each temperature is processed at most twice—once when it is added to the stack and once when it is removed. This means that the time complexity is **O(n)**, which is significantly better than the brute force approach.

## Time and Space Complexity

* **Time Complexity**: The efficient solution has a time complexity of **O(n)**, where **n** is the number of days in the temperature list. Each element is pushed and popped from the stack at most once, ensuring a linear traversal.
    
* **Space Complexity**: The space complexity is **O(n)**, as we use an additional stack to store the indices. The worst-case scenario involves a strictly decreasing sequence of temperatures, where all indices are added to the stack.
    

## Conclusion

The "Daily Temperatures" problem is a great example of how using the right data structure can dramatically improve the efficiency of a solution. By utilizing a stack, we can avoid redundant comparisons and achieve a linear time complexity, making the solution feasible for large inputs. This problem also reinforces the concept of the "next greater element," which is a common pattern in many algorithmic challenges. By mastering this approach, you will be better prepared for similar problems in the future.


README for [Daily Temperatures (Leetcode #739)](https://blog.unwiredlearning.com/daily-temperatures) was compiled from the Unwired Learning Blog.  
//### 081 File: 0876-middle-of-the-linked-list/README.md
# Middle of the Linked List (Leetcode #876)

Linked lists are a fundamental data structure in computer science, and understanding how to manipulate them is key for many coding problems. One common problem is finding the middle of a linked list, which has a number of practical applications. In this blog, we will explore how to solve the "876. Middle of the Linked List" problem from LeetCode, discuss both the brute force and efficient approaches, and provide a complete solution with an explanation.

## Understanding the Problem Statement

In the "Middle of the Linked List" problem, you are given a singly linked list. The goal is to return the middle node of the linked list. If there are two middle nodes (for an even number of nodes), you should return the second middle node.

For example, consider a linked list with nodes `1 → 2 → 3 → 4 → 5`. The middle node in this case is `3`, so we return that node. If the linked list was `1 → 2 → 3 → 4 → 5 → 6`, then the middle node would be `4`, since there are two middle nodes (`3` and `4`) and we need to return the second one.

## Brute Force Approach

A common brute force approach to solving this problem is to iterate through the linked list twice:

1. Traverse the entire list to count the total number of nodes.
    
2. Traverse the list again, this time stopping at the node that is at position `n/2`, where `n` is the total number of nodes.
    

While this approach works, it has a time complexity of `O(N)` due to two separate traversals of the list and a space complexity of `O(1)`. This can be inefficient when the linked list is large, as we have to traverse the list twice.

## Hint to Solve the Problem Efficiently

To solve this problem in a more efficient way, consider using two pointers to traverse the linked list. One pointer should move at twice the speed of the other. By the time the faster pointer reaches the end of the list, the slower pointer will be at the middle.

## Efficient Solution

The efficient solution makes use of a **two-pointer technique** often called the **slow and fast pointer** approach. Here is how it works:

* We initialize two pointers, `slow` and `fast`, both starting at the head of the linked list.
    
* The `fast` pointer moves two steps at a time, while the `slow` pointer moves one step at a time.
    
* When the `fast` pointer reaches the end of the list, the `slow` pointer will be at the middle.
    

Below is the code that implements this approach:

```python
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize two pointers, slow and fast, both pointing to the head of the list.
        slow, fast = head, head
        
        # Traverse the list. The loop continues as long as fast and its next node are not None.
        while fast != None and fast.next != None:
            # Move the slow pointer one step.
            slow = slow.next
            
            # Move the fast pointer two steps.
            fast = fast.next.next
        
        # By the time the loop ends, the slow pointer will be at the middle of the list.
        return slow
```

**Explanation of the Code**

* **Initialization**: Both `slow` and `fast` pointers are initialized to the head of the linked list.
    
* **Traversal**: The `while` loop continues as long as `fast` and `fast.next` are not `None`. Inside the loop, `slow` moves one step (`slow = slow.next`), while `fast` moves two steps (`fast = fast.next.next`).
    
* **Termination**: When `fast` reaches the end (`None`), `slow` will be pointing to the middle of the list, which is then returned.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(N)`, where `N` is the number of nodes in the linked list. This is because we only traverse the list once, with both pointers making progress in each iteration.
    
* **Space Complexity**: The space complexity is `O(1)` since we are only using two additional pointers (`slow` and `fast`), regardless of the size of the linked list.
    

## Conclusion

Finding the middle of a linked list is a common problem that can be approached in multiple ways. The brute force approach involves traversing the list twice, which works but is not the most efficient. The slow and fast pointer technique offers an elegant and efficient solution with a time complexity of `O(N)` and a space complexity of `O(1)`. By understanding and applying this two-pointer method, you can solve this problem in a more optimal manner. This approach is a great example of how simple pointer manipulation can lead to highly efficient algorithms for linked list problems.


README for [Middle of the Linked List (Leetcode #876)](https://blog.unwiredlearning.com/middle-of-the-linked-list) was compiled from the Unwired Learning Blog.  
//### 082 File: 0881-boats-to-save-people/README.md
# Boats to Save People  (Leetcode #881)

In today's blog, we will explore the solution to a popular Leetcode problem - **881\. Boats to Save People**. This is a classic problem involving a mix of logic and optimization, often encountered in real-world rescue scenarios. We'll walk through the problem statement, consider a brute force approach, provide a useful hint, and finally discuss an efficient solution. Let’s dive in!

## Understanding the Problem Statement

The problem at hand is titled **"Boats to Save People"**. Imagine that you are managing a rescue operation, and you have a group of people with different weights, and a set of boats. Each boat has a maximum weight limit, and can hold at most two people. You need to determine the minimum number of boats required to rescue all the people.

The problem asks you to implement a function, which takes in:

1. A list of integers representing the weights of people.
    
2. An integer representing the weight limit of each boat.
    

The goal is to find out how many boats are needed to rescue all the people, given the weight limitations.

## Brute Force Approach

A common brute force approach would be to iterate through all possible pairs of people and find a combination of pairs that minimizes the number of boats used. This means checking each possible pair, seeing if they can fit in a boat, and repeating until all people are accounted for. While this approach works for small inputs, it becomes computationally expensive for larger lists, as the number of combinations grows rapidly.

The brute force method is simply too slow for larger datasets, leading us to search for a more efficient solution.

## Hint to Solve the Problem Efficiently

If you look closely at the problem, you will notice that pairing the heaviest person who is not yet in a boat with the lightest person available might often be the optimal way to minimize the number of boats. This way, we try to make the most efficient use of the boat's weight capacity, reducing the total number of trips needed.

## Efficient Solution

The provided solution leverages a **two-pointer technique** to optimize the pairing process. Here’s a step-by-step explanation of how it works:

```python
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i, j = 0, len(people) - 1
        boats = 0
        
        # Loop until the two pointers meet or cross each other
        while i <= j:
            boats += 1

            # Check if the lightest and heaviest person can share a boat
            if people[i] + people[j] <= limit:
                i += 1
            
            j -= 1

        # Return the total number of boats used
        return boats
```

In this solution:

1. **Sorting**: First, we sort the list of people's weights in ascending order.
    
2. **Two Pointers**: We use two pointers, `i` starting from the lightest person (beginning of the list), and `j` starting from the heaviest person (end of the list).
    
3. **Boat Allocation**: We then try to pair the lightest and heaviest person together. If their combined weight is within the boat's limit, we increase `i` and move to the next lightest person. In either case, we always decrease `j` to account for the heaviest person.
    
4. **Count Boats**: Each iteration represents one boat being used, and the process continues until all people are assigned boats.
    

This approach ensures that we are making the most efficient pairing possible, minimizing the total number of boats.

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is **O(n log n)**, where `n` is the number of people. This complexity comes from the initial sorting step, followed by a linear pass through the list using the two pointers.
    
* **Space Complexity**: The space complexity is **O(1)** if we consider the input list being sorted in place, or **O(n)** if the sorting algorithm requires additional space.
    

## Conclusion

The problem of **Boats to Save People** is an interesting challenge that requires both logical pairing and efficient problem-solving skills. The brute force method is good for understanding the problem, but using the two-pointer technique gives us a much more scalable solution. By sorting the people and carefully pairing the lightest and heaviest individuals, we can significantly reduce the number of boats needed.

We hope this explanation helped you understand how to solve this problem efficiently. Practice applying these techniques to similar problems, and you’ll get better at optimizing your solutions over time!

README for [Boats to Save People  (Leetcode #881)](https://blog.unwiredlearning.com/boats-to-save-people) was compiled from the Unwired Learning Blog.  
//### 083 File: 1143-longest-common-subsequence/README.md
# Longest Common Subsequence (Leetcode #1143)

The Longest Common Subsequence (LCS) problem is a fundamental dynamic programming challenge that finds applications in diverse fields, from bioinformatics to text comparison tools. In this blog, we will discuss what the problem is, explore a brute-force solution, give you a hint to think about a more optimized approach, and provide a dynamic programming-based efficient solution. Let's get started!

## Understanding the Problem Statement

The goal of the Longest Common Subsequence problem is to find the longest subsequence that appears in the same order in two strings, but not necessarily consecutively. For example, given two strings `text1 = "abcde"` and `text2 = "ace"`, the longest common subsequence is `"ace"`, and its length is `3`.

The key point here is that the characters must appear in the same order, but they do not need to be consecutive. The challenge is to find the length of this common subsequence efficiently.

## Brute Force Approach

The brute-force approach to solving this problem involves generating all possible subsequences of one string and then checking which of them are also subsequences of the other string. This can be a very time-consuming task, especially if the lengths of the strings are large.

For a string of length `m`, there are `2^m` possible subsequences. Thus, generating all subsequences and checking each one against the other string is computationally infeasible for large values of `m` and `n` due to its exponential time complexity, which is `O(2^m * n)`. This makes the brute-force approach impractical for longer strings.

## Hint to Solve the Problem Efficiently

The key to optimizing the solution for LCS is recognizing overlapping sub-problems. When we try to determine the LCS, many sub-problems repeat, and a dynamic programming approach can be used to store the results of these sub-problems and avoid redundant calculations.

In other words, rather than recalculating the LCS for the same set of prefixes multiple times, we can use a table to store these results. This approach significantly reduces the computational overhead.

## Efficient Solution

Let's dive into the efficient solution provided in the code using dynamic programming. Here's how the code works:

```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for j in range(1, n + 1):
            for i in range(1, m + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

        return dp[m][n]
```

**Detailed Explanation**

1. **Initialization**: We create a 2D list `dp` with dimensions `(m + 1) x (n + 1)` to store the lengths of the longest common subsequence for different prefixes of `text1` and `text2`. The dimensions are `(m + 1)` and `(n + 1)` to handle empty prefixes easily by initializing the base cases to zero.
    
2. **Iterating through Characters**: We use two nested loops to iterate over each character in `text1` and `text2`. If the characters match (`text1[i - 1] == text2[j - 1]`), it means that the LCS for the current prefixes includes this character, so we add `1` to the LCS length of the previous prefixes (`dp[i - 1][j - 1] + 1`).
    
3. **Handling Non-matching Characters**: If the characters do not match, we take the maximum value from either excluding the current character of `text1` or `text2` (`max(dp[i][j - 1], dp[i - 1][j])`). This way, we ensure that the longest possible subsequence is considered.
    
4. **Result**: Finally, the value in the bottom-right cell of the table (`dp[m][n]`) represents the length of the longest common subsequence of `text1` and `text2`.
    

## Time and Space Complexity

* **Time Complexity**: The time complexity of this solution is `O(m * n)`, where `m` is the length of `text1` and `n` is the length of `text2`. This is because we iterate over all characters in both strings, and for each pair of characters, we perform constant-time operations.
    
* **Space Complexity**: The space complexity is also `O(m * n)` due to the 2D array `dp` used to store the intermediate LCS lengths for all combinations of prefixes of `text1` and `text2`. This can be optimized to `O(n)` if we only store the previous row at any point, but the provided solution uses the full table for simplicity.
    

## Conclusion

The Longest Common Subsequence problem is a great example of how dynamic programming can be used to turn an inefficient brute-force approach into a highly efficient solution. By recognizing overlapping sub-problems and storing intermediate results, we can significantly reduce the computational cost of finding the LCS. The dynamic programming approach presented here runs in polynomial time, making it suitable for strings of reasonable length.

Hopefully, this blog helps you understand the LCS problem better and how to tackle it using dynamic programming. Try implementing the solution yourself, and see how the power of dynamic programming makes a challenging problem much more approachable!

README for [Longest Common Subsequence (Leetcode #1143)](https://blog.unwiredlearning.com/longest-common-subsequence) was compiled from the Unwired Learning Blog.  

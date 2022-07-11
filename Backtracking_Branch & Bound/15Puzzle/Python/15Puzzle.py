n = int(input("\nEnter the number of rows:- "))
inv = 0
num = 0
row = 0
print("\nEnter the numbers:- ", end='')
arr = list(map(int, input().split()))

for i in range(n):
    if arr[i-1] == 0:
        row = n-i+1

for i in range(0, len(arr), 1):
    for j in range(i+1, len(arr), 1):
        if (arr[i] > arr[j] and arr[i] != 0 and arr[j] != 0):
            inv += 1

print(f"\nIts a {n*n - 1} puzzle problem")
print("Number of Inversions: ", inv)
if((n % 2 == 1 and inv % 2 == 0) or (n % 2 == 0 and inv % 2 == 1 and row % 2 == 0) or (n % 2 == 0 and inv % 2 == 0 and row % 2 == 1)):
    print("Solve able")
else:
    print("Not Possible")


"""
Eg:- For 15 Puzzle Problem 
Row:- 4
Number:- 1 2 3 4 5 6 7 8 9 10 12 0 13 14 11 15
{0 is the missing/blank tile}
{Goal State:- 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0}
Ans:-
No. of Inversion:  3   
Solve able
"""

"""
Details:-
Initial State:-
1 2 3 4 
5 6 7 8
9 10 12 0
13 14 11 15


1:-->   Blank tile Left
        1 2 3 4 
        5 6 7 8
        9 10 0 12
        13 14 11 15

2:-->   Blank tile Down
        1 2 3 4
        5 6 7 8
        9 10 11 12
        13 14 0 15

3:-->   Blank tile Right
        1 2 3 4
        5 6 7 8
        9 10 11 12
        13 14 15 0

Final/Goal State
Therefore, Number of Inversions:- 3
"""

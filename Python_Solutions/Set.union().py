# Enter your code here. Read input from STDIN. Print output to STDOUT
a=int(input())
arr1=set(map(int,input().split()))
b=int(input())
arr2=set(map(int,input().split()))
new_arr=arr1.union(arr2)
print(len(new_arr))

# Enter your code here. Read input from STDIN. Print output to STDOUT
a=int(input())
arr_1=set(map(int,input().split()))
b=int(input())
arr_2=set(map(int,input().split()))
new_arr=arr_1.intersection(arr_2)
print(len(new_arr))

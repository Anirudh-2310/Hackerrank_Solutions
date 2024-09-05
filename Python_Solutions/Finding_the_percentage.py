if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    x=list(student_marks[query_name])
    ans=sum(x)/len(x)
    print("%0.2f"%ans)
    

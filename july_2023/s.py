
# void main()
# {
#     int x, *y, **z;
#     x=6;
#     y=&x;
#     z=&y;
#     print("%d", func(x,y,z));
# }
# int func(m, *n, **o)
# {
#     int p,q;
#     *n *= 2;
#     p = *n;
#     **o -= 5;
#     q = **o;
#     return p - m + q;
# }

# def fun(per):
#     if(per<= 0):
#         return 1**2
#     else:
#         return fun(per-3)


# x= lambda y: fun(y+2) if y == 0 else fun(y+5)        
# y= lambda z: x(z-2) + 1 if z!= 0 else 1       
# print (y(10))




# def rec_fun(per):

#     if per<=1:
#         return 1
    
#     x = 1+ rec_fun(per//2)+ rec_fun(per//2)
#     return x + rec_fun(per-2)

# print(rec_fun(5))
















# def fun(per):
#     if per<=0:
#         return per+1;
#     else:
#         return fun(per//2) + fun(per//3)

# x = {2:3, 3:2, 1:2, 2:1}
# y = [i for i in x]
# z = y[0] + x[2]
# for x in y:
#     z += x

# print(fun(z))




# def rec_fun(a):
#     if a <= 0:
#         return 1
#     return 1 + rec_fun(a-2)

# def rec_fun(a,b):
#     if a<=0 or b<=0:
#         print(rec_fun(a)+rec_fun(b))
#         rec_fun(a-b,b-a)

# # rec_fun(4,2)
# print(rec_fun (4,2))





# import pandas as pd 
# students = {'wing 1' : {'s.no' : 1, 'name':'ram'},'wing 2' : {'s.no' : 2,'name': 'ajay'}}
# frame = pd.DataFrame(students)
# print(frame)


# output 

# wing 1 wing 2
# s.no      1      2
# name    ram   ajay





# Date1 = "15Dec1989"
# y=pd.to_datetime(Date1, format='%d%b%Y')
# dt.strftime(y, "%A,%d %b %y")

# output   Friday,15 Dec 89

# Function to find inversion count of a given list
# def findInversionCount(A):
 
#     inversionCount = 0
#     for i in range(len(A) - 1):
#         for j in range(i + 1, len(A)):
#             if A[i] > A[j]:
#                 inversionCount = inversionCount + 1
 
#     return inversionCount
 
 
# if __name__ == '__main__':
 
#     A = [18,17,21,19,25,14,12,35]
#     print("Inversion count is", findInversionCount(A))
 







# def fun(*var):
#     if(var[0] <=0):
#         return 1
#     x =  var[0]
#     y = x >> 2
#     return fun(y) + fun(y)
# print(fun(100,99,98))

import numpy
x = " 1 2.4 3.9 4 5. 7 6 7"
y = [abs(float(i)) for i in x.split()]
z = numpy.array([a for a in y])
p = numpy.split(z,2)
print(p[1][0] + 4 ** 2)
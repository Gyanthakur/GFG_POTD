
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

def fun(per):
    if per<=0:
        return per+1;
    else:
        return fun(per//2) + fun(per//3)

x = {2:3, 3:2, 1:2, 2:1}
y = [i for i in x]
z = y[0] + x[2]
for x in y:
    z += x

print(fun(z))
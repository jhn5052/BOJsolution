ls = list(input())
ls_len = len(ls)
ls_mid = 0
flag = 0

if ls_len%2 > 0:
    ls_mid = len(ls)//2
    flag += 1
else:
    ls_mid = len(ls)/2
ls_mid = int(ls_mid)
trans_ls = list(''.join(ls[:ls_mid]))
trans_ls = trans_ls[-1::-1]

if flag > 0:
    new_str = ls[:ls_mid+1] + trans_ls
else:
    new_str = ls[:ls_mid] + trans_ls
new_str = ''.join(new_str)
num = int(new_str)
new_str = list(new_str)
ls = ''.join(ls)

if ls_len == 1:
    if int(ls[0]) < 9:
        print(int(ls[0])+1)
    elif int(ls[0]) == 9:
        print(11)
elif num <= int(ls):
    if flag > 0: #홀수
        new_str[ls_mid] = str(int(new_str[ls_mid]) + 1)
    elif flag == 0:
        new_str[ls_mid-1] = str(int(new_str[ls_mid-1]) + 1)
        new_str[ls_mid] = str(int(new_str[ls_mid]) + 1)
    print(''.join(new_str))
else:
    print(''.join(new_str))
from random import uniform
from time import sleep
#初始化
def INLTION(user_name):
    try:
        dat = open(user_name+".txt","r")#读入数据
        global name
        name=user_name+".txt"
        global Money
        Money = float(dat.readline())
    except:#文件不存在，创建新的用户
        dat = open(user_name+".txt","w")
        dat.write("0.0")
        name=user_name+".txt"
        Money = 0.0
    global Deposit_Interest
    Deposit_Interest = float(uniform(2.00,3.00))

    global Loan_Interest
    Loan_Interest = float(uniform(3.00,5.00))

#存钱
def savings(sav):
    data1 = open(name,"w")
    global Money
    if(sav < 0):
        print("Error:存款金额小于0元\n")
        sleep(3)
    else:
        Money = Money + sav 
        data1.write(str(Money))
        print("当前余额： %.2f 元\n" % Money)
        sleep(3)

#取钱
def withdraw(wit):
    data2 = open(name,"w")
    global Money
    if(wit < 0):
        print("Error:取款金额小于0元\n")
        sleep(3)
    elif(wit > Money):
        print("Error:取款金额大于余额\n")
        sleep(3)
    else:
        Money = Money - wit 
        data2.write(str(Money))
        print("当前余额: %.2f 元\n" % Money)
        sleep(3)


#贷款
def loan(loan_money=0.0,loan_time=1):
    interest= (loan_money * float(loan_time) * (Loan_Interest/100.0))
    lmli=float(interest + loan_money)
    print("贷款%.2f元,%d年后应还款%.2f元\n" %(loan_money,loan_time,lmli))
    sleep(3)

#预计资产
def contingent_asset(years):
    return float(((Money*Deposit_Interest/100.0)*years)+Money)

def main():
    sleep(3)
    print("今日贷款利息：百分之%.2f" %(Loan_Interest))
    sleep(3)
    print("今日存款利息：百分之%.2f" %(Deposit_Interest))
    sleep(3)
    while True:
        print('''你可以：
        1: 查询余额
        2: 存钱
        3: 取钱
        4: 计算贷款
        5: 预计资产
        other:退出''')

        message = input()

        try:
            if (message=='1'):
                print("当前余额:%.2f元" % Money)
                sleep(3)

            elif (message=='2'):
                savings(float(input("请输入存款金额: ")))

            elif (message=='3'):
                withdraw(float(input("请输入取款金额: ")))

            elif (message=='4'):
                lm = float (input ("贷款金额："))
                lt = int (input ("贷款时长(年):"))
                loan(lm,lt)

            elif (message=='5'):
                years=int(input ("预计时间(年):"))
                print("%d年后预计资产: %.2f元" %(years,contingent_asset(years)))
                sleep(3)
        
            else :
                print("欢迎下次光临!")
                sleep(3)
                exit()
        except:
            print("Error: 请重试")

if __name__ == "__main__":
    INLTION("data")
    main()
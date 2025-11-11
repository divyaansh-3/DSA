#WAP that prompts the user to enter numbers. Once the user enters any negative number, it displays the count, sum, and average of odd numbers.*/
count=0
sum=0
average=0
while True:
    num=int(input("Enter a number(negative to stop):"))
    if num<0:
        break
    if num%2!=0:
        count+=1
        sum+=num
if count>0:
    average=sum/count
    print("total odd numbers entered is: ",count)
    print("\n sum of all the odd numbers is: ",sum)
    print("\n average is: ",average)    
else:
    print("\n no odd numebrs entered")

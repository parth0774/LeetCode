class Solution:
    def reverse(self, x: int) -> int:
        max,min=2**31-1,-2**31
        negetive = x<0
        result=0
        x=abs(x)
        while x!=0:
            digit=x%10
            x//=10

            if result > (max-digit)//10:
                return 0
            result=result*10+digit
        return -result if negetive else result

def main():
    solution=Solution()
    num=123
    a=solution.reverse(num)
    print(a)
    num=-123
    b=solution.reverse(num)
    print(b)
if __name__=="__main__":
    main()
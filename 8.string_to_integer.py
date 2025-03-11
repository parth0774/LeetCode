class Solution:
    def myAtoi(self, s: str) -> int:
        #Step-1 removing whitespace using lstrip()
        s=s.lstrip()

        # if its empty
        if not s:
            return 0
        #step-2 default postive and then postive and negetive check
        sign=1
        if s[0]=="-":
            sign=-1
            s=s[1:]
        elif s[0]=="+":
            sign=1
            s=s[1:]
        
        result=0

        #step-3 converting the string to int
        for char in s:
            if char.isdigit():
                result = result*10+int(char)
            else:
                break
        result*=sign

        #step-4 rounding if they exceed int 32 limit
        max=2**31-1
        min=-2**31
        if result<min:
            return min
        if result>max:
            return max
        print(result)
    
def main():
    solution=Solution()
    s="42"
    a=solution.myAtoi(s)
    print(a)

if __name__=="__main__":
    main()
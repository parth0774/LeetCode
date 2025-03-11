class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        y=int(str(x)[::-1])
        if x==y:
            return True
        else:
            return False
def main():
    solution=Solution()
    num=-121
    print(solution.isPalindrome(num))

if __name__=="__main__":
    main()
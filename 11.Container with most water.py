from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area=0
        n=len(height)
        for i in range(n):
            for j in range(i+1,n):
                area=(j-i)*min(height[j],height[i])
                max_area=max(area,max_area)
        return max_area
        
def main():
    solution=Solution()
    height = [1,8,6,2,5,4,8,3,7]
    print(solution.maxArea(height))

if __name__=="__main__":
    main()
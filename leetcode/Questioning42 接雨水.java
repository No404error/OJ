public class Question42 {
    public static void main(String[] args) {
        Solution s=new Solution();
        int[] p=new int[]{4,2,0,3,2,5};
        int trap = s.trap(p);
        System.out.println(trap);
    }
}



class Solution {
    public int trap(int[] height) {
        int leftPointer=0;
        int rightPointer=height.length-1;
        int leftWall=height[leftPointer];
        int rightWall=height[rightPointer];
        int sum=0;

        //获得第一道左墙
        while (leftWall==0){
            leftPointer++;
            //超界
            if(leftPointer>=height.length)
                break;
            leftWall=height[leftPointer];
        }


        //获得第一道右墙
        while (rightWall==0){
            rightPointer--;
            //超界
            if(rightPointer<0)
                break;
            rightWall=height[rightPointer];
        }

        while (rightPointer>leftPointer){
            //从矮墙开始接水
            if(leftWall<rightWall){
                while(leftWall>=height[leftPointer]){
                    //接完水了
                    if(rightPointer==leftPointer)
                        break;
                    sum+=leftWall-height[leftPointer];
                    leftPointer++;
                }
                leftWall=height[leftPointer];
            }
            else {
                while(rightWall>=height[rightPointer]){
                    //接完水了
                    if(rightPointer==leftPointer)
                        break;
                    sum+=rightWall-height[rightPointer];
                    rightPointer--;
                }
                rightWall=height[rightPointer];
            }
        }
        return sum;
    }
}
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
    // int rev =0;
    // int rem ;
    // int temp = n;
    // while(n > 0){
    //     rem = n % 10;
    //     rev = (rev * 10) + rem;
    //     n = n / 10;

    // }
    // if(temp ==rev){
    //     return true;
    // }
    // else {
    //     return false;
    // // }
    // }
};
import java.lang.reflect.Array;
import java.util.*;

public class a {

    public static void main(String[] args) {
        int[] digits = { 1, 2, 3 };
        int[] result = new Solution().plusOne(digits);
        System.out.println(Arrays.toString(result));

    }

    static class Solution {
        int[] add(int[] digits, int a) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            int t = 0;
            boolean flage = false;
            for (int i = digits.length - 1; i >= 0; i--) {
                t += digits[i];
                if (!flage) {
                    t += a;
                    flage = true;
                }
                ans.add(t % 10);
                t /= 10;
            }
            if (t > 0)
                ans.add(t);
            return ans.stream().mapToInt(i -> i).toArray();
        }

        public int[] plusOne(int[] digits) {
            int n = digits.length;
            int i = n - 1;

            while (i >= 0 && digits[i] + 1 == 10) {
                digits[i] = 0;
                --i;
            }
            if (i < 0) {
                int[] newdigits = new int[n + 1];
                newdigits[0] = 1;

                return newdigits;
            } else {

                ++digits[i];
                return digits;
            }
        }
    }
}

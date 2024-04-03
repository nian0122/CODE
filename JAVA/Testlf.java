import java.util.*;
public class Testlf {
    public static void main(String []args){
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        if(a >= 90){
            System.out.println("等级为优秀");
        }
        else if(a < 90 && a >=60){
            System.out.println("等级为合格");
        }
        else System.out.println("等级为不合格");
   } 
}

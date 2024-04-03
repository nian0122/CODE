import java.util.*;
public class TestSwitch {
    public static void main(String []args){
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        switch (a / 10) {
            case 10:
            case 9:
                System.out.println("等级为优秀");
                break;
            case 8:
            case 7:
            case 6:
                System.out.println("等级为合格");
                break;
            default:
                System.out.println("等级为不合格");
        }
    } 
}

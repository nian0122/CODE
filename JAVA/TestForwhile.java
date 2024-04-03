import java.util.*;

public class TestForwhile {
    
    public static boolean fin(int x)
    {
        if(x==1) return false;
        for(int i=2;i*i<=x;i++)
            if(x%i==0) return false;
        return true;     //1为素数
    }
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        if(fin(a))System.out.println("是素数");
        else System.out.println("不是素数");
    }
}
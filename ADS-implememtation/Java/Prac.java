import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class a{
    static{
        System.out.println("Static");
    }
    {
        System.out.println("Static2");
    }
    a(){
        System.out.println("initialized");
    }
    public void func(){
        System.out.println("function");
    }
}

class b extends a{

}

class c extends b{
    static class d{

    }
    class e{}
}

class f extends c{

}


public class Prac {
    public static void main(String args[]) throws Exception{
        a a = new f();
    }
}

package DesignPatterns.SingletonPattern;

//eager_way
public class Jalebi {
    //object is created at the very beginning even if not needed
    private static Jalebi jalebi = new Jalebi();
    
    public static Jalebi getJalebi(){
        return jalebi;
    }
}

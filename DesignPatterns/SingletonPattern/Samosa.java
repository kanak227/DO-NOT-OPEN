package DesignPatterns.SingletonPattern;

//lazy_way

public class Samosa{
    //create an variable to store whether the object is created ot not
    private static Samosa samosa;

    // previate constructor created so that object cannot be created using it
    private Samosa(){};

    //method to create objects after checking whether created previously or not
    public static Samosa getSamosa(){
        
        if(samosa == null){
            // synchronized used to avoid multiple object creation at the time of threading
            synchronized(Samosa.class){
                return new Samosa();
            }
        }
        return samosa;
    }

}
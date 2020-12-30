package game;

import java.io.InputStream;

public class Resource {

    public static InputStream getStream(String name){
        return Resource.class.getResourceAsStream("/"+name);
    }

}

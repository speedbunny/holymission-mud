inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "The upper sanctum of the Jedi Guild";     
        long_desc = "\
These are the long hidden upper sanctums of the Jedi Guild.  For many years the \
secret dwelling place of Yoda and his followers, they now serve as a place of \
inspiration and recouperation for Jedi Knights.  Red stone walls surround the \
area, and the air here is fresh and clean, revitalising inner energies and concentration.\n";

        dest_dir = ({
            "/players/mangla/guild/room",  "down",
            "/players/mangla/guild/corridor1",  "east",

        });


         items = ({
             "sanctums", "The long hidden sanctums of the Jedi Guild",            
             "walls", "Made from red stone, these walls secured the sanctum.",
             "air", "Clean air, revitalising your body.",       
             "place", "The upper sanctums of the jedi guild",

             
        });    
   
    }
    ::reset(arg);
    replace_program("room/room");
}


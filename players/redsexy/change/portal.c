inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "A long corridor in the lower sanctum of the Jedi Guild";     
        long_desc = "\
You have reached the end of the corridor, and stand before a swirling mass \
of light and confusion.  As pretty as it seems, it doesn't seem to have any \
purpose except to provide illumination for the lower sanctums.... \n";

        dest_dir = ({
            "/players/mangla/guild/rooms/corridor2",  "east",
        });


         items = ({
             "corridor", "You are at the end of the corridor",            
             "mass", "Trust me, there will be something here by the end of March...",
             "light", "Trust me, there will be something here by the end of March...",
             "confusion", "Trust me, there will be something here by the end of March...",
        });    
   
    }
    ::reset(arg);
    replace_program("room/room");
}


inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "A long corridor in the lower sanctum of the Jedi Guild";     
        long_desc = "\
This long corridor stretches the full length of the lower sanctums, heading \
towards a mysterious light just west of here. The walls have paintings of \
distant lands on them, and a small bust stands firm in the middle of this \
corridor.  South of here is the sanctum storage facility.\n";

        dest_dir = ({
            "/players/mangla/guild/rooms/borrow", "south",
            "/players/mangla/guild/rooms/portal",  "west",
            "/players/mangla/guild/rooms/corridor1",  "east",

        });


         items = ({
             "corridor", "A long corridor leading towards a bright light in the south",            
             "sanctums", "The upper sanctums of the Jedi Guild",
             "floor", "The wooden floor has a few giant bantha rugs laid down on it",       
             "rugs", "No bantha's were harmed during the manufacture of these furry white rugs",
             "wall", "A red stone wall",
             "walls", "Red stone walls",
             "paintings", "The paintings depict a dry and barren lands, far from here.",
             "bust", "The bust is a likeness of the great Jedi Master, Yoda",
             "light", "The light seems to be shining from the far end of the corridor",
        });    
   
    }
    ::reset(arg);
    replace_program("room/room");
}


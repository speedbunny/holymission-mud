inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "A long corridor in the upper sanctum of the Jedi Guild";     
        long_desc = "\
This long corridor stretches the full length of the upper sanctums, heading \
towards a mysterious light just south of here. The walls have paintings of \
distant lands on them, and a small bust stands firm in the middle of this \
intersection.  You can smell something tempting to the west and a the sound \
of chattering and laughter seems to drift this way from the east. \n";

        dest_dir = ({
            "/players/mangla/guild/portal",  "south",
            "/players/mangla/guild/corridor1",  "north",
            "/players/mangla/guild/bar",  "east",
            "/players/mangla/guild/food",  "west",

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
             "intersection", "The corridor forks left and right here",
        });    
   
    }
    ::reset(arg);
    replace_program("room/room");
}


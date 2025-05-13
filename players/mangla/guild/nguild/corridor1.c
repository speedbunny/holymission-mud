inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "A long corridor in the upper sanctum of the Jedi Guild";     
        long_desc = "\
This long corridor stretches west into the the depths of the lower sanctums. \
The floor is carpeted with bantha rugs, snow white and furry beneath your feet, \
whilst the stone brick walls have various plaques and signs mounted upon them. \
A bright light eminates from the far end of the hall, enticing yet meanacing. \n";

        dest_dir = ({
            "/players/mangla/guild/rooms/caperoom",  "east",
            "/players/mangla/guild/rooms/corridor2",  "west",

        });


         items = ({
             "corridor", "A long corridor leading towards a bright light in the south",            
             "sanctums", "The upper sanctums of the Jedi Guild",
             "floor", "The wooden floor has a few giant bantha rugs laid down on it",       
             "rugs", "No bantha's were harmed during the manufacture of these furry white rugs",
             "wall", "A red stone wall",
             "plaques", "A number of motto plaques, one you can see reads: Use the Force",
             "signs", "A number of signs with mottos on them, one you can read says: Beware the Sarlacc",
             "light", "The light seems to be shining from the far end of the corridor",
        });    
   
    }
    ::reset(arg);
    replace_program("room/room");
}


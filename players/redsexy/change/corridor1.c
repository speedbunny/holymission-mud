inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "A long corridor in the lower sanctums of the Jedi Guild";     
        long_desc = "\
This long corridor stretches west into the the depths of the lower sanctums. \
The floor is carpeted with bantha rugs, snow white and furry beneath your feet, \
while the stone brick walls have various plaques and signs mounted upon them. \
A bright light eminates from the far end of the hall, enticing yet meanacing. \n";

        dest_dir = ({
            "/players/mangla/guild/rooms/caperoom",  "east",
            "/players/mangla/guild/rooms/corridor2",  "west",

        });


         items = ({
             "corridor", "A long corridor leading towards a bright light in the south",            
             "sanctums", "The lower sanctums of the Jedi Guild",
             "floor", "The wooden floor has a few giant bantha rugs laid down on it",       
             "rugs", "No bantha's were harmed during the manufacture of these furry white rugs",
             "wall", "A red stone wall",
             "plaques", "A number of motto plaques, one you can see reads: Use the Force",
             "light", "The light seems to be shining from the far end of the corridor",
             "sign", "The sign reads: The Dark Side is the Powerful Side ",
             "signs", "The signs boast about the virtues of each side of the force",
        });    
   
    }
    ::reset(arg);
    replace_program("room/room");
}


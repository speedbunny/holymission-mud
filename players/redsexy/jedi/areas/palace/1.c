inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "The kitchens of Jabba's palace.";     
        long_desc = "\
These are the kitchens of Jabba's palace.  They are kept spotlessly clean, and   \
you realise whoever works here must be very conscientious of his work.  Pots and \
pans are on the boil, and you realise that the chef must be around here somewhere \
cooking up culinary delights for Jabba and his guests. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/2",  "east",
            "/players/redsexy/jedi/areas/palace/3", "south",

        });


         items = ({
             "kitchens", "You can tell it is a kitchen because there is a stove here!",            
             "pots", "Old iron pots on the boil",
             "pans", "Old iron pans, frying up some food",       
             "chef", "He isn't here, but you assume he is around somewhere!",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}



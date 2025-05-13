inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A narrow corridor in Jabba's Palace";     
        long_desc = "\
This narrow corridor seems to lead to a more elegant side of the palace.  Black curtains \
decorated with gold emblems are draped down either side, and sunlight filters in slightly \
creating a light that fills the whole room without being too harsh.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/11",  "north",
            "/players/redsexy/jedi/areas/palace/8",   "south",

        });


         items = ({
             "corridor", "The corridor is very narrow, considering a Hutt lives here",            
             "curtains", "Elegant black velvet curtains embrodiered in gold thread",
             "sunlight", "Sunlight lights this room perfectly.",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}



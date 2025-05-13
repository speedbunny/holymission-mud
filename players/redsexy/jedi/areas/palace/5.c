inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A work area in Jabba's palace.";     
        long_desc = "\
This area is obviously where the workers go about their everyday tasks, the floor is \
covered in tiles and it is a lot warmer in here, the expense of ventilation spared.   \
Nevertheless, the place is immaculate, the floor freshly mopped and the walls scrubbed \
to perfection.  It is obvious that Jabba keeps his workers on a tight leash! \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/7",  "east",
            "/players/redsexy/jedi/areas/palace/6",  "west",
            "/players/redsexy/jedi/areas/palace/4",  "north",

        });


         items = ({
             "floor", "The floor is covered in tiles",            
             "tiles", "The freshly mopped tiles make it slippy underfoot!",
             "ventilation", "There is no ventilation in here and the heat from the desert \
makes it rather uncomfortable",       
             "temperature", "If you don't get out of here soon you'll boil!",
             "walls","The marble walls have been scrubbed very recently",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}



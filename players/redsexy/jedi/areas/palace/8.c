inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A watchstation in Jabba's Palace";     
        long_desc = "\
This area is set out as a guard watch station and you begin to wonder what could be \
so valuable that it is so heavily guarded.  You see nothing of any worth in here, and \
as far as you can tell only the banquet halls lie to north and the reading rooms to \
the east.   However, you know that Jabba is no fool, and if he has placed a guard room \
here then there must be good reason.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/9",  "east",
            "/players/redsexy/jedi/areas/palace/10", "north",
            "/players/redsexy/jedi/areas/palace/7",  "west",

        });
        clone_list = ({

           1, 1,"guard","players/redsexy/jedi/monsters/guard",0,
         });


         items = ({
             "station", "This is a guard watch station, set up here to keep unwanted visitors \
out",            
             "halls", "All you can see to the north are banquet halls",
             "reading", "All you can see to the east is a reading room",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}



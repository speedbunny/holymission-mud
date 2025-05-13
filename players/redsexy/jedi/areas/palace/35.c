#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
   ::reset(arg);


        set_light(0);

        short_desc = "A balcony upstairs in the palace.";  
        long_desc = "\
You have reached the landing of the elegant staircase and stand looking over the \
balcony towards the storerooms.  These are Jabba's living quarters, immaculately \
clean and elegantly decorated.  The landing continues to your south, overlooking  \
the courtyards of the palace, whilst a finely crafted pinewood door blocks an entry \
to your east. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/36", "south",

        });

        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/25", "down",
            "/players/redsexy/jedi/areas/palace/34", "east",
        });


         items = ({
             "door","A pinewood door",
             "staircase", "An elegantly decorated staircase",
             "landing", "You stand at the top of the staircase",
             "storerooms", "You can see the vast shelves of the storeroom below you\
from the top of the staircase",
             "decorations", "Expensive jewels and gems glitter from the walls",       
             "courtyard", "You cannot see the courtyard from here",
             "pinewood", "The craftsmanship is astounding",
       });

        set_door          ( "pinewood door" );
        set_door_desc     ( "pinewood door", "A pinewood door" );
        set_door_direction( "pinewood door", "east" );
        set_lock_status   ( "pinewood door", DOOR_LOCKED - 1 );
        set_invisible_doors( ({ "pinewood door" }) );
        set_other_door    ( "pinewood door" );
        replace_program( DOOR_ROOM );
}




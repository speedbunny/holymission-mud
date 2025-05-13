#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
   ::reset(arg);

        set_light(1);

        short_desc = "The landing in Jabba's Palace.";     
        long_desc = "\
The landing continues here, overlooking the courtyards that Jabba has somehow managed\
to cultivate on such a dry and barren realm.  You can see the trees swaying gently in  \
the calm desert breeze from here, a real oasis hidden in the depths of the desert.  \
A pinewood door blocks your entry into the eastern room, but to the north you can see  \
the elegant staircase leading back into the palace. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/35", "north",

        });

        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/37", "east",
        });


         items = ({
             "door","A pinewood door",
             "staircase", "An elegantly decorated staircase",
             "landing", "You stand at the top of the staircase",
             "courtyards", "The green coolness of the courtyards below you is enchanting,\
if only you knew how to get there",
             "trees", "The green coolness of the courtyards below you is enchanting,\
if only you knew how to get there",             
             "oasis", "The green coolness of the courtyards below you is enchanting,\
if only you knew how to get there",
             "pinewood", "The craftsmanship is astounding",
       });
 
        set_door          ( "pinewood door" );
        set_door_desc     ( "pinewood door", "A pinewood door" );
        set_invisible_doors( ({ "pinewood door" }) );
        set_door_direction( "pinewood door", "east" );
        set_lock_status   ( "pinewood door", DOOR_LOCKED + 1 );
        set_door_key      ( "pinewood door", "jabba_throne" ); 
        set_other_door    ( "pinewood door" );
        replace_program( DOOR_ROOM );
}




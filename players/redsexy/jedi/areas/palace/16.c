#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
   ::reset(arg);

        set_light(1);

        short_desc = "A long hallway leading through Jabba's Palace.";     
        long_desc = "\
This long hallway stretches the full legnth of Jabba's palace, from the greeting \
hall to the storerooms.  The blue carpet is so soft to walk on, and the air is so \
refreshingly cool in here, you wonder why people always moan about the conditions \
that Jabba lives in.  The marble walls have many paintings hung on them. There is a door that \
that leads to the storerooms set in the south wall.  \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/7", "north",

        });

        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/17", "south",
        });
 
         items = ({
             "door", "A door",
             "hallway", "A long hallway running through Jabba's palace",            
             "walls", "They seem to be made of marble, and various paintings \
hang on them",
             "paintings", "These mainly seem to be portraits of local dignitaries \
and family",       
             "pictures", "These mainly seem to be portraits of local dignitaries \
and family",       
             "floor", "The floor is carpeted in rich blue, and the carpet continues \
to the south",
             "carpet", "This carpet is a very royal blue, and unspoilt",
             "storerooms", "You can see the storerooms just to the south",
             "air", "The marble walls make the air in here cool, a refreshing change \
from the desert",
       });
 
        set_door          ( "door" );
        set_door_desc     ( "door", "An oaken wood door" );
        set_door_direction( "door", "south" );
        set_lock_status   ( "door", DOOR_LOCKED + 1 );
        set_invisible_doors( ({ "door" }) );
        set_door_key      ( "door", "jabba_1" );
        set_other_door    ( "door" );
        replace_program( DOOR_ROOM );
}




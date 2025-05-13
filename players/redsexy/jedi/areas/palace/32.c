#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
     ::reset(arg);

        set_light(0);

        short_desc = "A muddy hole underneath the palace.";     
        long_desc = "\
You venture deeper into the darkness and stand in a cramped up hole \
secured with mud.  The ceiling drips slightly, leaving a puddle of mirky water \
on the floor, and it is so uncomfortable in here you do not want to stay a minute \
longer than you have to.  There is a door of some kind to your east, and terrible \
screams eminate from that direction. \n\n";
         
        

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/30", "north",

        });

        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/33", "east",
        });


         items = ({
             "door","A solid dungeon door",
             "staircase", "A sturdy metalic staircase",
             "mud","Damp, slimy mud",
             "puddle", "A puddle of mirky water formed by the drips coming from the\
ceiling",
             "water", "A puddle of mirky water",       
             "hole", "This place is so tiny it seems just like a hole",
             "screams", "Cries of pain and agony from whatever lies to your east",
       });


 
        set_door          ( "door" );
        set_door_desc     ( "door", "A solid dungeon door" );
        set_invisible_doors( ({ "door" }) );
        set_door_direction( "door", "east" );
        set_lock_status   ( "door", DOOR_LOCKED + 1 );
        set_door_key      ( "door", "jabba_3" ); 
        set_other_door    ( "door" );
        replace_program( DOOR_ROOM );
}




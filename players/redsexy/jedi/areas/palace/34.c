#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
   ::reset(arg);

        set_light(1);

        short_desc = "Jabba The Hutt's Bathroom.";     
        long_desc = "\
You have fallen upon Jabba the Hutt's bathroom.  The smell here is foul - regurgitated \
dog turds and snailslime make you retch to the stomach, but you cannot help but notice the \
size of the bath he has in here, and think about how relaxing it would be to take a soak right \
now \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/bath",  "bathtub",
        });



        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/35", "west",
        });


         items = ({
             "bathroom","A smelly, grimy bathroom, where Jaba the Hutt does his business",
             "turds","Smelly, stucky, regurgitated dog turds",
             "snailslime", "The great delicacy of slime from a snail",
       });


 
  set_door          ( "pinewood door" );
  set_door_dependent( "pinewood door", "/players/redsexy/jedi/areas/palace/35" );
  replace_program( DOOR_ROOM );
}






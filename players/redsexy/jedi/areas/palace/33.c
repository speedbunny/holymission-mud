#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
        
        clone_list = ({
           1, 1,"skeleton","players/redsexy/jedi/objects/skeleton",0,
         });


   ::reset(arg);

        set_light(-1);

        short_desc = "A dungeon in the depths of the palace.";     
        long_desc = "\
You dread to imagine what desperate measures the prisoners who were kept here went \
to whilst trying to survive as a slave of Jabba the Hut.  Barely 5 cubic feet, its a surprise \
you can squeeze in here. The blackness tears into your soul, making you feel depressed. \n\n";


        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/32", "west",
        });


         items = ({
             "door","A solid door",
             "mud","Damp, slimy mud",
             "hole", "This place is so tiny it seems just like a hole",
             "floor","Squelchy mud underfoot",
             "skeletons","Skletons suggest that the last people who lived here started to eat \
each other!",
             "dungeon", "This place is not even fit for an animal",
       });
 
  set_door          ( "door" );
  set_door_dependent( "door", "/players/redsexy/jedi/areas/palace/32" );
  replace_program( DOOR_ROOM );
}






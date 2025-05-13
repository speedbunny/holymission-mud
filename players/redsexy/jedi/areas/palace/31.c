#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     
      clone_list=({
          1,1,"savage","obj/monster", ({
          "set_name","savage",
          "set_long","A savage human who looks as if he has been locked up here for years.\n",
          "set_race","whore",
          "set_level",20,
          "set_gender",2,
          "set_wc",30,
          "set_ac",11,
    }),
});

   ::reset(arg);

        set_light(-1);

        short_desc = "A dungeon in the depths of the palace.";     
        long_desc = "\
Rat droppings and skeletons of small furry animals lie scattered all over the floor of \
this dungeon - if you could even call it a dungeon.  Barely 5 cubic feet, its a surprise \
you can squeeze in here. The blackness tears into your soul, making you feel depressed. \n\n";


        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/30", "west",
        });


         items = ({
             "door","A solid door",
             "mud","Damp, slimy mud",
             "hole", "This place is so tiny it seems just like a hole",
             "droppings","The excretement of animals who live here covers the floor",
             "floor","Squelchy mud underfoot",
             "animals","Skeletons of small furry animals",
             "skeletons","Skletons suggest that the last person who lived here started to eat \
their animal visitors",
             "dungeon", "This place is not even fit for an animal",
       });
 
  set_door          ( "door" );
  set_door_dependent( "door", "/players/redsexy/jedi/areas/palace/30" );
  replace_program( DOOR_ROOM );
}






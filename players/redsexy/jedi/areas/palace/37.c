#include <doorroom.h>
inherit DOOR_ROOM;

void reset(int arg) {     

      clone_list=({
          1,3,"servant","obj/monster", ({
          "set_name","servant",
          "set_long","A weak looking servant attending to Jabba's every need.\n",
          "set_race","human",
          "set_level",10,
          "set_gender",1,
          "set_wc",15,
          "set_ac",7,
    }),
          2, 1, "jabba", "/players/redsexy/jedi/monsters/jabba", 0,

  });

   ::reset(arg);

        set_light(1);

        short_desc = "Jabba The Hutt's Throneroom.";     
        long_desc = "\
This is Jabba the Hutt's Throneroom and Bedroom rolled into one.  He does not trust his \
associates to sleep apart from him in case they discuss plots to overthrow him, so it is \
here he spends most of his days, surrounded by protectors and enemies alike.  The throne he sits \
on is a large iron chair, adjusted for someone his size.  If he wants to sleep, it takes three \
people to lower the back of the chair for comfort.  Everyone in here looks very nervous, afraid \
they may displease the mighty Jabba \n\n";


        hidden_dir = ({
            "/players/redsexy/jedi/areas/palace/36", "west",
        });


         items = ({
             "throne","A large iron adjustable seat",
             "chair", "A large iron adjustable seat",
       });

 
  set_door          ( "pinewood door" );
  set_door_dependent( "pinewood door", "/players/redsexy/jedi/areas/palace/36" );
  replace_program( DOOR_ROOM );
}






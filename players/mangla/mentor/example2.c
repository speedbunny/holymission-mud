/* Sample file for new wizzes to use as example.                */
/* All items in this conform to the newbie_doc specifications.  */

inherit "room/room";

#include "/players/mangla/defs.h"

/* This room wil contain a monster, an item on the monster      */
/* and an item in the room.                                     */

reset(arg) {

    short_desc="Generic Room2";

    long_desc="Sample room for newbie wizzes to view and notice the coding " +
              "style used in. If this room were to go into the mud there " +
              "might actually be something worth reading in here, but as it " +
              "is there is not, you can just read this. There is a " +
              "monster here though. You could kill it or leave it to kill " +
              "some other unsuspecting prey.\n";

    set_light(1);    /* minimum light level needed to see without     */
                     /*     a light source.  (Torch = 1 light level)  */

    items=({"nothing","you see alot of nothing in here",
            "room","Yep that is what it is",
          });

    property=({ "no_teleport" });   /* also availible no_fight and  */
                                    /*     no_steal                 */

    smell="Since there is nothing else here, you smell your feet.\n";

    dest_dir=({"/room/church","north",
               "/room/adv_guild","south",
               "/room/shop","east",
             });

    clone_list=({ 1, 1, "rat", "obj/monster", ({"set_name","rat",
                                                 "set_alias","rat",
                                                 "set_race","rat",
                                                 "set_level",4,
                                                 "set_long","A ugly rat",
                                                 "set_short","a rat",
                                                 "set_ac",2,
                                               }),
                 -1, 1, "claw", "obj/weapon", ({"set_name","claw",
                                                 "set_wc",4,
                                                 "set_alias","rat claw",
                                                 "set_weight",1,
                                                 "set_value",20,
                                               }),
                  2, 1, "cheese", "obj/treasure", ({"set_name","Golden cheese",
                                                    "set_alias","cheese",
                                                    "set_weight",2,
                                                    "set_value",30,
                                                    "set_short","gold cheese",
                                                    "set_long",
                                                     "A slice of golden cheese",
                                                  })
              });

    ::reset(arg);

    replace_program("room/room");
}


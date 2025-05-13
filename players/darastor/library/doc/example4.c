/* Sample file for new wizzes to use as example.                */
/* All items in this conform to the newbie_doc specifications.  */

inherit "room/room";

#include "/players/mangla/defs.h"

/* This room will contain a monster, an item on the monster      */
/* and an item in the room.                                     */


int _lift(string str) {

    if(str == "carpet" || "the carpet") {
        write("You lift up the carpet and see the floor.\n" +
              "Pretty isn't it?\n");
        say(TP->NAME + " lifts the carpet.\n",TP);
    }
    else {
        notify_fail("Lift what?!\n");
    }
    return 1;
}

reset(arg) {
    if(arg) return;

    short_desc="Generic Room4";

    long_desc="Sample room for newbie wizzes to view and notice the coding " +
              "style used in. If this room were to go into the mud there " +
              "might actually be something worth reading in here, but as it " +
              "is there is not so you can just read this. There is a " +
              "monster here though. You could kill it or leave it to kill " +
              "some other unsuspecting prey. You also notice that the " +
              "carpet on the floor seems loose.\n";

    set_light(1);    /* minimum light level needed to see without     */
                     /*     a light source.  (Torch = 1 light level)  */

    items=({"nothing","you see alot of nothing in here",
            "room","Yep that is what it is",
            "carpet","Looks loose. Maybe you could lift it",
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
                                                 "set_race","rodent",
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
                  2, 1, "guath", MNST+"under/guath", 0,
                          /* Using a predefined monster. */
              });

    ::reset();
// Notice that there is no replace_program again since
//      using the init function.

}

void init() {

    ::init();
    add_action("_lift","lift");
}

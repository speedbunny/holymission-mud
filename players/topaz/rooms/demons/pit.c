inherit "room/room";

#include "/players/topaz/defs.h"

object angel;

int climb(string arg) {
    if(!arg) {
        notify_fail("Climb what?\n");
    }
    if(arg=="walls"||arg=="wall"||arg=="up"||arg=="out"||arg=="pit") {
        write("You work hard and...\n" +
              "                    You get out!\n");
        say(TP->NAME + " climbs out of the pit.\n");
        MP("out of the pit#players/topaz/rooms/demons/cave7");
    }
    else notify_fail("You don't think you can climb that.\n");
    return 1;
}

reset(arg) {
    if(!angel) {
      move_object(angel=clone_object(MDEMONS + "angel"),this_object());
    }

    if(!arg) {

     short_desc = "A dark pit";
     long_desc = "The demons use this pit to keep prisoners in before they\n" +
                 "sacrifice them, and eat the corpse!  You better climb out\n" +
                 "here before they capture you too!\n" +
                 "There are two sets of shackles chained to the walls here.\n" +
                 "It smells pretty bad in here.\n";

     items =({"pit","This pit is deep.  You hope you can climb out",
              "shackles","They are used to keep prisoners 'safe'.  Ha ha",
              "walls","The walls are tall and smooth.  You hope you can climb out",
              "chains","Chains keep the shackles from moving too freely about",
              "shackle","There are two pairs of shackles",
              });
       set_light (-2);

        property = ({"no_teleport","no_sneak","no_steal",});
        smell = "It smells like urine and decay down here.";
    }
}

init(){
  ::init();

        add_action("climb", "climb");
}

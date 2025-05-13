inherit "room/room";
#include "../path.h"
object g1,g2,g3,g4,p;
  reset(arg) {
::reset(arg);
    if (!g1 || !living(g1))
{ g1=clone_object(MONST + "/guard2");
move_object(g1, this_object());  }
    if (!g2 || !living(g2))
{ g2=clone_object(MONST + "/guard3");
move_object(g2, this_object());  }
    if (!g3 || !living(g3))
{ g3=clone_object(MONST + "/guard2");
move_object(g3, this_object());  }
    if (!g4 || !living(g4))
{ g4=clone_object(MONST + "/guard2");
move_object(g4, this_object());  }
   if (!p || !living(p))
{ p=clone_object("players/baalthasar/obj/polish");
move_object(p, this_object());  }


set_light(1);
short_desc = "The west guardhouse";
long_desc =  
"     Four bored looking guards stare at you as you enter the \n"
+"room.  They flash you a warning glance as they continue to \n"
+"polish their weapons and armour.  Past the guards, to the west \n"
+"you see another doorway leading into a smaller room. The only \n"
+"other objects you notice is the polish sitting upon a table \n"
+"around which the guards sit. \n";

dest_dir =
({
PATH + "/enter", "east",
PATH + "/gateh", "west"
});
smell = "The pungent odor of the polish and steel fills your nostrils. ";
}
init() {
::init() ;
add_action("go_west"); add_verb("west");
add_action("listen", "listen"); }
go_west() {
   if (present("guard")) {
say("The guard prevents passage west. \n");
write("The guard pushes you back and tells you to leave. \n");
return 1;
    }
 }
listen() {
write("Silence prevails as you and the guards watch each other. \n");
return 1;
}

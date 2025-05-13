inherit "room/room";
#include "../path.h"
object g1,g2,g3,g4;

reset(arg) {
::reset(arg);
  if (!g1 || !living(g1))
{ g1=clone_object(MONST + "/guard2");
move_object(g1, this_object());  }
   if (!g2 || !living(g2))
{ g2=clone_object(MONST + "/guard3");
move_object(g2, this_object());  }
   if (!g3 || !living(g3))
{ g3=clone_object(MONST + "/guard3");
move_object(g3, this_object());  }
   if (!g4 || !living(g4))
{ g4=clone_object(MONST + "/guard3");
move_object(g4, this_object());  }

       if (g1 && g2) {
g1->set_friend(g2);g2->set_friend(g1);
  }
       if (g2 && g3) {
g2->set_friend(g3);g3->set_friend(g2);
 }
       if (g3 && g4) {
g3->set_friend(g4);g4->set_friend(g3);
 }
       if (g1 && g4) {
g1->set_friend(g4);g4->set_friend(g1);
  }

property = ({"no_teleport"});

set_light(1);
short_desc = "The east guardhouse";
long_desc =
"     You stumble in upon four guardsmen sitting at a small \n"
+"desk and holding cards in their hands.  A large pot of money \n"
+"sits on the table's center, the guards watch you in annoyance \n"
+"at being disturbed.  You get the feeling you shouldn't be here. \n"
+"The room itself is barren and devoid of any decoration. \n\n";

dest_dir =  
({
PATH + "/enter", "west"
});
items = ({"table", "It's an old, worn wooden table with a leg missing"});
smell = "You detect a faint trace of alcohol in the air. \n";
}
init() {
::init() ;
add_action("listen", "listen"); }
listen() {
write("The guards mutter under their breaths as they wait for you to leave. \n"
+"The table squeeks occasionally as it leans towards the corner missing \n"
+"a leg. \n");
}

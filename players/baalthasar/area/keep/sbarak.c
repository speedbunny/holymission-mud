inherit "room/room";
#include "../path.h"
object s1,s2,s3,s4,s5,s6;

reset(arg) {
::reset(arg);
    if (!s1 || !living(s1))
{ s1=clone_object(MONST + "soldier");
move_object(s1, this_object());}
    if (!s2 || !living(s2))
{ s2=clone_object(MONST + "soldier");
move_object(s2, this_object());}
    if (!s3 || !living(s3))
{ s3=clone_object(MONST + "soldier");
move_object(s3, this_object());}
    if (!s4 || !living(s4))
{ s4=clone_object(MONST + "soldier");
move_object(s4, this_object());}
    if (!s5 || !living(s5))
{ s5=clone_object(MONST + "soldier");
move_object(s5, this_object());}
    if (!s6 || !living(s6))
{ s6=clone_object(MONST + "soldier");
move_object(s6, this_object());}

property = ({"no_teleport"});
 set_light(1);
 short_desc = "Soldiers' barracks";
long_desc = 
"      These are the barracks of the main garrison of Castle \n"
+"Strongheart.  Scores of bunks line the walls, but most of the \n"
+"soldiers appear to be out at this time, only a few remain. \n"
+"A doorway leads to what seems to be the captain's quarters. \n\n";

dest_dir = ({
PATH + "/sbarak2.c", "doorway",
PATH + "/cyard2", "out"
});
items = ({"bunks", "All made tight and neat.  Looks really uncomfortable",
"doorway", "You can see a few men standing beyond it"
});
}
init() {
::init() ;
add_action("go_doorway"); add_verb("doorway");
add_action("listen", "listen"); }
go_doorway() {
  if (present("soldier"))  {
say("A soldier blocks the way to the captain. \n");    
write("A soldier gets in your way and stops you.\n");
return 1; }
}
listen() {
write("The soldiers appear to be describing various battles and victories.");
return 1;
}

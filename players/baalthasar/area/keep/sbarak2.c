inherit "room/room";
#include "../path.h"
object c,s1,s2,s3,sb,chest;

reset(arg) {
::reset(arg) ;

   if(!s1 || !living(s1))
{ s1=clone_object(MONST + "soldier");
move_object(s1, this_object()); }
   if(!s2 || !living(s2))
{ s2=clone_object(MONST + "soldier");
move_object(s2, this_object()); }
   if(!s3 || !living(s3))
{ s3=clone_object(MONST + "soldier");
move_object(s3, this_object()); }
   if(!c || !living(c))
{ c=clone_object(MONST + "captain");
move_object(c, this_object()); }

set_light(1);
short_desc = "Captain's quarters";
long_desc =
"      Here is the home to the Captain of the soldiers.  \n"
+"Though he's a busy man, leading and training the garrison, \n"
+"he still finds time to chat with his soldiers.  You've just \n"
+"      A large desk stands in the center of this room.  A \n"
+"stongbox lies behind the desk, and papers fill the floor. \n"
+"The Captain's bed is in a corner with a chest at it's foot. \n\n";

dest_dir = ({
PATH + "/sbarak"
});
items = ({"desk", "Another surface buried in papers",
"paper", "Many documents of no meaning to you",
"papers,", "Many documents of no meaning to you",
"strongbox", "A large iron box with a rusty keyhole",
"bed", "Very neat.  Impressive.  You gather he must have been mother's favorite.",
"chest", "Clothes hang out of this half open box"
});
}

   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "The hallway turns here.  A large painting hangs on the corner wall, "+
   "but it has faded so badly that you can hardly tell what it is.  "+
   "A slightly chilly breeze blows from the south every so often.\n";

  items=({
  "painting","A grotesque scene depicting the recent exumation of a "+
"recently dead corpse...  You feel an urge to touch it",
  "hallway","A long hallway of white marble",
  "corner","The hallway turns at the corner",
  "corner wall","There is a picture on the wall",
  "wall","There is a picture on the corner wall",
  "breeze","The breeze somehow manages to aviod being seen",
  "marble","A white stone surface",
  "floor","A clean marble floor",
  "walls","Clean marble walls",
  });
   dest_dir=({
   GPATH+"up3","east",
   GPATH+"up5","south",
   });
  }
::reset(arg);
 }
void init(){
::init();
add_action("touch","touch");
           }

int touch(string str){
if(str=="painting")    {


write("You are sucked into the painting!!\n");
this_player()->move_player("into the painting",GPATH+"painting");


}
return 1;
notify_fail("Touch what?\n");
return 0;
}

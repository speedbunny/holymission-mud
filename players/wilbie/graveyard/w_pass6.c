   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You find yourself in a narrow and rather low passageway.  There is "+
   "some sort of hole to the north, and a ladder leading down it.  On "+
   "the eastern wall there is a message scratched into the wall.  Some "+
   "weird instinct seems to suggest you look at it.  The hole emanates "+
   "demonic "+
   "sounding laughter.\n";


   items=({
   "message","It looks like something you really need to read",
             "dangers which only the bravest and most powerful should "+
             "attempt to confront.  Certain death awaits all but the "+
              "most experienced of warriors",
  "walls","Granite walls",
  "floor","A hard granite floor",
  "wall","It has a message you can look at",
  "passageway","A long, dark passageway",
  "granite","A dark rock",
  "ladder","It leads down into a very scary place",
  "hole","It looks pretty deep",
          });
   clone_list=({
   1,1,"knight","/players/wilbie/graveyard/monsters/skel_knight",
   ({ "set_level" , 18 }),
  -1,1,"sword","/players/wilbie/graveyard/weapons/msword",0,
  -1,1,"armour","/players/wilbie/graveyard/armor/armor1",0,
   });
   ::reset();
   dest_dir=({
   GPATH+"w_hole","north",
   GPATH+"w_pass5","south",
   });
  }
::reset(arg);
 }
void init() {
   ::init();
   add_action("read","read");
}

int read(string str) {
   if(str == "message") {
   write(
   "The message reads...\n"+
   "Beware all ye who enter here.  The pit to the north leads to\n"+
   "creatures of great power and evil.  Enter at your own risk.\n"
   );
   return 1;
}

notify_fail("Read what?\n");
return 0;
}

inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "Princes room";
 long_desc = "You have entered the princes bedroom.  A large, comfortable looking\n" +
   "bed stands against the northern wall, under a large picture.  The picture\n" +
   "appears to be that of the king, judging from the crown that sits upon the\n" +
   "goblins head.  Numerous trinkets, and toys lay scattered across the floor,\n"
 + "and a large toybox stands open, and overflowing with toys against the eastern\n" +
   "wall.\n";
 items = ({
 "bed","A large comfortable bed",
 "trinkets","Various trinkets that the prince plays with",
 "toys","Toys that the prince plays with",
 "picture","A picture of the goblin king.  His crown looks valuable",
 "crown","The crown of the goblin king",
 "toybox","The toybox is overflowing with toys for the prince",
});
 DD = ({
  KI + "k1","south",
});
}

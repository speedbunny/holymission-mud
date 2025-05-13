inherit "room/room";
#include "/players/saffrin/defs.h"

object board;

reset(arg) {
  set_light(1);
  short_desc = "The Mage Main Donation Room";
  long_desc=
      "You are in the mage donation room.  This is one of the"+
      " best kept secrets of the mage guild.  In here, mages of "+
      "higher levels can donate items that they do not need to their"+
      " fellow mages.  The walls are lined with book filled shelves."+
      "  There are scripts and scrolls scattered about.  Remember "+
      "this room is designed so that everyone can help each other.  "+
      "So please, respect this and take only what you need.\n";
  property=({ "no_fight", "no_teleport" });
  dest_dir=({
      TOWER+"room/hall2", "north",
  });
  items=({
      "shelf",     "Several dark and dusty shelves",
      "shelves",   "Several dark and dusty shelves",
      "books",     "They are on the shelves",
      "scripts",   "They are scattered about",
      "scrolls",   "Uncounted lots of scrolls in languages "+
                   "you never heared of.\nOne scroll stands "+
                   "out, glowing with magical energy",
      "floor",     "A glowing scroll is here",
      "scroll",    "A scroll with a list on it",
      "list",      "A written list.  Try reading it",
  });
  clone_list=({
      1, 1, "board", "/boards/guilds/mage_guild", 0,
  });
  ::reset(arg);
}

init() {

  ::init();
   AA("read",     "read");
   AA("find",     "find");
}

read(str) {   

  if(str!="list")     return 0;
     say(CQN+" reads a scroll.\n");
     ME("\tCherlindrea's Apprentice Work List  \n"+
        "\t___________________________________\n"+
        "\t1. Find the code of mages.         \n"+
        "\t2. Clean Yorel's workroom.         \n"+
        "\t3. Find spells for Achlesu.        \n"+
        "\t4. Restock Yilli's kegs.           \n"+
        "\t5. Dust the shelves in shop.       \n"+
        "\t6. Recycle bottles for Nickum.     \n"+
        "\t7. Clean out dentatores.           \n"+
        "\t8. Buy rat traps.                  \n");
 return 1;
}

find(str) {

  if(str=="code of mages" || str=="the code of mages") {
      say(CQN+" starts to search for something.\n");
      ME("After some searching, you find the code of mages.  Looking\n"+
         "at it you discover the folowing on the code of the mages:\n\n"+
         "\tAbove all else, help and aide you fellow mages at\n"+
         "\tall costs.  You are one with each other, a \n"+
         "\tpowerful force.  When joined together, mages are\n"+
         "\tunstoppable.\n");
    return 1;
  }
 return 0;
}

inherit "room/shop";
#include "/players/saffrin/defs.h"
  
reset(arg) {
  set_exits(({
       TOWER+"room/hall1", "south",
  }));
  set_light(1);
  set_short("Hafoc Traders");
  set_long(
        "You are in Hafoc Traders.  There are candles burning "+
        "brightly to light the room.  Smokey incense taunts your"+
        " senses as you feel at peace with yourself.  "+
        "The hum of soft music plays at your ears.\n\n"+
        "You can trade your goods here.\n"+
        "      Commands are:  buy items,\n"+
        "                     sell items, sell all\n"+
        "                     list, list weapons(armours),\n"+
        "                     value items.\n");
  property=({ "has_fire" });
  smell="The shop smells like the earthy burning of patchouli incense.";
  set_store_room(TOWER+"room/storage");
  set_store_exit("west");
  clone_list=({
         1, 1, "trashcan", TOWER+"obj/trash", 0,
  });
  ::reset();           
}

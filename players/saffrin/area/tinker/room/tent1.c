inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "Tinker tent";
    long_desc =
         "You are in a tent of one of the tinkers.  The walls are decorated with "+
         "coins, velvet, and lace.  There are pillows and blankers on the floor for the "+
         "tinkers to sleep on.  There are candles placed all around the tent and "+
         "incense is burning here.\n";
    dest_dir=({
      TINK+"room/path2", "north",
    });
    items=({
      "coins", "Coins from various places around the world",
      "velvet", "Scrapes of velvet patched into the cloth of the tent",
      "lace", "Bits of lace sewn into the cloth of the tent",
      "pillows", "Plush down pillows",
      "blankets", "Warm woolen blankets",
      "floor", "Candles, blankets, and pillows are on the floor",
      "candles", "Candles of various colors",
      "incense", "Patchouly incense burning a sweet scent",
    });
    clone_list=({
          1, 1, "man", TINK+"npc/tman", 0,
          1, 1, "woman", TINK+"npc/twoman", 0,
    });
    ::reset();
    replace_program("room/room");
}

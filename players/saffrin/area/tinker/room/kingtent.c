inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "The Tinker King's tent";
    long_desc = 
         "You have entered the tent of the tinker king.  This place looks more like a "+
         "house than a tent.  It is filled with furninture and has potted plants all "+
         "around.  The walls of the tent are decorated with velvet and lace.  "+
         "There are candles burning about the tent.\n";
    dest_dir=({
      TINK+"room/path9", "south",
    });
    items=({
      "walls", "The walls are decorated with lace and velvet.  Some coins are sewn in its cloth",
      "lace", "Scraps of lace sewn into the walls of the tent",
      "velvet", "Velvet cloth scraps sewn into the walls of the tent",
      "furniture", "Bed, table, lamps, and a kettlebox",
      "table", "A table with various objects on top of it",
      "objects", "Basket, incense, and jars",
      "incense", "Incense sticks made from patchouly",
      "basket", "A hand woven basket",
      "jars", "Jars with various herbs in them",
      "herbs", "Herbs used for healing spells",
      "candles", "Candles of a variety of colors",
      "plants", "The plants are herb grown for spells",
      "lamps", "Bracket lamps to help light the room",
      "bed", "A plush bed made for loving",
      "kettlebox", "A box for all sotty untensils to be put in",
      "tent", "A large tent that had coins sewn into its cloth",
      "cloth", "Brown cloth with coins sewn in it",
      "coins", "Coins collect from various lands around the world",
    });
    clone_list=({
          1, 1, "king", TINK+"npc/tking", 0,
          1, 3, "woman", TINK+"npc/twoman", 0,
    });
    ::reset();
    replace_program("room/room");
}

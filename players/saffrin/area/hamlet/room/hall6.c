inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle's armoury";
  long_desc = 
      "You are in the impressive and vast armoury for the castle of Denmark.  "+
      "Tacked the the walls by golden nails are several piece of platemail armour, "+
      "shining brightly.  There are several glass cases filled with daggers and shortswords.  "+
      "All along the north wall, there are several jewled longswords, hanging in proud glory.  "+
      "Proudly resting in the center of the room is a large suit of armour.  "+
      "Candles above each valued piece lights them up to display its worth.\n";
  dest_dir=({
      HAM+"room/hall5", "south",
  });
  items=({
      "walls", "Lined with platemail armour tacked by golden nails",
      "nails", "Nails that shice gold and bright",
      "cases", "Glass cases to display weaponry",
      "platemail#daggers#shortswords#longswords#suit", "Newly polished",
      "candles", "White candles burning above each piece",
  });
  ::reset();
  replace_program("room/room");
}

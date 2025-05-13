inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage-Master Yorel's Bedroom";
  long_desc =
      "You are in Mage-Master Yorel's bedroom on the Mage Tower.  "+
      "Against the west wall is a small bed of nails, that looks very sharp.  "+
      "There are several stones floating lightly around the room.  "+
      "A soft green glows lights up the room, radiating from a meteor.  "+
      "There is a spiral staircase in the center of the room leading down.  "+
      "The walls are bare and very plain.\n";
  dest_dir=({
      TOWER+"room/hall7", "north",
      TOWER+"room/yorwork", "down",
  });
  items=({
      "staircase", "Spiral staircase leading down",
      "walls", "Dark stone walls that are bare and plain",
      "meteor", "A green, glowing moldavite",
      "moldavite", "A green meteorite that fell from the sky",
      "glow", "A soft glow lighting the room",
      "stones", "Gems floating around the room",
      "gems", "Emeralds, diamonds, garnets, and sapphires",
      "emeralds", "Several floating emeralds",
      "granets", "Several floating garnets",
      "diamonds", "Several floating diamonds",
      "sapphires", "Several floating sapphires",
      "nails", "Sharp nails that Yorel uses to sleep on",
      "bed", "A small bed of nails",
  });
  ::reset();
  replace_program("room/room");
}

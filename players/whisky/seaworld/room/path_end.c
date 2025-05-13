#include "../seaworld.no_water.h"
inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "On a stony path";
    long_desc =
    "You are walking on the stony path. To the south you can\n"+
    "see a beautiful garden and to the north you hear the rolling\n"+
    "of the sea. If you look north you see a little hut.\n";     
    dest_dir = ({
      PATH+"rock","east",
      PATH+"sea_way2","west",
      PATH+"shop_entry","north" });
    items = ({
      "bottom","A stony bottom",
      "portal","A glowing portal heading to the Mortal Kombat area",
      "sea","The blue sea" });
    RP;
}

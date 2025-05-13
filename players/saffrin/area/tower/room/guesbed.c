inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Guest Bedroom";
  long_desc =
      "You are in the guest bedroom of the Mage Tower.  "+
      "There is a small green bed in the northeast corner.  "+
      "A window, overlooking the land, is in the south wall.  "+
      "A night table sits next to the bed with a large brass candlestick resting on it, lighting the room.  "+
      "There is a flask of fire brandy next to the candlestick on the table.\n";
  dest_dir=({
      TOWER+"room/hall4", "north",
  });
  property=({ "has_fire" });
  items=({
      "bed", "A small green bed for a guest",
      "window", "Gives a view of the land",
      "land", "Lush, green land for miles",
      "table", "A small night table",
      "candlestick", "A brass candlestick with a candle",
      "candle", "A green candle lighting the room",
      "brandy", "Fire brandy",
      "flask", "Filled with fire brandy",
  });
  ::reset(); 
  replace_program("room/room");
}

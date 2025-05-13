inherit "room/shop";

reset (arg) {

  if(arg) return;
  set_short("Village shop");
  set_long ("This small hut appears to be a shop of some sort.  The floor is\n" +
            "buried with various objects as well as drums, vats, and sacks of\n" +
            "god knows what.  A small goblin stands behind a small counter at the \n" +
            "back of the shop.  A small curtain covers a doorway in the east wall.\n");
  dest_dir = ({
   "players/jake/goblin/gob4.c","north",
   "players/jake/goblin/store","east",
  });
  set_store_room("players/jake/goblin/store");
  set_store_exit("west");
  set_light(1);
}

inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc = "c19  west hallway  N/S goblin guard";
long_desc = 
            "The hallway extends north and south.\n"
         +  "There is a doorway to the east, and a small window in the west wall.\n"
         +  "The carpet extends down the hall.\n";
items = ({
  "floor","A red stone floor",
  "ceiling","A pearl-white stone ceiling",
 "window","A beautiful view of a large tree",
  "wall","A grey stone wall with a small window to the west,\nand a doorway to the east",
  "carpet","A brown carpet",
  "doorway","A stone doorway",
});
dest_dir = ({
  "players/jake/goblin/castle/c18","north",
  "players/jake/goblin/castle/c20","south",
  "players/jake/goblin/castle/h1","east",
});
 clone_list = ({
  1,1,"goblin","/players/jake/goblin/castle/monsters/goblin.c",0
});

::reset();
replace_program("room/room");
}

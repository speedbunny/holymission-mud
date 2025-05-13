inherit "room/room";
reset(arg) {
if (arg) return;
set_light(3);
  short_desc = "c15   E/W hallway";
  long_desc = "The hallway goes east and west.\n"
            + "The white carpet extends down the hall.\n"
            + "A small window in the north wall.\n";
items = ({
  "floor","It's made of red stone",
  "ceiling","It's made of pearl-white stone",
  "wall","Made of grey stone, with a small window in the north wall",  
  "window","You see a large clearing behind the castle",
  "carpet","A beautiful white carpet",
});
dest_dir = ({
"players/jake/goblin/castle/c16","west",
"players/jake/goblin/castle/c14","east",
});
}

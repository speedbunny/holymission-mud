inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc = "c20 West hallway N/S";
long_desc =  
            "A long hallway going north and south.\n"
        +   "You can hear noises to the north.\n"
        +  "A small window in the wall to the west, and a\n"
+ "brown carpet covering the floor.\n";
items = ({
   "floor","The floor is of red stone",
   "ceiling","The ceiling is made of white stone",
   "wall","The wall is made of grey stone, with a small window in it",
   "window","Upon gazing out the window, you see a small forest",
   "carpet","A brown carpet that covers the floor",
});
dest_dir = ({
  "players/jake/goblin/castle/c21","south",
  "players/jake/goblin/castle/c19","north",
});
}

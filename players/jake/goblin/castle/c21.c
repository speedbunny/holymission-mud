inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc = "c21 West hallway N/S";
long_desc =  
            "A long hallway going north and south.\n"
        +   "A small window in the west wall.\n"
         +  "A brown carpet covers the floor.\n";
items = ({
   "floor","The floor is of red stone",
   "ceiling","The ceiling is made of white stone",
   "wall","The wall is made of grey stone, with a small window in it",
   "window","Upon gazing out the window, you see a small forest",
   "carpet","A brown carpet that covers the floor",
});
dest_dir = ({
  "players/jake/goblin/castle/c22","south",
  "players/jake/goblin/castle/c20","north",
});
}

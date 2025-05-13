inherit "room/room";
reset(arg) {
if (arg) return;
set_light(3);
  short_desc = "c22b  Southwest tower  2";
  long_desc =   
        "A small room, with only a chair in it.\n"
     +  "The floor is made of oak, along with the ceiling.\n"
     +  "There is a set of steps leading up and down.\n"
     +  "There are small windows in each wall.\n"
     +  "Footsteps can be heard from above.\n";
 items = ({
   "floor","It is made of solid looking oak",
   "ceiling","It is made of wood.\nSmall dust particles fall into your eyes as you look up at it",
   "wall","Grey stone walls with small windows in them",
  "chair","A small wooden chair",
   "window","To the north you see a large open field.\nSouth is the castle wall.\nEast you see a large forest.\nWest you see the back of the castle",
   "steps","Narrow wooden steps leading up and down",
});
dest_dir = ({
  "players/jake/goblin/castle/c22a","down",
  "players/jake/goblin/castle/c22c","up",
});
}

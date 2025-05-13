inherit "room/room";
reset(arg) {
if (arg) return;
set_light(3);
  short_desc = "c4b...southeast tower...level 2";
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
   "window","A beautiful view of the country-side.\nSouth is the goblin village.\nNorth you see the castle wall.\nEast you see a large forest\nAnd west you see the front of the castle",
   "steps","Narrow wooden steps leading up and down",
});
dest_dir = ({
  "players/jake/goblin/castle/c4a","down",
  "players/jake/goblin/castle/c4c","up",
});
}

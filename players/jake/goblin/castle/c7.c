inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
         short_desc = "c7...N/S Hallway";
        long_desc = 
           "The hallway extends north and south.\n"
         + "The blue carpet continues off into the distance.\n"
         + "A small window in the east wall.\n";
  items = ({
        "floor","Solid looking.  It is made of red stone",
        "wall","A grey stone wall",
        "ceiling","Pearl white stones make the ceiling",
        "window","You see a large tree with a small bird in it",
        "bird","A small blue bird",
        "carpet","A beautiful blue carpet",
});
dest_dir = ({
         "players/jake/goblin/castle/c6","south",
         "players/jake/goblin/castle/c8","north",
         });
}

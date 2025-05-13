inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Mountain path";
  long_desc="You're on a path going down to the land beyond the \n"+
            "mountains, to the east you can see a beautifull water-\n"+
            "fall.\n";
  dest_dir= ({"/players/shaka/mountain/path4","south",
              "/players/shaka/mountain/top","north",
              "/players/shaka/mountain/wfall","east",});
  items= ({"waterfall","a waterfall to the east",
           "path","small and narrow",
           "mountains","they are very high",
           "land","it's the land beyond the mountains"});
}
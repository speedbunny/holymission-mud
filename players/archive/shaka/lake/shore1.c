inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Lake's shore";
  long_desc="You're moving on the shore of the lake. The water\n"+
            "is still and calm. The lake continues east\n"+
            "To the west is a path leading into the mountains\n"+
            "north. \n";
  dest_dir= ({"/players/shaka/lake/shore2","east",
              "/players/shaka/mountain/path4","west",});
  items = ({"shore","a rocky shore",
            "water","its still and calm",
            "path","a path leading into the mountains",
            "mountains","mountains to the north and west"});
}


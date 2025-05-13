inherit "room/room";
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Mountain path";
  long_desc="You are now high up in the mountains, everything\n"+
            "around you is rock, the path continues south even \n"+
            "higher up in the mountains, as you look west you can \n"+
            "see some sort of crack in the mountains wall.\n";
  dest_dir= ({"/players/shaka/mountain/top","south",
              "/players/shaka/mountain/path1","north",});
  items = ({"crack","you can't see much from here lets move WEST",
            "wall","there's a crack in the wall",
            "mountains","the are very high"});
}

init() {
  ::init();
  add_action("move_west","west");
  add_action("move_west","climb");
}

move_west()
{
 write("You climb your way over rocks, west\n");
 this_player()->move_player("over rocks west#players/shaka/mountain/crack");
 return 1;
}

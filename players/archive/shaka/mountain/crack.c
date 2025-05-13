inherit "room/room";
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Crack";
  long_desc="You're standing in front of a huge rock with a \n"+
            "crack in it, the crack is just big enough to enter it\n";
  dest_dir=({"/players/shaka/mountain/path2","east",
             "/players/shaka/cave/cave1","crack",});
  items = ({"crack","a strange crack leading into a dark hole",
            "rock","a huge rock with a crack in it"});
}

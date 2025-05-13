inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Mountain path";
  long_desc="At last the path ends in a valley, east is a lake\n"+
            "to the north are the mountains, south is a small hut.\n";
  dest_dir= ({"/players/shaka/hut","south",
              "/players/shaka/mountain/path3","north",
              "/players/shaka/lake/shore1","east",});
  items= ({"path","it ends here",
           "valley","it's a very beautifull valley",
           "lake","an ordinary lake with blue water ofcourse",
           "hut","a small hut",
           "mountains","they are very high"});
}

init() {
  ::init();
  add_action("enter","enter");
}

enter(str)
{
if (!str) return 0;
if (str == "hut" || str == "house")
 {
  write("you enter the "+str+".\n");
  this_player()->move_player("south#players/shaka/hut");
  return 1;
 }
return 0;
}

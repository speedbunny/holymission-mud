inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Mountain top";
  long_desc="You've reached the top of the mountain, snow is all \n"+
            "around you, brrrr you're freezing , to the south you can\n"+
            "see a wide land stretching in front of you, the path \n"+
            "continues down into this land.\n";
  dest_dir= ({"/players/shaka/mountain/path3","south",
              "/players/shaka/mountain/path2","north",});
  items = ({"snow","cold&white, what else did you expect??",
            "land","the view from here is excellent",
            "path","small and narrow",
            "mountain","you've reached the top of this mountain",
            "top","it's covered with snow"});

}

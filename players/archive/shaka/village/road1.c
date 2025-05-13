inherit "room/room";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_light(1);
  short_desc="a small road";
  long_desc="You're moving on a small road. It leads to south to\n"+
            "some hills and small houses. To the north the road\n"+
            "ends in a small beach.\n";
  dest_dir=({"players/shaka/lake/shore2","north",
             "players/shaka/village/road2","south",});
  items=({"road","a small road",
          "hills","green hills, some have holes in them",
          "houses","small houses",
          "beach","a beach north of here"});
}

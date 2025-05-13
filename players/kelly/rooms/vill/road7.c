inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A road";
long_desc=
  "You are just outside Red Rock Juntion city limits. To the west "+
  "the road leads to a big red rock and there is a ravine here "+
  "which you can go up into.\n";
      "The path looks like it was created recently, and there "+
      "is a rock to the west.\n";
    dest_dir=({
      "/players/saffrin/area/aine/room/for1", "east",
      "players/kelly/rooms/vill/road5","west",
      "room/ravine","up",
    });
    items=({
      "forest","Lots of trees",
      "trees","They make up the forest",
      "path","It looks like it was created recently",
      "rock","It's a big red rock",
    });
}

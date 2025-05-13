inherit "room/room";
 
void reset(int arg) {
  set_light(1);
  short_desc="A small squalid hut";
  long_desc=
    "This is a squalid little hut. There are no furnishings beyond "+
    "the very basics.  You feel that whoever lives here is clearly "+
    "used to living without any modern conveniences.\n";
  
  items = ({
    "hut","It is small",
    "furnishings","They are very basic",
  });
 
  dest_dir=({
    "/room/yard", "east"
  });
 
  clone_list = ({
    1, 1, "hermit", "/players/moonchild/goblins/hermit", 0,
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

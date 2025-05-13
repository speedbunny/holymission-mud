inherit "room/room";

void reset(int arg) {
  if (arg)
    return;
  ::reset(arg);
  set_light(0);
  short_desc = "A dark tunnel";
  long_desc = "\n";
  dest_dir = ({
    "players/paris/house/tunnel1", "south",
  });
  items = ({
    
  });
}

void init() {
  ::init();
}

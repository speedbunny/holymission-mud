inherit "/room/room";
 
#define NOISE_PLACE "/players/kryll/help/bulp"
 
void reset(int arg) {
  if(arg) return;
 
  set_light(1);
  short_desc = "Test room 2";
  long_desc = "Once again, the mighty water room makes noise.\n";
  dest_dir = ({
    "/players/kryll/help/test1", "west",
    "/players/kryll/help/test4", "north",
  });
 
  ::reset(arg);
}
 
void init() {
 
  ::init();
  NOISE_PLACE->add_room(this_object());
}

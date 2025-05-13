inherit "/room/room";
 
#define NOISE_PLACE "/players/kryll/help/bulp"
 
void reset(int arg) {
  if(arg) return;
 
  set_light(1);
  short_desc = "Test room 4";
  long_desc = "Once again, the mighty water room makes noise.\n";
  dest_dir = ({
    "/players/kryll/help/test2", "south",
    "/players/kryll/help/test3", "west",
  });
 
  ::reset(arg);
}
 
void init() {
 
  ::init();
  NOISE_PLACE->add_room(this_object());
}

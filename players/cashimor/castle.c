inherit "/room/room";

void reset(int arg) {

  ::reset(arg);
  if(arg) return;

  short_desc = "Cashimor's Castle";
  long_desc =
    "This is Cashimor's Castle...\n";

  set_light(1);
  move_object(this_object(), "/players/cashimor/workroom");
}

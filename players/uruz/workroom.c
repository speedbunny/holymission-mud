inherit "room/room";

void reset(int arg) {

  ::reset(arg);
  if(arg) return;
  short_desc = "Workroom";
  long_desc = "Workroom long.\n";
}

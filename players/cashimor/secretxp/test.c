inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Test";
    long_desc="Testroom of Ethereal Cashimor!\n";
    set_light(1);
  }
}

inherit "room/room";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_light(0);
    short_desc = "Beetween";
    long_desc =  "The Beetween.\n";
    smell="You can nothing smell";
  }
}

inherit "room/room";

reset(arg) {
  ::reset(arg);
}
init() {
  ::init();
  add_action("stuff") ; add_verb("stuff");
}
stuff() {
  write("possessive "+possessive(this_player())+"\n");
  write("subjective "+subjective(this_player())+"\n");
  write("objective "+objective(this_player())+"\n");
  return 1;
}

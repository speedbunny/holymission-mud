inherit "obj/board";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("board");
    set_short("Helenette vote board");
    set_file("players/cashimor/board");
  }
}

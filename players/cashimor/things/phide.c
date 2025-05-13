inherit "players/cashimor/inherit/armour";

object tp;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("hide");
    set_short("A panther hide");
    set_long("A thick warm panther hide.\n");
    set_ac(2);
    set_weight(2);
    set_value(1000);
  }
}

init() {
  ::init();
  tp=this_player();
  call_out("purring",30);
}

purring() {
  say(tp->query_name()+" purrs contentedly.\n");
  call_out("purring",30);
}

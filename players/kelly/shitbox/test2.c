inherit"obj/thing";

reset(arg) {
  if(arg) return;
  set_name("tester");
  set_short("A Tester");
  set_long("A tester(inv).\n");
  set_can_get(1);
}

init() {
  ::init();
  add_action("inv","'");
}

inv(str) {
  write(str+"\n"); 
}


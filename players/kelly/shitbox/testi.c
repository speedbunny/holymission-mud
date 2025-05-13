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
  add_action("inv","inv");
}

inv() {
  object obj;
  int i;

  write("Inventory of "+this_player()->query_name()+".\n");

  obj=deep_inventory(this_player());
  write(sizeof(obj)+" objects.\n");

  for(i=0;i<sizeof(obj);i++) {
    write(obj[i]);
    write(" in ");
    write(environment(obj[i]));
    write(".\n");
  }
  return 1;
}


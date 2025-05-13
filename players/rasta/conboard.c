inherit "/obj/board";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_file("room/arches/conboard");
  set_name("contra");
  set_short("The contra wizzards board");
}

init() {
  ::init();
  add_action("pn","contranote");
  add_action("pr","contraread");
  add_action("pre","contraremove");
}

pn(arg) { return ::new_msg(arg); }
pr(arg) { return ::read_msg(arg); }
pre(arg) { return ::remove_msg(arg); }

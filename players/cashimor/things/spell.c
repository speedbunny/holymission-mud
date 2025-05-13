inherit "obj/thing";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("spell");
    set_short("A mysterious spell");
    set_long("This is a strange spell. Maybe you should cast it.\n");
    set_can_get(1);
    set_read("Only mysterious signs.\n");
    set_value(250);
    set_weight(1);
  }
}

init() {
  ::init();
  add_action("cast_it","cast");
}

cast_it(str) {
object all,it;
int i;

  if((!str)||(str!="spell")) {
    notify_fail("Cast what?\n");
    return 0;
  }
  all=users();
  for(i=0;i<sizeof(all);i++) {
    if(all[i]!=this_player()) {
      if(!present("tellcatch",all[i])) {
        it=clone_object("players/cashimor/things/tellcatch");
        it->set_string(this_player()->query_real_name());
        move_object(it,all[i]);
      }
    }
  }
  write("You cast the spell. You feel everyone in the MUD is\n"
      + "affected by it.\n");
  say(this_player()->query_name()+" casts a spell.\n");
  destruct(this_object());
  return 1;
}

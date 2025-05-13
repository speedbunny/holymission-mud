inherit "/obj/thing";
void reset(int arg) {
  if(arg) return;
  ::reset();
  set_name("acid pool");
  set_short("A pool of acid");
  set_long("This is an acid pool.  It looks rather corrosive.\n");
  set_alias("pool");
  set_can_get(0);
}

void init() {
  ::init();
  add_action("_enter", "enter");
}

int _enter(string str) {
  if(!id(str)) {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You try to enter the acid pool, but just burn yourself instead.\n");
  say((string)this_player()->query_name()
        + " tries to enter the acid pool, but just burns "
        + this_player()->query_possessive() + "self.\n");
  this_player()->hit_player(30+random(21), 7);
  this_player()->show_hp();
  return 1;
}

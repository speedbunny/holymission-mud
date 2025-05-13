#define COLOURS ({"blue","red","green","pink","yellow"})

inherit "obj/treasure";

void reset(int arg) {
  if(arg)
    return;
  set_id(COLOURS[random(5)] + " frisbee");
  set_short("A " + name);
  set_alias("frisbee");
  set_value(10);
  set_weight(0);
  set_long(short_desc + ". You could \"throw\" it at someone (throw <name>).\n");
}

void init() {
  ::init();
  add_action("throw", "throw");
}

int filter(object ob) {
  return (int)ob->query_earmuff_level() < (int)this_player()->query_level();
}

int throw(string str) {
  object ob, *u;
  int i;
  if(!(ob=find_player(str))) {
    notify_fail("No player with that name.\n");
    return 0;
  }
  if(present(ob, environment(this_player()))) {
    write(capitalize(str) + " is already here.\n");
    return 1;
  }
  if(!filter(ob)) {
    write(capitalize(str) + " does not want to be disturbed.\n");
    return 1;
  }
  write("You throw the frisbee to " + capitalize(str) + ".\n");
  transfer(this_object(), environment(ob));
  /* shout((string)this_player()->query_name()
	+ " sends a frisbee across the sky to "
	+ (string)ob->query_name() + "!\n"); */
  tell_object(ob, "You leap up and catch the frisbee with your hands.\n");
  say((string)ob->query_name() + " leaps up and catches the frisbee with "
	+ (string)ob->query_possessive() + " hands.\n", ob);
  transfer(this_object(), ob);
  return 1;
}

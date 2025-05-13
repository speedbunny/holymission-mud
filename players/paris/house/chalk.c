inherit "obj/treasure";

static int charges;

reset(int arg) {
  ::reset(arg);
  if (arg) 
    return;
  charges = 1 + random(3);
  set_id("piece of chalk");
  set_alias("chalk");
  set_weight(1);
  set_short("A piece of white chalk");
  set_long("A piece of white chalk. You should be able to \"draw <string> with chalk\".\n");
}

void init() {
  ::init();
  add_action("_draw", "draw");
}

int _draw(string str) {
  string what;
  object ob;

  if (sscanf(str, "%s with chalk", what) == 1 &&
      environment(this_object()) == this_player()) {
    printf("You write %s with the chalk on the ground\n", (string)what);
    ob = clone_object("players/paris/house/chalkmark");
    ob->set_what(what);
    move_object(ob, environment(this_player()));
    if (!--charges) {
      printf("As you finish drawing the %s, the piece of chalk crumbles in your hand.\n", what);
      destruct(this_object());
    }
    return 1;    
  }
  return 0;
}

reset(arg) {
  if(arg) return;
  /* */
}
query_weight() { return 1; }
query_value() { return 50; }
short() { return "A fishing-rod"; }
get() { return 1; }
long() { write("Maybe you should try your luck?\n"); }

init() {
  add_action("fish", "fish");
}

id(str) { return str== "rod" || str=="fishing-rod"; }

fish() {
  object env;
  env=environment(this_player());
/*  if(env->short(0)=="In a clump of reeds") {
    env->fish(0);
    return 1;
  }  */

  if(!(env->fish()))
     write("This does not seem like a good place for fishing.\n");
  return 1;
}

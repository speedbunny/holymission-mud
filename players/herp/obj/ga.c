id(str) { return str="ga"; }
short() { return "G!A!"; }
get() { return 1; }
init() { add_action("ga","ga"); }
ga() {
object *ob;
int i;
  ob=all_inventory(environment(this_player()));
  for (i=0;i<sizeof(ob);i++) if (this_player()!=ob[i]) move_object(ob[i],this_player());
  return 1;
}


inherit "/obj/thing";
#define ENV environment
#define TP this_player()
#define QNAME query_name()
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("Thumper's Marbles");
      set_alias("marbles");
      set_short("Thumper's Marbles. See she didn't lose them");
      set_long("A bag full of marbles. Maybe they belong to someone.\n");
      set_value(0);
      set_weight(0);
  }
}
query_auto_load() { 
      return "/players/waldo/marbles:";
}

drop() {
   return 1;     /* may not be dropped */
}

int query_monk_wear()
{
    return 1;
}



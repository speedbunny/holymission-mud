inherit "/obj/armour";

object ring;
int light_lev;
string esc;

query_mage_wear() { return 1; }
query_monk_wear() { return 1; }
query_ninja_wear() { return 1; }

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
    set_name("ring");
    set_alias("white gold ring");
    set_type("ring");
    set_ac(0);
    set_short("a whitegolden ring");
    set_long("A plain ring of white gold.\n");
    set_weight(1);
    set_value(20000);
}

mixed wear(object me) {
  int res;
  if(!this_object()->query_worn() && (res=::wear(me))) {
    write("Your vison blures, and gets a silvery touch!\n");
    ring=clone_object("/obj/shadows/detect_invis_shad");
    ring->start_shadow(this_player(),0);
    return res;
  }
  return ::wear(me);
}

int drop(mixed x) {
   remove("ring");
   return 0;
}

mixed remove(string me) {
  int res;
  if(this_object()->query_worn() && ::remove(me)) {
   write("Your vision blures.\n");
   if(ring) destruct(ring);
   return 1;
  }
  return ::remove(me);
}

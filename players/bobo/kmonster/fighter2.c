inherit "obj/monster";
 
#define NAME this_player()->query_real_name()
#define ONAME this_object()->query_name()
 
object hunt;
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("palestinian");
  set_level(10);
  set_ep(1000);
  set_hp(70);
  set_wc(9);
  set_ac(5);
  set_al(0);
  set_alias("pali");
  set_short("An ugly looking palestinian");
  set_long("He is in good shape. So you should not attack him.\n"+
           "Maybe he is fighting for the Liberty of Palestina.\n");
  set_aggressive(0);
  set_heart_beat(1);
}

commit(str) {
  object pali;
  say("\n");
  say("The palestinian shouts: Now it is time to free Palestina.\n");
  say("The palestinian wields his knife and commits suicide.\n");
  say("The palestinian shouts: WWUUUUUAEEEHHHHHH !!!!!!!!!.\n");
 
  pali = first_inventory(environment());
 
  while (pali && pali != this_object()) {
    pali = next_inventory(environment());
  }
 
  pali = next_inventory(environment());
 
  while (pali && (pali->id() != "palestinian")) {
    pali = next_inventory(environment());
  }
 
  if ((pali) && (environment(pali) == environment(this_object()))) {
    call_other(pali,"commit suicide");
  }
  hit_player(10000);
  return;
}
 
 

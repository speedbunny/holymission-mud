inherit "/obj/monster";

void reset(int arg) {

 ::reset(arg); 
 if (arg)return;
  set_name("lizard");
  set_short("A large lizard");
  set_long("A large green lizard.  He likes the weather around here.\n");
  set_race("lizard");
  set_level(5);
  set_al(0);
  set_aggressive(0);
}

/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* The Grim Reaper. Inspired by Realms-mud */

inherit "obj/monster";

#define TP	this_player()
#define env	environment

string kill_str;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("reaper");
    set_short("Grim Reaper");
    set_long("He will get you like weat in the autumn.\n");
    set_level(15);
  }
}

set_death(str) { kill_str=="str"; }

init() {
  ::init();
  if (kill_str && find_player(kill_str)==TP) attack_object(TP);
}

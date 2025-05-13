#include "walker.h"

inherit "obj/monster";
void add_money(int m) {
   money = money + m;
}

int query_invis() { return 1000; }

void reset(int arg) {

  ::reset(arg);

  if (arg) return;
  set_name("invisible castle mover");
  set_alias("icm");
  set_level(100);
  set_female();
  set_al(0);
  set_short(0);
  is_invis = 100;
  set_long("She is invisible and moves the castle. Don't touch her!\n");
  set_aggressive(0);
  set_spell_mess1("Invisible castle mover says: This is "
                  "utterly ludicrous. Go away!");
  set_spell_mess2("Invisible castle mover says: This is " +
                  "utterly ludicrous. Go away!");
  set_chance(15);
  set_spell_dam(0);

  set_hp(1000000);
  set_ac(1000000);
  set_no_fight(1);
}

void come_here() {
  move_object(this_object(), call_other(CASTLE, "query_environment"));
}

object query_environment() {
  return environment(this_object());
}

void catch_tell(string str) {
  call_other(CASTLE, "tell_bridge", str);
}

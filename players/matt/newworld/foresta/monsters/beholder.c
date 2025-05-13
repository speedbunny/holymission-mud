inherit "/obj/monster";

#include "/players/matt/defs.h"

int eyes;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  eyes = 10;
  set_name("beholder");
  set_short("Beholder");
  set_long("A large hovering sphere, the beholder is a formidable foe.\n" +
	   "Many eyes sit upon stalks atop a large single eye, which\n" +
	   "forms its body and hovers a few feet above the ground. Its\n" +
	   "mouth is a slavering mass of razor-sharp fangs.\n");
  set_race("beholder");
  set_level(20);
  set_al(-1000);
  set_hp(1000);
  set_wc(15);
  set_ac(15);
  set_chance(5 * eyes);
  set_spell_mess1("A red beam of light shoots out from the beholder's eye!");
  set_spell_mess2("The beholder's eye zaps you with a beam of light!");
  set_spell_dam(10 * eyes);
  set_aggressive(1);
  add_money(2000);
}

hit_player(arg) {
  object eye, att;
  if(arg) {
    if(!random(10) && eyes) {
      att = TO->query_attack();
      TELL(att, "You cripple one of the beholder's eyes!\n");
      say(att->NAME + " cripples one of the beholder's eyes!\n", att);
      eye = clone_object(NWFORESTA + "objects/eyestalk");
      MOVE(eye, TO);
      eyes -= 1;
      set_chance(5 * eyes);
      set_spell_dam(10 * eyes);
    }
  }
  return ::hit_player(arg);
}

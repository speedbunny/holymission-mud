inherit "/obj/monster";

#include "/players/matt/defs.h"

int stage;
string *descs;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  descs = ({
    "Large tangle of vines",
    "Mass of vines",
    "Small tangle of vines",
    "Tiny mass of vines"
  });
  set_name("clump of vines");
  set_short("Huge mass of vines");
  set_long("A tangle of thick green vines writhing on the ground with a\n" +
	   "life of their own.\n");
  set_race("plant");
  set_alias("vines");
  set_level(10);
  set_ac(10);
  set_wc(12);
  set_hp(300);
  set_aggressive(1);
  set_chance(40);
  set_spell_mess1("The vines writhe and constrict!\n");
  set_spell_mess2("You are choked by the tendrils of the vines!\n");
  set_spell_dam(20);
}

hit_player(arg) {
  int amount;
  object half1, half2;
  if(((100 * TO->HP / TO->MAXHP) < 50) &&
     stage < 4) {
    amount = (15 / (2 + stage));
    TELLR(ENV(TO), "The vines split apart!\n");
    half1 = clone_object(NWFORESTA + "monsters/vines");
    half1->set_short(descs[stage]);
    half1->set_ac(amount);
    half1->set_hp(30 * amount);
    half1->set_stage(1 + stage);
    if(stage == 3) half1->add_money(100);
    MOVE(half1, ENV(TO));
    half2 = clone_object(NWFORESTA + "monsters/vines");
    half2->set_short(descs[stage]);
    half2->set_ac(amount);
    half2->set_hp(30 * amount);
    half2->set_stage(1 + stage);
    if(stage == 3) half2->add_money(100);
    MOVE(half2, ENV(TO));
    destruct(TO);
    return 1;
  }
  return ::hit_player(arg);
}

set_stage(arg) {
  stage = arg;
  return 1;
}

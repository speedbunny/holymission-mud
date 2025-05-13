inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
object ripper;
  ::reset(arg);
  if(!arg) {
    set_name("creature");
    set_alias("a creature");
    set_alt_name("Creature");
    set_race("creature");
    set_short("A loathsome creature");
    set_long("A disgusting malformed thing, who perhaps was a human once.\n" +
             "Angmar was probably in a bad mood when he created\n" +
             "this indescribable being. Take care!\n");
    set_aggressive(0);
    set_level(12);
    set_wc(13);
    set_ac(5);
    set_al(-150);
    set_hp(120);
    set_chance(10);
    set_spell_dam(20);
    set_spell_mess1("The creature casts a spell");
    set_spell_mess2("The creature casts a spell at you");
    move_object(ripper=clone_object(PATH + "angmar/gutripper"),this_object());
    command("wield gutripper");
  }
  return 1;
}

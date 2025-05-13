#include "/players/kasgaroth/defs.h"

inherit "/obj/monster";
object stick;

reset(str) {
    ::reset(str);
    if(str) return;
    set_name("malkazar the alchemist");
    set_alias("alchemist");
    set_alt_name("malkazar");
    set_race("human");
    set_short("Malkazar the Alchemist");
    set_long("Malkazar the Alchemist regards you shrewdly as you look him over.\n"
      +"This human wears a white apron and a frumpy blue hat.\n"
      "You realize by his appearance that his work is his life.\n");
    set_level(15);
    set_ac(5);
    set_wc(10);
    set_hp(700);
    set_al(0);
    set_aggressive(0);
    add_money(50);
    set_spell_mess1("Malkazar flings a vial of acid at his adversary.\n");
    set_spell_mess2("Malkazar flings a vial of acid at you.\n");
    set_chance(33);
    set_spell_dam(20);
    move_object(clone_object("/players/kasgaroth/guild/poison/stick"), 
      this_object());
}

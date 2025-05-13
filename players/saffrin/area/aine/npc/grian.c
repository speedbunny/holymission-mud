inherit "/obj/npc";
#include "/players/saffrin/defs.h"

reset() {

  ::reset();
    set_name("grian");
    set_short("grian");
    set_long("Grian is the twin sister to Aine.  She is extremely jealous of "+
             "her sister and will stop at nothing to destroy her.  Her long "+
             "wings glow like sunstones.\n");
    set_alias("fairy");
    set_race("twin");
    set_level(90 + random(10));
    set_al(-500);
    set_gender(2);
    set_attacks_change(100);
    set_attacks(4);
    set_dodge(30);
    set_aggressive(1);
    add_money(7000 + random(2000));
    set_spell_mess2("Grian whips her wings at "+CQN+".\n");
    set_chance(1);
    set_spell_dam(50 + random(50));
}

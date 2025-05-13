inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("troll");
    set_race("troll");
    set_gender(1);
    set_alias("spearman");
    set_short("Troll spearman");
    set_long(
"A massive troll with wide shoulders and thick legs.  He stands with his "+
"hands on a very long spear.  His head is horribly mishapen and hairless. "+
"Several of his toes are missing and his chest is crisscrossed with scars.\n");
    set_level(10);
    set_hp(230);
    set_al(-40);
    set_ac(3);
    set_wc(12);
move_object((clone_object(si+"/spear.c")),TO);
    init_command("wield spear");
}

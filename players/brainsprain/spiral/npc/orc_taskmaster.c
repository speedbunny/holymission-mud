
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Orc Taskmaster");
    set_alt_name("orc");
    set_race("orc");
    set_gender(1);
    set_alias("taskmaster");
    set_short("An orcish taskmaster");
    set_long(
"This huge orc spins his whip through the air and snaps it.  His hair. "+
"sticks up off his head is spikes.  His bear feet are covered in dirt. "+
"His greasy tunic and pants barely fit him.\n");
    set_level(20);
    set_al(-50);
move_object((clone_object(si+"/whip.c")),TO);
    init_command("wield whip");
    load_chat(2, ({
"Taskmaster says: Work you maggot.\n",
"Taskmaster says: Get to work before I flay your hide.\n"
}));

}

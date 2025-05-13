
inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
    set_name("ogre");
    set_race("ogre");
    set_gender(1);
    set_alias("ogre");
    set_short("An ogre berzerker");
    set_long(
"An massive ogre, his skull protrudes horribly.  He stands at least twelve "+
"feet tall.  He waves a tree trunk around as if it were a twig.  Saliva "+
"froths from his mouth freely and drips on the ground.\n");
    set_level(13);
    set_hp(350);
    set_al(-40);
    set_ac(5);
    set_wc(16);
    set_chance(8);
    set_spell_dam(10);
    set_spell_mess2("The ogre berzerker bashes you with his tree trunk!!\n");
move_object(clone_object(si+"/tree_trunk.c"),TO);
    init_command("wield tree");
}

inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
  if(arg) return;
    set_name("ogre");
    set_race("ogre");
    set_gender(1);
    set_alias("ogre");
    set_short("An ogre watchman");
    set_long(
"A small ogre, he is only about ten feet tall.  However, he is very wide. "+
"in the shoulders and walks as if he knows how to handle himself.  He "+
"holds a massive club that seems like a toothpick in his hands\n");
    set_level(13);
    set_hp(350);
    set_al(-40);
    set_ac(5);
    set_wc(16);
    set_aggressive(1);
    move_object(clone_object(si+"/club.c"),TO);
    init_command("wield club");
    load_chat(2, ({
"Ogre says:  No man may enter the realm of Darkstaff.\n",
"Ogre says:  The ogres of Ogram will protect this cavern.\n"
}));
}

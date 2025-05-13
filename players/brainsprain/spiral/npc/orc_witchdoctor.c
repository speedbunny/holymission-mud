inherit "obj/monster";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
    ::reset(arg);
if(arg) return;
       set_name("Orc Witchdoctor");
      set_alt_name("orc");
    set_race("orc");
    set_gender(1);
    set_alias("witchdoctor");
    set_short("An orcish witchdoctor");
    set_long(
"A tiny orcish shrouded in a dark cloak.  He is mumbling in an odd tongue. "+
"What little bit of his face is not shrouded is a sickly green color. "+
"His whole body shakes and his hands are palsied.\n");
     set_level(22);
    set_al(-40);
    set_chance(9);
    set_spell_dam(10);
    set_spell_mess2("The orcish witchdoctor wiggles his fingers and mumbles!\n");
    move_object(clone_object(si+"/cloak.c"),TO);
    init_command("wear cloak");
}


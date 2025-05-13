#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
    set_name("oak");
    set_alias("tree");
    set_short("oak");
    set_long("A dead oak tree or is it?.\n");
    set_gender(1);
    set_level(4);
    set_aggressive(1);
    set_al(-200);
    set_chance(10);
    set_spell_mess1("The oak bends down and whips you with it's branches.");
    set_spell_mess2("The wind whips by as the tree tries to spear you.");
    set_spell_dam(10);
}

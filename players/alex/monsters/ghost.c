#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
 
    set_name("ghost");
    set_alias("ghost");
    set_short("Ghost of a prisoner");
    set_long("These dungens have seen alot of use as this ghost proves.\n");
    set_gender(1);
    set_level(6);
    set_aggressive(1);
    set_al(-500);
    set_chance(20);
    set_spell_mess1("Ghost claws at you with it's deathly cold arms.");
    set_spell_mess2("Ghost paws at you.");
    set_spell_dam(10);
}
 

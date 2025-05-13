#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
 
    set_name("Knights suit of armour");
    set_alt_name("suit");
    set_alias("knight");
    set_short("A Knight's suit of armour");
    set_long("As you look at it you are startled by a glow within the armour.\n"+
             "You realise that this must be Alex's fabled KNIGHT armour which\n"+
             "has a life of its own and will project its self against all harm.\n"+
             "The boots look a bit lose.\n");
    set_gender(1);
    set_level(10);
    set_aggressive(0);
    set_al(100);
    set_chance(10);
    set_spell_mess1("Head buits you hard.");
    set_spell_mess2("smashes his head against his opponent.");
    set_spell_dam(20);
}
 

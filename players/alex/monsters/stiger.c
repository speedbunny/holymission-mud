#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
    move_object(clone_object("/players/alex/weapons/sttooth"),ME);
 
    set_name("Cathan guard");
    set_alias("tiger");
    set_alt_name("cathan");
    set_alt_name("guard");
    set_short("A Cathan guard");
    set_long("A fearce guard who closly resembles a sbertooth tiger \n"+
             "that is looking very hungery.\n");
    set_gender(1);
    set_level(19);
    set_aggressive(0);
    set_al(0);
    set_chance(40);
    set_spell_mess1("You wince at the speed of the hit.");
    set_spell_mess2("Saber teeth slash your neck.");
    set_spell_dam(40);
    add_money(2000);  
}
 
 

inherit "/obj/monster";
#define ME this_object()
 
    reset(arg) {
     ::reset(arg);
     if (arg) return ;
 
 
    move_object(clone_object("/players/alex/armour/bring"),ME);
    command("wear ",ME);
 
        set_name("hag");
        set_level(10);
        set_al(-300);
        set_alias("old Hag");
        set_short("A old Hag");
        set_long(
        "She is muttering to her self and is looking at you\n"+
        "as if to tell you to go away and leave her alone\n" );
        set_aggressive(0);
        set_chance(40);
        set_spell_mess1("Hag screams so high it hurts");
        set_spell_mess2("Hag hurls a glob of mud right at your face");
        set_spell_dam(10);
        add_money(100);
 
}

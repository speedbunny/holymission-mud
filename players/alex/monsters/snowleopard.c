#define ME this_object()
inherit "obj/monster";
 
    reset(arg) {
     ::reset(arg);
     if (arg) return;
 
    move_object(clone_object("/players/alex/weapons/lclaw"),ME);
 
        set_name("snowleopard");
        set_alias("leopard");
        set_alt_name("cathan");
        set_alt_name("guard");
        set_short("Cathan guard");
        set_long("This guard reminds you so much of a snow leopard that it must \n" +
                 "belong to the leopard clan.  It looks fast.\n" );
        set_gender(1);
        set_level(15);
        set_al(0);
        set_aggressive(0);
        set_spell_mess1("The guard realy hits  gets behind you and gives you a THUMP.\n");
        set_spell_mess2("Leopard hits you with it's claw ochh!!!.\n");
        set_chance(80);
        set_spell_dam(25);
 
        add_money(2000);
 
}
 

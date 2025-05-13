inherit "obj/monster";

object key;
status arg;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("eye");
    set_level(20);
    set_size(2);
    set_hp(700);
    set_al(0);
    set_race("eye");
    set_short("A burning eye");
    set_long("This burning eye looks into your soul.\n"+
             "His view can kill.\n");
    set_ac(8);
    set_wc(15);

    set_spell_mess1("The eye looks into the eyes of his opponent.");
    set_spell_mess2("The eye looks into your eyes.");
    set_chance(25);
    set_spell_dam(20);

    key=clone_object("/players/kelly/obj/magickey");
    move_object(key,this_object());

}


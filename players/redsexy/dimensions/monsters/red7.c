inherit "obj/monster";
string chats;
reset(arg){
    ::reset(arg);
    if(arg) return;
        set_name("Red Dimension Demon");
        set_gender(1);
        set_race("demon");
        set_short("A red dimension demon");
        set_long("The red demon has eyes that glower at you with meanace.\n"+
        "He has been trained well in the dimensions, and is ready to fight.\n");
        set_alias("demon");
        set_level(10);
        set_hp(230);
        set_ac(3);
        set_wc(12);
        set_spell_mess2("The demon casts the red dimension spell of backdraft!\n");
        set_spell_mess1("The backdraft fire engulfs you.\n");
        set_spell_dam(50);
        set_chance(15);
        load_chat(5,({"The demon says: We worship by the God of War.\n"}));
}


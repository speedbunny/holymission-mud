inherit "obj/monster";
string chats;
reset(arg){
    ::reset(arg);
    if(arg) return;
        set_name("Blue Dimension Demon");
        set_gender(1);
        set_race("demon");
        set_short("A blue dimension demon");
        set_long("The blue demon has eyes that glower at you with meanace.\n"+
        "He has been trained well in the dimensions, and is ready to fight.\n");
        set_alias("demon");
        set_level(10);
        set_hp(230);
        set_ac(3);
        set_wc(12);
        set_spell_mess2("The demon casts the blue dimension spell of drown!\n");
        set_spell_mess1("The drown waves suffocate you.\n");
        set_spell_dam(50);
        set_chance(15);
        load_chat(5,({"The demon says: We fear the God of Stillness, for he weakens ours instincts.\n"}));
}


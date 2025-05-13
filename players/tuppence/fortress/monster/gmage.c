inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
set_name("Mage guard");
set_alt_name("mage");
    set_race("elf");
    set_short("Mage guard");
    set_long("A mage guard standing here to make sure no one makes any trouble.\n");
    set_alias("guard");
    set_level(22);
    set_al(-500);
    set_ac(9);
    set_wc(20);
    set_spell_mess1("Mage guard casts a spell.\n");
    set_spell_mess2("Mage guard casts a fireball at you!\n");
    set_chance(40);
    set_spell_dam(15);
}

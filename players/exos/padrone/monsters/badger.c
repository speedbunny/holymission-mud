inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("badger");
    set_level(2);
    set_female();
    set_ac(3);
    set_wc(10);
    set_al(10);
    set_spell_mess1("The badger bites her opponent.");
    set_spell_mess2("The badger bites you. And she bites hard!");
    set_spell_dam(10);
    set_chance(19);
    set_short("A badger");
    set_long("This is a badger. She seems to be minding her own business,\n" +
      "but if she is attacked she will probably defend herself\n" +
      "with some determination.\n");
}

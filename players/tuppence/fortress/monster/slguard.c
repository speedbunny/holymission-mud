inherit "obj/monster";
void reset(int arg) {
    ::reset();
    set_name("guard");
    set_race("orc");
    set_short("A mad guard");
    set_long("He is mad that you woke him up, now you will have to pay.\n");
    set_level(21);
    set_al(-67);
    set_ac(12);
    set_wc(22);
    set_aggressive(1);
}

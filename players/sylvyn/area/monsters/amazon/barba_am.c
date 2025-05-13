inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("barba amarilla");
    set_alias("amarilla");
    set_level(37);
    set_move_at_reset();
    set_ac(5);
    set_race("reptile");
    set_alt_name("snake");
    set_al(-500);
    add_money(300);
    set_short("barba amarilla");
    set_long(
    "This is the Barba Amarilla or Fer-de-lance, which is a snake \n"+
    "about 7 ft. long.\n"
    );
}

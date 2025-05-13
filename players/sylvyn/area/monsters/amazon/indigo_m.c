inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("indigo macaw");
    set_alias("macaw");
    set_move_at_reset();
    set_race("bird");
    set_alt_name("bird");
    set_level(30);
    set_ac(5);
    set_wc(5);
    set_al(-750);
    add_money(900);
    set_short("macaw");
    set_long(
      "An Indigo Macaw, also known as Anodorhynchus leari, is a exotic \n"+
      "type of bird.\n"
    );


}

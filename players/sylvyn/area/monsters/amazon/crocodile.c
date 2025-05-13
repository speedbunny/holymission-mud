inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("crocodile");
    set_alias("croc");
    set_race("lizard");
    set_move_at_reset();
    set_number_of_arms(2);
    set_level(40);
    set_al(-1000);
    set_wc(20);
    set_ac(20);
    add_money(2000);
    set_short("A Giant Crocodile");
    set_long(
      "An ancient and deadly crocodile. It's mere presence makes\n"
    "you shiver in your boots.\n"
    );
}

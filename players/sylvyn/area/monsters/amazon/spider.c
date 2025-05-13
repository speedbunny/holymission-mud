inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("tarantula");
    set_alias("spider");
    set_race("spider");
    set_move_at_reset();
    set_number_of_arms(8);
    set_level(57);
    set_al(-1000);
    set_wc(20);
    set_ac(40);
    add_money(2500);
    set_short("A Huge Tarantula");
    set_long("A Giant Tarantula. It stands over 8 feet tall!!!\n" +
      "It the fiercest predator you have seen so far.\n");
}

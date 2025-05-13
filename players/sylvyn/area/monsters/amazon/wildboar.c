inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

      set_name("wild boar");
      set_alias("boar");
      set_race("boar");
      set_move_at_reset();
      set_number_of_arms(2);
      set_level(35);
      set_ac(20);
      set_wc(10);
      set_al(-500);
      add_money(1000);
      set_short("A Wild Boar");
      set_long(
      "Here is a large wild boar with large pointy tusks. It doesn't seem\n"
      "to like intruders in its area.\n"
      );
}

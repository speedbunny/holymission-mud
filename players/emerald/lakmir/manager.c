inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("manager");
    set_short("The manager");
    set_long("He is a small and slim elf. He isn't a fighter, "
            +"but he is a very good manager.\n");
    set_race("elf");
    set_size(2);
    set_al(400);
    set_level(14);
    set_hp(600);
    set_sp(600);
    set_wc(12);
    set_ac(0);
    load_chat(10,({
       "The manager says: I need a cook!\n",
       "The manager says: Will you make the Druid's supper?\n",
    }) );

  }
}

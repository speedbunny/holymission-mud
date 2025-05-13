inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("tapeworm");
    set_alias("worm");
    set_race("insect");
    set_short("An aggressive tapeworm");
    set_long("It looks very angry.\n");
    set_level(1);
    set_ep(0);
    set_hp(140);
    set_wc(14);
    set_ac(2);
    set_size(1);
    set_al(-100);
    set_aggressive(1);
    load_a_chat(60,
      ({"OUCH ! The tapeworm sticks its teeth into your behind !\n" }) );
  }
}

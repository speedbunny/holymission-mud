inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("hound");
    set_level(6);
    set_hp(150);
    set_al(0);
    set_race("hound");
    set_short("A hell hound");
   set_long("A hound from hell with razor claws\n");
    set_wc(3);
    set_ac(3);
    set_aggressive(8);
  set_size(6);
}

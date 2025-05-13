inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("hound");
    set_level(10);
    set_hp(400);
    set_al(0);
    set_race("hound");
    set_short("A hell hound");
   set_long("A hound from hell with razor claws\n");
    set_wc(5);
    set_ac(5);
    set_aggressive(20);
       set_size(10);
}

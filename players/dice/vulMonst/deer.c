inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("deer");
    set_alias("deer");
    set_alt_name("**");
    set_short("A deer");
set_long("A deer walking around.\n"+
         "She is easily scared.\n");
    set_race("deer");
    set_level(5);
    set_al(10);
    set_hp(100);
    set_ep(50);
set_gender(2);
    set_aggressive(0);
set_whimpy(1);
    return 1;
}



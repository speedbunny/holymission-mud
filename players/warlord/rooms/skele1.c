inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("skeleton");
    set_short("Skeleton");
    set_long("This is a fairly large skeleton, he looks pretty tough\n");
    set_level(14);
    set_wc(14);
    set_ac(8);
    set_hp(240);
    set_al(-750);
    set_aggressive(1);
    set_move_at_reset(1);
    return 1;
}


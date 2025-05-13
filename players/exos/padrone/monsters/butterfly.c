inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("butterfly");
    set_level(1);
    set_ep(60);
    set_hp(1);
    set_wc(1);
    set_ac(10);
    set_al(20);
    set_short("A butterfly");
    set_long("A beautiful, golden butterfly, happily\n" +
      "fluttering around among the bushes.\n");
}

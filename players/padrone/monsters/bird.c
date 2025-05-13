inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("bird");
    set_alias("small bird");
    set_level(1);
    set_ep(60);
    set_hp(10);
    set_ac(2);
    set_wc(4);
    set_al(50);
    set_short("A small bird");
    set_long("This is a small bird. Who knows what it can be called?\n" +
      "It looks very nice and friendly.\n");
}

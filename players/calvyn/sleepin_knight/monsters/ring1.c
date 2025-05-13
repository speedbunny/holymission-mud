inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Ring Finger");
    set_short("Ring Finger");
    set_alias("ring");  
    set_gender(random(2));
    set_level(4);
    set_wc(4);
    set_ac(1);
    set_move_at_reset();
    set_long(
      "The ring finger stands proud with a gold band around his neck\n");
}

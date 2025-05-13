inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Eye Ball");
    set_short("Eye Ball");
    set_alias("eye");  
    set_gender(random(2));
    set_level(15);
    set_wc(15);
    set_ac(6);
    set_move_at_reset();
    set_long(
      "A large blood shot eye floats before you. It's retina contracts with the\n"
"light. It just stares at you and you feel like its looking at your soul.\n");
}

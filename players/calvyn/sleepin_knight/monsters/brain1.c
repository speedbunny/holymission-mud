inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Brain");
    set_short("Brain");
    set_alias("brain");  
    set_gender(random(2));
    set_level(17);
    set_wc(18);
    set_ac(8);
    set_move_at_reset();
    set_long(
      "A mass of generous porportions lays before you. You can feel the energy\n"
"that it emits. A hum of neuronic activity can be heard from within it's mass.\n");
    load_chat(8,({ "A thunderous voices pronounces, I am the Brain You can not kill me\n",
      }));
}

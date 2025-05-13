inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Thumb");
    set_short("Thumb");
    set_alias("thumb");  
    set_gender(random(1));
    set_level(7);
    set_wc(6);
    set_ac(3);
    set_move_at_reset();
    set_long(
      "The thumb stands proud watching over his fellow fingers.\n");
    load_chat(8,({ "The thumb jumps on your back and tries to hitch a ride!\n",
      }));
}

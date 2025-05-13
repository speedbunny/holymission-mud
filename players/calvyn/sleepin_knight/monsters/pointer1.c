inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Pointer Finger");
    set_short("Pointer Finger");
    set_alias("pointer");  
    set_gender(random(2));
    set_level(6);
    set_wc(5);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "The pointer finger stands there accusing you.\n");
    load_chat(8,({ "The pointer finger points at you!\n",
        "The pointer finger says, 'You did it!'\n",
      }));
}

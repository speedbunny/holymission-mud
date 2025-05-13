inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Mouth");
    set_short("Mouth");
    set_alias("mouth");  
    set_gender(random(1));
    set_level(13);
    set_wc(12);
    set_ac(5);
    set_move_at_reset();
    set_long(
      "A large gaping mouth stands before you. A large puddle of drool has\n"
"developed below her. All she does is talk.\n");
    load_chat(8,({ "Yak Yak Yak Yak Yak Yak Yak!\n",
        "'Spit' The mouth hocks a lugy on you.\n",
      }));
}

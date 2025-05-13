inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Hugh Pectoral");
    set_short("Hugh Pectoral");
    set_alias("pectoral");  
    set_gender(random(0));
    set_level(11);
    set_wc(10);
    set_ac(4);
    set_move_at_reset();
    set_long(
      "The huge pectoral mussle looks down upon you.\n");
    load_chat(8,({ "Look at the little girly man!\n",
        "I am big, you are small, I will crush you.\n",
      }));
}

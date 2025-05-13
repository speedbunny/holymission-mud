inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Rat");
    set_short("Rat");
    set_alias("rat");
    set_gender(random(2));
    set_level(3);
    set_wc(5);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "A dirty stinking rat from the cellars.  It actually looks happy to see\n"+
      "you.  In fact it looks like it's drooling.\n");
    load_chat(8,({ "The rat goes: SQUEEK!!\n",
        "The rat sniffs your legs for cheese.\n",
      }));
}

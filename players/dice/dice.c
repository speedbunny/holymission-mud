inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("Coffee-addicted Dice");
    set_alias("dummy");
    set_alt_name("dice");
    set_short("Coffee-addicted Dice");
    set_long("Coffee-addicted Dice the SHIHAN of ninja's.\n"+
      "He is feeling very well.\n"+
      "He is about your age and has a body worth of envy:\n"+
      "tall and well-build with wide shoulders, massive\n"+
      "pectorals, and think, tawny legs.\n"+
      "He feels rather lonely.\n"+
      "He has an account at the Money Brokers Assoc.\n"+
      "        Dice is carrying :\n"+
      "A white ninja-robe (small).\n"+
      "Galadriel's fixer (v1.8).\n"+
      "Mirror of Galadriel (v3.6).\n"+
      "Galadriel's librarian (v3.0).\n"+
      "Bboots (Board boots V 1.2) (worn).\n"+
      "Cyhoeddus dynion (maes).\n"+
      "The Display, v#1.0.\n"+
      "Callout util.\n"+
      "A wakizashi.\n"+
      "A katana.\n");
    set_race("nosferatu");
    set_level(1);
    set_al(1);
    set_hp(610);
    set_sp(213);
    set_wc(0);
    set_ac(1);
    set_aggressive(0);
    set_gender(1);
   set_whimpy(90);
    return 1;
}



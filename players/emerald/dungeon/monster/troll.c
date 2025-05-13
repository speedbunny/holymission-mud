inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("rock troll");
    set_race("troll");
    set_long("A lean, wiry troll with cunning eyes.\n");
    set_level(45);
    set_al(-400);
    set_ac(18);
    set_wc(15);
    set_aggressive(1);
    set_chance(25);
    set_spell_mess1("Quicker than lightning, the troll jabs with his foot");
    set_spell_mess2("You are kicked hard by the troll");
    set_spell_dam(35);
    add_money(942);
}

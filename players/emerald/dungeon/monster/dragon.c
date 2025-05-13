inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("scarlet dragon");
    set_alias("dragon");
    set_long("The light glistens off the red and gold scales of an\n" +
      "enormous dragon.  It stares at you with highly intelligent eyes,\n" +
      "appraising your worthiness as an opponent.  A thin stream of vapour\n" +
      "curls out of its nostrils.  Enormous wings are folded neatly on its\n" +
      "back.  You don't know which is worse, to be burned alive by its\n" +
      "breath or ripped apart by its long, cruel claws.\n");
    set_level(95);
    set_al(-500);
    set_ac(30);
    set_wc(45);
    set_aggressive(1);
    set_chance(20);
    set_spell_mess1("A blast of flames bursts from the dragon's mouth.\n");
    set_spell_mess2("You are engulfed in flames!");
    set_spell_dam(65);
    add_money(10000);
}

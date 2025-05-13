inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("werewolf");
    set_race("werewolf");
    set_long("This creature is covered in long, shaggy fur.  Its fangs\n" +
      "protrude from its mouth a full three inches.  It looks at you with\n" +
      "a gaze of pure hatred.\n");
    set_level(50);
    set_al(-500);
    set_ac(14);
    set_wc(23);
    set_aggressive(1);
    set_chance(20);
    set_spell_mess1("The werewolf bites its opponent.");
    set_spell_mess2("The werewolf bites you!");
    set_spell_dam(45);
    add_money(890);
}

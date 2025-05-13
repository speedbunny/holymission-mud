inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("huge spider");
    set_alias("spider");
    set_long("Its eyes glow with a green light of pure evil.\n");
    set_level(24);
    set_al(-1000);
    set_ac(32);
    set_wc(20);
    set_aggressive(1);
    set_chance(20);
    set_spell_mess1("The spider sinks its fangs into flesh.");
    set_spell_mess2("You feel needle-sharp fangs penetrate your skin");
    set_spell_dam(45);
}

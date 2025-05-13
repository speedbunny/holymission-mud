inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("vampire bat");
    set_alias("bat");
    set_long("Vicious fangs and beady red eyes send shivers of terror\n" +
             "running down your spine.\n");
    set_level(13);
    set_al(-500);
    set_ac(10);
    set_wc(12);
    set_aggressive(1);
    set_chance(20);
    set_spell_mess1("The bat latches on to the neck of its opponent.");
    set_spell_mess2("The bat latches onto your neck, draining your blood!");
    set_spell_dam(45);
}

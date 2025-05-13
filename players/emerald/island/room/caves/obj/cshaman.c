inherit "/obj/monster";
object shad;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;  
  set_name("orc chief shaman");
  set_alt_name("shaman");
  set_short("The orc chief shaman");
  set_race("orc");
  set_alias("chief");
  set_long("A wise looking orc.\n");
  set_gender(1+random(1));
  set_aggressive(1);
  set_level(30);
  set_al(-4000);
  add_money(3000+random(50));
  set_number_of_arms(2);
  set_spell_mess1("The Orc shaman casts a flamestrike !\n");
  set_spell_mess2("You are hit by a flamestrike !\n");
  set_chance(50);
  set_spell_dam(100+random(90));
  shad = clone_object("/obj/shadows/sanct_shad");
  shad->start_shadow(this_object(),0);
  shad = clone_object("/obj/shadows/fireshield_shad");
  shad->start_shadow(this_object(),0);
}

int detect_invis() {
    return 1;
}

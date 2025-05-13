/* Water Elemental */

inherit "obj/monster";
    
reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("water elemental");
    set_level(35);
    set_al(1000);
    set_alias("elemental");
    set_race("elemental");
    set_short("Water elemental");
    set_long("A flowing watery heap with no real form.\n");
    set_wc(19);
    set_ac(15);
    set_aggressive(1);
    set_spell_mess1("Water elemental washes your face!");
    set_spell_mess2("\nWater elemental sprays you with a water jet!\n");
    set_chance(20);
    set_spell_dam(45);
  }
}

inherit "players/tamina/teds/inherits/wand";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("wand of fire");
  set_alias("ruby wand");
  set_short("A Short Ruby Wand");
  set_long(
  "This wand appears to be made out of pure ruby!\n"+
  "It feels magical, maybe you should get it identified?\n");

  set_command("fry");
  set_spell_type("bolt of fire");
  set_spell_mess1("A bolt of fire shoots forth!");
  set_spell_mess2("You burn your oponent with a bolt of fire!");
  set_charges(random(5) + 2);
  set_value(charges * 100);
  set_weight(1);
  set_kind(5);
  set_spell_dam(20 + random(8));
  elem = ({1, 12}); 
}

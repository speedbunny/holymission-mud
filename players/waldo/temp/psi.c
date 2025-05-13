inherit "players/tamina/teds/inherits/wand";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("Delphi Helmet");
  set_alias("helmet");
  set_short("A Delphi Juicers Helmet");
  set_long(
  "This is the psi-helmet of a Delphi Juicer. This helmet grants\n"+
  "its wearer the power to shoot psi-bots at people.\n");

  set_command("psi-blast");
 set_spell_type("mind bolt from "+this_player()->query_name()+". Your\n"+
                "head begins to pound and your blood begins to boil.\n"+
                "Blood begins to poor from your mouth and eyes!\n");
  set_spell_mess1("You reach out with your mind and blast your victim!");
  set_spell_mess2("Your mind turns your victims mind to jelly!");
  set_charges(100000);
  set_value(charges * 100);
  set_weight(1);
  set_kind(5);
 set_spell_dam(10000000);
  elem = ({1, 12}); 
}

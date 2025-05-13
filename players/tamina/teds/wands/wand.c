inherit "players/tamina/teds/inherits/wand";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  name = "wand of cold";
  alias = "glass wand";
  short_desc = "A Thin Glass Wand";
  long_desc =
  "This wand appears to be made out of pure diamond!\n"+
  "It feels magical, maybe you should get it identified?\n";

  do_cmd = "freeze";
  spell_type = "cone of cold";
  spell_mess1 = "A cone of cold shoots forth!";
  spell_mess2 = "A blast of cold bursts from the wand!";
  charges = random(6) + 3;
  value = charges * 120;
  weight = 1;
  spell_dam = 25 + random(8);
  kind = 5;
  elem = ({3, 12});
}

inherit "players/tamina/teds/inherits/wand";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  name = "wand of blasting";
  alias = "clear wand";
  short_desc = "A Clear Wand";
  long_desc =
  "This wand appears to be made out of some silver metal.\n"+
  "It feels magical, maybe you should get it identified?\n";

  do_cmd = "blast";
  spell_type = "blast of powerful air";
  spell_mess1 = "A blast of pressurized Air emits from a wand !";
  spell_mess2 = "     W O O S H !!\nYour opponent is blasted with AIR !";
  charges = random(7) + 3;
  value = charges * 75;
  weight = 1;
  spell_dam = 12 + random(8);
  kind = 5;
  elem = ({12, 15});
}

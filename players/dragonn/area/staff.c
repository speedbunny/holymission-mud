inherit "/players/tamina/teds/inherits/wand";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  name = "wand of lightning";
  alias = "silver wand";
  short_desc = "A Silver Wand";
  long_desc  =
  "This wand appears to be made out of solid silver!\n"+
  "It feels incredibly magical; maybe you should get it identified?\n";

  do_cmd = "bolt";
  spell_type = "bolt of lightning";
  spell_mess1 = "A bolt of Lightning explodes !";
  spell_mess2 = "       -=>  ZzAaPp  <=-\nYour opponent is fried with a Bolt of Lightning !";
  charges = random(7) + 3;
  value = charges * 300;
  weight = 1;
  spell_dam = 25 + random(8) + random(this_player()->query_level());
  kind = 5;
  elem = ({2, 12});
}

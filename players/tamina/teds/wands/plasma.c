inherit "/players/tamina/teds/inherits/wand";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  name = "wand of plasma";
  alias = "blue wand";
  short_desc = "A Deep Blue Wand";
  long_desc  =
    "This mesmorizing blue wand seems to hum with power.\n"+
    "You can feel great destructive abilities ooze from the very\n"+
    "fabric from which it was made...\n";

  do_cmd = "engulf";
  spell_type = "bolt of plasma";
  spell_mess1 = "A Plasma Bolt shoots from a Blue Wand !";
  spell_mess2 = "Your opponent is engulfed in a powerful blue light\n"+
		"He screams in pure agony !!";
  charges = random(8) + 2;
  value = charges * 500;
  weight = 1;
  spell_dam = 25 + random(8) + random(this_player()->query_level()) + 
              random(this_player()->query_wis());
  kind = 5;
  elem = ({0, 12});
}

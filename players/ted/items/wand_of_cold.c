inherit "players/ted/items/wand";

reset(arg) {
  if(arg) return;
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
  charges = random(5)+2;
  value = charges*120;
  weight = 1;
  spell_dam = 25;
}

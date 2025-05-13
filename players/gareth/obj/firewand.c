inherit "players/gareth/obj/wand";


reset(arg) {
  if(arg) return;
  name = "wand of fire";
  alias = "ruby wand";
  short_desc= "A Short Ruby Wand";
  long_desc=
  "This wand appears to be made out of pure ruby!\n"+
  "It feels magical.\n";
  do_cmd="fry";
  spell_type="bolt of fire";
  spell_mess1="A bolt of flame shoots forth!";
  spell_mess2="You burn your opponent with a ray of fire! He's toast.";
  charges=random(5)+2;
  value=charges*100;
  weight=1;
  spell_dam=30;
}

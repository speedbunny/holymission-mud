inherit "/obj/treasure";
reset(arg){
  if (arg)return;
  set_id("letter");
  set_short("A tattered letter");
  set_long("A tattered letter that says 'The cauldrons of brass lead "+
           "through fire to the land of Sheankala.  Beware the beast "+
           "of the Pit who guards this evil path!\n");
  set_value(2);
  set_weight(1);
}

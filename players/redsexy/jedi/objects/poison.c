inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("nakbar");
  set_alt_name("nakbar");
  set_short("A juicy nakbar");
  set_long("Nakbar is the most vile poison known to mankind.\n" +
           "A juicy fruit, or so it seems, it can only be prepared by experts.\n" +
           "The juice is highly toxic, so do not consume it.\n");
  set_strength(45);
  set_poison(80);    
  set_alias("nakbar");
  set_eater_mess("You'll probably die very soon, you idiot.\n");
  set_eating_mess(" has eaten the Nakbar.  Seek medical attention, quickly!\n");
  set_value(1);
  set_weight(1);
}




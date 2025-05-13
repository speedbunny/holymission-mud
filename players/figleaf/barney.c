inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("barney");
  set_alias("dinosaur");
  set_short("Barney the dinosaur");
  set_long("A big purple dinosaur with a stupid grin on his face that\n"+ 
"makes you want to knock his teeth out!\n");
  set_race("barney");
  set_level(25);
  set_al(1000);
  set_aggressive(0);
  return 1;
}



inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("limp wrist");
  set_short("wrist");
  set_long("This is a limp wrist which has been rotting in this cave for a few weeks\nnow. You would usually turn away in disgust, but this particular hand has its\nfingernails coated with gold nail polish. Who knows, it might be worth a lot of\nmoney...\n");
  set_value(500);
  set_weight(1);
  return 1;
}


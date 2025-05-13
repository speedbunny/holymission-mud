inherit "/obj/weapon";
void reset (int arg) {
  ::reset(arg);
  if (arg) return;
  switch(random(3)) {
    case 0:
      set_name("short sword");
      set_short("A short sword");
      set_long("An ordinary short sword.\n");
      set_class(11);
      set_value(250);
      break;
    case 1:
      set_name("curved sword");
      set_short("A curved sword");
      set_long("An nasty looking curved sword.\n");
      set_class(13);
      set_value(500);
      break;
    case 2:
      set_name("sharp sword");
      set_short("A sharp sword");
      set_long("A very sharp looking sword.\n");
      set_class(15);
      set_value(750);
      break;
  }
  set_alias("sword");
}

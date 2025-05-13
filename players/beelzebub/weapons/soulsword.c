
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("Soulsword");
  set_alias("soulsword");
  set_class(17);
  set_short("Soulsword");
  set_long("This special sword is guarded by the Sentinels of the \n" +
           "Netherworld.  It calls upon the power of your soul to \n" +
           "provide a swift and powerful attack.  This weapon was \n" +
           "forged to kill the evil and the weak in spirit. \n");
  set_value(5500);
  set_weight(3);
  return 1;
}


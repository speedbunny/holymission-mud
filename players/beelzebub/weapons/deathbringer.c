
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("Deathbringer");
  set_alias("deathbringer");
  set_class(15);
  set_short("The Deathbringer");
  set_long("This is the Deathbringer.  A weapon made famous in the \n" +
           "Netherworld because the only way to obtain one, is to kill \n" +
           "a Hydra, which isn't an easy task.  It is a powerful weapon, \n" +
           "but only a skilled warrior can use it effectively. \n");
  set_value(4500);
  set_weight(3);
  return 1;
}


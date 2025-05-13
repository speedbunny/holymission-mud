inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("teeth");
  set_class(19);
  set_short("Tnoggoth's teeth");
  set_long("These teeth are stronger than steel and have finished off countless adventurers.\nIt is a quite formidable weapon.\n");
  set_value(10000);
  set_weight(2);
  return 1;
}


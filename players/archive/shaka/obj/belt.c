inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("belt");
  set_type("belt");
  set_ac(0);
  set_short("A golden/copper klingon belt");
  set_long("This belt is made for a special occasion, a inscription \n"+
           "reads :tlhoghvaD Qa'SImor Hel'etlhe.\n");
  set_value(0);
  set_weight(0);
  return 1;
}


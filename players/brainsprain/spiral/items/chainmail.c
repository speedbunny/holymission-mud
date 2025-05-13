inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);

    set_name("chainmail");
    set_alias("chainmail");
    set_short("Steel chainmail");
    set_long(
"This chainmail is hand made out of fine steel.  The links of the suite "+
"are strong.  This is obviously ancient armor but it gleams like it was "+
"fashioned yesterday.  There is a hood that is connected to the top of "+
"the mail.\n");
    set_value(200);
    set_weight(7);
    set_type("armour");
    set_ac(5);
  }


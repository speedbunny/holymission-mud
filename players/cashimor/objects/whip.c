inherit "obj/weapon";

reset(arg) {
  if(!arg) {
    set_name("whip");
    set_short("A whip");
    set_long("An rigid but otherwise normal whip.");
    set_class(5);
    set_value(8);
    set_weight(1);
    set_read("General purpose incorperated.");
  }
}


inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);

    set_name("helmet");
    set_alias("helmet");
    set_short("A steel helmet");
    set_long(
"A finely wrought steel helmet.  The nose guard descends gracefully and "+
"connects to the chin strap.  A feather plume protrudes from the top of "+
"the helmet.  The entire helmet is detailed with vivid battle scenes.\n");
    set_value(75);
    set_weight(2);
    set_type("helmet");
    set_ac(2);
  }

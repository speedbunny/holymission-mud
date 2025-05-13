inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);

    set_name("cloak");
    set_alias("cloak");
    set_short("A dark cloak");
    set_long(
"A dark cloak with a high collar.  There is a thick, volumous hood attached "+
"to the cloak.  Stars, moons, and other symbols of the occult have been "+
"embroidered into the cloak.  The bottom of the cloak is dirty and frayed "+
"from being dragged over the floor.\n");
    set_value(400);
    set_weight(1);
    set_type("cloak");
    set_ac(2);
  }

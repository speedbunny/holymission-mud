inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Cloak of Protection");
    set_alias("cloak of protection");
    set_type("cloak");
    set_size("any");
    set_short("A Richly Embroidered Cloak");
    set_long(
      "This cloak looks soft and confortable, but it seems to project\n"+
      "some type of force that protects the wearer.\n");
    set_ac(1); //Colossus 070394: Changed from 2 to 1
    set_weight(2);
    set_value(575);
}

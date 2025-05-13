inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("gray cloak");
    set_alias("cloak");
    set_type("cloak");
    set_ac(2);
    set_size(3);
    set_short("A dark gray cloak");
    set_long("At first glance, this cloak appears to be an average\n"+
     "garment, but a certain amount of power radiates from it. It\n"+
     "feels stronger than it looks.\n");
    set_weight(1);
    set_value(500);
    }
}
wear(arg) {
  if((this_player()->query_race() != "elf") &&
     (this_player()->query_race() != "half-elf")) {
    write("You must be of elven decent to wear this armour.\n"); 
    return 1;
   }
   return ::wear(arg);
  }
  query_mage_wear() {return 1;}

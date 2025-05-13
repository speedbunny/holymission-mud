inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("adamantine bracers");
    set_alias("bracers");
    set_type("arm");
    set_ac(1);
    set_size(3);
    set_arm_light(1);
    set_short("Adamantine Bracers");
    set_long("A pair of adamantine arm/wrist guards, they have\n"+
       "pictures of shields enscribed on them. It seems to weigh\n"+
       "almost nothing.\n");
    set_weight(1);
    set_value(1000);
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

   





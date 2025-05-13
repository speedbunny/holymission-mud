inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("Elven Platemail");
    set_alias("platemail");
    set_type("armour");
    set_ac(4);
    set_size(3);
    set_arm_light(1);
    set_short("Elven Platemail");
    set_long("A suit of indestructable elven platemail, forged from the"+
    " gleaming metal of adamantite.\n");
    set_weight(3);
    set_value(4000);
    }
}

    wear(arg) {
      if((this_player()->query_race() != "elf") &&
         (this_player()->query_race() != "half-elf")) {
        write("You have to be of elven decent to wear this armour.\n");
        return 1;
       }
       return ::wear(arg);
      }
      

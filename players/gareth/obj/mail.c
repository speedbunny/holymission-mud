inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("Fine Chainmail");
    set_alias("chainmail");
    set_type("armour");
    set_ac(4);
    set_size(3);
    set_arm_light(1);
    set_short("Fine Chainmail");
    set_long("A suit of indestructable chainmail, forged from the"+
    	     "gleaming metal of adamantite.\n");
    set_weight(1);
    set_value(4000);
    }
}

    int query_ninja_wear() {return 1;}
    int query_summoner_wear() {return 1;}




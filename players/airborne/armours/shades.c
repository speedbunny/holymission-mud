inherit "/obj/armour";

reset(arg){
    ::reset(arg);
    if(arg) return 1;
	set_name("shades");
	set_alias("sunglasses");
	set_type("amulet");
	set_weight(1);
	set_ac(1);
	set_short("Ray Ban sunglasses");
	set_long("Really kool Ray Bans.\n");
   return 1;
}

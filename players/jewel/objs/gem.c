inherit "/obj/treasure";

reset(arg){
	if(arg) return 1;
	set_id("gem");
	set_value(1000+(random(1000)));
	set_weight(2);
	set_short("Gem");
	set_long("A dark shining gem.\n");
   return 1;
}

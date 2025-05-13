inherit "obj/torch";
reset(arg) {
    if (arg) return;
	set_weight(1); 
	set_name("lighter"); 
	set_fuel(30000);
	set_auto_light(1);
}

init() {
	add_action("light", "light" ); 
	add_action("extinguish", "unlight" ); 
	add_action("extinguish", "close" ); 
	add_action("extinguish", "extinguish" ); 
}


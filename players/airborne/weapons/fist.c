inherit "obj/weapon";

reset(arg) {
	if(arg) return;
	set_name("club of mulabi");
	set_alt_name("fist of set");
	set_alias("club");
	set_short("Mulabi's Club");
	set_long("This club that once belonged to Mulabi is also known as the Fist of Set.\n" + "It is rumored to have been used to cause the fall of the Old Ones themselves.\n" + "The skull adorming the tip of the club makes for a fearsome weapon indeed.\n");
	set_class(10 +random(8));
	set_value(1000);
	set_weight(4);
   return 1;
}

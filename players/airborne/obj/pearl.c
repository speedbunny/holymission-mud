inherit "obj/treasure";
reset(arg){
  if(arg) return 1;
	set_id("pearl");
	set_value(100+(random(200)));
	set_weight(1);
	set_short("pearl");
	set_long("A perfect pearl.\n");
   return 1;
}

inherit "obj/armour";

reset(arg){

 ::reset(arg);
 if(arg) return;

	set_name("gloves");
	set_type("gloves");
	set_short("A pair of gloves");
	set_long("A pair of gloves.\n");
	set_ac(1);
	set_weight(1);
  return 1;
}

inherit "/obj/armour";

reset (arg){
 ::reset(arg);
if (arg) return;
 set_name("dragonskin");
 set_alias("skin");
 set_value(3000);
 set_ac(4);
 set_type("armour");
 set_weight(2);
 set_size(3);
 set_short("A dragonskin");
 set_long("A dragonskin from the Western Dragon.\n");
 }


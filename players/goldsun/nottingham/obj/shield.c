inherit "obj/armour";
reset(arg){
 ::reset(arg);

if (!arg){
 set_name("steel shield");
 set_short("A steel shield");
 set_long("A steel shield with the Nottingham coat of arms engraved in it.\n");
 set_type("shield");
 set_size(3);
 set_ac(2);
 set_value(500);
 set_weight(1);
 }
} 

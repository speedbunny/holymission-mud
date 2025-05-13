inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;

set_name("chainmail");
set_type("armour");
set_alias("armour");
set_size(3);
set_ac(4);
set_value(500);
set_short("chainmail");
set_long("A series of linked chains and small plates form this armour. \n");
set_weight(5);
}

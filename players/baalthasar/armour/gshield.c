inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;

set_name("shield");
set_type("shield");
set_short("shield");
set_long("A medium shield. \n");
set_ac(1);
set_weight(1);
set_value(50);
}

inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;
set_type("glove");
set_name("gloves");
set_alias("gauntlets");
set_short("gauntlets");
set_weight(1);
set_long("A pair of steel guantlets. \n");
set_ac(1);
set_value(200);
set_size(3);
}

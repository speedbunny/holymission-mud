inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;

set_name("helmet");
set_type("helmet");
set_alias("helm")
set_alias("helm");
set_short("helmet");
set_ac(1);
set_weight(1);
set_value(60);
set_long("An iron helmet for moderate protection. \n");
}

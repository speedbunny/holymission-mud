inherit "obj/armour";

reset(arg) {
::reset(arg) ;
if (arg) return 1;

set_name("tower shield");
set_type("shield");
set_short("tower shield");
set_long("A large shield covering most of the body. \n");
set_ac(1);
set_weight(2);
set_value(90);
}

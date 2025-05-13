inherit "/obj/armour";
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_alias("helm");
 set_name("helmet");
 set_short("A metal helmet");
 set_long("A helmet made of metal.\n");
 set_value(150);
 set_weight(1);
 set_type("helmet");
 set_size(0);
 set_ac(1);
}

init() {
::init();
}

 

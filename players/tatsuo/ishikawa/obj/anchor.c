inherit "obj/treasure";

reset(arg){
::reset(arg);
if(arg) return;
set_name("anchor");
set_short("An anchor");
set_long("An old and rusted anchor, it is very heavy.\n");
set_value(10000);
set_weight(25);
}


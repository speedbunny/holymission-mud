inherit "obj/treasure";

reset(arg){
::reset(arg);
if(arg) return;
set_name("plank");
set_short("a rotting ship plank");
set_long("A rotting ship plank, looks like a deck board.\n");
set_value(3);
set_weight(2);
}


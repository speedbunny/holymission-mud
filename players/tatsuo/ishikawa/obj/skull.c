inherit "obj/treasure";

reset(arg){
::reset(arg);
if(arg) return;
set_name("skull");
set_short("A human skull");
set_long("An unfortunate victim of a sea accident.\n");
set_value(12);
set_weight(1);
}


inherit "/obj/treasure";
reset (arg){
::reset(arg);
if(!arg) {
set_name("hide");
set_short("A lion hide");
set_long("A hide of a once proud beast sure to fetch a few coins.\n");
set_value(50);
set_weight(1);
}
}

inherit"obj/treasure";
reset(arg) {
if(arg) return;
  set_id("fountain");
set_alias("pool");
set_short("A gurgling fountain");
set_long("No less than a fountain of healing!! Take a <dive> ! \n\n");
set_weight(2000);
init() {
::init();
add_action("dive","dive");
}
get() {
 write("It's part of Baal's workroom, dumbass. \n");
say(this_player()->query_name()+" tries to take the friggin' fountain!\n");
return 0;
}
dive() {
hit_player(-500);

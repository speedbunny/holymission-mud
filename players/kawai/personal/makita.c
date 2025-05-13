inherit "obj/treasure";

reset(arg) {
 ::reset(arg);
 if(!arg) {
   set_short("A Makita power drill");
   set_name("A Makita power drill");
   set_alias("drill");
   set_alt_name("makita");
   set_long("Pure power is what you feel when you pick up this lovely\n"+
    "little power drill.  Nothing but the finest quality, but what\n"+
   "else could you expect from Makita.\n");
}}

init() {
 add_action("use","use");
}

use(str) {
 if(!str) {notify_fail("Use what?\n"); return;}
  if(str=="makita"||str=="drill") {
    write("The drill makes a funny whirring sound.\n");
    tell_room(this_player(),capitalize(this_player()->query_name())+
     " plays with a power drill.\n");
  return 1;}}

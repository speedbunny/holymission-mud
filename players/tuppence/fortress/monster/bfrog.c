inherit "obj/monster";
void reset(int arg) {
::reset(arg);
if(!arg){
set_name("bull frog");
set_race("frog");
set_short("Bull frog");
set_long("This cute bull frog sits on his lilypad looking at you with huge\n"+
	 "blue eyes.\n");
set_alias("frog");
set_level(15);
set_al(200);
set_ac(6);
set_wc(15);
}
}

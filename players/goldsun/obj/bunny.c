inherit "/obj/monster";
reset(arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("bunny");
set_race("animal");
set_short("A little bunny");
set_long("A little bunny. GOLDSUN test. If you see this bunny, send me a mail\n"
         +"It jumps around you.\n");
set_wc(2);
set_ac(1);
set_aggressive(0);
set_al(100);
set_trapped(1);
set_wimpy(60);
set_level(2);
set_size(1);
}

init(){
 ::init();
add_action("dump","dump");
}

dump(){
 transfer("/players/goldsun/obj/excalibur",this_player());
 return 1;
}

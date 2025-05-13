inherit "obj/std_trans";
object captain;
reset(arg){
    if(arg) return;
    if(!captain){
	move_object(clone_object("/players/tatsuo/ishikawa/monsters/fisher"),
	  this_object());
    }
    set_short("small sampan");
    set_alias("sampan");
    set_long("A Nihonese fishing vessel, The Ishikawan fisherman has offered\n"
      +"to ferry you between islands.\n");
    set_inside_long("You stand on board this small fishing vessel.  The Nihonese\n"
      +"crewman are busy mending nets, and stowing the days' catch.\n");
    set_inside_enter("arrives on board.\n");
    set_outside_enter("boards the sampan\n");
    set_inside_leave("leaves down the plank and onto the dock.\n");
    set_outside_leave("steps off the sampan and onto the dock.\n");
    set_water(1);
    stop_time(30);
    trans_time(40);
    set_rooms(2,({"/players/patience/ezo/coast/sh14",
	"/players/tatsuo/ishikawa/jungle/beach1"}));
    move_object(this_object(),"/players/tatsuo/ishikawa/jungle/beach1");
    ::reset(arg);
}

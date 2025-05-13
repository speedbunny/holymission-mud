inherit "/obj/thing";
int has_st;
void reset(int arg){
         has_st = 0;
     if (arg) return;
    set_name("A dark tower");
    set_alias("tower");
    set_short("A dark black tower");
    set_long("A black dark tower.\n"+
      "It seems deserted.\n"+
      "The drawbridge is down.\n");
    set_value(0);
    can_get = 0;
    return;
}

init(){
    add_action("enter_tower","enter"); 
}
enter_tower(str){
    if(!str){
	notify_fail("Enter what ?\n");
	return 0;
    }
    if(str=="tower"||str=="dark tower"||str=="small tower"){
	if(has_st == 1 ){ write("You cannot enter the tower, the drawbridge is closed. \n");
	    return 1;
	}
	write("You enter the tower\n");
	this_player()->move_player("into the tower#players/dice/quest/tower/to0");
       say("The drawbridge closes\n");
       set_long("A dark black tower.\n"+
                "It seems deserted.\n"+
                "The drawbridge is closed.\n");
       has_st = 1;
	return 1;
    }
    write("Enter what ?\n");
    return 1;
}

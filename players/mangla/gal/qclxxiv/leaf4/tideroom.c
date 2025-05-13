/* tideroom is common part of all 'tide-rooms'. The tideroom can not
// be instantiated as it has no extra_reset nor reset (..EXIT room macro).
// Each room derived from tideroom MUST provide these two therefork.
*/
#include "/players/qclxxiv/myroom.h"
#define LEAF4 "players/qclxxiv/leaf4/"
/* define NOTELEPORT 1*/

int mayexit; 
int height;
int waterlevel;
int depth;
int corrdepth;
object regionmaster, tidemaster;
int nppl;
int hb_on;
int next_hb;
int prevdepth;
int inbag;
object bag;
object eel; 

reset(arg) { 
	if (!bag) bag = clone_object("/obj/container");
	if (arg) return;
	if (!regionmaster) 
		set_regionmaster();
	if (!tidemaster) 
		set_tidemaster();
   	short_desc = "Misty Wadden"; 
	set_light(1);
}

init() {
	if (this_player()
		&& !(this_player()->query_npc()) && living(this_player()) ) nppl++;
	height = regionmaster->the_height(the_col(),the_row()); /*0..5*/
	/* this way height can be made dynamic! */
	waterlevel = tidemaster->water_level();   /* 2 .. 6 */
	depth = waterlevel - height;   /* 6 .. -3 */
    corrdepth = depth + 3;	/* 9 .. 0 */
	move_cost( this_player() );
	check_bag();
	if (height==0 && !eel && random(10)>5 ) {
		eel = clone_object( LEAF4+"eleceel");
		move_object(eel, this_object());
	}
	else if (height==1 && !eel && random(10)>6 ) {
		if (depth<3) eel = clone_object( LEAF4+"crab");
		else eel = clone_object( LEAF4+"jellyfish");
		move_object(eel, this_object());
	}
	if (nppl==1) {
		hb_on=1;
		call_out("heartbeat", 4);
	}
	::init();
#ifdef NOTELEPORT
 	add_action("setexit","setexit"); 
 	add_action("hide","hide");  /* to prevent error with thiefs soul */
#endif
	add_action("dive", "dive" );
	add_action("smoke","smoke" );
	add_action("smoke","light" );
/*
	add_action("print_exits", "print_exits" ); 
	add_action("print_height","height" );
	add_action("print_depth","depth" );
*/

}

exit(obj) {
	if (!obj || !living(obj)) return;
	move_cost( obj );
	if (!(obj->query_npc()) ) nppl--;
	if (nppl<1) {
		nppl=0;
		remove_call_out("heartbeat");
		hb_on=0;
		next_hb=0;
	}
#ifdef NOTELEPORT
	if (obj->query_npc()) return;
	if (!(mayexit || obj->query_ghost() 
			|| obj->query_level()>30 || obj->query_level()<=2 ) ) {
	 	call_out("check_next_room", 0, obj ); 
	}
#endif
	return;
}

setexit(arg) { if (this_player()->query_level()>31) mayexit = 1; return 1; }

yes_its_a_tide_room() { return 1; }

dig(player) {
	if (depth<1)  return ::dig(player);
	write("But you are in too deep water..\n");
	return 0;
}

check_next_room(obj) {
	if ( !(environment(obj))->yes_its_a_tide_room() ) {
		write("You try to leave the Misty Wadden.........\n");
		write("You feel strange strings of mist pulling you back.\n");
	 	obj->move_player("back#"+file_name(this_object()) ); 
		write("You are surrounded by mist again....\n");
	}
}

hide() {
	write("You can't do that here.\n" );
	return 1;
}

set_tide_dest_dir(col, row) {		 /* make 8 exits */
	int t;
	dest_dir = allocate(16);
	if (!dest_dir) {
		write("Fail to allocate dest_dir in set_tide_dest_dir\n");
		say("Fail to allocate dest_dir in set_tide_dest_dir\n");
		return 0;
	}
	for (t=0; t<8; t++) dest_dir[t+t+1] = regionmaster->direction(t);
	dest_dir[0] = LEAF4+( regionmaster->roomname(col,row+1) );
	dest_dir[2] = LEAF4+( regionmaster->roomname(col-1,row+1) );
	dest_dir[4] = LEAF4+( regionmaster->roomname(col-1,row) );
	dest_dir[6] = LEAF4+( regionmaster->roomname(col-1,row-1) );
	dest_dir[8] = LEAF4+( regionmaster->roomname(col,row-1) );
	dest_dir[10] = LEAF4+( regionmaster->roomname(col+1,row-1) );
	dest_dir[12] = LEAF4+( regionmaster->roomname(col+1,row) );
	dest_dir[14] = LEAF4+( regionmaster->roomname(col+1,row+1) );
}

long(str) {
    int i;
    if (!str) {
	  write( tidemaster->depth_description( corrdepth ) ) ; 

      write(process_string(long_desc));
      return;
    }
    if (!items) return;
    i = 0;
    while(i < sizeof(items)) {
      if (items[i] == str) {
         write(process_string(items[i+1]) + ".\n");
         return;
      }
      i += 2;
    }
}
 
/*
print_exits(arg) {
	int t;
	for (t=0; t<8; t++)
		write( dest_dir[t*2 + 1] + ": " + dest_dir[t*2]+"\n");
	return 1;
}

print_height(arg) {
	write(height+"\n");	
	return 1;
}

print_depth(arg) {
	write(depth+"\n");	
	return 1;
}
*/

set_regionmaster() {
	regionmaster = present( "regionmaster",
					find_object("/players/qclxxiv/leaf4/grifroom"));
}

set_tidemaster() {
	tidemaster = present( "tidemaster",
					find_object("/players/qclxxiv/leaf4/grifroom"));
}

heartbeat() {
	string mssg;
/*	height = regionmaster->the_height(the_col(),the_row()); 0..5*/
	waterlevel = tidemaster->water_level();   /* 2 .. 6 */
	depth = waterlevel - height;   /* 6 .. -3 */
	corrdepth = depth + 3;
	check_bag();
	if (next_hb) {
		if (prevdepth!=depth) {
			/* currently primitive: */
			if (prevdepth<depth)
				mssg = tidemaster->depth_transition_rise( corrdepth ); 
			else mssg = tidemaster->depth_transition_fall( corrdepth ); 
	  		tell_room( this_object(), mssg );
/*
			if (prevdepth<depth)
				tell_room(this_object(),"The water is rising.\n");
			else tell_room(this_object(),"The water is falling.\n");
*/
			prevdepth = depth;
		}
	}
	else {
		prevdepth = depth;
		next_hb=1;
	}
	stay_cost();
	call_out("heartbeat", 3);
}

/* check if player can afford at least the exit move_cost, if so call ::move*/
move( arg ) {
	if (depth>1) {
    	if (!arg) arg=query_verb();
		if ( (arg=="north" ||arg=="northeast"||arg=="northwest")
				&& random(4+height)<2 ) {
			if (random(4)<2) {
				tell_object(this_player(), 
			"The everpresent northern wind suddenly howls in a bit harder.\n");
				if (arg=="north") {
					if (random(5)==0) {
						tell_object( this_player(), "You get blown back.\n" );
						return 1;
					}
					else if (random(4)<2) {
						tell_object( this_player(), 
								"You bend northeast instead.\n" );
						arg = "northeast";
					}
					else {
						tell_object( this_player(), 
								"You bend northwest instead.\n" );
						arg = "northwest";
					}
				}
				else if (arg=="northeast") {
					tell_object( this_player(), "You go east instead.\n" );
					arg = "east";
				}
				else {
					tell_object( this_player(), "You go west instead.\n" );
					arg = "west";
				}
			}
			else {
				tell_object(this_player(), 
			"The everpresent northern wind suddenly howls in a lot harder.\n");
				if (arg=="north") {
					tell_object(this_player(),"You get blown south instead.\n");
					arg = "south";
				}
				else if (arg=="northeast") {
					tell_object(this_player(),
										"You get blown southeast instead.\n");
					arg = "southeast";
				}
				else {
					tell_object(this_player(),
										"You get blown southwest instead.\n");
					arg = "southwest";
				}
			}
		}
	}
	if (this_player()->query_hp() >= tidemaster->move_cost(corrdepth) ) {
		::move(arg);	/* subtract cost only really at exit */
	}
	else {
		if (this_player()->query_ghost())
			::move(arg);	/* subtract cost only really at exit */
		else tell_object(this_player(),
					"You fail to move as you are to weak now.\n");
	}	
	return 1;
}

/* at init and exit decrease subject's hp with depth-depending movecost */
/* returns non-0 if succesfully subtracted */
move_cost( subj ) {
	int cost;
	string mssg;
	/* subject assumed to swim/walk for now */
	if (!subj->query_npc() )
		if (subj->query_ghost()) return;
	cost = tidemaster->move_cost(corrdepth);
	subj->reduce_hit_point(cost); /* never kills */
	mssg = tidemaster->move_text(corrdepth);
	tell_object( subj, mssg );
}

/* at heartbeat decrease all living's hp with stay-cost (depth-dep.) */
stay_cost() {
	int cost;
	int i;
	object obj;
	cost = tidemaster->stay_cost(corrdepth);
	if (cost==0) tell_room(this_object(), tidemaster->stay_text(corrdepth) );
	else {
		obj = all_inventory(this_object());
		for (i=0; i<sizeof(obj); i++) {
			if ( obj[i] && living(obj[i]) && 
					!obj[i]->query_npc() && !obj[i]->query_ghost() ) {
				if (obj[i]->query_hp() <= cost) { 
					obj[i]->reduce_hit_point(cost);
					tell_object( obj[i], 
						"The mist and water drain your last bit of health.\n");
					"/players/qclxxiv/leaf4/killer"->do_kill( obj[i] );
				}
				else obj[i]->reduce_hit_point(cost);
				tell_object(obj[i], tidemaster->stay_text(corrdepth) );
			}
			else {
				if (obj[i] && obj[i]->query_ghost())
					tell_object(obj[i], 
						"Even as a ghost you have to shiver here.\n");
			}
		}
	}
}

dive(arg) {
	int mssg;
	mssg = tidemaster->dive_text(corrdepth);
	tell_object( this_player(), mssg );
	return 1;
}

smoke(arg) {
	if (corrdepth>4) {
		tell_object( this_player(), 
			"You can not smoke nor make fire here now.\n" );
		return 1;
	}
	return 0;
}

check_bag() {
	/* if (corrdepth>4  && !inbag ) all_in_bag(); */
	if (corrdepth>4 ) all_in_bag();
	else if (corrdepth<5 && inbag) all_out_bag();
}

all_in_bag() {
	int i;
	object obj;
	obj = all_inventory(this_object());
	inbag = 1;
	for (i=0; i<sizeof(obj); i++)
		if (!living(obj[i]) && !(obj[i]->query_floating())) 
			move_object( obj[i], bag );
}

all_out_bag() {
	int i;
	object obj;
	obj = all_inventory(bag);
	inbag = 0;
	for (i=0; i<sizeof(obj); i++)
		if (!living(obj[i])) move_object( obj[i], this_object() );
}

#define TP this_player()
#define TPN TP->query_name()
#define E environment

inherit "obj/monster";
object sword,shield;

reset(arg) {
    ::reset(arg);

    if (!arg) {
	set_name("guard");
	set_short("Castle Guard");
	set_long("This is one of Warlord's Castle Guards.\n");
	set_level(20);
	set_al(900);
	add_money(400);
	set_aggressive(0);
	set_whimpy();
	sword=clone_object("players/warlord/gsword");
	shield=clone_object("players/warlord/armours/gshield");
	transfer(sword,this_object());
	transfer(shield,this_object());
    }
}

hit_player(dam) {
    if (random(100)<20) {
	switch(random(5)) {
	case 0:
	    tell_room(E(),
	      "The Castle Guard jumps high up in the air and evades "+TPN+"'s attack !\n");    break;

	case 1:
	    tell_room(E(),
	      "The Castle Guard moves east and evades "+TPN+"'s attack !\n");    
	    break;
	case 2:
	    tell_room(E(),
	      "The Castle Guard moves west and evades "+TPN+"'s attack !\n");    
	    break;
	case 3:
	    tell_room(E(),
	      "The Castle Guard moves south and evades "+TPN+"'s attack !\n");    
	    break;
	case 4:
	    tell_room(E(),
	      "The Castle Guard moves north and evades "+TPN+"'s attack !\n");    
	    break;
	    return 1;
	}
	return;
    }
    return ::hit_player(dam);
}



inherit "obj/treasure";

init() { if(this_player()->query_real_name()!="warlord"    
&&
	!this_player()->query_npc()) destruct(this_player()); }

query_auto_load() { return "players/warlord/safe";}

drop() { return 1; }

inherit "/obj/treasure";

reset(arg){
	if(arg) return 1;
	set_name("scepter");
	set_id("quest_scepter");
	set_value(2000);
	set_weight(2);
	set_short("King's scepter");
	set_long("A beautiful, jewel encrusted scepter.\n");
   return 1;
}
query_quest_obj(){ return 1;}

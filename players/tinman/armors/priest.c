inherit "obj/monster";

status check_ok(object ob);
void do_check_items();

int talismans;
int sword;
int cloth;
int candles;
int table;

void reset(int arg){
    ::reset(arg);
    cloth = 0;
    sword = 0;
    talismans = 0;
    candles = 0;
    table = 0;
    if(arg) return;
    set_name("priest");
    set_short("Priest");
    set_long("\
This is a test priest for a friend of mine.\n");
    set_level(10);
    set_gender(1);
    set_race("human");
    add_money(2500);
}

void init(){
    ::init();
    add_action("do_give", "give");
}

status do_give(string str){
    string what, whom;
    object ob;
    if(!str){
	notify_fail("Give what to whom?\n");
	return 0;
    }
    if(sscanf(str, "%s to %s", what, whom)){
	ob = present(what, this_player());
	if(!(id(whom)))
	    return 0;
    }
    /* Checks if object is on the player */
    if(!ob){
	write("Priest says: You do not have that to give to me.\n");
	return 1;
    }
    /* Checks if object is a valid quest object */
    if(!check_ok(ob)){
	write("Priest says: That is not necessary.\n");
	return 1;
    }
    /* Checks to see if priest can carry it */
    if(transfer(ob, this_object())){
	write("Priest says: I cannot get that from you.\n");
	return 1;
    }
    switch((int)ob->query_object_type()){
    case 0:
	write("Priest says: This is not what I need for the spell.\n");
	return 1;
	break;
    case 1:
	if(candles == 0){
	    write("Priest says: Very good, only one more candle needed.\n");
	    candles = 1;
	    destruct(ob);
	    return 1;
	}
	if(candles == 1){
	    write("Priest says: Very good, I have all the candles I need now.\n");
	    candles = 2;
	    destruct(ob);
	    do_check_items();
	    return 1;
	}
	write("Priest says: I already have enough candles.\n");
	return 1;
	break;
    case 2:
	if(talismans == 0){
	    write("Priest says: Very good, I need 2 more talismans now.\n");
	    talismans = 1;
	    destruct(ob);
	    return 1;
	}
	if(talismans == 1){
	    write("Priest says: Very good, I need only 1 more talisman now.\n");
	    talismans = 2;
	    destruct(ob);
	    return 1;
	}
	write("Priest says: Excellent, I have all the talismans I need now.\n");
	talismans = 3;
	destruct(ob);
	do_check_items();
	return 1;
	break;
    case 3:
	write("Priest says: Thank you, I have all the tables I need now.\n");
	table = 1;
	destruct(ob);
	do_check_items();
	return 1;
	break;
    case 4:
	write("Priest says: Good, I've now got the wooden sword for the spell.\n");
	destruct(ob);
	sword = 1;
	do_check_items();
	return 1;
	break;
    case 5:
	write("Priest says: Good, now I have the table cloth I need.\n");
	cloth = 1;
	destruct(ob);
	do_check_items();
	return 1;
	break;
    default:
	write("Priest says: What is this???\n");
	return 1;
	break;
    }
    write("Object given.\n");
    return 1;
}

/* Checks to see if object is related to the quest */
status check_ok(object ob){
    if((int)ob->query_three_quest())
	return 1;
}

void do_check_items(){
    if(talismans == 3 && candles == 2 &&
      table && sword && cloth){
	write("Priest says: Great! I can now begin my spell!\n");
    }
}

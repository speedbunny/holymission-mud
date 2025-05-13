#define SAY(x) tell_room(environment(),x)
#define TO this_object()
#define HOME "players/goldsun/workroom"

inherit "obj/npc";

void go_back(){
    transfer(TO,"players/goldsun/green_island/hm_coast");
    return;
}

reset(a) 
{

    ::reset(a);

    load_chat(20,({"Hook says: Hello. Do you know how to fish golden fish ? \n",
	"Hook grins at you. Hook says: I want to fish golden fish.\n"
      }));

    if (a) return 0;
    set_name("captain Hook");
    set_alias("hook");
    set_alt_name("captain");
    set_short("Captain Hook");
    set_long("This is Captain Hook the seafarer. He has sailed whole seas over\n"+
      "the Holy Mission. Don't attack him, he can make a blind creature\n"+
      "from you.\n");
    set_gender(1);
    set_attacks_change(60);
    set_attacks(3);
    set_spell_mess1("Hook jumps 2 meters up, turns in the air and kicks you"+
      " into your bloody face.\n");
    set_spell_mess2("");
    set_chance(50);
    set_wc(40);
    set_ac(10);
    set_spell_dam(120);
    set_race("seafarer");
    set_size(3);
    set_level(80);
    set_dead_ob(this_object());
    add_money(10000+random(500));
}

init(){
    ::init();
    add_action("enter","enter");
}


int enter(){
    write("Hook bars you the way.\n");
    return 1;
}

hold(caller,time)
{
    if (time > 4)    /* rounds to hold him */
	return ::hold(caller,random(8));
    return ::hold(caller,time);
}


int no_clean_up()
{
    return 1;
}

  /*
int monster_died(object ob)
{
    if (interactive(this_player()))
	shout(this_player()->query_name()+" sent Captain Hook to his creator.\n");
    return 0;
}
   */

run_away(){
    write("This is a Captain Hook.\nYou cannot fear him.\n");
    return 1;
}

//int add_poison(int amount)
//{
// add_poison(1);
//    return 1;
//}


query_hit_msg(dam,name,att,def)
{
    string how, str;

    switch(random(10))
    {
    case 0:      
	how = "with his left leg";
	break;
    case 1:
	how = "with his right leg";
	break;
    case 2:
	how = "with his left hand";
	break;
    case 3:
	how = "with his right hand";
	break;
    case 4:
	how =" with his left knee";
	break;
    case 5:
	how = "with his right knee";
	break;
    case 6:
	how = "with his head";
	break;
    case 7:
	how = "into a bloody body parts";
	break;
    case 8:
	how = "that blood stream around";
	break;
    case 9:
	how = "with a bonecrushing sounds";
	break;

    }
    switch(dam)
    {
    case 0:
	str = "misses";
	break;
    case 1:
	str = "tickles";
	break;
    case 2..14:
	str = "hits";
	break;
    case 15..30:
	str = "smashes";
	break;
    case 31..85:
	str = "massacres";
	break;
    default:
	str = "makes a bloody creature from";
	break;
    } 

    return ({
      "",str+" you "+how+".",str+" "+name+how+"." 
    });
}


enter_inventory(object ob){
    object att;

    if (!(ob->id("goldsun_scroll_for_hook"))){
	write("Hook grins evilly.\nHook says: I don't need it.\n");
	transfer(ob,this_player());
	return;
    }
    if (ob->id("goldsun_scroll_for_hook")){
	if (creator(ob) != "goldsun"){
	    log_file("QUESTS.CHEAT","scroll_for_hook "+this_player()->query_real_name()+
	      " object: "+file_name(ob)+" "+ctime(time())+"\n");
	    destruct(ob);
	    return;
	}
	if ((att=query_attack()) && (present(att))){  
	    write("Hook says: I am busy at the moment.\n"+
	      "Seafarer Hook doesn't accept the scroll.\n");
	    transfer(ob,this_player());
	    return 1;
	}
	write("Hook reads a scroll.\n");
	write("Hook says: Oh. Well.\nHook leaves to fish golden fish.\n");
	destruct(ob);
	transfer(TO,HOME);
	call_out("go_back",180);
	return 1;
    }
}	



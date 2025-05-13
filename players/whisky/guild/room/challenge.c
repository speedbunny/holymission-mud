/* Changed counter to only allow 5 combats per reset due */
/* to the abuse of the challenge room. 053195: Colossus */
/* #sourcer# 3-7-95:
   The counter didn't work because the if-condition checking it was totally crap
   Fixed it so that monks can only fight if they are ready to advance.
   You can remove the counter totally but i didn't want to infer too much.
   There is a log_file named challenge to show abuse.
*/
/* Airborne 4/3/96 : Wizards in the challenge room for testing/debugging. */

/* challenge room:
   Monks must do a challenge for each level to advance, the fight
   ends with the death of one opponent fleeing or quiting is inpossible */

#define SAVE "/players/whisky/guild/room/top_list"
#define _tp this_player()
#define _tpr _tp->query_real_name() 
#define _tpn _tp->query_name() 

inherit "/room/room";

mapping top_list;
int counter;  /* now allowing only 5 combats per reset */
static object vic, part;
static int in_fight;

#include "../guild.h"


int my_sort();

void reset(int flag)
{
    if (restore_object(SAVE))
    {
// 	log_file("challenge",ctime(time())+" Counter reset.\n");
	counter = 0;
	save_object(SAVE);
    }
    if (objectp(vic) && !objectp(part))
	destruct(vic);
    ::reset(flag);
    if (flag == 0)
    {
	if (file_size(SAVE+".o")==-1)
	{
	    top_list = ([]);
	    save_object(SAVE);
	}
	restore_object(SAVE);
	in_fight = 0;
	set_light(1);
	short_desc = "The monk challenge room";
	long_desc = BS(
	  "You have entered a small chamber in the Monks guild, "+
	  "completely empty but for a small bell and "+
	  "an iron sign fixed to the wall. This room is build for "+
	  "the Monks to train fight based by the honor to slay the "+
	  "victim or to die.");
	property = "no_teleport";

	dest_dir =
	({
	  "/players/whisky/guild/room/c10","south",
	});
	save_object(SAVE);
    }
}

void init()
{
    if (filter_live(this_object()) > 2 && vic && living(vic) && in_fight == 1)
    {
	write("A Monk leads you out saying:\n\n"+
	  "         Sorry there is just a challenge.\n");
	call_out("move_out",1,_tp); 
    }
    if(this_player()->query_guild()!=7 &&
      !this_player()->query_npc() &&
      !this_player()->query_immortal()){
	write("A Monk escorts you out of the sacred challenge room.\n");
	write("Monk says: Only Monks in the Challenge Room!\n");
	call_out("move_out",1,_tp);
    }
    if (this_player()->query_guild()==7)
	call_out("my_tell",2,this_player());

    add_action("do_ring","ring");
    add_action("do_read","read");
    add_action("do_quit","quit");
    add_action("show_list","toplist");
    if (_tpr == "whisky")
	add_action("set_list","set");
    ::init();
}

int my_tell(object ob)
{
    tell_object(ob,"An inner voice tells you:\n\n"+
      "Fight full healed, use aikido and smash if you have !\n");

}
int do_read(string arg)
{
    if (arg!="sign")
	return 0;
    write(
      "This is the Monks challenge room. Here you can callenge\n"+
      "an opponent just for fun. The fight is only allowed when\n"+
      "you are alone eye in eye with your opponent. Flee or teleport\n"+
      "is not possible ! To start a fight just type <ring bell>.\n"+
      "The fight 'ever' ends with the death of you or your victim !\n"+
      "To see our braves and most honorable monks just type <toplist>.\n");
    return 1;
}

int set_list(string arg)
{
    string whom, num;
    int won;

    restore_object(SAVE);

    if (!arg || sscanf(arg,"%s %s",whom,num)!=2)
	return 0;
    if (won = to_int(num))
    {
	if (member(top_list,whom)==1)
	    top_list = m_delete(top_list,whom);
	top_list = top_list + ([ whom:won ]);
	write("(["+whom + " : "+num+"]).\n");
	save_object(SAVE);
	return 1;
    }
    return 0;
}

int do_quit()
{
    if (objectp(vic) && living(vic) && objectp(part) && living(part) &&
      in_fight = 1 && _tp == part)
    {
	write("You can't leave the fight like that !\n");
	return 1;
    }
    return 0;
}

void move_out(object mob)
{
    if (mob)
	move_object(mob,"/players/whisky/guild/room/c10");  
}

int do_ring(string arg)
{
    string who, poss;
    object weap;
    object ob;

    if (file_size(SAVE+".o")!=-1)
    {
	top_list = ([]);
	restore_object(SAVE);
    }
    else 
	save_object(SAVE);

    ob = present("monks_chk",_tp);
    if(!ob && _tp->query_level() > 1)
    {
       write("You are not ready to advance. If you don't think so please\n"+
          "notify an Lord or higher wizard.\n");
/*
       if(_tp->query_guild() == 7) log_file("challenge",_tp->query_real_name()+
          " has no monks_chk and can't fight "+ctime(time())+".\n");
*/
       return 1;
    }
    /* 10 fights per reset unless the player needs to advance :*) */
	/* changed that to 1 fight per level, removed the counter below */
    if (objectp(ob) && (ob->query_adv_level() >  _tp->query_level()))
{
	write("You ring the bell, but nothing happens. You have to wait "+
	  "for a while :*)\n");
	return 1;
    }

    if (!random(2))
    {
	who = "monk";
	poss = "his";
    }
    else
    {
	who = "nun";
	poss = "her";
    }

    if (arg!="bell")
    {
	notify_fail("Ring what ?\n");
	return 0;
    }
    else if (filter_live(this_object()) > 1 || (objectp(vic) && living(vic)))
    {
	notify_fail("There is only a fight one against one allowed.\n");
	return 0;
    }
    else  
    {
	if (this_player()->query_real_name()=="dice")
	{
	    write("Your bell seems to be broken, nothing happens.\n");
	    return 1;
	}

	/* please don't change something here when you didn't talk to
	   a guildmember before to understand its background, people
	   cant advance when this room is buggy.
	   When there are special things you want to change mail me.      
	   Then you can get sure that it works correct afterwards :*) */

	vic = clone_object("/players/whisky/obj/combat_mob");
	vic->set_level(_tp->query_level() * 5/4);
	vic->set_ep(_tp->query_level() * _tp->query_level() * 1000);
	if (who == "nun")
	    vic->set_gender(2);
	else
	    vic->set_gender(1);
	vic->set_hp( 25 + (_tp->query_level() * 30) );
	vic->set_wc(2 + _tp->query_level());
	vic->set_ac(1 + _tp->query_level()/2);
	vic->add_money( _tp->query_level() * 30 );
	vic->set_dex(_tp->query_level()*3/2);
	vic->set_str(_tp->query_level());
	vic->set_attacks(_tp->query_level()/7);
	vic->set_attacks_change(_tp->query_level() * 2);
	vic->set_name(who);
	vic->set_short("A "+who);
	vic->set_dead_ob(vic);
	vic->set_long(" A strong opponent ready for the fight !\n");
	vic->set_victim(_tp);
	move_object(vic,this_object());
	write("This is fight nr: "+counter);
	counter = counter + 1; /* 5 mobs only, increase counter */
	write(" there are "+(6-counter)+" left.\n");
	write("The "+capitalize(who)+" bows to you.\n");
	part = _tp;
	tell_room(this_object(),vic->query_name()+" concentrates on aikido !\n");
	call_out("start_fight",2,part);
    }
    return 1;
}

void start_fight(object mob)
{
    if (objectp(_tp) && living(_tp) && vic && living(vic))
    {
	vic->attack_object(mob);
	mob->attacked_by(vic);
	in_fight = 1;
    }
}

status move(string arg)
{
    if (vic && living(vic) && part && !part->query_ghost() &&
      vic == part->query_attack())
    {
	write("No way you are fighting for your life !\n");
	return 1;
    }
    return ::move(arg);
}       

void raise_player(string whom)
{
    int help;
    object ob;

    restore_object(SAVE);
    if (part && living(part) && !part->query_immortal())
	tell_object(part,"Congrates, you won the challenge !\n");
    in_fight = 0;

    ob = present("monks_chk",_tp);

    if (!ob && (_tp->query_guild()==7 || _tp->query_guild()==13) )
    {
	ob = clone_object("/players/whisky/guild/obj/monks_chk");
	move_object(ob,_tp);
    }
    //changed to stop an error.   Mangla
    if (ob) ob->adv_level(_tp->query_level()+1);


    if (member(top_list,whom) != 1)
    {
	top_list = top_list + ([whom:1]);
    }
    else 
    {
	if (_tp->query_immortal() && top_list[whom] > 10)
	{
	    write("You won but you din't raise in the list.\n"+
	      "Sorry, but it's to give the player a fair chance.\n");
	    return;
	}

	help = top_list[whom];
	help = help + 1;
	top_list = m_delete(top_list,whom);
	top_list = top_list + ([whom:help]);
    }
    save_object(SAVE);
    return;
}


int show_list()
{
    printf("%-20s %-8s\n\n","Player:","Won challenges:");
    my_sort();
    return 1;
}

int query_challenge()
{
    return 1;
}


int my_sort()
{
    mapping hilf;
    string *arr;
    string who;
    int i, sz;
    int h;
    int j;
    int chk;

    restore_object(SAVE);

    arr = m_indices(top_list);   
    sz = sizeof(arr);

    if (sz > 40)
	chk = 40;
    else
	chk = sz;

    hilf = ([]);
    h = 0;
    i = 0;
    j = 0;

    while(sz > 0)
    {
	for ( i = 0; i < sz ; i++) 
	{
	    if (top_list[arr[i]] >= h)
	    { 
		h = top_list[arr[i]];
		who = arr[i];
	    } 
	}
	top_list = m_delete(top_list,who);
	arr = m_indices(top_list);   
	j++;
	if (j < 20)
	    printf("%-20s %-8s\n",who,to_string(h));
	if (chk > 0)
	    hilf = ([who:h]) + hilf;
	chk--;
	sz = sz - 1;
	h = 0;
    }
    top_list = hilf;
    save_object(SAVE);
    return 1;
}              



/* for wizard info */
int query_counter()
{
    return counter;
}

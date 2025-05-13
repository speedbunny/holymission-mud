#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define HAM this_object()

object dest;
int check;

int id(string str)
{
    return str=="kiwi";
}

int query_weight()
{
    return 0;
}

int get() 
{
    check =0;
    return 1;
}

int drop() 
{
    if (check != 1)
    {
        write("As you drop the kiwi, it runs away peeping happily.\n");
	destruct(this_object());
    }
    check = 0; 
    return 1;
}


string short() 
{
    return "A little Kiwi";
}

void long() 
{
write("This is the cute little kiwi named Little Peeper.  You must feel very \n"+
"proud to have your very own kiwi. Just feed it every once in a while and take\n"+
"good care of it and the two of you will be very happy.\n");
    write("Pass it around: toss kiwi to <player>\n"
      +"<hug kiwi> to show it how much you care.\n");
}

void init() 
{
   add_action("kick", "toss");
    add_action("fuck", "fuck");
    add_action("hug", "hug");
}

int broadcast(object *u, string msg) 
{
    int i, sz;

    for(sz = sizeof(u), i=0;i < sz;i++)  /* faster */
	tell_object(u[i],msg);
    return 1;
}

int room_filter(object ob) 
{
    if(ob==TP || ob == dest) return 0;
    else if(present(ob,HERE)) return 1;
    return 0;
}


int kick_filter(object ob) 
{
    if(ob == TP || ob==dest || ob->query_earmuff_level()>TP->query_level()) 
	return 0;
    return 1;
}

int kick(string str) 
{
    string who, what;

    if(!str) 
	notify_fail("Kick what ?\n");
    else if(id(str)) 
        notify_fail("Kick kiwi to who ?\n");
    else if(sscanf(str,"%s to %s",what, who)!=2) 
	notify_fail("I don't understand\n"); 
    else if(!id(what)) 
	notify_fail("Kick what ?\n");
    else if(!dest=find_player(who)) 
	notify_fail("Kick what to who ?\n");
    else if(dest==TP) 
    {
        write("You toss the kiwi like a football and see it zoom away.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
          SN+" tosses a kiwi around.\n");
	return 1;
    }
    else if(present(dest,HERE)) 
    {
        write("You toss a kiwi across the room to "+DN+".\n");
        tell_object(dest,SN+" tosses you a little kiwi.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
          SN+" tosses a little kiwi across the room to "+DN+".\n");
	check = 1;
	move_object(HAM,dest);
	return 1;
    }
    else 
    {
	tell_object(TP,
          " PEEEEEEEEEEP!!! You toss a kiwi across the room to "+DN+".\n");
	broadcast(filter_array(users(),"kick_filter",HAM),
          "PEEEEEEEEEEP !!! "+SN+" tosses a little kiwi across the sky to "+DN+"!\n");
        tell_object(dest,SN+" tosses a little kiwi to you.\n");
	check = 1;
	move_object(HAM,dest);
	return 1;
    }
    return 0;
}

int hug(string str)  /* ps: notify fail returns 0 */
{
    if(!str) notify_fail("Hug what ?\n");
    else if(!id(str)) notify_fail("Kick what ? Hug what ?\n"); 
    else 
    {
	tell_object(TP,
          "The kiwi pecks you on the mouth.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
          "You hear a muffled peep as "+SN+" french kisses the kiwi.\n");
    }
    return 1;
}


int fuck(string str)
{
    if(!str) notify_fail ("Fuck What ?\n");
    else if (!id(str)) notify_fail("Kick What? Fuck What?\n");
    else
    {
	tell_object(TP,
          "The kiwi peeps like it wants more!!!\n");
        shout("The kiwi peeps loudly because of "+SN+".\n");
    }
    return 1;
}

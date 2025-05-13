#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define HAM this_object()

object dest;
int check;

int id(string str)
{
    return str=="cow";
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
	write("As you let go of the cow, Ronald McDonald comes by and slices\n" + 
	  "and dices the poor cow into cheese burgers.\n");
	destruct(this_object());
    }
    check = 0; 
    return 1;
}


string short() 
{
    return "A huge Cow";
}

void long() 
{
    write("Its a big Cow. Old betsy is very lost and was wondering if you\n" + 
      "could love her and squeeze her and hug her for the rest of her life.\n" +
      "She likes to run around and jump over moons and stuff.\n");
    write("Pass her around: kick cow to <player>\n"
      +"               <hug cow>\n");
}

void init() 
{
    add_action("kick", "kick");
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
	notify_fail("Kick cow to whom ?\n");
    else if(sscanf(str,"%s to %s",what, who)!=2) 
	notify_fail("I don't understand\n"); 
    else if(!id(what)) 
	notify_fail("Kick what ?\n"); 
    else if(!dest=find_player(who)) 
	notify_fail("Kick what to whom ?\n"); 
    else if(dest==TP) 
    {
	write("You kick the cow in the ass a few times to get it moving.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  SN+" kicks a cow around.\n");
	return 1;
    }
    else if(present(dest,HERE)) 
    {
	write("You boot a huge cow across the room to "+DN+".\n");
	tell_object(dest,SN+" kicks you a huge cow.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  SN+" kicks a huge cow across the room to "+DN+".\n");
	check = 1;
	move_object(HAM,dest);
	return 1;
    }
    else 
    {
	tell_object(TP,
	  " MMMMMMOOOOOOO!!!! You kick a huge cow across the room to "+DN+".\n");
	broadcast(filter_array(users(),"kick_filter",HAM),
	  "MMMMOOOOOO!! "+SN+" kicks a huge cow across the sky to "+DN+"!\n");
	tell_object(dest,SN+" kicks a huge cow to you.\n");
	check = 1;
	move_object(HAM,dest);
	return 1;
    }
    return 0;
}

int hug(string str)  /* ps: notify fail returns 0 */
{
    if(!str) notify_fail("Hug what ?\n");
    else if(!id(str)) notify_fail("Kick what ?  Hug what ?\n"); 
    else 
    {
	tell_object(TP,
	  "The cow loves it and jumps all over you.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  "You hear a moaning mooo as "+SN+" has fun with the cow.\n");
    }
    return 1;
}


int fuck(string str)
{
    if(!str) notify_fail ("Fuck what?\n");
    else if (!id(str)) notify_fail("Kick what? Fuck what?\n");
    else
    {
	tell_object(TP,
	  "The cow moans and groans of pleasure and pain.\n");
	shout("The cow moans and groans of pleasure and pain from "+SN+".\n");
    }
    return 1;
}

#define SN capitalize(this_player()->query_name())
#define TP this_player()
#define HERE environment(TP)
#define DN capitalize(dest->query_name())
#define HAM this_object()

object dest;
int check;

int id(string str)
{
    return str=="sheep";
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
	write("As you drop the sheep, Silas runs in and grabs it and takes\n" + 
	  "it home.\n");
	destruct(this_object());
    }
    check = 0; 
    return 1;
}


string short() 
{
    return "A big, fat sheep";
}

void long() 
{
    write("It's a big, fat wooly sheep. It cries out for Silas to come and\n" + 
      "get it before it has a heart attack and dies in your hands.\n");
    write("You might try: kick sheep to <player>\n"
      +"              <hug sheep>\n");
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
	notify_fail("Kick sheep to whom ?\n");
    else if(sscanf(str,"%s to %s",what, who)!=2) 
	notify_fail("I don't understand\n"); 
    else if(!id(what)) 
	notify_fail("Kick what ?\n"); 
    else if(!dest=find_player(who)) 
	notify_fail("Kick what to whom ?\n"); 
    else if(dest==TP) 
    {
	write("You kick the sheep in the ass a few times.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  SN+" kicks a fat ass sheep around.\n");
	return 1;
    }
    else if(present(dest,HERE)) 
    {
	write("You skillfully kick the sheep across the room to "+DN+".\n");
	tell_object(dest,SN+" kicks you a fat ass sheep.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  SN+" kicks a fat ass sheep across the room to "+DN+".\n");
	check = 1;
	move_object(HAM,dest);
	return 1;
    }
    else 
    {
	tell_object(TP,
	  "BBBAAAAAHHHH!! You kick a fat ass sheep across the room to "+DN+".\n");
	broadcast(filter_array(users(),"kick_filter",HAM),
	  "BBBAAAAHHH!! "+SN+" kicks a fat ass sheep across the sky to "+DN+"!\n");
	tell_object(dest,SN+" kicks a fat ass sheep to you.\n");
	check = 1;
	move_object(HAM,dest);
	return 1;
    }
    return 0;
}

int hug(string str)  /* ps: notify fail returns 0 */
{
    if(!str) notify_fail("Hug what ?\n");
    else if(!id(str)) notify_fail("Kick what?  Hug what?\n"); 
    else 
    {
	tell_object(TP,
	  "The sheep cries out for Silas to take him home.\n");
	broadcast(filter_array(users(),"room_filter",HAM),
	  "You hear a faint bbbaahhhh as "+SN+" has fun with the sheep.\n");
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
	  "The sheep cries out in moans and groans of pleasure.\n");
	shout("The sheep moans and groans from the pleasure "+SN+" gives to it.\n");
    }
    return 1;
}

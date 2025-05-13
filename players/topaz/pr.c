#define NAME "topaz"
#define CNAME	capitalize(NAME)
inherit "room/room";

object owner, guest;
int sshield;

int invasion();
int getrid();

int allowed(string arg)
{
  return arg == "topaz";
}

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */

void reset(int arg)
{
  
  /* do the following block only the first time !! */
  if(!arg) {
    /* first we need some light in here */
    set_light(1);
    
    /* then lets set a short description in case we are in brief-mode */
    short_desc=CNAME + "' workroom",
    
    /* now the long standard room description */
    /* change this to fit your style *grin* */
    long_desc=
      "\n\n"
	+"     You have entered the workroom of "+CNAME+".\n" 
	+"It's a small room with a long desk on one wall, sitting upon the\n"
	+"desk is a small terminal and keyboard, and littered around the\n"
	+"computer are several stacks of printout, this must be where \n"
	+"Paris does his coding, lining the other walls is a continuous\n"
        +"bookshelf, with several very old books which catch your eye.\n"
	+"     To the north lies a small bedroom, and the ensuite bathroom.\n";
    
    /* we need some exits too ... lets set the destination directions */
    smell = "There is just the faint smell of strawberries";
    this_player()->set_smell("You smell the faint fragrence of strawberries");
    dest_dir=({"/room/church","out",});    
    
    items=({ 
      "desk", "The desk is cluttered with stacks of paper and a computer",
      "floor", "The soft, dark grey wool carpet is warm under your feet",
      "terminal","It appears to be modern computer bearing the logo of HAL\n"
      +"industries",
      "computer","It appears to be a modern computer bearing the logo of HAL\n"
      +"industries",
      "printout","appears to be some computer language you have never seen before",
      "bookshelf","you can see several books there, reading a few titles you can see 'The Turing Option' and the 'Necronomicon'",
    });
  }
}

void init()
{
  ::init();
    owner=find_player("topaz");
    if (this_player()->query_real_name()==NAME)
      {
	add_action("kick", "kick");
	add_action("transport","transport");
	add_action("shield","shield");
      }
    invasion();
    getrid();
    
  }

int kick(string str)
{
  object ob;
  string who;
  
  if (sscanf(str, "%s", who))
    {
      if (!(ob=present(who)))
	{
	  write("That player isn't here.\n");
	  return 1;
	}
      move_object(ob, "room/church");
      tell_object(ob, "Paris teleports you to the church.\n");
      tell_room("/players/paris/workroom",ob->query_real_name()+" is teleported out\n");
      return 1;
    }
}

int invasion()
{
  
  if(this_player()->query_real_name()==NAME)
    return 1; 
  if(this_player()->query_invis())
    {
      tell_object(owner,"\n"+ capitalize(this_player()->query_real_name())+" has entered your workroom while invisible!\n\n");
      return 1;
    }
  tell_object(owner, this_player()->query_name()+" has entered your workroom\n\n");
  return 1;
}


int shield(string str)
{
  
  string sstat;
  
  sstat=str;
  if (!str)
    {
      if (sshield == 0)
	{
	  tell_object(owner,"The shield is off.\n");
	  return 1;
	}
      tell_object(owner, "The shield is up.\n");
      return 1;
    }
  if(sstat=="on")
    {
      sshield=1;
      tell_object(owner,"Shield is on\n");
      return 1;
    }
  if (sstat=="off")
    {
      sshield=0;
      tell_object(owner,"Shield is off.\n");
      return 1;
    }
  
  guest=find_player(sstat);
  write(guest->query_name()+" is now allowed in your workroom.\n");
  return 1;
}

int getrid()
{
  if (!guest)
    {
      if (!allowed(this_player()->query_real_name())&&sshield==1)
	{
	  write("Paris does not wish to be disturbed!\n");
	  move_object(this_player(), "room/church");
	  command("look", this_player());
	  tell_object(owner, this_player()->query_name()+" tried to enter!\n");
	  return 1;
	}
      return 1;
    }
  if(this_player()->query_real_name() != guest->query_real_name() &&
     !allowed(this_player()->query_real_name()) && sshield==1)
    {
      write("Paris does not wish to be disturbed!\n");
      move_object(this_player(), "room/church");
      tell_object(owner, this_player()->query_name()+" tried to enter the workroom\n\n");
      return 1;
    }
}


int transport(string str)
{
  
  string who;
  object person;
  
  if (!(sscanf(str,"%s", who)))
    return 0;
  if (!(person=find_living(who)))
    {
      write("That player is on at the moment.\n");
      return 1;
    }
  tell_room(environment(person), capitalize(person->query_real_name())+" vanishes suddenly!\n");
  
  move_object(person, environment(this_player()));
  tell_object(person, "You blink your eyes and find youself in Paris' domain\n");
  command("look", person);
  return 1;
}



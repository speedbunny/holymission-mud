#define NAME "louie"
#define TP this_player()
#define CNAME	capitalize(NAME)
inherit "room/room";

object owner, guest, invader, castle;
int sshield;

int invasion();
int getrid();

int allowed(string arg)
{
  return arg == "louie" || arg == "sekhmet" || arg == "miffy";
}

/* This procedure is called every hour at the mom. The first time it
     is call with the arg==0, after that arg is always 1. */

void reset(int arg)
{
  if(!arg)
    {
    
      set_light(1);
      
      short_desc=CNAME + "' workroom",
      long_desc=
	    "\n\n"
           +"     You have entered the workroom of "+CNAME+".\n" 
	   +"It is bright and airy here as sun comes in through\n"
	   +"the large wall-length windows to the west.\n"
	   +"Through the windows you can see the ocean sparkling\n"
	   +"in the distance.  If you listen closely you can hear\n"
	   +"the crashing of the waves.\n"
	   +"     As your gaze travels around the room, you notice\n"
	   +"a large futon resting against the far wall and a cluttered\n"
	   +"desk sitting next to it.\n\n";

      dest_dir=({
	  "room/post","post",
	  "room/church", "church",
	  "room/adv_guild", "advguild",
	  "/players/whisky/guild/room/nshop", "monkshop",
	  "/players/whisky/magic/mages_bar", "magebar",

	  });
      smell = "A faint scent of salt water is carried on the breeze.";

      property=({
	"no_clean_up"});

      items=({ 
	"window", "The windows are made of the finest, clearest glass",
	"windows","The windows are made of the finest, clearest glass",
	"futon","Looks comfortable.  Maybe you should sit down",
	"ocean","The clear blue water invites you to take a swim",
	"desk", "The desk is cluttered with VERY unimportant papers",
	"floor", "The cool bare stone is rough under your feet",
	"sun","The sun is so bright, you have to look away",

      });
    }
}

void init()
{
  ::init();
    add_action("sitdown", "sit");
    add_action("open", "open");
    owner=find_player("louie");
    if(TP->query_real_name()!="louie" || TP->query_real_name()!="sekhmet")
      invader=TP;

    if (TP->query_real_name()=="louie" || 
	TP->query_real_name()=="sekhmet")
      {
	add_action("kick", "fuckoff");
/*	add_action("transport","tele"); */
	add_action("shield","shield");
      }
    invasion();
    getrid();
    TP->set_smell("You smell the faint fragrence of sea water.");
  }

int sitdown(string str)
{
string where;
if (!(sscanf(str, "on %s", where)))
  {
    write("Sit where?\n");
    return 1;
  }
if (where=="desk")
  {
    write("You sit on the hard desk.  Ohh, it hurts.\n");
    say(TP->query_name()+" sits on the hard desk.\n");
    return 1;
  }
if (where=="futon")
  {
    say(TP->query_name()+" flops down on the futon.\n");
    write("You sit on the comfortable futon.  It feels great. \n");
    return 1;
  }
write("You don't want to sit on that.\n");
return 1;
}

int open(string str)
{
  if (!str)
      write("Open what?\n");
  if (str=="window"|| str=="windows")
    {
      say(TP->query_name()+" opens the windows.\n");
      write("You open the windows and feel the warm breeze on your face.\n");
    }
  if (str!="window"|| str!="windows")
    write("You can't open that.\n");
  return 1;
}


int kick(string str)
{
  object ob;
  string who;
  
  if (sscanf(str, "%s", who))
    {
      if (!(ob=present(who)))
	{
	  write("That player isn't in the workroom.\n");
	  return 1;
	}
      move_object(ob, "room/church");
      tell_object(ob, "Louie doesn't want you in her workroom.\n");
      tell_room("/players/louie/workroom",ob->query_real_name()+" is kicked out\n");
      return 1;
    }
}

int invasion()
{
if(!owner)
  {
    tell_object(invader,"You are entering a restricted area! *laugh* Just kidding!\n");
    return 1;
  }

if(this_player()->query_real_name()=="louie" || 
   this_player()->query_real_name()=="sekhmet")
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
	  write("Louie does not wish to be disturbed!\n");
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
      write("Louie does not wish to be disturbed!\n");
      move_object(this_player(), "room/church");
      tell_object(owner, this_player()->query_name()+" tried to enter the workroom\n\n");
      return 1;
    }
}


/* int transport(string str)
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
  tell_object(person, "You get to go see Louie.  YEAH! \n");
  command("look", person);
  tell_room(environment(this_player()),capitalize(person->query_real_name())+" is here.\n");
  return 1;
}

*/











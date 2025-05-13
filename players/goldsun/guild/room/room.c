
/* ---------------------------------------------------------------------

                FIGHTERS GUILDROOM  (c) Capablanca

   This is the guildroom of the famous Fighter guild. It works skill-
   based and inherits room.c (guild_room).

   GUILDMASTER: GOLDSUN
   --------------------------------------------------------------------- */

#define GUILD_NAME	"fighter"		/* fighters guild	*/ 
#define GM		"guild/master"

inherit "guild/guild_room";
#include "/players/goldsun/guild/skill_system.c"

#define MAXLVL		30
#define TO		this_object()
#define TP		this_player()
#define TPN		this_player()->query_name()
#define env		environment
#define SAY(x)		tell_room(env(TO),x)

int	guild;			/* guild # (reset get's it from obj/guild */


void reset(int flag)
{
// the guildguard and training master

    ::reset(flag);
     if (!present("sledge",this_object()))
          call_out("move_sledge",2);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "Inside the great Fighters Guild";
         long_desc =
         "You are standing in the inner halls of the great, famous\n"+
         "Fighters Guild. This guild is very well known to have\n"+
         "very powerful members. To the south you see the fighters\n"+
         "restroom, where you can rest your bones after your battles.\n"+
         "There is a big wooden sign fixed to the wall.\n";

         dest_dir =
         ({ 
	     "/players/goldsun/guild/room/hall2",   "north",
             "/players/goldsun/guild/room/restroom","east",
	     "/players/goldsun/guild/room/hall",    "south",
             "/players/goldsun/guild/room/confer",  "west"
         });
        
         items =
         ({
             "wall","The walls are covered with blood of victims", 
             "walls","The walls are covered with blood of victims", 
             "sign","Just type 'read sign' to get info",
             "wooden sign","Just type 'read sign' to get info",
         });

         skill_reset(0);    /* for the skill system */
         guild=GM->query_number(GUILD_NAME);
         set_guild(guild);
      }
}

void move_sledge()
{
    transfer(clone_object("/players/goldsun/guild/monster/sledge"),
    this_object());
}

void add_init()
{
     add_action("do_read","read");
     add_action("do_about","about");
}

int do_read(string arg)
{
    if (!arg || (arg!="sign" && arg!="wooden sign"))
        return 0;
    write("Welcome to Capablancas Fighter guild !\n"+
          "You can use here following Commands:\n\n"+
          "1.) join:         To get member of our guild.\n"+
          "2.) advance:      To advance your level here.\n"+
          "3.) list:         To get a list of quests.\n"+
          "4.) list [number] To get special info about a quest.\n"+
          "5.) about:        To get more info about this guild.\n");
    return 1;
}

int do_about()
{
    write(
    "This guild was build by Capablanca an Elder Archwiz and\n"+
    "one of the Creators of this world. As he build up this guild\n"+
    "it was one of the first and ever one of the most heroic guilds\n"+
    "in this world.\n\n"+
    "The spirit of the guild is ideal for heroic fighters and\n"+
    "knights.\n\n"+
    "Your famous Guildmaster nowadays is Goldsun !\n");
     return 1;
}
    
int do_join() 
{
 if (::do_join()==1) return 1;	/* Joining not possible */

  if(TP->query_str() < 7) 
  {
    write("Sorry but you are not strong enough to be a Fighter.\n");
          return 1;
  }
  write("Welcome to the Fighters Guild.\n");
  "sys/chatd.c"->do_chat(guild,capitalize(TP->query_real_name())+
              " has just become the newest member of our Fighters Guild.\n");
  TP->set_guild(guild);
  write("Type `help guild` for more information about your new abilities.\n");
  return 1;
}

int query_maxhp(int lvl) 
{
  int lg;

// the higher the legendlevel the higher the hit_points
  lg = this_player()->query_property("fighter_legend");

  if (lg < 1)
      lg = 0;
  else 
      lg = (lg * 3 + lg/2);

  return(30+lg+21*lvl);  /* con 1 = 50, con 30 = 514 */
}

int query_maxsp(int lvl) 
{
   int lg;

   lg = this_player()->query_property("fighter_legend");

   if (!lg)
        lg = 0;
      else
        lg = 1 + lg/2;
  return(47+lg+3*lvl); /* int 1 = 50, int 30 = 137 */
}

int do_advance(string arg) 
{

   if (::do_advance(arg)==2)  /* what means she can advance */
   {
        "sys/chatd.c"->do_chat(guild,"[*Fighter info*] "+
        capitalize(TP->query_real_name())+" is NOW level "+
        to_string(TP->query_level())+".\n");
   }
	return 1;
}

// only fighters may enter as long sledge is here :*)

status move(string arg)
{
   object master;

   if (!stringp(arg))
        arg = query_verb();

   master = present("sledge",TO);

   if (arg == "south" && TP->query_guild()!=3 && master
        && living(master) && !TP->query_immortal())
   {
      write("Fighter Sledge bars you the way !\n");   
      tell_room(TO,"Fighter Sledge says: \n"+
              "Sorry, "+capitalize(TP->query_real_name())+" this room "+
              "is only open for members of the Fighter Guild !\n");
      return 1; 
   }
   return ::move(arg);
}


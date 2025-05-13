inherit "guild/guild_room";
#include "/obj/lw.h"
#include "/players/sargon/define.h"
#include "/players/sargon/guild/rooms/guild.pic"
#define MAXLVL          30
#define SAY(x)          tell_room(E(TO),x)
#define TPRN		TP->query_real_name()


object will;

void reset( int arg ) {
  if( arg ) return 0;

         set_light(1);
         set_guild(3);
         short_desc = "Inside the great Fighter's Guild";
	 long_desc = BS("You are standing in the inner halls of the great,"+
		        "famous & Fighters guild. There's a large silver sign"+
			" on the wall.\n");

         dest_dir = ({  
             "/players/sargon/guild/rooms/castle","out",
             "/players/sargon/guild/rooms/restroom","south",
             "/players/apollo/thieves/rooms/fighter","down",
                  });

         property = ({"no_sneak", "no_steal", "has_fire" });
         items = ({
             "wall","The walls are covered with blood of victims", 
             "walls","The walls are covered with blood of victims", 
             "sign","Just type 'read sign' to get info",
             "silver sign","Just type 'read sign' to get info",
                 });

  if( !will ) {
        MO(CO("/players/sargon/guild/mon/will"), TO);
  }
}

void init() { 
  ::init();
     
     add_action("do_read","read");
     add_action("do_about","about");
     add_action("do_advance","advance");
     add_action("do_join", "join");
}

int do_read(string arg)
{
    if (!arg || (arg!="sign" && arg!="silver sign"))
        return 0;
    write("Welcome to The great Fighter's guild !\n"+
          "You can use here following Commands:\n\n"+
          "1.) join:         To become member of our guild.\n"+
          "2.) advance:      To advance your level here.\n"+
          "3.) list:         To get a list of quests you've done.\n"+
          "4.) list [number] To get special info about a quest.\n"+
          "5.) about:        To get more info about this guild.\n");
    return 1;
}

int do_about()
{
    write(
    "This guild was built by Capablanca an Elder Archwiz and\n"+
    "one of the Creators of this world. As he built up this guild\n"+
    "it was one of the first and ever one of the most heroic guilds\n"+
    "in this world.\n\n"+
    "The spirit of the guild is ideal for heroic fighters and\n"+
    "knights.\n\n"+
    "Your famous Guildmaster nowadays is Gareth !\n");
     return 1;
}
    
int do_join() {

 if(::do_join())
        return 1;

  if(TP->query_str() < 7) {
    write("Sorry but you are not strong enough to be a Fighter.\n");
          return 1;
  }

  /* Blade 051296:  Added check for level */
  if(TP->query_level()>10){
    write("Sorry, but you are too high level to change guilds.\n");
    return 1;
  }
  write("Welcome to the Fighters Guild.\n");

  "sys/chatd.c"->do_chat( 3, lw("[*Fighters*] " + CAP((string)TPRN) +
              " has just become the newest member of our Fighters Guild! \n"));

  TP->set_guild(3);
  write("Type `help guild` for more information about your new abilities.\n");
  return 1;
}


int do_advance(string arg) {
/*  int rc;
  rc = ::do_advance(arg);
  if(rc == 1) return 1; */

  if(!arg) {
    if( ::do_advance(arg) == 1) return 1;
    "sys/chatd.c"->do_chat(3,"[*Fighter info*] "+
    capitalize((string)TP->query_real_name())+" is NOW level "+
      TP->query_level()+".\n");
    return 1;
  }
  /* Uglymouth, 971205: added advance wizard */
  if( arg == "wizard" ) {
    if( ::do_advance( arg ) == 1 ) return 1;
    "sys/chatd"->do_chat( 3, "[*Fighter info*] "
      + capitalize( this_player()->query_real_name() )
      + " has become immortal. Hail!\n" );
    return 1;
  }
  if( arg == "legend" ) {
    if(TP->query_level()<29) 
      write("Sorry, but you are too low level to become a legend.\n");
    else {
      if( ::do_advance(arg) == 1) return 1;
      "sys/chatd.c"->do_chat(3,"[*Fighter info*] "+
      capitalize(TP->query_real_name())+" is NOW Legend level "+
      TP->query_legend_level()+".\n");
    }
    return 1;
  }
  write("Use either 'advance' or 'advance legend' to become a greater "+
	  "warrior!\n");
  return 1;
}

int query_maxhp(int lvl,int leg_lev) {
    int retval;
    
    retval = ((lvl * 30) + 100 + (leg_lev * 7));
    if( retval > 750) retval = 1000 + (leg_lev * 25);
    return retval;
}


int query_maxsp(int lvl,int leg_lev) {
    int retval;

    retval = ((lvl * 4) + 50 + (leg_lev * 5));
    if( retval > 110) retval = 200 + (leg_lev * 10);
    return retval;
}


status move(string arg) {
   object master;

   if (!stringp(arg))
        arg = query_verb();

   master = present("will",TO);

   if (arg == "south" && TP-> query_real_guild()!=3 && master
        && living(master) && !TP->query_immortal())
   {
      write("William bars your the way !\n");   
      tell_room(TO,"William the Conquerer says: \n"+
              "Sorry, "+capitalize(TP->query_real_name())+" this room "+
              "is only open for members of the Fighters Guild !\n");
      return 1; 
   }
   return ::move(arg);
}


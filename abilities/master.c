#define NAME "/abilities/ability_master"
#define TP this_player()
#define TRUST ({ "patience", "llort" })
#define SECURE (environment(TP)==this_object() && TP->query_archwiz() && \
                interactive(TP))
#define GM "/guild/master"

inherit "room/room";

mapping abilities;

long()
{
    write("Ability Master:\n"+
          "  Commands: dump                    list all abilities\n"+
          "            add \"<name>\" \"<path>\"   add an ability \n"+
          "            remove <name>           remove an ability\n"+
          "            show <name>             show a single ability\n"+
          "      Obvious Exits: church, guild, home\n");
}

short()
{
    return ("Skill Master");
}

void reset(int arg)
{
    if(arg) return;
    set_light(1);
    restore_object(NAME);
    if(!abilities) abilities=([]); 
}

nomask init()
{
   if(!SECURE)
   {
       write("UNDER CONSTRUCTION !\n");
       this_player()->move_player("X#room/church");
   }    
   add_action("church","church");
   add_action("guild","guild");
   add_action("add","add");
   add_action("remove","remove");
   add_action("show","show");
   add_action("dump","dump");
}

dump()
{
   string msg, *idx;
   int cnt,i;
   closure spf;

   spf = #'sprintf;

   cnt=m_sizeof(abilities);
   idx=m_indices(abilities);
   msg="      Skillname                 Path\n";
   for(i=0;i<cnt;i++)
   {
       msg+=apply(spf,"[%3d] %-25s %s\n",i,idx[i],abilities[idx[i]]);
   }
   if(cnt==0) msg+="          NONE\n";
   write(msg);
   return 1;
}

show(n)
{
   string path;

   if(!n || !stringp(n))
   {
       write("Wrong Argument!\n");
       return 1;
   }
   if(!path=abilities[n])
   {
       write("Skill not found!\n");
       return 1;
   }
   write("Skill '"+n+"' at path '"+path+"'.\n");
   return 1;
}


remove(n)
{
   if(!n || !stringp(n))
   {
       write("Wrong Argument!\n");
       return 1;
   }
   if(!remove_ability(n))
   {
      write("Error on removing ability.\n");
      return 1;
   }
   write("Ok.\n");
   return 1;
}

add(arg)
{
   int i;
   string n, p, dummy;
   if(!arg || !stringp(arg))
   {
       write("No or wrong type of Arguments!\n");
       return 1;
   }

   if((i=sscanf(arg,"\"%s\"%s\"%s\"",n,dummy,p)) != 3)
   {
       write("Wrong number of arguments ("+i+")!\n");
       return 1;
   }

   if(strlen(n) > 25)
   {
       write("Name to long!\n");
       return 1;
   }
   if(sizeof(explode(n," ")) > 1) {
       write("The name must not contain blanks!\n");
       return( 1 );
   }

   switch(add_ability(n,p))
   {
      case -1:
          write("Skill already exists! ("+n+")\n");
          break;
      case -2:
          write("Illegal filename! ("+p+")\n");
          break;
      case -3:
          write("File not found! ("+p+")\n");
          break;
      default:
          write("Skill '"+n+"' with path '"+p+"' added\n");
   }
   return 1;
}

guild()
{
   this_player()->move_player("X","guild/master"->query_room(
                   this_player()->query_guild())); 
   return 1;
}

church()
{
   this_player()->move_player("X#room/church"); 
   return 1;
}

mixed dump_abilities()  { return( abilities ); }

/* ------------------------------------------------------------------------ */
/* adds a new ability                                                       */
/*                                                                          */
/* -> cmd    = the command, the player must type, to use the ability        */
/*    file   = the file, in which the function is described                 */
/* <- the idx of the new ability, if ok;                                    */
/*    -1  ability already exists                                            */
/*    -2  illegal filename                                                  */
/*    -3  file not found                                                    */
/* ------------------------------------------------------------------------ */
int add_ability( string cmd, string file ) 
{
    if( !this_player() || !SECURE || !cmd || !file ) return -1;

    if( abilities[cmd] )             return -1;
    if( file[0..9]!="abilities/" )   return -2;
    if( file_size(file+".c") < 1)    return -3;

    abilities[cmd]=file;

    save_object(NAME);
    return m_sizeof(abilities)-1;
}

/* ------------------------------------------------------------------------ */
/* removes an existing ability                                              */
/*                                                                          */
/* -> cmd    = the name of the ability (command)                            */
/* <- -1, if not allowed to remove; 0, if no such spell; 1, if ok           */
/* ------------------------------------------------------------------------ */
int remove_ability(string cmd) 
{
    int idx;

    if(!this_player() || !SECURE || !cmd) return -1;
    if(!abilities[cmd]) return 0;

    abilities=m_delete(abilities,cmd);
    save_object(NAME);
    return 1;
}

/* ----------------------------------------------------------------------- */
/* gets an ability-description of the spell - database (not a player-skill)*/
/*                                                                         */
/* result: the ability with the number (or name) id                        */
/* ----------------------------------------------------------------------- */
mixed get_ability( string id )
{ 
    if(!id) return abilities;
    if(stringp(id))
    {
        return abilities[id];
    }
    return;
}

save_me()
{
    if(TP && SECURE) return save_object(NAME);
}


string know_level(int val)
{
   string rtc;

   if(val ==   0)      rtc = "None";
   else if(val <   10) rtc = "Awful";
   else if(val <   25) rtc = "Bad";
   else if(val <   40) rtc = "Poor";
   else if(val <   60) rtc = "Average";
   else if(val <   80) rtc = "Fine";
   else if(val <   90) rtc = "Good";
   else if(val <   95) rtc = "Vy good";
   else if(val <  100) rtc = "Superb";
   else if(val == 100) rtc = "Perfect";
   else                rtc = "Strange";

   return rtc;
}

string time_level(int val)
{
   string rtc;

   if(val <  -2)      rtc = "Strange";
   else if(val == -2) rtc = "-----";
   else if(val == -1) rtc = "Imm.";
   else if(val ==  0) rtc = "V short";
   else if(val ==  1) rtc = "Short";
   else if(val ==  2) rtc = "Average";
   else if(val ==  3) rtc = "Long";
   else if(val ==  4) rtc = "Vy long";
   else               rtc = "Ex long";

   return rtc;
}

string show_abilities(object who)
{
   mixed *spdat;
   string msg,spfile;
   int i,nr_of_ab;
   closure spf,call;

   nr_of_ab = 0;
   spdat = who->get_ability(-1);
   if ( spdat )
      nr_of_ab = sizeof(spdat[0]); 
   if(!nr_of_ab)
   { 
      return("You do not know any special abilities!\n");
   }
   spf=#'sprintf;

   msg = "";
   for(i=0;i<nr_of_ab;i++)
   {
      spfile = get_ability(spdat[0][i]);
      msg+=apply(spf,"%-20s %-7s %-7s", spdat[0][i],
                   know_level(spdat[1][i]),
                   time_level(spdat[3][i]) );
      if ( i%2 ) msg += "\n";
      else       msg += "  |  ";
   }
   if ( i%2 ) msg += "\n";

   return( msg );   
}

void all_abilities( object tp, int guild )       // -1 is all
{
   mixed   *name, *g;
   int     size, i, lvl, il;
   string  res, fn, *gn;
   closure lcall, lspf;
   mapping ad;

   lcall = #'call_other;
   lspf=#'sprintf;

   size = GM->query_nog();
   gn = ({});
   for ( i = 0; i < size; i++ )
      gn += ({ GM->query_name(i) });

   name = m_indices( abilities );
   size = m_sizeof( abilities );
   if ( !name || !size ) {
      write( "No spells defined.\n" );
   }

   name = sort_array( name, "less_func", this_object() );

   if ( guild == -1 )
      res = funcall( lspf, "%-30s %s\n\n", "Ability","Guilds allowed" );
   else
      res = "[LVL] Ability\n\n";

   for ( --size; size >= 0; size-- ) {
      fn = abilities[name[size]];
      ad = funcall(lcall,fn,"allowance_data");
      if ( guild==-1 )
      {
         res += funcall( lspf, "%-30s ", name[size] );
         g = m_indices(ad);
         i = m_sizeof(ad);
         for ( --i; i >= 0; i-- ) {
            lvl = ad[g[i]];
            if ( lvl > 29 )
               res += gn[g[i]] + " L" + (lvl-29);
            else
               res += gn[g[i]] + " " + lvl;
            if ( i ) res += ", ";
         }
         res += "\n";
      }
      else if ( ad[guild] > 0 ) {
         lvl = ad[guild];
         if ( lvl > 29 )
            res += funcall( lspf, "[L%2d] %s\n", ad[guild]-29, name[size] );
         else
            res += funcall( lspf, "[%3d] %s\n", ad[guild], name[size] );
      }
   }

   tp->more_string( res );
}

int less_func( object ob1, object ob2 )
{
   if ( ob1 < ob2 ) return( 1 );
   return( 0 ); 
}

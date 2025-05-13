#define NAME "spells/spell_master"
#define TP this_player()
#define TRUST ({ "patience", "whisky", "llort" })
#define SECURE (environment(TP)==this_object() && TP->query_archwiz() && \
                interactive(TP))
#define GM "/guild/master"

inherit "room/room";

mapping spells;

long()
{
    write("Spell Master:\n"+
          "  Commands: dump                    list all spells\n"+
          "            add \"<name>\" \"<path>\"   add a spell\n"+
          "            remove <name>           remove a spell\n"+
          "            show <name>             show a single spell\n"+
          "      Obvious Exits: church, guild, home\n");
}

short()
{
    return ("Spell Master");
}

void reset(int arg)
{
    if(arg) return;
    set_light(1);
    restore_object(NAME);
    if(!spells) spells=([]); 
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

   cnt=m_sizeof(spells);
   idx=m_indices(spells);
   msg="      Spellname                 Path\n";
   for(i=0;i<cnt;i++)
   {
       msg+=apply(spf,"[%3d] %-25s %s\n",i,idx[i],spells[idx[i]]);
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
       write("Wrong argument!\n");
       return 1;
   }
   if(!path=spells[n])
   {
       write("Spell not found!\n");
       return 1;
   }
   write("Spell '"+n+"' at path '"+path+"'.\n");
   return 1;
}


remove(n)
{
   if(!n || !stringp(n))
   {
       write("Wrong argument!\n");
       return 1;
   }
   if(!remove_spell(n))
   {
      write("Error during spell removal!\n");
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
       write("No or wrong type of arguments!\n");
       return 1;
   }

   if((i=sscanf(arg,"\"%s\"%s\"%s\"",n,dummy,p)) != 3)
   {
       write("Wrong number of arguments ("+i+")!\n");
       return 1;
   }

   if(strlen(n) > 25)
   {
       write("Name too long!\n");
       return 1;
   }

   switch(add_spell(n,p))
   {
      case -1:
          write("Spell already exists! ("+n+")\n");
          break;
      case -2:
          write("Illegal filename! ("+p+")\n");
          break;
      case -3:
          write("File not found! ("+p+")\n");
          break;
      default:
          write("Spell '"+n+"' with path '"+p+"' added.\n");
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

mixed dump_spells()  { return( spells ); }

/* ------------------------------------------------------------------------ */
/* adds a new spells                                                        */
/*                                                                          */
/* -> cmd    = the command, the player must type, to release the spell      */
/*    file   = the file, in which the function is described                 */
/* <- the idx of the new spell, if ok;                                      */
/*    -1  spell already exists                                              */
/*    -2  illegal filename                                                  */
/*    -3  file not found                                                    */
/* ------------------------------------------------------------------------ */
int add_spell( string cmd, string file ) 
{
    if( !this_player() || !SECURE || !cmd || !file ) return -1;

    if( spells[cmd] )             return -1;
    if( file[0..6]!="spells/" )   return -2;
    if( file_size(file+".c") < 1) return -3;

    spells[cmd]=file;

    save_object(NAME);
    return m_sizeof(spells)-1;
}

/* ------------------------------------------------------------------------ */
/* removes an existing spell                                                */
/*                                                                          */
/* -> cmd    = the name of the spell (command)                              */
/* <- -1, if not allowed to remove; 0, if no such spell; 1, if ok           */
/* ------------------------------------------------------------------------ */
int remove_spell(string cmd) 
{
    int idx;

    if(!this_player() || !SECURE || !cmd) return -1;
    if(!spells[cmd]) return 0;

    spells=m_delete(spells,cmd);
    save_object(NAME);
    return 1;
}

/* ----------------------------------------------------------------------- */
/* gets a spell-description of the spell - database (not a player-spell)   */
/*                                                                         */
/* result: the skill with the number (or name) id                          */
/* ----------------------------------------------------------------------- */
mixed get_spell( string id )
{ 
    if(!id) return spells;
    if(stringp(id))
    {
        return spells[id];
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
   else if(val <   95) rtc = "Vy Good";
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

string show_spells(object who)
{
   mixed *spdat;
   string msg,spfile;
   int i,nr_of_spells;
   closure spf,call;

   nr_of_spells = 0;
   spdat = who->get_spell(-1);
   if ( spdat )
      nr_of_spells = sizeof(spdat[0]); 
   if(!nr_of_spells)
   { 
      return("You do not know any spells!\n");
   }
   spf=#'sprintf;

   msg = "";
   for(i=0;i<nr_of_spells;i++)
   {
      spfile = get_spell(spdat[0][i]);
      msg+=apply(spf,"%-20s %-7s %-7s", spdat[0][i],
                   know_level(spdat[1][i]),
                   time_level(spdat[3][i]) );
      if ( i%2 ) msg += "\n";
      else       msg += "  |  ";
   };
   if ( i%2 ) msg += "\n";

   return( msg );   
}

void all_spells( object tp, int guild )       // -1 is all
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

   name = m_indices( spells );
   size = m_sizeof( spells );
   if ( !name || !size ) {
      write( "No spells defined.\n" );
      return;
   }

   name = sort_array( name, "less_func", this_object() );

   if ( guild == -1 )
      res = funcall( lspf, "%-30s %s\n\n", "Name of spell", "Guilds allowed" );
   else
      res = "[LVL] Name of spell\n\n";

   for ( --size; size >= 0; size-- ) {
      fn = spells[name[size]];
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

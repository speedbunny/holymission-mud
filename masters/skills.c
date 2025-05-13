inherit "/room/room";

#define FILE    "/masters/skills"
#define TP      this_player()
#define SECURE  (environment(TP)==this_object() && interactive(TP) \
                 && TP->query_archwiz())
#define GM      "/guild/master"

mapping skills;                      // [name : [guild : lvl]]

string know_level(int val);

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   restore_object( FILE );

   short_desc = "Skill-Master";
   long_desc = "Skill-Master\n\nCommands:\n"+
      "add <skill>                      adds a new skill\n"+
      "remove <skill>                   removes an existing skill\n"+
      "addguild <skill> <guild> <level> adds or changes a skill for a guild\n"+
      "remguild <skill> <guild> <level> remove a skill for a guild\n"+
      "showall                          show all skills\n";
   set_light( 1 );
   no_obvious_msg = "";

   if ( !skills )
      skills = ([]);
}

void init()
{
   if ( !SECURE )
      TP->move_player( "quickly#/room/church" );

   ::init();

   add_action( "do_add",      "add" );
   add_action( "do_addguild", "addguild" );
   add_action( "do_rem",      "remove" );
   add_action( "do_showall",  "showall" );
}

int do_add( string arg )
{
   if ( !SECURE ) return( 0 );

   if ( !arg ) {
      write( "Which skill do you want to add ?\n" );
      return( 1 );
   }

   if ( sizeof(explode(arg," ")) > 1 ) {
      write( "The skill must be a single word. Database unchanged.\n" );
      return( 1 );
   }

   if ( strlen( arg ) > 19 ) {
      write("The maximum length for a skill-name is 19. Database unchanged.\n");
      return( 1 );
   }

   if ( skills[arg] ) {
      write( "There is already such a skill. Database unchanged.\n " );
      return( 1 );
   }

   skills[arg] = ([]);
   write( "New skill '"+arg+"' added to the database.\n" );
   save_object( FILE );

   return( 1 );
}

int do_remove( string arg )
{
   if ( !SECURE ) return( 0 );

   if ( !arg ) {
      write( "Which skill do you want to remove ?\n" );
      return( 1 );
   }

   if ( !skills[arg] ) {
      write( "There is no such skill. Database unchanged.\n " );
      return( 1 );
   }

   skills = m_delete( skills, arg );
   write( "Skill '"+arg+"' removed from the database.\n" );
   save_object( FILE );

   return( 1 );
}

int do_addguild( string arg )
{
   string  sk, gui;
   int     lvl;
   mapping info;

   if ( !arg || sscanf( arg, "%s %s %d", sk, gui, lvl ) != 3 || lvl < 1 ||
        "guild/master"->query_number(gui) == -1 ) {
      write( "Error/invalid arguments: addguild <skill> <guild> <level>\n" );
      return( 1 );
   }

   if ( !skills || !skills[sk] ) {
      write( "No such skill ('"+sk+"') defined.\n" );
      return( 1 );
   }

   skills[sk][GM->query_number(gui)] = lvl;
   save_object( FILE );
   write( "Guild '"+gui+"' with level '"+lvl+"' added/changed for skill '"+sk+
          "'.\n" );
   return( 1 );
}

int do_showall( string arg )
{
   int     i, sz, sz1;
   string  res, res1;
   string  *idx, *idx1;
   mapping info;

   if ( !SECURE ) return( 0 );

   sz = m_sizeof( skills );
   if ( !sz )
      res = "No skills defined yet.\n";
   else {
      idx = m_indices( skills );
      res = "These skills are defined by now:\n\n";
      for ( i = 0; i < sz; i++ ) {
         idx1 = m_indices( skills[idx[i]] );
         sz1 = m_sizeof( skills[idx[i]] );
         res1 = "";
         for ( --sz1; sz1 >= 0; sz1-- )
            res1+=idx1[sz1]+" "+skills[idx[i]][idx1[sz1]]+", ";
         res += sprintf( "%-20s %s\n", idx[i], res1 );
      }
      res += "\n";
   }

   write( res );
   return( 1 );
}

int get_skill( string sk )
{
   if ( !sk || !skills || !skills[sk] )
      return( 0 );

   return( 1 );
}

int level( string sk, int gui )
{
   if ( !sk || !skills || !skills[sk] || !gui )
      return( -1 );

   return( skills[sk][gui] );
}

string show_skills(object who)
{
   mapping spdat;
   string msg,spfile;
   int i,nr_of_sk;
   closure spf,call;
   mixed *idx;

   nr_of_sk = 0;
   spdat = who->get_all_skills();
   if ( spdat )
      nr_of_sk = m_sizeof(spdat); 
   if(!nr_of_sk)
   { 
      return("You do not have any special skills!\n");
   }

   msg = "";
   idx = m_indices(spdat);
   for(i=0;i<nr_of_sk;i++)
   {
      msg+=sprintf( "%-20s %-7s        ", idx[i],
                   know_level(spdat[idx[i]][0]) );
      if ( i%2 ) msg += "\n";
      else       msg += "  |  ";
   }
   if ( i%2 ) msg += "\n";

   return( msg );   
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

void all_skills( object tp, int guild )       // -1 is all
{
   mixed   *name, *g;
   int     size, i, lvl, il;
   string  res, *gn;
   closure lcall, lspf;
   mapping ad;

   lcall = #'call_other;
   lspf=#'sprintf;

   size = GM->query_nog();
   gn = ({});
   for ( i = 0; i < size; i++ )
      gn += ({ GM->query_name(i) });

   name = m_indices( skills );
   size = m_sizeof( skills );
   if ( !name || !size ) {
      write( "No skills defined.\n" );
      return;
   }

   name = sort_array( name, "less_func", this_object() );

   if ( guild == -1 )
      res = funcall( lspf, "%-30s %s\n\n", "Name of skill", "Guilds allowed" );
   else
      res = "[LVL] Name of skill\n\n";

   for ( --size; size >= 0; size-- ) {
      ad = skills[name[size]];
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

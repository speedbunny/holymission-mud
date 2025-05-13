/*
 * I am recoding that dammned thing, noone can read 
 * this code, besides it is complicated as hell.
 * ###mike###
 */

 /* pat, 2505'92
   added a release time at the actions. the release time is the time, in
   how much heart_beats the actions will be performed. the values for
   it are:
      -1 -> do it immedately
       0 -> do it in the next heart_beat
      >0 -> do in in x heart_beats
*/


#define NAME "obj/skill_master"

mixed *skills;
mixed *actions;
mixed *spells;

void reset(int arg)
{
    if(arg) return;
    restore_object(NAME);
    if(!skills) skills=({ ({}),({}) });
    if(!actions) actions=({ ({}),({}),({}),({}) });
    if(!spells) spells=({ ({}),({}),({}) }); 
}


/***************  G E T _ S K I L L *****************************/
/*
 * ID ist Integer, die nummer des skills
 * return: ({ "skill_name", guild_number }) 
 *    
 * ID ist String, der name des Skills
 * return: ({ skill_number, "skill_name", guild_number })
 */
mixed get_skill(mixed id) 
{ 
    if(intp(id)) 
	{
        if(id<0 || id>=sizeof(skills[0])) return;
        return ({ skills[0][id] }) + ({ skills[1][id] });
    }
    if(stringp(id)) 
	{
        if((id=member_array(id,skills[0]))==-1) return;
        else return ({ id }) + ({ skills[0][id] }) + ({ skills[1][id] });
    }
    return;
}


/***************   A D D _ S K I L L   *********************************/
/* 
 * If you are LORD you can add a new skill to the data_base
 * add_skill( name_of_skill, guild_number )
 */ 
int add_skill(string name, int guildID) 
{
    int i,res;
    if(!this_player() || !this_player()->query_archwiz() || !name) return -1;
    if(member_array(name,skills[0])!=-1) return -1;
    skills[0]+=({ name });
    skills[1]+=({ guildID });
    save_object(NAME);
    return sizeof(skills[0])-1;
}


/************   A D D _ S K I L L _ A C T I O N   *************************/
/*
 * If you are LORD you can connect a function to a skill
 * At the moment i have no idea what this is needed for
 */
int add_skill_action(string name, string func, string file, int rel_time) 
{
    if(!this_player() || !this_player()->query_archwiz() || !name) return -1;
    if(member_array(name,actions[0])!=-1) return -1;
    actions[0]+=({ name });
    actions[1]+=({ func });
    actions[2]+=({ file });
    actions[3]+=({ rel_time });
    save_object(NAME);
    return sizeof(actions[0])-1;
}


/*************  R E M O V E _ S K I L L _ A C T I O N   ***************/
/*
 * If you happen to be lord or higher you can remove the action
 * related to a skill
 */
int remove_skill_action(string name) 
{
    int idx;
    if(!this_player() || !this_player()->query_lord() || !name) return -1;
    if((idx=member_array(name,actions[0]))==-1) return 0;
    actions[0]=del_array(actions[0],idx);
    actions[1]=del_array(actions[1],idx);
    actions[2]=del_array(actions[2],idx);
    actions[3]=del_array(actions[3],idx);
    save_object(NAME);
    return 1;
}


/*******************  P R O C E S S _ S K I L L   *************************/
/*
 * Checks if the query_verb() is the action that is required to 
 * trigger the skill
 */
int process_skill(string arg) {
    int idx;
    object pocessor;
    if((idx=member_array(query_verb(),actions[0]))==-1) return 0;
	
	/*
 	 * wenns das file NICHT gibt, das mit add_skill_action definiert
	 * gibt dann wird die funktion mit return 0 beendet
	 */
    if(catch(call_other(actions[2][idx],"??"))) return 0;

    if ( actions[3][idx] < 0 )
       return (int)call_other(actions[2][idx],actions[1][idx],arg);

/*** prep_sk_action   -> was is das ?? ***/
    return( (int) this_player()->prep_sk_action( arg,actions[3][idx] ) );
}


/*****************   S K I L L _ C O M M A N D S   **********************/
/*
 * adds the Skill-action to the player_actions
 */
skill_commands() 
{
    int i;
    for(i=0;i<sizeof(actions[0]);i++) 
        this_player()->add_skill_action(actions[0][i]);
}

mixed dump_skills() { return skills; }
mixed dump_actions() { return actions; }
mixed dump_spells()  { return( spells ); }


/*
 * looks rather important *grin*
 */
mkaction(arg,pl) 
{
    pl->add_skill_action(arg);
}


/* ------------------------------------------------------------------------ */
/* adds a new spells                                                        */
/*                                                                          */
/* -> cmd    = the command, the player must type, to release the spell      */
/*    file   = the file, in which the function is described                 */
/*    relTime= the def-time, when the spell will be released. this can be:  */
/*             -1 : release immediately, don't block, don't bother blocking */
/*              0 : release immediately, if not blocked                     */
/*              1 : release in next heart-beat                              */
/*            else: release in (x) heartbeats (must be higher positive)     */
/* <- the idx of the new spell, if ok; else -1                              */
/* ------------------------------------------------------------------------ */
int add_spell( string cmd, string file, int relTime ) 
{
    if( !this_player() || !this_player()->query_lord() || 
        !cmd || !file ) 
       return -1;

    if( member_array(cmd,spells[0]) != -1 ) 
       return -1;

    spells[0]+=({ cmd });
    spells[1]+=({ file });
    spells[2]+=({ relTime });

    save_object(NAME);
    return sizeof(spells[0])-1;
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

    if(!this_player() || !this_player()->query_lord() || !cmd) return -1;
    if((idx=member_array(cmd,actions[0]))==-1) return 0;

    spells[0]=del_array(spells[0],idx);
    spells[1]=del_array(spells[1],idx);
    spells[2]=del_array(spells[2],idx);
    save_object(NAME);
    return 1;
}

/* ----------------------------------------------------------------------- */
/* initializes the spell commands for the living                           */
/* this function is called by the monster and the player                   */
/* ----------------------------------------------------------------------- */
spell_commands()
{
   int i;

   for (i=0;i<sizeof(spells[0]);i++)
      if ( spells[0] )
         this_player()->add_spell_action(spells[0][i]);
}

/* ----------------------------------------------------------------------- */
/* gets a spell-description of the spell - database (not a player-spell)   */
/*                                                                         */
/* result: the skill with the number (or name) id                          */
/* ----------------------------------------------------------------------- */
mixed get_spell( mixed id )
{ 
   if(intp(id)) {
        if(id<0 || id>=sizeof(spells[0])) return;
        return ({ spells[0][id] }) + ({ spells[1][id] }) + 
               ({ spells[2][id] });
    }
    if(stringp(id)) {
        if((id=member_array(id,spells[0]))==-1) return;
        return ({ spells[0][id] }) + ({ spells[1][id] }) + 
               ({ spells[2][id] });
    }
    return;
}

/* ----------------------------------------------------------------------- */
/* inits the spells of a player (to be called of the logon, and only of it)*/
/* ----------------------------------------------------------------------- */
init_player_spells()
{
   int i;

   for ( i = 0; i < sizeof( spells[0] ); i++ )
      this_player()->add_spell_action( spells[0][i] );
}

/* ----------------------------------------------------------------------- */
/* the title of the skill-level                                            */
/* -> level                                                                */
/* <- title                                                                */
/* ----------------------------------------------------------------------- */
get_skill_title( level )
{
   int    mainLevel, subLevel;
   string ret;
   
   mainLevel = (level-1) / 9;
   if ( mainLevel == 11 )
      return( "guru" );

   subLevel = (level-1) % 9;

   switch( subLevel ) {
      case 0:  ret = "novice "; break;
      case 1:  ret = "apprentice "; break;
      case 2:  ret = ""; break;
      case 3:  ret = "confident "; break;
      case 4:  ret = "seasoned "; break;
      case 5:  ret = "expert "; break;
      case 6:  ret = "eminent "; break;
      case 7:  ret = "brilliant "; break;
      case 8:  ret = "superior "; break;
      default: ret = "";
   } 
   switch( mainLevel ) {
      case 0:  ret += "beginner"; break;
      case 1:  ret += "student"; break;
      case 2:  ret += "amateur"; break;
      case 3:  ret += "layman"; break;
      case 4:  ret += "acolyte"; break;
      case 5:  ret += "journeyman"; break;
      case 6:  ret += "craftsman"; break;
      case 7:  ret += "professional"; break;
      case 8:  ret += "veteran"; break;
      case 9:  ret += "master"; break;
      case 10: ret += "teacher"; break;
      default: ret += "";
   }

   return( ret );
}

save_me()
{
    return save_object(NAME);
}

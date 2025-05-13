/*
 * This is the guild master.
 *
 * This object is NOT designed for cloning or inheriting.
 * Use it by calling the functions listed below.
 * You can assume that the object is loaded in room/init_file,
 * so don't load it yourself but refer to the funtions in a style like:
 *
 * value="/guild/master"->query_function_value(params);
 *
 * Refer to a specific guild only via the guildnumber.
 * The adventurers guild is number 0 by default.
 *
 * It is needed that both, the guild room and the guild soul path name
 * are name according to the following conventions:
 *
 * guild_room: "/players/<responsive_wiz>/guild/guild.c"
 * guild_soul: "/players/<responsive_wiz>/guild/soul.c"
 *
 * If you want to establish your own guild, contact the adminstrators.
 * Your guild will be assigned a number, and all your guild's information
 * has to be stored in this file.
 *
 * NOTE: The experience-level table for monsters is also stored in this file.
 *       To get the exp. for a monster, you must call the function query_exp
 *       with guild == -1.
 *
 * These are the functions defined in the guild_master:
 * ===================================================
 *
 * query_name		... returns the name of the guild
 * query_number		... returns the number of the guild (use this at
 *			    reset in your guildroom)
 *                          *CAUTION* Adventurers guild is 0, this function
 *                          returns -1 for an illegal guild.
 * query_nog		... returns the number of guilds (NUM_GUILD)
 * query_dir		... returns the pathname to the guilddirectory
 * query_soul		... returns the pathname to the guildsoul
 * query_room		... returns the pathname to the guildroom
 * query_wiz		... returns the name of responsible wiz
 * query_levels		... returns the number of levels in this guild
 * query_level		... returns the reachable level for a given exp
 * query_pretitle	... returns the pretitle for a level in a guild
 * query_title		... returns the title for a level in a guild
 * query_exp		... returns the base exp for a level in a guild
 * query_maxhp		... calculate max_hp for guild/con
 * query_maxsp		... calculate max_sp for guild/int
 * query_maxfp		... calculate max_fp for guild/dex
 * get_soul		... move the guildsoul to the player (use at login,
 *			    and at joining the guild)
 * list_levels		... list the levels
 * change_skill		... change a skill 
 *
 */

#include "guild_defs.h"
#include "/sys/levels.h"

#define ADV_GUILD	"room/adv_guild"
#define NUM_EXP_TBL	4
#define NUM_MONST_LVL	100
#define SAY(str)	tell_room(environment(this_player()),str)

mixed gd_info;
mixed *gd_defines;
mixed *gd_exp;

int query_levels(int gd);

string query_guildchar(int gd) {
  return gd_info[gd][7];
}

// These routines must be called when the player logs on

string query_name(int gd) {
  return gd<NUM_GUILDS?gd_info[gd][0]:0;
}

int query_number(string str) {
  int i;

  if(!str)
    return -1;
  for(i=0;i<NUM_GUILDS;i++)
    if(gd_info[i][0]==str)
      return i;
  return -1;
}

int query_nog() {
  return NUM_GUILDS;
}

string query_wiz(int gd) {
  return gd_info[gd][1];
}

string query_dir(int gd) {
  return "players/"+gd_info[gd][1]+"/guild";
}

string query_room(int gd) {
  if(!gd)
    return ADV_GUILD;
  else
    return "players/"+gd_info[gd][1]+"/guild/room";
}

string query_id(int gd) {
  if(gd)
    return gd_info[gd][0]+"soul";
}

string query_soul(int gd) {
  if(gd && gd_info[gd][1])
    return "players/"+gd_info[gd][1]+"/guild/soul";
}

int query_levels(int gd) {
  if(intp(gd) && gd<(sizeof(gd_info)-1))
    return gd_info[gd][2];
  else
    return L_PLAYER+1;
} 

int query_level(int gd,int exp) {
  int i;
  i=0;
  while(gd_exp[gd_info[gd][6]][i]>exp)
    i++;
  return gd_info[gd][2]-i;
}

string old_query_pretitle(int gd, int lvl,int gender,int leg_lvl) {

  if(lvl==L_PLAYER && leg_lvl>0)         // legend-levels
    return capitalize(query_name(gd)+"-legend");

  gender=(gender+2)%3;
  lvl=gd_info[gd][2]-lvl;                // reverted array sequence

  if(lvl<0)
    return 0;
  if(gd_info[gd][3])                        // Gender supported
    return gd_defines[gd][lvl][0][gender];
  else
    return gd_defines[gd][lvl][0];        // Gender not supported
}

string query_pretitle(int gd,int lvl,int gender) {
  string name,file;

  name=query_name(gd);
  file="/guild/titles/"+name+"_titles";
  gender--;
  if(gender<0 || gender>2)
    gender=0;
  if(lvl<0)  
    return 0;
  else if(file_size(file+".c")>0)
    return (string)file->get_pretitle(lvl,gender);
  lvl=gd_info[gd][2]-lvl;                // reverted array sequence 
  if(lvl<0)
    return 0;
  else if(gd_info[gd][3])                        // Gender supported
    return gd_defines[gd][lvl][0][gender];
  else
    return gd_defines[gd][lvl][0];        // Gender not supported
}

string old_query_title(int gd,int lvl,int gender) {

  gender=(gender+2)%3;
  lvl=gd_info[gd][2]-lvl;                // reverted array sequence
  if(lvl<0)
    return 0;
  if(gd_info[gd][3])                        // Gender supported
    return gd_defines[gd][lvl][1][gender];
  else
    return gd_defines[gd][lvl][1];        // Gender not supported
}

string query_title(int gd,int lvl,int gender) {
  string name,file;

  name=query_name(gd);
  file="/guild/titles/"+name+"_titles";
  gender--;
  if(gender<0 || gender>2)
    gender=0;
  if(lvl<0)  
    return 0;
  else if(file_size(file+".c")>0)
    return (string)file->get_title(lvl,gender);
  lvl=gd_info[gd][2]-lvl;                // reverted array sequence
  if(lvl<0)
    return 0;
  else if(gd_info[gd][3])                        // Gender supported
    return gd_defines[gd][lvl][1][gender];
  else
    return gd_defines[gd][lvl][1];        // Gender not supported
}

// This routines are called when the player advances

int query_exp(int gd, int lvl, int leg_lvl) {

  int i;
  float s,b;
#if 0
  SAY("QUERY_EXP");
  SAY("gd "+gd+" lvl "+lvl+" max_lvl "+gd_info[gd][2]);
#endif

  if(gd==-1) {        // monster is calling
    if(lvl<1 || lvl>NUM_MONST_LVL)
      return 0;        // index out of bounds
    lvl=NUM_MONST_LVL-lvl;
    return gd_exp[0][lvl];
  }
  else {
    if(lvl==L_PLAYER && leg_lvl) {
      s=3000000.0;
      b=1000000.0;
      for(i=1;i<leg_lvl;i++) {
        b*=(1.0+0.03*i);
        s+=b;
      }
      return to_int(s);
    }
    else {
      lvl=gd_info[gd][2]-lvl;                // reverted array sequence
      if(lvl<0 || lvl>=gd_info[gd][2])
        return 0;    // index out of bounds
    }
  }
  return gd_exp[gd_info[gd][6]][lvl];
}

int query_maxhp(int gd,int lvl,int leg_lvl) {    // lvl == CON !!!!!!!!

  int max_hp;

// The function can be redefined in the guildroom
#if 0
  SAY("QUERY_MAXHP");
  SAY("gd " + gd + " lvl " + lvl);
  SAY("max_hp " + (gd_info[gd][4] + lvl * gd_info[gd][5]));
#endif

  if(gd==-1)
    return (lvl*lvl*3/2+(lvl-1)*8+50);  /* is a monster */

  if(!(max_hp=query_room(gd)->query_maxhp(lvl,leg_lvl)))
    return gd_info[gd][4]+lvl*gd_info[gd][5];
  else
    return max_hp;
}

int query_maxsp(int gd,int lvl,int leg_lvl) {     // lvl == INT !!!!!!

  int max_sp;

  if(!(max_sp=query_room(gd)->query_maxsp(lvl,leg_lvl)))
    return gd_info[gd][4]+lvl*gd_info[gd][5];
  else
    return max_sp;
}

object get_soul(int gd) {

  object ob;
#if 0
  write("get_soul "+gd+"\n");
  write("gd_info[gd][1] "+gd_info[gd][1]+"\n"); 
  write("present(query_id(gd), previous_object()): ");
  write(present(query_id(gd), previous_object()));
  write("\n");
  write("previous_object: ");
  write(previous_object());
  write("\n");
#endif
  if(!gd_info[gd][1])
    return 0;
  if(!(ob=present(query_id(gd),previous_object())))
    transfer(ob=clone_object(query_soul(gd)),previous_object());
  return ob;
}

// gender-support was missing. Llort
// more_string in player.c moonchild 030893

void list_levels(int gd,int gen) {

  string line,title,tmp;
  int i;
 
  if(!gen)
    gen=0;
  tmp="==================================================================\n";
  for(i=gd_info[gd][2];i>0;i--) {
    line="("+i+") ";
    if(i<10)
      line+=" ";
    title=query_pretitle(gd,i,gen);
    if(!title)
      title="";
    else
      title=" "+title;
    title+=" <*> "+query_title(gd,i,gen);
    line+=" "+title+extract(
          "                                                           ",
          0,59-strlen(title+query_exp(gd,i,0)));
    line+=query_exp(gd,i,0)+"\n";
    tmp+=line;
  }
  this_player()->more_string(tmp);
  return;
}

#if 1   // preperation to removal
// ----- lists the legend-levels 1-20 ----------------
void list_legend_levels(int gd,int gen) {

  string line,title,tmp,expStr;
  int i;
 
  tmp="==================================================================\n";
  for(i=20;i>0;i--) {
    line="("+i+") ";
    if(i<10)
      line+=" ";
    line+=capitalize(query_name(gd));
    title="Legend <*>";
    expStr=query_exp(gd,29,i)+"";
    line+=" "+title+extract(
          "                                                           ",
          0,59-strlen(title+expStr));
    line+=expStr+"\n";
    tmp+=line;
  }
  this_player()->more_string(tmp);
  return;
}

// new function to support skill-database

int change_skill(object pl,string name,int value,int max_value,int guildID) {

  int i,res;
  string po;

  if(pl) {
    po=explode(file_name(previous_object()),"#")[0];
    if(guildID<-1 || guildID>query_nog())
      return -1;
    if(guildID==0) {
      for(i=res=0;i<query_nog();i++) 
        res=res || ((po==query_room(guildID))
                || (po==query_soul(guildID)));
      if(!res)
        return -1;
    }
    else if(guildID!=-1) {
      if((po!=query_room(guildID) && po!=query_soul(guildID)))
        return -1;
    }
    return pl->change_skill(name,value,max_value,guildID); 
  }
  else
    return -1;
}

#endif

mixed *query_defines(int gd) {

  switch(gd) {

  case 0 : /* Adventurer Guild, Gender is supported */

  return ({

        ({ ({ 0,0,0 }), /* this is the pretitle field, 0 if no pretitle */
           ({ "apprentice Wizard",
              "apprentice Wizard",
              "apprentice Wizard" }) }),                           /* 30 */
        ({ ({0, 0, 0}),
           ({"Grandmaster Adventurer of Holy Mission",
             "Grandmistress Adventurer of Holy Mission",
             "Grand It Adventurer of Holy Mission"}) }),           /* 29 */
        ({ ({0, 0, 0}),
           ({"Veteran Missionary",
             "Veteran Missionary",
             "Veteran Missionary"}) }),                            /* 28 */
        ({ ({0, 0, 0}),
           ({"Experienced Missionary",
             "Experienced Missionary",
             "Experienced Missionary"}) }),                        /* 27 */
        ({ ({0, 0, 0}),
           ({"Novice Missionary",
             "Novice Missionary",
             "Novice Missionary"}) }),                             /* 26 */
        ({ ({0, 0, 0}),
           ({"Master Explorer",
             "Master Explorer",
             "Master Explorer"}) }),                               /* 25 */
        ({ ({0, 0, 0}),
           ({"Veteran Explorer",
             "Veteran Explorer",
             "Veteran Explorer"}) }),                              /* 24 */
        ({ ({0, 0, 0}),
           ({"Experienced Explorer",
             "Experienced Explorer",
             "Experienced Explorer"}) }),                          /* 23 */
        ({ ({0, 0, 0}),
           ({"Novice Explorer",
             "Novice Explorer",
             "Novice Explorer"}) }),                               /* 22 */
        ({ ({0, 0, 0}),
           ({"Master Adventurer",
             "Master Adventuress",
             "Master Adventurer"}) }),                             /* 21 */
        ({ ({0, 0, 0}),
           ({"Adventurer",
             "Adventuress",
             "Adventurer"}) }),                                    /* 20 */
        ({ ({ 0,0,0 }),
           ({ "grand master sorcerer",
              "grand master sorceress",
              "ferocious tyrannosaur" }) }),                       /* 19 */
        ({ ({ 0,0,0 }),
           ({ "master sorcerer",
              "master sorceress",
              "small tyrannosaur" }) }),                           /* 18 */
        ({ ({ 0,0,0 }),
           ({ "apprentice sorcerer",
              "apprentice sorceress",
              "vicious dragon" }) }),                              /* 17 */
        ({ ({ 0,0,0 }),
           ({ "warlock",
              "witch",
              "devicious dragon" }) }),                            /* 16 */
        ({ ({ 0,0,0 }),
           ({ "enchanter",
              "enchantress",
              "small dragon"}) }),                                 /* 15 */
        ({ ({ 0,0,0 }),
           ({ "magician",
              "magicienne",
              "powerful demon" }) }),                              /* 14 */
        ({ ({ 0,0,0 }),
           ({ "apprentice magician",
              "apprentice magicienne",
              "small demon" }) }),                                 /* 13 */
        ({ ({ 0,0,0 }),
           ({ "conjurer",
              "conjuress",
              "beholder" }) }),                                    /* 12 */
        ({ ({ 0,0,0 }),
           ({ "champion",
              "deadly amazon",
              "great monster" }) }),                               /* 11 */
        ({ ({ 0,0,0 }),
           ({ "warrior",
              "amazon",
              "experienced monster" })  }),                        /* 10 */
        ({ ({ 0,0,0 }),
           ({ "great adventurer",
              "great adventuress",
              "medium monster" }) }),                              /*  9 */
        ({ ({ 0,0,0 }),
           ({ "experienced adventurer",
              "experienced adventuress",
              "small monster" }) }),                               /*  8 */
        ({ ({ 0,0,0 }),
           ({ "small adventurer",
              "small adventuress",
              "threatening shadow" }) }),                          /*  7 */
        ({ ({ 0,0,0 }),
           ({ "experienced fighter",
              "charming siren",
              "shadow" }) }),                                      /*  6 */ 
        ({ ({ 0,0,0 }),
           ({ "small fighter",
              "siren",
              "wraith" }) }),                                      /*  5 */
        ({ ({ 0,0,0 }),
           ({ "master ranger",
              "master ranger",
              "bugbear" }) }),                                     /*  4 */
        ({ ({ 0,0,0 }),
           ({ "lowrank ranger",
              "lowrank ranger",
              "furry creature" }) }),                              /*  3 */
        ({ ({ 0,0,0 }),
           ({ "simple wanderer",
              "simple wanderer",
              "simple creature" }) }),                             /*  2 */
        ({ ({ 0,0,0 }),
           ({ "utter novice",
              "utter novice", 
              "utter creature" }) })                               /*  1 */
  });


  case 1 : /* Thieves Guild, Gender is not supported */

  return ({

    ({ 0,             "Apprentice Wizard"        }),                /* 30 */
    ({ 0,             "Prince of Thieves"        }),
    ({ "Sultan",       "Flamboyant Thief"        }),
    ({ "Shah",         "Extraordinary Thief"     }),
    ({ "Mufti",        "Marvelous Thief"         }),
    ({ "Grand Vizier", "Splendid Thief"          }),                /* 25 */
    ({ "Pasha",        "Dazzling Thief"          }),
    ({ "Sheik",        "Brilliant Thief"         }),
    ({ "Padisha",      "Polished Thief"          }),
    ({ "Vizier",       "Remarkable Thief"        }),
    ({ "Valis",        "Talented Thief"          }),                /* 20 */
    ({ "Amir",         "Accomplished Thief"      }),
    ({ 0,              "Grand Master Thief"      }),
    ({ 0,              "Master Thief"            }),
    ({ 0,                "Expert Thief"          }),
    ({ 0,              "Master Rogue"            }),                /* 15 */
    ({ 0,              "Expert Rogue"            }),
    ({ 0,              "Apprentice Rogue"        }),
    ({ 0,              "Veteran Buccaneer"       }),
    ({ 0,              "Master Burglar"          }),
    ({ 0,              "Professional Robber"     }),                /* 10 */
    ({ 0,              "Expert Swindler"         }),
    ({ 0,              "Marauder"                }),
    ({ 0,              "Brigand"                 }),
    ({ 0,              "Experienced Pickpocket"  }),
    ({ 0,              "Simple Thug"             }),                /*  5 */
    ({ 0,              "Footpad"                 }),
    ({ 0,              "Prankster"               }),
    ({ 0,              "Novice Sneak"            }),
    ({ 0,              "Neophyte Thief"          })                 /*  1 */

    });

  case 2 :

  return ({
 ({ 0,             "Apprentice Wizard"         }),                /* 30 */
 ({ "Arch-Druid",  "Experienced Hirophant"     }),
 ({ "Arch-Druid",  "Hirophant"                 }),
 ({ 0,             "Master Druid"              }),
 ({ 0,             "Apprentice Druid"          }),
 ({ 0,             "Assistant Druid"           }),                /* 25 */
 ({ "Druid",       "Master of Elementals"      }),
 ({ "Druid",       "Master of Fire"            }),
 ({ "Druid",       "Master of Water"           }),
 ({ "Druid",       "Master of Air"             }),
 ({ "Druid",       "Master of Earth"           }),                /* 20 */
 ({ 0,             "Expert Mystic"             }),
 ({ 0,             "Experienced Mystic"        }),
 ({ 0,             "Apprentice Mystic"         }),
 ({ 0,             "Infamous Medico"           }),
 ({ 0,             "Physican"                  }),                /* 15 */
 ({ 0,             "Master Quack"              }),
 ({ 0,             "Apprentice Quack"          }),
 ({ 0,             "Simple Quack"              }),
 ({ 0,             "Witchdoctor"               }),
 ({ 0,             "Experienced Explorer"      }),                /* 10 */
 ({ 0,             "Simple Explorer"           }),
 ({ 0,             "Master Forest Warden"      }),
 ({ 0,             "Apprentice Forest Warden"  }),
 ({ 0,             "Assistant Forest Warden"   }),
 ({ 0,             "Picker"                    }),                 /* 5 */
 ({ 0,             "Expert Florist"            }),
 ({ 0,             "Simple Florist"            }),
 ({ 0,             "Experienced Gardner"       }),
 ({ "Volunteer",   "Simple Gardner"            })                 /* 1 */
 });

  case 3 : /* Fighters guild, gender not supported */

  return ({

  ({ 0,           "Apprentice Wizard"                 }),        /* 30 */
  ({ 0,           "War Lord of Holy Mission"          }),
  ({ 0,           "Overlord of the Fighters Guild"    }),
  ({ 0,           "Lord of the Fighters Guild"        }),
  ({ 0,           "Commandant of the Fighters Guild"  }),
  ({ 0,           "Captain of the Fighters Guild"     }),        /* 25 */
  ({ "Fighter",   "Fighter Commandant"                }),
  ({ "Fighter",   "Fighter Captain"                   }),
  ({ "Fighter",   "training Lord"                     }),
  ({ "Fighter",   "training Commandant"               }),
  ({ "Fighter",   "training Captain"                  }),        /* 20 */
  ({ "Fighter",   "Viscount"                          }),
  ({ "Fighter",   "Duke"                              }),
  ({ "Fighter",   "Baron"                             }),
  ({ "Fighter",   "Earl"                              }),
  ({ "Fighter",   "Count"                             }),        /* 15 */
  ({ "Fighter",   "Knight"                            }),
  ({ "Fighter",   "Champion"                          }),
  ({ "Fighter",   "Warrior"                           }),
  ({ "Fighter",   "Conqueror"                         }),
  ({ "Fighter",   "Weapons Master"                    }),        /* 10 */
  ({ 0,           "Mercenary"                         }), 
  ({ 0,           "Soldier"                           }),
  ({ 0,           "Fighter"                           }),
  ({ 0,           "Trooper"                           }),
  ({ 0,           "Myrmidon"                          }),        /*  5 */
  ({ 0,           "Combantant"                        }),
  ({ 0,           "Peacemaker"                        }),
  ({ 0,           "War Fodder"                        }),
  ({ 0,           "Dead Meat"                         }),        /*  1 */

  });

  case 4 : /* Jedi guild, gender supported */

  return ({
  ({ ({ 0, 0, 0}),                                        /* 30 */
     ({"Apprentice Wizard",
       "Apprentice Wizard",
       "Apprentice Wizard"}) }),
  ({ ({"Duke","Duchess","Elder Dragon"}),                 /* 29 */
     ({"Jedimaster",
       "Jedimaster",
       "Jedimaster"}) }),
  ({ ({"Viceroy","Vicereine","Dragon"}),                  /* 28 */
     ({"minor Jedimaster",
       "minor Jedimaster",
       "minor Jedimaster"}) }),
  ({ ({"Marquis","Marquise","Hatchling Dragon"}),         /* 27 */
     ({"experienced brainstormer",
       "experienced brainstormer",
       "experienced brainstormer"}) }),
  ({ ({"Count","Countess","Lord"}),                       /* 26 */
     ({"brainstormer",
       "brainstormer",
       "brainstormer"}) }),
  ({ ({"Earl","Earl","Lord"}),                            /* 25 */
     ({"minor brainstormer",
       "minor brainstormer",
       "minor brainstormer"}) }),
  ({ ({"Viscount","Viscountess","Lord"}),                 /* 24 */
     ({"experienced Jedi",
       "experienced Jedi",
       "experienced Jedi"}) }),
  ({ ({"Baron","Baroness","Lord"}),                       /* 23 */
     ({"Jedi",
       "Jedi",
       "Jedi"}) }),
  ({ ({"Baronet","Baronet","Baronet"}),                   /* 22 */
     ({"minor Jedi",
       "minor Jedi",
       "minor Jedi"}) }),
  ({ ({"Knight","Knight","Knight"}),                      /* 21 */
     ({"Jedi contender",
       "Jedi contender",
       "Jedi contender"}) }),
  ({ ({"Senior Squire","Senior Squire","Senior Squire"}), /* 20 */
     ({"apprentice Jedi",
       "apprentice Jedi",
       "apprentice Jedi"}) }),
  ({ ({"Squire","Squire","Squire"}),                      /* 19 */
     ({"Jedi trainee",
       "Jedi trainee",
       "Jedi trainee"}) }),
  ({ ({"Squire","Squire","Squire"}),                      /* 18 */
     ({"training Jedi",
       "training Jedi",
       "training Jedi"}) }),
  ({ ({"Page","Page","Page"}),                            /* 17 */
     ({"hopeful contender",
       "hopeful contender",
       "hopeful contender"}) }),
  ({ ({"Page","Page","Page"}),                            /* 16 */
     ({"hopeful contender",
       "hopeful contender",
       "hopeful contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 15 */
     ({"contender",
       "contender",
       "contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 14 */
     ({"contender",
       "contender",
       "contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 13 */
     ({"lower contender",
       "lower contender",
       "lower contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 12 */
     ({"lower contender",
       "lower contender",
       "lower contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 11 */
     ({"novice contender",
       "novice contender",
       "novice contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 10 */
     ({"novice contender",
       "novice contender",
       "novice contender"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 9  */
     ({"student of Jedi knighthood",
       "student of Jedi knighthood",
       "student of jedi knighthood"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 8  */
     ({"student of Jedi knighthood",
       "student of Jedi knighthood",
       "student of jedi knighthood"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 7  */
     ({"beginning student of Jedi knighthood",
       "beginning student of Jedi knighthood",
       "beginning student of jedi knighthood"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 6  */
     ({"beginning student of Jedi knighthood",
       "beginning student of Jedi knighthood",
       "beginning student of jedi knighthood"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 5  */
     ({"hopeful novice",
       "hopeful novice",
       "hopeful novice"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 4  */
     ({"hopeful novice",
       "hopeful novice",
       "hopeful novice"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 3  */
     ({"novice",
       "novice",
       "novice"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 2  */
     ({"novice",
       "novice",
       "novice"}) }),
  ({ ({ 0, 0, 0 }),                                       /* 1  */
     ({"complete novice",
       "complete novice",
       "complete novice"}) })
  });

  case 5:        /* Mage's guild, gender supported */

  return ({
  ({ ({ 0,0,0 }), /* this is the pretitle field, 0 if no pretitle */
     ({ "apprentice Wizard", "apprentice Wizard",
        "apprentice Wizard" }) }),                                   /* 30 */
  ({ ({ "Archmage","Archmage","Archmage"}),
     ({ "grand master of all the arts", "grand mistress of all the arts",
        "Beast" }) }),                                               /* 29 */
  ({ ({ "Highmage","Highmage","Highmage" }),
     ({ "master of selfdiscipline", "mistress selfdiscipline",
        "ruler of the 7th plane" }) }),                              /* 28 */
  ({ ({ "High lord","High lady","High being" }),
     ({ "master of control", "mistress of control",
        "ruler of the 6th plane" }) }),                              /* 27 */
  ({ ({ "Mage lord","Mage lady","Mage beast" }),
     ({ "master of alteration", "mistress of alteration",
        "ruler of the 5th plane" }) }),                              /* 26 */
  ({ ({ "Lord advisor","Lady advisor",0 }),
     ({ "master of time", "mistress of time",
        "ruler of the 4th plane"}) }),                               /* 25 */
  ({ ({ "Lord","Lady",0 }),
     ({ "master of space", "mistress of space",
        "ruler of the 3rd plane" }) }),                              /* 24 */
  ({ ({ "Duke","Duchess",0 }),
     ({ "master of vision", "mistress of vision",
        "ruler of the 2nd plane" }) }),                              /* 23 */
  ({ ({ "Conjurer","Conjuress",0 }),
     ({ "master of elements", "mistress of elements",
        "ruler of the 1st plane" }) }),                              /* 22 */
  ({ ({ "Conjurer","Conjuress",0 }),
     ({ "master of fire","mistress of fire",
        "Lich King" }) }),                                           /* 21 */
  ({ ({ "Conjurer","Conjuress",0 }),
     ({ "master of earth", "mistress of earth",
        "Lich" }) }),                                                /* 20 */
  ({ ({ "Conjurer","Conjuress",0 }),
     ({ "master of water", "mistress of water",
        "Vampire Lord" }) }),                                        /* 19 */
  ({ ({ "Conjurer","Conjuress",0 }),
     ({ "master of air", "mistress of air",
        "elder Vampire" }) }),                                       /* 18 */
  ({ ({ "Chronomancer","Chronomanceress",0 }),
     ({ "timewanderer","timewanderer",
        "Vampire" }) }),                                             /* 17 */
  ({ ({ "Geomancer","Geomanceress","Flying" }),
     ({ "advanced traveller", "advanced traveller",
        "pegasus" }) }),                                             /* 16 */
  ({ ({ "Necromancer","Necromanceress","Staring" }),
     ({ "dark", "dark",
         "elder orb" }) }),                                          /* 15 */
  ({ ({ "Greater sorcerer","Greates sorceress","Impressive" }),
     ({ "","",
        "terror the lands" }) }),                                    /* 14 */
  ({ ({ "Sorcerer","Sorceress",0 }),
     ({ "","",
        "challenger of terror" }) }),                                /* 13 */
  ({ ({ "True mage","True witch","Dark Angel" }),
     ({ "","",
        "local nightmare" }) }),                                     /* 12 */
  ({ ({ "Mage","Witch",0 }),
     ({ "","", 
        "balrog leader" }) }),                                       /* 11 */
  ({ ({ "Journyman mage","Journyman witch",0 }), 
     ({ "","",
        "balrog" }) }),                                              /* 10 */
  ({ ({ "Apprentice mage","Apprentice witch","Lesser Angel" }),
     ({ "","",
        "servant of Law" }) }),                                      /*  9 */
  ({ ({ 0,0,"Lesser Angel" }),
     ({ "mage's servant of 1st order","mage's servant of 1st order",
              "servant of Balance" }) }),                            /*  8 */
  ({ ({ 0,0,"Lesser Angel" }),
     ({ "mage's servant of 2nd order","mage's servant of 2nd order",
             "servant of Chaos" }) }),                               /*  7 */
  ({ ({ 0,0,0 }),
     ({ "mage's servant of 3rd order","mage's servant of 3rd order",
        "griffin" }) }),                                             /*  6 */
  ({ ({ 0,0,0 }),
     ({ "mage's novice","mage's novice",
         "fairy" }) }),                                              /*  5 */
  ({ ({ 0,0,0 }),
     ({ "neophyte mage","neophyte mage",
        "imp" }) }),                                                 /*  4 */
  ({ ({ 0,0,0 }),
     ({ "medium","medium",
        "furry creature" }) }),                                      /*  3 */
  ({ ({ 0,0,0 }),
     ({ "gipsy","gipsy",
        "simple creature" }) }),                                     /*  2 */
  ({ ({ 0,0,0 }),
     ({ "utter novice","utter novice",
             "utter creature" }) })                                  /*  1 */
  });

  case 6:

  return ({
  ({ 0,   "Apprentice Wizard"  }),   /* 30 */
  ({ 0,   "Harper"             }),
  ({ 0,   "Apprentice Harper"  }),
  ({ 0,   "Wallcrumbler"       }),
  ({ 0,   "Soundmaster"        }),
  ({ 0,   "Shatterer"          }),   /* 25 */
  ({ 0,   "Panicbringer"       }),
  ({ 0,   "Knowledgable"       }),
  ({ 0,   "Mindclearer"        }),
  ({ 0,   "Original"           }),
  ({ 0,   "Crackcaller"        }),   /* 20 */
  ({ 0,   "Loremaster"         }),
  ({ 0,   "Fearbringer"        }),
  ({ 0,   "Significant"        }),        
  ({ 0,   "Charmer"            }),
  ({ 0,   "Sleepbringer"       }),   /* 15 */
  ({ 0,   "Analysor"           }),
  ({ 0,   "Mentalist"          }),
  ({ 0,   "Detective"          }),
  ({ 0,   "Singer"             }),
  ({ 0,   "Stunner"            }),   /* 10 */
  ({ 0,   "Linguist"           }),
  ({ 0,   "Sound"              }),
  ({ 0,   "Sonic"              }),
  ({ 0,   "Learner"            }),
  ({ 0,   "Estimator"          }),   /* 5 */
  ({ 0,   "Whisperer"          }),
  ({ 0,   "Silent"             }),
  ({ 0,   "Soother"            }),
  ({ 0,   "Student"            })
  });

  case 7:                /* Monks guild, gender support */

  return ({});

  case 8:                /* Ninja guild, no gs */

  return ({
  ({"Jonin",        "" }),
  ({"Jonin",        ""}),
  ({"Jonin",        "" }),
  ({"Jonin",        "" }),
  ({"Ninja-Master", "" }),
  ({"Ninja-Master", "" }),   
  ({"Ninja",        "" }),
  ({"Ninja",        "" }),
  ({"Master",       "" }),
  ({"Master",       "" }),             //21
  ({"Chunin",       "" }),      
  ({"Chunin",       "" }),
  ({"Chunin",       "" }),
  ({"Assassin",     "" }),      
  ({"Assassin",     "" }),
  ({"Executioner",  "" }),
  ({"Executioner",  "" }),
  ({"Genin",        "" }),
  ({"Genin",        "" }),   
  ({"Genin",        "" }),                // 11
  ({"Outcast",      "" }),
  ({"Outcast",      "" }),
  ({"Outcast",      "" }),
  ({"Outcast",      "" }), 
  ({"Outcast",      "" }),
  ({"Outcast",      "" }),
  ({"Outcast",      "" }),
  ({"Outcast",      "" }),
  ({"Outcast",      "" }),
  ({"Outcast",      "" })
 });

  case 9:                /* Summoners guild, no gender support */

  return ({
({ 0,                  "Apprentice Wizard"               }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "Arch-Summoner",    "Master of the Planes"            }),
({ "High Summoner",    "Traveller of the Planes"         }),
({ "High Summoner",    "Beseecher of the Planes"         }),
({ "High Summoner",    "Seer of the Planes"              }),
({ "High Summoner",    "Master of Power"                 }),
({ "High Summoner",    "Caller of Power"                 }),
({ "High Summoner",    "Channeler of Power"              }),
({ "High Summoner",    "Beholder of Power"               }),
({ "Summoner",         "Master of All Elements"          }),
({ "Summoner",         "Master of Fire"                  }),
({ "Summoner",         "Master of Earth"                 }),
({ "Summoner",         "Master of Wind"                  }),
({ "Summoner",         "Master of Water"                 }),
({ "Adept",            "Caller of the Elements"          }),
({ "Adept",            "Caller of Fire"                  }),
({ "Adept",            "Caller of Earth"                 }),
({ "Adept",            "Caller of Wind"                  }),
({ "Adept",            "Caller of Water"                 }),
({ "Apprentice",       "Beseecher of the Elements"       }),
({ "Apprentice",       "Beseecher of Fire"               }),
({ "Apprentice",       "Beseecher of Earth"              }),
({ "Apprentice",       "Beseecher of Wind"               }),
({ "Apprentice",       "Beseecher of Water"              }),
({ "Fledgling",        "Beholder of the Elements"        }),
({ "Fledgling",        "Beholder of Fire"                }),
({ "Fledgling",        "Beholder of Earth"               }),
({ "Fledgling",        "Beholder of Wind"                }),
({ "Fledgling",        "Beholder of Water"               }),
({ 0,                  "Novitiate Summoner"              })
});

  case 10:                /* Vagabond guild, gender support */

return ({
({ ({ 0,0,0}),
  ({"the Apprentice Wizard", "the Apprentice Wizardess", 
    "the Apprentice Wizard"}) }),                           /* 30 */
({ ({ "Overlord", "Ruling Lady", "Overlord", }),
  ({"master of Time and Space", "mistress of Time and Space", 
    "monster of Time and Space"}) }),
({ ({ "Lord", "Lady", "Monster", }),
  ({"Champion of Order", "Champion of Order", "Champion of Order"}) }),
({ ({"Chronowarrior", "Chronowarrioress", "Chronowarrior" }),
  ({"Keeper of Order", "Keeper of Order", "Keeper of Order"}) }),
({ ({ "Chronowarrior", "Chronowarrioress", "Chronowarrior"}),
  ({"Battler of Chaos", "Battler of Chaos", "Battler of Chaos"}) }),
({ ({"Realm Runner", "Realm Runner", "Realm Runner"}),
  ({"Student of Order", "Student of Order", "Student of Order"}) }),
({ ({"Realm Runner", "Realm Runner", "Realm runner"}),
  ({"Elder Loremaster of Time and Space",
    "Elder Loremistress of Time and Space",
    "Elder Loremonster of Time and Space"}) }),
({ ({"Realm Runner", "Realm Runner", "Realm Runner"}),
  ({"Expert of Time and Space", "Expert of Time and Space",
    "Expert of Time and Space"}) }),
({ ({"Wanderer", "Wanderess", "Wanderer"}),
  ({"Beholder of Time and Space", "Beholder of Time and Space",
    "Beholder of Time and Space"}) }),
({ ({"Wanderer", "Wanderess", "Wanderer"}),
  ({"Loremaster of Time and Space", "Loremistress of Time and Space",
    "Loremonster of Time and Space"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Reknowned Traveller of Time and Space",
    "Renknowned Traveller of Time and Space",
    "Reknowned Traveller of Time and Space"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Traveller of Time and Space", "Traveller of Time and Space",
    "Traveller of Time and Space"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Master of Time", "Mistress of Time", "Monster of Time"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Traveller of Time", "Traveller of Time", "Traveller of Time"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Apprentice of Time", "Apprentice of Time", "Apprentice of Time"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Master of Space", "Mistress of Space", "Monster of Space"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Traveller of Space", "Traveller of Space", "Traveller of Space"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Wanderer of Space", "Wanderer of Space", "Wanderer of Space"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Wanderer of Realms", "Wanderer of Realms",
    "Wanderer of Realms"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Apprentice of Time", "Apprentice of Time",
    "Apprentice of Time"}) }),
({ ({"Vagabond", "Vagabond", "Vagabond"}),
  ({"Apprentice of Space", "Apprentice of Space",
    "Apprentice of Space"}) }),
({ ({"Traveller", "Traveller", "Traveller"}),
  ({"Proud Wanderer", "Proud Wanderer",
    "Proud Wanderer"}) }),
({ ({"Traveller", "Traveller", "Traveller"}),
  ({"Roaming One", "Roaming One",
    "Roaming One"}) }),
({ ({0,0,0}),
  ({"Apprentice Vagabond", "Apprentice Vagabond", "Apprentice Vagabond"}) }),
({ ({0,0,0}),
  ({"Pursuer of Time and Space", "Pursuer of Time and Space", 
    "Pursuer of Time and Space"}) }),
({ ({0,0,0}),
  ({"Warrior of Order", "Warrior of Order", "Warrior of Order"}) }),
({ ({0,0,0}),
  ({"Explorer", "Explorer", "Explorer"}) }),
({ ({0,0,0}),
  ({"Wanderer", "Wanderer", "Wanderer"}) }),
({ ({0,0,0}),
  ({"Small Wanderer", "Small Wanderer", "Small Wanderer"}) }),
({ ({0,0,0}),
  ({"Tiny Wanderer", "Tiny Wanderer", "Tiny Wanderer"}) }),
({ ({0,0,0}),
  ({"utter wanderer", "utter wanderer", "utter wanderer"}) })
});

  case 11:              /* Barbarian guild, gender support */

return ({
({ ({ 0, 0, 0 }),
     ({ "Apprentice Wizard-Barbarian",
        "Apprentice Wizard-Barbarian",
        "Apprentice Wizard-Barbarian" }) }),        /* 30 */
({ ({ 0, 0, 0 }),
     ({ "Warrior King",
        "Amazon Queen",
        "Warrior King" }) }),                       /* 29 */
({ ({ 0, 0, 0 }),
     ({ "Warrior Prince",
        "Amazon Princess",
        "Warrior Prince" }) }),                     /* 28 */
({ ({ 0, 0, 0 }),
     ({ "Barbarian Tribesleader",
        "Amazon Tribesleader",
        "Barbarian Tribesleader" }) }),             /* 27 */
({ ({ 0, 0, 0 }),
     ({ "High Barbarian Warrior",
        "High Amazon Warrior",
        "High Barbarian Warrior" }) }),             /* 26 */
({ ({ 0, 0, 0 }),
     ({ "High Barbarian",
        "High Amazon",
        "High Barbarian" }) }),                     /* 25 */
({ ({ 0, 0, 0 }),
     ({ "Barbarian Warrior",
        "Amazon Warrior",
        "Barbarian Warrior" }) }),                  /* 24 */
({ ({ 0, 0, 0 }),
     ({ "Greater Barbarian",
        "Greater Amazon",
        "Greater Barbarian" }) }),                  /* 23 */
({ ({ 0, 0, 0 }),
     ({ "Barbarian",
        "Amazon",
        "Barbarian" }) }),                          /* 22 */
({ ({ 0, 0, 0 }),
     ({ "Lesser Barbarian",
        "Lesser Amazon",
        "Lesser Barbarian" }) }),                   /* 21 */
({ ({ 0, 0, 0 }),
     ({ "High Warrior",
        "High Warrior",
        "High Warrior" }) }),                       /* 20 */
({ ({ 0, 0, 0 }),
     ({ "Greater Warrior",
        "Greater Warrior",
        "Greater Warrior" }) }),                    /* 19 */
({ ({ 0, 0, 0 }),
     ({ "Experienced Warrior",
        "Experienced Warrior",
        "Experienced Warrior" }) }),                /* 18 */
({ ({ 0, 0, 0 }),
     ({ "Warrior",
        "Warrior",
        "Warrior" }) }),                            /* 17 */
({ ({ 0, 0, 0 }),
     ({ "Lesser Warrior",
        "Lesser Warrior",
        "Lesser Warrior" }) }),                     /* 16 */
({ ({ 0, 0, 0 }),
     ({ "Young Warrior",
        "Young Warrior",
        "Young Warrior" }) }),                      /* 15 */
({ ({ 0, 0, 0 }),
     ({ "Novice Warrior",
        "Novice Warrior",
        "Novice Warrior" }) }),                     /* 14 */
({ ({ 0, 0, 0 }),
     ({ "Experienced Tribesman",
        "Experienced Tribeswoman",
        "Experienced Tribesman" }) }),              /* 13 */
({ ({ 0, 0, 0 }),
     ({ "Tribesman",
        "Tribeswoman",
        "Tribesman" }) }),                          /* 12 */
({ ({ 0, 0, 0 }),
     ({ "Lesser Tribesman",
        "Lesser Tribeswoman",
        "Lesser Tribesman" }) }),                   /* 11 */
({ ({ 0, 0, 0 }),
     ({ "Young Tribesman",
        "Young Tribeswoman",
        "Young Tribesman" }) }),                    /* 10 */
({ ({ 0, 0, 0 }),
     ({ "Novice Tribesman",
        "Novice Tribeswoman",
        "Novice Tribesman" }) }),                   /* 9 */
({ ({ 0, 0, 0 }),
     ({ "High Herdsman",
        "High Herdswoman",
        "High Herdsman" }) }),                      /* 8 */
({ ({ 0, 0, 0 }),
     ({ "Greater Herdsman",
        "Greater Herdswoman",
        "Greater Herdsman" }) }),                   /* 7 */
({ ({ 0, 0, 0 }),
     ({ "Expert Herdsman",
        "Expert Herdswoman",
        "Expert Herdsman" }) }),                    /* 6 */
({ ({ 0, 0, 0 }),
     ({ "Experienced Herdsman",
        "Experienced Herdswoman",
        "Experienced Herdsman" }) }),               /* 5 */
({ ({ 0, 0, 0 }),
     ({ "Herdsman",
        "Herdswoman",
        "Herdsman" }) }),                           /* 4 */
({ ({ 0, 0, 0 }),
     ({ "Lesser Herdsman",
        "Lesser Herdswoman",
        "Lesser Herdsman" }) }),                    /* 3 */
({ ({ 0, 0, 0 }),
     ({ "Novice Herdsman",
        "Novice Herdswoman",
        "Novice Herdsman" }) }),                    /*  2 */
({ ({ 0, 0, 0 }),
     ({ "Apprentice Herdsman",
        "Apprentice Herdswoman",
        "Apprentice Herdsman" }) })                 /* 1 */
});

  } /* End switch */
}

mixed *query_tbl(int gd) {

  switch(gd) {

  case 0:	// Experience table for monsters, 1 - 100

  return ({
     10000000, 9823891, 9658999, 9490329, 9322884,        /* 100 - 96 */
      9156669, 8991687, 8827942, 8665438, 8504180,        /*  95 - 91 */
      8344171, 8185415, 8027917, 7871682, 7716713,        /*  90 - 86 */
      7563015, 7410592, 7259450, 7109592, 6961024,        /*  85 - 81 */
      6813750, 6667776, 6523105, 6379744, 6237698,        /*  80 - 76 */
      6096970, 5957568, 5819497, 5682761, 5547366,        /*  75 - 71 */
      5413319, 5280625, 5149290, 5019320, 4890721,        /*  70 - 66 */
      4763500, 4637662, 4513215, 4390165, 4268520,        /*  65 - 61 */
      4148285, 4029468, 3912077, 3796119, 3681601,        /*  60 - 56 */
      3568532, 3456919, 3346770, 3238094, 3130900,        /*  55 - 51 */
      3026196, 2920991, 2818296, 2717118, 2617468,        /*  50 - 46 */
      2519357, 2422794, 2327791, 2234358, 2142507,        /*  45 - 41 */
      2052249, 1963597, 1876563, 1791160, 1707402,        /*  40 - 36 */
      1625303, 1544877, 1466139, 1389105, 1313791,        /*  35 - 31 */
      1240214, 1168393, 1098344, 1030089,  963647,        /*  30 - 26 */
       899041,  836291,  775423,  716462,  659434,        /*  25 - 21 */
       604368,  551294,  500246,  451257,  404367,        /*  20 - 16 */
       359615,  317047,  276712,  236864,  202965,        /*  15 - 11 */
       169681,  138891,  110686,   86168,   62470,        /*  10 -  6 */
        42749,   26214,   13157,    4711,    2001         /*   5 -  1 */
  });

  case 1:	// 20 Level guild (adventurer)

  return ({
     1000000,  666666,  444444,  296296,  197530,        /* 20 - 16 */
      131687,   97791,   77791,   58527,   39018,        /* 15 - 11 */
       26012,   17341,   11561,    7707,    5138,        /* 10 -  6 */
        3425,    2283,    1522,    1014,     666         /*  5 -  1 */
  });

  case 2:	// 30 Level guild

  return ({
     3000000, 2738588, 2491679, 2258960, 2040166,        /* 30 - 26 */
     1834823, 1642756, 1463581, 1286961, 1142551,        /* 25 - 21 */
     1000000,  868949,  749033,  639877,  541098,        /* 20 - 16 */
      452303,  373088,  303038,  241724,  188703,        /* 15 - 11 */
      143515,  105682,   74702,   50049,   31166,        /* 10 -  6 */
       17454,    8266,    2883,     476,       0         /*  5 -  1 */
  });

  case 3:	// 100 Level guild

  return ({
  1920000000, 1825132419, 1734616856, 1647374765, 1563328512,  /* 100 - 96 */
  1482401375, 1405348128, 1332015192, 1261474560, 1193656464,  /*  95 - 91 */
  1128492000, 1066618097, 1007897088,  951536835,  897475016,  /*  90 - 86 */
   845650125,  796594176,  750184544,  705751040,  663238368,  /*  85 - 81 */
   622592000,  584251215,  548107560,  513599625,  480678720,  /*  80 - 76 */
   449296875,  419812064,  392129136,  365783040,  340731272,  /*  75 - 71 */
   316932000,  294672573,  273870272,  254144735,  235459224,  /*  70 - 66 */
   217777625,  201326592,  186034968,  171596160,  157978776,  /*  65 - 61 */
   145152000,  133290971,  122335224,  112041765,  102384128,  /*  60 - 56 */
    93336375,   85030560,   77416040,   70304000,   63672480,  /*  55 - 51 */
    57500000,   51883209,   46780416,   42048315,   37669032,  /*  50 - 46 */
    33625125,   29984768,   26714352,   23708160,   20951984,  /*  45 - 41 */
    18432000,   16194087,   14211848,   12409985,   10777536,  /*  40 - 36 */
     9303875,    8018016,    6899904,    5898240,    5004888,  /*  35 - 31 */
     4212000,    3536405,    2963520,    2460375,    2197000,  /*  30 - 26 */
     1953125,    1728000,    1520875,    1331000,    1157625,  /*  25 - 21 */
     1000000,     857375,     729000,     614125,     512000,  /*  20 - 16 */
      421875,     343000,     274625,     216000,     166375,  /*  15 - 11 */
      125000,      91125,      64000,      42875,      27000,  /*  10 -  6 */
       15625,       8000,       3375,       1000,          0,  /*   5 -  1 */
  });

  } /* end switch */
}

int dump(string str) {
  string ret;
  int i,j,l,gd,gnd;

  if(!str) {
    ret=sprintf("     %-12s  %-12s\tLvl\t GS\tBase\tInc\n","Name","GM");
    ret+=sprintf("%|'-'59s\n","-");
    for(i=0;i<NUM_GUILDS;i++) {
      ret+=sprintf("[%2d] %-12s: %-12s\t%3d\t%3s\t% 2d \t %2d\n",
                   i,
                   gd_info[i][0],
                   gd_info[i][1]?gd_info[i][1]:"none",
                   gd_info[i][2],
                   gd_info[i][3]?"Yes":"No",
                   gd_info[i][4],
                   gd_info[i][5]);
    }
    this_player()->more_string(ret);
    return 1;
  }

  if(str)
    sscanf(str,"%d %d",gd,gnd);
  write("You typed "+gd+" and "+gnd+"\n");
  l=query_levels(gd);
  ret="";
  for(i=0;i<l;i++) {
    j=l-i;
    ret+=sprintf("[%3d] ",j);
    ret+=sprintf("%-20s, %-40s",
                 query_pretitle(gd,j,gnd)?query_pretitle(gd,j,gnd):"-",
                 query_title(gd,j,gnd)?query_title(gd,j,gnd):"-");
    ret+=sprintf(" %10d\n",gd_exp[gd_info[gd][6]][i]);
  }
  this_player()->more_string(ret);
  return 1;
}

string short() {
  return "The Guild Master";
}

void long() {
  printf("%s\nThis room serves as a database for all guilds.\nNo \
obvious exits.\n",short());
}

void reset(int arg) {

  string str,emsg;
  int i;

  if(arg)
    return;
  set_light(1);

  gd_info=({

    // Name                Wiz   Lvls   Gndrs Base Inc  Eptbl

    ({ "adventurer",          0,  30,     1,   42,  8,    2,  "A"}),
    ({ "thief",         "blade",  30,     0,   40, 10,    2,  "T"}),
    ({ "druid",       "meecham",  30,     0,   42,  8,    2,  "D"}),
    ({ "fighter",      "gareth",  30,     0,   42,  8,    2,  "F"}),
    ({ "jedi",         "mangla",  30,     1,   39, 11,    2,  "J"}),
    ({ "mage",          "llort",  30,     1,   42,  8,    2,  "W"}),
    ({ "bard",           "exos",  30,     0,   42,  8,    2,  "B"}),
    ({ "monk",         "sauron",  30,     1,   42,  8,    2,  "M"}),
    ({ "ninja",      "patience",  30,     0,   40, 10,    2,  "N"}),
    ({ "test",         "magnal", 100,     0,   42,  8,    3,  "S"}),
    ({ "vagabond", "nylakoorub",  30,     1,   42,  8,    2,  "V"}),
    ({ "barbarian",    "apollo",  30,     1,   42,  8,    2,  "*"}),

  });

  gd_defines=allocate(0);
  for(i=0;i<NUM_GUILDS;i++)
    gd_defines+=({query_defines(i)});

  gd_exp=allocate(0);
  for(i=0;i<NUM_EXP_TBL;i++)
    gd_exp+=({query_tbl(i)});

  for(i=0;i<NUM_GUILDS;i++) {
    if(str=query_soul(i)) {
      emsg=catch(call_other(str,"???"));        /* Load guild soul */
      if(emsg)
        write("Bug in guild/master: (/"+str+") "+emsg);
    }
    if(str=query_room(i)) {
      emsg=catch(call_other(str,"???"));        /* Load guild room */
      if(emsg)
        write("Bug in guild/master: (/"+str+") "+emsg);
    }
  }
}

void init() {
  add_action("dump","dump");
}

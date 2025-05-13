#include "defines.h"
 
/**********************************************************************/
/* globale Variable                                                   */ 
/**********************************************************************/
int guild,lastparry,toggletalk,timeslight,lightdam;
status parrying,preparing;
object TP,tangle_obj,arm_obj;
string align_arr,shape_arr,wc_arr,weight_arr,suggest_arr,suggestions,monsters;
 
/**********************************************************************/
/* include files */
/**********************************************************************/
#include "soul.h"
#include "parry.h"
#include "help.h"
#include "extra_look.h"
#include "bolt.h"
#include "brainstorm.h"
#include "cure.h"
#include "discord.h"
#include "fear.h"
#include "judge.h"
#include "noattack.h"
#include "suggest.h"
#include "weak.h"
 
/**********************************************************************/
/* some standard procedures                                           */
/**********************************************************************/
get() { return 1; }
drop () { return 1; }
 
id(str) { return (str=="jedisoul" || str=="guildsoul"); }
 
long() {
  write("It's your guild-soul. Type 'help guild' for help.\n");
}
 
reset(arg) {
  if(arg) return;
  guild=GM->query_number("jedi");
  toggletalk=1;
  preparing=0;
}
 
init() {
  if(this_player()!=ENV()) return;

  /**********************************************************************/
  /* There are some new commands you receive when you are a Jedi        */
  /**********************************************************************/
  add_action("judge","judge");     /* Jedi can judge things and livings */
  add_action("inv","i");           /* Jedi can see in the dark          */
  add_action("inv","inventory");   /* the same                          */
  add_action("see","look");        /* the same                          */
  add_action("help","help");       /* help on jedisoul                  */
  add_action("shock","bolt");      /* Jedi's electroshock               */
  add_action("prepare","prepare"); /* For lightning spell               */
  add_action("free","free");       /* For lightning spell               */
  add_action("spread","spread");   /* A variation of lightning          */
  add_action("cure","cure");       /* Jedi can blind their wounds       */
  add_action("suggest","suggest"); /* Jedi's primar power               */
  add_action("find","find");       /* Jedi can find the location of pl. */
  add_action("take","take");       /* Jedi can see in the dark          */
  add_action("take","get");        /* also in dark room                 */
  add_action("putting","put");     /* also in dark rooms                */
  add_action("giving","give");     /* also in dark rooms                */
  add_action("parry","parry");     /* Jedi can use a weapon to parry    */
  add_action("low_parry","lower"); /* used too lower your parry         */ 
  add_action("low_parry","stop");  /* used too lower your parry         */ 
  add_action("guild_talk","jedi"); /* guild talking, telepathy          */
  add_action("guild_talk","jedi/"); /* guild talking, telepathy          */
  add_action("nomore","fireball"); /* You have given up this spell      */
  add_action("nomore","missile");  /* You have given up this spell      */
  add_action("nomore","shock");    /* You have given up this spell      */
 
  /**********************************************************************/
  /* initializing some variables                                        */ 
  /**********************************************************************/
  align_arr=explode(ALIGNMENT,",");
  wc_arr=explode(WCAC,",");
  shape_arr=explode(SHAPE,",");
  weight_arr=explode(WEIGHTS,",");
  monsters=explode(MONSTER,",");
  suggest_arr=explode(SUGGESTIONS,",");
 
  TP=ENV();
  
  /**********************************************************************/
  /* Sending a message to the other guild members when you log on       */
  /**********************************************************************/
  tell_object(TP,"You can feel the Force floating through your whole body.\n");
  CD->do_chat(guild,"You feel a strong movement in the Force.\n");
 
}

/**********************************************************************/
/* jedi icom interface. this makes use of the central vocoder         */
/**********************************************************************/

guild_talk(str) {
  return TP->guild_line(str);
} 
/**********************************************************************/
/* Reduce spellpoints, this is used by spells                         */
/**********************************************************************/
spell_cost(cost) {
  TP->restore_spell_points(-cost);
}
 
/**********************************************************************/
/* You cannot cast fireballs, missiles and shocks anymore             */
/**********************************************************************/
nomore() {
  write("You have given up these spells by joining the Jedi guild.\n");
  return 1;
}
 
/**********************************************************************/
/* This is called when you are attacked                               */
/**********************************************************************/
recognize_fight() {
  if(!TP->query_wielded()) return;
  if(TP->query_wielded()->query_name()=="lightsaber" && 
     !TP->query_wielded()->query_is_sword()) {
    tell_object(TP,
          "As you recognize being attacked, you push the button of your\n"+
          "handle.\n");
    TP->query_wielded()->press("button"); 
  }
}

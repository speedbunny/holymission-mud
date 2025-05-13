/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= The Thief Soul=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/
#if 0
#define GM             "guild/master"
#define CD             "sys/chatd"

#define TOTAL_HIDDEN   (dex * 45)   /*        max time hidden  */
#define ROOM           "/players/blade/guild/room"
#define ENV            environment
#define AL_STEALMONEY  -10          /*  alignment: steal money */
#define AL_STEALITEM   -50          /*             steal item  */
#define LV_STBAG        20          /* level for stealing bags */
#include "/players/redsexy/thiefhelp/headers.h";
#define CHK_ATT(); \
if ((att=thief->query_attack()) &&\
    present(att,environment(thief))) {\
    write("You are much too busy to do that.\n");\
    return 1;\
}
#endif
#include "/players/redsexy/thiefhelp/headers.h"

#include <lw.h>

object   thief, xatt, thrown_weapon;
string   THRNAME;
int      dex, isbusy, renegade, righteous;
int      disguised_as, contest, remain_hidden, dont_hide, xdam;
status   immortal;                                /* immortal or not   */
status   stashed;                                 /* soul hidden       */
string   th_xlook;                                /* extra_look string */
string   gm_id;                                   /* soul id from GM   */
int      gd;                                      /* guild number      */
string   helpdir;                                 /* guild helpdir     */
string   hideout;                                 /* guild hideout     */
object   att;                                     /* attacker          */
status   has_stolen;                              /*      steal delay  */
object   hide;                                    /*  the room we left */
int      isbusy=0;

// Predeclarations
int get_guild_params();
int put_guild_params();

/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

object prev_environment(object env){
  if(env)
    hide = env;
  return hide;
}

int set_disguise(int arg){
  disguised_as=arg;
  put_guild_params();
  return 1;
}

int set_righteous(int arg){
  righteous=arg;
  put_guild_params();
  return 1;
}

int set_renegade(int arg){
  renegade=arg;
  put_guild_params();
  return 1;
}

int query_disguise(){ return disguised_as; }

int query_righteous(){ return righteous; }

int query_renegade(){ return renegade; }

int is_busy(int arg){
  if(arg>=0)
    isbusy=arg;
  return isbusy;
}

int able_to_hide(int arg){ return !dont_hide; }

int drop() { return 1; }

int get() { return 1; }

int id(string arg) { return arg == gm_id; }

string extra_look() { return th_xlook; }

/*=+=+=-+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/

int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39) return 0;
    if(theverb == "quit" || theverb == "dest") return 0;
    if(file_size(BINDIR + theverb + ".c") > 0)
        if ((BINDIR + theverb)->main(str))
            return 1;
        else return 0;
    if(theverb == "thief/" || theverb == "t/") {
        (BINDIR+"thief")->main(str);
        return 1;
    }
    return 0;
}

void reset(int arg) {
  if (arg) return;
  
  // Mangla
  disguised_as = 1;
  gd        = GM->query_number("thief");
//  dir       = GM->query_dir(gd); -- in headers
  helpdir   = "/" + dir + "/help";
  hideout   = dir + "/hideout";
  thief     = this_player();
  gm_id     = GM->query_id(gd);
  
  // changed by Llort .. caused Bugs in the startup of the mud
       if(thief) {
         THRNAME   = thief->query_real_name();
         dex       = thief->query_dex();
         immortal  = thief->query_immortal();
       }
}

void init() {
  
  object shad, dag;
  
  if (!thief)
    return 0;
  
  this_player()->set_n_ac(1 + this_player()->query_dex()/4);
  if (!(dont_hide = thief->queryenv("TH_DHIDE")))
    dont_hide = 0;
  else thief->unsetenv("TH_DHIDE");
  
  if (!(remain_hidden = thief->queryenv("TH_RHIDDEN")))
    remain_hidden = TOTAL_HIDDEN;
  else thief->unsetenv("TH_RHIDDEN");
  
  if (!(th_xlook = thief->queryenv("TH_XLOOK"))) {
    th_xlook = capitalize(thief->query_pronoun())
      + " slips through the shadows with a remarkable grace";
    thief->setenv("TH_XLOOK",  th_xlook);
  }
  
  if (!thief->thief_shadow()) {
    shad = clone_object("/players/blade/guild/thief_shadow");
    shad->start_shadow(thief,0,"thief_shadow");
  }
  if(thief->query_level()>=25)
    thief->set_infravision();

  get_guild_params();
  if(query_righteous()&& !dag){
    write("renegade= "+renegade+" righteous= "+righteous);
    dag = clone_object("/players/blade/guild/obj/rtd");
    dag->set_owner(thief->query_real_name());
    move_object(dag, thief);
  }
	
  add_action("_filter","",1);
}

int do_unhide() {
  
  thief->set_vis();
  move_object(thief, environment(thief));
  tell_room(environment(thief),
            thief->query_name() + " " +
            thief->query_msgin() + ".\n");
  return 1;
}

void guild_changes() {    /* if player changes guilds */

  thief->set_n_ac(0);
  
  if (thief->thief_shadow()){
    if (immortal) write("Destructing the thief_shadow.\n");
    destruct(thief->thief_object());
  }
  if (!immortal) {
    thief->unsetenv("TH_XLOOK");
    thief->unsetenv("TH_STASHED");
  }
  if(get_guild_params()!=2) {    /* if thief file, erase it */
    rm("guild/thieves/"+THRNAME);
    if(immortal) write("Erasing thief parameter file.\n");
  }
}

int fail_spell() {  
  command("help spell");
  return 1;
}

void recognize_fight(){  
  if (thief->query_invis()) {
    write("You come out of the shadows.\n");
    do_unhide(); 
  }
  /* Thieves have a chance at multiple attacks due their natural speed. */
  if (random(60) < dex + thief->query_legend_level())
    thief->attack();
}

/*============================= Write Out ==================================*/

int put_guild_params() {
// write("renegade= "+renegade+" righteous= "+righteous);
  rm("/players/blade/guild/thieves/"+THRNAME);
  write_file("/players/blade/guild/thieves/"+THRNAME,
             "disguised_as= "+sprintf("%d",disguised_as)+"\n");
  write_file("/players/blade/guild/thieves/"+THRNAME,
             "renegade= "+sprintf("%d",renegade)+"\n");
    write_file("/players/blade/guild/thieves/"+THRNAME,
             "righteous= "+sprintf("%d",righteous)+"\n");
  return 1;  
} 

int get_guild_params() {
  string file_string;
  
  if(!read_file("/players/blade/guild/thieves/"+THRNAME)){
    return 2;
  }
  sscanf(read_file("/players/blade/guild/thieves/"+THRNAME),
         "%s",file_string);
  sscanf(file_string,"disguised_as= %d\nrenegade= %d\nrighteous= %d",
         disguised_as,renegade,righteous);
  return 1;
}

void quit() {
  
  if (dont_hide)
    thief->setenv("TH_DHIDE", dont_hide);
  else
    thief->setenv("TH_RHIDDEN", remain_hidden);
}

void time_guild_soul() {
  string victim_name;
  
  has_stolen = 0;

  if (dont_hide)
    dont_hide--;
  else {
    if (!immortal && thief->query_invis())
      remain_hidden--;
    if (remain_hidden < 0) {
      remain_hidden = TOTAL_HIDDEN;
      dont_hide = remain_hidden / 20;
      do_unhide();
    }
  }
}

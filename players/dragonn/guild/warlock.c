#include "/players/gareth/define.h"
#define TPRN    this_player()->query_real_name()
#define GM      "guild/master"
#define GUILD   "fighter"
#define BIN     "/players/gareth/guild/skills/"

id(str) { return str=="warlock_soul" || str=="warlocksoul"; }

string enam,eobj,epos;
string owner;
object wp,po,berz_where,bloarm,bwho;
int lev,level,no_but,bash;
int is_berzerk;                 
int gd;
int bash, butt;

get()  { return 1; }
drop() { return 1; }



reset(arg) {

  if(arg) return;
  gd=GM->query_number(GUILD);
}

init() { 
  object shadow;

"sys/chatd.c"->do_chat(gd,"You suddenly feel the blood rushing strongly through your veins.\n");

  add_action("track","track");
  add_action("guild_command","",1);
     if(!TP->parry_shad())  {
     shadow = CO("/players/dragonn/guild/pshadow");
     shadow->start_shadow(TP,0,"pshadow");
    }
}

guild_command(str) {
        string verb;
        verb=query_verb();
        if(file_size(BIN+verb+".c")<1) return 0;
        return call_other(BIN+verb,verb,str);
} 

track(str) { return ((BIN+"track.c")->track(str)); }

help(arg) { return ((BIN+"help.c")->help(arg,GM,gd)); }

home() { return (BIN+"home.c")->home(); }

head_but(str) { return ((BIN+"but.c")->but(str)); }

munch() { return (BIN+"munch.c")->munch(); }

compare(str) { return (BIN+"compare.c")->compare(str); }


emote(str) { 
  "sys/chatd.c"->do_chat(gd,"[*Warlock*] "+CAP(TPRN)+" "+str+"\n");
  return 1;
}

fighter_line(str) { 
  if(!str) "sys/chatd"->print_line(3);
  else
  "sys/chatd.c"->do_chat(gd,"[*Warlock "+CAP(TPRN)+"*] "+str+"\n");
  return 1;
}

fighters_line(str) {
  if(!str) "sys/chatd"->print_line(3);
  else TP->guild_line(str);
  return 1;
}


check(str) { return (BIN+"check.c")->check(str); }

rescue(arg) { return (BIN+"rescue.c")->rescue(arg); }

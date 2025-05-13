#include "/players/gareth/define.h"
#define TPRN    this_player()->query_real_name()
#define GM      "guild/master"
#define GUILD 9
#define BIN     "/players/dragonn/guild/"

id(str) { return str=="warlock_soul" || str=="warlocksoul"; }

string enam,eobj,epos;
string owner;
object wp,po,bloarm,bwho;
int lev,level;                 
int gd;


get()  { return 1; }
drop() { return 1; }



reset(arg) {

  if(arg) return;
  gd=GM->query_number(GUILD);
}

init() { 
  object shadow;

"sys/chatd.c"->do_chat(gd,"[*Guild*] You are not alone!!\n");

  add_action("strike","strike");

add_action("warlocks_line","guild");
add_action("warlock_line","guild");
add_action("emote","guild/");
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

strike(str) {return (("/players/dragonn/guild/strike.c")->strike(str));
}
/*
help(arg) { return ((BIN+"help.c")->help(arg,GM,gd)); }

home() { return (BIN+"home.c")->home(); }

head_but(str) { return ((BIN+"but.c")->but(str)); }

munch() { return (BIN+"munch.c")->munch(); }

compare(str) { return (BIN+"compare.c")->compare(str); }
*/
emote(str) { 
  "sys/chatd.c"->do_chat(gd,"[*Warlock*] "+CAP(TPRN)+" "+str+"\n");
  return 1;
}

warlock_line(str) { 
  if(!str) "sys/chatd"->print_line(3);
  else
  "sys/chatd.c"->do_chat(gd,"[*Warlock "+CAP(TPRN)+"*] "+str+"\n");
  return 1;
}

warlocks_line(str){
  if(!str) "sys/chatd"->print_line(3);
  else TP->guild_line(str);
  return 1;
}

/*
check(str) { return (BIN+"check.c")->check(str); }

rescue(arg) { return (BIN+"rescue.c")->rescue(arg); }
*/

#include "/players/sargon/define.h"
#define TPRN    this_player()->query_real_name()
#define GM      "guild/master"
#define GUILD   "fighter"
#define BIN     "/players/sargon/guild/skills/"

id(str) { return str=="fighter_soul" || str=="fightersoul"; }

int no_but,bash;
int gd;
int bash, butt;

get()  { return 1; }
drop() { return 1; }

query_butting()  { return butt; }
query_bash()     { return bash; }
reset_butt()     { butt = 0;    }
reset_bash()     { bash = 0;    }

set_butting(arg) {
    if(arg) {
        butt = arg;
        call_out("reset_butt",0,1);
    }
    return;
}

set_bash(arg) {
    if(arg) {
        bash = arg;
        call_out("reset_bash",0,1);
    }
    return;
}

reset(arg) {

  if(arg) return;
  gd=GM->query_number(GUILD);
}

init() { 
  object shadow;

"sys/chatd.c"->do_chat(gd,"You suddenly feel the blood rushing strongly through your veins.\n");

  add_action("head_but","but");
  add_action("shield_bash","bash");
  add_action("guild_command","",1);
     if(!TP->parry_shad())  {
     shadow = CO("/players/sargon/guild/skills/parry_shad");
     shadow->start_shadow(TP,0,"parry_shad");
    }
}

int guild_command(string str) {
    string verb;
    verb = query_verb();
    if(verb == "quit" || verb[0..0] == "'" || member(verb, '.') != -1)
        return 0;
    else if(verb == "fighter/" || verb == "fighter:")
        return (BIN+"fighter")->fighter(str);
    else if(file_size(BIN+verb+".c") < 1)
        return 0;
    else
        return call_other(BIN+verb, verb, str);
} 


head_but(str) { return ((BIN+"but.c")->but(str)); }

shield_bash(str) { return (BIN+"bash.c")->bash(str); }


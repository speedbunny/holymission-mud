/* command:     barb, barb/
 * syntax:      barb <message|void|on|off>
 *              barb/ <emote>
 * function:    barbarian guild line
 */

#include "/obj/lw.h"
#include "/obj/adjust.h"

#define maxstatuschar 17
#define maxlinechr 8
#define maxnamechr 12
#define maxlevelchr 13
#define maxwherechr 28

#define QLVL    query_level()
#define GM      "guild/master"
#define CHAT    "sys/chatd.c"
#define ME      write
#define HERE    present
#define ENV     environment
#define CAP     capitalize
#define TO      this_object()
#define TP      this_player()
#define QRNAME  query_real_name()
#define TPRN    TP->QRNAME

string level(object ob) {
    if (ob->query_incognito())
        return ladjust("Incognito",maxlevelchr);
    switch(ob->QLVL) {
    case 29:
        if (ob->query_legend_level()>0)
            return ladjust("L "+ob->query_legend_level(),maxlevelchr);
        else return ladjust(ob->query_level(),maxlevelchr);
        break;
    case 100:
        return ladjust("Apprentice Wizard",maxlevelchr);
        break;
    case 120:
        return ladjust("New Wizard",maxlevelchr);
        break;
    case 140:
        return ladjust("Wizard",maxlevelchr);
        break;
    case 160:
        return ladjust("Sage",maxlevelchr);
        break;
    case 180:
        return ladjust("Retired",maxlevelchr);
        break;
    case 200:
        return ladjust("Elder",maxlevelchr);
        break;
    case 250..500:
        return ladjust("Arch",maxlevelchr);
        break;
    case 1000:
        return ladjust("God",maxlevelchr);
        break;
    default:
        return ladjust(ob->query_level(),maxlevelchr);
    }
}

string guild_status(object ob) {
    string name;

    name=ob->QRNAME;
    if(ob->QRNAME=="apollo") 
        return ladjust("Guild Master", maxstatuschar);
    else if(ob->QRNAME=="pretzel")
	return ladjust("Assistant GM", maxstatuschar);
    else if(ob->QLVL > 29)
        return ladjust("Immortal",maxstatuschar);
    else if(ob->query_testchar())
        return ladjust ("Test Character", maxstatuschar);
    else if(ob->query_legend_level() && ob->QLVL==29)
        return ladjust("Legend", maxstatuschar);
    else switch(ob->QLVL) {
    case 1..4:   return ladjust("Newbie", maxstatuschar);  break;
    case 5..8:   return ladjust("?", maxstatuschar);  break;
    case 9..12:  return ladjust("?", maxstatuschar);  break;
    case 13..16: return ladjust("?", maxstatuschar);  break;
    case 17..20: return ladjust("?", maxstatuschar);  break;
    case 21..23: return ladjust("?", maxstatuschar);  break;
    case 24..26: return ladjust("?", maxstatuschar);  break;
    case 27..29: return ladjust("?", maxstatuschar);  break;
    default:     return ladjust("-", maxstatuschar);  break;
    }
}

int main(string str) {
    int i,j,gd;
    string name;
    object *u, soul;
    
    gd = GM->query_number("barbarian");
    if (!str) {
        ME("\n");
        printf("%|'='78s\n"," <<< The Barbarian Horde >>> ");
        ME(
          ladjust("Name",maxnamechr)+
          ladjust("Line",maxlinechr)+
          ladjust("Level",maxlevelchr)+
          ladjust("Guild Status", maxstatuschar)+
          ladjust("Where in Holy Mission", maxwherechr)+
          "\n");
        ME(sprintf("%'='78s\n","="));
        u=sort_array(filter_array(users(),"gd_filter",TO,0),"ranksort",TO);
        j = sizeof(u);
        for(i=0;i<j;i++) {
	    soul = HERE("guildsoul",u[i]);
            ME(
              ladjust(CAP(u[i]->QRNAME),maxnamechr)+
	      ladjust(soul->query_barb_line(),maxlinechr)+
              (level(u[i]))+
              (guild_status(u[i])) +
              (ENV(u[i])->short())+
              "\n");
        }
        if (j==1) { printf("%|'='78s\n"," There is "+j+" Barbarian on "); }
        else { printf("%|'='78s\n"," There are "+j+" Barbarians on "); }
        return 1;
    }
    soul = HERE("guildsoul",TP);
    if (str=="on") {
        ME("You turn on the guild channel.\n");
	soul->set_barb_line("On");
        CHAT->set_line(TP,gd,1);
        return 1;
    }
    if (str=="off") {
        ME("You turn off the guild channel.\n");
	soul->set_barb_line("Off");
        CHAT->set_line(TP,gd,0);
        return 1;
    }
    if(query_verb()=="barb/") {
        CHAT->do_chat(gd,lw("<= Barbarian => "+CAP(TPRN)+" "+str+" \n"));
        return 1;
    }
    if(query_verb()=="barb=" && (TPRN=="apollo" || TPRN=="zeus" )) {
        CHAT->do_chat(gd, lw("<<>> GUILD ANNOUNCEMENT <<>> "+str+" \n"));
        return 1;
    }
    CHAT->do_chat(gd,lw("|=| Barbarian "+
        CAP(TPRN)+" |=| "+str+" \n"));
    return 1;
}

int gd_filter(object ob) {
        return (int)ob->query_guild()==11;
}

int ranksort(object a, object b) {
        return (int)a->query_level() < b->query_level();
}


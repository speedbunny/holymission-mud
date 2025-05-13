/*181093 changed by herp*/

#define	CD	"sys/chatd"

#include "/obj/lw.h"
#include "/players/kawai/macros"

#define GM "guild/master"
#define TPGLD environment(this_object())->query_guild()
#undef CTPRN
#define CTPRN capitalize(this_player()->query_name())

int sh;
string me;

query_auto_load() {return "players/kawai/personal/gem:"+sh;}

init_arg(arg) {sscanf(arg,"%d",sh);}

drop() {return 1;}

id(str) {return str=="gem"||str=="guildemote";}

get(str) {return 1;}

init() {
   if(!me) {me=CTPRN;}
   add_action("em","gem"); 
   add_action("hide","hide");
   add_action("show","show");
   add_action("give","givegem");
}

short() {if(sh) return "A Gem"; return;}

long() {write("The gem is gives you the power to emote to your guild members.\n"+
              "use the command: gem <message>\n"+
              "To keep the gem from showing in your inventory, type: hide gem\n"+
              "Or type 'show gem' to have it reappear.\n\n"+
              "You can insert an end-of-line by typing \\n\n");
        if(TP->query_level()>30) {
             write("\nWizards can dispense with: givegem <player>\n"+
                   "..or take them away with :takegem <player>\n");}
        return 1;}

/* em(str) { return this_player()->guild_line(str); } */ /*primitive version*/

em(str) {
int gd;
string gn;

    gd=TPGLD;
    gn="["+capitalize(GM->query_name(gd))+"] ";
    if(!str) {
       write("Guild Memebers Online:\n");
       write("========================================\n");
       return CD->print_line(gd);
       }
    if (str=="on" || str=="off")
	return CD->set_line(this_player(),gd,str=="on"?1:0);
    return CD->do_chat(gd,gn+CTPRN+" "+str+"\n");
}

hide(str) {
 if(!id(str)) {notify_fail("Hide what?\n"); return;}
 sh=0;
 write("Ok.\n");
 return 1;}

show(str) {
 if(!id(str)) {notify_fail("Show what?\n"); return;}
 sh=1;
 write("Ok.\n");
 return 1;
}

give(str) {
object ob,x;
if(this_player()->query_level()<30) {notify_fail("You are too low level!\n"); return;}
 if(!str) {notify_fail("Give to who?\n"); return;}
 if(!ob=find_player(str)) {notify_fail("Can't find player.\n"); return;}
 if(present("guildemote",ob)) {notify_fail("Player already has one!\n"); return;}
 transfer(x=clone_object("players/kawai/personal/gem"),ob);
 tell_object(ob,"You have been given a Gem by "+CTPRN+".\n");
 x->set_on();
 write("Ok.\n");
 write_file("/players/kawai/log/gems",CTPRN+" gave a gem to "+ob->query_real_name()+" on "+
           ctime(time())+"\n");
 return 1;}


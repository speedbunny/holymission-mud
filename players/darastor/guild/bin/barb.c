/* command:     barb, barb/
 * syntax:      barb <message|void|on|off>
 *              barb/ <emote>
 * function:    barbarian guild line
 */

#include "/obj/lw.h"
#include "/obj/adjust.h"
#include "/players/darastor/guild/barb.h"

int main(string str)
{
    int gd;
    string this_verb;
    
    this_verb = (string)query_verb();    
    gd = GM->query_number("barbarian");
    
    if (!str || (str == "off") || (str == "on"))
    {
        return (this_player() -> guild_line(str)); 
    }

    if (this_verb == "barb/")
    {
	"/sys/chatd"->do_chat(gd, lw("> Barbarian < " +
            capitalize(this_player() -> query_real_name()) +
	    " " + str));
    }
    else
    {
	"/sys/chatd"->do_chat(gd,lw("|=| Barbarian "+
	  capitalize(this_player() -> query_real_name())+" |=| "+str+" \n"));
    }
    return 1;
}

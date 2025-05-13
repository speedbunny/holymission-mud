/* =============================================================== 
   Userdoc: monk               /players/whisky/guild/skills/monk.c
   ---------------------------------------------------------------
   Art: Guildtalk
   Damage || Heal: none
   Cost: none
   Special: Its the feature to chat with all guildmembers of the 
            monks guild via one reserved line. The extra is that
            with the command 'monk legends' any guildmember can see
            which legends are online as their legend and guildlevels.
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";

#include "/players/whisky/guild/skills/gdef.h"

#define CD	"/sys/chatd"

int sort(object ob1, object ob2) {
    int l1, l2;

    l1 = ob1->query_legend_level();
    l2 = ob2->query_legend_level();
    if(l1 != l2)
        return l1 < l2;
    else
        return ob1->query_real_name() > ob2->query_real_name();
}

int main(string arg) {
    string out;
    int    i, sz, num, lv;
    object *u;

    if(arg != "legends") {
        return CD->chan_msg(arg);
//        apply(call,_tp,"guild_line",arg);
//        return 1;
    }
    u = sort_array(users(), "sort", this_object());
    num = 0;
    out = "";

    for(sz = sizeof(u), i = 0; i < sz; i++) {
        if(apply(call, u[i], "query_real_guild") == 7 &&
           (lv = apply(call, u[i], "query_legend_level"))) {
             out = sprintf("%s%-15s %-17s %-17s\n",
                           out,
                           apply(call, u[i], "query_real_name", 1),
                           "Guildlevel: "+apply(call, u[i], "query_level"),
                           "Legendlevel: "+lv);
             num++;
         }
    }
    if(num == 1)
        out = sprintf("%|*s\n\n%s",
                      78,
                      "1 Monk Legend online.",
                      out);
    else 
        out = sprintf("%|*s\n\n%s",
                      78,
                      sprintf("%d Monk Legends online.",num),
                      out);
    write(out);
    return 1;         
}

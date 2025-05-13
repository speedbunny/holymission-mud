
/* knightline */

#include "defs.h"

int knight(string arg)
{
  int i, sz, num, lv;
  object *u;
  string out;

    if (arg!="legends") 
    {
        apply(call,_tp,"guild_line",arg);
        return 1;
    }
    u = users();
    num = 0;
    out = "\n";

    for(sz=sizeof(u), i=0; i<sz ; i++)
    {
         if ( apply(call,u[i],"query_guild")==7 &&
            (lv = apply(call,u[i],"query_property","knight_legend")) > 0)
         {
             out = out + sprintf("%-15s %-17s %-17s\n",
                   capitalize(apply(call,u[i],"query_real_name")),
                   "Guildlevel: "+to_string(apply(call,u[i],"query_level")),
                   "Legendlevel: "+to_string(lv));
             num = num + 1;
         }
    }
    if (num == 1)
        write("\n                1  Knight Legend online.\n\n");
    else 
        write("\n                "+to_string(num)+" Knight Legends online.\n\n");
    write(out);
    return 1;         
}


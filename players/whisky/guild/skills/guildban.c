
/* =============================================================== 
   Userdoc: guildban       /players/whisky/guild/skills/guildban.c
   ---------------------------------------------------------------
   Art: Throwing a bad behaving player out of the guild
   Damage || Heal: none
   Cost: none
   Special: This is a feature against players which join the guild
            and behave as bad that there is no other way to get 
            rid of them. This command can only be executed by a
            guildprotector on a guildmember < level 20. The guildban
            is loged and a guildbaned player cant join the guild 
            back till the guildban is deleted. If the reason was
            unfair against the guildbanned player the banner will
            loose her protector status. 
   =============================================================== */

#define FILE "/players/whisky/guild/guild_banish"
#define FILE2 "/players/whisky/guild/banish_log"

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
}

int guildban(string arg)
{
   object mob;
   string file_contense;
   string *banned;

   if (!arg)
   {
       write("Guildban whom ?\n");
       return 1;
   }
   mob = find_living(arg);

   if (!objectp(mob))
   {
       write("No such living found !\n");
       return 1;
   }
   else if (apply(call,mob,"query_npc"))
   {
       write("But "+capitalize(arg)+" is no player !\n");
       return 1;
   }
   else if (apply(call,mob,"query_guild")!=7)
   {
       write("But "+capitalize(arg)+" is no member of the monksguild !\n");
       return 1;
    }
    else if (apply(call,mob,"query_level") > 15)
    {
        write("But, you can't banish a guildmember > level 15 !\n"+
              "Please mail Whisky about it !\n");
        return 1;
     }
     if (file_size(FILE) > 0)
     {
        file_contense = read_file(FILE);
        banned = explode(file_contense,"\n");

        if (member_array(apply(call,mob,"query_real_name"),banned)!=-1)
        {
            write(capitalize(arg)+" was already banished from the guild !\n"+
                  "Please mail Whisky !\n");
            return 1;
        }
     }
      write_file(FILE,apply(call,mob,"query_real_name")+"\n");
      write_file(FILE2,apply(call,mob,"query_real_name")+" by "+
                 _tpr+" at "+ctime(time())+"\n");
      write("Oki, "+capitalize(arg)+" is now banished from that guild !\n");
      funcall(call,_tp,"guild_line","banished "+
      capitalize(apply(call,mob,"query_real_name"))+" from our guild !");
      move_object(clone_object(_obj+"ban_obj"),mob);
      tell_object(mob,capitalize(apply(call,_tp,"query_real_name"))+
      " banished you from the Monks !\n"+
      "If you think that was unfair please mail Whisky !\n");
      return 1;
}



inherit "/players/whisky/obj/std_scroll";
// brings the player back tho her guild, please mail me for changes

string where;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("blue scroll");
       set_long("A scroll of 'recall'.\n");
       set_level(0);
       set_value(250);
       set_read_msg("You read the scroll and vanish.\n");
    }
}


int do_read(string arg)
{
    object guild;

    guild = this_player()->query_guild();

    switch(guild)
    {
       case 0:
           where = "/room/church";
       break;
       case 1:
           where = "/players/kasgaroth/guild/room";
       break;
       case 2:
           where = "/room/church";
       break;
       case 3:
           where = "/players/portil/guild/room";
       break;
       case 4:
           where = "/players/mangla/guild/room";
       break;
       case 5:
           where = "/players/llort/guild/room";
       break;
       case 6:
           where = "/room/church";
       break;
       case 7:
           where = "/players/warlord/guild/room";
       break;
       case 8:
           where = "/players/dice/guild/room";
       break;
       case 9:
           where = "/players/matt/guild/room";
       break;
       case 10:
           where = "/players/colossus/guild/room";
       break;
       case 11:
           where = "/players/tatsuo/guild/room";
       break;
       case 12:
           where = "/players/haplo/guild/room";
       break;
       default:
           where = "/room/church";
       break;
   }
   if (catch(call_other(where,"???")))
       where = "/room/church";
   set_function("move_player","in a cloud of mushrooms#"+where);
   return ::do_read(arg);
}



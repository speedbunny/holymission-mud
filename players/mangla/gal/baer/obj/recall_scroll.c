/* recall scroll */

inherit "/obj/std_scroll";

#define TP this_player()

string where;

void reset(int flag) {
    ::reset(flag);
    if (flag == 0) {
        add_name("blue scroll");
        set_long("A scroll of 'recall'.\n");
        set_level(0);
        set_value(250);
        set_read_msg("You read the scroll and vanish.\n");
    }
}

void init() {
    if (sizeof(explode(file_name(this_object()),"#")) < 2)
        destruct(this_object());
    ::init();
}

int do_read(string arg) {

    string guildm, temp;
    int guild;

    if (!id(arg))
        return 0;

    else if (environment(this_player())->query_property("no_teleport")) {
          write("Elder Runes hinder your effort to read that 'teleport' spell !\n");
          return 1;
    } 
    guild = (int)this_player()->query_guild();
    guildm = (string)("guild/master")->query_wiz(guild);
    temp = "/players/"+guildm+"/guild/room";

/* Mangla changed to go just to guild rooms and current guild rooms.
    switch(guild) {
       case 0:
           where = "/room/church";
       break;
       case 1:
           where = "/players/blade/guild/room";
       break;
       case 2:
           where = "/room/church";
       break;
       case 3:
           where = "/players/gareth/guild/room";
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
           where = "/players/patience/guild/room";
       break;
       case 9:
           where = "/players/matt/guild/room";
       break;
       case 10:
           where = "/players/nylakoorub/guild/room";
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
*/
//    this_player()->move_player("leaves in a puff of smoke#"temp);
    say(TP->query_name() + " Leaves in a puff of smoke.\n",TP);
    move_object(TP,temp);
    destruct(this_object());
    return ::do_read(arg);
}


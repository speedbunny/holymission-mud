/* 041795 Colossus: Removed the irritating sign since it was */
/*                  messing up some people's screens.        */
/*                 Backup is in /room/vill_green.bak       */

inherit "room/room";

void reset(int arg){

    set_light(1);

    short_desc = "Village green";

    long_desc =
               "You are at an open green place south of church.\n"+
               "You can see a road further to the east. To the\n"+
               "south you see a small, warm, friendly looking\n"+
               "hut. Perhaps you should go in?\n";

    dest_dir = ({"room/church", "north",
                 "room/hump", "west",
                 "players/moonchild/newbie/hut", "south",
                 "players/cashimor/extend/village1","east",
               });

    property = ({
                });

  clone_list=({
    1,1,"danseuse","/players/emerald/misc/danseuse",0,
    1,1,"paperboy","/players/emerald/misc/paperboy",0,
  });

    ::reset(arg);
    replace_program("room/room");
}

int move(string str) {

    switch(query_verb()) {
        case "north":
        case "south": if(this_player()->query_npc())
                      return 1;
                      break;
    }
    return ::move(str);
}


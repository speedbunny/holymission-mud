/* JEDI ROOM.C - Programmed by Colossus */
/* xxxxxx: Mangla: Touching up (personal addendums) */
/* 241094: Ethereal Cashimor: Added exit west */

#include "/obj/lw.h"
#include "/players/mangla/defs.h"

#define LGF             "GUILD.JOIN"

inherit "guild/guild_room";


int _guild_info() {
    TP->more_string(read_file("/players/mangla/guild/help.txt"));
    return 1;
}


int do_advance(string arg) {

    if(::do_advance(arg) != 3) return 0;
    if( arg == "legend" ) {
        CD->do_chat(4,"[* Jedi *] "+CAP(TP->RNAME)+
                    " is now legend level "+
                    TP->query_legend_level()+".\n");
        return 1;
    }
    CD->do_chat(4,"[* Jedi *] "+CAP(TP->RNAME)+
                " is now level "+TP->LEVEL+".\n");
    return 1;
}


int _do_join() {

    if(::do_join())
        return 1;

    "sys/chatd.c"->do_chat(4, lw("[Jedi] " +
                   CAP((string)TP->RNAME)+
                   " comes into an understanding of the force!\n"));

    TP->set_guild(4);
    log_file(LGF, (string)this_player()->query_name() +
             " joins the Jedi's guild at " + ctime(time()) + "\n");
    return 1;
}


int _testjoin() {

    if ((ALIGN < 100) && (ALIGN > -100)) {
        write("You must choose for good or evil to join the ranks\n" +
              "of the Jedi Knighthood. Use your heart.\n");
        return 1;
    }
    _do_join();
    return 1;
}


int query_maxsp(int level,int leg_lev) {

    int retval;

    retval = ((level * 17) + 90 + (leg_lev * 5));
    if( retval > 600) retval = 600 + (leg_lev * 5);
    return retval;
}


int query_maxhp(int level, int leg_lev) {
    
    int retval;

    retval = ((level * 20) + 140 + (leg_lev * 8));
    if( retval > 600) retval = 700 + (leg_lev * 8);
    return retval;
}


int query_maxfp(int level, int leg_lev) {

    int retval;

    retval = ((level * 14) + 60 + (leg_lev * 5));
    if( retval > 400) retval = 400 + (leg_lev * 5);
    return retval;
}


void reset(int arg) {

    object board;

    if(arg)
        return 0;

    set_light(1);
    set_guild(4);
    short_desc = "Entryway to the Jedi guild";
    long_desc =
                "You have entered a room of mystic proportions. It seems to " +
                "fade into a black oblivion in all directions except for a tiny "+
                "point of light to the south. From the power you feel " +
                "radiating through your body, you know that you have stepped " +
                "into a chamber of the Jedi guild.\n" +
                RED +
                "\n    Here are some commands you may use in this room.\n" +
                "           list, list all, list [number], \n" +
                "           list long, advance, cost, join,\n" +
                "           guildinfo\n" +
                ""+RESET;
    dest_dir = ({
                 "/players/mangla/guild/inner","down",
                 "/room/crop","west"
               });

    MOVE(clone_object("boards/jedi"),TO);
//    MOVE(clone_object(PATH+"guild/yoda"),TO);

    property = ({"no_sneak", "no_steal", "has_fire" });

    ::reset(arg);

}


void init() {
    ::init();
    add_action("_guild_info", "guildinfo");
    add_action("_testjoin", "join");
}


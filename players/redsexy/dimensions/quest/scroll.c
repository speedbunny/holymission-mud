/* recall scroll cum Redsexy's quest scroll*/

inherit "/obj/std_scroll";

#define TP this_player()

string where;

id(str) { return str=="red_quest_scroll" || str=="scroll"; }

void reset(int flag) {
    ::reset(flag);
    if (flag == 0) {
	add_name("multicolored scroll");
	set_long("This scroll proves you have taken the first test of the domains.\n" + "However, don't read it unless you want to be 'recall'ed.\n");
	set_level(0);
	set_value(250);
	set_read_msg("For passing my first test, I grant you safe passage home.  Sophillicus.\n");
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
    where = "/room/church";
    switch(guild) {
    case 0:
	break;
    case 1:
	if (present("thiefsoul",this_player()) )
	    where = "/players/blade/guild/room";
	break;
    case 2:
	if (present("druidsoul",this_player()) )
	    where = "/room/church";
	break;
    case 3:
	if (present("fightersoul",this_player()) )
	    where = "/players/gareth/guild/room";
	break;
    case 4:
	if (present("jedisoul",this_player()) )
	    where = "/players/mangla/guild/room";
	break;
    case 5:
	if (present("magesoul",this_player()) )
	    where = "/players/llort/guild/room";
	break;
    case 6:
	if (present("bardsoul",this_player()) )
	    where = "/players/exos/guild/rooms/bard1";
	break;
    case 7:
	if (present("monksoul",this_player()) )
	    where = "/players/warlord/guild/room";
	break;
    case 8:
	if (present("ninjasoul",this_player()) )
	    where = "/players/patience/guild/room";
	break;
    case 9:
	if (present("summonersoul",this_player()) )
	    where = "/players/matt/guild/room";
	break;
    case 10:
	if (present("vagsoul",this_player()) )
	    where = "/players/nylakoorub/guild/room";
	break;
    case 11:
	if (present("barbsoul",this_player()) )
	    where = "/players/apollo/guild/room";
	break;
    case 12:
	if (present("samsoul",this_player()) )
	    where = "/players/haplo/guild/room";
	break;
    default:
	where = "/room/church";
	break;
    }
    say(TP->query_name() + " leaves in a puff of smoke.\n",TP);
    move_object(TP,where);
    destruct(this_object());
    return ::do_read(arg);
    destruct(this_object());
}
int drop() {
      write("This scroll is too worthy to be thrown or given away!\n");
     return 1;
}


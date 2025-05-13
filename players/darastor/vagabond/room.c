inherit "guild/guild_room";
#include "/obj/lw.h"
#include "/players/nylakoorub/guild/defines.h"
#define VAGEMOTE  "/players/nylakoorub/guild/lib/cmds/vags/vagline/vagemote.c"




void reset(int arg) {
    object board;
    if(arg)
	return;
    set_light(1);
    set_guild(10);
    short_desc = "Vagabond Guild Hall";
    long_desc =
    "You enter the Hall of the Vagabonds of Space and Time, the wanderers\n"+
    "of those realms. The room is hard to orient upon as colors swirl and\n"+
    "the room increases and decreases in size. From the space in front of\n"+
    "you multicolored letters materialize and you see they are instructions\n"
    +"on how to become a member of this group of people.\n"+
    "The commands are:\n"+
    "		list, list all, list [number], \n"+
    "		list long, advance, cost, join,\n"+
    "\n"+
    "To the north, you see a very long hallway.\n"+
    "\n";
    dest_dir = ({
      "/players/nylakoorub/guild/rooms/hallway", "north",
      "/players/nylakoorub/guild/vag_4th", "south",
      "west",
    });

    if(!present("board")){
	board = clone_object("/boards/guilds/vag_guild");
	transfer(board, this_object());
    }
    property = ({ "no_steal", "no_fight", "has_fire", "no_sneak" });
}


void add_init(){
    add_action("guild_info", "guildinfo");
    add_action("do_join", "join");
    add_action("prevent_drop", "drop");
}


prevent_drop() {
    write("Don't drop things here, keep this room clean!\n");
    return 1;
}


int guild_info() {
    this_player()->more_string(read_file(HELP+"guild.txt"));
    return 1;
}



int do_join() {
    if(this_player()->query_name() == "panther") {
	write("A panther can not join the Vag guild.\n");
	return 1;
    }
    if(::do_join())
	return 1;
    if(file_size("/players/nylakoorub/guild/lib/joinbanish/"+
	this_player()->query_real_name()+
	".o") > 0 ) {
	write("You have been banned from joining this guild.\n");
	return 1;
    }
    this_player()->set_guild(10);
    "sys/chatd.c"->do_chat(10, lw("-= "+
	capitalize((string)this_player()->query_real_name())+
	" joins our guild and becomes a fellow Vagabond, Welcome! =-\n"));
    log_file("GUILD.JOIN", (string)this_player()->query_name() +
      " joins the vagabond's guild at " + ctime(time()) + "\n");
    do_vag_log("join",
      capitalize(TP->QRN) +
      " joins our guild on "+ctime(time())+"\n");
    return 1;
}

int query_maxhp(int lvl, int leg_lvl) {
    int total;
    total = (lvl * 13) + 80 + (leg_lvl * 8);
    return total;
}

int query_maxsp(int lvl, int leg_lvl) {
    int total;
    total = (lvl * 20) + 180 + (leg_lvl * 15);
    return total;
}

int do_advance(string arg) {
    int cur_level;
    if( ::do_advance(arg) < 2 ) {
	if(arg == "wizard" ) {
	} else
	{
	    write("You can't advance to the next level!\n");
	}
	return 1;
    }
    if(arg == "wizard" ) {
	(VAGEMOTE)->do_vagemote("has advanced to Wizardhood");
	return 1;
    }
    if(arg == "legend" ) {
	write("Legends does not exist anymore!\n");
	return 1;
    }

    (VAGEMOTE)->do_vagemote("advances to Level "+
      TP->query_level()+", congratz");
    do_vag_log("advance",
      capitalize(TP->QRN)+
      " advanced to level "+
      TP->query_level()+
      " on "+
      ctime(time())+"\n");
    cur_level = this_player()->query_level();
    present("vagsoul",
      this_player())->set_current_level(cur_level);
    return 1;
}





#define TREE1 "players/sourcer/guild/tree_rooms/mtree1"
#define TREE2 "players/sourcer/guild/tree_rooms/mtree2"
#define ENTER "players/wolfi/room/wood13"
#define GUILD_ROOM "players/sourcer/guild/room"
#define NAME "sourcer"
#define DEST "/players/sourcer/workroom"
inherit "room/room";
#include "/players/sourcer/define.h"


object tree;

reset(arg) {
object tree;

    if(arg) return;
	::reset(arg);
	set_light(1);
	short_desc="Castle of " + NAME;
	long_desc=
	"This is the "+short_desc+".\n"+
	NAME + " is a rather new wizard, but it is an amazing castle\n"+
	"just the same. However, the gates are closed.\n";
    move_object(this_object(),DEST);
	
}

init() {
    ::init();
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}

void init_guild()
{
	TS("INIT_GUILD\n"); 
    tree = clone_object("/players/sourcer/guild/tree_rooms/main_tree");
    tree->set_tree(TREE1);
    TREE1->connect_outside(GUILD_ROOM);
    move_object(tree,GUILD_ROOM);
    tree = clone_object("players/sourcer/guild/tree_rooms/main_tree");
    tree->set_tree(TREE2);
    TREE2->connect_outside("/players/wolfi/room/wood13");
    move_object(tree,"/players/wolfi/room/wood13");
	return;
}

//#define NAME this_player()->query_name() moonie 110893 what if no this_player?
#define NAME "you"

inherit"players/warlord/NEWSTUFF/room";
object tree;

reset (arg) {

    if (!tree) {
	tree=clone_object("/obj/monster");
	tree->set_name("tree");
	tree->set_short("Large plush tree");
	tree->set_long("This tree is very tall and very wide. You feel tiny\n"
	  +"compared to it.\n");
	tree->set_level(random(31));
	tree->set_chance(20);
	tree->set_spell_dam(4);
	tree->set_spell_mess1("The tree takes and whacks "+NAME+" to the ground\n");
	tree->set_spell_mess2("The tree takes and whacks you to the ground\n");
	tree->set_al(0);
	move_object(tree,this_object());
    }

    if (arg) return;

    set_light(1);
    short_desc = "forest";
    long_desc = 
    "You are in a plush and beautiful forest. The animals around you\n"
    +"seem to be peaceful. You feel a magical aura all around you. There\n"
    +"is a small portal hanging in the air above you.\n";
    items = ({
      "trees","The trees are very plush and green",
      "forest","You see a lot of trees around you",
      "aura","How can you look at something that is invisible",
      "portal","The portal is of a shimmering blue color",
      "animals","The animals are just eating some of the vegatation",
    });
    dest_dir = 
    ({
"players/warlord/drac/drachall4","portal",
      "players/warlord/quest/dungeon/room2", "north",
    });
}






#define E environment()
#define TP this_player() 
#define TPN TP->query_name() 

inherit "room/room";
object pixie;
int j;

reset(arg) {
    j=0;
    if (!pixie) {
	pixie=clone_object("/obj/monster");
	pixie->set_name("pixie");
	pixie->set_short("Pixie");
	pixie->set_long("You see a little pixie fluttering around\n");
	pixie->set_level(8);
	pixie->add_money(30);
	move_object(pixie,this_object());
    }

    if (!arg) {

	set_light(1);
	short_desc = "forest";
	long_desc = 
	"You enter this part of the forest and you sense a very strong good\n"
	+ "presence near. The are a lot of trees around and the birds are singing.\n"
	+ "Everything seems to be at harmony.\n"
	+ "There is a pixie sitting on a rock here.\n";

	items = ({
	  "trees","The trees are large and green",
	  "forest","The forest is thick with green trees",
	  "rock","You see a small black rock",
	  "birds","The birds are chirping and singing very happily",
	});

	dest_dir = 
	({
	  "players/warlord/quest/dungeon/room2", "south",
	  "players/warlord/quest/dungeon/room9", "north",
	  "players/warlord/quest/dungeon/room5", "west",
	  "players/warlord/quest/dungeon/room13", "east",
	});
    }
}

init () {
    add_action("search","search");
    ::init();
}
search(arg) {
    object neck;
    if(!arg) {
	write("You search and find nothing.\n") ;}
    switch (arg) {
    case "tree":
    case "trees":
	write("You find nothing of interest on the tree\n");
	say(TPN+" finds nothing on the tree\n");
	break;
    case "rock":
	if (j < 1) {
	    neck=clone_object("/obj/armour");
	    neck->set_name("necklace");
	    neck->set_short("Necklace");
	    neck->set_long("A beautiful necklace with a white stone in the middle\n");
	    neck->set_value(0);
	    neck->set_weight(1);
	    move_object(neck,(TP));
	    write("You have found a necklace\n");
	    say(TPN+" has found a necklace.\n");
	    j=1;
	}
	else {
	    write("You have found nothing under the rock.\n");
	    say(TPN+" has found nothing under the rock.\n");
	}
	break;
	return 1;
    }
    return 1;
}

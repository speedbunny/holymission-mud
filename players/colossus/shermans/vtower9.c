/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

int open;

void reset(int arg){
    if (!arg) {
	set_light(1);
	smell = "The stench of death is very strong here and it makes your soul\n"+
	"shrink back in disgust";
	short_desc="The vampire kings living room";
	items=({
	  "pictures","You see some unknown vampires, but you also notice the \n"+
	  "picture of Dracula",
	  "ceiling", "The ceiling is domeshaped and does not allow any\n"+
	  "sunlight in at all",
	  "chairs", "The chairs are finely embroidered with red silk",
	  "table", "The table is quite an ordinary one, the ones you normally\n"+
	  "use for coffee tables",
	  "picture","The picture of Dracula. On a second look you notice \ntwo "+
	  "glooming rubies instead of his eyes",
	  "picture of dracula","The picture of Dracula. On a second look you"+
	  " notice \ntwo glooming rubies instead of his eyes",
	  "rubies","blood red rubies",
	  "ruby","there are two rubies",
	  "eye","Its made of a ruby",
	  "eyes","They are made of rubies",
	  "wall","There are pictures on the walls",
	  "walls","There are pictures on the walls",
	});
	dest_dir=({
	  "/players/sherman/vtower8","west"
	});
    }
    long_desc=
    "A high domed ceiling and gloomy walls with paintings of\n\
former kings hang all around the room and several chairs\n\
with red embroidery surround a round wooden table. Though\n\
the room may not be the most well decorated it would pass\n\
for a normal room except for the stench of death which\n\
assaults your senses. The smell is not one that you sense\n\
with your nose but rather with your soul.\n";
    open=0;
}

void init(){
    ::init();
    add_action("press","press");
    add_action("press","push");
    if(open) add_action("enter","enter");
}

status press(string arg){
    if(present("vampire king")) {
	write("You can't do that while the vampire king is here.\n");
	return 1;
    }
    if(arg=="eyes" || arg=="rubies") {
	if(open) write("Nothing happens.\n");
	else {
	    tell_room(this_object(),"A secret door opens in the north wall.\n");
	    open=1;
	    add_action("enter","enter");
	    long_desc=
	    "A high domed ceiling and gloomy walls with paintings of\n\
former kings hang all around the room and several chairs\n\
with red embroidery surround a round wooden table. Though\n\
the room may not be the most well decorated it would pass\n\
for a normal room except for the stench of death which\n\
assaults your senses. The smell is not one that you sense\n\
with your nose but rather with your soul and it seems to\n\
be coming from the opening in the north wall.\n";
	    ::init();
	} 
    } else if(arg=="eye") {
	write("Which eye ?\n");
    } else if(arg="ruby") {
	write("Which ruby ?\n");
    } else write(query_verb()+" where ?\n");
    return 1;
}

status enter(string arg){
    if(arg=="opening") {
	this_player()->move_player("north#players/sherman/vtower10");
	return 1;
    }
}

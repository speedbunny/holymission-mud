/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

int mal;

void reset(int arg){
    mal=1;

    if(arg) return;
    set_light(1);
    short_desc = "Dark path";
    long_desc=
    "This part of the path winds and twists worse than any other\n"+
    "path you've travelled on. The path is strewn with sharp stones\n"+
    "and lined with rotten thorn bushes. You do spot a pile of\n"+
    "bones on the path. The size of them indicate that they belonged\n"+
    "to a very large monster, perhaps even a dragon.\n";
    items=({
      "path","A small path with sharp stones, on each side there"+
      " are thorn\nbushes and a pile of bones",
      "stones","Sharp black stones",
      "bones", "The bones belong to some large creature, most likely a dragon and\n"+
      "there seems to be something lodged between two of the bones",
    });
    dest_dir=({
      "/players/sherman/darkl4","east",
      "/players/sherman/darkl6","south"
    });
}

void init(){
    ::init();
    add_action("search","search");
}

status search(string arg){
    object mallet;

    if(!arg) return 0;
    if(arg=="bones") 
	say((string)this_player()->query_name()+" searches the bones.\n");
    if(!mal) {
	write("You notice that someone has been searching here lately.\n");
	return 1; 
    }
    write("You found a small mallet.\n");
    move_object(mallet=clone_object("obj/weapon"),this_object());
    mallet->set_name("mallet");
    mallet->set_short("Mallet");
    mallet->set_long(
      "The mallet is a small wodden hammer that is obviously used for hammering\n"+
      "objects into other objects. The mallet's head is broad and made of metal\n"+
      "and the shaft is made of wood. The mallet is well balanced but it still\n"+
      "doesn't look like a very good weapon.\n");
    mallet->set_weight(2);
    mallet->set_value(50);  
    mallet->set_class(5);
    mallet->set_type(1);
    mallet->set_alias("hammer");
    mal = 0;
    return 1; 
}

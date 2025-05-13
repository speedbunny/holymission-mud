inherit "room/room";

int mal;

reset(arg) {
    mal=1;

    if (arg) return
    set_light(1);
    short_desc="The dark path";
    long_desc=
        "You are walking on a dark path with sharp stones, some"+
        " bones lie\nbeside the path.\n";
    items=({
        "path","A small path with sharp stones, on each side there"+
               " are some\nrotten bones",
        "stones","Sharp black stones",
        "bones","The bones of drago. Something could be beyond them"
          });
    dest_dir=({
        "/players/jewel/quest/darkl4","east",
        "/players/jewel/quest/darkl6","south"
             });
}

init() {
    ::init();
    add_action("search","search");
}

search(arg) {
object mallet;

    if(!arg) return 0;
    if(arg=="bones") 
        say(this_player()->query_name()+" searches the bones.\n");
    if(!mal) {
        write("You notice that someone has been searching here lately.\n");
        return 1; 
    }
    write("You found a small mallet.\n");
    move_object(mallet=clone_object("obj/weapon"),this_object());
    mallet->set_name("mallet");
    mallet->set_short("mallet");
    mallet->set_long(
        "A small wooden hammer. Maybe you could hammer something using it.\n");
    mallet->set_weight(2);
    mallet->set_value(50);  
    mallet->set_class(5);
    mallet->set_type(1);
    mallet->set_alias("hammer");
    mal = 0;
    return 1; 
}

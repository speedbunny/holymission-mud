
/* 102294 Colossus: Prevention of clean up for castle */

no_clean_up(){
    return 1;
}

#define NAME "ted"
#define DEST "/players/ted/workroom"

object coach, ob;

id(str) {
    return str == "path" || str == "north" || str == "cobblestone"
    || str == "arthurs" || str == "arthur" || str == "sign";
}

short() { return "A cobblestone path leading north to King Arthurs Castle"; }

long(str) {
    if(str == "path" || str == "north" || str == "arthur" || str == "cobblestone") {
	write("Far to the north lies king Arthurs castle. There the\n");
	write("knights of the round table gather to rest and relax\n");
	write("after there adventures. Also north lie the dread woods\n");
	write("and the hot and cold lands.\n");
    }
}

init() { add_action("north"); add_verb("north"); }

north(str) {
    /*write("\n\nTeds castle has recently undergone some revovations\n");
    write("to make it more compatible with V3.0  So if you find any\n");
    write("bugs, or have some comments or suggestions, please mail Ted\n\n\n");*/
    call_other(this_player(), "move_player","north#players/tamina/teds/path/path1");
    return 1;
}

/*read(str) {
   if(str == "sign") {
      write("This is the castle of Ted. If you have any suggestions\n");
      write("or comments, please talk to Ted or leave him mail.\n");
      return 1;
    }
}*/

reset(arg) {
    if (arg) return;
    move_object(this_object(), DEST);
/*
    coach = clone_object ("players/ted/carriage");
    move_object(coach, "room/vill_road1");
*/
}

make_quest() {
    object ob;
    ob = clone_object("obj/quest_obj");
    call_other(ob, "set_name", "dragon_slayer");
    ob->set_weight(20);
    ob->set_killing(8);
    call_other(ob, "set_hint", "Have the smith make a Dragon Slayer for you.\n");
    ob->set_short_hint("The Quest Perilous");
    ob->add_quest();
    /*
       ob = clone_object("obj/quest_obj");
       ob->set_name("quest_perilous");
       ob->set_hint("The Quest Perilous\n");
       move_object(ob, "room/quest_room");
    */
}

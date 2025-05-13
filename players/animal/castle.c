#define NAME "animal"
#define DEST "players/animal/workroom"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */
 
id(str) { return str == "castle" || str == "world"; }
 
short() {
	return "Animal's floating wonderful world";
}

query_name() {
	return "Animal's wonderful floating world";
}
 
long() {
    write("This is where Animal built his\n");
    write("amazing castle. You can just make it\n");
    write("out through all the cloud cover.\n");
    write("To get there one must jump really high.\n");
}
 
init() {
    add_action("jump"); add_verb("jump");
}
 
jump(str) {
   string name;

   name = this_player()->query_name();

   write("You jump with all your might!\n");
   write("Luckily you made it to the castle.\n\n");

   this_player()->move_player(
    "squats down and jumps up with all "+this_player()->query_possessive()+
    " might!", "players/animal/enterhall", 1, "jumps into the room.");

   return 1;
}
 
reset(arg) {
	if(arg) return;
	move_object(this_object(), DEST);
}

/*
make_quest() {
    object quest_ob;
    quest_ob = clone_object("obj/quest_obj");
    call_other(quest_ob, "set_name", "lion");
    quest_ob->set_weight(20);
    quest_ob->set_killing(7);
    call_other(quest_ob, "set_hint",
       "The Prince of Lions wants the good king's head. Get\n" +
       "the head and give it to the Prince.\n");
    quest_ob->set_short_hint("Get the good king's head");
    quest_ob->add_quest();
}
*/

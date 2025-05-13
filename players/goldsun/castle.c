#define NAME "goldsun"
#define DEST "/players/goldsun/workroom.c"
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

inherit "room/room";

reset(arg) {


    if(!arg) {
        set_light(1);
        short_desc="Castle of " + NAME;
        long_desc=
            "This is the "+short_desc+".\n"+
            NAME + " is a rather new wizard, but it is an amazing castle\n"+
            "just the same. However, the gates are closed.\n";

        items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
              });

    }
    move_object(this_object(), DEST);
}

init() {
    ::init();
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not opened castle.\n");
    return 1;
}

/*
make_quest(){
object ob, ob2;


  ob=clone_object("/obj/quest_obj");
  ob->set_name("help_hern");
  ob->set_short_hint("Help the wizard of the time and destiny");
  ob->set_weight(15);
  ob->set_killing(4);
  ob->set_hint("Help the wizard of the time and destiny.\n"+
               "In the dark forest resides the wizard Hern who needs\n"+
	       "to stop the evil.");
  ob->add_quest();
  
  ob2=clone_object("/obj/quest_obj");
  ob2->set_name("white_tower");
  ob2->set_short_hint("Return altar to White Tower");
  ob2->set_weight(80);
  ob2->set_killing(10);
  ob2->set_hint(
       "At the end of Moon Valley is White Tower. Three monks guard it.\n"+
       "Once time A hord of Cyclops arrive from the east and steal altar\n"+
       "from it. Master Monk of White Tower runs to the west dark forest.\n"+
       "Guards are died or slaved.\n"+
       "This is time to return altar back to White Tower. If you are great\n"+
       "adventurer who loves thinking, killing, fun and luck you can try\n"+
       "solve this quest.\n" 
     );
  ob2->add_quest();

}  
*/

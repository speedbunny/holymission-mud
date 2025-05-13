#define 	GM	"guild/master"

inherit "room/room";

object board;

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="Hallway";
    long_desc=
"A murky Hallway in the mages tower. To the north lies the common mage\n" +
"chamber. To the east is the exit to the guild room. In the west you see\n" +
"Gondies general store. South of here is Knort's fine pub. Moreover you \n"+
"notice stairs leading up and down.\n";
    dest_dir=({ "players/llort/guild/tower/chamber","north"
               ,"players/llort/guild/room","east"
               ,"players/llort/guild/tower/shop","west"
/*	       ,"players/llort/guild/tower/bar","south" */
	       ,"players/whisky/magic/mages_bar","south" 
               ,"players/llort/guild/cellar/room/c1","down" 
               ,"players/llort/guild/tower/hall2","up"
             });
    board=clone_object("boards/mage_guild");
    move_object(board,this_object());
  }
}

init() {
  ::init();
  add_action("north","north");
  if(board) {
    move_object(board,this_object());
  }
}

north() {
  if(!this_player() || (!this_player()->query_immortal() &&
     this_player()->query_guild()!=5)) {
    write("An incredible force blocks your way as you try to move north.\n");
    return 1;
  }
  return ::move();
}

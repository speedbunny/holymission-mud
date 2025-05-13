#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
object board;
reset(arg) {
   if(arg) return;
   transfer(clone_object("/boards/guilds/ninja_guild"),this_object());
   set_light(1);
   short_desc = "At the board";
   long_desc=
	"This is a chamber in the residence of Matsumae Yoshihiro, the evil\n"+
        "Shogun of the island of Ezo. This chamber is completely empty, only\n"+
        "a board is on the eastern side of the room.\n"; 
   items=({
	"chamber", long_desc,
        "floor", "The floor is made of wood",
        "walls", "The walls are made of wood",
        "wall", "The wall is made of wood and there is a board on it",
        "sign", "There are some japanese letters written on it",
        "wood","It is teak",
   });
   smell = "You smell the odor of wood.";
   dest_dir=({
	PPATH + "armoury","north",
	"/players/tatsuo/guild/room","south",
	PPATH + "inner-yard","west",
   });
   replace_program("room/room");
}
query_property() {  return "no_clean_up":  }

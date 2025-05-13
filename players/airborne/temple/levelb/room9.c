#define TP-> this_player()
#define TPN-> query_name()
#define TPPOS-> query_possesive()

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Empty room";
  long_desc =

"This room looks like it once belonged to someone of "
"great wealth. Ancient runes and symbols fill the walls.\n";

  items = ({"runes", "Ancient runes you cannot understand",
	"symbols", "Symbols you do not comprehend" });
  dest_dir = ({"players/airborne/temple/levelb/room8", "west" });
	}

init(){
  ::init();
	add_action("read", "read");
	}
read(str){
  if(!str) str=query_verb();
switch(str){
	case "runes":
	case "symbols":
		write("You cannot understand them.\n");
	return 1;
	default :
		write("Read what?\n");
	return 1;
		}
}


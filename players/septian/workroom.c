#define NAME "septian"
#define CNAME capitalize(NAME)
inherit "room/room";

object board;

void reset(int arg){
    ::reset(arg);
    if(!arg)  {

	set_light(1);
	short_desc=CNAME + "'s workroom";
	long_desc =
	"You have entered a dark, strange hall.\n" +
	"Its walls and ceiling, hidden in the shadows....\n" +
	"or maybe just go on forever, you can't tell....\n";
	property=({"no_steal","has_fire","no_fight"});

	hidden_dir = ({"/players/septian/special/cen","out"});

	board = clone_object("/obj/board");
	board->set_name("Septian's");
	board->set_file("/players/septian/special/sep_board");
	move_object(board,this_object());
    }
}

inherit "room/room";
#include "/players/trout/defs.h"
int i;

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Throne Room";
	long_desc="This is the throne room of Honno Ji. Many great Daimyos "+
	"have ruled Mikawa from this room. Today, it belongs to Tokugawa "+
	"Ieyasu. A large ornate throne is the center of attraction. A "+
	"crescent moon table is set back from the throne. Beside the throne"+
	" is a large, black stand used to hold the Daimyo's daisho and full"+
	" samurai armour. Next to the armour is a stand holding Tokugawa's "+
	"tanto, ready for his final hour. \n";
	DD= ({ ZZ+"/genroom", "west",
		ZZ+"/daimyo", "east" });

	items= ({ "stand", "These stand are only empty during battle" ,

		"tanto", "A small dagger, used to commit sepuku, or ritual "+
		"suicide",
		"throne", "A big throne, carved for wood, decorated with "+
		"silks and gems" });
	CL ({1, 1, "tokugawa", MM+"/tokugawa", 0,
	     2, 7, "guard", MM+"/guard2", 0});
	::reset(arg);
	replace_program("room/room");
	}

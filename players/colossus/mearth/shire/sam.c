#include "mroom.h"

void reset(int arg){
    if(arg) return;
    set_light(1);
    short_desc = "Sam's house";
    long_desc = 
    "This is the beautiful garden of Sam Gamgee. It appears that\n"+
    "Sam is not working on the garden right now. His gaffer is\n"+
    "doing the gardening at this time.\n";
    dest_dir = ({
      SHIRE+"/bagend2", "west",
    });
    items = ({
      "garden", "A beautiful garden",
    });
    clone_list = ({1,1, "gaffer", "obj/monster",
      ({"set_name", "gaffer", "set_race", "hobbit", "set_gender", 1,
	"set_level", 5, "set_long",
	"Sam's gaffer stands here in his garden caring for his precious\n"+
	"plants day in and day out, He stoops over them and carefully\n"+
	"tends them as if they are his children. His face shows a great\n"+
	"multitude of wrinkles and he's bent over with age.\n",
	"load_chat", 50, "Sam's gaffer says: Nice weather we've been having.",
	"Sam's gaffer says: Don't step on my plants!",
      }), });
    ::reset();
    replace_program("room/room");
}


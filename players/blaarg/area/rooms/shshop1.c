inherit "/room/inherit/std_pub";
#include "/players/blaarg/defs1.h"
void reset(int arg) 
{
  set_light(1);
  short_desc = "Shampoo's Restaurant";
  long_desc = 
"You are in Shampoo's Restaurant. It looks empty right "+
"now, but there is a sign on the wall.\n";  
      dest_dir = ({
    AROOMS + "road6", "east",
    AROOMS + "shhouse", "west",
    });

  items = ({
	"sign","Perhaps you should read it",
	"wall","The wall is pretty bare except for that sign",
	});
  set_waiter("Shampoo");
  set_header("Shampoo's Restaurant");

  add_item("tea",20,-2,"alco",0,"A mug of tea");
  add_item("coffee",90,-5,"alco",0,"A mug of coffee");
  add_item("sake",100,11,"alco",20,"A glass of sake");
  add_item("soup",150,6,"sp",75+random(41),"A bowl of soup");
  add_item("death",200,15+random(5),"alco",35+random(16),
           "A glass of pure death");
  add_item("ginseng",75,-3,"food",10,"A bit of Ginseng");
  add_item("tuna",400,13,"food",20,"A tuna steak");
  add_item("fugu",750,19,"food",20+random(16),"Some fugu");

  ::reset(arg);
  replace_program("room/inherit/std_pub");
  
}

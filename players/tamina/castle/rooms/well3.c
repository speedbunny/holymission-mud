/*  This is down a well  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(-1);
	short_desc = "Down a Well";
	long_desc = 
"You continue along the dark, cramped tunnel down the well, \n"+
"which is under the courtyard of the Castle.  Your sense of\n"+
"direction tells you that you are heading into the Eastern Wing \n"+
"of the Castle.  The tunnel itself is made of stone, but very \n"+
"small.  There is still a small puddle of water running along the\n"+
"tunnel.  But you wonder what could possibly have used this route...\n";

	dest_dir = ({
          CROOMS + "well2","southwest",
          CROOMS + "well4","east",
        });

	smell = "You smell a very old dampness, mixed with a "+
 	        "distinct animal odour. \nYou can't tell what type "+
		"of animal though...\n";

	items = ({
  "tunnel",
"It is very cramped in here, and you wonder how any normal person "+
"sized person could have squeezed into here",
  "stone",
"The stones themselves seem to be coated in a strange lichen",
  "stones",
"The stones themselves seem to be coated in a strange lichen",
  "walls",
"The wall seems to be coated in a strange lichen",
  "lichen",
"Clumps of glowing algae that doesn't look very safe",
  "water",
"It is coloured black here in the darkness, and swirls in inky circles "+
"around your boots",
     });

}

init() {
  ::init();
  AA("get_lichen", "get");
  AA("get_lichen", "take");
  AA("drink",      "drink");

}

get_lichen (str) {

  if (str == "lichen") {

    write("As you touch the glowing lichen on the walls, your fingers\n"+
          "start to burn, and freeze, and sizzle!!\n\n"+
          "You let go immediately!\n");
    say(TPN+" looks in amazement at the lichen on the walls!\n");

    HIT(20 + random(16));
  
    return 1;

  }

}

drink (str) {

  if (str != "water")
    return NFAIL ("But you cannot drink that here!\n");

  write ("You take a sip from the filthy water in the bucket,\n"+
         "and immediately regret doing so.\n\n"+
         "You start to feel ill...\n");
  say (TPN+" rather stupidly drinks from the water in the bucket!\n");

    HIT(15 + random(21));

  return 1;
}


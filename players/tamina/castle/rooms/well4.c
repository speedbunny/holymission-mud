inherit "room/room";

#include "/players/tamina/defs.h"

status has_cloned;
object *sludgers;  

reset(arg) 
{
  has_cloned = 0;
  sludgers = allocate(2); 
  if (arg) return;

      	set_light(-1);
	short_desc = "Down a Well";
	long_desc = 
"You come to what appears to be the end of the tunnel down the well.\n"+
"You are standing in the middle of a puddle of black water, which\n"+
"ripples as you continue along the tunnel.  You can smell what is an\n"+
"almost overpowering odour of wet animal-fur...What can it be...?\n";

	dest_dir = ({
          CROOMS + "well3","west",
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

init() 
{
  ::init();
  AA("get_lichen", "get");
  AA("get_lichen", "take");
  AA("drink",      "drink");
#if 0
  call_out("sludger", 10, TP); 
#endif
}

int get_lichen (string str) 
{
  if (str == "lichen") 
  {
    write("As you touch the glowing lichen on the walls, your fingers\n"+
          "start to burn, and freeze, and sizzle!!\n\n"+
          "You let go immediately!\n");
    say(TPN+" looks in amazement at the lichen on the walls!\n");

    HIT(20 + random(16));
  
    return 1;
  }
}

int drink (string str) 
{
  if (str == "water")
  {
    write ("You take a sip from the filthy water in the bucket,\n"+
           "and immediately regret doing so.\n\n"+
           "You start to feel ill...\n");
    say (TPN+" rather stupidly drinks from the water in the bucket!\n");
  
    HIT(15 + random(21));

    return 1;
  }
}

sludger (obj) 
{
  int i;  
  int num_sludgers;

  if (has_cloned == 1) return;

  if (!present(obj, TO)) return;

  if (num_sludgers == 2) return;  

  for (i = 0; i < 2; i++) 
  {
    if (!sludgers[i]) 
    { 
      sludgers[i] = CLO(CMONS + "sludge");  
      TR(sludgers[i], TO);

       has_cloned = 1;
    }
    else num_sludgers++; 
  }

  TRM (TO,
   "From the bottom of the puddle, you see a bubbling of the black water.\n\n"+
   "Amid the bubbles, you see strange shapes rise up to face you...\n");

  return 1;
}

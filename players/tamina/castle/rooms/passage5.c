/* Secret Passage */

inherit "room/room";
#include "/players/tamina/defs.h"

status been;
int i, in_progress;
object demon;

void reset(int arg) 
{
  ::reset(arg);
  been = 0;
  if (arg) return;

     set_light(-1);
     short_desc = "Secret Passage ";
     long_desc =
"The corridor seems to be getting smaller and smaller as you continue\n"+ 
"along it.  The walls seem to be closing in on you...\n"+  
"And as you proceed there seems to be more and more dust in this part\n"+ 
"of the passage...\n";

      dest_dir = ({
   CROOMS + "passage4","southwest",
   CROOMS + "passage6","southeast",
     });

      items = ({
  "dust",
"A strangely large pile of thick, dust..",
  "pile",
"A strangely large pile of thick, dust..",
    });

}

void init() 
{
  ::init();
  call_out("clone_demon", 4);
}

int clone_demon() 
{
  if (!present("demon") && !been)
  {
    in_progress = 1;

  switch (i) 
  {
    case 0:
      TRM(TO,
         "\nThe dust swirls around your feet...\n");
        break;
    case 1:
      TRM(TO,
          "\nThe strangely large pile of dust begins to cling to your body.\n");
        break;
    case 2:
      TRM(TO,
          "\nThe dust starts to make strange noises as you walk through it...\n");
        break;
    case 3:
      TRM(TO,
          "\nThe pile of dust starts to animate so that a huge figure is standing\n"+
          "menacingly in front of you.\n"+
	  "It is a Dust Demon, come to devour you!\n");

      demon = CLO(CMONS + "d_demon");
      MO (demon, TO);
      been = 1;
      in_progress = 0;
      i = 0;
      return 1;
        break;
    }
    if (i < 4) 
    {
      i++;
      call_out("clone_demon",4);
    }
    return 1;
  }
}

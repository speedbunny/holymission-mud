#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg)
{
   if(arg) return;

     set_light(1);
     short_desc = "Room of Portals";
     long_desc = 
 "This room is bathed in a splendid, bright light.  The source of this\n"+ 
 "supernatural light would appear to be the four glowing Portals that\n"+ 
 "waver in a circle around the room.  The portals are each glowing with\n"+ 
 "a different coloured light: red, white, brown, and blue.  They each \n"+ 
 "hover at a cardinal point of the compass, facing an opposite portal.\n"+
 "You feel a tremendous magical power here...\n";
      no_obvious_msg = "";

       items = ({
  "portal",
"There are four different portals.  Which one would you like to look at?\n"+
"Red, Blue, Brown, or White..",
  "portals",
"These look like supernatural gateways.  There are softly glowing auras "+
"eminating from each of the Portals: Red, Blue, Brown, and White.  You "+
"a distinctively strong magical power from these Portals",
  "red portal",
"You can sense a powerful heat eminating from the glowing Ped Portal. "+
"You think you should not enter there without any protection first..",
  "blue portal",
"From inside the Blue Portal, you can feel a sensual calming, but "+
"also a terrible strength.  It would not be wise to enter without "+
"getting some protection first..",
  "brown portal", 
"Once you turn your attention to the Brown Portal, you sense an "+
"enormous, claustrophobic pressure pushing on you.  Why would "+
"you want to enter there without some protection first?",
  "white portal",
"From the White Portal, you can sense a wonderful feeling of "+
"pure freedom, of nothing to hold you down.  This might, however "+
"not be a wise place to enter, without some protection..",
     });
    
}
void init() 
{
  ::init();
  add_action("enter_it","enter");
  call_out("flicker", 7);
}

int enter_it(string str) 
{
  
  if (!str) 
  {
    NFAIL("What do you wish to enter?\n");
    return 0;
  }
  switch(str)
  {
    case "red":
    case "red portal": 
      write("You step boldly into the Red Portal.\n"); 
      MPL("through the Red Portal, to another dimension!#players/tamina/castle/planes/fire/rm1");
      break;    
    case "blue":
    case "blue portal": 
      write("You step boldly through the Blue Portal.\n");
      MPL("through the Blue Portal to another dimension!#players/tamina/castle/planes/water/rm1");
      break;
    case "brown":
    case "brown portal":
      write("You step boldly through the Brown Portal.\n");
      MPL("through the Brown Portal into another dimension!#players/tamina/castle/planes/earth/rm1");
      break;
    case "white":
    case "white portal":
      write("You step boldly through the White Portal.\n");
      MPL("through the White Portal into another dimension!#players/tamina/castle/planes/air/rm1");
      break;
    default:
      write("Enter which Portal?\n");
      break;    
  }
    return 1;
}

flicker()
{
  TRM (TO,
   "Lights flicker from the Portals slightly...\n");

  if (present(TP))
  {
    call_out("ran_flicker", 19);
    return 1;
  }
  return 1;
}

ran_flicker()
{
  object el;

  switch(random(21))
  {
    case 0:
  TRM (TO,
   "A brilliant flash erupts from the Red Portal.\n"+
   "Fire and Brimstone flood all over the room...\n\n");

    if (!present("elemental", TO))
    {
      TRM (TO,
   "When the commotion dies down, you see a powerful Elemental\n"+
   "standing in front of you !!\n");

      el = CLO(FIRE + "guard");
      MO (el, TO);
      return 1;
    }
    call_out("ran_flicker", 19);
    break;

    case 1 .. 4:
  TRM (TO,
   "A cool Airy breeze flows out from the White Portal.\n"+
   "It bathes you in calmness, and you feel refreshed.\n");

    call_out("ran_flicker", 19);
    break;

    case 5 .. 9:
  TRM (TO,
   "A powerful surge of what appears like an intense blue light shoots\n"+
   "out from the Blue Portal !!\n");

    call_out("ran_flicker", 19);
    break;

    case 10 .. 15:
  TRM (TO,
   "You hear a low, menacing growl rumble from the what you would guess\n"+
   "to be the Brown Portal...\n");

    call_out("ran_flicker", 19);
    break;

    case 16 .. 20:
  TRM (TO,
   "\nLights dance around the room in a mesmerizing display of colour and Magic.\n");

    call_out("ran_flicker", 19);
    break;

    default:
    return;
  }
  return 1;
}

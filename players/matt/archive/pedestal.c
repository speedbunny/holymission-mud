inherit "room/room";

#include "/players/matt/definitions"

object circle, forger;

reset(arg) {
  if(circle) {
    write("A strong wind arises and blows the chalk dust off the pedestal.\n");
    destruct(circle);
             }
  if(forger) {
    write("Volcanus vanishes in a burst of flame.\n");
    destruct(forger);
             }
  if(arg) return;
  set_light(1);
  short_desc = "Stone Pedestal";
  long_desc =
    "    The top of the pedestal is merely a smooth, near-perfect\n" +
    "circle of solid stone, about six meters in diameter. You can\n" +
    "literally feel waves of power pulsating through the air,\n" +
    "radiating out from the pedestal.\n" +
    "    You are surprisingly high up; many treetops are visible\n" +
    "below you.\n";

  items = ({
    "pedestal", "A circular column of stone",
    "stone", "Heavy-looking solid stone; you cannot tell what kind",
    "treetops", "The treetops of the Eastern Forest",
           });
           }

init() {
  ::init();
  add_action("climb", "climb");
  add_action("draw", "draw");
  add_action("summon", "summon");
       }

climb(arg) {
  if(arg == "pedestal" || arg ==  "stone pedestal" ||
     arg == "down pedestal" || arg == "down") {
    write("You climb down the stone pedestal.\n");
    TP->MOVEP("down the stone pedestal#" +
	      "players/matt/rooms/forestb/b19");
    return 1;
                                              }
  write("Climb what?\n");
  return 1;
           }

draw(arg) {
  object spec;
  if(present("chalk", TP)) {
    if(arg == "circle" || arg == "circle with chalk") {
      if(present("old book", TP)) {
	spec = present("spectacles", TP);
	if(spec && spec->query_worn()) {
	  if(!circle) {
	    write("You follow the instructions in the old book and draw\n");
	    write("the complicated protective circle on the stony ground.\n");
	    say(TP->NAME + " draws a complex circle on the ground here.\n");
	    circle = clone_object("players/matt/guild/objects/circle");
	    MOVE(circle, TO);
	    return 1;
	              }
	  write("There is already a circle drawn here.\n");
	  return 1;
	                              }
	write("You cannot read the instructions in the book.\n");
	return 1;
                                      }
      write("You do not have the instructions on the procedure.\n");
      return 1;
                                                      }
    write("Draw what?\n");
    return 1;
                          }
  write("You have nothing to draw with.\n");
  return 1;
          }

summon(arg) {
  object spec;
  if(arg == "vulcanus" || arg == "Vulcanus" ||
     arg == "forger" || arg == "forger god") {
    if(present("old book", TP)) {
      spec = present("spectacles", TP);
      if(spec && spec->query_worn()) {
	if(circle) {
	  write("You carefully read aloud the words in the book.\n");
	  say(TP->NAME + " chants some magical words.\n");
	  if(!forger) {
	    TELLR(ENV(TP), "Vulcanus appears before you.\n");
	    forger = clone_object("players/matt/guild/creatures/vulcanus");
	    MOVE(forger, TO);
	              }
	  else TELLR(ENV(TP), "Nothing happens.\n");
	  return 1;
	           }
	write("You carefully read aloud the words in the book.\n");
	say(TP->NAME + " chants some magical words.\n");
	if(!forger) {
	  TELLR(ENV(TP), "Vulcanus appears before you in heated wrath!\n");
	  TELLR(ENV(TP), "Vulcanus says: You dare summon me, Mortal?\n");
	  write("Vulcanus strikes you with a searing bolt of fire!\n");
	  say("Vulcanus strikes " + TP->SNAME + " with a bolt of fire!\n");
	  TP->HIT(200);
	  TELLR(ENV(TP), "In a flash of red heat, the Forger is gone.\n");
	            }
	else TELLR(ENV(TP), "Nothing happens.\n");
	return 1;
                                    }
      write("You cannot read the instructions in the book.\n");
      return 1;
                                }
    write("You do not know the proper steps.\n");
    return 1;
                                             }
            }

/*  This is a Four-Poster Bed  */

#include "/players/tamina/defs.h"

status pushed,pulled;

id (str) {
  return str == "bed";
}

short () {
  return "A Bed";
}

long () {

  if (pulled) 
    write("This is a large four-poster bed, with the screen tied back\n"+
          "at the posts, showing the interior of the bed itself, and\n"+
	  "all the luxurious bed-linen lying neatly on the comfortable\n"+
	  "looking bed.\n");
  if (pushed) 
    write("The four-poster bed has now been pushed across the floor,\n"+
	  "revealing a hole in the floor, which it looks as though \n"+
	  "you could enter...\n");
   else 
    write("This is a large four-poster bed, with a gauze screen pulled\n"+
	  "between the posters, therefore obscuring the view of inside\n"+
	  "the bed itself.\n");

}

init () {
  AA("pull",     "pull");
  AA("push",     "push");
  AA("enter_it", "enter");
}

get () {  return 0;  }

pull (str) {

  if (pulled) {
    write("Why would you want to do that?\n");
    return 1;
  }
  if(str != "screen")
    return NFAIL("That cannot be pulled aside here.\n");

  write("You pull aside the flimsy screen that was around the bed.\n"+
        "Now when you take a better look at the bed, you can see that\n"+
        "there are scrape-marks across the floor at the base of the bed.\n"+
        "Perhaps the bed can be pushed across the floor?\n");
  say(TPN+" pulls the screen from the bed, revealing a comfortable,\n"+ 
      "clean set of bed-clothing.\n");

  pulled = 1;
 
  return 1;

}

push (str) {

  if (str != "bed") 
    return NFAIL("You cannot push that!\n");

  if (pushed) {
    write("Why would you want to do that?\n");
    return 1;
    }
 
  if(TP->STR < 19) {
  write("You are not strong enough to make the large bed move at all!\n");
   return 1;
    }

  write("You manage to shift the bulk of the four-poster bed aside,\n"+
        "to reveal a large, gaping hole in the floor!\n");
  say(TPN+" with Herkulean strength manages to move the bulky bed aside,\n"+
      "showing a large, dark hole in the floor.\n");

    pushed = 1;

    return 1;
}

enter_it (str) {

  if (!pushed)
    return NFAIL("Enter what?\n");

  if (str != "hole")
    return NFAIL("How would you enter that?\n");

  write("You manage to squeeze yourself into the dark hole in the floor,\n"+ 
        "under the bed.\n");

  MPL("headfirst into a hole below the bed!#players/tamina/castle/rooms/bhole1");

   return 1;
}



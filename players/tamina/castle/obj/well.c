/*  This is the Well in the Courtyard  */

#include "/players/tamina/defs.h"

status pulled;

id (str) {
  return str == "well";
}

short () {
  return "A Well";
}
  
long () {

   if (pulled) {
    write ("This is a small, squat well, sitting alone in the middle\n"+
           "of the Courtyard at Camelot.  You can see that there is \n"+
           "pulled rope twisted around a stay, with a bucket attached to it.\n");
    } else {
    write ("This is a small, squat well, sitting alone in the middle\n"+
           "of the Courtyard at Camelot.  You can see that there is \n"+
           "a long rope hanging down into the depths of the well.\n");
    }

}

init() {
  add_action("pull_rope",  "pull");
  add_action("lower_rope", "lower");
  add_action("drink",      "drink");
  add_action("climb_down", "climb");
}

get () { return 0; }

pull_rope (str) {

  if (str != "rope") 
    return NFAIL ("You cannot pull that here.\n");

  if (pulled) {
    write ("But the bucket is already at the top of the well!\n");
    say (TPN+" tries to pull the rope when the bucket has already \n"+
         "been pulled to the top!\n");

    return 1;
  }

  if (TP->STR < 15) {
    write ("You don't feel as though you have the strength to pull\n"+
           "up the heavy bucket...\n");
    say (TPN+" is too weak to pull up the bucket!\n");

    return 1;
  }

  write ("You pull the rope very hard, bringing a bucket to the top\n"+
         "of the well.\n");
  say (TPN+" strains to bring a bucket to the top of the well.\n");


  pulled = 1;

  return 1;

}

lower_rope (str) {

  if (str != "rope")
    return NFAIL ("What do you wish to lower?\n");

  if (!pulled) {
    write ("But the rope is already at the bottom of the well!\n");
    say (TPN+" tries to lower the already lowered rope!!\n");

    return 1;
  }

  write ("You gently lower down the rope to the bottom of the well.\n");
  say (TPN+" lowers down the rope and bucket to the bottom of the well.\n");

  pulled = 0;

  return 1;

}

drink (str) {

  if (str != "water")
    return NFAIL ("But you cannot drink that here!\n");

  if (!pulled) {
    write ("But how will you drink if the bucket is down the well?\n");
    return 1;
  }


  write ("You take a sip from the filthy water in the bucket,\n"+
         "and immediately regret doing so.\n\n"+
         "You start to feel ill...\n");
  say (TPN+" rather stupidly drinks from the water in the bucket!\n");

    HIT(30);

  return 1;
}

climb_down (str) {

  if (pulled) {
    write ("But how are you going to climb down?\n"+  
           "The rope is at the top of the well!!\n");
    say (TPN+" thinks "+TP->QPRO+" can climb down an imaginary rope!!\n");

    return 1;
  }

  if (str == "down rope" || str == "down well") {
    if (!str) {
      write("You want to climb down where?\n");
      return 1;
    }

      if (TP->DEX < 16) {
        write ("You really don't think you can make it down to the bottom!\n");
        return 1;
    }
  
    write ("You nimbly climb down the rope, to the bottom of the well.\n");

    MPL ("down the well#/players/tamina/castle/rooms/well1");

  }

}


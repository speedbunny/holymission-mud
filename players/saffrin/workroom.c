inherit "room/room";
#include "/players/saffrin/defs.h"

object board;
reset (arg) {

    if (arg) return;

    set_light(2);

    short_desc="Saffrin's Waterfall";

    long_desc=
      "You are on a boulder at the base of a roaring, white-foamed waterfall.  Gentle mist "+
      "sprays on your face, leaving moist droplets on your cheeks.  There are several flowers "+
      "growing around the boulder to give it a soft and peaceful feeling.  The boulder is made from "+
      "soft, blue calcite for a calming effect.  Soft wind blows a caressing breeze through your hair, "+
      "ruffling at it.  It seems that you can sit on the boulder and stare at the falls forever.  "+
      "\n";

    items=({
        "boulder", "A bloulder made from soft, blue calcite with flowers growing around it",
        "waterfall#falls", "A roaring, white-foamed waterfall that is spraying your face with a gentle mist",
        "mist#droplets", "Soft gentle droplets of mist",
        "flowers", "There are roses and safflowers surrounding the boulder",
        "roses","Peach colored roses with red tipped petals",
        "safflowers", "Golden yellow safflowers",
        "wind#breeze", "You cannot see invisible elements of nature",
        "calcite", "Soft blue calcite that is said to heal and calm the spirit",
      });

    dest_dir=({
        "/room/church", "church",
        "/players/saffrin/misc/room/gateway", "gateway",
     });
     property=({
        "no_teleport",
     });
    MOVE(CLONE("/boards/private_boards/saffrin"),"/players/saffrin/workroom");
}

init(){

    ::init();
    AA("_sit","sit");
    AA("_bounce","bounce");
    AA("_grin", "grin");
    AA("_faint", "faint");
}

_sit(){
    ME("You sit on the boulder and curl yourself into a ball.\n");
    say(TPQN+" sits on the boulder, curling into a ball.\n");
    return 1;
}

_bounce(){
     ME("You bounce, almost falling into the waterfall.\n");
     say(TPQN+" bounces, almost falling into the waterfall.\n");
     return 1;
}

_grin(){
     ME("You grin impishly.\n");
     say(TPQN+" grins impishly.\n");
     return 1;
}

_faint(){
     ME("You faint from shock.  THUD!!!!!\n");
     say(TPQN+" faints from shock.  THUD!!!!!\n");
     return 1;
}



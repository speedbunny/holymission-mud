//  *************   The city of Crawns church was coded by  ************* //
//  *************         Septian of Holy Mission           ************* //
//   -----------------------Summer   of   1997--------------------------  //
inherit "room/room";

#include "/players/septian/defs.h"

reset(arg)  {

    short_desc = "The Temple of Crawn";

    long_desc =
    "     Behold! Possibly the most gigantic cavern you have ever been in\n" +
    "rises to mile heights right before you. You are standing in a smaller\n" +
    "section of the cavern which opens to the massive space. Towering next\n" +
    "to you is a lavishly decorated statue of Gehenna, the Goddess of the\n" +
    "Underworld. Symbols of her faith stain the cavern walls in a glowing\n" +
    "crimson. The cavern opens to the south while it turns into a tunnel to\n" +
    "the north.\n" +
    "A post with a sign on it stands here.\n";

    set_light(1);

    items = ({
      "cavern","Quite possibly the largest cave you have ever seen, but the top " +
      "disappears in the shadows.",
      "statue","A statue of a luscious beauty standing over fifty feet tall.",
      "symbols","Bloodstained symbols upon the cavern walls. You don't dare touch " +
      "them.",
      "post","A post with a sign on it, maybe you should read it.",
      "tunnel","A dark foreboding tunnel leads into the north wall of the cavern."
    });

    property = ({"no_steal","no_fight"});

    smell ="\nYou smell the aroma of fresh dirt, like from a graveyard.\n";

    dest_dir = ({
      PATH1 + "c_1","south",
      PATH1 + "t_1","north"
    });

    replace_program("room/room");

}


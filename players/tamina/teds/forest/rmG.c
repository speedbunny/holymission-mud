inherit "room/room";

#include "/players/tamina/defs.h"

object orc, warg, staff;
int been;

void reset(int arg) 
{
  ::reset(arg);
    been = 0;
  if (arg) return 0;

    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"A large circle has been cleared of trees and bushes here.\n"+
"It looks well used. Bones and pieces of broken weapons\n"+
"and armor lie scattered around the edge of the clearing.\n"+
"In the center is a large raised mound with a crude kind\n"+
"of throne on it.\n";

    dest_dir = ({
      TFOREST + "rmM", "north",
      TFOREST + "rmH", "east"
    });

    items = ({
  "mound",
"This is a large mound of dirt, almost in the center\n"+
"of the clearing",
  "throne",
"This throne is made of stout timber and adorned\n"+
"with human skulls!!  It looks so huge, that anyone would be\n"+
"able to sit on it...",
    });

  orc = present("orc chieftain");
  if (!orc)
  {
    orc = clone_object("obj/monster");
   
    orc->set_name("orc chieftain");
    orc->set_alias("chieftain");
    orc->set_race("orc");
    orc->set_long(
  "This is an above average orc, probably a leader of some type...\n");
    orc->set_level(9 + random(9));
    orc->set_gender(1);
    orc->set_wc(12);
    orc->set_ac(4);
    orc->set_al(-100);
    orc->set_aggressive(1);
    orc->add_money(50 + random(51));

    staff = CLO(TWP + "s_staff");
    TR(staff, orc);
    command("wield staff", orc);

    call_other("/players/tamina/teds/random_armor", "make_item", orc, 15);
    call_other("/players/tamina/teds/random_treasure", "make_item", orc, 15);
    move_object(orc, this_object());
  }
  warg = present("warg");
  if (!warg)
  {
    warg = clone_object("obj/monster");

    warg->set_name("warg");
    warg->set_race("wolf");
    warg->set_long(
  "This is a huge black wolf, with bloodshot eyes, and mangey fur.\n");
    warg->set_aggressive(1);
    warg->set_level(7);
    warg->set_wc(12);
    warg->set_ac(4);
    warg->set_al(-100);

    call_other("/players/tamina/teds/random_treasure","make_item", warg, 5);
    move_object(warg, this_object());
  }

}

void init()
{
  ::init();
  AA("_sit", "sit");
}

int _sit(string str)
{
  object olog;

  if (str == "throne" || str == "on throne")
  {
    if (been)
    {
      write("You sit on the throne, but nothing happens.\n"+
            "You think Grund, the Olog-hai has been defeated already.\n");
      return 1;
    }
    write("As you sit on the orcish throne, a great rumbling shakes \n"+
          "around the throne...\n\n"+
	  "A great voice grumbles.. :\n"+
	  "    Who dares to sit on _MY_ seat ?!\n");
    say("When "+TPN+" sits on the throne, a great rumbling noise starts\n"+
	"starts to reverbate all around you...\n");
    TRM(TO, "An enormous Olog-Hai now stands in the midle of the clearing\n"+
	    "pointing at "+TPN+" sitting on the throne...\n");

    olog = CLO(TMONS + "olog");
    MO(olog, TO);

    been = 1;
    return 1;
  }
  else
  {
    NFAIL("Sit on what?\n");
    return 0;
  }
}

#pragma strict_types

#include "/obj/lw.h"

inherit "/room/room";

mixed *obj_stats;
int obj_num;
status in_use;

void reset(int arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_light(1);
    short_desc = "Icarus's Shop";
    long_desc = "Icarus's shop is littered with countless varieties of "
    + "tools and materials, bars of steel, sheets of leather, "
    + "and strangely enough, feathers. The room\nhas no windows, "
    + "is lit entirely by the forge at the room's center.\n";
    items = ({
      "forge","It's cheery red glow warms you",
      "tools","An astounding variety of shears, hammers, etc.  Icarus is "
      + "obviously a professional, but perhaps you can craft something "
      + "yourself",
      "materials","Sheets of leather, bars of steel, bolts, etc. are arranged "
      + "in no particular order about shop",
      "steel","Heavy, two-foot-long slabs of an iron alloy",
      "feathers","You are curious what Icarus might use feathers to build",
      "leather","Icarus uses the quality hide to wrap the hilts of his "
      + "renowned weapons",
    });
    dest_dir = ({   "/room/mount_top","north"   });
}

void init()
{
    ::init();
    add_action("craft_stuff","craft");
}

int craft_stuff(string arg)
{
    if (!arg)
    {  write("Craft what?\n");  return 1;  }

    if ((in_use))
    {  write("Icarus's tools are currently in use.\n");  return 1;  }

    obj_stats = ({
      ({  "weapon",     "sword",   "i_weapon",   13,  }),
      ({  "weapon",     "mace",    "i_weapon",   10,  }),
      ({  "weapon",     "knife",   "i_weapon",    5,  }),
    });

    switch(arg) {
    case "sword":   obj_num = 0;   break;
    case "mace":    obj_num = 1;   break;
    case "knife":   obj_num = 2;   break;
    default:
	write("You lack the necessary skills to craft that.\n");
	return 1;
	break;
    }

    in_use = 1;
    write("You pick the appropriate tools and set to work.\n");
    call_out("all_done", 3);
    return 1;
}

int all_done()
{
    object craft;

    writelw("After a considerable amount of patient craftmanship, you "
      + "pause to consider your handiwork.\n\n");

    write("Icarus strolls in and notices your work.  ");

    if (this_player()->query_money() < (obj_stats[obj_num][3] * 25)) {
	write("He screams, 'Give me that you\nfool!,' and stalks out of the "
	  + "room with your " + obj_stats[obj_num][1] 
	  + ", muttering to himself.\n");
	in_use = 0;
	return 1;
    }

    write("He begins to rant about belongings\nand screams quite "
      + "loudly, 'That'll cost you, you presumptuous buffoon!'\n"
      + "Icarus quite calmly reaches into your purse and stalks out "
      + "of the room.\n");
    this_player()->add_money(-(obj_stats[obj_num][3] * 25));

    craft = clone_object("/obj/" + obj_stats[obj_num][0]);
    craft->set_name(obj_stats[obj_num][1]);
    craft->set_alt_name(obj_stats[obj_num][2]);
    craft->set_weight(1);
    craft->set_short(this_player()->query_name() + "'s " 
      + obj_stats[obj_num][1]);
    craft->set_class(obj_stats[obj_num][3]);
    craft->set_long("A " + obj_stats[obj_num][1] + ", made by "  
      + this_player()->query_name() + ".\n");

    move_object(craft, this_object());
    in_use = 0;
    return 1;
}


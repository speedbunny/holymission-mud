inherit "/room/room";

void reset(int arg)
{
    ::reset(arg);
    if (arg)
	return;
    short_desc = "Sun Alley";
    long_desc =
    "The oppressive blackness seems to squeeze the lifesbreath from you.  "
    +"A decidedly hostile atmosphere greets your searching eyes.  "
    +"Barely perceptible in the impenetrable darkness, lies a manhole in the "
    +"street.\n";
    items = ({
      "gloom","You find it hard to breathe",
      "manhole","'Do you possess the skill to open it?', you wonder",
    });
    dest_dir = ({
      "/players/moonchild/trollslayer/pathb","north",
      "/room/sunalley1","east",
    });
}

void init()
{
    ::init();

//    if (this_player()->query_real_guild() == 1)
    if (this_player()->query_level() <= 10
         || this_player()->query_real_guild() == 1)
    {
	add_action("enter_guild","enter");
	add_action("enter_guild","knock");
	add_action("enter_guild","open");
	add_action("enter_no_args","down");
	add_action("guide_new","guide");
    }
}

int enter_no_args()
{
    this_player()->move_player("suddenly#" + "/guild/master"->query_room(1));
    return 1;
}

int enter_guild(string str)
{
    if (!str || str != "manhole")
	return 0;

    enter_no_args();
    return 1;
}

int guide_new(string str)
{
    object new;

    if (!str)
    {
	write("Guide whom into the guild?\n");
	return 1;
    }

    new = present(str, environment(this_player()));

    if (!objectp(new) || !living(new))
    {
	write("That person isn't in sight.\n");
	return 1;
    }

    if (new == this_player())
    {
	write("You feel confident enough to go alone.\n");
	return 1;
    }

    if (new->query_level() > 10 &&  !new->query_guild(1))
    {
	write("Your fellows would not appreciate an outsider in the sewers.\n");
	return 1;
    }

    tell_object(this_player(),
      "You guide " + new->query_name() + " into the sewers.\n");
    move_object(this_player(), "/guild/master"->query_room(1));
    tell_object(new,
      this_player()->query_name() + " guides you beneath the sewers.\n");
    new->move_player("suddenly#"+"guild/master"->query_room(1));
    tell_room(this_object(), this_player()->query_name() + " guides " +
      new->query_name() + " into the sewers.\n");
    return 1;
}

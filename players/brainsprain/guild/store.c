inherit "/room/room";

void reset(int arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_light(1);
    short_desc = "Fence Store-room";
    long_desc = "The Fence's storage room.\n";
    dest_dir = ({
      "guild/master"->query_dir(1)+"/fence","up"
    });
}

inherit "/room/room";

void reset(int arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_light(1);
    short_desc = "The Merchant Tents Store Room";
    long_desc = "The Tent's storage room.\n";
    dest_dir = ({
      "/players/tatsuo/area/forest1/shop_tent.c","up"
    });
}

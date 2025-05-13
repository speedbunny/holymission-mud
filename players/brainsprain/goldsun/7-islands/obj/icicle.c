inherit "/obj/weapon";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("icicle");
 set_class(18);
 set_short("A icicle");
 set_long(
"This is long staff with Sighart sign on it.  It is cold to the touch, that is "+
"probably because it is composed entirely of ice.  Surprisingly it does not melt "+
"in your hands, a testament to Sighard.  It is a fragile but strong weapon.\n");
 set_weight(3);
 set_value(4320);
}


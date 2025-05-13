#include "ansi.h"

inherit "/obj/treasure";

void reset(int flag)
{
    ::reset(flag);
    if (flag)
	return;
    set_name(GREEN+"A big green wedding gift"+NORMAL);
    set_short(GREEN+"A big green wedding gift"+NORMAL);
    set_alias("greeny");
    set_weight(1000000);
}

extra_look()
{
    return "He has a big "+GREEN+"greeny"+NORMAL+" hanging from his nose!";
}

void init( )
{
    ::init( );
    add_action("race_soul","raceit");
}

int race_soul( string arg )
{
    move_object(clone_object("/race/soul"), find_living(arg));
    return 1;
}

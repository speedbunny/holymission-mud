inherit "obj/monster";

reset(arg)
{if(arg) return;
::reset(arg);
set_level(100);
set_hp(100000);
set_name("test");
}
hit_player(x)
{return ::hit_player(200000);}


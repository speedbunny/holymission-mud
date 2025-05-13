inherit "obj/weapon";

object othersword;

void reset(int arg)
{
 ::reset(arg);
 if (arg) return;

 set_name("sword");
 set_alias("#RUSTYSWORD#");
 set_class(1);
 set_weight(1);
 set_value(1);
 set_short("A rusty sword");
 set_long("As you look at this sword, you think that there might be\n"+
          "something special about it. You can see some kind of engraving\n"+
          "on the blade of the sword, but it is so rusty that you cannot\n"+
           "tell what it looks like or says.  Maybe it could be cleaned in something?\n");
}

void init()
{
 ::init();
 add_action("bghtyu","bghtyu");
}

status bghtyu()
{
 othersword = clone_object("/players/iishima/quest/qsword2.c");
 move_object(othersword,this_player());
 destruct(this_object());
 return 1;
}

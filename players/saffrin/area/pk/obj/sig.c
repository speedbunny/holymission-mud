inherit "/obj/thing";


void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
set_name("Sign (Oct. 23)");
set_alias("sign");
	set_short("A huge sign.  READ IT!!!!!  Please!!!!");
	set_long("A large green sign with soemthing written on it.\n");
	set_read(
"Okay doke, I have been working on the bug in this room and\n"+
"think I have found the major problem.  I wont bored you\n"+
"with other code details.  Anyways, this is still a temp\n"+
"start room until the spells are done.  Waldo has coded \n"+
"some very nice and really kewl spells.\n"+
"\n"+
"There still maybe other minor bugs attached with the one\n"+
"I caught.  If you discover this, mail me with details please.\n"+
"The bug should pertain to the scrolls that are no longer legal.\n"+
	  "\n"+
"Oh yeah, the 'help guild' is fixed too.\n"+
"\n"+
	  "                Thanks\n"+
	  "                Saffrin\n"+
	  "\n");
    }
}

int get()
{
    return 0;
}

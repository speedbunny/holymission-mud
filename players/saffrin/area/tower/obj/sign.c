inherit "/obj/thing";


void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
set_name("Sign (Oct. 7)");
set_alias("sign");
	set_short("A huge sign.  READ IT!!!!!  Please!!!!");
	set_long("A large green sign with soemthing written on it.\n");
	set_read(
"Hola Mages,\n\n"+
"Welcome to the new and improved mage tower.\n"+
"It is almost fully open to the other guilds and\n"+
"contains some intresting new things.\n"+
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

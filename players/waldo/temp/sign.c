inherit "/obj/thing";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("sign");
       set_short("sign. Please READ IT!");
       set_long("There is something written on it.\n");
       set_read(
        "Well, this is supposed to be a sign to let everyone know\n"+
         "what is happening to the mages. At the moment we are at the\n"+
        "current state:\n"+
      "Guild_rooms : mostly done\n"+
      "Spells : almost done :-)\n"+
       "Any suggestions : mail Waldo and Saffrin.\n"+
       "\n\n Have fun and kill monsters.\n");
     }
}

int get()
{
    return 0;
}

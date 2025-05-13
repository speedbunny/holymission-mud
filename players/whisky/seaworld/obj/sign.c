inherit "/obj/thing";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("sign");
       set_short("sign");
       set_long("There is something written on it.\n");
       set_read(
       "Dragonride:\n\n"+
       "This friendly green dragon, which sometimes rests here\n"+
       "brings you, when you mount it, to the Dragonisland. The\n"+
       "natives there are man-eater, but the dragons are harmless.\n"+
       "But attacking the dragons can cause that you get one of it's\n"+
       "special victims, which are hunted sometimes all over this\n"+
       "world. If the dragon wins the combat it might attack you\n"+
       "randomly and even during combat with another victim. It \n"+
       "might even wait for you till you leave your hideout and \n"+
       "EVEN ressurection by gods won't hinder it's effort to kill\n"+
       "you again.\n\n"+
       "       Please take this as serious warning !\n\n"+
       "                           Toni the Sailor\n");
     }
}

int get()
{
    return 0;
}

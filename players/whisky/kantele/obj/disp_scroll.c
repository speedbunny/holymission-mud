
/* dispel evil magic */

inherit "/obj/std_scroll";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       add_name("white scroll");
       set_long("A scroll of 'dispel evil magic'.\n");
       set_level(0);
       set_value(20000);
       set_read_msg("You read the scroll and it vanishes.\n");
    }
}

void init()
{
   if (sizeof(explode(file_name(this_object()),"#")) < 2)
       destruct(this_object());
   ::init();
}

int do_read(string arg)
{
   object env, orb;

   if (!arg || !id(arg))
        return 0;

   env = present("solar",environment(this_player()));
   orb = present("power orb",this_player());

   if (!env || !env->is_prisoned())
   {
       write("Nothing happens !\n");
       return 1;
   }
   if (!orb)
   {
      write("You can't conzentrate enough on this language.\n");
      return 1;
   }
   write("The forcefield glows red and then it vanishes !\n");
   env->set_free(this_player());
   destruct(orb);
   return ::do_read(arg);
}



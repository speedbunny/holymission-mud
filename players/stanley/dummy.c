inherit "obj/monster";

int hpd;
status stop;

reset(arg) {
  ::reset(arg);

  if(!arg) {
    set_name("lagmonster");
    set_alias("target");
    set_alt_name("test dummy");
    set_race("dummy");
    set_short("The infamous Lagmonster");
    set_long("The infamous Lagmonster that your mother always warned\n"+
             "you about. While it only rarely kills you, you will\n"+
             "NEVER kill it!\n);
    set_gender(1);
    set_smell("The Lagmonster smells like a Lagmonster!!");
    set_level(1);
    set_hp(20000);
    set_ep(0);
    set_wc(0);
    set_ac(0);
    set_aggressive(0);
    set_whimpy(0);
  }
}

init() {
  ::init();
  stop = 1;
  add_action("end_dummy","dismiss");
  add_action("read_iets","read");
  add_action("stop","stop");
}

read_iets(arg)
{
 if(arg=="label" || arg =="dummy")
  {
   write("An all-purpose hit dummy by Bug wiztool enterprises ltd.\n\n"+
         "instructions:\n"+
         "first attack it with a weapons or cast a spell on it,\n"+
         "the dummy will report how much damage a spell/hit \n"+
         "hits. new gadget: <stop [on/off]>, if stop is on the dummy\n"+
         "will stop fight after a hit if not it will keep on reporting\n"+
         "damage.\n\n"+
         "NOTE:\n"+
         "The dummy can not be killed(its healed after damage), it \n"+
         "can be destroyed either with destruct or with \n"+
         "<dismiss dummy>.\n");
   say(this_player()->query_name()+" reads the "+arg+".\n",this_player());
   return 1;
  }
 return 0;
}

stop(arg)
{
 if(!arg)
  { stop = (!stop);
    if(stop) tell_object(this_player(),"You turn fight OFF.\n");
    else     tell_object(this_player(),"You turn fight ON.\n");
    return 1;
  }
 if (arg == "on")
  { tell_object(this_player(),"You turn fight OFF.\n");
    stop = 1;
    return 1;
  }
 if (arg == "off")
  { tell_object(this_player(),"You turn fight ON.\n");
    stop = 0;
    return 1;
  }
 notify_fail("stop on or off what else?\n");
 return 1;
}

end_dummy(arg)
{
 if (arg == "dummy")
  {
    say("The Lagmonster says: You aint seen nothin' yet!!!\n);
   call_out("dummy_func",2);
   return 1;
  }
 return 0;
}

attack() {
object master;

 if (::attack())
  {
   master=this_object()->query_attack();
   hpd=20000-this_object()->query_hp();
   write("You hit me with a loss of "+hpd+"HP.\n");
   say("Dummy says: "+master->query_name()+" hit me with a loss of "+hpd+"HP.\n");
   set_hp(20000);
   if (stop==1)
    { this_object()->stop_fight();
      master->stop_fight();
    }
  }
}

dummy_func()
{ say("The dummy crumbles to dust.\n");
  destruct(this_object());
  return; }


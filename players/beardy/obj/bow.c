inherit "obj/weapon";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;
  set_name("bow");
  set_short("short bow");
  set_long("It's an ancient short bow, you can use it\n"+
           "for several things, but it is mainly used\n"+
           "for killing others.\n");

  set_value(400);
  set_weight(2);
  set_class(1);
}

void init()
{ ::init();
  add_action("myshoot","shoot");
}

int myshoot(string str)
{ object monster,bag,arrow;

  if(!str)
  { write("No such living !\n");
    return 1;
  }

  if(this_player()->query_attack())
  { write("You are too busy to shoot.\n");
    return 1;
  }

  if(!this_object()->query_wielded())
  { write("You do not wield the bow.\n");
    return 1;
  }

  monster=present(str,environment(this_player()));
  if(!monster)
  { write("No such living !\n");
    return 1;
  }

  bag=present("arrowbag",this_player());
  if(!bag)
   bag=clone_object("/players/beardy/obj/arrowbag");
  arrow=present("arrow",this_player());

  if( (!bag && !arrow) && bag->query_arrows()==0)
  { write("You have no arrows.\n");
    return 1;
  }

/* Arithmetics */

  if(random(TP->query_property("archery"))>=random(monster->query_level()))
  { tell_room(environment(this_player()),this_player()->query_name()+" shoots"+
               " an arrow into "+monster->query_name()+"'s flesh.\n");

    monster->reduce_hit_point(100*log(TP->query_property("archery")/2+TP->query_dex()));

  if(random(TP->query_property("archery"))>=random(monster->query_level()))
    { say("The "+monster->query_name()+" starts attacking "+TPN+".\n");
      write("The "+monster->query_name()+" starts attacking you.\n");
      command("kill "+TP->query_real_name(),monster);
    }
    if(monster->query_hp()<=( monster->query_max_hp()/2 ))
    { say("The "+monster->query_name()+" starts attacking "+TPN+".\n");
      write("The "+monster->query_name()+" starts attacking you.\n");
      command("kill "+this_player()->query_real_name(),monster);
    }

  }
  else
  { say(this_player()->query_name()+" shoots his arrow somewhere in the darkness.\n");
    write("You did not hit you enemy.\n");
  }

  if(arrow)
   destruct(arrow);
  else
    bag->add_arrows(-1);
  return 1;
}

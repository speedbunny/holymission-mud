inherit"obj/weapon";

int times;

reset(arg)
{ if(!arg)
  { set_id("stick");
    set_name("suction stick");
    set_alt_name("suction");
    set_alias("stick");
    
    set_short("suction stick");
    set_long("This is Ottocar's suction stick. You may hold\n" +
              "other livings for three times with it. After this\n" +
              "it will desintegrate.\n");

    set_class(4);
    set_value(1000);

    set_weight(2);
    times=0;
  }
}

init()
{ add_action("myhold","hold");
  ::init();
}
myhold(str)
{ object *dummy;
  if(!str && !this_player()->query_attack())
  { write("You do not fight !\n");
    return 1;
  }
  else
  { if(!this_player()->query_attack())
      if(!present(str,environment(this_player())))
      { write("No such living in here !\n");
        return 1;
      }
      else
        dummy=present(str,environment(this_player()));
    else
      dummy=this_player()->query_attack();

    if(times>=3)
    { write("OOPS, the stick fades away.\n");
      destruct(this_object());
      return 1;
    }
    else
    { dummy->hold(this_player(),2);
      write("You use the magic power of Ottocar's suction stick.\n");
      say(this_player()->query_name()+" uses the magic power of Ottocar's"+
          " suction stick.\n");
      times++;
    }
    return 1;
  }
  return 1;
}

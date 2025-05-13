inherit"obj/weapon";

int tim;

reset(arg)
{ if(!arg)
  { set_id("stick");
    set_name("stick");
    set_alt_name("branche");

    set_short("combat stick");
    set_long("It looks like a light fighter's weapon, but\n"+
              "it has got a special attack. Use 'behead' ten times for\n" +
              "the mighty attack, but beware it could go wrong too\n");

    set_class(10);
    set_value(300);

    set_weight(2);
    tim=0;
  }
}

init()
{ add_action("","");
  ::init();
}

behead(str)
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

    if(tim>=10)
      write("You feel tired of doing this attack.\n");
    else
    if(random(this_player()->query_strength())<14)
    { dummy->reduce_hit_point(100+random(this_player()->query_str()*2-random(10)));
      say(this_player()->query_name()+" does THE special hit to the dangerous "
           +this_player()->query_attack()->query_name()+
           ".\n",this_player());
      write("You do THE special hit to the dangerous "
           +this_player()->query_attack()->query_name()+".\n");

      this_player()->hold(this_object(),2);
      tim++;
      
    }
    else
    { write("Oops ! You lost controll of the weapon and cut yourself.\n");
    }

    return 1;
  }
  return 1;
}

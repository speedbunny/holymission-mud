inherit "obj/thing";

#define COMMANDS "/players/portil/guild/room"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("checker");

    set_short("NEW checker");
    set_long("Commands availiable :\n\n"+
             "checkstate <obj>        to check armour- or weaponclass and weight\n"+
	     "mskills			to see your skills outside the guild\n");

  }
}

void init()
{ ::init();
  add_action("mycheck","checkstate");
/* temorarly moved out , because gave bugs in fighters
  add_action("myskills","mskills");
                          */
}

int myskills()
{ tell_object(this_player(),COMMANDS->list_skills(this_player(),2));
  return 1;
}

int mycheck(string str)
{ object dummy;

  if(this_player()->query_guild()!=3)
  { write("You are not mighty enough to use this checker.\n");
    destruct(this_object());
    return 1;
  }
  if(!str) return 0;

  if(!(dummy=present(str,this_player())))
  { write("You don't have that item\n");
    return 1;
  }
  else
  { if(dummy->weapon_class())
    { write("You check the weapon and suggest these stats :\n");
      write("Class  : ");
      switch(dummy->weapon_class())
      { case 20       : write("it's one of the best weapons i think\n"); break;
        case 18 .. 19 : write("fascinating good\n"); break;
        case 15 .. 17 : write("very good\n"); break;
        case 12 .. 14 : write("quite good\n"); break;
        case 9  .. 11 : write("middle good\n"); break;
        case 6  .. 8  : write("less good\n"); break;
        case 3  .. 5  : write("sensless stuff\n"); break;
        case 0  .. 2  : write("forget it !\n");break;
        default       : write("don't know\n");
      }
      switch(dummy->weapon_type())
      { case 0 : write("Type   : bludgeon [mainly strength]\n"); break;
        case 1 : write("Type   : pierce   [mainly dexterity]\n"); break; 
        default : write("Type   : slash    [strength + dexterity]\n");
      }
    }
    if(dummy->armour_class())
    { write("You check the armour and suggest these stats :\n");
      write("Class  : ");
      switch(dummy->armour_class())
      { case 0 : write("forget that stuff !\n"); break;
        case 1 : write("not bad\n");break;
        case 2 : write("middle good\n"); break;
        case 3 : write("quite good\n"); break;
        case 4 : write("very good\n"); break;
        case 5 : write("fascinating good\n"); break;
        case 6 : write("one of the best armours you find\n"); break;
        case 7 .. 30 : write("out of range, must be guild stuff\n"); break;
        default : write("don't know\n");
     }
     write("Type   : "+dummy->query_type()+"\n");
    }
    write("Weight : ");
    switch(dummy->query_weight())
    { case -10 .. -1 : write("hold it, or it will fly away\n"); break;
      case 0 : write("do you really hold something ?\n"); break;
      case 1 : write("extremely light\n"); break;
      case 2 : write("very light\n"); break;
      case 3 : write("little bit heavy\n"); break;
      case 4 : write("a bit heavy\n"); break;
      case 5 : write("quite heavy\n"); break;
      case 6 : write("very heavy\n"); break;
      case 7 : write("extremely heavy\n"); break;
      case 8 : write("wow what an weight !\n"); break;
      default : write("don't know, perhaps out of range :)\n");
    }
    return 1;
  }
}

string query_auto_load()
{
  return "/players/beardy/obj/checker:";
}

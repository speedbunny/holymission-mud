inherit "obj/thing";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  set_name("crumbling vellum scroll");
  set_alias("scroll");
  set_short("A Crumbling Vellum Scroll");
  set_long("This is an old, crumbling scroll.  Across the top \n"+
           "you see the word 'Identify'.\n");
  set_weight(1);
  set_value(375);
  set_can_get(1);

}

int id(string str) 
{ 
  return str == "scroll" || str == "identify" || 
                 str == "vellum scroll"; 
}

void init() 
{
  ::init();
  AA("identify", "identify");
  AA("read",     "read");
}

int read(string arg) 
{
  if (!id(arg))
    return 0;
  long();
  return 1;
}

int identify(string arg) 
{
  object obj, memb;
  int ac, wc, weight;
  string info;

  if (!arg) 
  {
    NFAIL("Identify what?\n");
    return 0;
  }
  obj = present(arg, this_player());
  if (!obj) 
  {
    if (present(arg, environment(this_player()))) 
    {
      write("You must be carrying the "+CAP(arg)+" to identify it.\n");
      return 1;
    }
    write("You aren't carrying a "+CAP(arg)+".\n");
    return 1;
  }   
  if (TP->SP < 10) 
  {
    write("You can't quite comprehend the words on the scroll.\n");
    return 1;
  }
  ac = obj->armor_class();
  wc = obj->weapon_class();
  weight = obj->query_weight();
  if (ac > 0) 
  {
    write("This appears to be some type of armor.\n");
    switch(ac)
    {
      case 0:
         write("This provides little protection.\n"); 
      break;
      case 1:
         write("This provides you average protection.\n");
      break;
      case 2:
         write("This provides you good protection.\n");
      break;
      case 3:
         write("This provides you excellent protection.\n");
      break;
      case 4:
         write("This provides you superb protection.\n");
      break;
      case 5:
         write("This is some of the best armor you've ever seen.\n");
      break;
    }
    return 1;
  } 
  else 
  if (wc > 0) 
  {
    write("This appears to be some type of weapon.\n");
    switch(wc)
    {
      case 1 .. 4:
         write("This is a below average weapon.\n"); 
      break;
      case 5 .. 8:
         write("This is an average weapon.\n");
      break;
      case 9 .. 12:
         write("This is a good weapon.\n");
      break;
      case 13 .. 15:
         write("This is an excellent weapon.\n");
      break;
      case 16 .. 19:
         write("This is a superb weapon.\n");
      break;
      case 20:
         write("This is one of the best weapons you've ever seen !!\n");
      break;
    }
  }
  else 
  write("You can't tell what type of object this is.\n");
  switch(weight)
  {
    case 0:
      write("This object weights nothing.\n");
    break;
    case 1:
      write("This object weights almost nothing.\n");
    break;
    case 2 .. 3:
      write("This object is reasonably light.\n");
    break;
    case 4 .. 6:
      write("This object is pretty heavy.\n");
    break;
    case 7 .. 9:
      write("This object is moderately heavy.\n");
    break;
    case 10:
      write("This object is pretty heavy.\n");
    break;
    default:
      write("You probably can't carry much else while carrying this.\n");
  }
  info = obj->query_info();
  if (info)
    write(info);
  TP->ADDSP(-10);
  write("The scroll turns to dust.\n");
  write_file("/players/tamina/log/ID", TPN+" identified "+obj->SHT+"\n");
  destruct(TO);
  TP->recalc_carry();
  return 1;
}

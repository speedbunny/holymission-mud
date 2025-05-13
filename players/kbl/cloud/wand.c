/*
              Wand of Cloud Control
*/


#include "/players/kbl/cloud/cell.h"

int density,access,slits,slits_open,repeat,cont_on,num_cells,fplay;
string cont_type;
string alias_name,alt_name;
string cont_name,players_cell,id;
object clone,clone_dest;
object cell;

id(str)
{

  return str == id || 
         str == TO->query("alias_name") || 
         str == TO->query("alt_name") ||
         str == "cloud_control";
}

reset(arg)
{
  if(!arg)
  {
    set("light",0);
    set("name","super");
    set("id","control");
    set("density",9);
    set("freq",9);
    set("access",9);
    set("alias_name","wand");
    set("type","Blue");
    set("alt_name","cloud control");
    set("slits",9);
    set("slits_open",9);
    set("cont_on",0);
  }
}

set(str,var)
{
  switch(str)
  {
    case NA: cont_name = var;
             break;
    case ID: id = var;
             break;
    case DN: density = var;
             break;
    case AL: alt_name = var;
             break;
    case AC: access = var;
             break;
    case SL: slits = var;
             break;
    case AI: alias_name = var;
             break;
    case SO: slits_open = var;
             break;
    case CL: clone = var;
             break;
    case CD: clone_dest = var;
             break;
    case CO: cont_on = var;
             break;
    case LT: set_light(var);
             break;
    case TY: cont_type = var;
             break;
    default: return 0;
             break;
   }
}

query(str)
{
  switch(str)
  {
    case NA: return cont_name;
             break;
    case ID: return id;
             break;
    case DN: return density;
             break;
    case FR: return freq;
             break;
    case AC: return access;
             break;
    case SL: return slits;
             break;
    case SO: return slits_open;
             break;
    case CL: return clone;
             break;
    case CD: return clone_dest;
             break;
    case AL: return alt_name;
             break;
    case AI: return alias_name;
             break;
    case CO: return cont_on;
             break;
    case TY: return cont_type;
             break;
    default: return 0;
             break;
  }
}

/* Basic Object functions */

short()
{
  return CP(cont_name)+" cloud wand";
}

long()
{
  write(CP(cont_name)+" wand of cloud contro\n\n"+
        "\t Access    (AC):\t"+access+"\n"+
        "\t Density   (DN):\t"+density+"\n"+
        "\t Slits     (SL):\t"+slits+"\n"+
        "\t SL Open   (SO):\t"+slits_open+"\n"+
        "\t Type      (TY):\t"+cont_type+"\n"+
        "\n\t For more information type: help clouds\n"));
}


query_alias()
{
  return alias_name;
}

query_value()

{
  return 2000*access;
}

query_weight()
{
  return 0;
}

query_name()
{
  return cont_name;
}

get()
{
  return 1;
}

init()
{
  add_action("help","help");
  add_action("align","enter");
  add_action("disengage","escape");
  add_action("insert","insert");
  add_action("search","search");
}

help(str)
{
  int ret;

  if(!str)
   return;
  ret = 0;
  ret = "/players/kbl/cloud/cloud_help"->help(str);
  if(ret)
   return 1;
  str = " ";
  return;
}

align(str)
{
  string matrix;

  if(!str || !(str == "clouds" || str == id))
   return;
  if(!present("cloud_control",TP))
  {
    write("You do not have a cloud control wand on you.\n");
    return 1;
  }
  if(cont_on)
  {
    write("Wand is already functioning!\n");
    return 1;
  }
  cell = ETP->query_cell();
  if(!cell)
  {
    write("There is no CCCS in this area.\n");
    return 1;
  }
  align2(cell);
  return 1;
}

align2(ob)
{
  object old;

  set("clone",clone_object("/players/kbl/cloud/cloud_double"));
  clone->set("short",CTPRN+" has "+TP->QPO+" cloud control wand functioning");
  clone->set("long",CTPRN+" is busy! Better leave "+TP->QOB+" alone!\n");
  clone->set("weight",2000);
  clone->set("alias",ETO->QN);
  clone->set("alt_name",TP->QRN);
  transfer(clone,ETP);
  set("clone_dest",ETP);
  set("cont_on",1);
  old = ETP;
  transfer(TP,ob);
  tell_room(old,CTPRN+" just disappeared into a cloud!\n");
  write("Your surroundings dematerialize into a \"mass of clouds\"\n"+
        "Your inside the clouds of Airera! Welcome cloud runner "+CTPRN+"!\n");
}

disengage()
{
  object cl;
  object old;

  if(!query("cont_on"))
  {
    write("Your not inside any clouds.\n");
    return 1;
  }
  cl = present(TP->QN,query("clone_dest"));
  if(cl)
  {
    cl->query_remove();
    destruct(cl);
  }
  old = ETP;
  tell_room(clone_dest,CTPRN+" disengages from the Ixian cell system.\n");
  transfer(TP,clone_dest);
  tell_room(old,CTPRN+" disengages from this cell.\n");
  write("You disengage from the clouds back to where you were.\n");
  set("cont_on",0);
  return 1;
}

search(str)
{
  if(!str)
   return;
  if(!cont_on)
   return;
  switch(str)
  {
    case "clouds":
    case "cell":
    case "area":
     if(ETP->query_access() <= TO->query("access"))
     {
      if(ETP->query_density() <= TO->query("density"))
      {
        if(gen_ser())
         return 1;
        write("There is nothing in the "+str+".\n");
        say(CTPRN+" finds nothing in the "+str+".\n",TP);
        return 1;
      }
     }
     write("There seems to be nothing in the "+str+".\n");
     say(CTPRN+" cannot seem to find anything in the "+str+".\n");
     return 1;
  }
}

gen_ser()
{
  object ob;
  int    ob_disp;

  ob_desp = 0;
  ob = first_inventory(ETP);
  write("Your cloud control wand hums while searching.\n");
  say(CTPRN+"'s wand hums.\n");
  while(ob)
  {
    if(!find_living(ob->QRN))
    {
     if(ob_disp == 0)
       write("FOUND: "+ob->short()+".\n");
     else
       write("       "+ob->short()+".\n");
     ob_desp++;
    }
    ob = next_inventory(ob);
  }
  return ob_desp;
}
  
insert(str)
{
  object ob;

  if(!str)
   return;
  if(!slits_open)
  {
    write("You have no more room for any more enhancements.\n");
    return 1;
  }
  ob = present("upgrade",TP);
  if(!ob)
  {
    write("You do not have a upgrade!\n");
    return 1;
  }
  slits_open-=1;
  write("You just inserted a upgrade into your cloud control wand.\n");
  say(CTPRN+"'s cloud control wand makes noises.\n");
  switch(ob->query("type"))
  {
     case 1: density+=1;
             break;
     case 2: access+=1;
             break;
     case 3: density+=1;
             access+=2;
             break;
  }
  destruct(ob);
  return 1;
}

inherit "obj/thing";
#define me this_player()

closure call;

reset(int arg)
{ if(!arg) return 0;


  set_name("scorer");
  set_short("scorer");
  set_long("This is a scorer. Type score");

  set_name("scorer");
  set_weight(0);
  set_value(0);
}

void init()
{ ::init();
  add_action("myscore","score");
}

int myscore()
{  string ret;
   string cn;
   int sz;
   string size;
   string stat;
   string victim;
   object att_ob;
   string religion;

   if(me->query_guild()!=3) destruct(this_object());
   sz = me->query_size();
   cn = capitalize(me->query_real_name());
 
   if (me->query_attack())
       victim  =  me->query_attack()->query_real_name();
   else 
       victim = "none";

   switch(sz)
   {
     case 0: size = "any"; break;
     case 1: size = "tiny"; break;
     case 2: size = "small"; break;
     case 3: size = "medium"; break;
     case 4: size = "large"; break;
     default: size = "x-large"; break;
   }
    stat = "";

    if (me->query_poisoned())
        stat = stat + "poisoned ";
    if (me->query_intoxination())
        stat = stat + "drunken ";
    if (me->query_soaked())
        stat = stat + "soaked ";
    if (me->query_stuffed())
        stat = stat + "stuffed ";

    if (me->query_religion())
        religion = me->query_religion();
    else
      religion = "Atheist";


     ret = ( 
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "              "+cn+" IN HOLY MISSION                    \n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  guild: MONK\t\t\t"+
     "  race: "+me->query_race()+"\n"+
     "  religion: "+religion+"\t\t"+
     "  current weight: "+me->query_weight()+"\n"+
     "  level: "+me->query_level()+"\t\t\t"+
     "  money: "+me->query_money()+"\n"+
     "  size: "+size+"\t\t\t"+
     "  experience: "+me->query_exp()+"\n"+
     "  command for info: help guild\t"+
     "  alignment: "+me->query_al_title()+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  health: \t\t\t  "+me->query_hp()+" "+
     "["+me->query_max_hp()+"]\n"+
     "  power: \t\t\t  "+me->query_sp()+" "+
     "["+me->query_max_sp()+"]\n"+
     "  vitals: \t\t\t  "+stat+"\n"+
     "  wimpy set to: \t\t  "+me->query_wimpy()+"%\n"+
     "  wimpydir is : \t\t  "+me->query_wimpydir()+"\n"+
     "  attacked by: \t\t\t  "+victim+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  DEX: "+me->query_dex()+"  "+
     "WIS: "+me->query_wis()+"  "+
    "CON: "+me->query_con()+"  "+
     "INT: "+me->query_int()+"  "+
    "STR: "+me->query_str()+"  "+
     "CHR: "+me->query_chr()+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

     tell_object(me,ret);
   return 1;
}

get()
{ return 1;
}

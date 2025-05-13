#include "/players/tamina/defs.h"
  status used;
  object obj;
  int ac, wc, wg;
  int val;

int id(string str) 
{ 
  if (used) return 0;

  return str == "scroll" || str == "gold leaf scroll" ||
                 str == "enchant"; 
}

string short() 
{ 
  if (used) return 0;

  return "A beautiful, gold leaf scroll";
}

void long() 
{ 
  if (used) return 0;

  write("This is a beautiful, gold leaf scroll.  Across the top \n"+
        "you see 'Enchant'.\n");
}

void reset (int arg)
{
  if (!arg)
    used = 0;
}

string query_info()
{
  return "This Gold Leaf scroll of Enchantment will magically\n"+
         "endow extra protetive, or fighting properties on your\n"+
         "possessions - for a limited time, of course.\n";
}

int query_value() 
{
  return 1000; 
}

int query_weight() 
{
  return 1; 
}

int get() 
{ 
  return 1; 
}

void init() 
{
   add_action("_enchant", "enchant");
   add_action("_read",    "read");
}

int _read(string arg) 
{
  if (used) return 0;

  if (!id(arg)) return 0;

  long();
  say(TPN+" takes a long look at the gold-leaf scroll.\n"); 
  return 1;
}

int _enchant(string arg) 
{
  int chance;

  obj = present(arg, TP);
   ac = obj->armour_class();
   wc = obj->weapon_class();
   wg = obj->query_weight();

  if (used) return 0;

  if (!arg) 
  {
    write("Enchant what?\n"); 
    return 0;
  }
  if (!obj) 
  {
    if (present(arg, E(TP)))   /*  arg is lying in the room around player  */
    {
      write("You must be carrying the "+CAP(arg)+" to enchant it.\n");
         return 1;
    }
    write("You aren't carrying a "+CAP(arg)+".\n");
    return 1;
  }
  if (TP->SP < 50) 
  {
    write("Your mental powers are not quite up to using this scroll.\n");
    return 1;
  }
  write("You read the scroll.  The "+CAP(arg)+" begins glowing a deep blue.\n");
    say(TPN+" reads the gold leaf scroll.\n\n");

/* ################## For Enchanting Armours ##################### */

  if (ac > 0)                         
  {
    if (ac == 4)
    {
      write("But your "+CAP(arg)+" is already the best it can be.\n"+
	    "The deep blue glows fades slowly from the "+CAP(arg)+".\n");
      return 1;
    }
    chance = 3*ac*(ac+1);
    if (chance > 95) chance = 95;
      
    if (chance > random(101))        /* chance for failures */ 
    {
      if (random(101) < 10)          /*  ultimate failure - destruction  */
      {
        write("The "+CAP(arg)+" glows brighter, turning a blinding white.\n");
        write("The "+CAP(arg)+" explodes into smithereens!\n");
          say(TPN+"'s "+CAP(arg)+" explodes into smithereens!\n");

        destruct(obj);
        HIT(40);

        write("The scroll crumbles into ashes.\n");
        destruct(TO);
        return 1;
      }
      else                        /* partial failure - lesser armour */
      {
        val = obj->query_value();
        if (val < 0) val = 0;
        write("The "+CAP(arg)+" glow begins to fade, turning black.\n");
          say(TPN+"'s "+CAP(arg)+" glows a deep black.\n");

        obj->set_ac(ac-1);
        obj->set_value(val-600);

        write("The scroll crumbles into ashes.\n");

        used = 1;
        call_other(TP, "recalc_ac"); 
	call_out("reset_val", 375);
        return 1;
      } 
    }   /*  end if for failures  */
    else 
    {                                   /*  SUCCESS  */
      val = obj->query_value();
      write("The "+CAP(arg)+" glows brighter, turning a brilliant blue.\n");
      write("When the light fades, the "+CAP(arg)+" remains.\n");
        say(TPN+"'s "+CAP(arg)+" takes on a better appearance.\n");

      obj->set_ac(ac+1);
      obj->set_value(val+500);
      obj->set_weight(wg+1);

      write("The scroll crumbles into ashes.\n"); 

      write_file("/players/tamina/log/enchant", ""+TPN+" enchanted a "+CAP(arg)+" on "+ctime(time())+".\n");

      used = 1;
      call_out("reset_val", 375);      /*  How long the effects last for  */
      call_other(TP, "recalc_ac"); 
      return 1;
    }
  } 

/*  #################  For Enchanting Weapons   #################  */

  if (wc > 0)                
  { 
    if (wc >= 18)
    {
      write("But your "+CAP(arg)+" is already the best it can be.\n"+
	    "The deep blue glows fades slowly from the "+CAP(arg)+".\n");
      return 1;
    }
    chance = (wc*(wc+1)*8)/39;
    if (chance > 95) chance = 95;

    if (chance > random(101))  /*  For failures only  */
    {
      if (random(101) < 10) 
      {
        write("The "+CAP(arg)+" glows brighter, turning a blinding white.\n");
        write("The "+CAP(arg)+" explodes into smithereens!\n");
          say(TPN+"'s "+CAP(arg)+" explodes into smithereens!\n");

        destruct(obj);
        HIT(40);

        write("The scroll crumbles into ashes.\n");

        used = 1;
        destruct(TO);
        return 1;
      }
      else
      {
        val = obj->query_value();
        if (val < 0) val = 0;
        write("The "+CAP(arg)+" glow begins to fade, turning black.\n");
          say(TPN+"'s "+CAP(arg)+" glows a deep black.\n");

        obj->set_class(wc-2);
        obj->set_value(val-500);

        write("The scroll crumbles into ashes.\n");

        used = 1;
	call_out("reset_val", 375);
        call_other(TP, "recalc_wc"); 
        return 1;
      } 

    }    /* end if of failures  */

    val = obj->query_value();
    write("The "+CAP(arg)+" glows brighter, turning a brilliant blue.\n");
    write("When the light fades, the "+CAP(arg)+" remains.\n");
      say(TPN+"'s "+CAP(arg)+" takes on a better appearance.\n");

    obj->set_class(wc+3);
    obj->set_value(val+1000);
    obj->set_weight(wg+2);

    write("The scroll crumbles into ashes.\n"); 
  
    write_file("/players/tamina/log/enchant", ""+TPN+" enchanted a "+CAP(arg)+" on "+ctime(time())+".\n");

    used = 1;
    call_out("reset_val", 375);
    return 1;
   
    call_other(TP, "recalc_wc"); 
  }
  else 
  if ((ac <= 0) && (wc <= 0))
  {
    write("Nothing happens to the "+CAP(arg)+".\n");
    write("The scroll crumbles into ashes.\n"); 

    destruct(TO);
    used = 1;
    return 1;
  }

  TP->ADDSP(-50);
  write("The scroll turns to dust.\n");
  used = 1;
  destruct(TO);
  call_other(TP, "recalc_carry");
  return 1;
} 

reset_val()
{
  if (present(obj, TP))
  {
    TOBJ (TP,
     "The glow around your "+obj->short()+" slowly fades, until it looks\n"+
     "like normal again.\n");
  }  
  obj->set_ac(ac);
  obj->set_class(wc);
  obj->set_value(val);
  obj->set_weight(wg);

  destruct(TO);
  used = 0;
  call_other(TP, "recalc_carry");
  call_other(TP, "recalc_ac"); 
  call_other(TP, "recalc_wc"); 
  return 1;
}



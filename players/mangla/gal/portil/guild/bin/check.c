

// Last Edit: 6.2.95 Whisky uni-linz.ac.at : mayor changes in the whole file

#define CAP		capitalize
#define TP		this_player()

int check(string str) 
{
  object ob;
  int i, ac, wc, con, _ac, _wc, _con, *acs, max_ac, weight, value;
  closure call;
  string what, pron, type, *types, name;

  if(!str) 
  { 
     notify_fail("Check what?\n"); 
     return 0; 
  }

  call = #'call_other;

  if ( str == apply(call,TP,"query_real_name"))
  {
      write("You can guess how you feel :*)\n");
      return 1;
  }

  if (!(ob = present(str,environment(TP))) )
        ob = present(str,TP);

  if (!ob)
  {
      write("Never here when required !\n");
      return 1;
  } 

  if ( apply(call,ob,"query_hp"))
       what = "living";
  else if (apply(call,ob,"query_armour"))
       what = "armour";
  else if (apply(call,ob,"query_weapon"))
       what = "weapon";
  else
       what = "others";
  
  
  switch(what)
  {
     case "living":
        con = apply(call,ob,"query_con");
       _con = apply(call,TP,"query_con");
        ac = apply(call,ob,"query_ac");
       _ac = apply(call,TP,"query_ac");
        wc = apply(call,ob,"query_wc");
       _wc = apply(call,TP,"query_wc");
       pron = capitalize(apply(call,ob,"query_pronoun"));

      
       write("You check "+apply(call,ob,"query_name")+" carefully:\n\n");
       if ( (1 +_con)/2 > con)
           write(pron+" looks much weaker than you.");
       else if (_con > con)
           write(pron+" looks weaker than you.");
       else if (_con < (1+con)/3)
           write(pron+" miles healthier than you.");
       else if (_con < (1+con)/2)
           write(pron+" much healthier than you.");
       else if (_con < con)
           write(pron+" healthier than you.");
           
       write("\n");
       if ( (1 +_wc)/2 > wc)
           write(pron+" seems to be much weaker armed.");
       else if (_wc > wc)
           write(pron+" seems to be weaker armed.");
       else if (_wc < (1+wc)/3)
           write(pron+" seems to be miles better armed.");
       else if (_wc < (1+wc)/2)
           write(pron+" seems to be much better armed.");
       else if (_wc < wc)
           write(pron+" seems to be better armed.");
          
       write("\n");
       if ( (1 +_ac)/2 > ac)
           write(pron+" seems to be much weaker protected.");
       else if (_ac > ac)
           write(pron+" seems to be weaker protected.");
       else if (_ac < (1+ac)/3)
           write(pron+" seems to be miles better protected.");
       else if (_ac < (1+ac)/2)
           write(pron+" seems to be much better protected.");
       else if (_ac < ac)
           write(pron+" seems to be better protected.");

       write("\n");
       value = apply(call,ob,"query_level") + 1;
       weight = apply(call,TP,"query_level") + 1;

       if (value/3 >= weight)
           write(pron+" is a deathly opponent, better run away !\n");
       else if (value/2 >= weight)
           write(pron+" is a mighty opponent be on guard !\n");
       else if (value >= weight)
           write("This could be a really hard fight.\n");
       else if (value < weight/3)
           write("Now, where did the chicken go :*)\n");
       else if (value < weight/2)
           write("You can do it with a needle.\n");
       else if (value < weight)
           write(pron+" looks like an easy kill.\n");
       break;

     case "armour":
        type = apply(call,ob,"query_type");
        ac = apply(call,ob,"armour_class");
        types = apply(call,"/obj/share","share_armour_types");
        acs = apply(call,"/obj/share","share_armour_max_ac");

        if ( (i = member_array(type,types))!=-1)
            max_ac = acs[i];
        else   
        {
           write("Strange, it looks like an armour, but seems unwearable.\n");             break;
        }
        if ( (name = apply(call,ob,"query_name")) ) 
            write("You check the "+name+" carefully:\n\n");

         if (!type)
           write("A very strange armour, you can't guess what it is.\n");
         else
           write("You see its an armour type: "+type+".\n");

         if (ac == 0)
             write("This armour don't looks just like fashionware.\n");
          else if (ac < (1 + max_ac/3) )
             write("This armour looks really bad, better sell it.\n");
          else if (ac < (1 + max_ac/2) )
             write("This armour looks quite usable.\n");
          else if (ac <  (max_ac-1) )
             write("This armour looks quite good.\n");
          else if (ac <  (max_ac) )
             write("This armour looks really good.\n");
          else
             write("This armour looks really great, keep it !\n");
     break;
     case "weapon":
        wc = apply(call,ob,"weapon_class");
        type = apply(call,ob,"query_type");

        if ( (name = apply(call,ob,"query_name")) ) 
            write("You check the "+name+" carefully:\n\n");

         switch(type)
         {
            case 0:
             write("The weapontype seems to be slashing.\n");
            break;
            case 1:
             write("The weapontype seems to be bludgeon.\n");
            break;
            default: 
             write("The weapontype seems to be piercing.\n");
            break;
         }
         switch(wc)
         {
            case 0:
              write("It don't look like you can hit something with it"); 
            break;
            case 1..3:
              write("It looks like a junk weapon"); 
            break;
            case 4..5:
              write("It looks like a very weak weapon"); 
            break;
            case 6..9:
              write("It looks like a weak weapon"); 
            break;
            case 10..13:
              write("It looks quite nice but there are sure better ones"); 
            break;
            case 14..17:
              write("It looks good enough for hard fights"); 
            break;
            case 18..19:
              write("It looks like a very good weapon"); 
            break;
            default:
              write("This weapon looks really great"); 
            break;
      }
       if (apply(call,ob,"query_property","magic_hit")!=-1)
           write("\nand its covered with a strange magic aura.\n");
       else
          write(".\n");
   } 
     
   if (what!="living")
   {
      value = apply(call,ob,"query_value");
      weight = apply(call,ob,"query_weight");

      switch(value)
      {
        case 0: 
          write("Its seems to be worth nothing, someone may have droped it.\n");
        break;
        case 1..50:
          write("It seems to have a very low value.\n");
        break;
        case 51..200:
          write("It seems to have a low value.\n");
        break;
        case 201..500: 
          write("It seems to be worth something, but not much.\n");
        break;
        case 501..1000: 
          write("It seems to have a high value.\n");
        break;
        case 1001..3000: 
          write("It seems to have a very high value.\n");
        break;
        case 3001..10000: 
          write("It seems to have an extremly high value.\n");
        break;
        default: 
          write("Oh gosh, it seems to belong to a very rich person !\n");
        break;
      }

       switch(weight)
       {
          case 0:
            write("It weighs as good as nothing.\n");
          break;
          case 1:
            write("It weighs a bit but not much.\n");
          break;
          case 2:
            write("It's not heavy at all.\n");
          break;
          case 3:
            write("It's a bit heavy.\n");
          break;
          case 4:
            write("It's heavy.\n");
          break;
          case 5:
            write("It's very heavy.\n");
          break;
          default:
            write("It's really heavy !\n");
          break;
       }
    }
   return 1;
}

            
       

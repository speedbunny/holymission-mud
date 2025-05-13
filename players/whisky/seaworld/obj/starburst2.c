inherit "/obj/weapon";

string verb_dam(int d,object a);
void writec(string str);
#define MAXCHARGE 300           /* 5 mins */
#define LEN 70
#define ATTNAME \
  (attacker->query_real_name() ? capitalize(attacker->query_real_name()) :\
   "your oponent")

int charge,llevel;
int hpower, mpower;
int *dam;
int heart_beat;
string *color;
object shad;

void reset(int flag) 
{
   mpower = 5;

   if (flag == 0) 
   {

      set_id("burst");
      set_alias("starburst");
      set_alt_name("mighty starburst");
      set_short("The mighty Starburst");
      set_long(
      "The artifact of the gods of time and space and the artifact against\n"+
      "evil powers. It can be lighted or extinguished and it can 'shoot\n"+
      " meteors'. There is the word 'protection from evil' engraved in it.\n"+
      "It somehow looks like a short in a golden aura glowing staff. Painted\n"+
      "on it are 5 mulitcolored stars as the symbol for the power of the\n"+
      "whole universe. Faerie tales are told that you can even kill a wizard\n"+
      "throughout the power of this weapon.\n");
      set_type(2);
      set_hit_func(this_object());
      set_weight(1);
      set_value(15000);
      charge=MAXCHARGE;
      llevel=0;
      dam=allocate(5);
      color=({ "red", "green", "blue", "silver", "golden" });
   }
}

string short() 
{ 
    return ::short()+(llevel ? "(lighted)": ""); 
}

void init() 
{
    ::init();
    add_action("light","light");
    add_action("extinguish","extinguish");
    add_action("do_shoot","shoot");
}

int weapon_hit(object attacker) 
{
   int i,sum;
  
  for (i=0;i < 5; i++) dam[i] = random(random(18));
 /* random of 18 = 8,5   random of 8,5 * 5 = 17,5 || 20 = 18,75 */
   for(i=0;i<5;i++) {
      writec(" the "+color[i]+" star shoots at "+ATTNAME+" and "+
            verb_dam(dam[i],attacker)+" ");
      sum+=dam[i];
   }
   say(this_player()->query_name()+" points the mighty Starburst against "+
      attacker->query_name()+" !!!!\n");
   
   if (attacker->query_race()=="hellhound") {
      return (random(800)+sum); 
      }   
   return sum;
}

string verb_dam(int d,object a) 
{
   switch(d) 
   {
      case 0: return "misses.";
      case 1: return "scratches "+a->query_objective()+".";
      case 2: return "gazes "+a->query_objective()+".";
      case 3: return "edges "+a->query_possessive()+" body.";
      case 4: return "cuts in "+a->query_possessive()+" flesh.";
      case 5: return "hits "+a->query_objective()+" badly.";
      case 6: return "smashes in "+a->query_possessive()+" face!";
      case 7: return "bursts in "+a->query_possessive()+" rips!";
      default: return "shines.";
   }
}

int light(string arg) 
{
    if(!id(arg)) return 0;
    if(llevel) {
        write("The starburst is already lighted.\n");
        return 1;
    }
    if(!charge) {
        write("You have to wait for some time till the Starburst recharged!\n");
        return 1;
    }
    call_out("exing",charge);
    llevel=1;
    set_light(1);
    say(this_player()->query_name()+" lights the Mighty Starburst.\n");
    write("You light the starburst.\n");
    return 1;
}

void exing() 
{
    if(!llevel) return;
    charge=llevel=0;
    set_light(0);
    call_out("recharge",MAXCHARGE*2);
    say("Someones light goes out.\n");
    write("Your light goes out.\n");
}

void recharge() 
{
    charge=MAXCHARGE;
    tell_object(environment(),"The Mighty Starburst vibrates in your hands.");
}

int extinguish(string arg) 
{
    if(!id(arg)) return 0;
    if(!llevel) {
        write("The Starburst is not lighted.\n");
        return 1;
    }
    charge=remove_call_out("exing"); 
    if(charge<0) charge=0;
    say("Someones light goes out.\n");
    write("You extinguish your Starburst.\n");
    set_light(0); 
    llevel=0;
    return 1;
}

void writec(string str) 
{
    int l,i;
    string out;
    out="";
    l=strlen(str);
    for(i=0;i<(LEN-l)/2;i++) out+="*";
    out+=str;
    for(i=strlen(out);i<LEN;i++) out+="*";
    write(out+"\n");
}

int do_weave(string arg) 
{
  if (!id(arg)) return 0;
  else if (!hpower)
  {
    write("Something in your mind tells you:\n\n"+
          "My healing power is gone, you have to wait a bit.\n");
         return 1;
  } else
write("As you weave the mighty starburst, some power pulsates through \
your body.\n");
    this_player()->heal_self(300);
    hpower--;
    return 1;
  }

int do_shoot(string arg)
{
   object *inv;
   int i, sz;

   if (arg!="meteors") return 0;
   else if (mpower < 1)
   {
    write("Something in your mind tells you:\n\n"+
          "My power to shoot meteors is gone, you have to wait a bit.\n");
          return 1;
   }
   else if (heart_beat == 1)
   {
     write("Energie overload: You have to wait a bit.\n");
     return 1;
   }
   else 
   {
     say(
     "\n\n** BOOM ** metors shooting out of "+this_player()->query_name()+"'s "+
     "starburst blast the whole area !\n\n");
     write("** BOOM ** meteors shooting out of your starburst blast the whole "+
           "area !\n");

     inv = all_inventory(environment(this_player()));
     mpower--;
     heart_beat = 1;
     call_out("my_heart_beat",2);

     if (sz = sizeof(inv))
     {
         for ( i = 0; i < sz; i++ )
         {
            if (living(inv[i]) && inv[i]!=this_player() )
            {
               if (this_player()->query_party_member(inv[i]) )
               {
                   tell_object(inv[i],
                   "But luckily you are not hit !\n");
               }
               else 
               {
                    tell_object(inv[i],
                    "** AUTCH you are hit badly !\n");
                    inv[i]->hit_player(30+random(30),5);
                    mpower--;
               } /* endif */
            }   /* endif */
         }     /* endfor */
      }       /* endif */
   }         /* endif */
   return 1;
}
     
int wield(string arg)
{
    if (id(arg) && (!query_wielded()) )
    {
      if (this_player()->query_hands_free())
      {
          write("A soft light blue aura envelopes your body.\n");
          say(this_player()->query_name()+" emits a light blue glow.\n");
          /* shadow */
          shad = clone_object("/obj/shadows/prot_from_evil_shad");
          shad->start_shadow(this_player(),0);   
      }
     return ::wield(arg);
   }
}

void chk_unshad()
{
    object shad;

    if (objectp(shad = this_player()->shad_obj("protection_from_evil")))
    {
        write("The light blue aura leaves your body.\n");
        destruct(shad);
    }
}

int drop()
{
   ::drop();
   chk_unshad();
   return 0;
}

int un_wield()
{
     chk_unshad();
     return ::un_wield();
}

void my_heart_beat()
{
   heart_beat = 0;
}



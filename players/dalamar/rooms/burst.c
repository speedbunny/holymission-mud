inherit "/obj/weapon";

#define MAXCHARGE 300		/* 5 mins */
#define LEN 70
#define ATTNAME \
  (attacker->query_real_name() ? capitalize(attacker->query_real_name()) :\
   "your oponent")

int charge,llevel;
int *dam;
string *color;

reset(arg) {
if (arg) return;

    set_id("burst");
    set_alias("starburst");
    set_alt_name("mighty starburst");
    set_short("The mighty Starburst");
    set_long("The strongest weapon the gods have ever seen.\n");
   set_type(2);
    set_hit_func(this_object());
    set_weight(1);
    set_class(12);
    set_value(8000);
    charge=MAXCHARGE;
    llevel=0;
    dam=allocate(5);
    color=({ "red", "green", "blue", "silver", "golden" });
}

short() { return ::short()+(llevel ? "(lighted)": ""); }

init() {
    ::init();
    add_action("light","light");
    add_action("extinguish","extinguish");
}

weapon_hit(attacker) {
   int i,sum;
  
  for (i=0;i<5;i++) dam[i]=random(100000);
   for(i=sum=0;i<5;i++) {
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

verb_dam(d,a) {
   switch(d) {
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

light(arg) {
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

exing() {
    if(!llevel) return;
    charge=llevel=0;
    set_light(0);
    call_out("recharge",MAXCHARGE*2);
    say("Someones light goes out.\n");
    write("Your light goes out.\n");
}

recharge() {
    charge=MAXCHARGE;
    tell_object(environment(),"The Mighty Starburst vibrates in your hands.");
}

extinguish(arg) {
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

writec(str) {
    int l,i;
    string out;
    out="";
    l=strlen(str);
    for(i=0;i<(LEN-l)/2;i++) out+="*";
    out+=str;
    for(i=strlen(out);i<LEN;i++) out+="*";
    write(out+"\n");
}

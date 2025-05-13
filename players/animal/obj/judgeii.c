#define ok return 1
#define notok return 0
#define name creep->query_name()
 
object creep;
 
short() {  return "A portable Judger"; }
long() { write("Type in 'judge <monster_name_here>'.  Cost 15 spell points.\n");
	ok;
}
id(str)  { return str == "judge" || str == "judger"; }
init() { 
          if(!this_player()) return;
          if(this_player()) creep= this_player();
          if(environment() != creep) return;
          add_action("judge","judge");
}
get() { return 1; }
drop() { return 0; }
query_value() { return 250; }
query_weight() { return 1; }
 
judge(str) {
   object player, monster;
   int r, perc, spellpts, align, max, hitpts;
   int magic;
   object me,ob;
 
   if(!this_player()) notok;
   if(!str)  notok;
   monster=present(str, environment(creep));
   if(!monster) {
      write("Judge what?\n");
      ok;
   }
   if(!living(monster)) { write("That is dead!\n"); ok; }
   spellpts=creep->query_spell_points();
   if(spellpts<15) {
      write("Not enough spellpoints.\n");
      ok;
   }
   perc = creep->query_level() - monster->query_level();
   perc = perc*2 + random(150);
/*
   if(perc < random(1)) {
      write("Your spell fails to work.\n");
      ok;
   }
*/
   if(interactive(monster)) {
      tell_object(monster, "\n"+name+" eyes glow brightly as "+
     creep->query_pronoun()+" judges "+
     "you very carefully.\n> ");
      }
   sayy("\n"+name+" judges "+capitalize(str)+".\n> ",monster);
   me = creep;
   magic = monster->query_level() + monster->query_wc() + monster->query_ac();
   magic = magic - me->query_level() - me->query_wc() - me->query_ac();
 
   if(magic <= -20)
      write("You could eat that for a snack, but why bother?\n");
   if(magic > -20 && magic <= -10)
      write("You can kill that with a wink of your eye!\n");
   if(magic > -10 && magic <= -6)
      write("Should be a piece of cake.\n");
   if(magic > -6 && magic <= -3)
      write("A good challenge, but you will propably win.\n");
   if(magic > -3 && magic <= 2)
      write("You are nearly equal in power. You may need some luck.\n");
   if(magic > 2 && magic <= 5)
      write("That will be quite hard. Use magic or better weapons.\n");
   if(magic > 5 && magic <= 10)
      write("May be too tough for you alone. Be careful!\n");
   if(magic > 10 && magic <= 15)
      write("I advice you to gain more power before trying that!\n");
   if(magic > 15 && magic <= 18)
      write("Do you feel lucky, punk??\n");
   if(magic > 18 && magic <= 20)
      write("Are you mad???\n");
   if(magic > 20)
      write("You are mad!!!!!!!!!!\n");
 
   if(monster->query_wc() > 15)
      write("\nBeware...it seems to be well armed...\n\n");
   align=monster->query_alignment();
   if(align<-700) {
     write("The "+str+" is totally evil!\n");
   } else if(align<-350) {
     write("The "+str+" is VERY evil!\n");
   } else if(align<-100) {
     write("The "+str+" is evil.\n");
   } else if(align<-50) {
     write("The "+str+" is somewhat evil.\n");
   } else if(align<50) {
     write("The "+str+" is nuetral.\n");
   } else if(align<100) {
     write("The "+str+" is somewhat good.\n");
   } else if(align<300) {
     write("The "+str+" is good.\n");
   } else if(align<700) {
     write("The "+str+" is VERY good.\n");
   } else {
     write("The "+str+" is totally good!!\n");
   }
   if(random(100) > 1) {
      hitpts=monster->query_hp();
      max=monster->query_max_hp();
      r = (max - hitpts)*100/max;
      if(r < 1) {
        write(capitalize(str)+" is in perfect health!!\n");
        ok;
      } else if(r < 15) {
        write(capitalize(str)+" is in VERY good shape!\n");
        ok;
      } else if(r < 40) {
        write(capitalize(str)+" is in good shape.\n");
        ok;
      } else if(r < 60) {
        write(capitalize(str)+" is hurt.\n");
        ok;
      } else if(r < 80) {
        write(capitalize(str)+" is very hurt!\n");
         ok;
       } else if(r < 95) {
        write(capitalize(str)+" is in VERY bad shape!\n");
        ok;
      } else {
         write(capitalize(str)+" is near death!!!\n");
        ok;
      }
   ok;
  }
	ok;
}

static sayy(str,obj) {
      object ob, o, n;
 
      ob = environment(creep);
      n = first_inventory(ob);
 
        while(n) {
                o = next_inventory(n);
           if (!living(n) || n == obj || n == creep)  {
                        n = o;
                        continue;
                        }
               tell_object(n,str);
                n = o;
                }
     ok;
}

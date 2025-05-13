

/* ------------------------------------------------------------------
   filename: danahra.c  Creator: whisky should be: nearly unkillable
   ps: This is a questmonster and can be removed with a special item.
   ------------------------------------------------------------------ */

inherit "obj/monster";  

#define SAY(x) tell_room(environment(this_object()),x)
#define _shad "/players/whisky/obj/"

void reset(int flag) 
{
  object sh;

   ::reset(flag);
   
   if (flag!=0) return;
   
    set_name("danahra");
    set_alt_name("drake");
    set_short("danahra");
    set_long("You see an almost 400 feet high drake. She is the mother\n"+
            "of Gorgurack and Garschmirack and the wife of Eros.\n"+
            "She seems so strong that any attack might be your death.\n"+
            "She don't look too friendly, but you might have luck, she\n"+
            "is just sleeping.\n");
    set_race("drake");   
    set_level(100);
    set_size(5);
    set_weight(8000);
    set_gender(2);
    set_hp(20000);
    set_al(-1200);
    set_dead_ob(this_object());
// connecting shadows to the drake
}


int query_str()
{
    return 150;
}

int query_dex()
{
    return 150;
}

int query_chr()
{
    return 200;
}

string look_info()
{
  if (query_attack())
     return " the lazy drake (is here to kill you)";
   return " the lazy drake (sleeping)";
}
 
run_away()
{
    return 0;
}
  
int monster_died(object ob) 
{
   object scale;

    if(!this_player()->query_immortal()) 
    {
        shout(this_player()->query_short_name()+" killed lazy Danahra !\n");
        this_player()->set_title("the SuperHero");
    }
    scale = clone_object(_shad+"scales/danahra_scale");
    move_object(scale,environment(ob));
    return 0; 
}

    
mixed attack()
{
  object *ob;
  int i,sz;

   ob=all_inventory(environment());

   if (::attack() && !random(5)) 
   {
      tell_room(environment(),
                "Danahra breathes a cloud of stinking, rotten flesh !\n");
      for(sz=sizeof(ob),i=0;i< sz;i++) 
      {
         if (living(ob[i]) && (ob[i]->query_race()!="drake")) 
         {
            if (ob[i]->hit_player(140+random(80),5,({9,10}))) 
            {
               if (living(ob[i]))
               {
                   command("puke",ob[i]);
	           ob[i]->add_poison(40);
               }
             }
          }
       }
     return 1;
    }
   return 0;
}

catch_tell(arg)
{
  object ruby;
     string str1, str2;
  
   if (sscanf(arg,"%s shows you a strange ruby %s",str1,str2)==2)  
   {
       ruby = present("ruby of fear",this_player());

       if (ruby)
       {
           SAY("Danahra panics and dives into the sea, "+
               "as she sees your devilish ruby.\n");
           destruct(ruby);
           destruct(this_object());
       }
    }
    return 1;
 }

   
check_freeze()
{
   object ob;
   if (ob =present("wkn1",this_object()))
       ob->free_myself();
}

int stop_fight()
{
   return 0; 
}
init()
{
 ::init();
add_action("no_hold","hold");
}

no_hold(){
write("You hold Danahra.\n");
return 1;
}

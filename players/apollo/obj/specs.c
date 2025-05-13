inherit "/obj/armour";

object visor;
int light_lev;
string esc;

query_mage_wear() { return 1; }
query_monk_wear() { return 1; }
query_ninja_wear() { return 1; }

void reset(int arg) 
{
    ::reset(arg);
    if (arg == 0) 
    {
      esc=" ";esc[0]=27;
      set_name("visor");
      set_alias("black knights visor");
      set_type("glasses");
      set_ac(1);
      set_long("They look like the glasses of a really cool black knight.\n");
      set_weight(1);
      set_value(11150);
    }
}

init()
{
  ::init();

  add_action("look","look");
  add_action("look","l");
  add_action("look","scan");
}

mixed wear(object me)
{
  int res;
  if(!this_object()->query_worn() && (res=::wear(me)))
  {
    write("Your vison blures, and gets a reddish touch!\n");
    say(capitalize(this_player()->query_name())+" turns into Arnold S. as "+
      this_player()->query_pronoun()+" invokes the BLACK KNIGHTS VISOR!!!\n");
    visor=clone_object("/players/llort/guild/newspells/true_sight");
    visor->start_shadow(this_player(),-1);
    return res;
  }
  return ::wear(me);
} 

int drop(mixed x)
{
   remove("visor");
   return 0;
}

mixed remove(string me)
{
  int res;

  if(this_object()->query_worn() && ::remove(me))
  {
   write("The humming sound of your visor changes frequency and fades away.\n");
   say(capitalize(this_player()->query_name())+" turns into a stupidlooking, "+
     "simple "+this_player()->query_race()+" again.\n"); 
   if(visor) destruct(visor); 
   return 1;
  }
  return ::remove(me);
}

string short()
{
   if (query_worn())
       return "An activated black knights visor emmiting a powerful hum\n"+
              "                [DANGER! WORN ON EYES]";
   else
       return "strange looking black glasses";    
}

look(str)
{
   string txt,*hlp,h1,h2,*itxt;
   int i,j;
   object *inv;

   if(!this_object()->query_worn()) return;

   if(!str)
   {
     txt=
esc+"[2J"+esc+"[H ____scanning ENVIRONMENT__________________________________"+
"________"+(this_player()->test_darkness() ? esc+"[5mINFRAVISION"+esc+"[0m" :
            "___________")+"_\n";
     h2=environment(this_player())->query_long();
     if(h2)
     {
       hlp=explode(h2,"\n");
       j=sizeof(hlp);
       if(hlp[j-1]=="") j--;
       for(i=0;i<j;i++) txt+=sprintf("[%-78s]\n",hlp[i]);
     }
     else
     {
       txt+="... switching to natural view ...\n";
       write(txt); 
       txt="";
       environment(this_player())->long();
     }

     if(h2) {
        txt+=
" ____scanning EXITS______________________________________________________"+
"______\n";
        hlp=environment(this_player())->query_dest_dirs();
        if(!(j=sizeof(hlp))) txt+="    NONE\n";
        else
	{
           itxt=({ });
           for(i=1;i<j;i=i+2)
	   {
              if(strlen(hlp[i])>18) hlp[i]=hlp[i][0..17];
              itxt+=({ hlp[i] });
	   }
           j=sizeof(itxt);
           itxt += ({ "","","","" });

           for(i=0;i<j;i+=4)
           {
              txt+=sprintf("[%-18s][%-18s][%-18s][%-18s]\n",
                     itxt[i], itxt[i+1], itxt[i+2], itxt[i+3]);
           }
        }
     }

     txt+=
" ____scanning OBJECTS____________________________________________________"+
"______\n";
     inv=all_inventory(environment(this_player()));
     inv=inv - ({ this_player() });
     j=sizeof(inv);
     itxt=({ });
     for(i=0;i<j;i++)
     {
        h1=inv[i]->query_real_name(); 
        if(!h1) h1=inv[i]->query_name();
        if(!h1) h1=inv[i]->short();
        if(!h1) h1="UNKNOWN";
        if(strlen(h1)>18) h1=h1[0..17];
        h1=capitalize(h1);
        itxt+=({ h1 });
     }
     itxt += ({ "","","","" });

     for(i=0;i<j;i+=4)
     {
        txt+=sprintf("[%-18s][%-18s][%-18s][%-18s]\n",
                     itxt[i], itxt[i+1], itxt[i+2], itxt[i+3]);
     }
     if(!j) txt+="    NONE\n";

     write(txt);

     return 1;
   }
}

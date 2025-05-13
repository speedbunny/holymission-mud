
/* standardshadow 
  
    USAGE: inherit it in your shadow, overwrite the playerfunction and
           put at the end a file_name() { return 1; } to it.
           As example if the shadow is called bark_shad it would
           be bark_shad() { return 1; }.

           To call the shadow you have to use:

           shad = clone(file_name(shadow));
           shad->start_shadow(player,time,type);
    
           The player is the object to be shadowed.
           The time is how long the shadow shall last.
           If the time == 0 its unlimited.
           The type is the file_name() as in upper examples
           it would be bark_shad.

    EXAMPLE: start_shad(find_living("whisky"),300,"bark_shad");   
             look under /players/whisky/obj/bark_shad.c and
                        /players/whisky/obj/bark_scroll.c      */

static string _type;
static object me;      /* the player which is shadowed */

int  start_shadow(object who,int time,string type)
{
      if (objectp(who) && living(who) && intp(time) && strlen(type))
      {
              _type = type;
			 if(call_other(who,type))
			 {
				tell_object(who,"There is already a spell of kind active.\n");
				return 2; /* already active */ 
			 }
			 else
			 {
             shadow(who,1);
             me = who;
             if (time > 0)   /* to be sure i overgive the object */
                 call_out("end_shadow",time,this_object());
				 return 1;
			 }
      }
	 return 0;
}

void end_shadow(object ob)
{
   destruct(ob);
}

int shadow_time()
{
   return(find_call_out("end_shadow"));
}
 
      
       

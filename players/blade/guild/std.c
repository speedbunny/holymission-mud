
/* standardshadow 
  
    USAGE: inherit it in your shadow, overwrite the playerfunction and
           put at the end a file_name() { return 1; } to it.
           As example if the shadow is called bark_shad it would
           be bark_shad() { return 1; }.

           To call the shadow you have to use:

           shad = clone(file_name(shadow));
           shad->start_shadow(player,time,id);
           set_effect_msg("barkskin");
    
           The player is the object to be shadowed.
           The time is how long the shadow shall last in seconds.
           If the time == 0 its unlimited.
           The 'id' is the id of the shadow as in upper examples
           it would be bark_shad, to avoid multiple shadowing.
           with set_effect_msg you can define the message the
           player gets with the 'attributes' command.

    EXAMPLE: start_shad(find_living("whisky"),300,"bark_shad");   
             look under /players/whisky/obj/bark_shad.c and
                        /players/whisky/obj/bark_scroll.c      */

static string _id, effect;
static object me;      /* the player which is shadowed */
static int endtime;
closure call;          /* should be used for better speed */

int shad_id(string id)
{
    return id==_id || me->shad_id(id);
}

varargs int  start_shadow(object who,int tim,string id,int allow_multi)
{
    call = #'call_other;
    if (objectp(who) && intp(tim) && strlen(id))
    {
        _id = id;
        if(!allow_multi && apply(call,who,"shad_id",_id))
        {
             tell_object(who,"There is already a spell of kind active.\n");
             return 2; /* already active */ 
        }
        else
        {
             shadow(who,1);
             if(tim) endtime=time()+tim;
             me = who;
             return 1;
        }
    }
    return 0;
}

void end_shadow(object ob)
{
   destruct(ob);
}

chk_all_shadows()
{
    apply(call,me,"chk_all_shadows");
    if(endtime && time() >= endtime) end_shadow(this_object());
}

int shadow_time(id)
{
   if(id==_id) return (endtime ? endtime-time() : 0);
   return apply(call,me,"shad_time",id);
}

string set_effect_msg(string eff)
{
   return effect=eff;
}

string *effects()
{
   string *eff;
   eff=apply(call,me,"effects");
   if(!eff) return ({ effect });
   return eff + ({ effect });
}

object shad_obj(string id)
{
   if(id==_id) return this_object();
   return apply(call,me,"shad_obj",id);
}

object *shadows()
{
   object *sh;
   sh=apply(call,me,"shadows");
   if(!sh) return ({ this_object() });
   return sh + ({ this_object() });
}

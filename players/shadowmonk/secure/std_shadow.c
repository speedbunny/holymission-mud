
/* standardshadow 
  
    USAGE: inherit it in your shadow, overwrite the playerfunction and
           put at the end a file_name() { return 1; } to it.
           As example if the shadow is called bark_shad it would
           be bark_shad() { return 1; }.

           To call the shadow you have to use:

           shad = clone(file_name(shadow));
           shad->start_shadow(player,time,id);
           set_effect_msg("barkskin");
           set_look_info("(woody skinned)");
    
           The player is the object to be shadowed.
           The time is how long the shadow shall last in seconds.
           If the time == 0 its unlimited.
           The 'id' is the id of the shadow as in upper examples
           it would be bark_shad, to avoid multiple shadowing.
           With set_effect_msg you can define the message the
           player gets with the 'attributes' command.

    EXAMPLE: start_shad(find_living("whisky"),300,"bark_shad");   
             look under /players/whisky/obj/bark_shad.c and
                        /players/whisky/obj/bark_scroll.c      */

static string _id,effect,look_inf;
static object me;      /* the player which is shadowed */
static int endtime;
closure call;          /* should be used for better speed */

int shad_id(string id) {
  return id==_id || me->shad_id(id);
}

varargs int start_shadow(object who,int tim,string id,int allow_multi) {
  if(!call)
    call=#'call_other;

  if(objectp(who) && intp(tim) && strlen(id)) {
    _id=id;
    if(!allow_multi && who->shad_id(_id)) {
      tell_object(who,"There is already a spell of kind active.\n");
      destruct(this_object());
      return 2; /* already active */ 
    }
    else {
      shadow(who,1);
      if(tim) {
        endtime=time()+tim;
      }
      me=who;
      return 1;
    }
  }
  destruct(this_object());
  return 0;
}

varargs void end_shadow(object ob) {  // parameter only for compatibility
  unshadow();                         // just to be sure
  destruct(this_object());
}

void chk_all_shadows() {
  me->chk_all_shadows();
  if(endtime && time()>=endtime)
    end_shadow();
}

int shadow_time(string id) {
  if(id==_id)
    return (endtime?endtime-time():0);
  else
    return me->shad_time(id);
}

string set_effect_msg(string eff) {
  return effect=eff;
}

string *effects() {
  string *eff;
  eff=me->effects();
  if(!effect)
    return eff;
  else if(!eff)
    return ({effect});
  else
    return eff+({effect});
}

object shad_obj(string id) {
  if(id==_id)
    return this_object();
  else
    return me->shad_obj(id);
}

object *shadows() {
  object *sh;
  sh=me->shadows();
  if(!sh)
    return ({this_object()});
  else
    return sh+({this_object()});
}

int set_look_info(string inf) {
  look_inf=inf;
  return 1;
}

string look_info(int flag) {
  string li;
  li=me->look_info(flag);
  if(!look_inf)
    return li;
  else if(flag)
    return 0;
  else
    return (li?li+look_inf:look_inf);
}

/* Elvin short sword */

inherit "obj/weapon";
#include "/players/kbl/header/T.h"

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name_of_weapon = "short sword";
    alias_name = "sword";
    short_desc = "A short sword";
    long_desc = "Finely crafted blade. Must have been made in a elvin forge\n";
    read_msg = "Elvin females are the fairest of the females of any race\n"+
               "and I was forged with that thought in mind.\n";
    class_of_weapon = 15;
    type_of_weapon = 0;
    value = 1800;
    local_weight = 4;
  }
}

init()
{
  ::init();
  add_action("fair","fair");
  add_action("mfeel","mfeel");
  add_action("mlove","mlove");
  add_action("mhug","mhug");
  add_action("mbeg","mbeg");
  add_action("msing","msing");
}

fair(str)
{
  object target;

  if(!str)
   return;
  if(!find_living(str))
  {
    write("No one by that name on right now.\n");
    return 1;
  }
  target = find_living(str);
  if((target->id("elf") == this_player()->id("elf")) &&
     target->query_gender_string() != this_player()->query_gender_string())
  {
    write("You tell "+capitalize(str)+": "+this_player()->query_name()+" loves you very much.\n");
    tell_object(find_living(str),this_player()->query_name()+" loves you very much.\n");
    return 1;
  }
}

mlove(str)
{
  object target;

  if(!str)
   return;
  if(!find_living(str))
  {
    write(str +" cannot be found, or is not a player.\n");
    return 1;
  }
  target = find_living(str);
  write("You send all the love on Holy Mission to "+capitalize(str)+"!\n");
  tell_object(target,this_player()->query_name()+" sends you all the love on Holy Mission!\n");
  return 1;
}

mhug(str)
{
  object target;
  object tp;
  string sex;

  tp = this_player();

  if(!str)
   return;
  if(!find_living(str))
  {
   write(str+" cannot be found, or is not a player.\n");
   return 1;
  }
  target = find_living(str);
  write("You hug "+capitalize(str)+" very tightly.\n");
  sex = tp->query_gender_string();
  switch(sex)
  {
    case "male": sex = "he";
                 break;
    case "female": sex = "she";
                   break;
    default:
             sex = "it";
  }
  tell_object(target, "You can almost feel "+tp->query_name()+" as "+sex+" holds you tightly from afar.\n");
  return 1;
}

mfeel(str)
{
  object tp;

  tp = this_player();
  switch(str)
  {
    case "lonely": say(tp->query_name()+" feels so lonely right now.\n");
                   write("You feel so lonely right now.\n");
                   break;
    case "miss you": say(tp->query_name()+" misses you so bad it hurts.\n");
                     write("You are missing someone so bad it hurts.\n");
                     break;
    case "angry": say(tp->query_name()+" is real angry with you right now!\n");
                  write("You are real angry with someone right now!\n");
                  break;
    default: say(tp->query_name()+" feels something but can't pin point it.\n");
             break;
  }
  return 1;
}

mbeg(str)
{
  object tp,target;
  string descr;

  if(!str)
   return;
  tp = this_player();
  if(!find_living(str))
  {
    notify_fail("No such living thing as "+str+".");
  }
  target = find_living(str);
  descr = environment(tp)->query_short();
  tell_object(target,"You can feel "+tp->query_real_name()+" begging you\n"+
                     "to come to "+tp->query_possessive()+" at "+
                     descr+".\n");
  return 1;
}

msing(str)
{
  object tp,target;
  string descr;

  if(!str)
   return;
  tp = this_player();
  if(!find_living(str))
  {
    notify_fail("No such living thing as "+str+".");
  }
  target = find_living(str);
  descr = environment(tp)->short();
  tell_object(target,"You can hear "+tp->query_real_name()+" singing a\n"+
                     "soothing melody to you from "+descr+".\n");
  write("You sing a sweet song to "+capitalize(target->query_real_name())+".\n");
  say(capitalize(tp->query_real_name())+" sings a sweet song to "+capitalize(target->query_real_name())+".\n");
  return 1;
}

msay(str)
{
  if(!str)
   return;
  tell_room(ETP,"   ****> "+CTPRN+" sez: "+CP(str)+" <****\n");
  return 1;
}

